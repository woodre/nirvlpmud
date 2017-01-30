#define CAP 110
#define vac 1
int levels,timeleave,kidages,inout,whoout,count,preg;
string genders,names,parents,nparents,ptoo;
string parent_too;
int exps,hitpoints,dcnumberid;
#include "/players/boltar/sprooms/count.c"
short() {return "The daycare annex center"; }

id(str) {
    return str=="window" || str == "unbreakable window" || str=="box" ||
           str=="command box" || str == "instructions";
}
long(str) {
   if(str=="box" || str=="command box" || str == "instructions")
     write("The stylish modern looking command box has a variety of \n"+
     "options on it. The instructions list the following:\n"+
     "leave <childname>         Leave your child in the daycare center\n"+
     "pickup <childname>        Pickup your child from the daycare center\n"+
     "other <kidname> <parent>  Set the name of the second parent\n"+
     "list                      Lists your kids\n"+
     "check                     Check on your kids.\n"+
     "buy                       Purchase fortified munchies for the child\n"+
     "                          Only 50 coins a bag!\n");
   if(str=="window" || str == "unbreakable window")
     write("Through the window you see the children at play and the staff\n"+
     "caring for them well.\n");
   if(str) return 0;
   write("You walk through the brick entry way into the forth section\n"+
     "of the daycare center. To the south is the exit to the third\n"+
     "section of the daycare. The daycare center is well appointed and\n"+
     "automated so that the care givers and the children are protected\n"+
     "from evil creatures and men who are known to enter the village\n"+
     "from time to time. There is a large unbreakable window exposing\n"+
     "the inner facility to view. There is small command box with \n"+
     "instructions.\n");
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
add_action("set_dna","setdna");
add_action("set_level","setlevel");
add_action("set_name","setname");
  add_action("list_kids","list");
    add_action("check_on","check");
add_action("set_parent_too", "other");
 add_action("leave","leave");
 add_action("south","south");
 add_action("north","north");
 add_action("buy_munchies","buy");
 }
reset(arg) {
  int i;
  if (arg) return;
 set_light(1);
 dcnumberid = 5;
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
  nparents=allocate(CAP+1);
   genders =allocate(CAP+1);
   ptoo = allocate(CAP+1);
   preg = allocate(CAP+1);
     restore_object("players/boltar/sprooms/daycare5");
    if(!restore_object("players/boltar/sprooms/daycare5"))
      save_object("players/boltar/sprooms/daycare5");
   while (i<=CAP) {
     inout[i] = 1;
     whoout[i] = 0;
     i += 1;
    }
  }
pickup(str) {
string cap_name,kidgender,kidname,me,kidptoo;
int inum,kidxp,kidhp,kid_age,kidpreg;
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
       if(preg[i]) {
          kidpreg = preg[i];
          kidptoo = ptoo[i];
       }
        inout[i] = 0;
        whoout[i] = 1;
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
       if(preg[i]) {
          kidpreg = preg[i];
          kidptoo = ptoo[i];
       }
        inout[i] = 0;
        whoout[i] = 2;
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
    if(kidpreg) {
      kid->set_kidpreg(kidpreg);
      kid->set_kidptoo(kidptoo);
    }
	call_other(kid, "set_aggressive", 0);
        kid->set_ep(kidxp);
move_object(clone_object("obj/kid_soul"), kid);
       move_object(kid,this_player());
       write("Your child returns from the playroom and into your arms.\n");
       say(kid->query_name()+" runs out of the playroom to "+this_player()->query_name()+"\n");
        reset_count();
        save_object("players/boltar/sprooms/daycare5");
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
     if(call_other("players/boltar/sprooms/daycare2", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/daycare3", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/daycare", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/daycare4", "check_names", str)) yyu =1;
     if(call_other("players/boltar/sprooms/daycare6", "check_names", str)) yyu =1;
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
    ptoo[count] = kidob->query_pregtoo();
  preg[count] = kidob->query_pregnancy();
  exps[count] = kidob ->query_exp();
   tmpt = kidages[count];
   if(timeleave[count])
   tmpt += time() - timeleave[count];
  kidages[count] = tmpt;
    if(preg[count]) {
    kidages[count] = kidob->query_kidage();
  }
 inout[count] = 1;
/*
    if(count != topcount) 
      count = topcount;
*/
  reset_count();
 write("Your child enters the playroom.\n");
 say(kidob->query_name() + " enters the playroom.\n");
  destruct(kidob);
  save_object("players/boltar/sprooms/daycare5");
  return 1;
  }
south() {
    call_other(this_player(), "move_player", "south#players/boltar/sprooms/daycare4.c");
    return 1;
  }
north() {
	call_other(this_player(), "move_player", "north#players/boltar/sprooms/daycare6.c");
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
        save_object("players/boltar/sprooms/daycare5");
  return 1;
  }
save_dc(){
/*
 if(this_player()->query_level() < 1000 && !this_player()->is_kid()) return 0;
*/
        save_object("players/boltar/sprooms/daycare5");
       return 1;
}
