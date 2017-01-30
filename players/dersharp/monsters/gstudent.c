inherit "obj/monster";
#include "ex.h"
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("student");
   set_race("human");
   set_alias("student");
   set_short("A female university student");
   set_long("A typical student of GREY UNIVERSITY and as such is a snotty brat.\n"+
            "She will do ANYTHING to get a passing grade....\n");
   set_level(15);
   set_hp(225);
   set_al(-10);
   set_wc(20);
   set_ac(12);
   set_chat_chance(2);
   load_chat("Student says: How will I ever get a passing grade????\n");
   load_chat("Student winks at the professor seductively.\n");
   gold=clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,TOB);
}
