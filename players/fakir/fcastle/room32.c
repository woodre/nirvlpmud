inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Castle Courtyard";
long_desc =
"   A huge wooden door hangs open at this northern end of the courtyard,\n"+
"inviting you to enter the great hall of the castle.  An open stable is\n"+
"to the west, and an apothecary shop is built against the castle wall to\n"+
"the east.\n";

items = ({
"door",   "A double door that opens outward from the northern wall of the courtyard",
"wall",   "The exterior wall of the great hall and the inside\n"+
          "wall of the castles inner ward or courtyard",
"hall",   "You can't see the hall from here, but it is\n"+
          "just beyond the open doorway",
"stable", "A regular sort of stable. They board horses\n"+
          "and other beasts of burden",
"shop",   "A small unkempt shop of an ancient healer",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room37.c", "north",
   "/players/fakir/fcastle/room33.c", "stable",
   "/players/fakir/fcastle/room36.c", "apothecary",
   "/players/fakir/fcastle/room31.c", "south",
});
}


