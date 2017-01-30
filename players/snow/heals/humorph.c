/* This is a heal. Stats: 3 uses, Heal 50, Intox 6, Price 3000 */
inherit "/obj/clean.c";

#define TP this_player()
#include "std.h"
#include "/players/snow/closed/cyber/color.h"
#define TAB BOLD+"High Density Injector Tab (UM)"+OFF

int shots, price;
 
id(str) { return str == "ultramorph" || str == "UM" || str == "tab" 
                 || str == "htab"
               || str == "UltraMorph" || str == "injector tab"; }
 
reset(arg) {
        if (!arg) shots = 3;
        price = shots * 1000;
  set_no_clean(1);
}
 
long() {
        write(
"This is a high density tab of UltraMorph.\n"+
"A digital readout on the tab flashes: "+GREEN+shots+OFF+".\n"+
"You could read the tab to find out its usage.\n");
}
 
short() { return TAB+" *"+shots+"*"; }
 
query_value() { return (shots * 1000); }
 
init() {
  add_action("inject_um", "inject");
    add_action("read_tab","read");
}
 
inject_um(arg){
   if(environment() != this_player()) return;
  if(!arg) write("Inject what?\n");
  if(arg != "um" && arg != "UM") notify_fail("Usage: inject um\n");
    else {
if(!TP->drink_alcohol(6)) return 1;
    else{
  if(arg == "um" || arg == "UM") {
/*
  if(shots == 3) {
    write_file("/players/snow/log/heals",ctime(time())+" "+
          this_player()->query_real_name()+" used a UM tab.\n");
  }
*/
  shots--;
  TP->heal_self(50);
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
 
query_weight() { return 1; }
 
query_save_flag() { return 1; }

is_heal() { return "intox"; }
query_potence() { return 50; }
