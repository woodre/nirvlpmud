/*
*actual value of the heal is 2400

* total intox 60 / total heal 150 = .20.   cost per heal 16 coins
  heals a little extra sometimes, chance depends on how low your hp are
  not sold - must fight for them.
 */

inherit "/obj/clean.c";
#include "/players/jenny/define.h"
string GG;
int x;
int shots, price;
id(str) { return str == "gatorade"; } 

reset(arg) {
     x = random(6);
   switch(x) {
      case 0: GG = YEL+"Lemon "+GRN+"Lime"+NORM; break;
      case 1: GG = YEL+"O"+RED+"r"+YEL+"a"+RED+"n"+YEL+"g"+RED+"e"+NORM; break;
      case 2: GG = RED+"Fruit Punch"+NORM; break;
      case 3: GG = GRN+"Citrus "+YEL+"Cooler"+NORM; break;
      case 4: GG = RED+"Strawberry "+GRN+"Kiwi"+NORM; break;
      case 5: GG = HIC+"Cool "+HIB+"Blue "+HIR+"Raspberry"+NORM; break;
}

        if (!arg) shots = 3;
        price = shots * 50;
  set_no_clean();
}
 
long() {
        write(
     "This is a glass bottle of "+GG+" flavored Gatorade.  Drinking\n"+
     "it helps revitalize the body by providing a quick infusion of\n"+
     "carbohydrates.\n"+
      "There are "+shots+" sips left.\n");
}
short() { return GG+" flavored Gatorade"; }
query_value() { return (shots * 50); }
 
init() {
    add_action("heal","drink");
    add_action("heal","sip");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "gatorade") {
  if(!TP->drink_soft(10)) {
    write("You've had too much to drink already.\n"); return 1; }
    else{
  if(arg == "gatorade") {
int amount;
if(random(TP->query_hp()) < STASTAT) {
amount = 60; }
else {
amount = 50; }
  shots--;
  TP->heal_self(amount); 
        write(
"You put the bottle up to your mouth and take a big swig of "+GG+"\n"+
"flavored Gatorade.  That helps quench your deep down body thirst.\n"+

"There are "+CYN+shots+NORM+" sips left."+NORM+"\n");
        say(
TPN+" takes a sip of "+GG+" flavored Gatorade.\n");
if(amount == 60) {write("You feel an extra burst of energy right away.\n");
}
command("mon",TP);


if(shots < 1){
  write("You finish the bottle of Gatorade and throw it away.\n");

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
query_potence() { return 50; }
