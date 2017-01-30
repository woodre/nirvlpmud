#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Tall stinging nettles grow in rich abundance all about you between the\n"+
"trees and bushes and block your path.  They have thin pale stalks with\n"+
"poisoned leaves on short stems.\n";

items = ({
"trees",   "Tall and slender and of a slightly different sort than in the other parts\n"+
           "of the wood.  These have bright red and yellow leaves, and purple branches.\n"+
"bushes",  "Some have prickly leaves like holly, with little gold berries at the top",
"nettles", "A type of poison plant",
"path",    "It leads back the way you came, to the north",
"stalks",  "The part of the plant which grows up from the ground.  They are of\n"+
           "different heights, but all are taller then your head",
"leaves",  "They look like normal leaves, but contain a very painful poison",
"stems",   "The part of the plant that attaches the leaf to the stalk",
 
});

if(!present("imp2",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/imp2.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room23.c", "north",
   
});
}



