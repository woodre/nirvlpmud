#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "An Eagles Nest";
long_desc =
"This is the nest of a grey eagle.  Broken branches, twigs, and short\n"+
"stalks of vegetation have been woven into a rough platform high in the\n"+
"top of an ancient oak.  A panoramic view of the Whispering Woods is\n"+
"visible from here, as well as much of the lands beyond its borders.\n"+
"You are lucky the eagle pair are off in search of food.\n";

items = ({
"nest",    "It is roughly five feet in diameter, and constructed of odd bits of\n"+
           "forest debris.  There is a slight lip built up around the perimeter",
"branches","Three to four foot long branches forming the base of the nest",
"twigs",   "Small in diameter and short in length, these are woven into the\n"+
           "base of the nest to form a smooth bed for the eggs and eventually\n"+
           "for the eaglets that hatch",
"stalks",  "Grasses, reeds, thistle down and straw.  These make up the soft\n"+
           "top layer of the nest, giving it a soft layer of insulation",
"vegetation", "Grasses, reeds, thistle down and straw",
"platform", "This refers to the nest itself, as it appears to be a platform\n"+
            "due to its sheer size",
"oak",      "A large and mighty oak rising from the ground, its base a tangle of thick\n"+
            "strong roots anchored firmly in the earth",
"view",     "To the north and west, beyond the trees of the woods, you can see the\n"+
            "low valleys and hills of the countryside, and an empty road going to\n"+
            "in a north-south direction.  To the east a very dark and deep forest\n"+
            "of evergreens grow.  Dark clouds hang in the air over the trees there.\n"+
            "To the south a great canyon divides the land, and stretches as far as\n"+
            "the eye can see",
"lands",    "The area lying beyond the woods itself",

 
});
if(!present("eaglet",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/eaglet.c"),this_object());
 move_object(clone_object("/players/fakir/woods/NPC/eaglet.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room29.c", "down",
});
}



