/********************************************************************
* Header: Garrett
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Garrett Cloud"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
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
      // Remove spacee
      str = "removeSpace(plainText)\n";
      str += "   FOR s is all values in plainText";
      str += "      if (plainText[s] is equal to ' ')\n";
      str += "         editedText[s] equals plainText[i++]\n";
      str += "      else\n";
      str += "         editedText[s] equals plainText[s]\n";
      str += "   return editedText\n";

      // offsetFromPassword function
      str += "offsetFromPassword(password)\n";
      str += "   if the word 'two' is found in password\n";
      str += "      return 2\n";
      str += "   else if 'three' is found in password\n";
      str += "      return 3\n";
      str += "   else if the word 'four' is found in password\n";
      str += "      return 4\n";
      str += "   else if 'five' is found in password\n";
      str += "      return 5\n";
      str += "   else if 'six' is found in password\n";
      str += "      return 6\n";
      str += "   else if 'seven' is found in password\n";
      str += "      return 7\n";
      str += "   else if 'eight' is found in password\n";
      str += "      return 8\n";
      str += "   else if 'nine' is found in password\n";
      str += "      return 9\n";
      str += "   else\n";
      str += "      return default value of 3\n";

      // The encrypt pseudocode
      str +=  "encrypt(plainText, password)\n";
      str += "   editedText equals the return from removeSpace(plainText)\n";
      str += "   offset equals the return from offsetFromPassword(password)\n";
      str += "   FOR p is all values in plainText\n";
      str += "      row[i] += plainText[p]\n";
      str += "      if r equals offset\n";
      str += "         r-- and increment is now false\n";
      str += "      else if increment is true\n";
      str += "         r++;\n";
      str += "      else\n";
      str += "         r--;\n";
      str += "   For k is number of rows\n";
      str += "      text += row[k]\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   offset = offsetFromPassword(password)\n";
      str += "   FOR p is all values in plainText\n";
      str += "      row[r] += cipherText[p]\n";
      str += "      if r equals offset\n";
      str += "         r-- and increment is now false\n";
      str += "      else if increment is true\n";
      str += "         r++;\n";
      str += "      else\n";
      str += "         r--;\n";

      return str;
   }


   /**********************************************************
    * REMOVESPACE
    * Removes spaces from plainText
    **********************************************************/
   virtual std::string removeSpace(const std::string & plainText)
   {
      string editedText;
      for(int s = 0; s < plainText.length(); s++)
      {
         if(plainText[s] == ' ')
         {
            editedText[s] = plainText[s+1];
         }
         else
         {
            editedText[s] = plainText[s];
         }
         
      }
      return editedText;
   }

   /**********************************************************
    * OFFSETFROMPASSWORD
    * TODO: ADD description
    **********************************************************/
   virtual int offsetFromPassword(const std::string & password)
   {
      if(password.find("two"))
      {
         return 2;
      }
      else if(password.find("three"))
      {
         return 3;
      }
      else if(password.find("four"))
      {
         return 4;
      }
      else if(password.find("five"))
      {
         return 5;
      }
      else if(password.find("six"))
      {
         return 6;
      }
      else if(password.find("seven"))
      {
         return 7;
      }
      else if(password.find("eight"))
      {
         return 8;
      }
      else if(password.find("nine"))
      {
         return 9;
      }
      else
      {
         return 3;
      }
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

#endif // CIPHER02_H