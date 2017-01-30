inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Gatehouse";
long_desc =
"   Oil lamps flicker amidst the inner gloom of the gatehouse.\n"+
"Heavy reinforced doors lead to hallways east and west, and\n"+
"luckily they have been left open.  A half eaten meal of stew\n"+
"and bread sits on a short table next to the western wall.  An\n"+
"open archway north leads to the inner court of the castle.\n";

items = ({
"archway",  "A stone arch with heavy battle doors open and inviting",
"lamps",    "Simple bowl type oil lamps with a cotton wick",
"doors",    "Hardwood from the forest hand cut into a thick\n"+
            "and very sturdy door. It could withstand a giant",
"stew",     "Meat, vegetables, and some thick gravy in a wooden bowl",
"bread",    "Dark brown and coarsely ground, it hardly appears edible",

});
dest_dir = ({
   "/players/fakir/fcastle/room30.c", "north",
   "/players/fakir/fcastle/room2.c",  "south",
   "/players/fakir/fcastle/room68.c", "east",
   "/players/fakir/fcastle/room65.c", "west",

});
}


