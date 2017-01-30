#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit PAGE;

object mage,master;
reset(){
  spell = "bauble";
  spell_short = "Bauble";
  spell_desc = "   Many great wizards were once young apprenticies to the arts\n"+
               "of magic.  They, through great practice and dedication, becaome\n"+
               "some of the most powerfull people in our time.  Most started out\n"+
               "with learning the simple task of creating a shimmering ball of\n"+
               "light, in order to learn how better to concentrate.  This trinket\n"+
               "started them on the path of greatness.\n";
  size = 2;
  time = 3;
  hpcost = 0;
  spcost = 20;
  ppgain = 10;
  type = "sor";
}

check_spell(object mage,str){
return 1;
}

cast_spell(mage){
object bauble;
int i,a;
tell_object(mage,"You focus upon a sphere of empty space before you. Your\n"+
                 "hands cupping the globe as rays of light swirl, and begin\n"+
                 "to take form.  Suddenly a ball of glowing light appears.\n");
mage->remote_say(mage->query_name()+" creates a ball of glowing light out of thin air.\n");
  bauble = clone_object("/players/wocket/mages/obj/bauble_ob.c");
  move_object(bauble,mage);
  return;
}
