inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower Stairway";
long_desc =
"   The stairway of the west tower winds its way upward as it hugs\n"+
"the stone wall.  A landing projects outward here and meets two\n"+
"doors, one on either side.  An oil torch illuminates each door.\n"+
"There are four exits: descend, climb, door1, door2\n";

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
  add_action("door1","door1");
  add_action("door2","door2");
  add_action("descend","descend");
  add_action("climb","climb");
::init();
}

descend() {
  this_player()->move_player("descend#/players/fakir/fcastle/room55.c");
  return 1;
}

climb() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room57.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
} 

door1() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room61.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;

}

door2() {
  if(!present("bloodguard")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room64.c");
    return 1;
  } 
  write("The Bloodguard moves in one quick motion to block your way.\n");
  say("The Bloodguard quickly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
}