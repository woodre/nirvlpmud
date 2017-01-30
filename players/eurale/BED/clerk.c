/*
 * Name changing hotel receptionist NPC
 */

#include "def.h"
inherit "obj/monster";

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
   if (a == 2) name = "arrina";
   if (a == 3) name = "snow";
   if (a == 4) name = "nooneelse";
   if (a == 5) name = "cosmo";
   if (a == 6) name = "pain";
   if (a == 7) name = "beck";
   if (a == 8) name = "wocket";
   if (a == 9) name = "eurale";

set_name(name);
set_race("human");
set_alias(name);
Name = capitalize(name);
set_short(Name+", the Clerk");
set_long(Name+" is the "+HOTELNAME+" desk clerk.\n"+
  "  The desk clerks of the Jurassic Park Bed and Breakfast wear\n"+
  "green, jungle outfits with canvas belts and a smart looking\n"+
  "pith helmet.  Their white over-the-calf socks contrast nicely with\n"+
  "black, lace-up hiking boots.\n");
   set_level(5);
   set_hp(random(10)+70);
   set_al(0);
   set_wc(9);
   set_ac(5);
   set_whimpy();
}
