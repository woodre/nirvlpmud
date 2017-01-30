/*
heal = (random(max_hp() - hp()) + stamina)
i'm not going to assign a "heal value" to it.  it is what it is, besides
you fight for it, so it's a moot point.
it can be good or not so good, if you arn't that hurt, it won't heal that much
because the randomness works against you
 */

inherit "/obj/clean.c";
inherit "/obj/treasure.c";
#include "/players/jenny/define.h"
int shots, price;
id(str) { return str == "pain-killers" || str == "bottle" || str == "pills"; } 

reset(arg) {
        if (!arg) shots = 3;
        price = shots * 100;
        set_short("A bottle of pain-killers");
  set_no_clean();
}
 
long() {
        write(
     "This is a small white plastic bottle filled with pain-killing\n"+
     "pills.  Hockey players sometimes use these to help them play\n"+
     "through injuries.  You could "+CYN+"pop pill"+NORM+".\n"+
     "There are "+CYN+shots+NORM+" pills left.\n");
}
query_value() { return (shots * 100); }
 
init() {
    add_action("heal","pop");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "pill" || arg == "pain-killer") {

int amount;
amount = (random(TP->query_mhp() - TP->query_hp()) + STASTAT);
  shots--;
  TP->heal_self(amount); 
        write(
"You open the bottle and pop a pain-killer into your mouth.\n"+
"You are feeling a little better already.\n"+
"There are "+CYN+shots+NORM+" pills left.\n");
        say(
TPN+" opens a bottle and pops a pill into "+POS+" mouth.\n");
command("mon",TP);

if(shots < 1){
  write("You finish off the pain-killers and toss the bottle aside.\n");

     destruct(this_object()); TP->recalc_carry();

                }
return 1;
                }
        }
get() {
    return 1;
}
 
query_charges(){ return shots; }
query_weight() { return 1; }
 
query_save_flag() { return 1; }

is_heal() { return 1; }
