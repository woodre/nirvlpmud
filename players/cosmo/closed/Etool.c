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
set_short("A "+HIC+"crystal dragon's orb"+NORM);
set_long(
	"  This crystal orb was forged by Eurale himself after studying \n"+
	"the ways of -The Hunter- for a great deal of time.  It incorp - \n"+
	"orates the power of the fae with vast knowledge of it's use. \n"+
	"Use it's power wisely.... \n\n"+
"Places:  church  lockers  post  dmage  gulch  portal park  fantasy \n"+
"         board  test  fiend  keep  xxx \n"+
"\n"+
"Commands:  hentai  force  hand  I  Irm  calm  bring  jail  pew  heal \n"+
"           money  get!  drop!  goin  place  send  deste  shand  setat \n"+
"           view  zap  unguild  ID  register  sset  garble  nset  aset \n"+
"           cl  sps  tel  gset  xxx \n"+
"\n");
set_class(100);
set_weight(0);
set_value(0);
}

drop() { return 1; }
query_save_flag() { return 1; }

init() {
  ::init();
  if(epn != "eurale") {
  write("NOT POSSIBLE!! \n");
  destruct(ep);
destruct(this_object());
}

  add_action("church","church");
  add_action("gulch","gulch");
  add_action("lockers","lockers");
  add_action("post","post");
  add_action("dmage","dmage");
  add_action("park","park");
  add_action("fantasy","fantasy");
  add_action("portal","portal");
  add_action("board","board");
  add_action("test","test");
  add_action("fiend","fiend");
  add_action("keep","keep");

  add_action("calm","calm");
  add_action("commands","commands");
  add_action("hand","hand");
  add_action("power_get","get!");
  add_action("power_drop","drop!");
  add_action("goin","goin");
  add_action("money","money");
  add_action("bring_player","bring");
  add_action("dungeon_player","jail");
  add_action("church_player","pew");
  add_action("force","force");
  add_action("inv","I");
  add_action("inv_room","Irm");
  add_action("heal","heal");
  add_action("move_them","place");
  add_action("send","send");
  add_action("deste","deste");
  add_action("shand","shand");
  add_action("setat","setat");
  add_action("view","view");
  add_action("zzap","zap");
  add_action("unguild","unguild");
  add_action("change_id","ID");
  add_action("register","register");
  add_action("sset","sset");
  add_action("garble","garble");
  add_action("nset","nset");
  add_action("chek","chek");
  add_action("cl","cl");
  add_action("aset","aset");
  add_action("sps","sps");
  add_action("tel","tel");
  add_action("gset","gset");
}


/*  ROOM LOCATIONS TO TELEPORT TO   */
church() { Mv,"church#room/church.c"); return 1; }
gulch() { Mv,"gulch#players/eurale/Drygulch/wagon.c"); return 1; }
lockers() {Mv,"lockers#players/catwoman/tl.c"); return 1; }
post() {Mv,"post#room/post.c"); return 1; }
dmage() { Mv,"dmage#players/mythos/closed/guild/assembly.c"); return 1;}
portal() { Mv,"portal#players/saber/ryllian/portal.c"); return 1; }
park() { Mv,"park#players/eurale/Park/jp98.c"); return 1; }
fantasy() { Mv,"fantasy#players/eurale/Dis/rooms/hub.c"); return 1; }
board() { Mv,"board#room/adv_inner.c"); return 1; }
test() { Mv,"test#players/eurale/testroom.c"); return 1; }
fiend() { Mv,"fiend#players/eurale/Fiend/mm1.c"); return 1; }
keep() { Mv,"keep#players/eurale/Keep/k1.c"); return 1; }


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
  write("\nYou pull money out of the air.... \n\n");
  this_player()->add_money(80000);
return 1;
}
 
bring_player(str) {
   object ob;
   string bye, there;
 
   if(!str) return 0;
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
     write (capitalize(str) + " is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob, "The room fades as darkness falls around you\n" +
       "When the light returns you are in a new place\n");
   move_object(ob, environment(this_player()));
   tell_room(there, capitalize(str) +
     " disappears from before you ..You know they were summoned by someone with power\n");
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

heal(str) {
object ob;
string who;
  if(!str) { this_player()->heal_self(100000);
  write("You are completely healed.. \n"); return 1; }

  sscanf(str,"%s",who);
  ob = find_player(who);
  if(!ob) { ob = find_living(ob); }
  if(!ob) { write("not logged on... \n"); return 1; }
  ob->heal_self(100000);
  write("You have healed "+capitalize(who)+".\n");
  tell_object(ob,"A dark mist settles over you..... \n"+
                 "Suddenly, it flows into your body through your mouth \n"+
                 "and nose....... You feel very odd... \n"+
                 "It dissipates and.... You are completely healed. \n");
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
  "Eurale's pet blue demon flies in and hands you something...\n");
  write("Your pet blue demon takes something and flies off...\n");
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
 

send(str) {
  object ob;
  string who,what;
if(!str)
  {write ("You going to do something? \n"); return 1; }
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
  tell_object(find_player(who),"Destroyed: "+what+".\n");
return 1;
}


shand(str) {
object ob;
  string who,what;
  if(!str) {write("hands <who> <what/path> \n"); return 1; }
  sscanf(str,"%s %s",who,what);
  ob = find_player(who);
  if(!ob) {write("not logged on... \n"); return 1; }
  move_object(clone_object(what),ob);
write("You have silently handed "+capitalize(who)+" a "+what+".\n");
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


zzap(str) {
object ob;
  if(!str) return 0;
  ob = present(str,environment(this_player()));
  if(!ob || !living(ob)) { ob = find_living(ob); }
  if(!ob) { write("not here... \n"); return 1; }
  this_player()->zap_object(ob);
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


change_id(str) {
string nme;
  if(!str) { this_object()->set_name("orb");
  write("Name changed back to 'orb'. \n"); return 1; }

if(str == "bard") nme = "instrument";
if(str == "knight") nme = "templar";
if(str == "undead") nme = "life";
if(str == "mage") nme = "mageobj";
if(str == "poly") nme = "Mizan-guild-object";
if(str == "cyber") nme = "implants";
if(str == "vamp") nme = "nooneelse vampire fangs";
if(str == "shardak") nme = "shardak_mark";
if(str != "bard" && str != "mage" && str != "poly" && str != "cyber" &&
	str != "undead" && str != "vamp" && str != "knight" &&
	str != "shardak")
	{ nme = str; }
this_object()->set_name(nme);
this_object()->set_short(CYN+"A crystal orb"+NORM);
  write("Name of Orb is set to "+nme+".\n");
return 1; }
query_on() { return 1; }
query_original() { return 1; }
query_telepathy() { return 1; }


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
if(what == "exl") { ob->set_extra_level(num);
	write("extra level of "+who+" set at "+num+".\n"); return 1; }
if(what == "guild") { ob->set_guild_name(num);
  write("guild name of "+who+" set to "+num+".\n"); return 1; }
if(what == "level") { ob->set_level(num);
	write("level of "+who+" set at "+num+".\n"); return 1; }
if(what == "align") {ob->add_alignment(num);
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
if(what == "frog") { ob->frog_curse(num);
	write("frog of "+who+" set at "+num+".\n"); return 1; }
if(what == "wiz") { ob->set_wiz_level(num);
	write("wiz level of "+who+" set at "+num+".\n"); return 1; }
if(what == "xp") { ob->add_exp(num);
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



cl() {
  command("cat /log/eurale",this_player()); return 1; }


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
if(what == "preg") { ob->set_pregnancy(this_player()->query_name());
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


tel(str) {
string ob, who, msg;
  if(lower_case(this_player()->query_real_name()) != "eurale") return 0;
  if(!str || sscanf(str,"%s %s",who,msg) != 2) {
  write("Use:  tel <who> <msg> \n"); return 1; }
  ob = find_living(lower_case(who));
  if(!ob) { write("not here.... \n"); return 1; }
  if(!this_player()->query_invis() < 1) {
  tell_object(ob,"From the darkness Eurale whispers softly: "+msg+"\n");
  write("You whisper to "+capitalize(who)+": "+msg+"\n");
  return 1; }
  tell_object(ob,"Eurale whispers to you: "+msg+"\n");
  write("You tell "+capitalize(who)+": "+msg+"\n");
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




commands() {
  write("This is the list of the commands for your wiztool:\n");
  write("==================================================\n");
  write("force               -  force a player to do something.\n");
  write("hand <who> <what>   -  hand a player something.\n");
  write("I <who>             -  list of a persons inventory (paths).\n");
  write("Irm                 -  paths of the objects in a room.\n");
  write("calm                -  stops fighting in a room.\n");
  write("bring <who>         -  brings a player to you.\n");
  write("dun <who>           -  throws a player into the town prison.\n");
  write("pew <who>           -  brings a player to the church.\n");
  write("heal                -  heal yourself.\n");
  write("money               -  give yourself max cash.\n");
  write("get! <object>       -  pickup something you normally couldn't.\n");
  write("drop! <object>      -  drop something you normally couldn't.\n");
  write("goin <who>          -  go into someones inventory.\n");
  write("place <who> <where> -  move a player to a certain place.\n");
write("send <who> <what>   -  send something to a player. \n");
write("deste <who> <what>  -  dest player inventory object.\n");
write("shand <who> <what>  -  silently hand a player something. \n");
write("view <who> <a/h>    -  view players [a]lias or [h]istory \n");
write("zap <who>           -  kill a monster. \n");
write("unguild <who>       -  remove guild name, rank and exp. \n");
write("ID <name>           -  change the orb to a guild object <name>. \n");
write("sps <who> <amt>     -  add <amt> spell points. \n");
write("register <who>      -  register a player. \n");
write("aset <who> <what>   -  sets:  scrime  ccrime  shunt  invis  vis \n");
write("                                preg  cpreg  birth \n");
write("gset<who,guild name>-  sets guild name\n");
write("sset <who,what,wht> -  sets: title, gender, name, swield, swear \n");
write("                                      alt, home \n");
write("nset <who,what,num> -  sets:  exl  level wc  dead  soak  stuff xp \n");
write("                             intox  ac  frog  align  wiz \n");
write("garble <who>        -  garbles the speech of a player. \n");
write("setat <who,what,num>-  set an attribute number. \n");
  write("\nThats the list for now.\n");
  return 1;
}
 

