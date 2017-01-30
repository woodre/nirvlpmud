#include <ansi.h>
#define jedi environment(previous_object())
#define level this_player()->query_guild_rank()
#define dark previous_object()->query_darkside()
#define pre jedi->query_pretitle()
#define name jedi->query_name()
#define title jedi->query_title()

main(){

if(level <= 4 && !dark){
  jedi->set_title(" ["+HIG+"padawan apprentice"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }
if(level <= 8 && !dark){
  jedi->set_title(" ["+HIG+"jedi knight"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }  
if(level <= 12 && !dark){
  jedi->set_title(" ["+HIG+"jedi"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }  
if(level >= 13 && !dark){
  jedi->set_title(" ["+HIG+"jedi master"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }  
if(level <= 4 && dark){
  jedi->set_title(" ["+HIR+"dark apprentice"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }  
if(level <= 8 && dark){
  jedi->set_title(" ["+HIR+"jedi assassin"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
}
if(level <= 12 && dark){
  jedi->set_title(" ["+HIR+"jedi"+NORM+"]");
  jedi->set_guild_name("jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
}
if(level >= 13 && dark){
  jedi->set_title(" ["+HIR+"jedi master"+NORM+"]");
  jedi->set_guild_name("Jedi");
  tell_object(jedi,
  "You are now: "+pre+" "+name+" "+title+"\n"+ 
  "You reveal yourself to the world as a Jedi.\n");
  return 1;
  }	 	  
return 1;
}
