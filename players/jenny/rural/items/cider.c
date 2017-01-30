/*
this is the 10 coins per heal point class of heal.
3 shots at 50 per shot, total heal value is 1500 coins.
 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string GG;
int shots, price;
id(str) { return str == "apple cider" || str == "cider" || str == "jug"; } 

reset(arg) {
   GG = GRN+"App"+RED+"le Ci"+GRN+"der"+NORM;

        if (!arg) shots = 3;
        price = shots * 500;
  set_no_clean();
}
 
long() {
        write(
     "A pint sized plastic jug of "+GG+".  The Reinheart family\n"+
     "makes this fresh cider from the 6 apple trees in their back yard.\n"+
     "Most folks round these parts think it's delicious.  Drink it and\n"+
     "see for yourself.\n"+
      "There are "+shots+" sips left.\n");
}
short() { return "A jug of "+GG; }
query_value() { return (shots * 500); }
 
init() {
    add_action("heal","drink");
    add_action("heal","sip");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "cider" || arg == "apple cider") {
  if(!TP->drink_soft(17+random(2))) {
    write("You've had too much to drink already.\n"); return 1; }
    else{
  if(arg == "cider" || arg == "apple cider") {
  shots--;
  TP->heal_self(50); 
        write(
"You put the jug up to your mouth and take a big sip of "+GG+".\n"+
"It taste like fresh apples, not too tart, not too sweet.  If autumn\n"+
"had a taste, this would be it.\n"+
"There are "+CYN+shots+NORM+" sips left."+NORM+"\n");
        say(
TPN+" takes a sip of "+GG+".\n");
}
command("mon",TP);


if(shots < 1){
  write("You finish the jug of "+GG+" and throw it away.\n");

     destruct(this_object()); TP->recalc_carry();
                }
return 1;
                } 

        }
}
get() {
    return 1;
}
 
query_weight() { return 1; }
 
query_save_flag() { return 1; }

is_heal() { return "soak"; }
query_potence() { return 50; }
