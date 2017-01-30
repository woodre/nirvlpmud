#include "/players/wren/ansi.h"
#define TP this_player()

query_weight() {return 0;}
query_value() {return 0;}
drop() {return 1;}
get() {return 1;}

int block;

id(str) {
    return str == "wrentell_object" || str == "wtell" || str == "wren_phone";
         }

extra_look() {
       if(environment() == this_player())
            write("You feel Wren's presence through a 'wren_phone'.\n");
       else
            write(environment()->query_name() +"is in contact with higher powers.\n");
       }

long() {
    write(
       "Direct connection to Wren. Use 'wt <message>' to \n"+
       "talk to him. Message will go through even if he isn't \n"+
       "able to respond immediately or has scarpered. \n");
    return 1;
     }

init() {
   if(!environment()) return;
   add_action("tell_wren","wt");
       }

tell_wren(str){
  if(!str){ write("wt <message> -or- wt :<emote>\n"); return 1; }
  if(find_living("wren")){
    if(str[0] == ':'){
     tell_object(find_living("wren"), HIR+"(EMOTE)"+TP->query_real_name()+" "+str[1..(strlen(str) -1)]+NORM+"\n");
    find_living("wren")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
    write(HIB+"<EMOTE>"+NORM+" You "+str[1..(strlen(str) -1)]+"\n");
    }
    else{
    tell_object(find_living("wren"), HIR+TP->query_real_name()+" tells you: "+str+NORM+"\n");
    find_living("wren")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
    write(HIB+"<>"+NORM+" You tell Wren: "+str+"\n");
    }
    }
else{ write_file("/players/wren/closed/wt", TP->query_real_name()+" :: "+str+" <--> "+ctime(time())+".\n"); }
  return 1;
  }



