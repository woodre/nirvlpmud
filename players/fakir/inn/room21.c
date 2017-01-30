#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Winespring Inn";
  long_desc =
   "A tall mirror bordered in polished oak runs from countertop to ceiling.\n"+
   "Master Brandelwyn al'Vere, proprietor of this inn and Mayor of the\n"+ 
   "village usually stands here to wait on patrons of the inn who wish to\n"+
   "partake in the fine ale and beer he stocks.\n";
  items = ({
    "mirror", "Oddly crystal clear compared to the other glass objects in the inn.\n"+
              "Only a master glassman could pour so clear a pane, and even then only\n"+
              "with the help of magic from the 'one power'.  How a mirror such as this\n"+
              "would come to be on the wall of an inn is a mystery.",
    "oak",     "A hard, grained wood from a tree found in the foothills of the Mountains of Mist",  
    "ceiling", "Ten feet off the floor, it is made of interlocking knotted wood planks",  
  });
  if(!present("bran.c",this_object()))
    move_object(clone_object("/players/fakir/inn/NPC/bran.c"),this_object());
  move_object(clone_object("/players/fakir/inn/OBJ/cashbox.c"),this_object());
  dest_dir = ({
    "/players/fakir/inn/room7.c", "jumpback",
  });
}
