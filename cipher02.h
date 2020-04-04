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
   virtual std::string getEncryptAuth() { return "Jessen Noble"; }
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
      // Remove space
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
    * OFFSETFROMPASSWORD
    * TODO: ADD description
    **********************************************************/
   virtual int offsetFromPassword(const std::string & password) const
   {
      if(password == ("two"))
      {
         return 2;
      }
      else if(password == ("three"))
      {
         return 3;
      }
      else if(password == ("four"))
      {
         return 4;
      }
      else if(password == ("five"))
      {
         return 5;
      }
      else if(password==("six"))
      {
         return 6;
      }
      else if(password==("seven"))
      {
         return 7;
      }
      else if(password==("eight"))
      {
         return 8;
      }
      else if(password==("nine"))
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
    * RAIL/FENCE encryption 
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      // TODO - Add your code here

      const int key = std::stoi(password);
      bool increment = true;
      std::string* row = new string[key];
      int r = 0;
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

       string end = "";
       const int key = std::stoi(password);
       bool increment = true;
       std::string* row = new string[key];
       int r = 0;
       // FOR p is zero while p is less than plainText.size()
       for (int p = 0; p < plainText.size(); p++)
       {
           // row[r] += plainText[p]
           row[r] += plainText[p];

           // if r equals key-1
           if (r == (key - 1))
           {
               // decrement r
               r--;
               // increment false
               increment = false;
           }
           // else if increment is true
           else if (increment)
           {
               // increment r
               r++;
           }
           // if r equals zero
           else if (r == 0)
           {
               // increment r
               r++;
               // increment equals true
               increment = true;
           }
           // else decrement r
           else
           {
               r--;
           }
       }

       int p = 0;
       // FOR r is zero while r is less than key
       for (int r = 0; r < key; r++)
       {
           // FOR c is zero while row[r][c] is not NULL
           for (int c = 0; row[r][c] != NULL; c++)
           {
               // row[r][c] = plainText[p]
               row[r][c] = plainText[p];
               // increment p
               p++;
           }
       }

       int cc = 0;
       increment = true;
       // FOR rr is zero while row[rr][cc] is not NULL
       for (int rr = 0; row[rr][cc] != NULL;)
       {
           end += row[rr][cc];
           // if rr equals key-1 then decrement rr, increment cc, set increment = false
           if (rr == (key - 1))
           {
               rr--;
               if (key > 2)
                   cc++;
               increment = false;
           }
           // if rr is zero and increment is false then increment rr, increment cc, set increment equal to true
           else if (rr == 0 && !increment)
           {
               rr++;
               cc++;
               increment = true;
           }
           // else if increment is true then increment cc
           else if (increment)
           {
               rr++;
           }
           // else decrement cc
           else
           {
               rr--;
           }
       }

    return end;
};

#endif // CIPHER02_H