#include "/players/mythos/closed/guild/def.h"
int time, ti, num;
string dir;

id(str) { return str == "ward"; }
short(){write(HIB+"X] WARD [X\n"+NORM);}
long() {write(HIB+"A ward- protecting the room from the spirits and demons.\n"+NORM);}
reset(arg) {
   if(arg) return;
   ti = num = 0;
   call_out("check",10+time);
  call_out("warding",1);}

drop() {return 1;}
get() { return 0;}

set_time(n) { time = n;}
set_din(ni) { num = ni;}
set_dir(str) { dir = str;}
  
check() {
 if(time * 5 < ti) {
 if(ep) {
 tell_room(ep,BOLD+"The ward vanishes!\n"+NORM); }
 this_object()->set_light(2);
 destruct(this_object());
 return 1;}
 ti = ti + 1;
 call_out("check",10+time);
 return 1;
}

warding() {
int de;
object ob;
if( environment(this_object())) {
ob= all_inventory(environment(this_object()));
for(de=0; de<sizeof(ob); de++) {
  if(living(ob[de]) && (call_other(ob[de],"id","demon") || (call_other(ob[de],"id","spirit")) ||
    (call_other(ob[de],"id","daemon")) || (call_other(ob[de],"id","avatar")) ||
    (call_other(ob[de],"id","nightmare")) || (call_other(ob[de],"id","iezu")))) {
   if(!ob[de]->id("nasty")) { 
    if(ob[de]->query_level() < time + 5) {
    if(!num) {
    command(dir,ob[de]); 
    call_out("warding",3);
    return 1;}
    else {
    ob[de]->run_away(); 
    call_out("warding",3);
    return 1;}
    } 
    }
    } } }
call_out("warding",3);
return 1;}
    
query_shatter_proof() { return 1;}
