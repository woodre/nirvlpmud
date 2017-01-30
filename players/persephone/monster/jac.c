inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("storekeeper");
      set_alias("owner");
      set_alias("salesman");
      set_alias("jack");
      set_short("Junk Shop Owner");
      set_long("This guy is really filthy he is just like his\n"+
               "shop and by the smell you think he has not washed\n"+
               "in ages.\n\n");
      set_level (10);
      set_wc (14);
      set_ac (8);
      set_hp(150);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      load_chat("Jack asks: can I interest you in something?\n");
      load_chat("Jack states: I carry the best Junk around!!\n");
      load_chat("Jack enquires: You are sure you are alright?\n");
      load_chat("Jack looks around and whispers watch out for jeny\n");
      load_chat("Jack says: I know where you can find a cheap room.\n");
      load_chat("Jack says: I have a key in here somewhere.\n");
}
