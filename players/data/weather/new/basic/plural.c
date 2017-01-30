/*
 *  /basic/plural.c
 *  a short version of basic/gender   by Alfe for Tubmud 1996-Jun-18
 *
 *  This version only implements the functions for neuter and plural.
 *
 *  The functions are all varargs and can get an identifier-argument
 *  so that they may be overloaded and fakeitems or components or suchlike
 *  can have a different gender than this_object().
 *  Thus, room->query_plural("books") could return 1, while
 *  room->query_plural() returns 0.
 */

#include <gender.h>

private int gender; 

varargs int query_gender(string str) { 
  return gender; 
}

varargs int query_neuter(string str) { 
  return query_gender(str) == GND_NEUTER; 
}

varargs int query_plural(string str) { 
  return query_gender(str) == GND_PLURAL; 
}

varargs void set_gender(int g,string str) {
  if (g>=GND_NEUTER && g<=GND_PLURAL)
    gender = g;
}

varargs void set_neuter(string str) { 
  set_gender(GND_NEUTER,str);
}

varargs void set_plural(string str) {
  set_gender(GND_PLURAL,str);
}

varargs string query_gender_string(string str) {
  return GND_DESCRIPTIONS[query_gender(str)];
}

varargs string query_pronoun(string str) {
  return GND_PRONOUNS[query_gender(str)];
}

varargs string query_possessive(string str) {
  return GND_POSSESSIVES[query_gender(str)];
}

varargs string query_objective(string str) {
  return GND_OBJECTIVES[query_gender(str)];
}
