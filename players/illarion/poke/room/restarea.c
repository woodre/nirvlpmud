inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;

  set_light(1);
  set_short("A small rest area");
  set_long(
"This small, one-room cabin has a peaceful, safe feeling to it.  A few "+
"comfortable chairs are distributed along the walls, underneath a set of "+
"paintings.  In one corner sits a small monitor and keyboard, the screen "+
"glowing slightly.  "+
"At the north and south ends of the cabin, a door stands open, "+
"leading out of the cabin.");

  add_exit("north",PROOM+"field3,5");
  add_exit("exit",PROOM+"ontrail");

  add_item("chairs","Institutional-type chairs, designed to be stackable and "+
                    "easy to move, but they still look like they'd be all "+
                    "right to sit on if you were tired, and didn't mean to "+
                    "stay very long.");
  add_item("paintings","The paintings are all of fantastic-looking creatures, "+
                       "like none you've ever seen before.  Three are of "+
                       "exotic-looking birds, each different, and the fourth "+
                       "is of a creature that looks a little bit like a cat, "+
                       "but is otherwise totally unfamiliar.");
  add_item("monitor","Looking closer, you see that the monitor is connected "+
               "to a computer hidden behind it.  The screen iteself reads, "+
               "'Pokemon trainer login:', following by a blinking cursor.");
  add_item("computer","This computer looks like it's seen quite a bit of use "+
                      "over the years.");
  add_item("keyboard","A well-used keyboard, in front of the monitor.  The "+
                      "keys are marked in english, and you could probably "+
                 BLD("type")+" something on it.\n");
}
void init() {
  ::init();
  add_action("cmd_type","type");
  add_action("go_north","north");
}
int go_north() {
  call_other("/players/illarion/poke/room/vroomcon","move_me",this_player(),
    3,6,"north");
  return 1;
}
int cmd_type(string str) {
  if(!str) FAIL("Type what?\n");
  say(TPN+" types something on the keyboard.\n");
  write("After a short moment of waiting, the computer prints out:\n"+
        "\"Trainer unknown\"\n"+
        "The screen then resets to its original login prompt.\n");
  return 1;
}
