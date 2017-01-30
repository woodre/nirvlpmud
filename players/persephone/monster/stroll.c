inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(200);
   move_object(gold, TOB);
   set_name("troll");
   set_alias("troll");
   set_short("A Sand Troll");
   set_long("A mutated troll that lives on and near beaches unlike\n" +
            "their cousins that live in forests these troll aren't\n" +
            "agressive at all\n\n");
   set_level (5);
   set_wc(9);
   set_ac(5);
   set_hp(75);
   set_al(-100);
   set_aggressive(0);
   set_gender(0);
  }
}
