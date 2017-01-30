inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  object body;
  if(body=present("ill_imm_body",this_object())) {
    tell_room(this_object(),"Suddenly, the body comes to life!\n");
    destruct(body);
  }
  if(!present("Amanda",this_object()))
    move_object(clone_object(HMON+"amanda"),this_object());
  if(arg) return;

  set_light(1);
  short_desc="An old-fasioned bedroom";
  long_desc=
"You stand in a plush room that fairly reeks of wealth and dubious taste.\n"+
"The dominant feature of the room is the large, four-postered and\n"+
"canopied bed set against one wall.  Opposite the bed is a large wooden\n"+
"dresser and large mirror.  A moderate sized window and a large wooden\n"+
"door face each other across the bed.\n",

  items= ({
    "room","Probably a guest room in a relatively new structure..",
    "bed","Nice and solid in addition to being fancy.  It looks a bit\n"+
          "mussed too",
    "dresser","Carved wood with several drawers.  Looking closer,\n"+
               "you notice that the drawers are slightly open, and\n"+
               "appear to have been ransacked",
    "wall","The walls are whitewashed and clean",
    "door","The door is large, but seems more decorative\n"+
            "than functional",
    "window","The large window is covered by lacy curtains, but they don't hide\n"+
             "the fact it is wide open",
  });
  dest_dir= ({
    HROOM+"abedroom","door",
    HROOM+"aledge","window",
  });
}
void init() {
  ::init();
  add_action("cmd_door","door");
  add_action("cmd_window","window");
}
cmd_door() {
  if(present("Amanda",this_object())) {
    write("Amanda stands in your way and says, \"Leaving already?\"\n");
    say(TPN+"'s attempt to use the door is blocked by Amanda.\n");
  } else {
    write("You open the door a bit, and hear soldiers shouting about\n"+
          "a thief.  Perhaps a more discreet exit is in order?\n");
    say(TPN+" opens the door, but closes it again after listening briefly.\n");
  }
  return 1;
}
cmd_window() {
  if(present("Amanda",this_object())) {
    write("Taking Amanda by surprise, you step out the window.\n");
  }
  return 0;
}
