#include "def.h"

inherit MYROOM;

int open;

reset(arg) {
  if (arg) return;
  set_pk(1);
  set_light(1);
  short_desc=HIB+"Dark City"+NORM;
  long_desc=
"     Shadows rule this city of darkness and mystery.  This crowded\n\
street is filled with shops closed down for the perpetual night.\n\
Skyscrapers from different eras of history block the skyline, making\n\
you doubt whether or not there is an end to these maze-like streets.\n\
To the east is a garishly painted aquarium.  There's another alley to\n\
the west.\n";
  items=({
    "shadows","Inky blots of darkness spread by the occasional streetlight",
    "street","Dark-hued cars roll through the streets of the city",
    "shops","Pawn shops, toy stores, repair shops, barber shops, everything you\n"+
            "can imagine, but none of it is open",
    "skyscrapers","Bleak edifices of humanity's achievements block the sky as far\n"+
                  "as you can see",
    "skyline","Buildings, large and small, as far as you can see",
    "building","A tall office building spiraling into the sky to the south",
    "window","A window leading into Neptune's Kingdom.  You see rows of fish\n"+
             "tanks lit up inside",
    "aquarium","A sign above the aquarium says \"Neptune's Kingdom\""
  });
  dest_dir=({
    PATH+"alley4","west",
    PATH+"aquarium","east",
    PATH+"street8","south"
  });
  set_config(call_other(PATH+"controller","query_config"));
}   

init() {
  ::init();
  add_action("cmd_break","break");
  add_action("cmd_break","shatter");
  add_action("cmd_break","smash");
  add_action("cmd_east","east");
  add_action("cmd_open","open");
}

cmd_east() {
  if(!open) {
    write("The door is closed, but there's a window you could try.\n");
    return 1;
  }
  write("You slip into Neptune's Kingdom through the broken window.\n");
  say(this_player()->query_name()+" slips into Neptune's Kingdom through a broken window.\n");
  return 0;
}

cmd_open(str) {
  if(!str) { notify_fail("Open what?\n"); return 0; }
  if(str=="door") {
    write("The door is locked.\n");
    return 1;
  }
  if(str=="window" && !open) {
    write("The window is locked shut.\n");
    say(this_player()->query_name()+" tries to open a window.\n");
    return 1;
  }
  if(str=="window" && open) {
    write("The window is broken.\n");
    return 1;
  }
  notify_fail("Open what?\n");
}

cmd_break(str) {
  if(!str) { notify_fail("Break what?\n"); return 0; }
  if(str=="window") {
    write("You shatter the aquarium's window.\n");
    say(this_player()->query_name()+" shatters the aquarium window.\n");
    open=1;
    return 1;
  }
  if(str=="door") {
    write("You try to batter down the door, but it's too strong.\n");
    say(this_player()->query_name()+" tries to batter open the aquarium's door.\n");
    return 1;
  }
  notify_fail("Break what?\n");
}

void set_config(int arg) {
  switch(arg) {
    case 0:
      dest_dir=({
        PATH+"alley4","west",
        PATH+"aquarium","east",
        PATH+"street8","south"
      });
      break;
    case 1:
      dest_dir=({
        PATH+"street1","north",
        PATH+"alley4","west",
        PATH+"aquarium","east",
        PATH+"street8","south"
      });
      break;
    case 2:
      dest_dir=({
        PATH+"street5","west",
        PATH+"aquarium","east",
      });
      break;
    case 3:
      dest_dir=({
        PATH+"street2","north",
        PATH+"alley4","west",
        PATH+"aquarium","east",
        PATH+"street8","south"
      });
      break;
  }
}