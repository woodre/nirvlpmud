inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "King's Chambers";
long_desc =
"   The royal chambers are spacious and full of light from the many\n"+
"windows which look out over the castle courtyard.  A king size bed\n"+
"takes up one entire wall of the room.  A gigantic dresser and mirror\n"+
"cover another.  A wash stand with a bowl and pitcher stand near the\n"+
"door, and a huge mastiff sleeps at the foot of the bed.\n";

items = ({
"chambers",   "The king's royal bedroom",
"windows",    "Square windows with solid glass panes",
"courtyard",  "The inner ward of the castle, or courtyard",
"bed",        "A huge, oversized, bed made for a king of kings",
"wall",       "One of four walls inside the king's bedroom",
"dresser",    "A very large twelve drawer dresser with a top mirror",
"mirror",     "You see yourself, and boy are you UGLY!",
"stand",      "A four legged wash stand of wood",
"bowl",       "A porcelain bowl glazed white with gold leaf",
"pitcher",    "A porcelain pitcher glazed white with gold leaf",
"door",       "A royal door to be sure, carved from solid oak",
"mastiff",    "A very large and mean looking dog. Do NOT wake him",


});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room98.c", "out",
   
});
}


