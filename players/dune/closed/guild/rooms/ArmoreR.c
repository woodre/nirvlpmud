inherit "obj/monster";
#include "../DEFS.h"

   int a;
   string Name;

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "blast";
   if (a == 2) name = "odaisan";
   if (a == 3) name = "ed";
   if (a == 4) name = "beafcake";
   if (a == 5) name = "olga";
   if (a == 6) name = "skee";
   if (a == 7) name = "ursula";
   if (a == 8) name = "telsa";
   if (a == 9) name = "mary Joe";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the armorer");
   set_long(Name+" is a well-established armorer who specializes\n"+
            "in durable highly-protective, yet light armors.\n"+
            "The armor sold here is of cloth-like texture, but\n"+
            "metal-like strength.\n");
   set_level(16);
   set_hp(random(30)+400);
   set_al(0);
   set_wc(18);
   set_ac(19);
   gold=clone_object("obj/money");
   gold->set_money(random(650)+700);
   move_object(gold,this_object());
}

id(str)  {
  return str == ARMOR_NPC || str == "armorer" ||
         str == name || str == Name;
}

string get_name() { return Name; }
