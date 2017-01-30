#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

realm() { return "NT"; }
reset(arg) {
   if(!present("poet"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/poet.c"),this_object()); }}
   if(!present("painter"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/painter.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "Wild flowers in the field grow in abundance here.  The trees\n"+
      "just beyond the field have been neatly trimmed back to allow\n"+
      "the sunlight to permeate through.  There is a wooden bench\n"+
      "here for people to relax on while they enjoy the view.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "The flowers smell lovely.");
   items = ({
         "hills", "Rolling hills where wild flowers grow",
         "hill", "Rolling hills where wild flowers grow",
         "wild flowers", "Many kinds of flowers that grow on the hill",
         "flowers", "Many kinds of flowers that grow on the hill",
         "field", "The place where many kinds of wild flowers grow",
         "trees", "Small saplings that have been recently planted",
         "view", "The surrounding land that makes you feel all warm inside",
         "wooden bench", "A bench carved from a fallen log that the Smurfs like to sit on",
         "bench", "A bench carved from a fallen log that the Smurfs like to sit on"});
   dest_dir = ({
         "/players/puppy/s/rm/11.c", "north",
         "/players/puppy/s/rm/9.c", "south",
         "/players/puppy/s/rm/18.c", "west"});
   move_object(clone_object("/players/puppy/s/mob/poet.c"), this_object());
   move_object(clone_object("/players/puppy/s/mob/painter.c"), this_object());
   return 1; }

init(){
   ::init();
   add_action("bbench", "sit");
}

bbench(str){
   if(str == "wooden bench" || str == "bench"){
      write("You take a load off and relax on the bench.\n");
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n,s,w]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n,s,w]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n,s,w]";
}
