inherit "obj/weapon";
#include "/obj/ansi.h"


int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("whip");
        set_short(HIK+"Belmont's Whip"+NORM);
       set_long("This is the whip of the Belmont Clan, passed down from generation to generation.\n"+
		" It is said that this instrument has slain the legendary vampire, Dracula.\n");
        set_params("other|good",3,0);
		set_params("other|light",3,0);
	    set_class(17);
        set_weight(1);
        set_value(1200);
        message_hit = 
    ({
        BOLD+" ~~EVISCERATED~~ "+NORM," blood gushes everywhere",
        HIR+" --==FILLETS==--   "+NORM," extremely hard",
        HIY+" --==SLICES==-- "+NORM," viciously",
        HIC+" snapped "+NORM,", with precision",
        HIG+" cracked "+NORM," drawing a little blood",
        HIB+" grazed "+NORM," lightly",
        HIW+" struck "+NORM," very lightly"
    });

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
  if (i>5) {

        say(this_player()->query_name()+"'s "+BOLD+"whip"+HIY+" hums"+NORM+" with a "+HIC+" righteous"+NORM+" aura.\n");
        write(""+BOLD+"Belmont's whip "+NORM+" glows with "+BOLD+"Holy Fire"+NORM+".\n");
  return 3;
    }
   return 0;
}
