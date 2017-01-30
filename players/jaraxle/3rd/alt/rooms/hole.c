#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   int i;
   if(!present("phantom", this_object())){
      
      for(i = 0; i < 4; i++){
         
         move_object(clone_object("/players/jaraxle/3rd/alt/mobs/mini_phantom"),
            this_object());
         
      } 
      
   }
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Dark hole"+NORM;
   long_desc =
   "  A dark hole that doesn't seem to belong.  Along\n"+
   "the back wall a large, wavering shadow is cast from\n"+
   "the darkness.\n";
   add_item("shadow","Odd, a shadow in a dark room.\nIt looks almost translucent");
   add_exit("/players/jaraxle/3rd/alt/rooms/road2.c","up");
   
}

cmd_search(str)
{
   if(str == "shadow")
      {
      write("As you try to search the shadow your hand passes into the wall.\n");
   }
   else ::cmd_search(str);
   return 1;
}

init(){
   ::init();
   add_action("enter","enter");
}
enter(str){
   if(!str) return (notify_fail("What?\n"), 0);
   if(str == "shadow" || str == "portal"){
      write("You slide through the shadow to the other side...\n");
      TP->move_player("up#/room/adv_guild");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
