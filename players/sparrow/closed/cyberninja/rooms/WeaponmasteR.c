inherit "obj/monster";
#include "../DEFS.h"

   int a;
   string Name;

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "camaris";
   if (a == 2) name = "scar";
   if (a == 3) name = "orion";
   if (a == 4) name = "athena";
   if (a == 5) name = "bambam";
   if (a == 6) name = "maximillian";
   if (a == 7) name = "ronny";
   if (a == 8) name = "thu";
   if (a == 9) name = "she-ra";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the weaponmaster");
   set_long(Name+" is a brilliant weapon-maker and quite a\n"+
         "fighter too.  You are lucky to be serviced by one\n"+
         "so knowledgeable in weapon creation and combat tactics.\n");
   set_level(16);
   set_hp(random(30)+410);
   set_al(0);
   set_wc(24);
   set_ac(13);
   gold=clone_object("obj/money");
   gold->set_money(random(650)+600);
   move_object(gold,this_object());
}

 id(str)  {
  return str == WEAPON_NPC || str == "weaponsmaster" ||
         str == name || str == Name;
 }

string get_name() { return Name; }
