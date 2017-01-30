#define CAP 110
#define vac 0
int levels,timeleave,kidages,inout,count;
string genders,names,parents,nparents;
string parent_too;
int exps,hitpoints;
#include "/players/boltar/sprooms/restore/count.c"
short() {return "The daycare annex center"; }
long() {
    write("You have entered the day care center, where you can leave your\n"+
   "child and pick him up later. Commands are 'leave name' and 'pickup name'.\n"+
   "The daycare annex center appears to be well staffed and well maintained.\n"+
   "Through the window you can see many toys for the children to play\n"+
   "with in the next room.\nThe exit is south (daycare 3).\n");
   write(" "+
   "Type 'buy' to buy your kid some munchies, only 50 coins a bag!\n");
write("To set a second parent: the registered parent must type:\n"+
  " 'other <kid's name> <2nd parent's name>'\n");
   return 1;
 }
init() {
 add_action("pickup","pickup");
 add_action("set_age_man","setage");
add_action("set_gender","setgender");
 add_action("save_dc","savedc");
add_action("set_parent","setparent");
add_action("set_parent_blah","setparenttwo");
add_action("set_exp","setexp");
add_action("set_level","setlevel");
add_action("set_name","setname");
  add_action("list_kids","list");
add_action("set_parent_too", "other");
 add_action("leave","leave");
 add_action("south","south");
 add_action("buy_munchies","buy");
 }
reset(arg) {
  int i;
  if (arg) return;
 set_light(1);
  names = allocate(CAP+1);
  parent_too = allocate(CAP+1);
  levels = allocate(CAP+1);
  hitpoints = allocate(CAP+1);
  exps = allocate(CAP+1);
  timeleave = allocate(CAP+1);
  kidages = allocate(CAP+1);
   inout = allocate(CAP+1);
  parents = allocate(CAP+1);
  nparents=allocate(CAP+1);
   genders =allocate(CAP+1);
     restore_object("players/boltar/sprooms/restore/daycare4");
    if(!restore_object("players/boltar/sprooms/restore/daycare4"))
      save_object("players/boltar/sprooms/restore/daycare4");
   while (i<=CAP) {
     inout[i] = 1;
     i += 1;
    }
  }
pickup(str) {
string cap_name,kidgender,kidname,me;
int inum,kidxp,kidhp,kid_age;
int kidlevel,i;
string kidparenttwoo,kidnparents;
object kid;
if(!str) {
write ("We need a name.\n");
return 1;
}
  me=this_player()->query_real_name();
 cap_name=capitalize(me);
    while(i < CAP+1) {
    if(parents[i] == me && inout[i] == 1 && names[i] == str) {
        kidname = names[i];
        kidlevel = levels[i];
        kidhp = hitpoints[i];
        kidxp = exps[i];
        kidgender =genders[i];
        timeleave[i] = time();
        kid_age = kidages[i];
       kidnparents = nparents[i];
       kidparenttwoo = parent_too[i];
        inout[i] = 0;
         inum=i;
    }
    if(parent_too[i] == me && inout[i] == 1 && names[i] == str) {
        kidname = names[i];
        kidlevel = levels[i];
        kidhp = hitpoints[i];
        kidxp = exps[i];
        kidgender =genders[i];
        timeleave[i] = time();
        kid_age = kidages[i];
       kidnparents = nparents[i];
       kidparenttwoo = parents[i];
        inout[i] = 0;
         inum=i;
    }
    i += 1;
    }
   if(!kidname) {
  write("Your child is not here.\n");
   return 1;
    }
   if(count_out(me)) {
     inout[inum] = 1;
     return 1;
     }
     kid = clone_object("obj/kid");
    kid->set_gender(kidgender);
   if(kidlevel > 0) kid->set_level(kidlevel);
  if(kidlevel == 0) kid->set_level(1);
      kid->set_kidage(kid_age);
         kid->set_hp(kidhp);
      if(!kidnparents) kidnparents=parents[inum]+"#"+parent_too[inum];
      kid->set_nparents(kidnparents);
      kid->set_parenttwo(kidparenttwoo);
         kid->set_npu();
      if(kidhp == 0)
	call_other(kid, "set_hp", 30);
call_other(kid, "set_ac", 0);
	call_other(kid, "set_wc", 0);
	call_other(kid, "set_al", 0);
          kid->set_short(cap_name+"'s baby");
    kid->set_name(kidname);
    kid->set_daycare(this_object());
    kid->set_dc_num(inum);
    kid->set_parent(me);
	call_other(kid, "set_aggressive", 0);
        kid->set_ep(kidxp);
move_object(clone_object("obj/kid_soul"), kid);
       move_object(kid,this_player());
       write("Your child returns from the playroom and into your arms.\n");
       say(kid->query_name()+" runs out of the playroom to "+this_player()->query_name()+"\n");
        reset_count();
        save_object("players/boltar/sprooms/restore/daycare4");
   return 1;
 }
leave(str) {
int par_too_flag;
int yyu;
  int i,topcount;
  int okfl,tmpt;
 object kidob;
if(str=="baby") { write("You must name your child.\n"); return 1; }
     while(i<=CAP) {
     if(names[i] == str) okfl=1;
     i+=1;
     }
     if(call_other("players/boltar/sprooms/restore/daycare2", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/restore/daycare3", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/restore/daycare", "check_names", str)) yyu =1;
     if(yyu==1) {
     write("Your child is registered at the other daycare center.\n");
    return 1;
   }
     i=0;
      if (vac != 1) {
     purge_inactive();
    }
    set_times();
    check_replace();
  if(count > CAP && !okfl) {
    write("The day care center is full.\n");
    return 1;
   }
  if(!str) {
    write("Who do you wish to leave here?\n");
     return 1;
    }
  kidob=find_living(str);
  if(!kidob) { write("Cannot find any children named "+str+"\n"); return 1; }
  if(kidob->is_player()) kidob=present(str);
   if(!kidob) return 0;
   if(!present(kidob)) {
  write("please place your child in the room.\n");
  return 1;
 }
   if(!kidob->is_kid()) {
   write("We don't take that kind here.\n");
   return 1;
   }
  topcount = count;
   count += 1;
   while(i <= CAP) {
    if(parents[i] == this_player()->query_real_name() && names[i] ==str){
     count = i;
    }
    if(parent_too[i] == this_player()->query_real_name() && names[i] ==str){
    par_too_flag = 1;
     count = i;
    }
   i+=1;
   }
/*
if(names[count] && !par_too_flag) {
if(names[count] != kidob->query_real_name()) {
      write("This is not same child that you last brought here, if you have more than one\nchild one must be saved under each parents name.\n");
     reset_count();
     return 1;
}
  }
*/
if(check_names(str) && !par_too_flag){
      if(names[count] != check_names(str)) {
          write("That child has been saved under another parents name\nWrite Boltar to have the parent name changed.\n");
           reset_count();
      return 1;
      }
 }
  if(!par_too_flag)
 parents[count] = this_player()->query_real_name();
 names[count] = kidob->query_real_name();
 genders[count] = kidob->query_gender();
 levels[count] = kidob->query_level();
  hitpoints[count] = kidob->query_hp();
  nparents[count] = kidob->query_nparents();
  exps[count] = kidob ->query_exp();
   tmpt = kidages[count];
   if(timeleave[count])
   tmpt += time() - timeleave[count];
  kidages[count] = tmpt;
 inout[count] = 1;
/*
    if(count != topcount) 
      count = topcount;
*/
  reset_count();
 write("Your child enters the playroom.\n");
 say(kidob->query_name() + " enters the playroom.\n");
  destruct(kidob);
  save_object("players/boltar/sprooms/restore/daycare4");
  return 1;
  }
south() {
    call_other(this_player(), "move_player", "south#players/boltar/sprooms/restore/daycare3.c");
    return 1;
  }
north() {
    call_other(this_player(), "move_player", "north#players/boltar/sprooms/restore/daycare22.c");
    return 1;
  }
reset_count(){
  int k;
   while(k <= CAP) {
    if(!parents[k]) {
     count = k - 1;
     k = CAP + 1;
     }
    k += 1;
      }
   if(parents[CAP]) count = CAP + 1;
    return;
}
check_names(str) {
  int u;
     while (u <= CAP) {
      if (names[u] == str) {
      return names[u];
      }
     u += 1;
    }
   return 0;
}
set_parent_too(str){
  int u;
string cid,par;
  str = lower_case(str);
    if(sscanf(str, "%s %s", cid,par) != 2) return 0;
    if(!find_player(par)) {
      write(par+" must be logged on to set the second parent.\n");
      return 1;
     }
  while(u <= CAP) {
   if (parents[u] == this_player()->query_real_name() && cid == names[u])
     parent_too[u] = par;
   u+=1;
   }
  write("second parent set.\n");
        save_object("players/boltar/sprooms/restore/daycare4");
  return 1;
  }
save_dc(){
 if(this_player()->query_level() < 1000 && !this_player()->is_kid()) return 0;
        save_object("players/boltar/sprooms/restore/daycare4");
       return 1;
}
