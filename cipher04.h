/********************************************************************
* Header: Jeremias
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <sstream>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jeremias Platero"; }
   virtual std::string getCipherName()  { return "NULL Cipher"; }
   virtual std::string getEncryptAuth() { return "Nakai Velasquez"; }
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
      str += "   offset = password % 3\n";
      str += "   FOR x is all values of plainText\n";
      str += "   cipherText <- generateWord(x,password,offset)\n"; 
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
      str += "generateWord(x,password,offset)\n";
      str += "   wordsize = rand() % 8\n";
      str += "   i = 0\n";
      str += "   if(offset == 0)\n";
      str += "      newWord = x\n";
      str += "      while (i < wordSize)\n";
      str += "            newWord += 'a' + (rand() % 26)\n";
      str += "            i++\n";
      str += "   if(offset == 1)\n";
      str += "      while (i < wordSize)\n";
      str += "            if(i==1)\n";
      str += "                newWord += x\n";
      str += "            newWord += 'a' + (rand() % 26)\n";
      str += "            i++\n";
      str += "   if(offset == 2)\n";
      str += "      while (i < wordSize)\n";
      str += "            if(i==2)\n";
      str += "                newWord += x\n";
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
      std::string cipherText;
      int offset;

      for (int i = 0; i < password.size(); i++)
      {
            offset += (int)password[i];
      }

      offset = offset % 3;
      
      for (int x = 0; x < plainText.size(); x++)
         cipherText += generateWord(plainText[x], password, offset);

      return cipherText;
   }

   virtual std::string generateWord(int x, std::string password, int offset)
   {
      int wordSize = rand() % password.size() + 1;
      std::string newWord;
      int i = 0;

      if (offset == 0)
      {
         newWord += x;
         while (i < wordSize)
         {
            newWord += 'a' + (rand() % 25);
            i++;
         }
      }
      else if (offset == 1)
      {
         newWord += x;
         while (i < wordSize)
         {
            if (i == 1)
               newWord += x;
            else
               newWord += 'a' + (rand() % 25);
            i++;
         }
      }
      else if (offset == 2)
      {
         newWord += x;
         while (i < wordSize)
         {
            if (i == 2)
               newWord += x;
            else
               newWord += 'a' + (rand() % 25);
            i++;
         }
      }
      return newWord;
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
    std::stringstream ss(plainText);//(plainText);
    std::string newPass = password;
    //stringstream pp(password);
    //int x;
    //pp >> x;
    //cout << "Value of x: " << x << endl;
    //string decrpted;
    int result = 0;
    for (int i = 0; i < newPass.length(); i++)
    {
        result += newPass[i] - int('0');
    }
    std::cout << "Result: " << result << std::endl;
    int offset = result % 3;
    std::cout << "Value of offset: " << offset << std::endl;

    std::string word;
    while (ss >> word)
    {
        plainText += word[offset];
    }

    return plainText;
};

#endif // CIPHER04_H