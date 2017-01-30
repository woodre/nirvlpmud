#include "/include/mudlib.h"
inherit ROOM;

object lum;
int i;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
    "file", "room/newbie/new7",
    "direction", "south door",
    "long", "A sturdy wooden door to the cabin.\n",
    "key id", "city key",
  }));
  if (!arg) {
    set_short("Cabin");
    set_long(
"You are inside a small cabin.  The ceiling is just barely high enough \n"+
"for elves to enter.  Maybe a few dwarves can fit in too.  The cabin is\n"+
"pretty well built.  The logs seem new and quite sturdy.  The floor is \n"+
"just dirt.  You can see the eating quarters to the north.\n");
    set_exits(({
      "/room/newbie/pub", "north",
    }));
    set_weather(2, 4, 3);
    set_items(({
      "floor", "A dirt floor",
      "logs",  "Round wooden logs",
    }));
  }
  if (!present("elf")) {
    for (i=0; i<3; i++) {
      lum = clone_object(MONSTER);
      lum->set_name("elf");
      lum->set_short("A wood elf");
      lum->set_alias("elf");
      lum->set_long(
"This is one of the more powerful elves.  His muscles are bulging out  \n"+
"of his little elvish suit.  He stands only about 4 ft tall, but in    \n"+
"battle, one might think he's a giant.  He spends his time carving wood\n"+
"and trading his wares with the humans in the city.\n");
      lum->set_level(5);
      lum->set_ac(5);
      lum->set_wc(9);
      lum->set_gender(1);
      lum->add_money(200);
      lum->set_race("wood elf");
      move_object(lum, this_object());
    }
  }
}

