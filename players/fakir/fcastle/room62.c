inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Queen's Chambers";
long_desc =
"   Silken robes of many colors hang in the open closet set against\n"+
"the far wall.  A queen size bed with thick down comforters extends\n"+
"from the near corner, and takes up most of the area in the room. A\n"+
"sleek black cat sleeps on top of the bed.\n";

items = ({
"robes",   "Lovely silken robes from far across the great waters",
"closet",  "A tall wooden closet of a rich dark wood",
"wall",    "One of the four walls in the queen's bedroom",
"bed",     "A bed made for a queen, it looks comfy",
"comforters", "Soft silken cloth stuffed with goose down",
"corner",     "One of four corners in the room",
"cat",        "A silky black cat. It is asleep on the bed",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room93.c", "out",
   
});
}


