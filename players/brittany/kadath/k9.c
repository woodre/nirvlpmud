#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
 "     The steps are made out of stone and twist, upward and downward\n"+  
   "out of sight.  Mounted on the walls are some handrails made out of\n"+
   "twisted rope.\n";
 
   items = ({
         "steps","The steps are wide and made of stone",
         "walls","The walls are made of basalt and are warm to the touch",
         "handrails","The handrails are made of twisted rope",
         "rope","The rope is twisted and mounted on the walls for handrails",
         "twisted rope","The rope is twisted and mounted on the walls for handrails",
           });

   dest_dir = ({
         "/players/brittany/kadath/k8.c","up",
         "/players/brittany/kadath/k10.c","down",
         });
}
init(){
::init();
add_action("down","down");
add_action("up","up");
add_action("search","search");
}
 
down(str){
  write("You continue down.  Then as if the dream become\n"+
        "clearer the Enchanted Woods appear out of nowhere.\n\n");
    say(tpn+"  continues down.\n");
    tp->move_player("down#/players/brittany/kadath/k10.c");
return 1; }
 
up(str){
   write("You walk up the steps toward the waking world.\n\n");
    say(tpn+"  walks up the steps.\n");
    tp->move_player("up#/players/brittany/kadath/k8.c");
return 1; }
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
