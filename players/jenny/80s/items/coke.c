/*
*actual value of the heal is 800

* total intox 40 / total heal 100 = .40.   cost per heal 8 coins
 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string COKE;
int shots, price;
id(str) { return str == "coke" || str == "new coke" || str == "the new coke" || str == "bottle"; } 

reset(arg) {
COKE = BOLD+RED+"NE"+WHT+"W CO"+RED+"KE"+NORM;
        if (!arg) shots = 4;
        price = shots * 30;
  set_no_clean();
}
 
long() {
        write(
     "This is a half liter glass bottle of the "+COKE+".  During the mid\n"+
     "1980's, Coca-Cola responded to their declining sales by changing\n"+
     "their formula.  This worked out poorly, because few people liked\n"+
      "the "+COKE+" and they quickly switched back to the old formula,\n"+
      "which they renamed Coca-Cola Classic.  You could "+RED+"drink coke"+NORM+"\n"+
     "to sample the most infamous marketing blunder of the 1980's.\n");    
}
short() { return "A bottle of the "+COKE; }
query_value() { return (shots * 35); }
 
init() {
    add_action("heal","drink");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "coke" || arg == "new coke") {
  if(!TP->drink_soft(10)) {
    write("You've had as much of the "+COKE+" as you can stomach for now.\n"); return 1; }
    else{
  if(arg == "coke" || arg == "new coke") {
int amount;
if(TP->query_attrib("wil") > random(120)) {
amount = 30; }
else {
amount = 25; }
  shots--;
  TP->heal_self(amount); 
        write(
"You take the cold glass bottle into your hand, then raise it up and run\n"+
"it over your sweat soaked forehead.  Boy, does that ever feel good.  You\n"+
"look at the label, which reads the "+COKE+".  You think 'oh well.  How\n"+
"bad can it be?  Down the hatch.'\n"+

"There are "+RED+shots+NORM+" sips left."+NORM+"\n");
        say(
TPN+" takes a sip of "+COKE+".\n");
if(amount == 30) {write(WHT+"It takes incredible willpower on your part, but you actually\n"+
"manage to enjoy that sip."+NORM+"\n");}
command("mon",TP);


if(shots < 1){
  write("You finish the bottle of the "+COKE+" and throw it away.\n");

     destruct(this_object()); TP->recalc_carry();
                }
return 1;
                }
        }
}
}
get() {
    return 1;
}
 
query_weight() { return 2; }
 
query_save_flag() { return 1; }

is_heal() { return "soak"; }
query_potence() { return 25; }
