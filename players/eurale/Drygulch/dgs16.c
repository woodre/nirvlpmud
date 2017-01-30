#define tp this_player()
inherit "room/room";
int OPEN;

reset(arg) {
  if(arg) return;
OPEN = 0;
set_light(1);
if(!present("capsule")) {
  move_object(clone_object("players/eurale/Drygulch/capsule.c"),
		this_object()); }

short_desc = "Drygulch";
long_desc =
	"  You have managed to push your way into the tangle of tumble-\n"+
	"weeds beside the trail.  There is a very strange capsule half\n"+
	"buried in the sand that has blown around it.\n";

items = ({
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs14.c","south",
});

}

init() {
  ::init();
  add_action("enter","enter");
  add_action("open","open");
}

open(str) {
if(!str) { write("What are you trying to open?\n"); return 1; }
if(str == "capsule") {
if(OPEN == 1) {
  write("The door has already been opened.\n");
  return 1; }
else {
  write("You push your fingers under the lip of the door and pull it\n"+
	"open enough to enter.\n");
  OPEN = 1;
  return 1; }
return 1; }
}

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "capsule") {
if(OPEN == 1) {
  tp->move_player("into the capsule#players/eurale/Space/teleport_up.c");
  OPEN = 0;
  return 1; }
else {
  write("You cannot enter the capsule until it is opened.\n");
  return 1; }
 return 1; }
}
