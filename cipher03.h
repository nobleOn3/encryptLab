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
   virtual std::string getEncryptAuth() { return "Garrett Cloud"; }
   virtual std::string getDecryptAuth() { return "Jessen Noble"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://math.asu.edu/sites/default/files/affine.pdf , https://www.geeksforgeeks.org/implementation-affine-cipher/?ref=rp");
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
      str =  "\nAffine Encryption:\n\nSplit password into two intigers\nStore: \n   loop through password[i]\n      |a += (int)password[i] \n      |b += (int)password[i]\n   m = 95 (alphabet size)\n   a = a % m\n   b = b % password.size()\n\nParse through plaintext:\n      x = ascii decimal (int) equivalent for plaintext[i]\n      plaintext[i] = ax + b % m\nDisplay: plaintext (now encrypted)";

      // The decrypt pseudocode
      str += "\nAffine Decrpytion:\n\nSplit password into two intigers\nStore: \n   loop through password[i]\n      |a += (int)password[i] \n      |b += (int)password[i]\n   m = 95 (alphabet size)\n   a = a % m\n   b = b % password.size()\n\n// Find inverse of key\nLoop up from 0-94 (alphabet size):\n      if ((a * i % 94) == 1)\n         inverse = i\n\nParse through cyphertext:\n      ciphertext[i] = inverse * (ciphertext[i] - b) % 94\nDisplay: plaintext (now decrypted)";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
       std::string cipherText = "";
       // TODO - Add your code here
       int a = (int)(password[0]) - '0'; // actual number
       int b = (int)(password[1]) - '0';
       int m = 95;
       int x;

       for (int i = 0; i < plainText.length(); i++)
       {
           x = (int)plainText[i]; //ascii
           cipherText += std::to_string((a * x + b) % m);
           cipherText += ' ';
       }

       return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      // TODO - Add your code here
      // Affine Decrpytion:read in ciphertext from user
      // Read in key from user in form of 2 intigers
      // Store:  
      // a = first intiger 
      // b = second intiger \n  
      int a = (int)(password[0]);
      int b = (int)(password[1]); 

      // m = 95 (alphabet size)\n\n// 
      int m = 95;

      // Find inverse of key\n
      // Loop up from 0-94 (alphabet size):\n     
      //  if ((a * i % 94) == 1)\n         
      //  inverse = i\n\n
      int inverse = 0;
      for(int i = 0; i < m; i++)
      {
         if(((a * i) % m) == 1)
         {
            inverse = i;
            break;
         }
      }

      //Parse through ciphertext:\n      
      //  ciphertext[i] = inverse * (ciphertext[i] - b) % 94\n
      std::string cipherTmp;
      int j = 0;
      for(int i = 0; i < cipherText.size(); i++)
      {
         for(j; j < cipherText.size(); j++)
         {
            if (cipherText[j] != ' ')
            {
               cipherTmp += cipherText[j];
            }
            else
            {
               j++;
               break;  
            }
         }

         std::cout << inverse << std::endl;
         std::cout << (char)((((std::stoi(cipherTmp)) - b) % m) + ((int)' ')) << std::endl;
         std::cout << ((char)(inverse * ((std::stoi(cipherTmp)) - b) % m) + ((int)' ')) << std::endl;
         //plainText += (char)(inverse * ((a * std::stoi(cipherTmp) + b) % m) + (int)' ');
         plainText += (char)(inverse * ((std::stoi(cipherTmp)) - b) % m) + (int)' ';
         cipherTmp = "";

         if(j >= cipherText.size())
         {
            break;
         }
      }
      //  Display: plaintext (now decrypted)
      return plainText;
   }
};

#endif // CIPHER03_H