/*
 *
 * Author: Vertebraker <tmieczkowski@hotmail.com>
 * Filename: /obj/lang_master
 * Date:   <10-5-03>
 * Description:
 *  Inheritable language master object.
 *  Feature list pending.
 *
 */

#pragma strict_types

#include <ansi.h>

/*
 * These are simple flags (I wish I knew how to use set_bit()..)
 * for usage in the case-sensitivity deprecation code I introduce
 * here.
 */

#define LCASE_INT 1
#define UCASE_INT 0

/*
 * These are error codes we return into our errorMsg
 * function that log and display a msg that users
 * will not understand but administration _will_.
 * This log will be kept in a standard file as denoted
 * below.
 */

#define ECODE_TEXT_BADTYPE     320
#define ECODE_ADDENDUM_BADTYPE 420

/*
 * These are the only valid expressions used
 * in the addendum and random text addition
 * functions.
 *
 */

#define VALID_AORT_TYPES ({"char","phrase"})

#define LOG_LANG "LANG_ERR"

/* internal variables */

static int    *arrCasePositions;  /* array holding flags of u.c or l.c letters */
static string  strOriginalText;   /* original text inputted */
static string  strNewText;        /* output */
static string *arrWords;          /* array holding all words grabbed from sentence */
static string  temp;              /* standard temporary string variable */

/* dictionary lookup */

int            pctDictionaryFreq; /* frequency Dictionary goes off. will default to 100 */
static mapping mapDictionary;     /* holds dictionary definitions */
string        *arrSavedDictionary; /* need for saving maps on Nirv */

/* random phrase adding */

int            pctRandTextFreq;  /* frequency Random Text gets introduced */
string        *arrRandText;      /* array of rand text type and actual content */

/* change patterns */

string        *arrPatterns;    /* bad : good syntax */
int            pctPatternsFreq;

/* random func */

int            pctRandFuncFreq; /* frequency a Random Func will be called */
string        *arrRandFunc;     /* list of all random funcs avail */

/* random addendum */

int            pctRandAddendumFreq; /* frequency an addendum will be added */
string        *arrRandAddendum;     /* list of all addendums */

status         isLoaded;          /* has object been loaded? Standard */


/*
 * In this subprogram, we initialize an array containing 
 * the case significance of each character in the string
 * we have input.  This is saved and rebuilt later
 * in the final completionary steps of this entire
 * program.
 */

void getCasePositions()
{
 int  s;
 if(s = strlen(strOriginalText))
 {
  int x;
  string char;

  arrCasePositions = allocate(s);
  for(x = 0; x < s; x ++)
  {
   char = strOriginalText[x..x];
   arrCasePositions[x] = (lower_case(char) == char ? LCASE_INT : UCASE_INT);
  }
 }
}

/*
 * Here's we splice our sentence down into its "chunks"
 * separated by spaces - a.k.a. WORDS.
 * This sub is obviously useful for our purposes.
 */

void getWords()
{
 string temp, temp2;

 arrWords = ({ });
 temp2    = strOriginalText;

 while(sscanf(temp2, "%s %s", temp, temp2) == 2)
  arrWords += ({ temp });
}

/* This needs to go into Efuns. */

string queryPunctuation(string word)
{
 string puncChar;

 puncChar = word[strlen(word)-1..strlen(word)-1];

 if(member_array(puncChar, ({".","!","?",",",":","-"})) > -1)
  return puncChar;
}

/*
 * A simple lookup into our map to see if
 * we have a match.  I need to expand this later
 * to accept multiple syntax.
 * Strip out punctuation, see WHAZZA
 */

varargs string lookupInDictionary(string word)
{
 string translation, punc;

 write("lookupInDictionary: word: " + word + "\n");
 if(punc = queryPunctuation(word))
 {
  if(strlen(word) > 1)
   word = word[0..strlen(word)-2];
 }

 if(mapDictionary && sizeof(mapDictionary) && (translation = mapDictionary[word]))
 {
  write("translating " + word + " to " + translation + "\n");
  word = translation;
 }

 return word + (punc ? punc : "");
}

/*
 * Lookup entire sentence/all WORDS.
 */

void lookupAllInDictionary()
{
 int x, s;

 s = sizeof(arrWords);

 for(x = 0; x < s; x ++)
  arrWords[x] = lookupInDictionary(arrWords[x]);
}

/*
 * This meaty fun replaces certain patterns
 * based on parameters specified by the inheritance.
 * Refer to intense documentation.
 */

varargs string replacePattern(string word, string badPattern, string goodPattern, string positionType)
{

 string a, z;
 if(positionType)
  switch(positionType)
  {
   case "BGN":
    if(sscanf(word,"%s"+badPattern+"%s", a, z) == 1 && z)
     word = goodPattern + z;
    break;
   case "END":
    if(sscanf(word,"%s"+badPattern+"%s", a, z) == 1 && a)
     word = a + goodPattern;
   case "MID":
    if(sscanf(word,"%s"+badPattern+"%s", a, z) == 2)
     word = a + goodPattern + z;
   case "ALL":
    while(sscanf(word,"%s"+badPattern+"%s",a,z)==2)
     word = a + goodPattern + z;
  }
 return word;
}

/*
 * Replace ALL Patterns.
 */

void replaceAllPatterns()
{
 int x, y;
 y = sizeof(arrWords);
 for(x = 0; x < y; x ++)
  arrWords[x] = replacePattern(arrWords[x]);
}

/*
 * Time to call a random function,
 * like one that will capitalize
 * the whole string, part of the string,
 * chop it, or otherwise do whatever
 * the heck the inheriter wants.
 * This function may not accept an argument.
 */

void callRandFunc()
{
 string funcToCall;
 int    arraySize;

 if(arrRandFunc && (arraySize = sizeof(arrRandFunc)))
 {
  funcToCall = arrRandFunc[random(arraySize)];
  call_other(this_object(), funcToCall, 0);
 }
}

/* Next two funs need to be put in Efuns.
   Completely self-explanatory.             */

status isEvenNumber(int num)
{
 return !(num % 2);
}

status isOddNumber(int num)
{
 return !isEvenNumber(num);
}

/*
 * This generic error msg will log to file
 * specified by LOG_LANG
 * Using log_file() .. 
 */

void errorMsg(int errorCode)
{
 if(this_player())
 {
  tell_object(this_player(),
"This program has failed.\n\
Please contact the administrator of this device as soon\n\
as possible. This error has been recorded.\n");
 }
 log_file(LOG_LANG, ctime()[4..15]+" tp: " +
   this_player()?(string)this_player()->query_real_name():"none" + 
   " caller: " + caller() ? file_name(caller()) : "none" + " " +
   " this_obj: " + this_object() ? file_name(this_object()) : "none" +
   "\n");
}

/* For each individual word, there will be a pctg chance
   of adding a random phrase or character.  For basic
   stuttering, the Scarface "effbomb-a-thon", etc.
*/

void addRandText()
{
 int    index, s;
 string textType, textContent;

 if(!arrRandText || !(s = sizeof(arrRandText)))
  return;

 s = sizeof(arrWords);

 for(index = 0; index < s; index ++)
  if(pctRandTextFreq > random(100))
  {
   int  x, y;

   y = random(sizeof(arrRandText));

   if(isEvenNumber(y))
   {
    textType = arrRandText[y];
    textContent = arrRandText[y+1];
   }
   else
   {
    textType = arrRandText[y-1];
    textContent = arrRandText[y];
   }

   if(member_array(textType, VALID_AORT_TYPES) == -1)
    return errorMsg(ECODE_TEXT_BADTYPE);
   
   switch(textType)
   {
    string *tmp, *tmp2;
    case "char":
     arrWords[index] += textContent;
     break;
    case "phrase":
     if(index > 0)
      tmp = arrWords[0..index-1];
     else
      tmp = ({ });
     if(index < s)
      tmp2 = arrWords[index+1..s-1];
     else
      tmp2 = ({ });
     arrWords += ({ tmp });
     arrWords += ({ textContent });
     arrWords += ({ tmp2 });
     break;
   }
  }
}

/*
 * Add a random phrase or character to the
 * end of the string, like exclamation marks for
 * effect, or random Pacinoesque rants.
 */
     
void addRandAddendum()
{
 int    index, s;
 string addendumType, addendumContent;

 if(!arrRandAddendum || !(s = sizeof(arrRandAddendum)))
  return;

 index = random(s);

 if(isEvenNumber(index))
 {
  addendumType = arrRandAddendum[index];
  addendumContent = arrRandAddendum[index + 1];
 }
 else
 {
  addendumType = arrRandAddendum[index - 1];
  addendumContent = arrRandAddendum[index];
 }

 if(member_array(addendumType, VALID_AORT_TYPES) == -1)
  return errorMsg(ECODE_ADDENDUM_BADTYPE);
 
 switch(addendumType)
 {
  case "char":
   arrWords[sizeof(arrWords)-1] += addendumContent;
   break;
  case "phrase":
   arrWords += ({ addendumContent });
 }
}

/*
 * Funny name.  We actually build a new string
 * from the words that we have changed.
 * We replace the case-sensitivity as we have
 * saved those values.
 *
 * This will not work very well. So for now
 * (until I implement more advanced procedures
 * for handling case-sensitivity) if the new string
 * is longer OR shorter than the original,
 * we will go ahead and dump the result and not
 * bother case-formatting.
 */

void rebuildText()
{
 int    x, y;
 string sentence;

 sentence = implode(arrWords, " ");
 strNewText = "";
 if(strlen(sentence) != strlen(strOriginalText))
 {
  strNewText = sentence;
  return;
 }
 y = strlen(sentence);
 for(x=0;x<y;x++)
 {
  if(arrCasePositions[x] == UCASE_INT)
   strNewText += capitalize(sentence[x..x]);
  else
   strNewText += sentence[x..x];
 }
}

/*
 * Reset internal variables
 */

void resetVariables()
{
 arrCasePositions = ({});
 strOriginalText = "";
 strNewText = "";
 arrWords = ({ });
 temp = "";
}

/*
 * The parameter is meat because that's what this
 * function is.  The basic meat and potatoes;
 * the driver.
 */

string translateText(string meat)
{
 strOriginalText = meat;

 getCasePositions();
 getWords();

 if(pctDictionaryFreq && (pctDictionaryFreq > random(100)))
  lookupAllInDictionary();

 if(pctRandTextFreq)
  addRandText();

 if(pctRandAddendumFreq && (pctRandAddendumFreq > random(100)))
  addRandAddendum(); 

 if(pctRandFuncFreq && (pctRandFuncFreq > random(100)))
  callRandFunc();

 if(pctPatternsFreq && (pctPatternsFreq > random(100)))
  replaceAllPatterns();
 rebuildText();

 return strNewText;
}

/* Basic set & query functions */

void setDictionaryFreq(int x) { pctDictionaryFreq = x; }
int queryDictionaryFreq() { return pctDictionaryFreq; }

void setDictionary(mapping m) { mapDictionary = m; }
mapping queryDictionary() { return mapDictionary; }

void setRandTextFreq(int x) { pctRandTextFreq = x; }
int queryRandTextFreq() { return pctRandTextFreq; }

void setRandText(string *x) { arrRandText = x; }
string *queryRandText() { return arrRandText; }


void setRandFuncFreq(int x) { pctRandFuncFreq = x; }
int queryRandFuncFreq() { return pctRandFuncFreq; }

void setRandFunc(string *x) { arrRandFunc = x; }
string *queryRandFunc() { return arrRandFunc; }


void setRandAddendumFreq(int x) { pctRandAddendumFreq = x; }
int  queryRandAddendumFreq() { return pctRandAddendumFreq; }

void setRandAddendum(string *x) { arrRandAddendum = x; }
string *queryRandAddendum() { return arrRandAddendum; }

