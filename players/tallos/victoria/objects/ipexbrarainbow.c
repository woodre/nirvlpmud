inherit "/obj/armor";
#include "/obj/ansi.h"
#include "DEFS.h"

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("bra");
  set_alias("underwear");
  set_short(BOLD+"An "+HIB+"<"+HIR+"IPEX"+HIB+">"+NORM+""+HIR+" B"+HIY+"r"+HIG+"a"+HIW+" and"+HIB+" P"+HIM+"a"+HIR+"n"+HIY+"t"+HIG+"i"+HIB+"e"+HIM+"s"+NORM);
  set_long(
  "         This set of "+HIR+"B"+HIY+"r"+HIG+"a"+NORM+" and"+HIB+" P"+HIM+"a"+HIR+"n"+HIY+"t"+HIG+"i"+HIB+"e"+HIM+"s"+NORM+" is from the "+HIM+"Victoria's\n"+
  "Secret"+HIB+" <"+HIR+"IPEX"+HIB+">"+NORM+""+NORM+" series.  It is often known as the worlds most\n"+
  "advanced "+HIR+"B"+HIY+"r"+HIG+"a"+NORM+". It's virtually weightless, has maximum "+NORM+""+RED+"nipple"+NORM+"\n"+
  "coverage, and minimal "+HIY+"padding"+NORM+". Far considered to be amongst\n"+
  "the most comfortable and best fitting of all"+HIR+" B"+HIY+"r"+HIG+"a"+HIB+"s"+NORM+".  The "+HIR+"b"+HIY+"r"+HIG+"a"+NORM+"\n"+
  "seems to make you want to 'show' it to people.\n");
  set_type("underwear");
  set_type("underwear");
  set_ac(2);
  set_weight(0);
  set_value(20000);
}
init() {
  ::init();
  add_action("show","show");
}
show(str) {
object obj;
if(!str) { write("What would you like to model?\n"); return 1; }
if(str == "bra" || str == "panties" || str == "underwear") {

if(TPHP < 10 || TPSP < 70) {
   write("You aren't really feeling up to modeling right now. You just don't have the energy for it.\n");
return 1; }

  obj = first_inventory(ETP);
  while(obj) {
    obj->stop_fight();
    obj->stop_fight();
    obj->stop_hunter();
    obj = next_inventory(obj);
  }

write("You model off your sexy underwear for all to see. "+NORM+
      "Everyone stops and is mezmorized by the show.\n");
say(capitalize(TPRN)+" puts on a sexy show for you and all others in the room modeling their underwear. *"+NORM+
    "You seem to stop what you are doing and stare with hungry eyes.\n");
TP->add_spell_point(-70);
  return 1; 
}
}


