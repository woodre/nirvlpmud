inherit "obj/monster";
#include "../DEFS.h"
 
   int a;
   string Name;
 
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "intella";
   if (a == 2) name = "cisco";
   if (a == 3) name = "merced";
   if (a == 4) name = "casper";
   if (a == 5) name = "indri";
   if (a == 6) name = "herzog";
   if (a == 7) name = "aloha";
   if (a == 8) name = "ronler";
   if (a == 9) name = "chip";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the fab technician");
   set_long(Name+" wears a metallic rainbow-colored clean suit.\n"+
            "Amazingly enough, this person is dancing happily while\n"+
            "inspecting the quality of fabricated chips.\n");
   set_level(8);
   set_hp(random(20)+110);
   set_al(0);
   set_wc(13);
   set_ac(8);
   gold=clone_object("obj/money");
   gold->set_money(random(150)+150);
   move_object(gold,this_object());
}
 
id(str)  {
  return str == FAB_NPC || str == "tech" || str == "technician" ||
         str == name || str == Name;
}

string get_name() { return Name; }
