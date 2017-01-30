/*  This is for Sin for assisting with finding bugs on the LD
driver. It can also be shared. */
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
  set_id("defibrillator");
    set_alias("defibrillator");
    set_weight(0);
}

short(){
	if(this_player())
	if(this_player() == environment())
	return "A Defibrillator";
}

        long(){
	write("This defibrillator can be used to ressurect your mud child\n"+
      "Command: revive <child name>\n");
if(this_player()->query_real_name() == "data" ||
   this_player()->query_real_name() == "sin" ||
   this_player()->query_real_name() == "genesis" ||
   this_player()->query_real_name() == "xerxes" ||
   this_player()->query_real_name() == "darknesss" ||
   this_player()->query_real_name() == "yen" ||
   this_player()->query_real_name() == "jacksparrow" ||
   this_player()->query_real_name() == "vodka"){
   write(
      "Owner Command: share_kid_rez <player name>\n");
   }
	return 1;
}
query_value(){ return 0; }
query_weight(){ return 0; }
get(){ return 1; }
drop(){ return 1; }

init(){
   add_action("share_kid_rez", "share_kid_rez");
   add_action("revive_kid", "revive");
   
}

revive_kid(str) {
string cap_name,kidgender,kidname,me,kidptoo,nom;
int inum,kidxp,kidhp,kid_age,kidpreg,where,flag,x;
int kidlevel,i;
string kidparenttwoo,kidnparents;
object kid;

if(!str) {
write ("We need a name.\n");
return 1;
}
nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare");
   x = 2;
 }
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare2","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare2");
   x = 2;
 }
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare3","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare3");
   x = 2;
 }
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare4","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare4");
   x = 2;
 }
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare5","checkiflisted",nom+" "+str);
 if (flag == 99) {
 restore_object("/players/boltar/sprooms/daycare5");
   x = 2;
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
 
 share_kid_rez(str){
object ob;
  if(this_player()->query_real_name() != "data" &&
     this_player()->query_real_name() != "yen" &&
	 this_player()->query_real_name() != "xerxes" &&
	 this_player()->query_real_name() != "jacksparrow" &&
	 this_player()->query_real_name() != "sin" &&
	 this_player()->query_real_name() != "noxius" &&
     this_player()->query_real_name() != "genesis") return 0;
  if(!str){ write("share it with who?\n"); return 1; }
  ob = present(str, environment(this_player()));
  if(!ob){ write("They are not here!\n"); return 1; }
  if(!living(ob) || ob->query_npc()){ 
    write("They can't have it.\n");
    return 1; 
    }
  if(present("tester", ob)){ 
     write("They already have one.\n");
     return 1;
     }
  move_object(clone_object("/players/data/closed/defibrillator.c"), ob);
  tell_object(ob, "You receive a defibrillator.\n");
  write("You give "+str+" a defibrillator.\n");
  return 1;
  }