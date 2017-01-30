#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The massive hardwood bar runs the entire length of this wall to the west.\n"+
   "Heavy wooden shelves surround the window behind the bar, and casks of wine\n"+
   "are stacked below it in an upright triangle, with the top cask having a\n"+
   "spigot in its end.  Empty wine glasses and a few bottles with cork stoppers\n"+
   "cover the shelves.  A serving bowl of fresh complimentary sweetcakes lies\n"+
   "upon the bartop here for the enjoyment of the inn's customers.\n";

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
   "casks",   "Cherrywood slats held in place by rusty metal bands top, middle, and\n"+
              "bottom.  The end panels are round and solid.  The wood is sealed on the\n"+
              "inside to aid the wine in its aging process",
   "triangle","A method of stacking wine casks so the new wine is slowly rotated from\n"+
              "bottom to top of the pile, thereby ensuring the wine is well aged when\n"+
              "drawn and served",
   "spigot",  "Solid brass with a toggle lever on the top to allow a smooth flow of ale\n"+
              "from the cask when tapped",
   "glasses", "Hand blown in the glass shop down the lane, they are rather thick but\n"+
              "still delicate in design, resembling a tulip with a stem and base",
   "bottles", "Roughly blown and drawn to a taper at the top, they hold a sopith each\n"+
              "and are used mostly for show, though a few do contain potions and oiled\n"+
              "herbs used as additives to certain drinks",
   "stoppers","Small soft corks cut from the thick bark of the bandanoin tree",
   "bowl",    "Carved from a solid chunk of wood into the shape of a prieter flower",
   "cakes",   "Made from a mixture of sifted mea flour, left over mash from the brewery,\n"+
              "and clover honey, they are a meal in themselves",
   });

dest_dir = ({
   "/players/fakir/inn/room15.c", "south",
   "/players/fakir/inn/room8.c",  "southwest",
   "/players/fakir/inn/room7.c",  "west",
});

}