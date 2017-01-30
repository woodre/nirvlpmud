#include "/players/feldegast/closed/shortcut.h"
inherit "room/room";
string *commands;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A deep, dank dungeon";
  long_desc=
"    You are in a dungeon deep beneath the Crystal Tower.  There\n"+
"are no exits.  There is no escape.  You must've done something\n"+
"pretty dumb to get put in here.\n";
  dest_dir=({
  });
  commands=({
"say","'","look","l","sc","i","emote",":","who","who2","kewlwho",
"kill","wield","unwield","muffle","channel","put","get","help"
  });
}
init() {
  if(this_player()->query_level()<21) {
#ifndef __LDMUD__
    add_action("block");add_xverb("");
#else
    add_action("block", "", 3);
#endif
    write("The guards chain you to the wall.\n");
  }
}
block(str) {
  string verb, bleh;
  if(member_array(str,commands)>-1) return 0;
  if(sscanf(str,"%s %s",verb,bleh)) {
    if(member_array(verb, commands)>-1) return 0;
  }
  write("You rattle your chains.\n");
  say(TPN+" rattles his chains.\n");
  return 1;
}

