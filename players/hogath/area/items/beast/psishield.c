/****************************************************
creator:  Hogath                                    *
Started:  3/28/04                                   *
Type:  shield                                       *
For:  Monsters in demon forest                      *
In game:  No                                        *
For Player Use:  NO                                 *
Please refer to psiblade for reason :P              *
*****************************************************/


#include <ansi.h>
#include "/players/hogath/tools/def.h"
inherit "obj/armor";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_name(HIB+"Psi-shield"+NORM);
    set_alias("shield");
    set_short(HIB+"Psi-shield"+NORM); 
    set_long("A shield made up of mental energy.\n");
    set_ac(2);
    set_type("shield");
    set_weight(0);
    set_value(0);
}
do_special(owner)
{
    int i;
    i = random(10);
    if(i == 10)
    {
     tell_object(owner, tpn+BOLD+"[Blocks]"+NORM+" with "+tp->query_possessive()+" shield\n");
     return (1+(random(2)));
    }
}
