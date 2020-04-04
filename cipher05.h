/********************************************************************
* Header: Bryan
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Bryan Yeske"; }
   virtual std::string getCipherName()  { return "Vingenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Jeremias Platero"; }
   virtual std::string getDecryptAuth() { return "Nakai Velasquez"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "www.britannica.com, Gustavus J. Simmons (2009), ";
      s += "\"Vigenère cipher\', \n   retrieved: ";
      s += "https://www.britannica.com/topic/Vigenere-cipher\n\n";
      return s;
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
       // The encryptCase pseudocode
      str =  "#include<bits/stdc++.h>\n ";
      str += "encrypt(string  plainText, string password)\n";
      str += "  String Key = sterilize ( password)\n";
      str += "  String coded\n";
      str += "    For (int i = 0; i  <= plaintext.size(); I ++)\n";
      str += "      int p = i %key.size()// needed to go back through password\n";
      str += "      If (isalpha(plaintext[i]))\n";
      str += "          Int x = ( plaintext[i] + keyt[p]) % 26\n";
      str += "          x += ’A’\n";
      str += "          coded.push_back(x)\n ";
      str += "     else\n";
      str += "       Coded.pushback(plaintext[i]\n";
      str += "   RETURN coded\n\n";

      // The decryptCase pseudocode
      str += "encrypt(string cipher, string password)\n";
      str += "  String key = sterilize ( password)\n";
      str += "  String answer\n";
      str += "    For (int i = 0; i  <= plaintext.size(); I ++)\n";
      str += "      int p = i %key.size() // needed to go back through password\n";
      str += "      If (isalpha(plaintext[i]))\n";
      str += "          Int x = ( (cipher[i] - key[p]) + 26  ) % 26\n";
      str += "          x += ’A’\n";
      str += "          answer.push_back(x)\n ";
      str += "      else\n";
      str += "       answer.pushback(plaintext[i]\n";
      str += "   RETURN answer\n\n";

      // helper routine
      str += "sterilize(string password)\n";
      str += " string temp \n";
      str += " //removes symbols and makes only a word password";
      str += "  for (int i = 0; i <= password.size() i++) \n";
      str += "    if (isalpha(password[i]))\n";
      str += "      temp.pushback(password[i[\n";
      str += "   RETURN temp\n\n";


      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      //std::string cipherText = plainText;
      std::string key = password;
      std::string coded;
      for(int i = 0; i <= plainText.size(); i++) {
          int p = i % key.size();// needed to go back through password
          if(isalpha(plainText[i])) {
              int x = (plainText[i] + key[p]) % 26;
              x += 'A';
              coded.push_back(x);
          }
          else
              coded.push_back(plainText[i]);
      }
       std::string cipherText = coded;
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
         
         std::string key = password;
         std::string answer;

         for (int i = 0; i <= plainText.size(); i++)
         {
               int p = i % key.size();
               if (isalpha(plainText[i])) 
               {
                     int x = ((plainText[i] - key[p]) +26) % 26;
                     x += 'A';
                     answer.push_back(x);
               }
               else 
               {
                     answer.push_back(plainText[i]);
               }
         }

      return answer;
   }
   /**********************************************************
    * Sterlize
    * removes symbols and makes only a word password
    *
    *  virtual std::string sterilize(const std::string& password) {
    *   std::string temp;
    *   for (int i = 0; i <= password.size(); i++) {
    *           if (isalpha(password[i]))
    *               temp.push_back(password[i]);
    *
    *        }
    *      return temp;
    *  } 
    *};
    **********************************************************/
#endif // CIPHER05_H