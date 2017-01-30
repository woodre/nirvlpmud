okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A dark forest";
  long_desc =
"     A small, rinkadink tool shed stands to the west of you, whereas east\n"+
"leads to the log cabin.  A few small pine trees guard the shed, and the\n"+
"overgrowth all around you seems to be increasingly getting out of hand.\n"+
"The sound of a chainsaw's rotary blade can be heard from within the shed.\n";
  dest_dir = ({
ED1ROOM+"shed","enter",
ED1ROOM+"o1","east",
});
  items = ({
"shed","The small tool shed can be entered",
"trees","A clumping of pine trees rises above the small shed",
"overgrowth","The overgrowth makes it impossible to travel in any other directions",
});
  }

init() {
  ::init();
  add_action("search","search");
  add_action("no_leave","north");
  add_action("no_leave","west");
  add_action("no_leave","south");
  add_action("no_leave","southwest");
  add_action("no_leave","southeast");
  add_action("no_leave","northeast");
  add_action("no_leave","northwest");
  }

no_leave() {
  write("The overgrowth prevents travel in that direction!\n"); return 1; }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }
