#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

object gold;
reset(arg) {
   int i;
   if(!present("phantom", this_object())){
      
      for(i = 0; i < 7; i++){
         
         move_object(clone_object("/players/jaraxle/3rd/alt/mobs/mini_phantom"),
            this_object());
         
      } 
      
   }
   if(arg) return;
   gold = clone_object("obj/money");
   gold->set_money(500+random(401));
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Huge Safe"+NORM;
   long_desc =
   "  An empty safe with a strange aura about it.\n"+
   "Along the walls, wavering shadows are cast through\n"+
   "the room.\n";
   add_item("shadow","Odd, a shadow in a dark room.\nIt looks almost translucent");
   add_item("shadows","Odd, shadows in a dark room.\nThey look almost translucent");
   add_exit("/players/jaraxle/3rd/alt/rooms/bank.c","out");
   move_object(gold, this_object());
   
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
 if(str == "shadow" || str == "shadows" || str == "portal"){
      write("You slide through the shadow to the other side...\n");
      TP->move_player("up#/room/bank");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
