#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
inherit "obj/weapon";
int hit, heal, n;
reset (arg){

     set_name("vampsword");
     set_alias("sword");
     set_class(17);
     set_weight(4);
    set_short(BOLD + "Sword " + NORM + "of " + RED + "V" + NORM + "ampiric " + RED + "R" + NORM + "egeneration");
     set_long("  This sword " + RED + "glows" + NORM + " with warmth, and you feel much better after\n\
 holding it for awhile.  It is the most gigantic sword you\n\
 have ever seen, so you may have to strain to carry it.\n");
     set_value(random(1000)+999);
    /* reduced value from 100,000 to 1000+random(999) */
    /* nothing really need to be worth 100,000 vital 11/6/2003 */
     set_hit_func(this_object());
}

weapon_hit(attacker){
     int i;
     object gob;
     if(this_player()->query_guild_name() == "vampire") {
       if(gob = present("fangs", this_player())) {
         if( random(3) ) gob->add_BLOODPTS( random(4) );
         write(RED+"Blood"+NORM+" flows down the weapon into your hands.\n");
         return 0;
       }
     }
     i = random(20);
       if(i<4){
        heal = random(7);
        call_other(this_player(), "add_hit_point", heal);
        write("You feel rejuvenated by the power of the sword.\n");
}
return 1;
}
