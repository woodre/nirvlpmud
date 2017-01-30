/*
*actual value of the heal is 400

 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
int shots, price;
id(str) { return str == "goats milk" || str == "milk" || str == "some goats milk"; } 

reset(arg) {
        if (!arg) shots = 3+random(3);
        price = shots * 35;
  set_no_clean();
}
 
long() {
        write(
"This is a container of goat's milk.  You are not a true country boy\n"+
"or girl until you've tried some.\n"+
"You can "+MAG+"drink milk."+NORM+"\n");

}
short() { return WHT+"goats milk "+YEL+"<"+shots+">"+NORM; }
query_value() { return (shots * 35); }
 
init() {
    add_action("heal","drink");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "milk") { return 0; }
    else {
  if(!TP->drink_soft(3+random(2))) {
    write("You should wait a little while before drinking any more.\n"); return 1; }
    else{
  if(arg == "milk") {
int amount;
if(TP->query_attrib("pie") > random(40)) {

amount = 15; }
else {
amount = 10; }
  shots--;
  TP->heal_self(amount); 
        write(
""+WHT+"You take a sip of goat's milk."+NORM+"\n"+

""+YEL+"There are "+shots+" sips left."+NORM+"\n");
        say(WHT+""+TPN+" takes a sip of goat's milk."+NORM+"\n");
if(amount == 15) {write(CYN+"Your good nature makes the milk taste much better than usual."+NORM+"\n");}
command("mon",TP);


if(shots < 1){
  write(""+WHT+"You drink the last of the goat's milk and throw the container away."+NORM+"\n");


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
query_potence() { return 10; }
