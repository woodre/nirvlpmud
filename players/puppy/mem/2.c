#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   move_object(clone_object("/players/puppy/mem/fman.c"), this_object());
   move_object(clone_object("/players/puppy/mem/board.c"), this_object());
   
   set_short("A place to remember");
   set_long(
      "The wreckage that has fallen covers the ground.  Under a pile\n"+
      "of rubble are the remains of an engine from station thirty four.\n"+
      "The outline of the foundations to both towers can be seen here.\n"+
      "Reaching down from the sky is a giant piece of framework that\n"+
      "forms an archway.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "An ashy odor fills the air.");
add_property("NF");
   items = ({
         "wreckage", "The remains of the twin towers in it's final resting place",
         "ground", "The place where the twin towers once stood",
         "pile of rubble", "Pieces of metal and stone that litter the ground", 
         "rubble", "Pieces of metal and stone that litter the ground",
         "pile", "Pieces of metal and stone that litter the ground",
         "remains", "A crushed piece of equipment used by the NYFD",
         "engine", "A crushed piece of equipment used by the NYFD",
         "foundation", "The remains of what was once the base of two great buildings",
         "foundations", "The remains of what was once the base of two great buildings",
         "giant piece of framework", "A huge iron structure that fell from the towers.  It looks like\n"+
         "you may be able to enter through an opening in the structure",
         "piece of framework", "A huge iron structure that fell from the towers.  It looks like\n"+
         "you may be able to enter through an opening in the structure",
         "framework", "A huge iron structure that fell from the towers.  It looks like\n"+
         "you may be able to enter through an opening in the structure",
         "archway", "A huge iron structure that fell from the towers.  It looks like\n"+
         "you may be able to enter through an opening in the structure",
         "arch", "A huge iron structure that fell from the towers.  It looks like\n"+
         "you may be able to enter through an opening in the structure",
         "opening", "It looks like you might be able to 'enter' the opening",
         "sky", "You can not see the sky because of all the debry in the air"});
   
   
   dest_dir = ({
         "/players/puppy/mem/1.c", "up",
         "/players/puppy/mem/glaxgor", "south",
});
}

init () {
   ::init() ;
   add_action("blah", "enter");
}
blah(str) {
   if(str == "arch" || str == "archway" || str == "opening") {
      write("You carefully step through the framework.\n");
      say(this_player()->query_name()+" steps through the framework.\n");
      tell_room("players/puppy/mem/3.c", this_player()->query_name()+" arrives through an opening in the framework.\n");
      move_object(this_player(),"/players/puppy/mem/3.c");
      command("look",this_player());
      return 1;
   }
   if(!str) {
      write("What are you trying to enter?\n");
      return 1;
   }
}
