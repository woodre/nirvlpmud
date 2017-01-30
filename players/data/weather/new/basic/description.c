/*
 * basic/description.c - Give a description to an object.
 * Feb 1992 by marion@cs.tu-berlin.de
 *
 * migrated with basic/compat245/description, Coogan, 19-Dec-1998
 *
 */

#pragma strong_types

#include <message.h>
#include <libs.h>

string query_composite_long (string str);

private mixed short_desc;
private mixed long_desc;
private mixed extra_long_desc, extra_look_desc;
private mixed name_desc;  // changed string to mixed, Coogan, 26-Nov-1998


//***************** The part of name/short/long descriptions *****************

// The short description should not have a newline at the end, nor a '.'.
// varargs necessary because of complex/room::set_short, Carador.
varargs void set_short(mixed str) {
  short_desc = str;
}

// The long description should include a newline at the end.
// varargs necessary because of complex/room::set_long, Coogan, 24-Oct-1997.
varargs void set_long(mixed str) {
  long_desc = str;
}

void set_extra_long(mixed str) {
  extra_long_desc = str;
}

void set_extra_look(mixed str) {
  extra_look_desc = str;
}

// Since describe allows even invisible objects to be described with their
// name, it should be possible for every object to have one
void set_name(mixed name) {
  name_desc = name;
}

string query_name() {
  return funcall(name_desc);
}

string query_short() {
  return funcall(short_desc);
}

// made varargs because of save_types, Coogan, 26-Sep-2010
varargs string query_long(string str) {
  return funcall(long_desc ? long_desc : query_composite_long(str), str);
                        // arg 'str' added to funcall(), Coogan, 30-Jun-2003
}

// Because several objects from /complex overload the three functions above,
// there must be a way to provide the name, short and long description.
// Coogan, 01-Apr-1998

string query_real_name() {
  return funcall(name_desc);
}

string query_real_short() {
  return funcall(short_desc);
}

#if 1  // Coogan, 27-Sep-2010, trying to keep things simple
string query_real_long() {
  return funcall(long_desc);
}
#else
varargs string query_real_long(string str) {
  // made varargs, Coogan, 27-Sep-2010
  return funcall(long_desc ? long_desc : query_composite_long(str));
}
#endif

string query_description_long(string str) {
  return funcall(long_desc ? long_desc : query_composite_long(str));
}

string short() {
  return query_short();
}

varargs string long(string str) {
  return query_long(str);
}

string extra_long() {
  return funcall(extra_long_desc);
}

mixed extra_look() {
  return funcall(extra_look_desc);
}

/* this is just for timedepdesc, it will be removed as soon as possible */
// not so soon, I think :-)   Coogan, 01-Apr-1998
// mixed arg instead of str, Coogan, 27-Sep-2010
// changed to type void instead of string, Coogan, 24-Mar-2011
void set_description_long(mixed str) {
  long_desc = str;
}

/* muxestba Aug 93 - this has been a great nuisance before. */
string query_composite_long(string str) {
  return 0;
}


//*********** The part of taste/smell/touch/sound descriptions ****************

// sound-related functions added by Ugh Oct-15-1998

private mixed taste;
private mixed smell;
private mixed touch;
private mixed sound; 
private mixed colour;

void set_taste(mixed m) {
  taste = m;
}

void set_smell(mixed m) {
  smell = m;
}

void set_touch(mixed m) {
  touch = m;
}

void set_sound(mixed m) {
  sound = m;
}

void set_colour(mixed c) {
  colour = c;
}

varargs string query_taste(string id) {  // made varargs, Coogan, 27-Feb-2002
  string res;
  if (closurep(taste))
    res = funcall(taste, id);
  else
    res = taste;
  if (!res)
    return 0;                   // it has no special taste (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "taste",
                                      " " + res + ".\n" })));
}

varargs string query_smell(string id) {
  string res;
  if (closurep(smell)) 
    res = funcall(smell, id);
  else
    res = smell;
  if (!res)
    return 0;                   // it has no special smell (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "smell",
                                      " " + res + ".\n" })));
}

varargs string query_touch(string id) {
  string res;
  if (closurep(touch))
    res = funcall(touch, id);
  else
    res = touch;
  if (!res)
    return 0;                   // it has no special touch (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_S, M_ME_PRONOUN, " touch ", M_ME_VERB,
                                      "be", " " + res + ".\n" })));
}

varargs string query_sound(string id) {
  string res;
  if (closurep(sound))
    res = funcall(sound, id);
  else
    res = sound;
  if (!res)
    return 0;                   // it has no special sound (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "sound",
                                      " " + res + ".\n" })));
}

mixed query_colour() {
  return colour;
}

string query_real_taste() {
  return funcall(taste);
}

string query_real_smell() {
  return funcall(smell);
}

string query_real_touch() {
  return funcall(touch);
}

string query_real_sound() {
  return funcall(sound);
}

string query_colour_description() {
  return query_colour() && LIB_COLOURS->get_colour_name(query_colour());
}

#if 0  // not needed anymore, Coogan, 22-Apr-2002
varargs string query_taste_string(string id) {
    // made varargs, Coogan,27-Feb-2002
  if (!query_taste(id))
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "have",
                                        " no particular taste." })));
  else
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "taste",
                                        " ", M_APPLY, #'query_taste, ({ id }),
                                        "." })));
}

string query_smell_string() {
  if (!query_smell())
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "have",
                                        " no particular smell." })));
  else
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "smell",
                                        " ", #'query_smell, "." })));
}

string query_touch_string() {
  if (!query_touch())
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "have",
                                        " no special touch." })));
  else
    return capitalize(message2string(({ M_S, M_ME_PRONOUN, " touch ", M_ME_VERB,
                                        "are", " ", #'query_touch, "." })));
}

string query_sound_string() {
  mixed h;
  if (!(h = query_sound()))
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "have",
                                        " no special sound." })));
  else
    return h;
}
#endif


// ********************** The part of other descriptions *********************

// size related functions added by Coogan, 09-Apr-1998

private mixed size;   // the size of compact items in cm, e.g. a ball
                      // if (intp()), then it's an absolute size
                      // if (stringp()), then it's a macro of <size.h>
                      // changed to mixed, Coogan, 28-Nov-2002

mixed query_size() {
  return size;
}

void set_size(mixed s) {
  if (intp(s)) {
    if (s > 0)
      size = s;
  }
  else
    size = s;
}

