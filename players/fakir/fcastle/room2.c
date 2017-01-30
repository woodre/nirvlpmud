inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Outer Ward";
long_desc =
"   The outer ward of the castle is the first defensive wall, and\n"+
"surrounds the entire exterior perimeter of the castle.  The ward\n"+
"runs east and west from here.  To the north a two-story gatehouse\n"+
"provides protection from the weather for the guards at the castle\n"+
"entry.  An open drawbridge to the south leads back to a dirt path\n"+
"in the woods.  You are standing on the southern ward of the castle,\n"+
"facing north.\n";

items = ({
"path",       "A wide and well trodden dirt path leading into the woods",
"woods",      "The tree-line is cut well back from the castle wall",
"gatehouse",  "Made from the same stone as the castle, with cross shaped\n"+
              "slits from which the guards can fire arrows at attackers",
"wall",       "Thick grey stone with very fine joints. Not even a knife\n"+
              "blade could slide between the individual stones",
"castle",     "Built in some former age of magic, its stone walls shine\n"+
              "with a dim glimmer of residual magic",
"ramparts",   "Raised portions of the southern defensive wall which makes\n"+
              "up the southern ward of the castle.  Archers and pikemen\n"+
              "use the ramparts for cover in case of an attack",
"drawbridge", "Heavy wooden beams banded in bronze and other metals.",
"ward",       "The defensive walkway and battlement that surrounds the entire\n"+
              "castle.  Built twenty feet from ground level, it affords a good\n"+
              "view of the surrounding countryside, and a very effective means of\n"+
              "defending the castle. You are standing on the southern ward, facing\n"+
              "north",
});

dest_dir = ({
   "/players/fakir/fcastle/room29.c", "gatehouse",
   "/players/fakir/fcastle/room3.c",  "west",
   "/players/fakir/fcastle/room16.c", "east",
   "/players/fakir/fcastle/room1.c",  "drawbridge",

});
}


