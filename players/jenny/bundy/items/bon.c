inherit "/obj/clean.c";

#include "/players/jenny/define.h"

int shots, price;
 
id(str) { return str == "box" || str == "bonbons" ||  str == "bon-bon"  ||  str == "bonbon" || str == "bon-bons"; } 

 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 1000;
  set_no_clean();
}
 
long() {
        write(
"A box of chocolate covered cherry bon-bons.  Peg Bundy loves these.\n"+
"Maybe you could "+RED+"eat bonbon."+NORM+"\n");


}
 
short() { return YEL+"A box of bon-bons. "+RED+"<"+shots+">"+NORM; }

query_value() { return (shots * 1000); }
 
init() {
    add_action("bonbon","eat");
}
 
bonbon(arg){
   if(environment() != this_player()) return;
if(!arg || arg != "bonbon") { return 0; }
    else {
  if(!TP->eat_food(7)) {
    write("Your stomach cannot handle another one just yet.\n"); return 1; }
    else{
  if(arg == "bonbon") {
  shots--;
  TP->heal_self(50); 
        write(
""+YEL+"You eat a delicious bon-bon"+NORM+" \n"+

""+RED+"There are "+shots+" bon-bons left."+NORM+"\n");
command("mon",TP);
        say(CYN+""+TPN+" eats a bon-bon and feels better."+NORM+"\n");


if(shots < 1){
  write(""+YEL+"You finish the bon-bons and toss the box aside."+NORM+" \n");


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
