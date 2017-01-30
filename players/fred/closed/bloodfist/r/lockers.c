inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the walls of the room",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand that has been tracked in",
    "benches",
      "There are a number of simple, wooden benches that sit beneath the\n"+
      "lockers.  They are ideal for sitting on while one puts on or takes\n"+
      "off their equipment",
    "doorway",
      "The doorway leads into the meeting room to the east",
    "sign",
      "The sign hanging near the doorway has information about using "+
      "the lockers",
    "lockers",
      "Each metal locker is a few feet tall about about a foot wide or so\n"+
      "wide.  They all have a slight grating on the front so that air can\n"+
      "get into the lockers.  Each has a lock on it so that the equipment\n"+
      "is protected while the owner is away",
    "lock",
      "Each locker has a lock on it to keep the contents safe",
  });

  dest_dir=({
    DIR + "r/meeting.c",         "east",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This is a dark little side room that has been dug out of the mountain.\n"+
"The walls here are completely lined with metal lockers which can be used\n"+
"to store equipment and items.  There are one or two lit torches in the\n"+
"room providing light.  There are benches around the edge of the room to\n"+
"sit on while you put on your equipment.  The ground is harder here,\n"+
"however there is still much sand which has been tracked in from outside.\n"+
"A sign hangs from the wall beside the doorway east.\n";
  else
    long_desc = 
"  This is a dark little side room that has been dug out of the mountain.\n"+
"The walls here are completely lined with metal lockers which can be used\n"+
"to store equipment and items.  There are one or two extinguished torches\n"+
"in the room.  There are benches around the edge of the room to sit on\n"+
"while you put on your equipment.  The ground is harder here, however\n"+
"there is still much sand which has been tracked in from outside. A sign\n"+
"hangs from the wall besides the doorway east.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("withdraw","withdraw"); /* locker funs */
  add_action("list", "list");        /* locker */
  add_action("deposit","deposit");   /* locker */
  add_action("clear", "clear");      /* locker */
  add_action("buylocker","buy");     /* locker */
  add_action("read", "read");
}

status read(string str)
{
  if(str != "sign") return 0;
  write("The sign reads:\n\n"+
    pad("",4)+BOLD+BLK+"Locker Commands\n"+NORM+
    pad("",6)+pad("1. buy locker",20)+"- purchase 1 of up to 10 locker spaces.\n"+
    pad("",6)+pad("2. withdraw <item>",20)+"- withdraws <item> from locker.\n"+
    pad("",6)+pad("3. deposit <item>",20)+"- deposits <item> in locker.\n"+
    pad("",6)+pad("4. clear <item>",20)+"- clears out a locker space.\n"+
    pad("",6)+pad("5. list",20)+"- displays all items in your locker.\n"+
    "\n");
  return 1;
}

deposit(str){
  "/players/catwoman/tl.c"->deposit_item(str);
  return 1;
}

buylocker(str){
  "/players/catwoman/tl.c"->buy_locker(str);
  return 1;
}

list(){
  "/players/catwoman/tl.c"->list();
  return 1;
}

clear(str){
  "/players/catwoman/tl.c"->clear(str);
  return 1;
}

withdraw(str){
  "/players/catwoman/tl.c"->withdraw_item(str);
  return 1;
}

