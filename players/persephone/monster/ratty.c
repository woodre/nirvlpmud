inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      gold = clone_object("obj/money");
      gold->set_money(random(900));
      move_object(gold, TOB);  
      set_name("rat");
      set_alias("giant rat");
      set_short("Giant Rat");
      set_long("This must be the largest and most evil looking \n"+
               "species of rat you have ever seen. Their fangs\n" +
               "look like they could cause serious damage.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(0);
      set_aggressive(0);
      set_gender (0);
}

