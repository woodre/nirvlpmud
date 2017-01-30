inherit "obj/weapon";
#include "/obj/ansi.h"


int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("sword");
	  set_name("soulcleaver");
        set_short(""+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+"");
       long_desc =
        "  Titanium laser cut alloy encrusted with Diamonds. This\n"+
        "sword has claimed countless lives; its thirst for bloodlust\n"+
        "is unrelentless. Bloodlust consumes whosoever gazes onto its\n"+
        "amazingly sharp blade.\n";
        set_params("other|evil",3,0);
		set_type("sword");
		set_params("other|dark",3,0);
	    set_class(18);
        set_weight(3);
        set_value(2000);

	  message_hit = ({
        BOLD+"hewed"+NORM," into "+BOLD+RED+"bloody slabs"+NORM,
        BOLD+"cleaved"+NORM,", leaving deep angry gashes",
        BOLD+"hacked"+NORM," into thin slices",
        BOLD+"slashed"+NORM,", laying open their flesh",
        BOLD+"stuck"+NORM," deep into the bowels",
        BOLD+"cut"+NORM," with a surgeon's skill",
        BOLD+"whittled"+NORM," into small shavings"
        });
		 
      query_save_flag();
	  
      set_hit_func(this_object());
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}
weapon_hit(attacker) {
  i=random(10);
  if (i>4) {

        say(this_player()->query_name()+"'s "+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+" glows with a "+HIR+"deadly"+NORM+" aura.\n");
        write(""+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+" summons Slayn "+BOLD+"SPIRITS"+NORM+" to harm its foe!.\n");
  return 3;
    
}
}	