inherit "obj/monster";
#include "follow.h"
   object gold;
reset(arg){
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("A student");
     set_long("This is likely a freshman student, very worried about his upcoming finals.\n"+
              "For this reason,  he is carefully attending the classes and hard studying\n"+
              "the subjects.  He really wants to learn more.\n");

   set_level(13);
   set_hp(200);
   set_al(-10);
   set_wc(17);
   set_ac(10);
 gold = clone_object("obj/money");
 gold->set_money(random(150)+600);
 move_object(gold,this_object());
}

