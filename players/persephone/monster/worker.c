inherit "obj/monster";
#include "/players/persephone/rooms.h"
object ban;
int i;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      for(i=0;i<2;i++){
        ban = clone_object("players/persephone/heal/banana");
        move_object(ban, TOB);
      }
      set_name("worker");
      set_alias("worker");
      set_alias("workman");
      set_alias("labourer");
      set_short("A Labourer or Worker");
      set_long("A worker who is loading the transport ship\n"+
               "he seems to be carrying bunches of banana's.\n");
      set_level (15);
      set_wc (20);
      set_ac (12);
      set_hp(225);
      set_al(-50);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      load_chat("The Worker sings: Day Oh Daaaayyyy Ooh\n");
      load_chat("The Worker carries a bunch of bananas on to the boat\n");
      load_chat("The Worker sings Daylight comes and me wanna go home\n");
      load_chat("The Worker sings I work all night for a drink of rum\n");
}
