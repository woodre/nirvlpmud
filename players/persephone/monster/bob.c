inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
    gold = clone_object("obj/money");
    gold->set_money(random(200));
    move_object(gold, TOB);
      set_name("farmer bob");
      set_alias("farmer");
      set_alias("bob");
      set_alias("man");
      set_short("A struggling farmer");
      set_long("A worker who is loading the transport ship\n"+
               "he seems to be carrying bunches of banana's.\n");
      set_level (15);
      set_wc (20);
      set_ac (12);
      set_hp(225);
      set_al(200);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(50);
      load_chat("Bob nods his head to increase his bid\n");
      load_chat("Bob counts his money\n");
      load_chat("Bob sighs about the weather\n");
      load_chat("Bob says Stormhold was once a bustling town\n");
}
