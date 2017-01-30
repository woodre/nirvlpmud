
#include <ansi.h>
#define LOGFILE "/players/dragnar/WORK_REPORT"
#define tpn this_player()->query_name()
#define tl this_player()->query_level()
#define BIN "/players/dragnar/wiztool/bin"

id(str) {
    return str == "book" || str == "tool" || str == "dark_sight_object";
}
short () {
    return "A Spellbook";
}
long() {
    write("A Wizards Book of Spells.\n");
}
get() { return 1; }
drop() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }
init() {
  if (this_player()->query_real_name() == "dragnar" || 
      this_player()->query_real_name() == "dragtest" ||
      this_player()->query_real_name() == "gnar") {
    
    int i;
    string cmd;
    string *f;
    
    f = get_dir( BIN + "/_*.c" );
    
    i = sizeof(f);
    while (i--) {
	    sscanf(f[i], "_%s.c", cmd);
	    add_action("cmd_hook", cmd);
    }
    /* Player interaction */
    add_action( "bring_player", "bring");
    add_action( "fix_guild", "fix_guild" );
    add_action( "echo_to", "echoto");
    add_action( "church_player", "chr");
    add_action( "echo_all", "echoall");
    add_action( "echor", "echor");
    add_action( "hand","hand");
    add_action( "heal","heal");
    add_action( "heal_all","heal_all");
    add_action( "echo_player","echop");
    add_action( "dun","dun");
    add_action( "idest","idest");
    add_action( "ptest","ptest");
    /* Player updates */
    add_action("settitle","settitle");
    add_action("setrank","setrank");
    add_action("setste","setste");
    add_action( "axp","axp");
    add_action("setgexp","setgexp");
    add_action("set_stat","set_stat");
    add_action("set_home","set_home");
	  add_action("set_guild_file","set_guild_file");
    add_action("set_level","set_level");
    add_action("set_ex","set_ex");
    add_action("add_al","add_al");
    add_action("add_bal","add_bal");
    add_action("add_quest","add_quest");
    /* wiz actions */
    add_action("mobdual","mobdual");
    add_action("tell","tell");
    add_action( "power_get", "get!");
    add_action( "power_drop", "drop!");
    add_action( "goin", "goin");
    add_action("money", "money");
    add_action("no_fight", "no");
    add_action("force", "force");
    add_action("inv","I");
    add_action("awho","awho");
    add_action("invr","ir");
    add_action("request","request");
    add_action("destinv","destinv");
    /* wiz admin */
    add_action( "chomp","chomp");
    add_action( "worklog","worklog");
    add_action("readlog","readlog");
    add_action("drag","drag");
    add_action("v","v");
    add_action("shop","shop");
    add_action("amr","amr");
    add_action("h","h");
    add_action("weap","weap");
    add_action("c","c");
    add_action("r","r");
    add_action("mons","mons");
    add_action("past","past");
    add_action("temp","temp");
    add_action("walking_dead","dead");
    /* wth? */
    add_action("rescue","rescue"); 
  }
}

cmd_hook(string str) {
  string cmd, verb;
 
	verb = query_verb();
  
  cmd = BIN + "/_" + verb + ".c";
  if( file_size(cmd) > 0)
    return (int)call_other(cmd, "cmd_" + verb, str);
  else {
    write("file: " + cmd + "\n");
  }
}
fix_guild(string str)
{
 object fool;
 int x;

 if(!str)
 {
  write("Usage: 'fix_guild <name>'\n");
  return 1;
 }
 if(!(fool = find_player(str)))
 {
  write(capitalize(str)+" is not logged in.\n");
  return 1;
 }
 fool->set_guild_exp(0);
 fool->set_guild_rank(71);
 fool->set_guild_name("mages");
 fool->set_guild_file("/players/pavlik/guild/mages/gob.c");
 write("Ok, you have set "+capitalize(str)+"'s guild status.\n");
 return 1;
}

fix_guild2(string str)
{
 object fool;
 int x;

 if(!str)
 {
  write("Usage: 'fix_guild <name>'\n");
  return 1;
 }
 if(!(fool = find_player(str)))
 {
  write(capitalize(str)+" is not logged in.\n");
  return 1;
 }
 fool->set_guild_exp(16639422);
 fool->set_guild_rank(71);
 fool->set_guild_name("mage");
 fool->set_home("/players/dragnar/workroom");
 fool->set_guild_file("/players/pavlik/guild/mages/gob");
 write("Ok, you have removed "+capitalize(str)+"'s guild status.\n");
 return 1;
}

mobdual(string str) {
  string mob1, mob2;
  object mon1, mon2;
  if(sscanf(str,"%s %s",mob1,mob2) != 2) return 0;
  write("mon1: '"+mob1+"'\n");
  write("mon2: '"+mob2+"'\n");
  mon1 = present(mob1, environment(this_player()) );
  if( !mon1 ) {
    write(mob1+ " isn't here Gnar.\n");
    return 1;
  }
  mon2 = present(mob2, environment(this_player()) );
  if( !mon2 ) {
    write(mob2+" aren't here Gnar.\n");
    return 1;
  }
  mon1->attacked_by( mon2 );
  return 1;
}

chomp() {
  this_player()->set_spell_dam(1300);
  write("Vortaxx chomps on your attackers throat.\n");
  say("Dragnar's dragon "+HIR+"chomps"+NORM+" on his attackers throat.\n");
  return 1;
}

invr(str) {
object ob,targ;
int h;
  if(!str) str = "dragnar";
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

destinv() {
  this_player()->destruct_inventory();
  write("OK.\n");
  return 1;
}  

dun(str) {
string add;
  add = str + " /room/prison.c";
  place(add);
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

ptest( str ) {
string who,what;
int amount;
object target;
  if(!str) return 0;
  if(sscanf(str,"%s %s %d",who,what,amount) != 3) return 0;
  if(!find_player(who)) { 
    write("Target is not in play.\n"); 
    return 1; 
  }
  target = find_player(who);
  if(!target) {
    write("Target not found Gnar.\n");
    return 1;
  }
  if( what == "lev" ) 
    target->set_prestige_level( amount );
  else if( what == "skp" )
    target->set_prestige_skillpt( amount );
  else
    target->set_prestige_skill(what,amount);
  write("You have set "+who+"'s "+what+" to "+amount+"\n");
  return 1;
}

add_bal( str ) {
  string who;
  object targ;
  int amount;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,amount) != 2) 
    return 0;
    
  targ = find_player( who );
  if( !targ ) {
    write("Not found.\n");
    return 1;
  }
  targ->add_bank_balance( amount );
  write("OK\n");
  return 1;
}

add_quest( str ) {
  string who, quest;
  object targ;
  if(!str) return 0;
  if(sscanf(str,"%s %s",who,quest) != 2) 
    return 0;
    
  targ = find_player( who );
  if( !targ ) {
    write("Not found.\n");
    return 1;
  }
  targ->set_quest( quest );
  write("OK\n");
  return 1;
}

set_stat(str) {
string who,what;
int amount;
  if(!str) return 0;
  if(sscanf(str,"%s %s %d",who,what,amount) != 3) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_attrib(what,amount);
  write("You have set "+who+"'s "+what+" to "+amount+"\n");
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
return 1; }

set_guild_file(str) {
  string who;
  string what;
  
  if(!str) return 0;
  if(sscanf(str,"%s %s",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  if(find_player(who)->query_level() > tl) {
    write("You may not set the home of someone above you.\n");
  return 1; }
  find_player(who)->set_guild_file(what);
  write("You have set "+who+"'s home to "+what+"\n");
  return 1; 
}

set_level(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_level(what);
  write("You have set "+who+"'s level to "+what+"\n");
return 1; }


set_ex(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_extra_level(what);
  write("You have set "+who+"'s extralevel to "+what+"\n");
return 1; }

add_al(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->set_alignment(what);
  write("You have set "+who+"'s alignment to "+what+"\n");
return 1; }

drag() {
  cat("/log/dragnar");
  return 1;
}

mguide() {
  cat("/doc/build/RULES/monster.guide");
  return 1;
}
worklog( string str ) {
  if(!str) return 0;
  write_file("/log/WR/dragnar_workreport","["+ctime(time())+"]  "+str+".\n");
  write("report done.\n");
  return 1;
}

readlog() {
   tail("/log/WR/dragnar_workreport");
    return 1;
}

settitle(str) {
  string ttl;
  string who;
  object target;
  if(sscanf(str, "%s %s",who,ttl)!=2) return write("huh?\n");
  if(!who) { write("huh?\n"); return 1; }
  if(!ttl) { write("huh?\n"); return 1; }
  target=find_player(who);
  if(!target) { write("I can't find them Drag.\n"); return 1; }
  target->set_title(ttl);
  write("Done...\n");
  return 1; 
}
no_fight() {
  object ob;
  ob=first_inventory(environment(this_player()));
  while (ob) {
    if (living(ob)) {
      if (ob->query_attack()) {
      ob->query_attack()->stop_fight();
        ob->stop_fight();
      }
    }
    ob = next_inventory(ob);
    ob;
  }
  write ("You say: NO...fighting.\n");
  say (this_player()->query_name() + " says: NO....fighting.\n");
  return 1;
}
static echor(str) {
  if (!str) {
    write ("Echo what?\n");
  return 1;
  }
  say (str + "\n");
  write ("You echo: "+str+" \n");
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
  if (!str) return 0;
  ob=present(str,this_player());
  if (!ob) {
     write ("You dont have a "+str+" .\n");
     return 1;
  }
  write("You drop "+ob->short()+ ".\n");
  move_object(ob,environment(this_player()));
  return 1;
}
goin(str) {
   object retard;
   retard=find_player(str);
   if (!retard) return 0;
   move_object(this_player(), retard);
   return 1;
}

money(str) {
   int x;
   if (!str) return 0;
   if (sscanf(str,"%d", x) != 1) {
      write ("snytax: money <amount> \n");
      return 1;
   }
   this_player()-> add_money(x);
   write("Adding "+x+" coins.\n");
   return 1;
}
static echo_to(str) {
  object ob;
  string who;
  string msg;
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
     write("Echoto what ?\n");
     return 1;
  }
  ob=find_living(lower_case(who));
  if (!ob) {
     write("no player with that name.\n");
     return 1;
     return 1;}
  tell_object(ob, msg + "\n");
  write ("you echo: " + msg + "\n");
  return 1;
}
static echo_all(str) {
  if (!str) {
    write("Echoall what?\n");
    return 1;
  }
  shout(str + "\n");
  write ("You echo: " + str + "\n");
  return 1;
}
bring_player(str) {
  object ob;
  string bye, there;
  if(!str) return 0;
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) {
     write (capitalize(str) + "is not online at this time.\n");
     return 1;
  }
  there = environment(find_living(str));
  if( !there ) {
    write("No environment.\n");
    return 1;
  }
  tell_object(ob, "A large black dragon dives from the clouds.\n"+
     "His talons rip open your back as he takes you to a new place.\n");
  move_object(ob, environment(this_player()));
  tell_room(there, "A large black dragon dives from the sky and takes  "+capitalize(str)+" away.\n");
  say ("A large black dragon drops "+capitalize(str) + " at Dragnar's feet.\n");
  write("A large black dragon drops "+capitalize(str) + " at your feet.\n");
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
  tell_room(there, capitalize(str) +
     " is escorted to the church.\n");
  write (capitalize(str) + " is escorted to the church.\n");
  return 1;
}

axp(str) {
  string name;
  int num;
  object who;
  if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
  if(!name) {
     write("huh?\n");
     return 1;
   }
  if(!num) {
     write("huh?\n");
     return 1;
   }
  who = find_player(name);
  if(!who) {
     write("He ain't here Dragnar.");
   }
  who->add_exp(num);
  write("Done\n");
  return 1;
}
force(str) {
  object player;
  string name,cmd;
  if (!str) return 0;
  if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
  player=find_living(name);
  if(!player) { write(capitalize(name)+ " is not online.\n"); }
  command(cmd,player);
  return 1;
}
         
inv(str) {
  object who, obj;
  int x;
  string one, two, three;
  if(!str) str = "dragnar";
  if(!find_living(str)) {
     write("I could not find "+str+" in the MUD.\n");
     return 1; }
  who=find_living(str);
  obj=first_inventory(who);
  while(obj) {
     write(obj);
     write(" : ");
     x=0;
     if(obj->short()) { write(obj->short()); x=1; }
     if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
     if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
     if(x==0) { write("* INVISIBLE *"); }
     write("\n");
     obj=next_inventory(obj);
   }
  write("Done.\n");
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
   write("Done.\n");
   return 1;
}

awho(str){
   object us;
   int x, y;
   if(str) return;
   us = users();
   write("]-------|player|----------|location|------------------------------------------->\n");
   for(x=0;x<sizeof(us);x++){
      y = x + 1;
      write(y + ".\t" + capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
         write("\t"); else write("\t\t");
      if(!environment(us[x])) write("Logging in");
      else write(environment(us[x])->short());
      write("\n");
     }
   return 1;
}
tell(str) {
  object plyr;
  string who;
  string what;
  if(!str) {write("Tell what?\n"); return 1;}
  if(sscanf(str,"%s %s",who,what)==2){
    plyr = find_living(who);
    if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
    if(this_player()->query_invis() > 1) {
        tell_object(plyr, HIR+"D"+NORM+RED+"ragnar"+NORM+" (invis) : "+what+" \n");
       plyr->add_tellhistory("Dragnar tells you: "+what+"\n");
       plyr->Replyer((string)this_player()->query_real_name());
      write("You tell "+plyr->query_real_name()+": "+what+"\n");
      return 1; }
    if(this_player()->query_invis() < 1) {
       tell_object(plyr, HIR+"D"+NORM+RED+"ragnar"+NORM+" : "+what+" \n");
      plyr->add_tellhistory("Dragnar tells you: "+what+"\n");
      plyr->Replyer((string)this_player()->query_real_name());
      write("You tell "+plyr->query_real_name()+": "+what+"\n");
      return 1;
    }
  }
  write("Tell what to whom?\n");
  return 1;
}
v() {
  command("cd ~",this_player());
  return 1;
}
weap() {
  command("cd /players/dragnar/weapons", this_player());
  return 1;
}
amr() {
  command("cd armor", this_player());
  return 1;
}
shop() {
  command("cd /players/dragnar/shop",this_player());
  return 1;
}
c() {
  command("cd /players/dragnar/closed", this_player());
  return 1;
}
h() {
  command("cd heal", this_player());
return 1;
}
r() {
  command("cd rooms", this_player());
return 1;
}
mons() {
  command("cd mons", this_player());
return 1;
}
past() {
  command("cd /players/dragnar/past",this_player());
return 1;
}
wst() {
  command("cd /players/dragnar/Wastelands",this_player());
return 1;
}
walking_dead() { 
  command ("cd /players/dragnar/WalkingDead", this_player()); 
  return 1;
}

temp() {
  command("cd /players/boltar/templar",this_player());
  return 1;
}
jed(string str) {
  if(!str) {
    command("cd /players/dragnar/Jedi",this_player());
    return 1;
  }
  else {
    command("cd /players/dragnar/Jedi/"+str+"",this_player());
    return 1;
  }
}

heal(str){
  object ob;
  if(!find_player(str)) {
    write("They don't seem to be on drag.\n");
  return 1;
  }
  ob=find_player(str);
  ob->heal_self(10000);
  tell_object(ob, "You have been healed by dragnar.\n");
  write(capitalize(str)+" is now fully healed.\n");
  return 1;
}

request() {
	int i;
	object ob;
	ob=users();
	for(i=0; i < sizeof(ob); ++i) {
      if(present("bloodscar", ob[i])){
        command("new_scar Forced by Dragnar", ob[i]);
        tell_object(ob[i], "Dragnar caused new_scar.\n");
      }
	}
	write("Ok, done.\n");
	return 1;
}
echo_player(str) {
	int i;
	object ob;
	ob=users();
	for(i=0; i < sizeof(ob); ++i) {
      if(ob[i]->query_level() < 20) {
      tell_object(ob[i], str+"\n");
      }	
	}
	write("You echoed: "+str+"\n");
	return 1;
}
setrank(str) {
	int ob, amount;
	object member, guild;
	string who;
	if(!str || sscanf(str, "%s %d",who,ob) != 2) {
	write("Error...\n"); return 1; }
	member = find_living(who);
	amount=member->query_guild_rank();
	if(!who) { write("Can't find "+who+".\n"); return 1; }
	member->add_guild_rank(-amount);
	member->add_guild_rank(ob); 
	write("Ok, done.\n");
	return 1;
	}
setste(str) {
    object who;
    int amount;
    string target;
    sscanf( str, "%s %d",target,amount);
    write("amount is " +amount +"\n");
    who = find_player(target);
    who->set_attrib("ste",amount);
    return 1;
}
setgexp(str) {
  int ob, amount;
  object member;
  string who;
  if(!str || sscanf(str, "%s %d",who,ob) != 2) {
    write("Error...\n"); return 1; }
  member = find_player(who);
  amount = member->query_guild_exp();
  if(!member) { write("Can't find "+who+".\n"); return 1; }
  member->add_guild_exp(-amount);
  member->add_guild_exp(ob);
  write("Ok, done.\n");
return 1; }

rescue(str) {
  return clone_object("/players/wocket/closed/rescueshad.c")->set_rescued(str);
}
