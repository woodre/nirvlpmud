inherit "obj/treasure";
#define CAP 110
#define vac 1 
string kidname, str;
int inum,levels,timeleave,kidages,whoout,count,preg;
int inout,kidlevel,kidhp,kidxp,kid_age, i;
string kidnparents,kidparenttwoo,kidpreg,genders,names,kidgender,cap_name,parents,nparents,ptoo,kidptoo,me;
string parent_too;
object player_ob, in;
int exps,hitpoints,dcnumberid;
#include "/players/boltar/sprooms/count.c"
query_inout() { return inout; }
reset(arg) {
  int i, inout;
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
        
  dcnumberid = 2;
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
 restore_object("players/boltar/sprooms/daycare2");
  while (i<CAP+1) {
    whoout[i] = 0;
    i += 1;
    }
}
init(){
   add_action("revive_kid", "revive");
   add_action("setter", "setter");
   
}

query_in() {
    player_ob = this_player();
	inout = 1;
    return 1;

}

revive_kid() {
    restore_object("players/boltar/sprooms/daycare2.c");
    if(this_object()->query_inout() == 1) {
	write("it says 1\n");
	return 1;
	}
	else {
	write("it didnt work\n");
	return 1;
	}
}

setter() {
  if(inout) {
    write("You deactivate the shields.\n");
    inout=0;
    return 1;
  }
  else {
    write("You activate the shields.\n");
    inout=1;
    return 1;
  }
}