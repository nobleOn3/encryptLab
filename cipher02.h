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
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "cipher name"; }
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
      str =  "encrypt(plainText, password)\n";
      str += "   offset = offsetFromPassword(password)\n";
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
      str += "decrypt(plainText, password)\n";
      str += "   offset = offsetFromPassword(password)\n";
      str += "   FOR p is all values in plainText\n";
      str += "      row[r] += plainText[p]\n";
      str += "      if r equals offset\n";
      str += "         r-- and increment is now false\n";
      str += "      else if increment is true\n";
      str += "         r++;\n";
      str += "      else\n";
      str += "         r--;\n";
      str += "   For k is number of rows\n";
      str += "      text += row[k]\n";

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

#endif // CIPHER02_H