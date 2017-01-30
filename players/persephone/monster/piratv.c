inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      gold = clone_object("obj/money");
      gold->set_money(random(1000));
      move_object(gold, TOB);
      set_name("pirate");
      set_alias("ruffian");
      set_alias("man");
      set_short("A Black Pirate");
      set_long("A burly and strong looking pirate who has a nasty\n"+
               "snarl on his face. By the mark on his arm you can \n"+
               "tell he is one of Vvladimirs trusted pirates.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(100);
      set_aggressive(1);
      set_gender ("male");
      set_a_chat_chance(30);
      load_a_chat("Pirate throws back his head and Cackles Gleefully!!\n");
      load_a_chat("Pirate demands: Where is that torturer he will pay?\n");
      load_a_chat("The Pirate Snickers at you\n");
      load_a_chat("Pirate states: Die fools!!\n");
      load_a_chat("The Pirate glares at you!\n");
      load_a_chat("The Pirate laughs in your face.\n");
      set_chance(15);
      set_spell_dam(15);
      set_spell_mess1("The Pirate twirls throws his hands around\n");
      set_spell_mess2("The Pirate gouges her eyes\n");
}

