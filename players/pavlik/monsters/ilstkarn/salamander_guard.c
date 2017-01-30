#include <ansi.h>
inherit "/obj/monster";
#define SAL HIR+"Salamander"+NORM

reset(arg) {
  int tres;
  ::reset(arg);
  if(arg) return;
  set_name(SAL);
  set_alt_name("salamander guard");
  set_alias("guard");
  set_short("a "+SAL+" Guard");
  set_long(
  "Salamander's are lesser elemental's of fire.  They are lizard-like\n"+
  "an appearance, but walk upright like men.  The Guard is larger and\n"+
  "more fierce looking than the average Salamander.  You wonder what\n"+
  "he is guarding.\n");
  set_race("salamander");
  set_level(20);
  set_hp(550);
  set_al(-1000);
  set_aggressive(1);
  set_a_chat_chance(25);
  load_a_chat(SAL+" Guard threatens you in a gutteral languange.\n");
  load_a_chat(SAL+" Guard calls for help!\n");
  load_a_chat(SAL+" kicks you in the shin!\n");
  load_a_chat(SAL+" scoops up a handful of lava.\n");
  load_a_chat(SAL+" Guard steps into the lava and feels better.\n");
  tres = random(6);
  if(tres == 0)
       move_object(clone_object("players/pavlik/items/blue_potion"),
       this_object());
  else if(tres == 1)
       move_object(clone_object("players/pavlik/items/heals/lava_drink"),
       this_object());
  else if(tres == 2)
       move_object(clone_object("players/pavlik/items/green_potion"),
       this_object());
  else if(tres == 3)
       money = 2200 + random(800);

  move_object(clone_object("players/pavlik/weapons/fire_spear"),
  this_object());
  command("wield fire_weapon", this_object());
  set_wc(30+random(10));
  set_ac(17);
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

init() {
  ::init();
  add_action("nope", "east");
}

nope() {
  write("The Guard will not let you pass!\n");
  return 1;
}

