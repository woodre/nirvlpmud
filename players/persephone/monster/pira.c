inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(25);
   move_object(gold, TOB);
   set_name("piranha");
   set_short("A savage Piranha");
   set_long("A savage Piranha with sharp teeth maybe you should not\n" +
            "have entered the creek\n\n");
   set_level (1);
   set_wc(5);
   set_ac(3);
   set_hp(15);
   set_al(0);
   set_aggressive(1);
   set_gender(0);
  }
}
