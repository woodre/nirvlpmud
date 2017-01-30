inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "East Tower Stairway";
long_desc =
"   The stairway of the east tower winds its way upward as it hugs\n"+
"the stone wall.  A landing projects outward here and meets two\n"+
"doors, one on either side.  An oil torch illuminates each door.\n"+
"There are four exits: descend, climb, door5, door6\n";

items = ({
"doors",   "Narrow wooden doors with a simple lift type handle",
"room",    "The central room of the east tower",
"tower",   "The east tower, living quarters to the Royal family and invited guests",
"wall",    "Solid stone and covered in places by soot from the torches",
"torches", "Everburning oil torches with long wooden bases",
"landing", "Projecting outward from the wall, they provide a space\n"+
           "at each doorway to the various rooms of the tower",
"stairway","A solid stone stairway that ascends the inner tower wall",

});

if(!present("watchman",this_object()))
 move_object(clone_object("/players/fakir/fcastle/NPC/guard1.c"),this_object());

}

init() {
  add_action("door5","door5");
  add_action("door6","door6");
  add_action("descend","descend");
  add_action("climb","climb");
::init();
}

descend() {
  this_player()->move_player("descend#/players/fakir/fcastle/room47.c");
  return 1;
}

climb() {
  if(!present("watchman")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room85.c");
    return 1;
  } 
  write("The Watchman moves slowly but still manages to hinder your leaving.\n");
  say("The Watchman slowly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
} 

door5() {
  if(!present("watchman")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room49.c");
    return 1;
  } 
  write("The Watchman moves slowly but still manages to hinder your leaving.\n");
  say("The Watchman slowly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;

}

door6() {
  if(!present("watchman")) {
    this_player()->move_player("climb#/players/fakir/fcastle/room50.c");
    return 1;
  } 
  write("The Watchman moves slowly but still manages to hinder your leaving.\n");
  say("The Watchman slowly moves to block "+capitalize(this_player()->query_name())+"'s path!\n");
  return 1;
}