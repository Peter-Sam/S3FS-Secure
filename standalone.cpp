#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <openssl/rc4.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include "cryptlib.h"

//#include <cryptlib.h>
#include "md5.h"
#include "rc4.h"
#include"rc4_locl.h"
#include "rc4_enc.c"
#include "rc4_skey.c"

using namespace std;
//#define KEY "potroast"// RC4 KEY
//#define KEY_LENGTH (sizeof(KEY)-1)// Length of key
void encrypt(int fd,int fd2);
//unsigned char *MD5(const unsigned char *d, size_t n, unsigned char *md);
//void decrypt();
int main(int argc, char* argv[] )
{
	//string data = "encryptkey";
	int fd1;
	int fd2;
	if( argc == 3)// accepts 3 arguments
	{
		fd1 = open(argv[1],O_RDWR,0700);//open file (fd1)
		fd2 = open(argv[2], O_CREAT | O_RDWR,0700);//open output file (fd2)
		//put error message
		encrypt(fd1, fd2);//encryption
		
	}
	//error handling
	else if(argc != 3)
	{
		perror("Error: not enough arguments");
	}
	/*else if( argc == 6 && arg[2] == "-d")
	{
		void decrypt();
	}
	*/
	if((fd1 = open(argv[1],O_RDONLY)) == -1 || ((fd2 = open(argv[2], O_CREAT | O_RDWR,0700)) == -1))
	{
		perror("Error: incorrect use of arguments");
	}
	close(fd1);//close files
	close(fd2);
	return 0;
}
void encrypt (int fd, int fd2)// another char *bytes?
{
	//string pass;
	//cout<< " enter password: " <<endl;// do i need a passwd?
	//cin >> pass;
	string rc4key = "potroast";// key to encrypt
	int length = rc4key.length();// length of key
	int size;
	//const int fdSize = 4096;
	//char buffer[fdSize];
	//reading from file
	size = lseek (fd,0, SEEK_END);// size of input files
	unsigned char* infile = (unsigned char*) malloc(size+1);// char* to hold input file info
	memset(infile,0,size+1);// allocate memory
	lseek(fd,0, SEEK_SET);
	ssize_t count;
	//read(fd,infile, size);
	count = read(fd,infile, size);
	
	unsigned char* md5key =(unsigned char*) malloc(length);// creates a md5 key to work with openSSL
	MD5((const unsigned char *) rc4key.c_str(),length, md5key);// md5 function
	RC4_KEY key;
	unsigned char* outfile = (unsigned char*) malloc(size+1);
	memset(outfile,0,size+1);
	RC4_set_key(&key, length,md5key);
	RC4(&key, size,infile, outfile);
	lseek(fd2, 0, SEEK_SET);
	write(fd2, outfile,size); 
	free(outfile);// free memory
	free(infile);
	free(md5key);
	
	
}
//open
//read
//encrypt
// write
//close
