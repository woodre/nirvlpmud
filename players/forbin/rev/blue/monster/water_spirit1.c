#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Water Spirit");
  set_alt_name("water spirit");
  set_alias("small water spirit");
  set_race("spirit");
  set_short(HIC+"Water Spirit"+NORM);
  set_long(
    "Some of the fountain's water has been possessed by a spirit and\n"+
    "has taken a somewhat humanoid shape.  A very distinct upper torso\n"+
    "can be seen, while the lower torso disappears into a swirling mass\n"+
    "in the shape of a funnel.  Its two large arms are very powerful\n"+
    "looking.  It turns its head from side to side, as if its blank\n"+
    "face, without eyes, nose, or mouth can sense a presence.\n");
  set_level(20);
  set_hp(1080);
  set_wc(40);
  set_ac(20);
  if(!random(3)) set_aggressive(1);
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Water Spirit swirls about you...\n");
    load_chat("The water around you bubbles as the Spirit howls...\n");    
  set_a_chat_chance(20);
    load_a_chat("You feel a wave of water as the Water Spirit stikes you\n");    
  add_money(4000+random(2001));
  add_spell("attack_one",
    "You suck in a mouthful of water as the $HB$Water Spirit$N$ levels you with\n"+
    "a powerful blast of water!  You feel as if you are going to drown.\n",
    "The $HB$Water Spirit$N$ knocks #CTN# for a loop with a blast of water.\n",
  10+random(16), "16-40", "other|water");   
}

monster_died() {
  object spirit;
  spirit = present("water spirit", environment(this_object()));
  if(!spirit)
    environment(this_object())->stop_churn();
  tell_room(enivronment(),
    "The water calms as the last Water Spirit dies.\n");
  return 1;
}