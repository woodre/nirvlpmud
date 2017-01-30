/************************************************************
creator: Hogath                                             *
Started: 3/25/04                                            *
Type:  Weapon                                               *
For: Neuron Beast and psionic based mobs                    *
In game:  No                                                *
For Player Use: No                                          *
This is a non player weapon, it is intended for use only on *
Certian mobs.  Please do not give it to any players         *
Hogath                                                      *
*************************************************************/


#include <ansi.h>
#include "/players/hogath/tools/def.h"
inherit "obj/weapon.c";

object ob;
int i;


reset (arg){

    int level;
    ::reset(arg);
    if (arg) return;
    set_name(HIW+"Psi-Blade"+NORM);
    set_alias("blade");
    set_long("\n");
    set_class(15+(tp->query_level()/5));
    set_weight(0);
    set_value(0);
    set_type("sword");
    set_hit_func(this_object());}


weapon_hit(atacker){

    ob = tp->query_attack();
    i = random(5);
    if(i = 5)
    {
     write("Light streams along sword, as it hits.\n");
     say(tpn+" slashes at "+ob->query_name()+".\n");
     return (random(20));
    } 
    return 1;
}
