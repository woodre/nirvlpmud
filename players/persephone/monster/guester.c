inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
object paper;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      gold = clone_object("obj/money");
      gold->set_money(random(300));
      move_object(gold, TOB);  
      paper = clone_object("/players/persephone/obj/news.c");
      move_object(paper, TOB);
      set_name("guest");
      set_alias("man");
      set_alias("tourist");
      set_short("Hotel Guest");
      set_long("A Tourist of fair Stormhold minding his own business.\n"+
               "He seems to be reading a newspaper.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(500);
      set_aggressive(0);
      set_gender (0);
      set_chat_chance(15);
      load_chat("Tourist says: Service has certainly dropped off at this hotel\n");
      load_chat("The tourist turns over another page of the paper\n");
      load_chat("The tourist looks around warily\n");
      load_chat("The tourist drinks from a cracked cup\n");
}

