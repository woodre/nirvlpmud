/*
*actual value of the heal is 800
* * total intox 40 / total heal 100 = .40.   cost per heal 8 coins

 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string JBEANS;
int shots, price;
id(str) { return str == "jar" || str == "beans" || str == "jellybeans"; } 

reset(arg) {
JBEANS = BOLD+YEL+"je"+BLK+"ll"+WHT+"yb"+BLU+"ea"+GRN+"ns"+NORM;
        if (!arg) shots = 4;
        price = shots * 30;
  set_no_clean();
}
 
long() {
        write(
"This is a glass jar filled with "+JBEANS+".  There is an assortment\n"+
"of different flavors.  This was a favorite treat of President Reagan.\n"+
"you could "+RED+"eat "+NORM+"some "+RED+"beans"+NORM+".\n");

}
short() { return "A jar of "+JBEANS; }
query_value() { return (shots * 35); }
 
init() {
    add_action("heal","eat");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "beans" || arg == "jellybeans") {
  if(!TP->eat_food(10)) {
    write("You don't have room for any more "+JBEANS+".\n"); return 1; }
    else{
  if(arg == "beans" || arg == "jellybeans") {
int amount;
if(TP->query_attrib("pie") > random(120)) {
amount = 30; }
else {
amount = 25; }
  shots--;
  TP->heal_self(amount); 
        write(
"You eat a handful of "+JBEANS+".\n"+

"There are "+RED+shots+NORM+" handfuls left."+NORM+"\n");
        say(
TPN+" eats a handful of "+JBEANS+".\n");
if(amount == 30) {write(WHT+"Your guilt free conscience really allows you to enjoy the taste."+NORM+"\n");}
command("mon",TP);


if(shots < 1){
  write("You finish the "+JBEANS+" and toss the jar aside.\n");

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

is_heal() { return "food"; }
query_potence() { return 25; }
