/*
*actual value of the heal is 600
*heals 5 more if piety > random(120)
* total intox 30 / total heal 75 = .4   8 coins per heal point
 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string COOLER;
int shots, price;
id(str) { return str == "bartles & jaymes" || str == "cooler" || str == "bottle" || str == "wine cooler"; } 

reset(arg) {
COOLER = BOLD+WHT+"Bartles "+NORM+"& "+BOLD+MAG+"Jaymes"+NORM;
        if (!arg) shots = 3;
        price = shots * 30;
  set_no_clean();
}
 
long() {
        write(
     "This is a bottle of "+COOLER+" wine cooler.  They\n"+
     "come in an assortment of flavors.  These were popular drinks\n"+
     "during the 80's.  You could "+CYN+"drink cooler."+NORM+"\n");
}
short() { return COOLER+" wine cooler"; }
query_value() { return (shots * 35); }
 
init() {
    add_action("heal","drink");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "cooler" || arg == "bartles & jaymes") {
  if(!TP->drink_alcohol(10)) {
    write("You're too drunk to have any more.\n"); return 1; }
    else{
  if(arg == "cooler" || arg == "bartles & jaymes") {
int amount;
if(TP->query_attrib("pie") > random(120)) {
amount = 30; }
else {
amount = 25; }
  shots--;
  TP->heal_self(amount); 
        write(
"You have taken a sip of "+COOLER+" wine cooler.\n"+
"Thank you for your support.\n"+
"There are "+MAG+shots+NORM+" sips left."+NORM+"\n");
        say(
TPN+" takes a sip of "+COOLER+" wine cooler.\n");
if(amount == 30) {write(WHT+"Your guilt free conscience really allows you to enjoy the taste."+NORM+"\n");}
command("mon",TP);

if(shots < 1){
  write("You finish your "+COOLER+" and toss the bottle aside.\n");

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
