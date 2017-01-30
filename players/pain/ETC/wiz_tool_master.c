wizard_rules() {
command("more /players/pain/rules/wiz_rules.txt",this_player());
return 1;
}

wizard_log(str) {
string reason, action;

if(!str) {
	command("tail /log/"+this_player()->query_real_name()+"_log",this_player());
	return 1;
}
if(sscanf(str,"%s#%s",action,reason) != 2) {
	write("Usage: wlog action#reason\ni.e. wlog heal me#I was hurt.\n");
	return 1;
}
else {
log_file(this_player()->query_real_name()+"_log",ctime()+"--Action: "+action+" Reason: "+reason+"\n");
write("Wrote: Action: "+action+" Reason: "+reason+", to /log/"+this_player()->query_real_name()+"_log.\n");
return 1;
}
}

no_fight() {
 object ob;
 ob=first_inventory(environment(this_player()));
   while (ob) {
     if (living(ob)) {
      if (ob->query_attack()) {
       (ob->query_attack())->stop_fight();
       ob->stop_fight();
       }
      }
      ob = next_inventory(ob);
     }
 
write ("You say: NO...fighting.\n");
say (this_player()->query_name() + " says: NO....fighting.\n");
return 1;
}
 
power_get(str) {
  object ob;
  if(!str) return 0;
  ob = present(str,environment (this_player()));
   if(!ob) {
     write ("No "+str+" here.\n");
     return 1;
     }
write ("You take: "+ob->short() + ".\n");
move_object(ob,this_player());
return 1;
}
 
power_drop(str) {
  object ob;
  if(!str) {
    return 0;
    }
  if(!present(str,this_player())) {
    write("You don't have that...\n");
    return 1;
    }
  else {
   ob=present(str,this_player());
   move_object(ob,environment(this_player()));
   write("You have dropped the " +str+ "\n");
   return 1;
   }
}
 
goin(str) {
   object retard;
   retard=find_player(str);
   if (!retard) return 0;
   move_object(this_player(),retard);
   return 1;
}
 
money(str) {
 int x;
  if (!str) return 0;
   if (sscanf(str,"%d", x) != 1) {
     write("Syntax: money <amt>.\n");
     return 1;
       }
   this_player()-> add_money(x);
   write("Adding "+x+" coins.\n");
return 1;
}
 
bring_player(str) {
   object ob;
   string bye, there;
 
   if(!str) return 0;
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
     write (capitalize(str) + "is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob, "The room fades as darkness falls around you\n" +
       "When the light returns you are in a new place\n");
   move_object(ob, environment(this_player()));
   tell_room(there, capitalize(str) +
     " Dissapears from before you ..You know they were summoned by someone with power\n");
    say (capitalize(str) + " arrives suddenly.\n");
    write (capitalize(str) + " answers your summons.\n");
    return 1;
}
 
dungeon_player(str) {
   object ob;
   string bye, there;
 
if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
     write (capitalize(str) + "is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob,"You are imprisoned "+ capitalize(str)+".\n");
   move_object(ob,"room/prison");
   tell_room(there, capitalize(str) + " is taken away.\n");
   write (capitalize(str) + " is imprisoned.\n");
    log_file("DUNGEON",ctime()+"- "+this_player()->query_real_name()+"- imprisoned "+str+"\n");
   return 1;
}
 
church_player(str) {
   object ob;
   string bye, there;
 
   if(!str) return 0;
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
     write (capitalize(str) + "is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob,"You are escorted to the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) + " is escorted to the church.\n");
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}
 
force (str) {
  object player;
  string name,cmd;
  if (!str) return 0;
  if ((!sscanf (str,"%s %s",name,cmd))==2) return 0;
  player=find_living(name);
  if(!player) { write(capitalize(name)+" is not online.\n"); return 1; }
  command(cmd,player);
  log_file("FORCE",ctime()+"- "+this_player()->query_real_name()+" forced "+name+" to "+cmd+"\n");
  return 1;
}
 
inv(str) {
  object who, obj, tmp;
  int x;
  string one, two, three;
  if(!find_living(str)) {
    write("I could not find "+str+" in the MUD.\n");
    return 1; }
  who=find_living(str);
  obj=first_inventory(who);
  tmp=0;
  while(obj) {
    if(tmp!=0) {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp=0; }
    write(obj);
    write(" : ");
    x=0;
    if(obj->short()) { write(obj->short()); x=1; }
    if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
    if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
    if(x==0) { write("* INVISIBLE *"); }
    write("\n");
    if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
      tmp=obj; }
    obj=next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}
 

inv_room() {
  object who, obj, tmp;
  int x;
  string one, two, three;
  obj=first_inventory(environment(this_player()));
  tmp=0;
  while(obj) {
    if(tmp!=0) {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp=0; }
    write(obj);
    write(" : ");
    x=0;
    if(obj->short()) { write(obj->short()); x=1; }
    if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
    if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
    if(x==0) { write("* INVISIBLE *"); }
    write("\n");
    if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
      tmp=obj; }
    obj=next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}

heal() {
this_player()->heal_self(100000000);
  tell_object(this_player(),"You feel more invigorated now.\n");
return 1;
}
 
hand(str) {
  object who;
  string what;
  if(!sscanf(str,"%s %s",who,what)==2) {
    write("Usage: hand <player> <item>\n");
    return 1; }
  if(!find_living(who)) {
    write("I could not find `"+who+"'.\n");
    return 1; }
  who=find_living(who);
  move_object(clone_object(what),who);
  log_file("HAND",ctime()+"- "+this_player()->query_real_name()+"-"+str+"\n");
  tell_object(who,"A slight breeze passes you by as you notice a new item on you.\n");
  write("Done.\n");
  return 1;
}
 
 
move_them(str) {
  object them;
  string who,where,oldplace;
  if(!str) {
    write("Usage is place <who> <where>\n");
    return 1;
    }
  if((!sscanf(str,"%s %s",who,where))==2) return 1;
  them=find_living(who);
  if(!them) {
    write("I could not find "+capitalize(who)+" anywhere.\n");
    return 1;
    }
  oldplace=environment(them);
  tell_room(oldplace,"A mist forms around "+capitalize(who)+" and when it clears\n"+
            "they are no longer there.\n");
  tell_object(them,"A mist forms around you.  Several seconds later, the mist\n");
  tell_object(them,"lifts and you are in a new place.\n");
  move_object(them,where);
  command("look",them);
  tell_room(where,"A mist suddenly rolls in and when it clears you see "+capitalize(who)+" in its place.\n");
  return 1;
}
 
commands() {
  write("This is the list of the commands for your wiztool:\n");
  write("==================================================\n");
  write("wlog <action>#<reason> -  log your actions.\n");
  write("rules                  -  view the wizards' rules.\n");
  write("force                  -  force a player to do something.\n");
  write("hand <who> <what>      -  hand a player something.\n");
  write("I <who>                -  list of a persons inventory (paths).\n");
  write("Irm                    -  paths of the objects in a room.\n");
  write("calm                   -  stops fighting in a room.\n");
  write("trans <who>            -  brings a player to you.\n");
  write("bring <who>            -  brings a player to you.\n");
  write("dun <who>              -  throws a player into the town prison.\n");
  write("chr <who>              -  brings a player to the church.\n");
  write("heal                   -  heal yourself.\n");
  write("money <amt>            -  give yourself some cash.\n");
  write("get! <object>          -  pickup something you normally couldn't.\n");
  write("drop! <object>         -  drop something you normally couldn't.\n");
  write("goin <who>             -  go into someones inventory.\n");
  write("place <who> <where>    -  move a player to a certain place.\n");
  write("\nThats the list for now.\n");
  return 1;
}
 

