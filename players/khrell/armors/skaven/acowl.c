#include "/players/khrell/define.h"
#include <ansi.h>
inherit ARMOUR;


reset(arg) {
   set_name("assassins cowl");
   set_alias("cowl");
   set_short(HIK+"Cowl of Assassination"+NORM);
   set_long("\
   Part of the infamous garb worn by Eshin master assassins.  Woven\n\
from the hairs of slain spell casters and bound with the essence of\n\
shadows.  It is quite thin and can easily fit over one's face without\n\
obstructing other armors.                                           \n");      
   
   set_ac(2);
   set_type("misc"); 
   set_weight(0);
   set_value(1100);
}
