#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  if(phrase.empty()) return 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool has_upper = false;
  bool has_lower = false;
  
  for(int i = 0; i < pass.length(); i++){
    if(isupper(pass[i])){
      has_upper = true;
    }
    if(islower(pass[i])){
      has_lower = true;
    }
    if(has_upper && has_lower){
      return true;
    }
  }
  
  return has_upper && has_lower;
}

/* Receives a string and returns a count of how many case-sensitive unique characters there are. If there are duplicate instances of the same character it should only count as a single character. Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters. */
unsigned int Password::unique_characters(string phrase){
  bool ascii_chars[128] = {false}; // Array to track seen ASCII characters
  unsigned int unique_count = 0;

  for(char c : phrase){
    unsigned char_index = static_cast<unsigned char>(c);
    if(!ascii_chars[char_index]){
      ascii_chars[char_index] = true;
      unique_count++;
    }
  }

  return unique_count;
}