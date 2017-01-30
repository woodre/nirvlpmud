#include "/players/jareel/define.h"
inherit "obj/monster.c";
reset(arg)  {
 ::reset(arg);
  if(arg) return;

set_name("joe");
set_alias("shop keeper");
set_alt_name("barkeep");
set_race("human");
set_short("The barkeep Joe");
set_long(
  "You see a man behind the bar being very attentive.  His \n"+
  "baby blue eyes flicker in the light of the hearth fire, and\n"+
  "his toothless grin sends a shiver up your spine.\n");
set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_heal(5,5);
set_aggressive(0);
set_dead_ob(this_object());
add_money(400);
}

init() {
 ::init();
  add_action("order","order");
  add_action("order","buy");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
}if (str == "jungle juice") {
        mess = "Your senses feel heightened.  You are now ready to face the world";
        heal = 0;
        value = 60;
        strength = -3;
}else if (str == "faerie legs") {
        mess = "A tingling feeling goes through your body as you crunch the leg";
        heal = 5;
        value = 50;
        strength = 14;
}else if (str == "beer") {
        mess = "You feel a heluva lot better";
        heal = 40;
        value = 480;
        strength = 12;
}else if (str == "dwarf haunch") {
        mess = "A tingling feeling goes through your body as you crunch the leg";
        heal = 30;
        value = 300;
        strength = 12;
}else if (str=="everclear") {
        mess = "Your eyes close and your face tightens";
        heal = 25;
        value = 500;
        strength = 6;
}else {
       write("Bartender says: Whats your poisen?\n");
       return 1;
}if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " punk, come back when you have coins.\n");
        return 1;
}cost = value;
    if (!call_other(this_player(), "drink_alcohol", strength)) {
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                str + " but the bartender refuses.\n");
        return 1;
}write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}

