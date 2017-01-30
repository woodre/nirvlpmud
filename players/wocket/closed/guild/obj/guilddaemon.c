#include "/players/wocket/closed/ansi.h"

object listeners;
object members;
int num_listeners;
int num_members;

reset(arg){
    if(arg) return;
  num_listeners = 0;
  listeners = ({});
  members = ({ });
}

resetchannel(){
int i,n;
object *ppl;
ppl = users();
num_listeners = num_members = 0;
listeners = members = ({});

for (i=0,n=sizeof(ppl); i<n; i++){
    if(present("oriekagob",ppl[i])){
      members += ({ ppl[i], });
      num_members++;
    }
}

for (i=0,n=sizeof(members); i<n; i++){
    if(present("oriekagob",members[i])->query_muffled() != 1){
       listeners += ({ members[i], });
    num_listeners++;
    }
}

}

tell_guild(str){
int i;
for(i=0;i<sizeof(listeners);i++){
if(listeners[i]){
  if(listeners[i] == this_player()){
  tell_object(listeners[i],"Your orieka whispers to the others:\n");
  }
  else
  tell_object(listeners[i],this_player()->query_name()+"'s orieka voice whispers in your ear:\n");
    tell_object(listeners[i],str);
}
    }
return 1;
}

create_say(str){
string msg;
msg = "\t";
msg += MAG+this_player()->query_name()+" says, \""+NORM+str+MAG+"\"\n"+NORM;
tell_guild(msg);
}


guildwho(){
object om;
int i;
int n;
string msg;
msg = MAG+"Orieka masters -\n";
for(i=0,n=sizeof(members);i<n;i++){
om = members[i];
  msg += om->query_name()+"\t"+om->query_level()+"\n";
  }
write(msg+NORM);
}
