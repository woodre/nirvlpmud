inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "West Tower";
long_desc =
"   The central room of the west tower is spacious and partially lit\n"+
"from the many small windows cut into the tower wall.  A worn circular\n"+
"stairway hugs the tower wall, illuminated in places by smokey torches\n"+
"set in notched brackets.  An occasional landing can be seen where the\n"+
"stairway passes a door on its way to the top of the tower.\n";

items = ({
"room",    "The central room of the west tower",
"tower",   "The west tower, living quarters to the King and Queen",
"windows", "Large square openings covered in a transparent oiled cloth",
"wall",    "Solid stone and covered in places by soot from the torches",
"torches", "Everburning oil torches with long wooden bases",
"brackets","Metal sheaths attached to the stone wall which hold the torches",
"landing", "They provide a space for each doorway of the tower stair",
"stairway","A solid stone stairway that ascends the inner tower wall",

});
dest_dir = ({
   "/players/fakir/fcastle/room56.c", "climb",
   "/players/fakir/fcastle/room30.c", "east",
   
});
}


