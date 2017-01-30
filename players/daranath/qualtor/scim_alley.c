#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
inherit "room/room";

reset(int arg){
if(!present("figure")) {
move_object(clone_object("/players/daranath/qualtor/mon/figure.c"),this_object());
}
if(!present("child")) {
move_object(clone_object(ROOT+"folk/chld_shadow.c"),this_object());
move_object(clone_object(ROOT+"folk/chld_shadow.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Scimitar Alley"+NORM+" (west)\n"+
"All the rebuilt areas in Qual'tor, and Scimitar Alley has yet to feel any of\n"+
"restruction that the other areas in City Ward have. Ruined buildings and\n"+
"warehouses still line the alley, with nothing good lurkering nearby\n";

    items=({
"alley","Scimitar Alley is nothing but ruined buildings and warehouses",
"building","Several buildings that should be condemed line both sides of the alley",
"buildings","Several buildings that should be condemed line both sides of the alley",
"warehouses","Scimitar Alley used to be home to a variety of warehouses and other\n"+
     "buildings used for trade",
"warehouse","Scimitar Alley used to be home to a variety of warehouses and other\n"+
     "buildings used for trade",
    });

    dest_dir=({
"/players/daranath/qualtor/child_path2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("descend_down","descend");
    }

search(){
write("Within the shadows of one of the warehouses, you seem to find a small\n"+
      "opening in the rubble. You can <"+HIR+"descend"+NORM+"> into it.\n");
 say(tp +" searches the area.\n");
return 1;
}

descend_down() {
write("\nYou carefully descend into Qual'tors ancient sewer system.\n\n");
this_player()->move_player("down into the sewers#/players/daranath/qualtor/newstuff/undercity1.c");
return 1;
}

