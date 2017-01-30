#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/monster.c";

object Blade;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Blade=clone_object(ROOT+"weapons/spirit_blade.c");
  move_object(blade, this_object());
  command("wield blade", this_object());  
  set_name("Water Spirit");
  set_alt_name("water spirit");
  set_alias("large water spirit");
  set_race("spirit");
  set_short(HIB+"Water Spirit"+NORM);
    "Some of the fountain's water has been possessed by a spirit and\n"+
    "has taken a somewhat humanoid shape.  A very distinct upper torso\n"+
    "can be seen, while the lower torso disappears into a swirling mass\n"+
    "in the shape of a funnel.  Its three big arms are very powerful\n"+
    "looking, and it holds a sword in its third hand.  This water\n"+
    "spirit is very large and looks very strong.\n");
  set_level(21);
  set_hp(1300);
  set_wc(50);
  set_ac(20);
  if(!random(3)) set_aggressive(1);  
  set_dead_ob(this_object());  
  set_chat_chance(5);
    load_chat("The Water Spirit swirls about you...\n");
    load_chat("The water around you bubbles as the Spirit howls...\n");    
  set_a_chat_chance(20);
    load_a_chat("You feel a wave of water as the Water Spirit stikes you\n");    
  add_spell("attack_one",
    "You suck in a mouthful of water as the $HC$Water Spirit$N$ levels you with\n"+
    "a powerful blast of water!  You feel as if you are going to drown.\n",
    "The $HC$Water Spirit$N$ knocks #CTN# for a loop with a blast of water.\n",
  25, "26-60", "other|water");     
  add_money(4500+random(2001));    
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