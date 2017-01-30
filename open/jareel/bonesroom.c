inherit "/players/jareel/room";
#define ESWORD RED+"~"+BLU+" Ele"+GRN+"men"+HIW+"tal S"+NORM+GRN+"wo"+BLU+"rd"+RED+" ~"+NORM
#define BONESARENA "/open/jareel/bonesarena.c"
#include "/players/jareel/define.h"

     reset(arg) {
     if(arg) return;

     if(!present("statue"))  {
       MOCO("/players/jareel/general_stuff/bone_statue.c"),this_object()); }
     if(!present("board"))  {
       MOCO("/players/jareel/general_stuff/bone_graf.c"),this_object()); }


     set_light(-3);
     short_desc=("Bone's "+BOLD+BLK+"Onyx Lair"+NORM+"");
     long_desc=(
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"     An eerie fog hovers over the ground, leaving the floor virtually\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     invisible.  Tapestries hang from the stone walls, each depicting\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+BOLD+"X"+NORM+BLK+BRED+"@"+NORM+"     different scenes of Bone's quest for legendary status.  In the center\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     of the room a granite table stands, a blood red sheet covering it.\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"     An onyx coffin rests upon the table, its lid sealed and locked. The\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     only way out is west, through a narrow doorway.\n");
     items = ({
       "fog","An eerie fog that hovers above the ground",
       "tapestries","Blood red in color, these tapestries hang from the walls and feature\n"+
         "pictures of various events in Bone's life",
       "north wall","The tapestry bears pictures of Bone fighting the creatures of the\n"+
         "elemental test, and of him raising the "+ESWORD+" above his\n"+
         "head in victory",
       "east wall","The tapestry bears a picture of Bone fighting a fiery phoenix, the\n"+
         "mighty Hinotori.  A second picture shows Bone drinking from a pool\n"+
         "of blood near the fallen beast",
       "south wall","The tapestry bears a picture of Bone and his family celebrating at a feast",
       "wall","Which wall are you looking at? (north wall, south wall or east wall",
       "walls","Which wall are you looking at? (north wall, south wall or east wall",
       "table","A table made from granite",
       "sheet","A blood red sheet, made of fine silk",
       "coffin","A large coffin made from onxy.  It is closed, and its lid is sealed and locked",
       "doorway","You can leave the room through the doorway to the west",
});

     dest_dir = ({
      "/players/jareel/areas/statue/hall2.c","west",
   });
}
     int peeps;void init() {
       ::init();
       if(!this_player())
     return;
     add_action("StartBone","start");
     add_action("piss_off","open");
     add_action("piss_off","enter");
     add_action("piss_off","touch");
     add_action("Search","search");
     peeps++;
       if(find_call_out("wind") == -1)
     call_out("wind", random(25) + 3);
       }void exit() {  peeps--;
       if(peeps <= 0)    while(remove_call_out("wind") != -1) ;
       }void wind() {  object ob,next;
     string msg;
       switch(random(2)) {    case 0: msg= "The fog swirls around your feet...\n";
     break;
     case 1: msg= "The fog swirls around your feet....\n";
     break;
     }  tell_room(this_object(),msg);
     call_out("wind", random(25) + 3);
  }

     Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
}

     piss_off(str) {
       if(!str || str !="coffin") { notify_fail("What?\n"); return 0; }
       if(str == "coffin") {
         write("A deep voice growls: You must not touch the coffin of Bone.\n"+
         RED+"      You flee in panic!\n"+NORM);
         this_player()->move_player("out of the room in fear!#/players/jareel/areas/statue/hall2.c");
     return 1;
   }}

  StartBone(string str){
     if(!str || str != "arena"){
       notify_fail("What do you want to do?\n");
     return 0;
   }
   if(this_player()->query_level() < 19){
     write("Not until you are level 19.\n");
/* removed, it's only done when arena actually starts.
     say(this_player()->query_name()+" is off to try and kill Bone.\n");
*/
   return 1;
 
   }
/*
 * Commenting this out, going to check room inventory instead
}
   if("/players/jareel/areas/statue/arena/bone/rm1.c"->query_enter() == 1){
     write("Someone is in the arena.\n");
   return 1;
   }
   write("You start the arena.\n");
     say(this_player()->query_name()+" dissapears.\n");
     move_object(this_player(),"/players/jareel/areas/statue/arena/bone/rm1.c");
     say(this_player()->query_name()+" enters.\n");
     command("glance",this_player());
       "/players/jareel/areas/statue/arena/bone/rm1.c"->set_enter(1);
   return 1;

}
  if ("/players/jareel/areas/statue/arena/bone/rm1.c"->cannot_enter())
*/
  if ((status)BONESARENA->cannot_enter())
  {
    notify_fail("There is already someone in Bone's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Bone.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/bone/rm1.c");
  command("glance", this_player());

  return 1;
}

