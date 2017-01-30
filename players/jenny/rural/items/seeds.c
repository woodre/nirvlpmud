/*
this is the 10 coins per heal point class of heal.
3 shots at 50 per shot, total heal value is 1500 coins.
 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string GG;
int shots, price;
id(str) { return str == "pumpkin seeds" || str == "seeds" || str == "baggie"; } 

reset(arg) {
   GG = RED+"Pu"+YEL+"mp"+RED+"ki"+YEL+"n s"+RED+"ee"+YEL+"ds"+NORM;

        if (!arg) shots = 3;
        price = shots * 500;
  set_no_clean();
}
 
long() {
        write(
     "A small ziplock baggie full of "+GG+".  Mrs. Reinheart took\n"+
     "them out of the pumpkins that grow in the field behind her house.\n"+
     "They have been salted and baked to a crispy golden brown.  Eat\n"+
     "them and give them a try.\n"+
      "There are "+shots+" handfulls of seeds left.\n");
}
short() { return "A baggie full of "+GG; }
query_value() { return (shots * 500); }
 
init() {
    add_action("heal","eat");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "seeds" || arg == "pumpkin seeds") {
  if(!TP->eat_food(17+random(2))) {
    write("You couldn't eat another bite.\n"); return 1; }
    else{
  if(arg == "seeds" || arg == "pumpkin seeds") {
  shots--;
  TP->heal_self(50); 
        write(
"You grab a small handfull of "+GG+" out of the baggie and stuff\n"+
"them into your mouth.  They are crispy and have a pleasant earthy\n"+
"flavor.  You could snack on these things all day.\n"+
"There are "+CYN+shots+NORM+" handfulls of "+GG+" left.\n");
        say(
TPN+" eats a handfull of "+GG+".\n");
}
command("mon",TP);


if(shots < 1){
  write("You finish the bag of "+GG+" and throw it away.\n");

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

is_heal() { return "stuff"; }
query_potence() { return 50; }
