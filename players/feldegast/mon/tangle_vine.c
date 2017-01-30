#include "/players/feldegast/defines.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tangle vine");
  set_alt_name("vine");
  set_short(HIG+"Tangle Vine"+NORM);
  set_long(
"This is a thick, green tangle of vines sprouting up out of the ground with\n"+
"its lithe tendrils.\n"
  );
  set_race("plant");
  set_level(5);
  set_wc(1);
  set_ac(5);
  set_hp(250); /* High hp for low wc and limited duration */
  set_al(0);
  set_chat_chance(5);
  set_a_chat_chance(5);
}
