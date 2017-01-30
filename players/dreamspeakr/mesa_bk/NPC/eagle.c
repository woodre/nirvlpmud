#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("eagle");
     set_alias("eagle");
     set_alt_name("bald eagle");
     set_race("bird");
     set_gender("female");
     set_short(YEL+"Bald Eagle"+NORM);
     set_long(
       "This large bird of prey, having a pure white head, neck and \n"+
       "tail, with a wing span of about 3 feet long.  She appears to \n"+
       "be searching for food for her nest of young ones.\n");

     set_level(13);
     set_hp(195);
     set_al(0);
     set_wc(17);
     set_ac(10);
     set_aggressive(0);

     set_chat_chance(5);
       load_chat("The bald eagle lets out a loud "+HIR+"SQUAWK"+NORM+"!\n");
     set_a_chat_chance(35);
       load_a_chat("The eagle's claws "+HIR+"scratch"+NORM+" at your eyes.\n"); 
       load_a_chat("The eagle swoops down "+RED+"pecking "+NORM+"you on the forehead.\n");
       load_a_chat(HIR+"Blood"+NORM+" pours down your forhead, the eagle cuts you deep.\n");
       load_a_chat("The eagle clamps down hard on your kneck with his "+RED+"talons"+NORM+".\n");
       load_a_chat("Swiftly the eagle lunges its "+RED+"talons"+NORM+" into your face!\n"); 
       load_a_chat("The eagle's sharp "+RED+"beak"+NORM+" pecks at your eyes!\n");
     set_dead_ob(this_object());
}

monster_died() {
    move_object(clone_object("players/dreamspeakr/mesa/OBJ/talon.c"), environment(this_object()));
    tell_room(environment(this_object()),
	"The eagle falls to the ground breaking off a talon. \n");
    return 0; 
    }