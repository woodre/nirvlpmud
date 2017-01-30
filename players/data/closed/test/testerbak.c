inherit "obj/treasure";
#define CAP 110
#define vac 1
#define ENV(x) environment(x)

#define CAPN(x) capitalize(x)
int levels,timeleave,kidages,inout,whoout,count,preg;
string genders,names,parents,nparents,ptoo;
string parent_too;
int exps,hitpoints,dcnumberid;
#include "/players/boltar/sprooms/count.c"

reset(arg) {

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
        
    }

init(){

   add_action("kid_daycare_check", "revive");
   
}

revive_kid(str) {
string cap_name,kidgender,kidname,me,kidptoo;
int inum,kidxp,kidhp,kid_age,kidpreg,where;
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
     if(parents[i] == me && inout[i] < 1 && names[i] == str) {
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

         inum=i;
    }
    if(parent_too[i] == me && inout[i] < 1 && names[i] == str) {
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

         inum=i;
    }
    i += 1;
    }
   if(!kidname) {
  write("Your child is in daycare.\n");
   return 1;
    }
	  if(find_living(kidname)) {
	  where = call_other(ENV(find_living(kidname)),"short");
    write(CAPN(str)+" is alive!\n"+
	"Location: "+where+"\n");
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
       if(!kidnparents) kidnparents=parents[inum]+"#"+parent_too[inum];
       kid->set_nparents(kidnparents);
       kid->set_parenttwo(kidparenttwoo);
         kid->set_hp(kidhp);
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
       write("You bend to the fallen corpse of "+CAPN(str)+" and revive them.\n");
       say(kid->query_name()+" is revived by "+this_player()->query_name()+"'s efforts!\n");

   return 1;
 }
 
 kid_daycare_check(str) {
 int flag,x;
 string nom;
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare_LD");
   call_other("/players/data/closed/test/tester.c","revive_kid",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare2","checkiflisted",nom+" "+str);
 if (flag == 99) { 
   restore_object("/players/boltar/sprooms/daycare2_LD");
   call_other("/players/data/closed/test/tester.c","revive_kid",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare3","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare3_LD");
   call_other("/players/data/closed/test/tester.c","revive_kid",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare4","checkiflisted",nom+" "+str);
 if (flag == 99) { 
 restore_object("/players/boltar/sprooms/daycare4_LD");
  call_other("/players/data/closed/test/tester.c","revive_kid",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare5","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare5_LD");
   call_other("/players/data/closed/test/tester.c","revive_kid",str);
   x = 2;
 }
 if(!x) write("Cannot find your child.\n");
 return 1;
}