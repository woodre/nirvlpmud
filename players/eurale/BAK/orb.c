/*  Eurale's Wiztool  */

#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_real_name()
#define ep environment(this_object())
#define epn ep->query_real_name()
#define Mv call_other(this_player(),"move_player"

inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("orb");
set_alias("crystal");
set_short("A "+HIC+"crystal dragon orb (floating)"+NORM);
set_long(
	"  This crystal orb was forged by Eurale himself after studying \n"+
	"the ways of -The Hunter- for a great deal of time.  It incorp - \n"+
	"orates the power of the fae with vast knowledge of it's use. \n"+
	"Use it's power wisely.... \n\n"+
"Places:  church  board  test  portal  office\n"+
"\n"+
"Commands:  hentai  hand  I  Irm  calm  jail  pew  cl  sps  et\n"+
"           money  place  send  deste  setat  'help wiz_levels' \n"+
"           view  unguild  register  sset  garble  nset  aset \n"+
"           gset  quiet  file  infect  imprison/free  hps  authcheck \n"+
"\n");
set_class(100);
set_weight(0);
set_value(0);
set_light(0);
}

drop() { return 1; }
query_save_flag() { return 1; }

/*
query_auto_load() { return "players/eurale/closed/Dorb.c:"; }
*/

init() {
  ::init();
  if(epn != "eurale") {
  write("NOT POSSIBLE!! \n");
  destruct(ep);
destruct(this_object());
}

  add_action("Office","office");
  add_action("church","church");
  add_action("portal","portal");
  add_action("board","board");
  add_action("test","test");

  add_action("calm","calm");
  add_action("sore_throat","infect");
  add_action("commands","commands");
  add_action("hand","hand");
  add_action("money","money");
  add_action("dungeon_player","jail");
  add_action("church_player","pew");
  add_action("inv","I");
  add_action("inv_room","Irm");
  add_action("send","send");
  add_action("deste","deste");
  add_action("setat","setat");
  add_action("view","view");
  add_action("unguild","unguild");
  add_action("register","register");
  add_action("sset","sset");
  add_action("garble","garble");
  add_action("shut_up","quiet");
  add_action("nset","nset");
  add_action("aset","aset");
  add_action("sps","sps");
  add_action("hps","hps");
  add_action("et","et");
  add_action("gset","gset");
  add_action("quest_set","quest");
  add_action("filer","file");
}


/*  ROOM LOCATIONS TO TELEPORT TO   */
church() { Mv,"church#room/church.c"); return 1; }
portal() { Mv,"portal#players/saber/ryllian/portal.c"); return 1; }
board() { Mv,"board#room/adv_inner.c"); return 1; }
test() { Mv,"test#players/eurale/testroom.c"); return 1; }
Office() { Mv,"office#players/eurale/VAMPIRES/RMS/office.c"); return 1; }


calm() {
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
 
write("You command the fighting to stop.... and it does. \n");
say (this_player()->query_name() + " says: C'est Finis....and all is still.\n");
return 1;
}
 
 
 
money() {
  write("You reach up and pull coins out of thin air.....\n");
  this_player()->add_money(80000);
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
  move_object(ob,"players/eurale/closed/prison.c");
   tell_room(there, capitalize(str) + " is hauled away.\n");
   write (capitalize(str) + " is imprisoned.\n");
   return 1;
}
 
church_player(str) {
   object ob;
   string bye, there;
 
  if(!str) { write("Who do you want to send to the church?\n"); return 1; }
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
  tell_object(who,
  "Eurale's pet "+HIC+"blue demon"+NORM+" flies in and hands you something...\n");
  write("Your pet "+HIC+"blue demon"+NORM+" takes something and flies off...\n");
  return 1;
}
 

send(str) {
  object ob;
  string who,what;
if(!str)
  { write("Usage: send <what> <who>\n"); return 1; }
  sscanf(str,"%s %s",who,what);
  ob = find_player(who);
  if(!ob) {write("not here... \n"); return 1; }
  if(!present(what,this_player()))
	{write("you don't have one.... \n"); return 1; }
  move_object(present(what,this_player()),ob);
  write("You call forth a servant and it takes "+what+" to "+
		capitalize(who)+"\n");
  say(tp+" calls forth a demon....\n\nThe demon flies off... \n");
  tell_object(ob,"\nA small demon appears and hands you a "+what+"\n\n"+
		 "It whispers to you:  From Eurale\n\n");
  tell_room(environment(ob),
	"A small demon flies in and hands something to "+
	capitalize(who)+".\n\n");
return 1; }


deste(str) {
string who,what;
  object ob;
  if(!str) { write("deste <who> <item> \n"); return 1; }
  sscanf(str,"%s %s",who,what);
  if(!find_player(who)) { write("player not present... \n"); return 1; }
  ob = present(what, find_player(who));
  if(!ob) { write("object not present... \n"); return 1; }
  destruct(ob);
  write("Object destroyed... \n");
/*
  tell_object(find_player(who),"Destroyed: "+what+".\n");
*/
return 1;
}



setat(str) {
string who,what;
int num;
  if(!str) {write("setat <who> <what> <num> \n"); return 1; }
  sscanf(str,"%s %s %d",who,what,num);
  if(!find_player(who)) {write("not logged on... \n"); return 1; }
  find_player(who)->set_attrib(what,num);
write("You have set "+capitalize(who)+"'s "+what+" to "+num+".\n");
return 1;
}


view(str) {
string who,type;
object ob;
  if(!str) {write("view name a/h \n"); return 1; }
  sscanf(str,"%s %s",who,type);
  if(!find_player(who)) {write("not here.... \n"); return 1; }
  if(!present("qt",find_player(who))) {write("no...qt.. \n"); return 1; }
  ob = present("qt",find_player(who));
  if(type == "a") {call_other(ob,"alias"); }
  if(type == "h") {call_other(ob,"history"); }
return 1;
}



unguild(str) {
string type,who;
int num,numer;
object pl;
  if(!str) { write("unguild <who> \n"); return 1; }
  sscanf(str,"%s",who);
  if(!find_player(who)) { write("not on... \n"); return 1; }
pl = find_player(who);
  pl->set_guild_name(0);
  pl->set_guild_rank(0);
  pl->set_guild_exp(0);
  pl->set_guild_file(0);
  num = ((int)pl->query_guild_exp());
  numer = ((int)pl->query_guild_rank());
  pl->add_guild_exp(-num);
  pl->add_guild_rank(-numer);
write("You have unguilded "+capitalize(who)+".\n");
tell_object(pl,"You feel suddenly empty..... \n");
return 1;
}


register(str) {
  if(!str) { write("register <who> \n"); return 1; }
  if(!find_player(str)) { write("not on.... \n"); return 1; }
  if(call_other(find_player(str),"query_ghost"))
  { write("Sorry, he's dead... \n"); return 1; }
call_other(find_player(str),"reset",1);
find_player(str)->recalc_quest();
write("Registered.... \n");
return 1;
}


sset(str) {
  string who, what, wht;
  int whtn;
  object ob;
    if(!str) {
    write("sset <who> <what> <wht> \n");  return 1; }
  sscanf(str,"%s %s %s",who,what,wht);
  ob = find_player(who);
  if(!ob) { write("not logged on.... \n"); return 1; }
if(what == "quest") { ob->set_quest(wht);
  write(capitalize(who)+" has been credited with quest: "+wht+"\n"); return 1; }
if(what == "pretitle") { ob->set_pretitle(wht);
  write("Pretitle of "+who+" set to: "+wht+".\n"); return 1; }
if(what == "title") { ob->set_title(wht);
	write("title of "+who+" set to "+wht+".\n"); return 1; }
if(what == "gender") { ob->set_gender(wht);
	write("gender of "+who+" set to "+wht+".\n"); return 1; }
if(what == "name") { ob->set_living_name(wht);
	write("name of "+who+" set to "+wht+".\n"); return 1; }
if(what == "swield") { ob->stop_wielding(wht);
	write(who+" stops wielding "+wht+".\n"); return 1; }
if(what == "home") { ob->set_home(wht);
	write(who+"'s home is now "+wht+"\n"); return 1; }
if(what == "swear") { ob->stop_wearing(wht);
	write(who+" stops wearing "+wht+".\n"); return 1; }
if(what == "alt") { ob->set_al_title(wht);
	write("allignment title set to "+wht+".\n"); return 1; }
if(what == "race") { ob->new_race(what);
	write("race of "+who+" set to "+wht+".\n"); return 1; }
return 1;
}



nset(str) {
string who,what;
int num;
object ob;
  if(!str) { write("nset <who> <what> <num> \n"); return 1; }
  sscanf(str,"%s %s %d",who,what,num);
  ob = find_player(who);
  if(!ob) { write("not logged on.... \n"); return 1; }
if(what == "grank") { ob->set_guild_rank(num);
  write("guild rank of "+who+" set to "+num+".\n"); return 1; }
if(what == "gexp") { ob->add_guild_exp(num);
  write("guild experience of "+who+" altered by "+num+"\n"); return 1; }
if(what == "exl") { ob->set_extra_level(num);
	write("extra level of "+who+" set at "+num+".\n"); return 1; }
if(what == "guild") { ob->set_guild_name(num);
  write("guild name of "+who+" set to "+num+".\n"); return 1; }
if(what == "level") { ob->set_level(num);
	write("level of "+who+" set at "+num+".\n"); return 1; }
if(what == "align") { ob->add_alignment(num);
    write("alignment of "+who+" is altered by "+num+".\n"); return 1; }
if(what == "wc") { ob->set_wc(num);
	write("weapon class of "+who+" set at "+num+".\n"); return 1; }
if(what == "dead") { ob->set_dead(num);
	write("dead of "+who+" set at "+num+".\n"); return 1; }
if(what == "soak") { ob->add_soaked(num);
	write("soak of "+who+" set at "+num+".\n"); return 1; }
if(what == "stuff") { ob->add_stuffed(num);
	write("stuff of "+who+" set at "+num+".\n"); return 1; }
if(what == "intox") { ob->add_intoxication(num);
	write("intox of "+who+" set at "+num+".\n"); return 1; }
if(what == "ac") { ob->set_ac(num);
	write("ac of "+who+" set at "+num+".\n"); return 1; }
if(what == "frog") {
  ob->frog_curse(num);
  write("Frog curse of "+who+" set to "+num+".\n");
  ob->save_me();
  return 1; }
if(what == "xp") {
  find_player(who)->add_exp(num);
  write("You have altered "+who+"'s experience by "+num+"\n"); return 1; }
tell_object(ob,
	"You feel something grip your throat.... \n"+
	"Something strange invades your very soul... \n"+
	"You begin to shake with fear and pain...\n\n"+
	"Then it's over.......... \n");
return 1;
}


garble(str) {
  if(!str) { write("garble <who> \n"); return 1; }
  if(!find_player(str)) { write("not logged on.... \n"); return 1; }
  move_object(clone_object("players/eurale/closed/garble.c"),
	find_player(str));
  command("save",this_player());
  write("Garbled sir.... :)  \n");
return 1;
}


sore_throat(str) {
  if(!str) { write("Who gets the sore throat?\n"); return 1; }
  if(!find_player(str)) { write("Not here...\n"); return 1; }
  move_object(clone_object("players/eurale/closed/sore_throat.c"),
      find_player(str));
  command("save",find_player(str));
  tell_object(find_player(str),
    "You suddenly get a very sore throat....\n");
  write("You've given "+capitalize(str)+" a sore throat!\n");
  return 1;
}

shut_up(str) {
  if(!str) { write("Usage:  quiet <who>\n"); return 1; }
  if(!find_player(str)) { write("Not logged on....\n"); return 1; }
  tell_object(find_player(str),"You have been completely silenced..\n");
  move_object(clone_object("players/eurale/closed/shut_up.c"),
    find_player(str));
  write(capitalize(str)+" is silenced...... bliss!\n");
return 1;
}




aset(str) {
string who, what;
object ob;
  if(!str) { write("aset <who> <what> \n"); return 1; }
  sscanf(str,"%s %s",who,what);
  ob = find_player(who);
  if(!ob) { write("not logged on.... \n"); return 1; }
if(what == "scrime") { ob->set_crime();
  write("crime of "+who+" is set.\n"); return 1; }
if(what == "ccrime") { ob->clear_crime();
  write("crime of "+who+" is removed.\n"); return 1; }
if(what == "shunt") { ob->stop_hunting_mode();
  write("hunt mode of "+who+" if off.\n"); return 1; }
if(what == "invis") { ob->set_invis_sp();
  write("invis of "+who+" is set.\n"); return 1; }
if(what == "vis") { ob->visible();
  write(who+" is now visible.\n"); return 1; }
if(what == "preg") { ob->set_pregnancy();
  write(who+" is now pregnant.\n"); return 1; }
if(what == "cpreg") { ob->clear_pregnancy();
  write(who+" is no longer pregnant.\n"); return 1; }
if(what == "birth") { ob->child_birth();
  write("you have made "+who+" give birth.\n"); return 1; }
return 1;
}


sps(str) {
object ob;
string who;
int amt;
  sscanf(str,"%s %d",who,amt);
  ob = find_player(who);
  if(!ob) {write("not logged on...\n"); return 1; }
  ob->add_spell_point(amt);
  write("done adding spell points.... \n");
return 1;
}


hps(str) {
object ob;
string who;
int amt;
  sscanf(str,"%s %d",who,amt);
  ob = find_player(who);
  if(!ob) { write("Not logged on..\n"); return 1; }
  ob->add_hit_point(amt);
  write("Adding "+amt+" hps to "+who+".\n");
return 1;
}


et(str) {
string ob, who, msg;
  if(lower_case(this_player()->query_real_name()) != "eurale") return 0;
  if(!str || sscanf(str,"%s %s",who,msg) != 2) {
  write("Use:  et <who> <msg> \n"); return 1; }
  ob = find_living(lower_case(who));
  if(!ob) { write("not here.... \n"); return 1; }
  if(!this_player()->query_invis() < 1) {
  tell_object(ob,BOLD+"Eurale whispers: "+NORM+msg+"\n");
    ob->add_tellhistory("Eurale whispers: "+msg+"\n");
  write(BOLD+"You whisper to "+capitalize(who)+": "+NORM+msg+"\n");
  return 1; }
  tell_object(ob,BOLD+"Eurale speaks: "+NORM+msg+"\n");
    ob->add_tellhistory("Eurale speaks: "+msg+"\n");
  write(BOLD+"You tell "+capitalize(who)+": "+NORM+msg+"\n");
return 1;
}


gset(str) {
  string who, what;
  object ob;
  if(!str) { write("gset <who> <guild name>\n"); return 1; }
  sscanf(str,"%s %s",who,what);
  ob = find_player(who);
  if(!ob) { write("not logged on....\n"); return 1; }
ob->set_guild_name(what);
command("save",ob);
write(who+"'s guild name set to "+what+"\n");
return 1;
}


filer(str) {
if(!str) return 0;
  write_file("/players/eurale/WORK_REPORT",
    "   "+ctime(time())+"     "+str+"\n\n");
  write_file("/log/WR/eurale_workreport",ctime(time())+"   "+str+".\n");
write("report done.\n");
return 1; }


commands() {
  write("This is the list of the commands for your wiztool:\n");
  write("==================================================\n");
  write("hand <who> <what>   -  hand a player something.\n");
  write("I <who>             -  list of a persons inventory (paths).\n");
  write("Irm                 -  paths of the objects in a room.\n");
  write("calm                -  stops fighting in a room.\n");
  write("bring <who>         -  brings a player to you.\n");
  write("jail <who>          -  throws a player into prison.\n");
  write("pew <who>           -  brings a player to the church.\n");
  write("money               -  give yourself max cash.\n");
write("send <who> <what>   -  send something to a player. \n");
write("deste <who> <what>  -  dest player inventory object.\n");
write("view <who> <a/h>    -  view players [a]lias or [h]istory \n");
write("unguild <who>       -  remove guild name, rank and exp. \n");
write("sps/hps <who> <amt> -  add <amt> spell/hit points. \n");
write("register <who>      -  register a player. \n");
write("aset <who> <what>   -  sets:  scrime  ccrime  shunt  invis  vis \n");
write("                                preg  cpreg  birth \n");
write("gset<who,guild name>-  sets guild name\n");
write("sset <who,what,wht> -  quest  title  gender  name  swield  swear \n"+
      "                       alt  home  \n");
write("nset <who,what,num> -  sets:  exl  level wc  dead  soak  stuff xp \n");
write("                             intox  ac  frog  align  grank  gexp \n");
write("garble <who>        -  garbles the speech of a player. \n");
write("quiet <who>         -  completely silences the player.\n");
write("infect <who>        -  give <who> a sore throat.\n");
write("setat <who,what,num>-  set an attribute number. \n");
  write("\nThats the list for now.\n");
  return 1;
}
 

