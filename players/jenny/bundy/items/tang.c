inherit "/obj/clean.c";

#include "/players/jenny/define.h"

int shots, price;
 
id(str) { return str == "tang" || str == "glass"; } 

 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 550;
  set_no_clean();
}
 
long() {
        write(
"A nice refreshing glass of tang.  This is one of the favorite beverages \n"+
    "of the Bundy family.  Maybe you could "+MAG+"drink tang."+NORM+"\n");

}
 
short() { return MAG+"A glass of tang "+CYN+"<"+shots+">"+NORM; }

query_value() { return (shots * 550); }
 
init() {
    add_action("tang","drink");
}
 
tang(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "tang") { return 0; }
    else {
  if(!TP->drink_soft(15+random(2))) {
    write("You couldn't possibly drink any more.\n"); return 1; }
    else{
  if(arg == "tang") {
  shots--;
  TP->heal_self(50); 
        write(
""+MAG+"You take a big sip of tang."+NORM+"\n"+

""+YEL+"There are "+shots+" sips left."+NORM+"\n");
command("mon",TP);
        say(MAG+""+TPN+" takes a big sip of tang and smiles at you."+NORM+"\n");


if(shots < 1){
  write(""+MAG+"You finish the tang and throw the glass on the ground."+NORM+"\n");


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

