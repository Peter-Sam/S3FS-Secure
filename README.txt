Readme file by: Peter Sam
This is a guide to properly install and use my secure s3fs, openSSL, and my standalone utility.
My secure s3fs implementation can be found in the fdcache.cpp file included in this folder.
ALL MY CODE CAN BE FOUND UNDER THE KEYWORD "my code" 
NO MAKEFILE NECESSARY
////////SECURE S3FS////////////////////////////////////////////
1. Create an Amazon S3 account by going to www.aws.amazon.com/s3
2. Create a bucket
3. Install s3fs-fuse
	NOTE: This program has been tested on Linux. It is best to use it one the Ubuntu linux distribution.
Type the following command to download file:
sudo apt-get install automake autotools-dev fuse g++ git libcurl4-gnutls-dev libfuse-dev libssl-dev libxml2-dev make pkg-config
it clone https://github.com/s3fs-fuse/s3fs-fuse.git
cd s3fs-fuse
./autogen.sh
./configure
make
sudo make install

1.Mount the bucket
2.The following commands mount the bucket:
echo MYIDENTITY:MYCREDENTIAL >  ~/.passwd-s3fs// creates a password file
chmod 600  ~/.passwd-s3fs
3.type cd s3fs-fuse
4.s3fs petersamcsc4420 ~/s3fs-fuse/myMountpoint/ -o passwd_file=~/.passwd-s3fs -o dbglevel=info -f -o  curldbg
your bucket should be now mounted

1.Download OpenSSL
2. cd~/Desktop/openssl-1.0.2o
3.sudo config
  sudo make
  sudo make test 
  sudo make install

How to use secure-s3fs:
1.Drag a copy of file you want to encrypt and put in to the mountpoint.
	- or this can be done by the following command: "mv image.jpeg /mnt"
2.Go to your bucket on the Amazon website and it should be encrypted.
3. To decrypt the file, download the file.

How to use the standalone utility:
1. cd Desktop/myRC4
2. to compile:
	g++ standalone.cpp -o standalone -lssl -lcrypto
3. To encrypt: Only three arguments are needed
	./standalone input.jpeg FiletoBeEncrypted.jpeg
4. To decrypt: Only three arguments are needed
	./standalone encryptedFile.jpeg DecryptedFile.jpeg
5. Files to include in standalone folder:
ALL THESE FOLDERS ARE FROM OPENSSL:
asm folder
ms folder
openssl folder
cryptlib.h
e_os.h
e_rc4.c
e_rc4_hmac_md5.h
md5.h
rc4.h
rc4_enc.c
rc4_locl.h
rc4s.cpp
rc4_skey.c
rc4speed.c
rc4test.c
rc4_utl.c





