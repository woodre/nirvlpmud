inherit "/obj/clean.c";

#include "/players/jenny/define.h"

int shots, price;
 
id(str) { return str == "weenie tots" || str == "tot" || str == "tots"; } 

 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 1100;
  set_no_clean();
}
 
long() {
        write(
"This is a bag of weenie tots.  Weenie tots are Al Bundy's favorite food.\n"+
"Technically, they are not food, but the Bundy's were never big on\n"+
"nutrition anyway.  Maybe you could "+YEL+"pop tot."+NORM+"\n");


}
 
short() { return RED+"A bag of weenie tots. "+YEL+"<"+shots+">"+NORM; }

query_value() { return (shots * 1100); }
 
init() {
    add_action("weenie","pop");
}
 
weenie(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "tot") { return 0; }
    else {
  if(!TP->eat_food(6)) {
    write("Your stomach cannot handle another one just yet.\n"); return 1; }
    else{
  if(arg == "tot") {
  shots--;
  TP->heal_self(50); 
        write(
""+RED+"You pop a weenie tot into your mouth."+NORM+"\n"+

""+YEL+"There are "+shots+" tots left."+NORM+"\n");
command("mon",TP);
        say(WHT+""+TPN+" eats a weenie tot and feels better."+NORM+"\n");


if(shots < 1){
  write(""+YEL+"You eat the last of the weenie tots and throw the bag away."+NORM+"\n");


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
