/********************************************************************
* Header: Nakai
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Nakai Velasquez"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "\n\n\nAffine Encryption:\n\nRead in plaintext from user\nRead in key from user in form of 2 intigers\nStore: \n   a = first intiger \n   b = second intiger\n   m = 95 (alphabet size)\n\nParse through plaintext:\n      x = ascii decimal (int) equivalent for plaintext[i]\n      plaintext[i] = ax + b % m\nDisplay: plaintext (now encrypted)";

      // The decrypt pseudocode
      str += "\n\n\nAffine Decrpytion:\n\nread in ciphertext from user\nRead in key from user in form of 2 intigers\nStore: \n   a = first intiger \n   b = second intiger \n   m = 95 (alphabet size)\n\n// Find inverse of key\nLoop up from 0-94 (alphabet size):\n      if ((a * i % 94) == 1)\n         inverse = i\n\nParse through cyphertext:\n      ciphertext[i] = inverse * (ciphertext[i] - b) % 94\nDisplay: plaintext (now decrypted)";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER03_H