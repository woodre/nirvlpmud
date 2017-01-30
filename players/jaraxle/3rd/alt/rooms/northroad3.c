#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   no_clean = 1;
   short_desc = BLK+BOLD+"Village road (Northroad)"+NORM;
   long_desc =
   "  Northroad has come to it's end, as you see animal and\n"+
   "human bones scattered around. To the north you see a\n"+
   "swirling vortex as well as the remains of the old K-mart\n"+
   "store. By first glance you would guess that the Vortex\n"+
   "opened inside the K-Mart thereby destroying it with the\n"+
   "staff and customers.\n";
   
add_item("vortex","A swirling blue and black vortex.\n"+
                  "Spinning maddly in the middle of\n"+
                  "the old K-Mart. It looks like you\n"+
                  "can see through to some odd land");
add_item("swirling vortex","A swirling blue and black vortex.\n"+
                  "Spinning maddly in the middle of\n"+
                  "the old K-Mart. It looks like you\n"+
                  "can see through to some odd land");
   add_item("bones","Bones from the dead customers and pets of K-Mart");
   add_item("store","An old Super K-Mart, torn to asunder by a vortex");
   add_object("/players/jaraxle/3rd/alt/mobs/quin.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad2.c","south");
}

init(){
   ::init();
   add_action("enter","enter");
}
enter(str){
   if(!str) return (notify_fail("What?\n"), 0);
   if(str == "vortex" || str == "swirling vortex"){
      write("You slide through the vortex to the other side...\n");
      TP->move_player("up#/room/adv_guild");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
