#define TP this_player()
#include "std.h"
int shots, price;
 
id(str) { return str == "ultrasober" || str == "US" || str == "tab" 
               || str == "UltraSober" || str == "injector tab"; }
 
reset(arg) {
        if (!arg) shots = 4;
        price = shots * 100;
}
 
long() {
        write(
"This is an injector tab of UltraSober.\n"+
"A digital readout on the tab flashes: "+shots+".\n"+
"You could read the tab to find out its usage.\n");
}
 
short() {
        return "An injector tab (US)";
}
 
query_value()
{
    return price;
}
 
init() {
  add_action("inject_us", "inject");
    add_action("read_tab","read");
}
 
inject_us(arg){
 
  if(!arg) write("Inject what?\n");
  if(arg != "US") return 0;  
    else {
if(!TP->drink_alcohol(-12)) return 1;
    else{
        if(arg == "US"){
/*
  if(shots == 4) {
    write_file("/players/snow/log/heals",ctime(time())+" "+
          this_player()->query_real_name()+" used a US tab.\n");
  }
*/
  shots--;
  TP->drink_alcohol(-7);
        write(
"The UltraSober buzzes into your system! Your head clears.\n"+
"The digital readout on the tab flashes: "+shots+".\n");
        say(capitalize(TP->query_name()) + " injects a tab (US).\n");
if(shots < 1){
        write(
"The tab crumbles to dust as you inject the last bit of UltraSober.\n");
        transfer(this_object(),"/players/snow/storage.c");
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
"This is a tab of UltraSober, a high-tech sobering solution.\n"+
"To use it, just 'inject US'\n"+
"The digital display shows the number of shots of US remaining.\n");
  return 1;
   }
}
 
get() {
    return 1;
}
 
query_weight() {
    return 1;
}

query_save_flag() { return 1; }
