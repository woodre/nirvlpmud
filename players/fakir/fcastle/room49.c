inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Royal Quarters";
long_desc =
"   A soft bearskin rug complete with the skull attached lies on the\n"+
"stone floor, and muffles your footsteps.  Armors and weapons are\n"+
"scattered about the room. The royal medallion of the prince of the\n"+
"realm hangs from a bedpost by a golden chain.\n";  

items = ({
"rug",      "A large bearskin rug, well tanned and stitched around the edges",
"skull",    "The skull of the bear",
"floor",    "The stone floor of the prince's bedroom",
"armors",   "Practice shields, gauntlets, a silver helm, and other such",
"weapons",  "Rapiers of all sorts, broadswords, a longbow, and several arrows",
"medallion","A royal medallion of fine craftsmanship. Upon the face, the\n"+
            "inscription reads: 'Prince Magor of the Magor Royal Family'",
"bedpost",  "A thick but well built part of the headboard of the bed",
"chain",    "A linked golden chain attached to a royal medallion",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room92.c", "out",
});
}


