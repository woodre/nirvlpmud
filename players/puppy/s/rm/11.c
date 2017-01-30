#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

int berry;
realm() { return "NT"; }
reset(arg) {
   berry = 0;
   if(!present("vanity"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/vanity.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "The grass here has been trampled down from all the traffic\n"+
      "that moves through here. To the north is a small pond that\n"+
      "is covered with overgrowth.  Small pebbles line the banks\n"+
      "of the pond.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "grass", "Lush grass that has been trampled",
         "weeds", "Tall strands of plant life that grow from the pond",
         "small pond", "A clear pond that is overgrown with weeds",
         "pond", "A clear pond that is overgrown with weeds",
         "banks", "An area covered with pebbles surrounding the pond",
         "small pebbles", "Tiny rocks lining the banks of the pond",
         "pebbles", "Tiny rocks lining the banks of the pond",
         "overgrowth", "Weeds that grow in the pond"});
   dest_dir = ({
         "/players/puppy/s/rm/10.c", "south",
         "/players/puppy/s/rm/19.c", "west",
         "/players/puppy/s/rm/12.c", "east"});
   
}
init(){
   ::init();
   add_action("search_bush","search");
}

search_bush(str){
   if(berry >=1){
      write("You search the bushes, but find nothing.\n");
      return 1; }
   if(str == "bushes" || str == "bush"){
      write("You find some blue berries in the bushes!\n");
      say(this_player()->query_name()+" finds some blue berries in a bush.\n");
      move_object(clone_object("/players/puppy/s/heal/berries.c"),this_player());
      berry +=1;
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [s,w,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [s,w,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [s,w,e]";
}
