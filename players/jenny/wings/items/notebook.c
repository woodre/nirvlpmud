#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int strength,courage,stamina,protection,character;
string ST,PR,SA,CG,CH;
object ob;
id(str) { return str == "notebook" || str == "book" || str == "scotty bowman's notebook"; } 
reset(int arg) {
  if(arg) return;
set_short("Scotty Bowman's Notebook");

set_long(
"This is a black leather bound notebook, which belongs to Scotty Bowman.\n"+
"It contains scouting reports on everyone.  He uses this to help his team\n"+
"prepare for their opponents.  Maybe you can use this notebook to 'lookup'\n"+
"the people that you see.\n");

set_weight(1);
set_value(1000);
}
init() { 
    ::init(); 
add_action("monster","lookup");
}
monster(string name) {
    object ob;
if(!name) {notify_fail("What do you want to look up?\n"); return 0; }
    ob = present(name, environment(this_player()));
        if (!ob) {
        write("That is not here.\n");
        return 1; }
        if(!living(ob)) { write("That's not even a living thing!\n"); return 1; }
    strength = ob->query_wc();
    protection = ob->query_ac();
    courage = ob->query_wimpy();
    character = ob->query_alignment();
    stamina = ob->query_hp();
    if(strength < 10) { ST = "very weak";}
    if(strength > 9 && strength < 15) {ST = "weak";}
    if(strength > 14 && strength < 23) {ST = "average";}
    if(strength > 22 && strength < 32) {ST = "tough";}
    if(strength > 31 && strength < 41) {ST = "very tough";}
    if(strength > 40 && strength < 60) {ST = "extremely tough";}
    if(strength > 59) {ST = "badass";}
    if(protection < 6) { PR = "very light";}
    if(protection > 5 && protection < 10) {PR = "light";}
    if(protection > 9 && protection < 15) {PR = "average";}
    if(protection > 14 && protection < 20) {PR = "well protected";}
    if(protection > 19 && protection < 26) {PR = "very well protected";}
    if(protection > 25 && protection < 31) {PR = "extremely well protected";}
    if(protection > 30) {PR = "nearly impenetrable";}
    if(courage < 1) { CG = "fearless";}
    if(courage > 0 && courage < 10) {CG = "reckless";}
    if(courage > 9 && courage < 20) {CG = "bold";}
    if(courage > 19 && courage < 30) {CG = "average";}
    if(courage > 29 && courage < 40) {CG = "cautious";}
    if(courage > 39 && courage < 60) {CG = "timid";}
    if(courage > 59 && courage < 80) {CG = "cowardly";}
    if(courage > 79) {CG = "what a wuss!";}
    if(character < -700) { CH = "pure evil";}
    if(character > -701 && character < -400) {CH = "has a mean streak";}
    if(character > -401 && character < -100) {CH = "ornery";}
    if(character > -101 && character < 100) {CH = "indifferent";}
    if(character > 99 && character < 400) {CH = "positive";}
    if(character > 399 && character < 700) {CH = "gentlemanly";}
    if(character > 699) {CH = "saintly";}
    if(stamina < 90) { SA = "very little";}
    if(stamina > 89 && stamina < 165) {SA = "little";}
    if(stamina > 164 && stamina < 250) {SA = "below average";}
    if(stamina > 249 && stamina < 400) {SA = "average";}
    if(stamina > 399 && stamina < 600) {SA = "good";}
    if(stamina > 599 && stamina < 850) {SA = "very good";}
    if(stamina > 849 && stamina < 1200) {SA = "great";}
    if(stamina > 1199 && stamina < 1800) {SA = "incredible";}
    if(stamina > 1799 && stamina < 3000) {SA = "unbelievable";}
    if(stamina > 2999 && stamina < 6000) {SA = "insane";}
    if(stamina > 5999) {SA = "WOW!";}
    if(strength > 59) {ST = "badass";}

write(BOLD+WHT+"\n"+
"		All Available Info On "+CAP(ob->query_name())+"\n"+
"\n"+
"		Strength:"+RED+"	"+ST+WHT+"\n"+
"		Protection:"+RED+"	"+PR+WHT+"\n"+
"		Stamina:"+RED+"	"+SA+WHT+"\n"+
"		Attitude:"+RED+"	"+CH+WHT+"\n"+
"		Courage:"+RED+"	"+CG+NORM+"\n"+
"\n");
return 1; }
