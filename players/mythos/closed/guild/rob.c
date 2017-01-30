#include "/players/mythos/closed/guild/def.h"
int time;

id(str) { return str == "dark_cloak"; }
drop() {return 1;}
get() { return 0;}

reset(arg) {
  if(arg) return;
  call_out("zcheck",3);
} 
  
zcheck() {
if(ep) {
  if(environment(ep)) {
 if(!present("zzzb",environment(ep))) {
 destruct(this_object()); return 1;} }}
 call_out("zcheck",3);
 return 1;
}
