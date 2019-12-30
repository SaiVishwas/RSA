# RSA
RSA (Rivest–Shamir–Adleman) algorithm in C to encrypt/decrypt messages

1) Our code requires the use of the GNU Multiple Precision(GMP) Library
   Therefore please install it on your system by running the following command on the terminal

    <i>sudo apt-get install libgmp3-dev</i>

2) Once the installation is complete, please compile and run the program by using 

      <i>gcc -c Client.c 
  gcc -c find_k.c -lgmp
  gcc -c find_phi.c -lgmp
  gcc -c find_e.c -lgmp
  gcc -c createkey.c -lgmp
  gcc -c enc_fun.c -lgmp
  gcc -c enc_caller.c 
  gcc -c encrypt.c 
  gcc -c get_int.c 
  gcc -c find_d.c -lgmp
  gcc -c decrypt.c 
  gcc -c dec_fun.c -lgmp
  gcc -c stringify.c 
  gcc -c generate_prime.c -lgmp
  gcc Client.o createkey.o find_phi.o find_e.o find_k.o find_d.o encrypt.o enc_fun.o dec_fun.o decrypt.o generate_prime.o enc_caller.o stringify.o get_int.o -lgmp 

   ./a.out </i>


3) While executing please create the keys first by entering 1 on the terminal

4) Place the data to be encrypted in the input.txt file

5) Then encrypt the data by pressing 2 and entering the required public keys on the terminal

6) The encryted data is stored in the encrypted.txt file

7) In order to decrypt, please copy and paste the encrypted data in encrypted.txt to 'to_be_decrypted.txt' file

8) Then decrypt the data by pressing 3 and entering the required private keys on the terminal

9) The decrypted data (original message) is stored in the output.txt file

Thank you.
