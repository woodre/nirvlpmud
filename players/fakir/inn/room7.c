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
   "east and west.  A tall mirror bordered in polished oak covers the wall\n"+
   "behind the bar from countertop to ceiling.  Your reflected image is\n"+
   "clear and precise in the mirror.\n";

items = ({
   "bar",     "Thick cut hardwood polished to a high luster and about two spans\n"+
              "in height, it is a sight to behold.  A brass rail runs its length\n"+
              "about eight snitches from the base, and is rather scuffed and nicked.\n"+
              "The wood has a warmth to it, as if it were imbued with some sort of\n"+
              "magic.  Looking closely, you see your face reflected in the bar top's\n"+
              "polished surface",
   "wall",    "The north wall of the inns commonroom",   
   "counter", "Less ornate than the bar itself, it is also built entirely from one\n"+
              "long single cut of hardwood.  Its top is somewhat dusty.",
   "mirror",  "Oddly crystal clear compared to the other glass objects in the inn.\n"+
              "Only a master glassman could pour so clear a pane, and even then only\n"+
              "with the help of magic from the 'one power'.  How a mirror such as this\n"+
              "would come to be on the wall of an inn is a mystery.",
   "oak",     "A hard, grained wood from a tree found in the foothills of the Mountains of Mist",  
   "countertop", "The countertop is somewhat dusty",
   "ceiling", "Ten feet off the floor, it is made of interlocking knotted wood planks",  
   "cashbox", "Solid brass with a strong looking clasp and lock. It is not locked.",
   "lid",     "Solid brass with a small emblem of a dragon on the top",
 "brandelwyn","Perhaps if you got a bit closer, you could see him better.  You might\n"+
              "try to 'jump the bar'",
   "mayor",   "Perhaps if you got a bit closer, you could see him better.  You might\n"+
              "try to 'jump the bar'",
 "proprietor","Perhaps if you got a bit closer, you could see him better.  You might\n"+
              "try to 'jump the bar'",
});

dest_dir = ({
   "/players/fakir/inn/room21.c", "jumpbar",
   "/players/fakir/inn/room8.c", "south",
   "/players/fakir/inn/room16.c", "east",
   "/players/fakir/inn/room6.c",  "west",
   "/players/fakir/inn/room15.c", "southeast",
   "/players/fakir/inn/room5.c",  "southwest",
});

}
