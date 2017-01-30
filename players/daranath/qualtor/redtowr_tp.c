#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("portal")) {
move_object(clone_object("/players/daranath/qualtor/obj/portal1.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
"The top of the Red Tower is intact, having survived the chaos that\n"+
"plagued the rest of the city. Large stone battlements stand at \n"+
"intervals along the outer ledge to protect the tower from attacks.\n"+
"A large stone dais stands here, with a glowing crystal placed upon it.\n";

    items=({
"battlements","Large stone battlements protect anyone on top the tower",
"stone","The stone is dark red in color",
"dais","A stone dais has been placed here, to support the crystal",
"crystal","The glowing crystal is eminating a glowing field that encompasing the\n"+
     "tower, protecting it from the falling Ash that covers the\n"+
     "Ghost Ward within the city of Qual'tor",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr9.c","down",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("The top of the tower is just bare stone.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

