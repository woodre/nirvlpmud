#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("king"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/king.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "On the lush grass, where the path forms, rests a tiny wooden throne.\n"+
      "It sits along the small stream to the west.  Some tiny rocks have\n"+
      "been laid out to form a path leading from the throne across\n"+
      "to the stream.\n");
   set_light(1);
   add_listen("main", "You hear the water rolling over the rocks.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "lush grass", "Well kept grass",
         "grass", "Well kept grass",
         "tiny wooden throne", "A throne carved from a tree stump",
         "wooden throne", "A throne carved from a tree stump",
         "throne", "A throne carved from a tree stump",
         "small stream", "A stream that seems to divide the village",
         "stream", "A stream that seems to divide the village",
         "small path", "Carefully laid out rocks that the Smurfs usually 'walk' on",
         "path", "Carefully laid out rocks that the Smurfs usually 'walk' on",
         "worn path", "Carefully laid out rocks that the Smurfs usually 'walk' on",
         "tiny rocks", "Carefully laid out rocks that the Smurfs usually 'walk' on",
         "rocks", "Carefully laid out rocks that the Smurfs usually 'walk' on"});
   dest_dir = ({
         "/players/puppy/s/rm/21.c", "north",
         "/players/puppy/s/rm/17.c", "hut"});
}

init(){
   ::init();
   add_action("rrocks", "walk");
}

rrocks(str){
   if(!str){ notify_fail("Where would you like to go?\n"); return 0; }
   if(str == "rocks") {
      write("You walk to the other side of the stream.\n");
      this_player()->move_player("across the stream#players/puppy/s/rm/23.c");
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n,e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n,e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n,e]";
}
