#ifndef  _UTIL_H_
#define  _UTIL_H_


#define needrank(L) \
if(this_player()->query_guild_rank() < (int)L) {\
  tell_object(this_player(),\
    "Your guild rank is too low.\n");\
  return 1; }

#define needsp(S) \
if(this_player()->query_spell_point() < (int)S) {\
  tell_object(this_player(),\
    ("You are low on power.\n");\
  return 1; }


#endif
