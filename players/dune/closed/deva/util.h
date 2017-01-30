/*
 * Ascension, by Dune and Snow
 * Utility functions
 */

#ifndef _UTIL_H_
#define _UTIL_H_


#define SETSIZE       8

/* settings */
#define CLASS         0
#define DISGRACE      1
#define COLOR         2
#define SILENCE       3
#define DEMONBANE     4
#define INFERNALBANE  5
#define UNDEADBANE    6
#define SHADOWBANE    7

#define needrank(L) \
if(this_player()->query_guild_rank() < L) {\
  write("Your guild rank is too low.\n");\
  return 1; }

#define needsp(S) \
if(this_player()->query_spell_point() < S) {\
  write("You are low on power.\n");\
  return 1; }

#define ENABLE_SPIRIT \
status query_spirit() { return 1; } \
provoke_attack(object targetob) { call_out("fight", 0, targetob); } \
fight(object targetob) { this_object()->attack_object(targetob); } \
set_owner(string own) { owner = own; } \
string query_owner() { return owner; }


#endif
