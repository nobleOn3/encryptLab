/********************************************************************
* Header: Jessen Nihilist cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
   private:
      char table[7][7] = {
         {'D','O','M','G','U','Y','A'},
         {'B','C','E','F','H','I','J'},
         {'K','L','N','P','Q','R','S'},
         {'T','V','W','X','Z','0','1'},
         {'2','3','4','5','6','7','8'},
         {'9',' ','!','@','#','$','%'},
         {'^','&','*','?','_','-',';'},
      };

public:
   virtual std::string getPseudoAuth()  { return "JESSENNOBLE"; }
   virtual std::string getCipherName()  { return "Nihilist"; }
   virtual std::string getEncryptAuth() { return "Bryan Yeske"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Eric Brandel, \"The Nihilist Cipher\", OCT 14, 2016");
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
      str += "   loop through plaintext\n";
      str += "      loop through tableRows\n";
      str += "         loop through tableColumns\n";
      str += "            IF(table[tableRow][tableCol] EQUALS plaintext[index]\n";
      str += "               cT += tableRow\n";
      str += "               cT += tableCol\n";
      str += "               IF we have not reached the end of plaintext\n";
      str += "                  cT += SPACE\n";
      str += "   loop through password\n";
      str += "      loop through tableRows\n";
      str += "         loop through tableColumns\n";
      str += "            IF(table[tableRow][tableCol] EQUALS plaintext[index]\n";
      str += "               encodedPass += tableRow\n";
      str += "               encodedPass += tableCol\n";
      str += "               IF we have not reached the end of password\n";
      str += "                  encodedPass += SPACE\n";
      str += "   while(encodedPass size < cT size) ";
      str += "      loop(encodedPass)\n";
      str += "         encodedPass += encodedPass[i]\n";
      str += "         i++";
      str += "         encodedPass += encodedPass[i]\n";
      str += "         IF encodedPass size == cT size\n";
      str += "            break;\n";
      str += "   c_Index <- 0\n";
      str += "   p_Index <- 0\n";
      str += "   For each value in cT\n";
      str += "       loop through cT by c_Index\n";
      str += "          IF cT[c_Index] != SPACE\n";
      str += "             cipher_val += cT[index]\n";
      str += "          ELSE\n";
      str += "             break from loop\n";
      str += "       loop through encodedPassword by p_Index\n";
      str += "          IF encodedPassword[p_Index] != SPACE\n";
      str += "             pass_val += encodedPassword[p_Index]\n";
      str += "          ELSE\n";
      str += "             break from loop\n";
      str += "       cipherText += (cipher_val + pass_val)\n";
      str += "       IF cT[index + 1] != NULL\n";
      str += "          cipherText += SPACE\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   loop through password\n";
      str += "      loop through tableRows\n";
      str += "         loop through tableColumns\n";
      str += "            IF(table[tableRow][tableCol] EQUALS password[index]\n";
      str += "               en_pass += tableRow\n";
      str += "               en_pass += tableCol\n";
      str += "               en_pass += SPACE\n";
      str += "   c_Index <- 0\n";
      str += "   p_Index <- 0\n";
      str += "   For length of cipherText letters\n";
      str += "      loop through cipherText by c_Index\n";
      str += "         IF cipherText[c_Index] != SPACE\n";
      str += "            cipher_val += cipherText[c_Index]\n";
      str += "         ELSE\n";
      str += "            break from loop\n";
      str += "      loop through en_pass by p_Index\n";
      str += "         IF en_pass[p_Index] != SPACE\n";
      str += "            pass_val += en_pass[p_Index]\n";
      str += "         ELSE\n";
      str += "            break from loop\n";
      str += "       almost_plain += (cipher_val - pass_val)\n";
      str += "       IF cipherText[index + 1] != NULL\n";
      str += "          almost_plain += SPACE\n";
      str += "   loop through almost_plain\n";
      str += "      plain_row <- almost_plain[index]\n";
      str += "      index++\n";
      str += "      plain_col <- almost_plain[index]\n";
      str += "      index++\n";
      str += "      plainText += table[plain_row][plain_col]\n";
      str += "   RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: Code that creates 
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cT;//temp cipher
      std::string encodedPassword;
      int i = 0;//index
      int r = 0;//row
      int c = 0;//column
      bool found = false;
         for (i = 0; i <= plainText.size(); i++) {
           found = false;
            for (r = 0; r <= 7 && found == false; r++){ 
              for (c = 0; c <= 7 && found == false; c++){
                  if(table[r][c] == toupper(plainText[i])){
                     cT += r;
                     cT += c;
                     if ( i + 1 <= plainText.size()){
                       cT += " ";
                       }
                     found = true;
                     }
                  }
               }  
            }
            
      std::cerr << cT << std::endl;
      
      int size = password.size();
         for (i = 0; i <= plainText.size(); i++) {
           found = false;
            for (r = 0; r <= 6 && found == false; r++){ 
              for (c = 0; c <= 6 && found == false; c++){
                  if(table[r][c] == toupper(password[i % size])){
                     encodedPassword += r;
                     encodedPassword += c;
                     if ( i + 1 <= password.size()){
                       encodedPassword += " ";
                       }
                     found = true;
                     }
                  }
               }  
            }
            
      std::cerr << encodedPassword << std::endl;
      
      while(encodedPasswords.size() < cT.size()) {
               encodedPasswords += encodedPassword[i]
               i++
               encodedPassword += encodedPassword[i]
              if (encodedPassword() size == cT.size()){
                 break;
              }
              else{
              encodedPassword += " ";
              }
      }
        // Repeat above process to encode password
         int p_Index = 0;
         int c_Index = 0;
         int cipher_val = 0;
         int pass_val = 0;
         std::string cipherText;
         std::cout << "size " << size << "\n";
         for (i = 0; i <= cT.size(); i = i+3){
            for (c_Index = i; cT[c_Index] != ' '; c_Index++){ 
                  cipher_val = (cipher_val * 10) + cT[c_Index];
            }
            std::cout << "c Value " << cipher_val << "\n";
            for (p_Index = i; encodedPassword[p_Index] != ' '; p_Index++){ 
                  pass_val = (pass_val * 10) + encodedPassword[p_Index];
            }
            std:: cout << " p value: " << pass_val << "\n\n";
             cipherText += (cipher_val + pass_val);
             if (i + 1 <= cT.size()){
                cipherText += " ";
                cipher_val = 0;
                pass_val = 0;
             }
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
      return plainText;
   }


};

#endif // CIPHER01_H