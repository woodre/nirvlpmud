/*
 *  /basic/gender.c     (was /obj/living/gender.c  Alfe 1995-Feb-11)
 */

/*
  Technical objects which represent more than one alike real objects (boots
  for example) and only carry the pluralized short description ("boots" or
  "leather boots" or such) should get the gender plural to make it easier
  to find the correct term for more than one technical objects of them. Up
  to now those boots became "two bootses" if a player got two pairs of them
  in its inventory, the same happened in the shop's (Version 95) list.
  The simul_efun describe() handles those items correctly if they have the
  gender plural set.
*/

#include <gender.h>

inherit "basic/plural";

varargs int query_male(string str) { 
  return query_gender(str) == GND_MALE; 
}

varargs int query_female(string str) { 
  return query_gender(str) == GND_FEMALE; 
}

varargs void set_male(string str) { 
  set_gender(GND_MALE,str);
}

varargs void set_female(string str) { 
  set_gender(GND_FEMALE,str);
}
