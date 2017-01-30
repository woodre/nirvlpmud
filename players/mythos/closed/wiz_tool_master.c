#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define logg "WIZTOOL",ctime(time())+tpn

id(str) { return str == "wizmaster"; }


/* These two commands added by Pain 1/22/1997 */

wizard_rules() {
command("more /players/pain/RULES/wiz_rules.txt",this_player());
return 1;
}

wizard_log(str) {
string reason, action;

if(!str) {
		command("tail /log/"+this_player()->query_real_name()+".workreport",this_player());
        return 1;
}
if(sscanf(str,"%s#%s",action,reason) != 2) {
        write("Usage: wlog action#reason\ni.e. wlog heal me#I was hurt.\n");
        return 1;
}
else {
log_file(this_player()->query_real_name()+".workreport",ctime()+"--Action: "+action+" Reason: "+reason+"\n");
write("Wrote: Action: "+action+" Reason: "+reason+", to /log/"+this_player()->query_real_name()+".workreport.\n");
return 1;
}
}


/* End Pain Additions */


add_xp(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->add_exp(what);
  write("You have added "+what+" xp to "+who+"\n");
  log_file(logg + " added "+what+" xp to "+who+"\n");
return 1; }

set_stat(str) {
string who,what;
int amount;
  if(!str) return 0;
  if(sscanf(str,"%s %s %d",who,what,amount) != 3) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_attrib(what,amount);
  write("You have set "+who+"'s "+what+" to "+amount+"\n");
  log_file(logg + "set "+who+"'s "+what+" to "+amount+"\n");
return 1; }

set_home(str) {
string who;
string what;
  if(!str) return 0;
  if(sscanf(str,"%s %s",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  if(find_player(who)->query_level() > tl) {
    write("You may not set the home of someone above you.\n"); 
  return 1; }
  find_player(who)->set_home(what);
  write("You have set "+who+"'s home to "+what+"\n");
  log_file(logg + " set "+who+"'s home to "+what+"\n");
return 1; }

set_level(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_level(what);
  write("You have set "+who+"'s level to "+what+"\n");
  log_file(logg + " set "+who+"'s level to "+what+"\n");
return 1; }


set_ex(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_extra_level(what);
  write("You have set "+who+"'s extralevel to "+what+"\n");
  log_file(logg + " set "+who+"'s extralevel to "+what+"\n");
return 1; }

peace() {
object att,ob;
int h;
ob = all_inventory(environment(tp));
h = 0;
while(h<sizeof(ob)) {
  if(ob[h]->query_attack()) { 
    att = ob[h]->query_attack();
    ob[h]->stop_fight();
    att->stop_fight();
  }
h++;
}
tell_room(environment(tp),capitalize(tpn)+
   " has called a stop to all fighting!\n");
return 1; }

money() {
  write("You draw money from another dimension.\n");
  tp->add_money(80000);
return 1; }

heal(str) {
object ob;
  if(!str) ob = tp;
  else ob = find_player(str);
  if(!ob) { write("Target is not in play.\n"); return 1; }
  ob->heal_self(10000);
  if(ob != tp) tell_object(ob,capitalize(tpn)+
     " has healed you.\n");
  write("You heal "+ob->query_real_name()+"\n");
return 1;}

inv(str) { 
object ob,targ;
int h;
  if(!str) return 0;
  targ = find_player(str);
  if(!targ) { write("target not in play.\n"); return 1;}
  ob = all_inventory(targ);
  h = 0;
   write(str+"'s inv\n");
   write("ROOM: ");
   write(environment(targ));
   write("\n");
   while(h<sizeof(ob)) {
    write(ob[h]);
    write(" ");
    if(ob[h]->short()) write(ob[h]->short());
    else if(ob[h]->query_name()) write(ob[h]->query_name());
    else write("INVIS");
    write("\n");
    h++; }
   write("done.\n");
return 1; }

invr(str) { 
object ob,targ;
int h;
  if(!str) return 0;
  targ = find_player(str);
  if(!targ) { write("target not in play.\n"); return 1;}
  ob = all_inventory(environment(targ));
  h = 0;
   write(str+"'s room's inv\n");
   write("ROOM: ");
   write(environment(targ));
   write("\n");
   while(h<sizeof(ob)) {
    write(ob[h]);
    write(" ");
    if(ob[h]->short()) write(ob[h]->short());
    else if(ob[h]->query_name()) write(ob[h]->query_name());
    else write("INVIS");
    write("\n");
    h++; }
   write("done.\n");
return 1; }
   
hand(str) { 
string what,name;
object ob,targ;
ob = 0;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }
  ob = clone_object(what);
  if(!ob) { write("Object did not clone.\n"); return 1; }
  move_object(ob,targ);
  tell_object(targ,"A soft wind blows and something "+ 
                   "is dropped into your inventory\n"+
                   "     **   From: "+capitalize(tpn)+
                   "    **\n");
  write("You have cloned "+what+" to "+name+"\n");
return 1; }

place(str) { 
string name,where;
object targ; 
 if(!str) return 0;
 if(sscanf(str,"%s %s",name,where) != 2) return 0;
 targ = find_player(name);
 if(!targ) { write("Target not in play.\n"); return 1; }
 if(move_object(targ,where)) {
  write("You have moved "+name+" to "+where+"\n");
  tell_object(targ,"You have been moved to "+
                   environment(targ)->short()+" by "+
                   tpn+"\n");
 } else { write("ERROR: move not completed.\n"); }
return 1; }

dun(str) {
string add;
  add = str + " /room/prison.c";
  log_file(logg + " dungeoned "+str+"\n");
  place(add);
return 1; }

church(str) { 
string add;
  if(!str) { add = tpn+" /room/church.c"; }
  else { add = str +" /room/church.c"; }
  place(add);
return 1; }

trans(str) { 
  if(!str) return 0;
  if(!find_player(str)) { write("Target is not game.\n");
     return 1; }
  tell_room(environment(find_player(str)),
           capitalize(str)+
          " has been summoned by a higher power.\n");
  move_object(find_player(str),environment(tp));
  write("You have transed "+str+" to you.\n");
  tell_object(find_player(str),"You have been summoned.\n");
return 1; }

idest(str) { 
string name,what;
object ob,targ;
  if(!str) return 0;
  if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target is not in play.\n");
    return 1; }
  ob = present(what,targ);
  if(!ob) { write("Object is not on target.\n");
   return 1; }
  destruct(ob);
  tell_object(targ,capitalize(tpn)+" has dested "+
     what+" off you.\n");
  write("You have dested "+what+" off "+name+"\n");
return 1; }


