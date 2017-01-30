#include "../defs.h"
#define BAR OFF+"        <----------------------------------------------------------->\n"+OFF
string listeners;
string members;
string history;
int num_listeners;
int num_members;

reset(arg){
    if(arg) return;
  num_listeners = 0;
  listeners = ({});
  members = ({ });
  history = ({ });
}

resetchannel(){
int i,n;
object *ppl,gob;
ppl = users();
num_listeners = num_members = 0;
listeners = members = ({});
/* modified by illarion - 2 dec 2004
   an error was preventing players from quitting
   */
for (i=0,n=sizeof(ppl); i<n; i++){
    if((gob=present(GUILD_ID,ppl[i]))){
      members += ({ ppl[i]->query_real_name(), });
      if(!gob->query_muffled()) {
        listeners+=({ ppl[i]->query_real_name() });
        num_listeners++;
      }
      num_members++;
    }
}
/*
for (i=0,n=sizeof(members); i<n; i++){
    if(present(GUILD_ID,find_player(members[i]))->query_muffled() != 1){
       listeners += ({ members[i], });
    num_listeners++;
    }
}
*/
}

force_tell_guild(str,arg){
int i;
object necro;
for(i=0;i<sizeof(members);i++){
necro = find_player(members[i]);
if(necro){
 tell_object(necro,str);
}
    }
if(!arg){
addhistory(str);
}
return 1;
}

tell_guild(str,arg){
int i;
object necro;
for(i=0;i<sizeof(listeners);i++){
necro = find_player(listeners[i]);
if(necro){
 tell_object(necro,str);
}
    }
if(!arg){
addhistory(str);
}
return 1;
}

create_say(object necro,string str){
string msg;
string verb;
string lastchar;
lastchar = str[strlen(str)-1];
switch(lastchar){
case '?': verb = "asks"; break;
case '!': verb = "exclaims"; break;
default:  verb = "says"; break;
}

msg = NECRO+necro->query_name()+" "+verb+", \""+NORM+str+OFF+"\"\n"+NORM;
if( (necro->query_real_name() == OWNERRN || necro->query_real_name() == ALTSPIRITS) && necro->query_invis() > 20){
  switch(lastchar){
  case '?': verb = "ask"; break;
  case '!': verb = "exclaim"; break;
  default:  verb = "say"; break; 
  }
  msg = NECRO+BOLD+"The Spirits "+OFF+verb+", \""+NORM+str+OFF+"\"\n"+NORM;
}
tell_guild(msg);
}

create_emote(object necro,string str){
string em, arg, file;
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
    
    if(sscanf(str, "%s %s", em, arg) != 2) {
      em = str;
    }
    em = implode(explode(em, "."), "");
    if(file_size(file="/bin/soul/_"+em+".c") > 0) {
      return (int)file->guildcast("necromancer", arg);
    }
msg = NECRO+necro->query_name()+" "+str+"\n"+NORM;
if( (necro->query_real_name() == OWNERRN || necro->query_real_name() == ALTSPIRITS) && necro->query_invis() > 20){
  msg = NECRO+BOLD+"The Spirits "+OFF+str+"\n"+NORM;
}
tell_guild(msg);
}

create_echo(object necro,string str){
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
msg = NECRO+str+" ("+OFF+necro->query_name()+OFF+")\n"+OFF;
if( (necro->query_real_name() == OWNERRN || necro->query_real_name() == ALTSPIRITS) && necro->query_invis() > 49){
  msg = NECRO+str+"\n"+OFF;
}
tell_guild(msg);
}

create_think(object necro,string str){
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
msg = NECRO+necro->query_name()+" . o O ("+NORM+str+OFF+")\n"+NORM;
if( (necro->query_real_name() == OWNERRN || necro->query_real_name() == ALTSPIRITS) && necro->query_invis() > 20){
  msg = NECRO+BOLD+"The Spirits "+OFF+" . o O ("+NORM+str+OFF+")\n"+NORM;
}
tell_guild(msg);
}


guildwho(){
object mage,guildob;
int i;
int n;
int seenmembers;
string msg;
string name;
msg = "\t<"+HIR+"Necromantic Guild Who"+OFF+">------------------------------------->\n";
msg += BOLD+BLK+"       Name         Level  Gender   Line    Hp    Sp       Oppt\n"+NORM;
members = sort_array(members,"greater_fun",this_object());
seenmembers = 0;
for(i=0,n=sizeof(members);i<n;i++){
mage = find_player(members[i]);
if(mage){
guildob = present(GUILD_ID,mage);
if(!guildob){ 
  members -= ({ mage });
  mage = 0;
}
}
if (mage && mage->query_interactive() && (mage->query_real_name() != OWNERRN) ){
  if(mage->query_invis() < this_player()->query_level()){ 
      seenmembers++;
      msg += " ";
  if(in_editor(mage) && (this_player()->query_level() > 20) )
      msg += HIM+"]"+OFF;
      else
      msg += " ";
    if(mage->query_dead())
      msg += HIY+"*"+OFF;
      else
      msg += " ";
    if(mage->query_invis())
      msg += HIB+"*"+OFF;
      else
      msg += " ";
    if(environment(mage) && environment(mage)->realm() == "NT")
      msg += HIB+"X"+OFF;
      else
      msg += " ";
    if(query_idle(mage) > 300)
      msg += BOLD+"i"+OFF;
      else
      msg += " ";
    if(mage->query_fight_area())
      msg += HIR+"*"+OFF;
      else
      msg += " ";
    name = cutstring(mage->query_name(),12);
    if(mage->query_pl_k())
      name = HIR+name+OFF;
  msg += name+" ";
  if(mage->query_level() > 20)
  msg += BOLD+"wiz  "+OFF;
  else{
  msg += cutstring(mage->query_level(),2);
  if(mage->query_extra_level())
  msg += "+"+cutstring(mage->query_extra_level(),2);
  else
  msg += "   ";
  }
  msg += "  ";
  msg += cutstring(mage->query_gender(),6);
  msg += "   ";
  if(guildob->query_muffled())
  msg += "deaf";
  else
  msg += "on  ";
  msg += "   ";
  msg += cutstring(((mage->query_hp()*100)/(mage->query_mhp()*10))+"/10",6);
  msg += " ";
  msg += cutstring(((mage->query_sp()*100)/(mage->query_msp()*10))+"/10",6);
  msg += "   ";
  if(mage->query_attack())
  msg += cutstring(mage->query_attack()->query_name(),13)+" "+OFF;
  msg += "\n";
  }
 } 
}
msg += BOLD+BLK+"       There are currently "+HIR+seenmembers+OFF+BOLD+BLK+" members online\n"+OFF; 
msg += BAR;
write(msg+NORM);
}

on_channel(){
string msg;
int i,a;
object mage,guildob;

  msg = BOLD+BLK+"The members on the Necro Channel are "+OFF; 
  for(i=0,a=sizeof(members);i<a;i++){
    mage = find_player(members[i]); 
    if(mage){
    guildob = present(GUILD_ID,mage);
    if(!guildob){ 
      members -= ({ mage[i] });
      mage = 0;
    }
    }
    if(mage){
      if(mage->query_invis() < this_player()->query_level()){ 
        if(!guildob->query_muffled()){
          if(i == 0) 
            msg += mage->query_name();
          else{ 
            if(i == (a-1))
             msg += " and "+mage->query_name();
            else
             msg += ", "+mage->query_name();
          }
        }
      }
    } 
  }
  write(msg+".\n");
}
    
addhistory(str){
  if(sizeof(history) == 20){
    history -=({ history[0] });
  }
  str = str[18..strlen(str)];
  str = "       <"+HIR+"n"+OFF+">"+str;
  history += ({ str, });
}

viewhistory(){
  int i,a;
  string msg;
  msg = "\n";
  msg += "\t<"+HIR+"Necromantic Channel History"+OFF+">------------------------------->\n";
  for(i=0,a=sizeof(history);i<a;i++){
    msg += history[i];
  }
  msg += BAR;
  write(msg); 
 return 1;
}

cutstring(str,i){
str = str +"                                ";
str = str[0..i-1];
return str;
}

greater_fun(string o,string t){
object one,two;
one = find_player(o);
two = find_player(t);
if(!one || !two) return;
if(one->query_level() == two->query_level()) 
  return one->query_extra_level() < two->query_extra_level();
else
  return one->query_level() < two->query_level();
}

query_tag() {
  return NECRO;
}

query_listeners() {
  return listeners;
}

