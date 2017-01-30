#include "/players/mythos/closed/guild/def.h"
#define mend_min 10

id(str) {return str == "black_orb" || str == "orb"; }
int mending;
short() { return BOLD+"The Rent Orb"+NORM;}
long() { write("THIS ORB IS RENT!\n"+
               "The fae spill out causing the fabric of\n"+
               "infinity to shake and twist.\n"+
               "'mend' to heal the orb.\n"+
               "To become one with the orb and the Order\n"+
               "'reach orb'.\n"); }

drop() { return 0;}		
get() {return 0; }
query_save_flag() { return 1;}

init() {
  if(present(pact,tp)) {
  add_action("reach","reach"); }
  if(present(fear,tp)) {
  add_action("mend","mend"); }
  call_out("rendies",100);
}

reach(str) {
object orrb;
  if(!str) { return 1;}
  if(str == "orb") {
  if(present(fear,tp)) { write("You already have a guild object!\n"); return 1;}
  if((tp->query_guild_exp() != 0) ||  (tp->query_guild_file() != 0) ||
     (tp->query_guild_name() != 0) || (tp->query_guild_rank() != 0)) {
     write("Have a wiz look at you.\n");
  return 1;}
  if(read_file("/players/mythos/closed/guild/leave/"+tpn)) {
    write("contact Mythos.\n");
  return 1;}
  write("You reach into the orb and suddenly.....\nENERGY pours into you....!\n");
  if(restore_object(MEM+tpn)) { 
  move_object(clone_object("/players/mythos/closed/guild/hunger.c"),tp); 
  tp->save_me(); return 1;}
  write("You have been changed!  You may wish to extinguish any light source...\n");
  orrb = clone_object("/players/mythos/closed/guild/hunger.c"); 
  move_object(orrb,tp);
  pp->set_own(tpn);
  pp->set_dark_level(1); 
  pp->add_sacrifice(200);  
    pp->set_fae(1); 
  if(tp->query_gender() == "female") {
  if(0==random(10)) {
  pp->set_talent(1);
    pp->set_fae(3); }} 
  if(tp->query_gender() == "male") {
  if(0 == random(20)) {
  pp->set_talent(1);
    pp->set_fae(3); } } 
  pp->save_dark();
  write("Something whispers: "+
        "Welcome to the DARK....\n");
  tp->save_me();
  write("Talk to your sponsor or a guild commander for information...\n");
  /*
  write("\nSuddenly, you are transported someplace else...\n\n");
  move_object(tp,"/players/mythos/closed/guild/task/1/1.c");
  command("look",tp);
  write("\nA voice whispers:  See that woman.... feed upon her fear....\n\n");
  tp->set_wc(tp->query_attrib("str"));
  tp->set_ac(5);
  */
  command("dte enters the realm of Darkness....",tp);
  write_file("/players/mythos/closed/guild/ENTER",ctime(time())+" "+tpn+"\n");
  return 1;}
return 1;}

rendies() {
object ob;
ob = clone_object("/players/mythos/closed/guild/rendie.c");
switch(random(14)) {
  case 0 : move_object(ob,"/players/mythos/aroom/forest/forestr2.c"); break;
  case 1 : move_object(ob,"/players/mythos/aroom/forest/pool.c"); break;
  case 2 : move_object(ob,"/players/mythos/aroom/forest/pathway2.c"); break;
  case 3 : move_object(ob,"/players/mythos/closed/guild/assembly.c"); break;
  case 4 : move_object(ob,"/players/mythos/closed/guild/assembly.c"); break;
  case 5 : move_object(ob,"/players/mythos/aroom/path1.c"); break;
  case 6 : move_object(ob,"/players/mythos/mroom/narita.c"); break;
  case 7 : move_object(ob,"/players/mythos/aroom/forest/forest3.c"); break;
  case 8 : move_object(ob,"/players/mythos/aroom/path1.c"); break;
  case 9 : move_object(ob,"/players/mythos/enterance.c"); break;
  case 10 : move_object(ob,"/players/mythos/portal.c"); break;
  case 11 : move_object(ob,"/players/mythos/aroom/vil1.c"); break;
  case 12 : move_object(ob,"/players/mythos/aroom/path2.c"); break;
  case 13 : move_object(ob,"/players/mythos/closed/guild/seclib.c"); break;
}
tell_room(environment(this_object(),"A RENDIE IS BORN\n");
call_out("rendies",50+random(100));
return 1;}

mend(){
object ob;
int n;
if(!restore_object("/players/mythos/closed/guild/mending")) { mending = 0;}
mending = mending + 1;
if(mending >= mend_min) { 
ob = users();
 for(n=0;n<sizeof(ob);n++){
 if(present(fear,ob[n])) {
    tell_object(ob[n],BOLD+
    "\n  <<<<<<<<<    THE RENT HAS BEEN MENDED!    >>>>>>>>>\n\n"+NORM); } }
    rm("/players/mythos/closed/guild/check");
    rm("/players/mythos/closed/guild/mending.o");
    move_object(clone_object("/players/mythos/closed/guild/ob.c"),environment(this_object()));
    destruct(this_object()); return 1;}
save_object("/players/mythos/closed/guild/mending");
call_out("timing",450);
return 1;}

timing() {
rm("/players/mythos/closed/guild/mending.o"); 
tell_room(environment(this_object()),"The Rent grows....\n");
call_out("timing",450);
return 1;}

query_shatter_proof() { return 1;} 
