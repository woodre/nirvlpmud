#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("mephit")){
move_object(clone_object(ROOT+"mon/vapor_mephit.c"),this_object());
move_object(clone_object(ROOT+"mon/vapor_mephit.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar "+BLU+"Vapor Springs"+NORM);
long_desc=
"Travel through the Gundar vapor pools ends here with the rocky pathways fading\n"+
"out. The hot springs blend into a large lake extending as far as the local\n"+
"mists will let you see. Volcanic activity is obviously present, as the lake\n"+
"boils and bubbles out in the distance. The only exit is back the way \n"+
"you came.\n";

items=({
"pools","The vapor pools end here, blending into a large lake",
"pool","The vapor pools end here, blending into a large lake",
"lake","The lake extends for quite some distance, a small island can be seen\n"+
      "in its center",
"island","A small island sits in the middle of the lake. There seems to\n"+
         "be no way to get to it",
"pathways","The rocky pathways end at the lake here",
"pathway","The rocky pathways end at the lake here",
    });

    dest_dir=({
  ROOT+"vapor2.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The lake extends into the distance, blocking all further travel.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
