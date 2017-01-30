inherit "/obj/clean.c";

#include "/players/jenny/define.h"

int shots, price;
 
id(str) { return str == "beer" || str == "bottle"; } 

 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 650;
  set_no_clean();
}
 
long() {
        write(
"A refreshing bottle of beer.  Al Bundy likes to have one of these\n"+
    "after a hard day at the shoe store.  Maybe you could "+YEL+"drink beer."+NORM+"\n");

}
 
short() { return GRN+"A bottle of beer "+YEL+"<"+shots+">"+NORM; }

query_value() { return (shots * 650); }
 
init() {
    add_action("beer","drink");
}
 
beer(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "beer") { return 0; }
    else {
  if(!TP->drink_alcohol(13)) {
    write("You are too drunk to drink more.\n"); return 1; }
    else{
  if(arg == "beer") {
  shots--;
  TP->heal_self(50);
        write(
""+GRN+"You take a big swig of beer."+NORM+" \n"+
""+YEL+"There are "+shots+" swigs left."+NORM+"\n");
command("mon",TP);
        say(GRN+""+TPN+" takes a swig of beer and "+WHT+"BURPS."+NORM+"\n");
if(shots < 1){
  write(""+RED+"You finish the beer and throw the bottle on the ground."+NORM+"\n");


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

is_heal() { return "intox"; }
query_potence() { return 50; }
