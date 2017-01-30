/*
 * Name changing hotel receptionist NPC
 */

inherit "obj/monster";
#include "def.h"

string Name, name;

id(str)  {
  return str == "clerk" || str == name || str == Name ||
         str == NPCID;
  }

reset(arg){
   int a;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "dune";
   if (a == 2) name = "cathylee";
   if (a == 3) name = "fabien";
   if (a == 4) name = "franswah";
   if (a == 5) name = "clumpy";
   if (a == 6) name = "moby";
   if (a == 7) name = "ahab";
   if (a == 8) name = "billybob";
   if (a == 9) name = "eurale";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the Clerk");
   set_long(Name+" is the "+HOTELNAME+" desk clerk.\n"+
           "Clerks here wear white togas with\n"+
           "gold-colored belts. A large smiley-face\n"+
           "button is pinned to the front of each toga.\n");
   set_level(5);
   set_hp(random(10)+70);
   set_al(0);
   set_wc(9);
   set_ac(5);
   set_whimpy();
}
