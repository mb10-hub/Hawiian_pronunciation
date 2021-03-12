#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool vowelGroup(char first, char next, string& replacement);
bool singleVowel(char current, string& replacement);
bool consonantGroup(char prevchar, char currchar, string& replacement);
bool isValidChar(char cha);
bool isValidInput(string word);
char getInvalidChar(string word);
string convertToHawaiian(string input);


int main(){

  string userStr;
  string userInput;
  string invalid;

  cout << "Enter a hawaiian word to pronounce ==>" << endl;
  while (getline(cin, userStr)) {


    if (!isValidInput(userStr)) {

      invalid = getInvalidChar(userStr);
      cout << "Error: Can't convert " << userStr << " because " << invalid << " is not a       valid hawaiian      character" << endl;

    }

    if (isValidInput(userStr)) {

      cout << userStr << " is pronounced ";
      cout << convertToHawaiian(userStr) << endl;

    }
    cout << "Enter a hawaiian word to pronounce ==>" << endl;
  }
}

bool vowelGroup(char first, char next, string& replacement){

  first = tolower(first);
  next = tolower(next);

  if ((first == 'a' && (next == 'i' || next == 'e'))){
    replacement = "eye";
    return true;
  }
  else if ((first == 'a' && (next == 'o' || next == 'u'))){
    replacement = "ow";
    return true;
  }
  else if ((first == 'e' && next == 'i')){
    replacement = "ay";
    return true;
  }
  else if ((first == 'e' && next == 'u')){
    replacement = "eh-oo";
    return true;
  }
  else if ((first == 'i' && next == 'u')){
    replacement = "ew";
    return true;
  }
  else if ((first == 'o' && next == 'i')){
    replacement = "oy";
    return true;
  }
  else if ((first == 'o' && next == 'u')){
    replacement = "ow";
    return true;
  }
  else if ((first == 'u' && next == 'i')){
    replacement = "ooey";
    return true;
  }
  else {
    return false;//vGroup = false;
  }
}

bool singleVowel(char current, string& replacement){

  current = tolower(current);

  if ( current == 'a'){
    replacement = "ah";
    return true;
  } else if ( current == 'e'){
    replacement = "eh";
    return true;
  } else if ( current == 'i'){
    replacement = "ee";
    return true;
  } else if ( current == 'o'){
    replacement = "oh";
    return true;
  } else if ( current == 'u'){
    replacement = "oo";
    return true;
  } else{
    return false;//sVowel = false;
  }
}

bool consonantGroup(char prevchar, char currchar, string& replacement){

  if ((currchar == 'p') || (currchar == 'k') || (currchar == 'l') || (currchar == 'm') || (currchar == 'n')){
    replacement = currchar;
    return true;
  }
  else if ((currchar == 'w') && (prevchar == 'a' || prevchar == 'u' || prevchar == 'o')){
    replacement = 'w';
    return true;
  }
  else if ((currchar == 'w') && (prevchar == 'i' || prevchar == 'e')){
    replacement = 'v';
    return true;
  }
  else {
    return false;
  }

}

bool isValidChar(char cha){

  cha = tolower(cha);

  if (cha == 'a' || cha == 'e' || cha == 'i' ||
            cha == 'o' || cha == 'u' || cha == 'p' ||
            cha == 'k' || cha == 'l' || cha == 'h' ||
      cha == 'm' || cha == 'n' || cha == 'w' || cha == ' ' || cha == '\'')
    {
      return true;
    }
  else {
    return false;
  }
}

bool isValidInput(string word) {


  for (unsigned i = 0; i < word.size(); i++) {

    if (!isValidChar(word.at(i))) {
      return false;
    }

  }
  return true;
}

char getInvalidChar(string word) {

  char invalid = ' ';

  assert(!(isValidInput(word)));
  for (unsigned i = 0; i < word.size(); i++) {
    if (!isValidChar(word.at(i))) {
      invalid = word.at(i);
      break;
    }
  }
  return invalid;
}

string convertToHawaiian(string userStr){

  string replacement = "";
  string hawaiianWord = "";
  unsigned i;

  assert(isValidInput(userStr));

  for (i = 0; i < userStr.size(); i++)
    {

      if ((i != userStr.size() - 1) && (vowelGroup(userStr.at(i), userStr.at(i + 1), replacement)))
	{

	  if ((i != userStr.size() - 2) && (userStr.at(i + 1) != ' '))
	    {
	      hawaiianWord += replacement + "-";

	    }
	  else
	    {
	      hawaiianWord += replacement;

	    }
	  i = i + 1;
	}

      else if (singleVowel(userStr.at(i), replacement))
	{
	  if ((i != userStr.size() - 1) && ((userStr.at(i + 1) != ' ')) && (userStr.at(i + 1) != '\''))
	    {
	      hawaiianWord += replacement + "-";
	    }
	  else
	    {
	      hawaiianWord += replacement;

	    }
	}

      else if ((i != 0) && (consonantGroup(userStr.at(i - 1), userStr.at(i), replacement)))
	{
	  if (i != 0)
	    {
	      hawaiianWord += replacement;
	    }
	  else
	    {

	      hawaiianWord += replacement + "-";

	    }
	}

      else if (!singleVowel(userStr.at(i), replacement) &&
	       !((i != userStr.size() - 1) && vowelGroup(userStr.at(i), userStr.at(i + 1), replacement))){

	hawaiianWord += userStr.at(i);

      }

    }

  return hawaiianWord;


}
