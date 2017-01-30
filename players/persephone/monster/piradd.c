inherit "obj/monster";
#include "/players/persephone/rooms.h"
object cyril;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      cyril = clone_object("players/persephone/obj/body");
      move_object(cyril,TOB);
      set_name("bucaneer");
      set_alias("pirate");
      set_alias("man");
      set_short("Bucaneer");
      set_long("One of the many bucaneers and pirates wandering\n"+
               "around Stormhold mind you think it is best to leave\n" +
               "him alone\n\n");
      set_level (18);
      set_wc (28);
      set_ac (16);
      set_hp(475);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(30);
      set_a_chat_chance(30);
      load_chat("The Bucanneer eyes you up and down warrily\n");
      load_chat("The Bucanneer yawns\n");
      load_chat("The Bucanneer states no one is getting passed here\n");
      load_a_chat("The Bucanneer snickers that did not hurt\n");
      load_a_chat("The Bucanneer grins at you\n");
}


init(){
  ::init();
    add_action("gerble","up");
    add_action("gerble","u");
}
gerble(){
  write("The buccaneer asks where you think you are going\n");
  say("The buccaneer blocks " + CAPTPLNM + "'s way up\n");
return 1;
}
