#include "/players/quicksilver/closed/color.h"
#define WRAP_DEFAULT 75
/* ********************************************************************
 * Remove Color
 *
 * Returns the string passed minus the color codes.  
 * Mainly useful for formatting text.
*/
string remove_color(string text) {
  int i, siz;
  string *temp;
  string junk;

  if (!text_contains(text,ESC))
    return text;
  temp = explode(text,ESC);
  siz = sizeof(temp);

  for (i = 0; i < siz; i++) 
    sscanf(temp[i], "[%sm%s", junk, temp[i]);

  text = implode(temp,"");
  return text;
}

/* ********************************************************************
 * ansi_strlen()
 *
 * Returns the strlen minus the ansi codes.
*/
int ansi_strlen(string arg) {
  return strlen(remove_color(arg));
}

/* ********************************************************************
 * Formatting Functions
 * 
 * ralign    - pass it text and field size, it returns text right-aligned
 * lalign    - same, but it aligns it to the left, pads the rest
 * center    - returns text centered in field
 * line_wrap - wraps lines ... 76 chars
*/
string lalign(string text, int field) {
  int len, pad, i, ack;
  string str;

  text = text+"";
  len = strlen(remove_color(text));

  if (len > field)
    return "len bigger than field";

  pad = field - len;

  str = "                                                          ";
  text += str[1..pad];
  return text;
}

string ralign(string text, int field) {
  int len, pad, i, ack;
  string str;

  text = text+"";
  str = "                                                    ";
  len = strlen(remove_color(text));

  if (len > field)
    return "len > field";

  pad = field - len;
  text = str[1..pad] + text;

  return text;
}

string center(string text, int field) {
  int i, pad, len, ack;
  string str, extra_pad;

  text = text+"";
  str = "                                                      ";
  extra_pad = "";
  if (text_contains(text,ESC))
    len = strlen(remove_color(text));
  else
    len = strlen(text);

  if (len > field)
    return ("Len: "+len+" Field: "+field);

  pad = (field - len)/2;

  if ((pad * 2) + len < field)
    extra_pad = " ";

  text = str[1..pad] + text + str[1..pad] + extra_pad;
  return text;
}

string line_wrap(string text, int hangident, int length) {
  string *words, str;
  int i, siz, count;

  text = text + ""; /* types don't always maintain integrity */
  count = 0;
  str = "                                                                           ";
  if(!length) length = WRAP_DEFAULT;
  if (ansi_strlen(text) < length)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  for (i = 0; i < siz; i++) {
	count += 1 + ansi_strlen(words[i]);
    if (count > length) {
      while (words[i] == "") {
	    words = words[0..i-1] + words[i+1..siz];
		siz--;
	  }
      count = ansi_strlen(words[i]) + hangident;
      words[i] = "\n" + (hangident ? str[1..hangident] : "") + words[i];
    }
  }

  text = implode(words, " ");
  return text;
}