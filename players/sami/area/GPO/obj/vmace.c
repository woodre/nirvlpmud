inherit "obj/weapon";

#include "/obj/ansi.h"


int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("mace");
	  set_name("cudgel");
        set_short("cudgel");
       long_desc =
        "  Iron mace encrusted with rust and blood. Other than looking\n"+
        "as if it could fall apart at any moment, it appears to be well\n"+
		"made. a note on the side reads 'cast in the forge of sami'.\n";
        set_params("other|evil",3,0);
		set_type("mace");
		set_params("other|dark",3,0);
	    set_class(15);
        set_weight(3);
        set_value(1200);
/*
	  message_hit = ({
        BOLD+"hewed"+NORM," into "+BOLD+RED+"bloody slabs"+NORM,
        BOLD+"cleaved"+NORM,", leaving deep angry gashes",
        BOLD+"hacked"+NORM," into thin slices",
        BOLD+"slashed"+NORM,", laying open their flesh",
        BOLD+"stuck"+NORM," deep into the bowels",
        BOLD+"cut"+NORM," with a surgeon's skill",
        BOLD+"whittled"+NORM," into small shavings"
        });
	*/	 
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
  if( !environment() || environment()->is_player() )
    return;
  if (i>8) {
        say(environment()->query_name()+"'s cudgel glows with a "+HIR+"deadly"+NORM+" aura.\n");
        write("Your cudgel glows with a "+HIR+"deadly"+NORM+" aura.\n");
  return 3;
    
}
}	
