inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
    gold = clone_object("/players/persephone/object/gold");
    move_object(gold, TOB);
      set_name("mate");
      set_alias("pirate");
      set_short("The First Mate");
      set_long("A rotund speciman of humankind if he is indeed\n"+
               "human. He looks like he could chew up many people\n"+
               "for breakfast\n");
      set_level (18);
      set_wc (26);
      set_ac (15);
      set_hp(450);
      set_al(-500);
      set_aggressive(0);
      set_gender ("male");
      set_chance(20);
      set_spell_dam(30);
        set_spell_mess1("Grasps his arms around his nearest oponent");
        set_spell_mess2("Gives you a bearhug.");
      set_chat_chance(20);
      set_a_chat_chance(30);
      load_chat("The mate glares at you you have your orders.\n");
      load_chat("The mate shouts: Stop your slacking!\n");
      load_chat("The mate says: We leave tonight!\n");
      load_a_chat("The mate says: I will have you put in shackles for this\n");
      load_a_chat("The mate curses you\n");
      load_a_chat("The mate spits on your face in fury\n");
}
init(){
  ::init();
    add_action("gerble","up");
    add_action("gerble","u");
    add_action("gerble","south");
    add_action("gerble","s");
}
gerble(){
  write("The Mate blocks your way\n");
  say("The mate blocks " + CAPTPLNM + "'s way\n");
return 1;
}
