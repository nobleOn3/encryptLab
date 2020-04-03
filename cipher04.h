/********************************************************************
* Header: Jeremias
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jeremias Platero"; }
   virtual std::string getCipherName()  { return "NULL Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "Garrett Cloud"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Gaines, Helen F. (2014). Cryptanalysis: A Study of Ciphers and Their Solution. Courier Corporation");
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
      str = "encrypt(plainText, password)\n";
      str += "   FOR x is all values of plainText\n";
      str += "   cipherText <- generateWord(x,password)\n"; 
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   stringstream ss(cipherText)\n";
      str += "   plainText\n";
      str += "   offset = password % 3\n";
      str += "      while(stringstream)\n";
      str += "            word\n";
      str += "            ss >> word\n";
      str += "            plainText += word[offset]\n";
      str += "   RETURN plainText\n\n";

      //generates words with random letters
      str += "generateWord(x,password)\n";
      str += "   wordsize = rand() % 8\n";
      str += "   offset = password % 3\n";
      str += "   if(offset == 0)\n";
      str += "      newWord = x\n";
      str += "      while (i < wordSize)\n";
      str += "            newWord += 'a' + (rand() % 26)\n";
      str += "            i++\n";
      str += "   if(offset == 1)\n";
      str += "      newWord = x\n";
      str += "      while (i < wordSize)\n";
      str += "            newWord += 'a' + (rand() % 26)\n";
      str += "            i++\n";
      str += "   if(offset == 2)\n";
      str += "      newWord = x\n";
      str += "      while (i < wordSize)\n";
      str += "            newWord += 'a' + (rand() % 26)\n";
      str += "            i++\n";
      str += "    return newWord\n\n";

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
      stringstream ss(plainText);
      //string decrpted;
      int offset = password % 3;

      while (stringstream)
      {
          string word;
          ss >> word;
          cipherText += word[offset];
      }

      return plainText;
   }
};

#endif // CIPHER04_H