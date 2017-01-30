#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int toughness;
int readout;
object ob;
id(str) { return str == "radar gun" || str == "gun" || str == "radar"; } 
reset(int arg) {
  if(arg) return;
set_short(BOLD+""+RED+"A radar gun"+NORM);

set_long(
"This is a radar gun used by members of the Hazzard County Sheriff's Department.\n"+
"Upon closer inspection, it looks more like a common hair dryer.  Isn't that\n"+
"just like Boss Hogg?  The state gives him money to buy radar guns, and he keeps\n"+
"it and gives the Sheriff's Department hair dryers instead.  The inexperienced\n"+
"adventurer may still find it useful to "+CYN+"clock "+NORM+"monsters with.\n");

set_weight(1);
set_value(100);
}
init() { 
    ::init(); 
add_action("monster","clock");
}
monster(string name) {
    object ob;
    if(TPL > 10 && TPL < 21) {write("You are too experienced to need this gun.\n"); return 1; }
if(!name) {notify_fail("What do you want to clock?\n"); return 0; }
    ob = present(name, environment(this_player()));
        if (!ob) {
        write("That is not here.\n");
        return 1; }
    toughness = ob->query_composite();
    if(toughness < 100) {readout = "very weak";}
    if(toughness > 99 && toughness < 200) {readout = "weak";}
    if(toughness > 199 && toughness < 400) {readout = "mediocre";}
    if(toughness > 399 && toughness < 600) {readout = "medium";}
    if(toughness > 599 && toughness < 800) {readout = "medium tough";}
    if(toughness > 799 && toughness < 1000) {readout = "tough";}
    if(toughness > 999 && toughness < 1700) {readout = "very tough";}
    if(toughness > 1699) {readout = "It's your funeral.";}

    write(BOLD+""+WHT+""+CAP(name)+"'s strength can best be described as:"+RED+"  "+readout+""+NORM+"\n");
    return 1; }
