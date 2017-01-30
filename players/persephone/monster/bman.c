inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
object wobble;
reset(arg) {
  ::reset(arg);
    if(arg) return;
    gold = clone_object("obj/money");
    gold->set_money(random(300));
    move_object(gold, TOB);
      set_name("business man");
      set_alias("man");
      set_alias("executive");
      set_short("A Stylish Executive");
      set_long("A trendy business executive looking for a slave\n"+
               "as a status symbol he is definately not from here.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(-250);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(50);
      load_chat("The Executive waves his hands exubarantly\n");
      load_chat("The Executive looks around happily\n");
      load_chat("The Executive whistles a cheery tune\n");
      load_chat("The Executive says: You know I can outbid you\n");
}
second_life(){
    wobble=clone_object("players/persephone/closed/niny");
    move_object(wobble, TPL);
    ::second_life();
}
