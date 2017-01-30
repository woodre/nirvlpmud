inherit "obj/weapon";
#include <ansi.h>


int hit, heal, n;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("grace");
	  set_type("exotic");
        set_short(""+HIR+"V"+HIK+"ampire's"+HIR+" G"+HIK+"race "+NORM+"("+HIR+"Evil forged"+NORM+")");
        set_long("This is the grace of a Vampire. It is rumoured that a vampire\n"+
		"can drain your blood using its grace alone\n");
        set_params("other|evil",15,0);
	    set_class(17);
        set_weight(3);
        set_value(7200);
        set_name(""+HIR+"V"+HIK+"ampire's"+HIR+" G"+HIK+"race "+NORM+"");
      set_hit_func(this_object());
}
weapon_hit(attacker){
     int i;
     object gob;
     if(this_player()->query_guild_name() == "vampire") {
       if(gob = present("fangs", this_player())) {
         if( random(3) ) gob->add_BLOODPTS((6));
         write("Your weapon feeds on the "+RED+"Blood"+NORM+" of your foe.\n");
		 write("You feel the absorbed "+RED+"Blood"+NORM+" racing through your veins.\n");
         return 1;
       }
     }
     i = random(20);
       if(i<4){
        heal = random(7);
        call_other(this_player(), "add_hit_point", heal);
        write("You feel rejuvenated by the power of the "+HIR+"V"+HIK+"ampire's"+HIR+" G"+HIK+"race "+NORM+".\n");
}
return 1;
}