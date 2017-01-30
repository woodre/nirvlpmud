/*
*actual value of the heal is 600
* total intox 30 / total heal 75 = .4   8 coins per heal point

 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string CSUN;
int shots, price;
id(str) { return str == "capri sun" || str == "juice" || str == "capri"; } 

reset(arg) {
CSUN = BOLD+RED+"Ca"+YEL+"pri S"+RED+"un"+NORM;
        if (!arg) shots = 3;
        price = shots * 30;
  set_no_clean();
}
 
long() {
        write(
     "This is fruit juice in a bag.  You just pop a straw in and drink it.\n"+
     "During the 80's, it was common for kids to have this in their\n"+
     "lunch box.  Maybe you could "+CYN+"drink juice."+NORM+"\n");

}
short() { return CSUN; }
query_value() { return (shots * 35); }
 
init() {
    add_action("heal","drink");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "juice" || arg == "capri sun") {
  if(!TP->drink_soft(10)) {
    write("You've had too much "+CSUN+" already.\n"); return 1; }
    else{
  if(arg == "juice" || arg == "capri sun") {
int amount;
if(TP->query_attrib("pie") > random(120)) {
amount = 30; }
else {
amount = 25; }
  shots--;
  TP->heal_self(amount); 
        write(
"You suck on the straw for a sip of "+CSUN+".\n"+

"There are "+RED+shots+NORM+" sips left."+NORM+"\n");
        say(
TPN+" takes a sip of "+CSUN+".\n");
if(amount == 30) {write(WHT+"Your guilt free conscience really allows you to enjoy the taste."+NORM+"\n");}
command("mon",TP);


if(shots < 1){
  write("You finish your "+CSUN+" and toss the bag aside.\n");

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
 
query_weight() { return 1; }
 
query_save_flag() { return 1; }

is_heal() { return "soak"; }
query_potence() { return 25; }
