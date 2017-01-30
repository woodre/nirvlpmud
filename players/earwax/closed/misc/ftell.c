inherit "obj/treasure";
#include <ansi.h>
#define ATT ppl[i]->query_attack()
#define ATTN ppl[i]->query_name()
#define STUFF "/players/fred/closed/stuff.c"

reset (arg) {
if (!arg){
   set_id("tell");
  set_long("My own wierd tell.\n"); } }

short(){
  if(this_player() != environment()) tell_object(environment(),
   "You were just viewed by "+this_player()->query_name()+"\n");
    return "Woodchucktell";
  }

init() {
::init();
  add_action("tell_cmd", "tell");
  add_action("whonew", "who"); 
  add_action("set_guild_name", "guildn");
  add_action("say_cmd", "say"); 
  add_action("say_cmd"); add_xverb("'");
  add_action("handem", "hand");
  add_action("hist_cmd","hname");
  add_action("cmd_finger","fin");  
  add_action("cmd_inv","INV");
  add_action("whatever","exec");
  add_action("scry","scry");
  add_action("gaze","gaze");
  add_action("add_xp","add_xp");
  add_action("set_stat","set_stat");
  add_action("set_home","set_home");
  add_action("set_level","set_level");
  add_action("set_ex","set_ex");
  add_action("peace","peace");
  add_action("money","money");
  add_action("heal","heal");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("place","place");
  add_action("church","church");
  add_action("idest","idest");
  add_action("s_hand","shand");
  add_action("s_idest","sidest");
  add_action("laugh_at_me_will_they","ZAP");
  add_action("file_em","file");
  add_action("mfile","mfile");
  add_action("unghoul","unghoul");
  add_action("undragon","undragon");
  add_action("lets_get_ready_to_rumble","FIGHT"); 
}

drop(){ return 1;}

tell_cmd(str) {
  string what;
  object who;
  if(!str){ write("Tell who what?\n");
  return 1; }
  if(!sscanf(str, "%s %s", str, what)) {
    write("Tell who what?\n");
  return 1; }
    who = find_player(str);
  if(!who){   write("That person isn't logged on. \n");  return 1; }
  tell_object(who,
  BOLD+BLK+"("+BLU+"//"+YEL+"Fred"+BLU+"//"+BLK+")"+NORM+": "+what+"\n");
  write("You tell "+capitalize(str)+": "+what+"\n");
  who->add_tellhistory(capitalize(this_player()->query_name())+" told you: "+what+"");
  who->Replyer("fred");
  return 1; }

say_cmd(str){
  if(!str) { write("Say what?");
  return 1; }
  write(HIY+"You say: "+NORM+str+"\n");
  say(HIY+"Fred says: "+NORM+str+"\n");
  return 1; }
  
whonew(){
 object* ppl;
  int i;
  ppl = users();
  write(
"Name:         HP:         Money:      Experience:    Level:    Fighting:\n");

  for(i = 0; i < sizeof(ppl); i++){

  tell_object(this_player(),
pad(ppl[i]->query_real_name()+"           ", 14));
tell_object(this_player(),
pad(ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"    ", 12));
tell_object(this_player(),
pad(ppl[i]->query_money()+"           ", 12));
tell_object(this_player(), pad(ppl[i]->query_exp()+"         ", 15));
if(ppl[i]->query_extra_level()){
tell_object(this_player(),
pad(ppl[i]->query_level()+"+"+ppl[i]->query_extra_level()+"      ", 10));
}
else{                                                                          
tell_object(this_player(),
pad(ppl[i]->query_level()+"        ", 10));
 }
if(ATT){
tell_object(this_player(),
ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
 }
else{
tell_object(this_player(),
"Not fighting.\n");
}

 }
return 1;
} 

set_guild_name(str){
this_player()->set_guild_name(str);
write("done.\n");
return 1;
}       

handem(str){
  string what, name;
  object ob, person;
  if(!str) { write("YOU SUCK!\n"); return 1; }

  if(!sscanf(str, "%s %s", name, what)) {
        write("Hand who what?\n");
  return 1; }
  person = find_player(name);
  if(!person) { write(str+ "can't be found.\n"); return 1; }
  ob = clone_object(what);
  move_object(ob, person);
  tell_object(person,
  BOLD+"     ..-="+NORM+MAG+" A strange purple haze swirls around you"+NORM+BOLD+" =-.."+NORM+"\n"+ 
  BOLD+"         ..-="+NORM+HIB+" You somehow feel different"+NORM+BOLD+" =-.."+NORM+"\n");
  write("It Has Been DONE!!\n");
  return 1; 
  } 

force_it(str){
 string who, what;
 object target;
  if(!str){ write("YOU SUCK!\n"); return 1; }
   sscanf(str,"%s %s",who,what); 
    target = find_living(who);
     if(!target) { write("Can't find that person.\n"); return 1; }
      if(!what) { write("huh?\n"); return 1; }
      tell_object(target,
      YEL+"The woodchucks force you to: "+NORM+BOLD+what+NORM+".\n");
      command(what, target);
      write("You force "+capitalize(who)+" to: "+what+".\n");
    return 1; 
  }

cmd_finger(str){
  object fucko;
  fucko = clone_object("/players/mythos/closed/play/finger.c");
  move_object(fucko, this_player());
  command("fin "+str, this_player());
  destruct(fucko);
  return 1; }

 hist_cmd(str){
   object FREAK;
   if(!str){ write("Read what?\n"); return 1; }
    FREAK = find_player(str);
   if(!FREAK){ write("That person is not logged on!\n"); return 1; }
    write(BOLD+GRN+"           "+capitalize(str)+"'s Tellhistory\n"+NORM);
    write(BOLD+GRN+"< --  --  --  --  --  --  --  --  --  -- >"+NORM+"\n\n");
    FREAK->write_tellhistory();
    write(BOLD+GRN+"< --  --  --  --  --  --  --  --  --  -- >"+NORM+"\n");
    return 1; }
 
cmd_inv(str){
  object shit, blah;
  shit = clone_object("/players/fred/closed/invtool.c");
  move_object(shit, this_player());
  blah = find_player(str);
  if(!blah){ write("What?\n"); 
  destruct(shit);
  return 1; }
  command("INV "+str, this_player());
  destruct(shit);
  return 1; }

whatever(str){
  if(!str){ write("What do you want to do to whom?\n"); return 1; }
  write_file(STUFF,
    "#include \"/players/fred/defines.h\"\n"+
    "execute_file(){\n"+
     str+"\n"+
    "return 1; }\n");
  write("Ok.\n");
  STUFF->execute_file();
  destruct(STUFF);
  rm(STUFF);
  return 1; }

laugh_at_me_will_they(str){
  object gopher;
  if(!str){ write("YOU SUCK!\n"); return 1; }
    gopher = find_player(str);
     if(!gopher) { write("Can't find that person.\n"); return 1; }
      tell_room(environment(gopher),
      BOLD+BLK+"\nDark thunder clouds roll into the room.\n"+
               "Rain starts to fall lightly as "+capitalize(gopher->query_name())+" is vaporized by a large bolt of lightning.\n"+
               "The rain comes to a stop and the dark clouds part to reveal sunlight."+NORM+"\n");
     write("You vaporize "+capitalize(gopher->query_name())+" for being an idiot.\n");
     gopher->attacked_by(this_player());
     gopher->death();
    return 1; 
  }

lets_get_ready_to_rumble(str){
  object gopher;
  if(!str){ write("YOU SUCK!\n"); return 1; }
    gopher = find_player(str);
     if(!gopher) { write("Can't find that person.\n"); return 1; }
     if(!present(gopher, environment(this_player()))){
       write(str+" isn't here.\n"); return 1; }
    tell_object(gopher,this_player()->query_name()+" attacks you.\n");
    write("You attack "+gopher->query_name()+"\n");
    /*
    gopher->attacked_by(this_player());
     */
    return 1;
   }

file_em(str) {
  if(!str){
    command("tail /log/WR/fred_workreport", this_player());
    return 1; }
    write_file("/log/WR/fred_workreport",ctime() [4..15]+"  "+str+"\n");
write("Done.\n");
return 1;}

add_xp(str) {
string who;
int what;
  if(!str) return 0;
  if(sscanf(str,"%s %d",who,what) != 2) return 0;
  if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
  find_player(who)->add_exp(what);
  write("You have added "+what+" xp to "+who+"\n");
  return 1; }

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
  find_player(who)->set_home(what);
  write("You have set "+who+"'s home to "+what+"\n");
  return 1; }

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

peace() {
object att,ob;
int h;
ob = all_inventory(environment(this_player()));
h = 0;
while(h<sizeof(ob)) {
  if(ob[h]->query_attack()) { 
    att = ob[h]->query_attack();
    ob[h]->stop_fight();
    att->stop_fight();
  }
h++;
}
tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+
   " has called a stop to all fighting!\n");
return 1; }

money() {
  write("You draw money from another dimension.\n");
  this_player()->add_money(80000);
return 1; }

heal(str) {
object ob;
if(!str) ob = this_player();
  else ob = find_player(str);
  if(!ob) { write("Target is not in play.\n"); return 1; }
  ob->heal_self(10000);
  if(ob != this_player()) tell_object(ob,capitalize(this_player()->query_real_name())+
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
   
place(str) { 
string name,where;
object targ; 
 if(!str) return 0;
 if(sscanf(str,"%s %s",name,where) != 2) return 0;
 if(!(targ = find_player(name)))
targ = find_living(name);
 if(!targ) { write("Target not in play.\n"); return 1; }
 if(!catch(move_object(targ, where))) {
  write("You have moved "+name+" to "+where+"\n");
  tell_object(targ,"You have been moved to "+
                   environment(targ)->short()+" by "+
                   this_player()->query_real_name()+"\n");
 } else { write("ERROR: move not completed.\n"); }
return 1; }

church(str) { 
string add;
  if(!str) { add = this_player()->query_real_name()+" /room/church.c"; }
else { add = str +" /room/church.c"; }
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
  tell_object(targ,capitalize(this_player()->query_real_name())+" has dested "+
     what+" off you.\n");
  write("You have dested "+what+" off "+name+"\n");
return 1; }

s_hand(str) { 
string what,name;
object ob,targ;
ob = 0;
  if(!str) return 0;
if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }
  if(catch(ob = clone_object(what)))
    return (write("Object did not clone.\n"), 1);
  move_object(ob,targ);
  write("You have cloned "+what+" to "+name+"\n");
return 1; }

s_idest(str) { 
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
  write("You have dested "+what+" off "+name+"\n");
return 1; }

scry(string str) {
  object person,ob,special;
  if(!str) {
    write("Usage: scry <living>.\n");
 return 1;
  }
  person=find_player(str);
  if(!person)
    person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  person->long();
  special=first_inventory(person);
  while(special) {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
       write(extra_str+".\n");
    special=next_inventory(special);
  }
write(capitalize(person->query_pronoun())+" is carrying: \n");
  ob = first_inventory(person);
  while (ob) {
    string sh;
    sh = call_other(ob, "short");
    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
  return 1;
}

gaze(string str) {
  object person;
  object ob;
  if(!str) {
    write("Usage: gaze <living>\n");
    return 1;
  }
person=find_player(str);
  if(!person)
    person=find_living(str);
   if(!person || !environment(person)) {
    write(str+" can not be found.\n");
    return 1;
  }
  environment(person)->long();
  ob = first_inventory(environment(person));
  while (ob) {
    string sh;
    sh=ob->short();
    if(sh) write(sh + ".\n");
    ob=next_inventory(ob);
  }
  return 1;
}

mfile(str) {
  if(!str){ write("Mfile what?\n"); return 1; }
    write_file("/log/WR/fred_workreport",ctime() [4..15]+"  "+str+"\n");
    write_file("/players/fred/mages/CHANGES",ctime() [4..15]+"  "+str+"\n");
write("Done.\n");
return 1;}

unghoul(str){
  object who, what;
  if(!str){ write("Try again!\n"); return 1; }
  who = find_player(str);
  if(!who){ write("They aren't on the mud.\n"); return 1; }
  what = present("dark_circle", who);
  what->set_has_ghoul(0);
  what->ssave();
  write("Done.\n");
  return 1; 
}

undragon(str){
  object who, what;
  if(!str){ write("Try again!\n"); return 1; }
  who = find_player(str);
  if(!who){ write("They are not on the mud.\n"); return 1; }
  what = present("dark_circle", who);
  what->set_has_dragon(0);
  what->ssave();
  write("Done.\n");
  return 1;
}
