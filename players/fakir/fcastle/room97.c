inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower Stairway";
long_desc =
"   The stairway of the west tower winds its way upward as it hugs\n"+
"the stone wall.  A landing projects outward here and meets two\n"+
"doors, one on either side.  An oil torch illuminates each door.\n"+
"There are four exits: descend, climb, door3, door4\n";

items = ({
"doors",   "Narrow wooden doors with a simple lift type handle",
"room",    "The central room of the east tower",
"tower",   "The west tower, living quarters to the King and Queen",
"wall",    "Solid stone and covered in places by soot from the torches",
"torches", "Everburning oil torches with long wooden bases",
"landing", "Projecting outward from the wall, they provide a space\n"+
           "at each doorway to the various rooms of the tower",
"stairway","A solid stone stairway that ascends the inner tower wall",

});

if(!present("bloodguard",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/bloodguard.c"),this_object());

}

init() {
  add_action("door3","door3");
  add_action("door4","door4");
  add_action("descend","descend");
  add_action("climb","climb");
::init();
}

descend() {
  this_player()->move_player("descend#/players/fakir/fcastle/room56.c");
  return 1;
}

climb() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room58.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
} 

door3() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room60.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;

}

door4() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room63.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
}