#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
    if(!present("priest")){
    move_object(clone_object("/players/brittany/kadath/NPC/kaman.c"),this_object());
}

   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     This is a small room inside the cavern walls.  The walls\n"+
   "are made of brimstone and fireshadows blaze across them.  On\n"+
   "one side of the room, there is a stone desk, with an old looking\n"+
   "book sitting on top of it.  On the far wall, there is a doorway\n"+
   "at the top of some steps leading downward.\n";
   
   items = ({
         "fireshadows","Shadows of fire blazing across the walls",
         "book","A old looking book sitting on the desk, that is sealed closed",
         "walls","The walls are made of brimstone and have fireshadows blazing across them",
         "desk","A huge desk made out of stone",
         "stoned desk","A huge desk made out of stone",
         "doorway","A doorway on the far wall, with steps leading down",
         "room","This is a small room inside of the cavern walls",
         "steps","The steps are wide and made of stone",
         "wall","On the far wall, there is a doorway with steps leading down",
         "far wall","On the far wall, there is a dooreay with steps leading down",
          });

   dest_dir = ({
         "/players/brittany/kadath/k5.c","east",
         "/players/brittany/kadath/k8.c","down",
          });
}
init(){
::init();
add_action("down","down");
add_action("up","up");
add_action("search","search");
}
 
down(str){
   write("You walk down the steps into deeper slumber and\n"+
         "the dream begins.\n\n");
    say(tpn+"  walks down the steps.\n");
    tp->move_player("down#/players/brittany/kadath/k8.c");
return 1; }
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
