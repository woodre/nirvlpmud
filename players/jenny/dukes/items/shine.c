/*
*actual value of the heal is 880 actually, a little less since it is between tox levels

 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
int shots, price;
id(str) { return str == "moonshine" ||  str == "shine" || str == "jug" || str == "jug of moonshine"; } 

reset(arg) {
        if (!arg) shots = 3+random(3);
        price = shots * 70;
  set_no_clean();
}
 
long() {
        write(
"This is a jug of Hazzard County's best moonshine.  You can't\n"+
"buy anything this good in stores.  It was made from a nearby still.\n"+
"You can "+CYN+"drink moonshine."+NORM+"\n");

}
short() { return RED+"A jug of moonshine "+WHT+"<"+shots+">"+NORM; }
query_value() { return (shots * 70); }

init() {
    add_action("heal","drink");
    add_action("heal","swig");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "moonshine" && arg != "shine") {return 0; }
    else {
  if(!TP->drink_alcohol(6+random(2))) {
    write("Friend, you're drunker than a skunk in a barrow full of bourbon.\n"+
              "Wait a while.\n"); return 1; }
    else{
if(arg == "moonshine" || arg == "shine") {
int amount;
if(TP->query_attrib("pie") > random(41)) {

amount = 25; }
else {
amount = 20; }
  shots--;
  TP->heal_self(amount); 
        write(
""+CYN+"You take a swig of moonshine."+NORM+"\n"+

""+YEL+"There are "+shots+" swigs left."+NORM+"\n");
if(amount == 25) {write(WHT+"Your righteousness makes the moonshine taste better."+NORM+"\n"); }
command("mon",TP);
        say(CYN+""+TPN+" takes a swig of moonshine."+NORM+"\n");


if(shots < 1){
  write(""+CYN+"You drink the last of the moonshine and throw the jug away."+NORM+"\n");


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

is_heal() { return "intox"; }
query_potence() { return 20; }
