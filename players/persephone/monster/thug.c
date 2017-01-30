inherit "obj/monster";
#include "/players/persephone/rooms.h"
object cyril;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      cyril = clone_object("players/persephone/weapon/bill");
      move_object(cyril,TOB);
      set_name("thug");
      set_alias("bouncer");
      set_short("Thug");
      set_long("A mean and angry thug who only wants to see you dead.\n"+
               "By his big and muscular chest you think he might be able\n" +
                "to kill you with his bare hands\n");
      set_level (20);
      set_wc (30);
      set_ac (17);
      set_hp(500);
      set_al(0);
      set_aggressive(1);
      set_gender ("male");
}


init(){
  ::init();
    add_action("gerble","up");
    add_action("gerble","u");
    add_action("gerble","south");
    add_action("gerble","s");
    add_action("gerble","north");
    add_action("gnrble","e");
}
gerble(){
  write("The Thug asks where you think you are going\n");
  say("The Thug blocks " + CAPTPLNM + "'s way\n");
return 1;
}
