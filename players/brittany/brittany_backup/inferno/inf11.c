#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/brittany/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
short_desc = RED+"Inferno"+NORM;
   long_desc =
   "     Inside of the building in the middle of the room is a\n"+
   "huge stone statute.  It looks like a sculptured pylon of some\n"+
   "kind.  When approached closely one might think that it has\n"+
   "been whipped by searing winds or dust to make it appear\n"+
   "more mummified.  On the wall, you see a lever that draws\n"+
   "your attention.\n";

   items = ({
});
   dest_dir = ({
"/players/brittany/inferno/inf13.c","out",
});
}
init(){
::init();
add_action("pull","pull");
}
 
pull(str){
   object chaos;
   if(!str ||  str != "lever") {
   notify_fail("What do you want to pull?\n");
   return 0; }
 
   if(lever) {
 write("You sit down and the room turns dim as a yellow GLOW moves closer.\n\n"+
   ""+HIY+"The Crawling chaos appears."+NORM+"\n");
      chaos = clone_object("/players/brittany/kadath/NPC/nyar.c");
      move_object(chaos,this_object());
      chaos->attack_object(this_player());
     throne = 0;
   }
   else write("You pull the lever and nothing happens.\n");
   return 1; }
 
