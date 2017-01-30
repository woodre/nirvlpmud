#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The stairs to the cellar are dark and steep, and descend between two\n"+
   "rock walls slick with moisture.  The bottom is pitch dark...and you\n"+
   "cannot see past the sixth stair.\n";

items = ({
   "cellar",  "Built below the main level of the inn, it perhaps predates the inn itself",
   "stairs",  "About seven snitches deep each, you can see to the sixth one and assume\n"+
              "they must desend another span or two past that but cant be sure",
   "walls",   "Made of the same ancient rock as the foundation of the inn, and having\n"+
              "only on place of origin...the Misty Mountains.  No mortar has been used\n"+
              "in the making of these walls, yet the rock holds fast to each other, as\n"+
              "if parts of a puzzle were placed together and once joined, would not break\n"+
              "apart.  Only one race has the skill to join rock in such a fashion. The\n"+
              "Ogier",
   "moisture","Condensation caused by the cold stone drawing moisture from the air",
   "bottom",  "You can't see the bottom of the stairs.  It is too dark",
   "stair",   "The sixth stair.  It is like all the others here",
   
   
});
dest_dir = ({
   "/players/fakir/inn/room18.c", "north",
   "/players/fakir/inn/room32.c", "descend",
      
});

}
