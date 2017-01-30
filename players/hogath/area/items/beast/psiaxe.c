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
id(str) {return str=="axe" || str=="psi-axe" || str=="psi axe" || str=="psi_axe";}

reset (arg){
    
    ::reset(arg);
    if (arg) return;
    set_name(BOLD+"Psi-Axe"+NORM);
    set_long("An axe made up of pure mental energy.  It\n"+
             "seems as if your hand could pass through it.\n");
    set_weight(0);
    set_value(0);
    set_type("axe");
    set_hit_func(this_object());}

wield(str){
    if(!id(str)) return 0;
    if(wielded) return 0;
    ::wield(str);
    set_class(16+(tp->query_level()/5));
    return 1;
}

unwield(str){
    if(!id(str)) return 0;
    if(!wielded) return 0;
    ::unwield(str);
    set_class(16); 
    return 1;
}
    weapon_hit(atacker){
    int bonus;    
    ob = tp->query_attack();
    i = random(5);
    if(i > 3)
    {
     write(tpn+" "+BLINK+"grins"+NORM+" as the axe bites into "+ob->query_name()+".\n");
     say(ob->query_name()+" staggers back as the axe\n\n"+
        "\t\t"+HIR+"STRIKES A BLOODY BLOW"+NORM+".\n");
     bonus = tp->query_level();
     return (5+random(bonus));
    } 
    else return 0;
}
