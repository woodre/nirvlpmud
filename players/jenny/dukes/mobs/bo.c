inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("bo duke");
    set_race("human");
    set_gender("male");
    set_alias("duke");
    set_alt_name("bo");
    set_al(320+random(300));
    set_level(16);
    set_hp(230+random(100));
    set_wc(20+random(6));
    set_ac(11+random(4));
    set_short(WHT+""+YEL+"Bo Duke"+NORM);
    set_long(
      "Bo Duke is a slender young man, about 20 years old with\n"+
     "wavy blond hair.  He is wearing blue jeans and a yellow\n"+
     "short sleeved dress shirt.  Bo is a good, well mannered\n"+
     "country boy.  He and his cousin Luke are both on probation\n"+
     "for running moonshine, and must stay in Hazzard County.\n"+
     "Even though he is generally law abiding now days, he still\n"+
     "manages to get in plenty of trouble with the law.  The hazzard\n"+
     "County Police are always looking for, and creating excuses\n"+
     "to put him and Luke in jail.  Bo is one of the best drivers in\n"+
     "Hazzard County, and usually is the one driving the General Lee.\n");
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
write(""+YEL+"Bo says: "+NORM+"No sir!  You aint opening the trunk.\n");
return 1; }
}
