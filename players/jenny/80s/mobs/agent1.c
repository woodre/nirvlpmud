inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "secret service agent" ||  str == "agent" || str == "bodyguard"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("secret service agent");
    set_race("human");
set_gender("male");
    set_al(50+random(15));
    set_level(8); 
    set_hp(120+random(10));
    set_wc(12+random(2));
    set_ac(7);
    set_short("A secret service agent");
    set_long(
      "This burly man wearing a black suit, and dark sunglasses is\n"+
      "a member of the secret service.  He is assigned to protect the\n"+
     "President of the United States.  It is doubtful he will let you\n"+
      "get anywhere near the president.  Security has been tight ever\n"+
      "since Hinkley's assassination attempt.\n");
  gold=clone_object("obj/money");
  gold->set_money(250+random(100));
  move_object(gold,this_object());
}
init() {
  ::init();
add_action("stop","east");
}
stop() {
if(TP->query_ghost() == 1 || TPL > 20) { return 0; }
else{
write(HIR+"The agent says:  "+NORM+"I can't let you go in there.\n");
return 1; }
}
