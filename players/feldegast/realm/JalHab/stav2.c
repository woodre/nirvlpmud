#include "defs.h"

inherit "/players/feldegast/std/generic_pub.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("waittress"))
    move_object(clone_object(MON_PATH+"belinda.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="The Bloated Toad";
  long_desc=
"  This end of the tavern is stiflingly hot.  A wooden staircase\n\
ascends up and over the mahogany bar.  A pass-thru is on the end\n\
of the bar opposite the staircase and leads into the kitchen.\n\
Next to the kitchen door, a menu is posted on a chalkboard.\n";
  items=({
    "staircase","A wooden staircase that ascends up and over the bar",
    "bar","It is battered, but clean",
    "chalkboard","It lists the menu and dishes",
    "pass-thru","It is up so the waitresses can 'pass-thru' it",
  });
  dest_dir=({
    PATH+"stav1.c","south",
    "fake exit","north",
    PATH+"stav3.c","up",
  });
/* I was using the chart in /doc/build/RULES/heals/heal1 when I was doing these. */
  add_item("Mead",({ "mead" }),
    "You order some imported mead.\n",
    " orders some mead.\n",
    350,35,14,"intox");
  add_item("Red Rum",({ "rum", "red rum" }),
    "You order some red rum.\n",
    " orders some red rum.\n",
    500,50,14,"intox");
  add_item("Siqi",({ "siqi" }),
    "You order some siqi, a local alcoholic drink that is infamously sour.\n",
    " orders some siqi and puckers up.\n",
    700,50,10,"intox");
  add_item("Lemonade", ({ "lemonade", "ade" }),
    "You order some refreshing lemonade.\n",
    " orders some lemonade.\n",
    360,30,12,"soak");
  add_item("Mint Tea", ({ "iced tea", "tea" }),
    "You order some fragrant mint tea.\n",
    " orders some mint tea.\n",
    640,40,8,"soak");
  add_item("Cactus juice",({ "juice", "cactus juice" }),
    "You order some fresh cactus juice.\n",
    " orders some cactus juice.\n",
    1000,50,6,"soak");
  add_item("Falafels",({ "falafel","falafels" }),
    "The waittress brings you a hot steaming plate of fresh fried falafels.\n",
    " orders falafels.\n",
    385,35,13,"stuff");
  add_item("Taboulleh",({ "taboulleh","tab" }),
    "The waittress brings you a plate of taboulleh salad and a basket of\n"+
    "thin pitas.\n",
    " orders some taboulleh.\n",
    630,45,10,"stuff");
  add_item("Lamb Kebabs",({ "lamb","kebabs","lamb kebabs" }),
    "You order a plate of skewers with pieces of charred lambs interleaved\n"+
    "with peppers, onions, and tomatoes.\n",
    "orders lamb kebabs.\n",
    800,50,8,"stuff");    
  add_item("Baklava",({ "baklava" }),
    "The waittress brings out a tasty slice of sticky sweet baklava.\n",
    " orders some baklava.\n",
    600,40,9,"stuff");
}

void init() {
  ::init();
  add_action("cmd_bad","north");
  add_action("cmd_read","read");
}

int cmd_bad(string str) {
  write("You decide not to disturb the cook.\n");
  return 1;
}

int cmd_read(string str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str!="board" &&
     str!="sign" &&
     str!="chalkboard" &&
     str!="menu") {
    notify_fail("Read what?\n");
    return 0;
  }
  cmd_list(0);
  return 1;
}
