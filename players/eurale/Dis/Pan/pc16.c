#include "DEFS.h"
inherit "room/room";
int p3;

reset(arg) {
p3 = 1;

if(!present("lily")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/lilly"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Never Island";
long_desc =
	"  You stand on the beach at the western end of Never Island.\n"+
	"The sand gives way to grass and then to forest as you go east.\n"+
	"The forest itself is made up of large trees and thick shrubbery.\n"+
	"You can also see a large ship anchored out in the deep water\n"+
	"of the lagoon.\n";

items = ({
	"ship","Looks like it might be a pirate ship",
	"water","Clear and blue",
	"trees","Big oaks and walnuts",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc17.c","east",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("sprinkle","sprinkle"); }

sprinkle(str) {
  if(!str) { write("What are you trying to sprinkle?\n"); return 1; }
  if(str == "dust") {
    this_player()->move_player("dust#players/eurale/Dis/Pan/pc13.c");
    return 1; }
return 1;
}

search(str) {
object ob;
  ob = present("lily");
  if(ob) {
  write("Tiger Lily says:  We must move quickly to save the boys.\n");
  return 1; }

if(!str) { write("What are you trying to search here?\n"); return 1; }
if(str == "sand") {
  if(!present("lily") && (p3 == 1)) {
  write("You sift through the sand and find a puzzle piece.\n");
  move_object(clone_object("players/eurale/Dis/misc/puz3.c"),
	this_player());
  p3 = 0;
  return 1; }

  if(!present("lily") && (p3 == 0)) {
  write("You carefully sift through the sand to no avail.\n");
  return 1; }
 return 1; }
return 1;
}
