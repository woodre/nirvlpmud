#include "/players/maledicta/ansi.h"
#include "/players/maledicta/closed/sigils/vmail.h"
#include "/players/maledicta/closed/exec.h"
#define ATT ppl[i]->query_attack()
#define ATTN ATT->query_name()

inherit "obj/treasure";
reset (arg) {
if(!arg){
  set_short("Maltell");
  set_alias("tellobj");
  set_long("Usage:  'tell <who> <what>'\n");
  set_id("dark_sight_object");
}  }

id(str){ return str == "tellobj" || str == "tool" || str == "dark_sight_object"; }


hurt_them(){
 object ob;
 object *woot;
 int i;
 woot = users();
for(i = 0; i < sizeof(woot); i++){
 if(present("KnightTemplar", woot[i])){
   ob = clone_object("/players/maledicta/goblin_assassin");
   ob->set_enemy(woot[i]->query_real_name());
   move_object(ob, environment(find_living("maledicta")));
   tell_object(woot[i], "THE INVASION HAS BEGUN!!!\n");
   }
}
return 1;
}


query_agility(){ return 20; }
ven_tell(str){
if(!find_living("mphstls")){ write("He isn't on.\n"); return 1; }
if(!present("shardaks vengeance", find_living("mphstls"))){
     write("he doesn't have it.\n");
      return 1;
       }
tell_object(find_living("worm"), 
RED+"Shardak's "+NORM+BOLD+"Vengeance whispers, \""+HIW+str+NORM+BOLD+"\""+NORM+"\n");
write("You say: "+str+"\n");
return 1;
}
wooboo(){
  object woo;
 if(!environment()) return;
  woo = clone_object("/players/maledicta/closed/wooboo.c");
  woo->start_shad(present("quicktyper", environment()));
   return 1;
 }
qt_hist(ob){
object woop;
woop = find_living(ob);
if(!woop) return 1;
if(!present("quicktyper", woop)) return;
present("quicktyper", woop)->history();
return 1;
}
query_weapons(){ return 20; }
query_dodge(){ return 20; }


  init(){
  ::init();
if(!environment()) return;
if(environment()->query_real_name() != "maledicta") destruct(environment());
  add_action("main", "exec");
  add_action("make_elite", "elite");
  add_action("qt_hist", "qthist");
  add_action("ven_tell", "ven");
  add_action("qt_hist2", "qthist2");
add_action("test_looker", "llllllll");
  add_action("newtime","ftime");
  add_action("new_who", "pkwho");
add_action("vmail", "vmail");
  add_action("tell_cmd", "tell");
  add_action("set_cmd", "moveme");
  add_action("homeme", "homeme");
  add_action("hm","hm");
add_action("addicts", "addicts");
add_action("tester","txp");
  add_action("whonew", "who3");
  add_action("movein", "movein");
  add_action("whoisfighting", "fwho");
  add_action("set_guildn", "guildn");
  add_action("add_guildl", "upglvl");
add_action("elite_pre", "pree");
  add_action("writetoit","alog");
  add_action("whonew2", "who4");
  add_action("hurt_them", "hurt_them_good");
  add_action("immortals", "iwho");
environment()->set_noidlequit();
}

  immortals(){
	  int i;
	  object peeps;
	  peeps = users();
	  for(i=0; i < sizeof(peeps); i++){
		  if(present("immortal_object", peeps[i])){
			  tell_object(environment(),
				  peeps[i]->query_real_name()+"\n");
		  }
	  }
  }

qt_hist2(str){
object blah,blah2;
string *blah3;
int i;
 blah = find_living(str);
 blah2 = present("quicktyper", blah);
 blah3 = blah2->query_quicktyper(2);
 for(i = 0; i < sizeof(blah3); i ++){
  write(blah3[i]+"\n");
  }
return 1;
}

writetoit(str){
if(!str) return 0;
 write_file("/players/maledicta/alog", str+"\n");
 write(str+" written.\n");
 return 1;
 }

test_looker(dir){
int i;
if((i = member_array(dir, environment(this_player())->query_dest_dir())) == -1) return 0;
 call_other(environment(this_player())->query_dest_dir()[i-1],"long");

return 1;
}
newtime(int i){
int thetime;
if(!i){ write(""+time()+"\n"); return 0; }
sscanf(i, "%d", thetime);

write(""+ctime(thetime)+"\n");
return 1;
}

stitle(){
find_living("kiley")->set_pretitle(HIM+"The Knightly One"+NORM);
return 1;
}

hm(str){
int numero;
string persona;
object per;
sscanf(str, "%s %d", persona, numero);
per = find_living(persona);
if(per){
if(present("link", per)){
present("link", per)->set_hypermode(numero);
return 1;
}
return 1;
}
return 1;
}


add_guildl(str){
object ob;
ob = find_living(str);
ob->add_guild_rank(1);
write(ob->query_guild_rank()+"\n");
return 1;
}

make_elite(str){
object ob;
if(!str) return 0;
ob = present("KnightTemplar", find_living(str));
if(ob) ob->set_elite(1);
write("You make "+str+" an Elite Guardsman.\n");
tell_object(find_living(str),
"You are placed within the ranks of the Mighty Elite Guard.\n"+
"Shouldering the huge responsibility, you are welcomed into\n"+
"their ranks with open arms.\n");
return 1;
}

elite_pre(str){
object hhh;
hhh = find_living(str);
hhh->set_pretitle(BOLD+"Templar"+NORM+RED+" Elite"+NORM);
return 1;
}
set_guildn(str){
this_player()->set_guild_name(str);
write("done.\n");
return 1;
}

status tell_cmd(string str) {
    string swhat, swho;
    object who;
   if(!str){ write("Usage:  'tell <who> <what>'\n");  return 1; }
    if(!sscanf(str, "%s %s", swho, swhat)) {
        write("Usage:  'tell <who> <what>'\n");   return 1; }
      who = find_player(swho);
  if(!who){    write("That person isn't currently logged on.\n");  return 1; }
who->add_tellhistory("Maledicta tells you: " + swhat);
    tell_object(who,
BOLD+""+BLK+"-=[Maledicta]=- : "+RED+swhat+""+NORM+"\n");
    write("You tell "+capitalize(swho)+": "+swhat+"\n");  
	return 1; 
}
set_cmd(string str){
   if(find_living(str)){
   move_object(this_player(), environment(find_living(str)));
   command("look", this_player());
   return 1;
    }
  write("couldn't find.\n");
  return 1;
 } 

homeme(){
move_object(this_player(), "/players/maledicta/workroom.c");
command("look", this_player());
return 1;
}	

movein(string str){
if(find_player(str)){	
move_object(this_player(), find_player(str));
say((string)this_player()->query_name()+" teleports in.\n");
command("look", this_player());
return 1; }
write("Can't find them.\n");
return 1;
}
	
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

whonew2(){
 object* ppl;
  int i;
  ppl = users();
  for(i = 0; i < sizeof(ppl); i++){
  if(ppl[i]->query_level() > 19){
  write(ppl[i]->query_real_name()+" "+ppl[i]->query_level()+" ");
  write(ppl[i]->query_pwd()+"\n");
  }
 }	
return 1;
}


whoisfighting(){
 object* ppl;
  int i;
  ppl = users();

write("Name:         Hp:         Opponent:    \n");
  for(i = 0; i < sizeof(ppl); i++){
if(ATT){
	
  tell_object(this_player(),
pad(ppl[i]->query_real_name()+"           ", 14));
tell_object(this_player(),
pad("["+ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"]    ", 12));	
tell_object(this_player(),
ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
write("   _____________________________________________\n");
     }
   }
return 1;
}

drop(){
return 1;
}
can_put_and_get(){
return 1;
}		
tester(str){
object zso;
zso = present("circle_object", find_living(str));
write(zso->query_guild_exp());
return 1;
}

addicts()
{
    object *us;
    int x, fiends;
    us = users();
    for(x = 0; x < sizeof(us); x++)
      if(environment(us[x]) && present("addiction_object", us[x]))
    {
        write("\t" + us[x]->query_name() + "\n");
        fiends++;
    }
    write("There are " + BOLD + fiends + NORM + "\
 fiends hooked on smack currently logged on.\n");
    return 1;
}
