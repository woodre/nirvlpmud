inherit "obj/weapon";
#include "/obj/ansi.h"
#include "/players/jareel/define.h"

  int i;
  
  reset(arg) {
    ::reset(arg);
    if(arg) return;
    
	set_alias("truesword");
    set_name("truesword");
    set_short(HIK+"TrueSword"+NORM);
    long_desc =
      "This is the scythe of legend, "+BOLD+"Deaths Scythe"+NORM+" wielded by\n"+
      " Death himself. There are runes in which you cannot Interpret written along \n"+
      " the black blade. This blade seems almost "+HIK+"evil"+NORM+".\n",
    
	set_class(21);
    set_params("physical",20,0);
    set_params("physical",20,0);

    set_type("sword");
    set_weight(3);
    set_value(1200);
    message_hit = ({
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
    i=random(2);
      if (i==0) {
        say(this_player()->query_name()+"'s "+BOLD+"scythe"+HIY+" glows"+NORM+" with a "+HIR+"deadly"+NORM+" aura.\n");
        write(""+BOLD+"Death's scythe "+NORM+" summons undead "+BOLD+"SPIRITS"+NORM+" upon its FOE!!!.\n");
    return 4;
    }
  }

