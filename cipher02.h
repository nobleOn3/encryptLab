/********************************************************************
* Header: Garrett
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Garrett Cloud"; }
   virtual std::string getCipherName()  { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Jessen Noble"; }
   virtual std::string getDecryptAuth() { return "Bryan Yeske"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://pdfs.semanticscholar.org/5c64/40d0e45b326989669f0757bfbed4446ad5c1.pdf");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // Remove space
      str = "removeSpace(plainText)\n";
      str += "   FOR s is all values in plainText";
      str += "      if (plainText[s] is equal to ' ')\n";
      str += "         editedText[s] equals plainText[i++]\n";
      str += "      else\n";
      str += "         editedText[s] equals plainText[s]\n";
      str += "   return editedText\n";


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
      str += "   FOR p is zero while p is less than plainText.size()\n";
      str += "      row[r] += plainText[p]\n";
      str += "      if r equals key-1\n";
      str += "         decrement r\n";
      str += "         increment false\n";
      str += "      else if increment is true\n";
      str += "         increment r\n";
      str += "      else if r equals zero\n";
      str += "         increment r\n";
      str += "         increment equals true\n";
      str += "      else decrement r\n";
      str += "   FOR r is zero while r is less than key\n";
      str += "      FOR c is zero while row[r][c] is not NULL\n";
      str += "         row[r][c] = plainText[p]\n";
      str += "         increment p\n";
      str += "   FOR rr = 0 while row[rr][cc] is not NULL\n";
      str += "      if rr equals key-1 then decrement rr, increment cc, set increment = false\n";
      str += "      else if rr is zero and increment is false then increment rr, increment cc, set increment equal to true\n";
      str += "      else if increment is true then increment cc\n";
      str += "      else decrement cc\n";

      return str;
   }


   /**********************************************************
    * REMOVESPACE
    * Removes spaces from plainText
    **********************************************************/
   virtual std::string removeSpace(const std::string & plainText)
   {
      std::string editedText;
      for(int s = 0; s < plainText.length(); s++)
      {
         if(plainText[s] == ' ')
         {
            editedText += plainText[s+1];
            s++;
         }
         else
         {
            editedText += plainText[s];
         }
         
      }
      return editedText;
      
   }


   /**********************************************************
    * ENCRYPT
    * RAIL/FENCE encryption 
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      // TODO - Add your code here

      int key = (password[0] % 10) + 2;
      std::cout << key << std::endl;
      bool increment = true;
      std::string* row = new std::string[key];
      int r = 0;
      std::cout << "Done 1\n";
      for (int p = 0; p < plainText.size(); p++)
      {
          row[r] += plainText[p];

          if (r == (key - 1))
          {
              r--;
              increment = false;
          }
          else if (increment)
              r++;
          else if (r == 0)
          {
              r++;
              increment = true;
          }
          else
          {
              r--;
          }
      }

      for (int k = 0; k < key; k++)
      {
          cipherText += row[k];
      }
      std::cout << "Done 1\n";
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

      int key = (password[0] % 10) + 2;
      bool increment = true;
      std::string row[key];
      int count = 0;

      int r = 0;
      for(int p = 0; p < cipherText.size(); p++)
      {
         row[r] += cipherText[p];
         count++;
         if(r == (key-1))
         {
            r--;
            increment = false;
         }

         else if(increment == true)
            r++;
         else if(r == 0)
         {
            r++;
            increment = true;
         }
         else
         {
            r--;
         }
         
      }

      for(int k = 0; k < key; k++)
      {
         plainText  += row[k];
      }
      return plainText;
   }
};

#endif // CIPHER02_H