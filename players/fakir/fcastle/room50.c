inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Royal Quarters";
long_desc =
"   A gilded bedframe supports a soft fluffy down mattress with\n"+
"quilted comforters piled high upon it.  A tall carved closet\n"+
"with double doors rests beside an open window that looks out\n"+
"over the eastern castle yards and walls.\n";

items = ({
"bedframe",   "An ornately carved and guilded bedframe of wood and metal",
"mattress",   "A thick pad of cloth filled with goose down",
"comforters", "Large oversized blankets filled with feathers and tissle",
"closet",     "A stand alone closet of wood with two doors",
"doors",      "Double doors of the closet...the each have a handle",
"window",     "A real glass window with shutters that open and close",
"yards",      "The courtyard of the castle",
"walls",      "The eastern defensive wall and outer ward of the castle",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room87.c", "out",
});
}


