inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Jester's Room";
long_desc =
"   Odd hats with long tails and bells hang from the walls\n"+
"all about and colorful costumes lie in piles in the corner.\n"+
"Balls of all colors and sizes are lying about as well, and\n"+
"mixed within the mess are a few puppets and stuffed animal\n"+
"replicas.\n";

items = ({
"hats",   "Long tailed hats with bells on strings and funny patches",
"tails",  "Attached to the hats, they sway in a faint gust from the window",
"bells",  "Silver bells that jingle faintly if touched",
"costumes","Multi colored pants, shirts and shoes",
"piles",   "Costumes in a pile",
"balls",  "Round leather balls in bright colors and differing sizes",
"puppets", "Hand puppets mostly, that look like a sock",
"replicas", "Stuffed skins of forest animals with odd looking faces",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/fcastle/room89.c", "out",
});
}


