/* 
 * Forbin
 * Created:   2003.08.08
 * Last edit: 2003.08.08 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This npc is part of the Dervish guild quest for 
 * Nar-Tuith.  It is only accessible by Dervish that are
 * questing, and is not meant to be killed. 
 * (That is why it has 6666 hps, wc 75, and ac 125)
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "albatross" || str == "giant albatross" 
                            || str =="gigantic albatross" 
                            || str == "a gigantic albatross"); }

reset(arg) {
  object gold;
  ::reset(arg);
  if(arg) return;
  
  set_name(ALBATROSS);
  set_race("bird");
  set_gender("female");
  set_short(HIR+"a gigantic albatross"+NORM);
  set_long("\n");
  set_level(25);
  set_hp(6666);
  set_wc(75);
  set_wc(125);
  set_al(0);
  set_wc_bonus(0);
  set_ac_bonus(0);
  set_dead_ob(this_object());
  set_chat_chance(2);
    load_chat("The looks expectantly back towards the horizon.\n");
    load_chat("The albatross gazes at you impatiently.\n");
    load_chat("Flapping is wings, the albatross shakes sand from its feathers.\n");
  set_a_chat_chance(10);
    load_a_chat("The albatross grabs at you with a taloned claw.\n");
    load_a_chat("Your flesh is torn away by the albatross' beak.\n");
    load_a_chat("The albatross flaps its wings, slamming you to the ground.\n");
} 

init() {
  ::init();
  add_action("cmd_mount","mount");
}

cmd_mount(string str) {
  if(!str || str != "albatross" || str != "bird") {
    notify_fail("Mount what?\n");
    return 0;
  }
  say(this_player()->query_name()+" climbs onto the back of the albatross.  The giant\n"+
      "bird takes off into the sky.\n");
  if(environment()->query_where_am_i() == 1) {
    move_object(this_object(),"/players/forbin/dervish/jibboo01.c");
    move_object(this_player(),"/players/forbin/dervish/jibboo01.c");
    write("\nYou climb up onto the albatross and with a great flapping of wings,\n"+
          "it takes off into the sky.  Turning quickly, it takes you out across\n"+
          "the sea, climbing higher and higher.  Soon all that surrounds you are\n"+
          "clouds and mist.  After what seems an eternity, he softly lands upon\n"+
          "an area of sun-drenched rolling sands.  You quickly climb back down.\n\n");
  } 
  else {
    move_object(this_object(),"/players/forbin/dervish/beach01.c");
    move_object(this_player(),"/players/forbin/dervish/beach01.c");
    write("\nYou climb up onto the albatross and with a great flapping of wings,\n"+
          "it takes off into the sky.  Higher and higher she climbs, taking you\n"+
          "through the clounds.  After a bit, you notice the ocean far below you\n"+
          "Several minutes later, the giant albatross safely lands on a beautiful,\n"+
          "deserted beach.  You quickly climb back down.\n\n");
  }
  command("look",this_player());
  say(this_player()->query_name()+" arrives riding upon a giant albatross.\n");
    return 1;
}
