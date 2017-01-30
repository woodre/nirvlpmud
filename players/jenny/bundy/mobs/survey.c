inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("survey lady");
    set_alt_name("survey");
    set_alias("lady");
    set_race("human");
    set_al(-14);
    set_level(15);
    set_hp(233+random(20));
    set_wc(18);
    set_ac(13);
    set_gender("female");
    set_short("A survey lady");
    set_long(
      "This is a survey lady who works in the mall.  She is a slightly\n"+
      "overweight woman in her mid-50's.  She stops shoppers to get\n"+
      "information on what types of food they eat, what products they\n"+
     "like to buy, and their views on various issues.\n");
  gold=clone_object("obj/money");
  gold->set_money(720+random(100));
  move_object(gold,this_object());
  set_chat_chance(8);
  load_chat(""+CYN+"The lady says:"+NORM+ "  Would you like to take a survey?\n");
set_a_chat_chance(16);
  load_a_chat(""+CYN+"The survey lady says:"+NORM+" PLEASE!  I'm just doing my job!\n");
}
init() {
  ::init();
add_action("stop","north");
add_action("stop","south");
add_action("stop","west");
add_action("stop","east");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else {
if(TP->query_level() >12 && TP->query_level() <20) {
write(""+CYN+"The survey lady says: "+NORM+"Just a few minutes of your time please.\n");
return 1; }}
}
