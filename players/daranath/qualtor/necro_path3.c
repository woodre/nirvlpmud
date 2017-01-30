#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
   a=0;
   if(!arg){
      
      set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+BLK+BOLD+"Dark Graveyard"+NORM+")");
      long_desc=
      "The dark pathway turns to the north here, leading up to the\n"+
      "burnt out shell of the ruined keep. The shadow from the keep\n"+
      "casts a pall over this area, keeping you on your toes.\n";
      
      items=({
            "pathway","The pathway runs from the ruined keep to the protective wall",
            "keep","The keep was destroyed during the downfall of Qual'tor",
            "shadow","The shadow of the keep cloaks this area in darkness",
            "shell","The shell of the blackened keep stands as a reminder of the former glory of Qual'tor",
            "toes","You know what your toes look like",
          });
      
      dest_dir=({
            "/players/daranath/qualtor/necro_path4.c","north",
            "/players/daranath/qualtor/necro_path2.c","west",
          });
      
   }
}

init(){
   ::init();
   add_action("search","search");
/* commented out by wocket
   add_action("dar_north","north");
*/
}

dar_north(){
  if(!present("necro_ob",this_player())){
    if(present("guardian",this_object())){
      write("\nThe shadow of the ruined keep falls about the area.\n\n");
      return 1;
      }
      else{
      move_object(clone_object("/players/daranath/guild/mon/skel_guardian.c"),this_object());
      write("As you try to pass through the area, something climbs fromt he ground!\n");
      write("\nThe shadow of the ruined keep falls about the area.\n\n");
      return 1;
    }
  }
  return 0;
}


search() {
   write("You find nothing of interest about the pathway.\n");
   return 1;
}
