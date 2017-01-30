/* approved for play 4/1/00 - Eurale  */

inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("boss hogg");
    set_alt_name("hogg");
    set_race("human");
    set_alias("boss");
    set_al(-(350+random(240)));
set_gender("male");
    set_level(13);
    set_hp(180+random(40));
    set_wc(15+random(3));
MOCO("/players/jenny/dukes/items/cigar.c"),this_object());
    set_ac(8+random(4));
    set_short(BOLD+""+WHT+"Boss Hogg"+NORM);
    set_long(
      "Jefferson Davis Hogg is the Hazzard county commissioner.  He\n"+
      "is a short, fat man, about 60 years old, who is losing what's\n"+
     "left of his grey hair.  Boss is dressed in a white suit, and\n"+
      "matching top hat.  His main interests in life are food, food,\n"+
      "money, and more food, in that order.  Boss Hogg is crookeder\n"+
     "than a corkscrew.  He is always cooking up a scheme.  His\n"+
     "schemes usually involve swindling someone's money, and trying\n"+
     "to frame the Duke boys and put them in jail.  You might want\n"+
     "to "+CYN+"buy "+NORM+"a "+CYN+"radar gun"+NORM+" from him for 200 coins.\n");
  gold=clone_object("obj/money");
  gold->set_money(100+random(100));
  move_object(gold,this_object());
set_chat_chance(25);
    load_chat(WHT+"Boss Hogg says: "+NORM+" Can I interest you in a radar gun?\n");

}
init() { 
    ::init(); 
add_action("radar","buy");
}
radar(arg) {
if(!arg) { notify_fail("What do you want to buy?\n"); return 0; }
if(arg == "radar" || arg == "radar gun" || arg == "gun") {
 if(!this_player()->add_weight(1)) {
    write("You can't carry that.\n");
return 1; }
if(this_player()->query_money() < 200) {
write("You can't afford that!\n");
return 1; }
TP->add_money(-200);
write("You buy a radar gun.\n");
say(TPN+" buys a radar gun.\n");
MOCO("/players/jenny/dukes/items/radar.c"),TP);
write_file("/players/jenny/logs/radar", ""+TPRN+" bought a radar gun at "+ctime()+"\n");
return 1; }
}
