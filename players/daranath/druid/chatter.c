/* Chat lines for the Druid's guild...  same ones I use everywhere else */

#include <ansi.h>

object guild_chat;
object temp;

id(str) { return str == "druid_chatter"; }

reset(arg) { 
  if(arg) return;
  guild_chat = ({0});
  call_out("check",3);
}

check() { if(environment(this_object())) destruct(this_object()); return 1; }

query_guild_chat(int a) { if(!a) a = 0; return guild_chat[a]; } 

query_guild_chat_size() { return sizeof(guild_chat); }

add_membr(object targ) {
  if(member_array(targ,guild_chat) == -1) guild_chat += ({targ});
}

sub_membr(object targ) {
  if(member_array(targ,guild_chat) != -1) guild_chat -= ({targ});
} 

chat_line(string msg,string who,int emote) {
  int a;
    for(a=0;a<sizeof(guild_chat);a++) {
	  if(guild_chat[a]) {
 if(!emote) tell_object(guild_chat[a],"<< "+HIG+"Druid"+NORM+" >> "+who+" says: "+msg+"\n");
else tell_object(guild_chat[a],"<< "+HIG+"Druid"+NORM+" >> "+who+" "+msg+"\n");
	  } 
	}
}

