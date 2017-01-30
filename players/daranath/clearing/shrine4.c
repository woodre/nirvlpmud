#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
move_object(clone_object("/players/daranath/mons/vine.c"),this_object());
move_object(clone_object("/players/daranath/mons/vine.c"),this_object());
    
    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" ("+BLK+BOLD+"Ruined Shrine"+NORM+")");
    long_desc=
      "Broken blocks of dark grey stone stand at awkward positions in\n"+
      "this small clearing in the forest. Vines crawl about the ancient\n"+
      "rock, giving them a helpless, trapped look. The center of the\n"+
      "area is free of any growth, a light colored sand kept neatly \n"+
      "within a perfect circle.\n";

    items=({
      "forest", "The evil forest known as the DarkenWood spreads about\n"+
                "the area to the south",
      "stone", "The blocks of stone have been knocked over from thier\n"+
               "positions to rest unevenly about the area",
      "sand", "The light colored sand rests within a perfect circle in\n"+
              "the center of the broken shrine, no grass or any other\n"+
              "plant growing from it",
      "vines", "The vines grow about everywhere, holding the stone within\n"+
               "thier thorny grasp", 
      "vine", "The large vine grow about everywhere, thorns running the\n"+         
              "length of the plants",
    });

    dest_dir=({
      "/players/daranath/clearing/shrine3.c","east",
      "/players/daranath/clearing/shrine2.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing of value about the ruins of the shrine.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


