#include <ansi.h>
inherit "/obj/monster";
#define MM HIR+"Magma"+NORM+"man"

reset(arg) {
  int tres;
  ::reset(arg);
  if(arg) return;
  set_name(HIR+"Magma"+NORM+"man");
  set_alias("magmaman");
  set_short(HIR+"Magma"+NORM+"man");
  set_long(
  "A stoic Magmaman.  These volitile creatures live deep below the\n"+
  "surface of the world.  They thrive on the molten lava that runs\n"+
  "through these caverns.  Their bodies are thick and solid.  Rough\n"+
  "craggy spikes line their tough hides.\n");
  set_race("magma man");
  set_level(17);
  set_hp(425);
  set_ac(12);
  set_wc(26);
  set_al(-(500 + random(1000)));
  if(!random(3)) set_aggressive(1);
  else set_aggressive(0);
  set_a_chat_chance(30);
  set_chat_chance(30);
  load_chat(MM+" wades through the lava.\n");
  load_chat(MM+" stares into the lava.\n");
  load_chat("A "+MM+" considers throwing you into the lava river.\n");
  load_a_chat(MM+" tries to throw you into the lava river!\n");
  load_a_chat("The "+MM+" scoops up a hand full of lava.\n");
  load_a_chat(MM+" steps into the lava and feels better.\n");
  tres = random(4);

  if(tres == 0)
       move_object(clone_object("players/pavlik/items/ilstkarn/fire_stones"),
       this_object());
  else if(tres == 1)
       move_object(clone_object("players/pavlik/items/heals/lava_drink"),
       this_object());
  else if(tres == 2)
       money = 400 + random(400);

  message_hit= ({
    "throws a ball of burning Lava on", "",
    "beats", " with a heavy fist",
    "spits a stream of laval at", "",
    "throws a ball of burning Lava on", "",
    "pummels", " with a heavy fist",
    "headbutts",
    "punches",
  });
}

stop_fight() {
  if(!random(4)) {
    ::stop_fight();
    return 1;
  }
  return;
}

