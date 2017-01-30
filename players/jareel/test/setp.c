inherit "obj/weapon";
#include "/obj/ansi.h"


int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("scythe");
          set_name("Death's Scythe");
        set_short(HIK+"Death's Scythe"+NORM);
       long_desc =
            "This is the scythe of legend, "+BOLD+"Deaths Scythe"+NORM+" wielded by\n"+
                " Death himself. There are runes in which you cannot Interpret written along \n"+
                " the black blade. This blade seems almost "+HIK+"evil"+NORM+".\n",


				set_params("other|ice",27,0);
				set_params("other|fire",27,0);
				set_params("other|water",27,0);






    	set_type("exotic");
        set_class(2);
        set_weight(3);

        set_value(7200);
        message_hit = 
    ({
        BOLD+" EVISCERATED "+NORM," Blood gushes everywhere",
        HIR+" FILLETED  "+NORM," extremely hard",
        HIY+" MINCED "+NORM," viciously",
        HIC+" sweeped "+NORM,", with precision",
        HIG+" slashed "+NORM," drawing a little blood",
        HIB+" grazed "+NORM," lightly",
        HIW+" struck "+NORM," very lightly"
    });
      query_save_flag();
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

        say(this_player()->query_name()+"'s "+BOLD+"scythe"+HIY+" glows"+NORM+" with a "+HIR+"deadly"+NORM+" aura.\n");
        write(""+BOLD+"Death's scythe "+NORM+" summons undead "+BOLD+"SPIRITS"+NORM+" upon its FOE!!!.\n");
  return 3;
    
}
}