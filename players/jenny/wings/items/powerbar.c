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
id(str) { return str == "power bar" || str == "bar"; } 

reset(arg) {
     x = random(5);
   switch(x) {
      case 0: GG = GRN+"Apple "+RED+"Cinnamon"+NORM; break;
      case 1: GG = YEL+"Banana"+NORM; break;
      case 2: GG = YEL+"Peanut Butter"+NORM; break;
      case 3: GG = BLU+"Wild "+RED+"Berry"+NORM; break;
      case 4: GG = GRN+"Oatmeal Raisin"+NORM; break;
}

        if (!arg) shots = 3;
        price = shots * 50;
  set_no_clean();
}
 
long() {
        write(
     "This is a "+GG+" flavored Power Bar.  It is a nutritious\n"+
     "candy bar that is filled with carbohydrates.  Eating it will\n"+
     "give you more energy.\n"+
      "There are "+shots+" bites left.\n");
}
short() { return "A "+GG+" flavored Power Bar"; }
query_value() { return (shots * 50); }
 
init() {
    add_action("heal","eat");
    add_action("heal","bite");
}
 
heal(arg){
   if(environment() != this_player()) return;
if(!arg) { return 0; }
if(arg == "bar" || arg == "power bar") {
  if(!TP->eat_food(10)) {
    write("You've had too much to eat already.\n"); return 1; }
    else{
if(arg == "bar" || arg == "power bar") {
int amount;
if(random(TP->query_hp()) < STASTAT) {
amount = 60; }
else {
amount = 50; }
  shots--;
  TP->heal_self(amount); 
        write(
"You take a large bite of your "+GG+" flavored Power Bar.\n"+
"There are "+CYN+shots+NORM+" bites left."+NORM+"\n");
        say(
TPN+" takes a bite of "+POS+" "+GG+" flavored Power Bar.\n");
if(amount == 60) {write("You feel an extra burst of energy right away.\n");
}
command("mon",TP);


if(shots < 1){
  write("You toss the empty wrapper aside.\n");

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

is_heal() { return "stuff"; }
query_potence() { return 50; }
