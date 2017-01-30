inherit "obj/treasure";
#define CAP 110
#define vac 1 
int levels,timeleave,kidages,inout,whoout,count,preg;
string genders,names,parents,nparents,ptoo;
string parent_too;
int exps,hitpoints,dcnumberid;
#include "/players/boltar/sprooms/count.c"
reset(arg) {
  int i;
  if(arg) return;
  set_id("tester");
    set_alias("tester");
    set_weight(0);
    set_value(0);

set_short("tester");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
  dcnumberid = 1;
  names = allocate(CAP+1);
  parent_too = allocate(CAP+1);
  levels = allocate(CAP+1);
  hitpoints = allocate(CAP+1);
  exps = allocate(CAP+1);
  timeleave = allocate(CAP+1);
  kidages = allocate(CAP+1);
  inout = allocate(CAP+1);
  whoout = allocate(CAP+1);
  parents = allocate(CAP+1);
  genders =allocate(CAP+1);
  nparents=allocate(CAP+1);
     ptoo = allocate(CAP+1);
   preg = allocate(CAP+1);
  while (i<CAP+1) {
    inout[i] = 1;
    whoout[i] = 0;
    i += 1;
    }
}
init(){
   add_action("revive_kid", "revive");
   add_action("list_kido","listme");
   restore_object("/players/boltar/sprooms/daycare2.c");
   
}

list_kido() {
object ob;
ob="/players/boltar/sprooms/daycare2";
write(this_player()->ob()->query_info()):
return 1;
}