#include "/players/maledicta/ansi.h"
#define TP this_player()

query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }

int block;

id(str){
   return str == "maltell_object" || str == "maltell";
}

query_auto_load(){ return "/players/maledicta/maltell.c:"; }

extra_look(){ return environment()->query_name()+" has a [maltell]"; }


long(){
   write(
      "This is a private line to Maledicta. Use mt <message> to\n"+
      "talk to him. The message will go through whether he is on\n"+
      "or not. Maledicta will respond if he is able too.\n");
   return 1;
}

init(){
   if(!environment()) return;
   add_action("tell_mal", "mt");
   }

tell_mal(str){
  if(!str){ write("mt <message> -or- mt :<emote>\n"); return 1; }
  if(find_living("maledicta")){
    if(str[0] == ':'){
     tell_object(find_living("maledicta"), HIR+"(EMOTE)"+TP->query_real_name()+" "+str[1..(strlen(str) -1)]+NORM+"\n");
    find_living("maledicta")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
    write(HIB+"<EMOTE>"+NORM+" You "+str[1..(strlen(str) -1)]+"\n");
    }
    else{
    tell_object(find_living("maledicta"), HIR+TP->query_real_name()+" tells you: "+str+NORM+"\n");
    find_living("maledicta")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
    write(HIB+"<>"+NORM+" You tell Maledicta: "+str+"\n");
    }
    }
else{ write_file("/players/maledicta/closed/mt", TP->query_real_name()+" :: "+str+" <--> "+ctime(time())+".\n"); }
  return 1;
  }
