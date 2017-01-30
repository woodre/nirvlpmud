#include "/players/feldegast/defines.h"

inherit ROOM;

int door;

reset(arg) {
  if(!present("portal")) {
    object portal;
    portal=clone_object("/players/feldegast/obj/azure_portal.c");
    portal->set_destination("/players/feldegast/shrine.c");
    move_object(portal, this_object());
  }
  if(!present("chest")) {
/*
    move_object(clone_object("/players/feldegast/obj/magic_chest"),this_object());
*/
  }
  if(arg) return;
  short_desc="Clearing";
  long_desc=
"  This is a small clearing at the bottom of a magnificent tower, made\n"+
"out of marble with a sparkling clear crystal at the pinnacle.  At\n"+
"the bottom of the tower is a strong iron banded door with a few small\n"+
"steps leading up to it.  A parchment note is tacked onto the door\n"+
"just beneath the knocker.  The clearing is surrounded on all sides by\n"+
"thick foliage and trees.\n";
  set_light(1);
  dest_dir=({
  });
  items=({
    "door","A door with a gap under it.  You could 'scribble' a note and slip\n"+
           "it beneath Feldegast's door.  There's also a note tacked on the door",
    "tower","The tower is a magnificent display of magic and engineering, extending\n"+
            "high into the sky with it's smooth white walls and shining pinnacle",
    "crystal","The huge crystal at the pinnacle of the tower is a many-faceted gem.\n"+
              "You suspect it is there strictly for aesthetics",
    "note","A parchment note written with an elegant, flowing script.\n"+
           "Perhaps you can read it",
    "parchment","A parchment note written with an elegant, flowing script.\n"+
                 "Perhaps you can read it",
    "knocker","A brass knocker that should only be used if you wish to\n"+
              "speak to Feldegast",
    "foliage","The thick foliage surrounds the clearing in all directions,\n"+
              "preventing you from going far in any direction",
    "trees","The tall trees block out the skyline.  You can't see more than a few\n"+
            "hundred feet in any direction",
  });
}
init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_scribble","scribble");
  add_action("cmd_knock","knock");
  add_action("cmd_open","open");
  add_action("cmd_close","close");
  add_action("cmd_enter","enter");
}
cmd_knock() {
  object me;
  me=find_player("feldegast");
  if(me)
    tell_object(me,"You hear "+TPRN+" knocking on your tower door.\n");
  write("You knock loudly on the door to see if anybody is home.\n");
  say(TPN+"knocks loudly on the tower door.\n");
  call_other("/players/feldegast/closed/tower/tower0","???");
  return 1;
}
cmd_open(str) {
  notify_fail("What is it you wish to open?\n");
  if(!str || str!="door") return 0;
  FTELL("MARK\n");
  if(TPRN!="Feldegast") {
    write("You don't know how.\n");
    say(TPN+" tries to open the door, but fails.\n");
    return 1;
  }
  if(door) {
    write("The door is already open.\n");
    return 1;
  }
  write("You open the crystal tower's door.\n");
  say(TPN+" opens the door.\n");
  door=1;
  return 1;
}
cmd_close(str) {
  notify_fail("Close what?\n");
  if(str!="door") return 0;
  if(TPRN!="Feldegast") {
    write("You don't know how.\n");
    say(TPN+" tries to close the door, but fails.\n");
    return 1;
  }
  if(!door) {
    write("The door is already closed.\n");
    return 1;
  }
  door=0;
  write("You close the door to the crystal tower.\n");
  return 1;
}
cmd_enter(str) {
  notify_fail("Enter what?\n");
  if(str!="tower") return 0;
  if(!door) {
    write("You can't.  The door is closed.\n");
    return 1;
  }
  TP->move_player("into the tower#players/feldegast/closed/tower/tower0.c");
  return 1;
}
cmd_scribble(str) {
  write("You scribble,'"+str+"' on a note and shove it under Feldegast's door.\n");
  say(TPN+" writes a note and shoves it under the door.\n");
  write_file("/players/feldegast/log/messages.log",
  ctime(time())+" "+TPRN+" wrote you a message saying:\n"+str+"\n");
  return 1;
}
cmd_read(str) {
  notify_fail("Read what?\n");
  if(!str) return 0;
  if(str!="note" && str!="parchment" && str!="letter") return 0;
  write("The note reads:\n");
  cat("/players/feldegast/closed/tower/letter.txt");
  return 1;
}
