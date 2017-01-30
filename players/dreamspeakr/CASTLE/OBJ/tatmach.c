#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

     set_name("machine");
     set_alias("machine");
     set_short(HIB+"Tattoo Machine"+NORM);
     set_long(
	" \n"+
        " \n"+
        " \n"+
        " \n"+
        " \n");
     set_type("knife");
     set_class(21);
     set_weight(4);
     set_value(1000);
     set_hit_func(this_object());
     set_save_flag(1);
}

  weapon_hit(attacker){
     int W;
       object theroom;
       theroom=environment(wielded_by);
     W = random(11);
     if(W>7)  {
       tell_room(theroom,"\n");
       tell_room(theroom,HIR+"         B L O O D    S P U R T S\n"+NORM);
       tell_room(theroom,"\n");
       tell_room(theroom,"             the needle rips through its foe's skin!\n");
       tell_room(theroom,"\n");
       wielded_by->add_spell_point(-random(20));
       return 11;
   }
}
