#include "/players/wocket/closed/ansi.h"

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
object *ppl;
ppl = users();
num_listeners = num_members = 0;
listeners = members = ({});

for (i=0,n=sizeof(ppl); i<n; i++){
    if(present("mageguildob",ppl[i])){
      members += ({ ppl[i]->query_real_name(), });
      num_members++;
    }
}

for (i=0,n=sizeof(members); i<n; i++){
    if(present("mageguildob",find_player(members[i]))->query_muffled() != 1){
       listeners += ({ members[i], });
    num_listeners++;
    }
}

}

force_tell_guild(str){
int i;
object mage;
for(i=0;i<sizeof(members);i++){
mage = find_player(members[i]);
if(mage){
 tell_object(mage,str);
}
    }
addhistory(str);
return 1;
}

tell_guild(str){
int i;
object mage;
for(i=0;i<sizeof(listeners);i++){
mage = find_player(listeners[i]);
if(mage){
 tell_object(mage,str);
}
    }
addhistory(str);
return 1;
}

create_say(object mage,string str){
string msg;
string verb;
string lastchar;
lastchar = str[strlen(str)-1];
switch(lastchar){
case '?': verb = "asks"; break;
case '!': verb = "exclaims"; break;
default:  verb = "says"; break;
}

msg = MAG+"("+HIR+"*"+NORM+MAG+") "+mage->query_name()+" "+verb+", \""+NORM+str+MAG+"\"\n"+NORM;
tell_guild(msg);
}

create_emote(object mage,string str){
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
msg = MAG+"("+HIR+"*"+NORM+MAG+") "+mage->query_name()+" "+str+"\n"+NORM;
tell_guild(msg);
}

create_echo(object mage,string str){
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
msg = MAG+"("+HIR+"*"+NORM+MAG+") "+str+" ("+NORM+mage->query_name()+MAG+")\n"+NORM;
tell_guild(msg);
}

create_think(object mage,string str){
string msg;
int i;
i = strlen(str)-1;
str = str[1..i];
msg = MAG+"("+HIR+"*"+NORM+MAG+") "+mage->query_name()+" . o O ("+NORM+str+MAG+")\n"+NORM;
tell_guild(msg);
}


guildwho(){
object mage;
int i;
int n;
string msg;
string name;
msg = MAG+"\n        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM;
msg += MAG+"       Name         Level  Gender   Line    Hp    Sp       Oppt\n"+NORM;
members = sort_array(members,"greater_fun",this_object());
for(i=0,n=sizeof(members);i<n;i++){
mage = find_player(members[i]);
if (mage){
  if(mage->query_invis() < this_player()->query_level()){ 
     msg += "  ";
  if(in_editor(mage))
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
  if(present("mageguildob",mage)->query_muffled())
  msg += "deaf";
  else
  msg += "on  ";
  msg += "   ";
  msg += ((mage->query_hp()*100)/(mage->query_mhp()*10))+"/10";
  msg += " ";
  msg += ((mage->query_sp()*100)/(mage->query_msp()*10))+"/10";
  msg += "   ";
  if(mage->query_attack())
  msg += cutstring(mage->query_attack()->query_name(),13)+" "+OFF;
  msg += "\n";
  }
 } 
}
msg += MAG+"       There are currently "+HIR+sizeof(members)+OFF+MAG+" members online\n"; 
msg += MAG+"        [-----------------------------["+HIR+"*"+OFF+MAG+"]-----------------------------]\n"+OFF;
write(msg+NORM);
}

addhistory(str){
  if(sizeof(history) == 20){
    history = history[1..19];
  }
  str = str[29..strlen(str)];
  str = "       [*]" +MAG+str;
  history += ({ str, });
}

viewhistory(){
  int i,a;
  string msg;
  msg = "\n";
  msg += MAG+"        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM;
  for(i=0,a=sizeof(history);i<a;i++){
    msg += history[i];
  }
  msg += MAG+"        [-----------------------------["+HIR+"*"+NORM+MAG+"]-----------------------------]\n"+NORM;
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
