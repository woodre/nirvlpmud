inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("luke duke");
    set_race("human");
    set_gender("male");
    set_alias("duke");
    set_alt_name("luke");
    set_al(340+random(300));
    set_level(16);
    set_hp(260+random(110));
    set_wc(22+random(4));
    set_ac(12+random(4));
    set_short(WHT+""+BLU+"Luke Duke"+NORM);
    set_long(
      "Luke Duke is a thin young man, who looks to be in his late\n"+
     "20's.  He is a little shorter and more muscular than his cousin\n"+
     "Bo.  He has dark hair, which is sort of curly.  He is an ex-marine,\n"+
     "and one of the best fighters in Hazzard.  Like all Dukes, he was\n"+
     "brought up to be courteous and well mannered.  He and his\n"+
     "cousin Bo are currently on probation for running moonshine,\n"+
     "and even though they are honest and basically law abiding, they\n"+
     "manage to be in constant trouble with the corrupt Hazzard\n"+
     "County Sheriff's Department.  Luke is one of the best drivers\n"+
     "in Hazzard County.  Even though he doesn't get to drive the\n"+
     "General much, when he does, he never fails to outrun Rosco.\n");
  gold=clone_object("obj/money");
  gold->set_money(400+random(200));
  move_object(gold,this_object());
}
init() {
  ::init();
add_action("trunk","open");
}
trunk(arg) {
if(arg == "trunk") {
if(!arg) { return 0; }
write(""+BLU+"Luke says: "+NORM+"No sir!  You aint opening the trunk.\n");
return 1; }
}
