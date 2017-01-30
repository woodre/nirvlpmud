inherit "obj/monster";
#include "/players/persephone/rooms.h"
object cyril;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      cyril = clone_object("players/persephone/obj/bill");
      move_object(cyril,TOB);
      set_name("swashbuckler");
      set_alias("pirate");
      set_short("Swashbuckler");
      set_long("A swift and dashing young Swashbuckler\n"+
               "by the swagger in his step you think he\n" +
               "he thinks he runs the town\n\n");
      set_level (20);
      set_wc (30);
      set_ac (17);
      set_hp(500);
      set_al(0);
      set_aggressive(1);
      set_gender ("male");
      set_a_chat_chance(30);
      load_a_chat("The Swashbuckler snickers you have met your match this time\n");
      load_a_chat("The Swashbuckler says trying to sneak past me are you\n");
      load_a_chat("The Swashbuckler looks at his fingernails and yawns\n");
      load_a_chat("The Swashbuckler grins at you\n");
}


init(){
  ::init();
    add_action("gerble","up");
    add_action("gerble","u");
    add_action("gerble","south");
    add_action("gerble","s");
    add_action("gerble","east");
    add_action("gerble","e");
    add_action("gerble","west");
    add_action("gerble","w");
}
gerble(){
  write("The buccaneer asks where you think you are going\n");
  say("The buccaneer blocks " + CAPTPLNM + "'s way\n");
return 1;
}
