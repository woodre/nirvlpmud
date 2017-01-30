#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("penguin")) {
  move_object(clone_object("players/softly/winter/penguin"),this_object());
  }


  if(arg) return;
set_light(1);

short_desc = "Frozen Lake";
long_desc ="  The blindingly bright frozen lake is surrounded by dying trees\n"+
           "dotted with a few evergreens.  The air is very cold.  To the\n"+
           "south a fire is visible with a small structure to the southeast.\n"+
           "The lake ends to the north.\n";

items = ({
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees dominate the landscape",
  "lake",  "The ice is quite thick covering the surface of the solidly\n"+
           "frozen lake.  The surface has scratches, as if someone had\n"+
           "been skating on the ice",
  "air",   "The air is frigid",
  "structure", "A small shack has smoke rising above it.  It bears investigating",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond10.c","northeast",
  "/players/softly/winter/rooms/pond5.c","east",
  "/players/softly/winter/rooms/pond3.c","south",
  });
}
status query_skates(object ob)
{
    int x, z;
    object *all;    
    all = all_inventory(ob);
    for(x = 0; x < sizeof(all); x ++)
    {
      if((int)all[x]->is_softly() && (mixed)all[x]->id("ice skates") && (int)all[x]->query_worn())
      z = 1;
    }
    return z;  
}   

status move(string str)
{
    int chance;
    string where;
    chance = random(20);
    if(query_skates(this_player()) || !chance)
    {
      write("\t"+BOLD+"You glide across the ice...\n"+NORM);
      say((string)this_player()->query_name() + "\
 glides across the ice.\n");
      ::move(str);
      return 1;
    }
    else
    {
      switch(random(4))
      {
        case 0: where = "bottom"; break;
        case 1: where = "side"; break;
        case 2: where = "face"; break;
        case 3: where = "tummy"; break;
      }
      write("\tYou fall and land on your " + where + "!  Splat!\n");
      say((string)this_player()->query_name() + "\
 falls and lands on " + possessive(this_player()) + "\
 " + where + ".\n");
      return 1;
    }
}
