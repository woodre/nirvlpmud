inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "East Tower";
long_desc =
"   The central room of the east tower is spacious and partially lit\n"+
"from the many small windows cut into the tower wall.  A worn circular\n"+
"stairway hugs the tower wall, illuminated in places by smokey torches\n"+
"set in notched brackets.  An occasional landing can be seen where the\n"+
"stairway passes a door on its way to the top of the tower.\n";

items = ({
"room",  "The central room of the east tower",
"tower", "The east tower, living quarters to the Prince and Princess,\n"+
         "children to the King and Queen.",
"windows","Large square openings covered in a transparent oiled cloth",
"wall",  "Solid stone and covered in places by soot from the torches",
"torches","Everburning oil torches with long wooden bases",
"brackets","Metal sheaths attached to the stone wall which hold the torches",
"landing","Projecting outward from the wall, they provide a space\n"+
          "at each doorway to the various rooms of the tower",
"stairway","A solid stone stairway that ascends the inner tower wall",

});
dest_dir = ({
   "/players/fakir/fcastle/room46.c", "climb",
   "/players/fakir/fcastle/room30.c", "west",

});
}


