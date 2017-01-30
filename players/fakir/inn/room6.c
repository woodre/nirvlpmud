#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The massive hardwood bar runs the entire length of this wall to the\n"+
   "east.  Heavy wooden shelves surround the window behind the bar, and\n"+
   "casks of ale are stacked below it in an upright triangle, with the\n"+
   "top cask having a spigot in its end.  Empty mugs and a few bottles\n"+
   "with cork stoppers cover the shelves.  A large serving bowl of fresh\n"+
   "complimentary sweetcakes lies upon the bartop here for the enjoyment\n"+
   "of the inn's customers.\n";

items = ({
   "bar",     "Thick cut hardwood polished to a high luster and about two spans\n"+
              "in height, it is a sight to behold.  A brass rail runs its length\n"+
              "about eight snitches from the base, and is rather scuffed and nicked.\n"+
              "The wood has a warmth to it, as if it were imbued with some sort of\n"+
              "magic.  Looking closely, you see your face reflected in the bar top's\n"+
              "polished surface",
   "wall",    "The north wall of the inns commonroom",
   "shelves", "Built to last, they are attached to the wall with heavy brackets\n"+
              "of brass.  They are somewhat dusty",
   "window",  "Made of the cloudy glass of the area, it is difficult to see through\n"+
              "with any clarity.  The pane is divided into four equal squares by a\n"+
              "wooden trim, and a heavy putty holds the glass secure in its place",
   "casks",   "Eylem wood slats held in place by rusty metal bands top, middle, and\n"+
              "bottom.  The end panels are round and solid wood charred on the inside\n"+ 
              "to add a mellow flavor to the ale",
   "triangle","A method of stacking ale casks so the new ale is slowly rotated from\n"+
              "bottom to top of the pile, thereby ensuring the ale is well aged when\n"+
              "drawn and served",
   "spigot",  "Solid brass with a toggle lever on the top to allow a smooth flow of ale\n"+
              "from the cask when tapped",
   "mugs",    "Hand made in the clay shop down the lane, they are heavy and deep with\n"+
              "handles from top to bottom with room for a large hand to grasp them",
   "bottles", "Roughly blown and drawn to a taper at the top, they hold a sopith each\n"+
              "and are used mostly for show, though a few do contain potions and oiled\n"+
              "herbs used as additives to certain drinks",
   "stoppers","Small soft corks cut from the thick bark of the bandanoin tree",
   "bowl",    "Carved from a solid chunk of wood into the shape of a prieter flower",
   "cakes",   "Made from a mixture of sifted mea flour, left over mash from the brewery,\n"+
              "and clover honey, they are a meal in themselves",
   "bartop",  "Polished to a high luster from decades of use and countless applications\n"+
              "of wax, it can withstand even the most stubborn water stain",});

if(!present("Tinker",this_object())) move_object(clone_object("/players/fakir/inn/NPC/tinker.c"),this_object());

dest_dir = ({
   "/players/fakir/inn/room7.c", "east",
   "/players/fakir/inn/room5.c", "south",
   "/players/fakir/inn/room8.c", "southeast",
});

}
