/*
//  Most of these funs were taken directly from
//  /obj/user/waxfuns.c
//
//  Some modifications were made to suit my needs,
//  just figured credit was due.
//    -Forbin
*/

#include "/players/forbin/closed/wiztool/cmds/monthday.h"

#define WRAP 70
#define HWRAP 52
#define LWRAP 70

/* ********************************************************************
 * instr()
 *
 * returns 1 if 'str' is present in 'arg', 0 otherwise
*/
status instr(string arg, string str) {
  string junk, junk2, longstr;
  int ack;

  if (!arg || arg == "")
    return 0;
  longstr = arg+"";
  sscanf(arg,"%s",longstr); /* apparently necessary, *bog* */
  if (longstr == str)
    return 1;
  if (sscanf(longstr,str+"%s",junk) == 1) 
    return 1;
  if (sscanf(longstr,"%s"+str, junk) == 1)
    return 1;
  if (sscanf(longstr,"%s"+arg+"%s",junk,junk2) == 2)
    return 1;
  return 0;
}

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

  if (!instr(text,ESC))
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

varargs string line_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;

  if (!width) width = WRAP;
  
  text = text + ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  for (i = 0; i < siz; i++) {

    count += 1 + ansi_strlen(words[i]);

    if (count > width && words[i] != " ") {
      count = ansi_strlen(words[i]);
      words[i] = "\n" + words[i]+" ";
    }
    else if (words[i] != " ") {
      words[i] += " ";
    }
  }


  text = implode(words, "");
  return text;
}

varargs string help_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;

  if (!width) width = HWRAP;
  
  text = text + ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  for (i = 0; i < siz; i++) {

    count += 1 + ansi_strlen(words[i]);

    if (count > width && words[i] != " ") {
      count = ansi_strlen(words[i]);
      words[i] = "\n    " + words[i]+" ";
    }
    else if (words[i] != " ") {
      words[i] += " ";
    }
  }


  text = implode(words, "");
  return "    " + text;
}

varargs string log_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;
  int tick;

  if (!width) width = LWRAP;
  
  text += ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
  
  text = monthday() + " " + text;  
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  tick = 0;

  for (i = 0; i < siz; i++) {

    count += 1 + ansi_strlen(words[i]);
    if(!tick)
    {
      if (count > width+7 && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
        tick = 1;
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }
    else
    {
      if (count > width && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }    
  }


  text = implode(words, "");
  return text;
}

varargs string atk_tent_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;
  int tick;

  if (!width) width = WRAP;
  
  text += ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
  
  text = monthday() + " " + text;  
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  tick = 0;

  for (i = 0; i < siz; i++) {

    count += 1 + ansi_strlen(words[i]);
    if(!tick)
    {
      if (count > width+7 && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
        tick = 1;
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }
    else
    {
      if (count > width && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }    
  }


  text = implode(words, "");
  return text;
}

varargs string def_tent_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;
  int tick;

  if (!width) width = WRAP;
  
  text += ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
  
  text = monthday() + " " + text;  
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  tick = 0;

  for (i = 0; i < siz; i++) {

    count += 1 + ansi_strlen(words[i]);
    if(!tick)
    {
      if (count > width+7 && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
        tick = 1;
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }
    else
    {
      if (count > width && words[i] != " ") {
        count = ansi_strlen(words[i]);
        words[i] = "\n        " + words[i]+" ";
      }
      else if (words[i] != " ") {
        words[i] += " ";
      }
    }    
  }


  text = implode(words, "");
  return text;
}