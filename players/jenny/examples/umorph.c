/* Stats: 5 uses, Totalheal: 150, Totaltox: 42(.28), Price 1500 */
/* Totaltox = 40 + random(2)*5 = slightly over 42 */

#define TP this_player()
#include "std.h"
#include <ansi.h>
inherit "/obj/clean.c";

int shots, price;
 
id(str) { return str == "ultramorph" || str == "UM" || str == "tab" 
               || str == "UltraMorph" || str == "injector tab"; }
 
reset(arg) {
        if (!arg) shots = 5;
        price = shots * 300;
  set_no_clean();
}
 
long() {
        write(
"This is an injector tab of UltraMorph.\n"+
"A digital readout on the tab flashes: "+GREEN+shots+OFF+".\n"+
"You could read the tab to find out its usage.\n");
}
 
short() { return BOLD+"Injector Tab (UM)"+OFF+" *"+shots+"*"; }
 
query_value() { return (shots * 300); }
 
init() {
    add_action("inject_um"); add_verb("inject");
    add_action("read_tab","read");
}
 
inject_um(arg){
   if(environment() != this_player()) return;
  if(!arg || (arg != "um" && arg != "UM") ) { notify_fail("Inject what?\n"); return 0: }
    else {
  if(!TP->drink_alcohol(8+random(2))) {
    write("You are too intoxicated to inject more.\n"); return 1; }
    else{
  if(arg == "um" || arg == "UM") {
  shots--;
  TP->heal_self(30);
        write(
"The UltraMorph rips through your system! Pain disappears.\n"+
"The digital readout on the tab flashes: "+GREEN+shots+OFF+".\n");
  write(BOLD+" ~HP: "+TP->query_hp()+"  ~SP: "+TP->query_sp()+OFF+"\n");
        say(capitalize(TP->query_name()) + " injects a tab (UM).\n");
if(shots < 1){
  write(BOLD+"Your UltraMorph tab crumbles as you inject the last bit."+
        OFF+"\n");
     destruct(this_object()); TP->recalc_carry();
                }
return 1;
                }
        }
}
}
 
read_tab(arg) {
  if(arg == "tab") {
    write(
"The tab reads: \n"+
"This is a tab of UltraMorph, an incredible painkiller.\n"+
"To use it, just 'inject UM'\n"+
"The digital display shows the number of shots of UM remaining.\n");
  return 1;
   }
}
 
get() {
    return 1;
}
 
query_weight() { return 2; }
 
query_save_flag() { return 1; }

is_heal() { return "intox"; }
query_potence() { return 30; }
