#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit "/players/wocket/mages/obj/page.c";

reset(){
  spell = "stoneskin";
  spell_short = "Stoneskin";
  spell_desc = "Through the mystic enchanements of the ages there have always\n"+
               "been rumors of men being turned to stone.  Some have learned\n"+
               "learned to capture this power for good.\n";
  spcost = 150;
  hpcost = 0;
  coincost = 0;
  type = "enc";
  size = 5;
  time = 4;
}

check_spell(object mage,string str){
  return 1;
}

cast_spell(object mage){
object stoneskin;
  tell_object(mage,"You cast stoneskin.\n");
  stoneskin = clone_object(OBJDIR+"stoneskin_ob.c");
  move_object(stoneskin,mage);
  mage->wear(stoneskin);
  return 1;
}
