/* Added cosmetics 8/16/02 - Eurale  */

#include "/open/ansi.h"
inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("spiked Chaos Platemail");
   set_short(BOLD+"Spiked Chaos Platemail"+NORM);
   set_alias("platemail");
   set_long("You can not stare for too long at the primal forces of Chaos.\n");
   set_long("You cannot stare for too long into the primarl forces of Chaos,\n"+
   "the opposite of Order and Good.\n");
   /* changed to AC 5 - 2004.11.01 Forbin */
   set_ac(5);
/* As an enchanted item, this armor should protect against magic as well */
   set_params("magical",2);
   /* Added defense against good  Illarion Dec 2004 */
   set_params("other|good",0,30,0);
   set_weight(3);
   set_value(1000);
}
