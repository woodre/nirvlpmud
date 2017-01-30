#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Here in the kitchen several serving girls are busy doing dishes, wiping\n"+
   "counters, and preparing vegetables for the steaming pots of stew sitting\n"+
   "on the huge iron stove.  A service table runs the center of the room, and\n"+
   "is covered in flour and bits of pickin berries.  Four fresh baked pies sit\n"+
   "on an open window sill to cool, and steam spirals up from the slits in the\n"+
   "brown top crust.  A door to the cellar stands open to the south.\n";

items = ({
   "dishes",     "Soiled plates, bowls, pots and pans in the process of being washed",
   "counters",   "Located along two walls, they are used to prepare the food for the\n"+
                 "hungry patrons of the commonroom.  They are clean and ready for use",
   "vegetables", "Carrots, celery, biscuit root, and turnips",
   "pots",       "Large black cast iron pots with heavy lids tipped at an angle to\n"+
                 "allow some of the steam to escape during the cooking process",
   "stew",       "You cannot see into the pots from here",
   "stove",      "Made from polished brass, cast iron, and various other metals you\n"+
                 "cannot recognize, it has six round trivets for burners and a large\n"+
                 "oval plate in the top.  The oval plate can be removed to add split\n"+
                 "wood to the firebox inside.  Two oven doors with long handles are\n"+
                 "fastened to the front of the oven with hinges left and right, so\n"+
                 "the doors can swing out from the center.  Six cast iron legs hold\n"+
                 "the body of the stove off the floor about a quarter span.  A large\n"+
                 "flume or hood sits over the oven to carry off any steam or escaping\n"+
                 "smoke from the trivets",
   "trivets",    "Removable round metal plates that are recessed into the stove top", 
   "table",      "A large, sturdy wooden table three spans long and one span wide",
   "room",       "This is the heart of the Winespring Inn....the kitchen",
   "flour",      "White all purpose flour milled right here in the town of Two Rivers",
   "berries",    "Small blue and red berries, picked fresh just yesterday by the river",
   "pies",       "Deep dish pickin berry pies...a specialty of Mistress al'Vere's",
   "sill",       "The wooden plate or sash of the window, which is wider by half than\n"+
                 "the rest of the wooden framework",
   "steam",      "White wisps of vapor scented with pickin berry",
   "slits",      "Four diagonal cuts in the top crust to allow steam to escape while\n"+
                 "the pie is baking",
   "girls",      "Three young ladies just old enough to follow the village custom of\n"+
                 "braiding their hair at the age of consent.  They are wearing aprons\n"+
                 "and a uniform dress that Mistress al'Vere provides",
   "crust",      "Flaky and golden brown...it just makes your mouth water",
   
});
if(!present("mistress",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/mistress.c"),this_object());

dest_dir = ({
   "/players/fakir/inn/room17.c", "north",
   "/players/fakir/inn/room19.c", "south",
   "/players/fakir/inn/room14.c",  "west",
   
});

}
