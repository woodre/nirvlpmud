inherit "/obj/clean.c";

#include "/players/jenny/define.h"

int shots, price;
 
id(str) { return str == "toaster" || str == "toast"; } 

 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 550;
  set_no_clean();
}
 
long() {
        write(
"This is a toaster that contains some, um nutritious' toaster shak'ins.  \n"+
    "Only a starving member of the Bundy family would consider eating\n"+
     "this.  Maybe you could "+CYN+"shake toaster."+NORM+"\n");

}
 
short() { return WHT+"A toaster "+BLU+"<"+shots+">"+NORM; }

query_value() { return (shots * 550); }
 
init() {
    add_action("toast","shake");
}
 
toast(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "toaster") { return 0; }
    else {
  if(!TP->eat_food(15+random(2))) {
    write("You are too full to eat any more.\n"); return 1; }
    else{
  if(arg == "toaster") {
  shots--;
  TP->heal_self(50); 
        write(
""+BLU+"You lift the toaster above your head and shake it,\n"+
     "savoring the tasty 'toaster shakins'."+NORM+"\n"+

""+YEL+"There are "+shots+" shakes of the toaster left."+NORM+"\n");
command("mon",TP);
        say(RED+""+TPN+" lifts a toaster above "+POS+" head and shakes it.\n"+
 "Savoring the tasty 'toaster shakins'"+NORM+"\n");


if(shots < 1){
  write(""+YEL+"You eat the last of the toaster shak'ins and throw the toaster away."+NORM+"\n");



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
