#include "/players/jareel/ansi.h"
#define TP this_player()

     query_weight(){ return 0; }
     query_value(){ return 0; }
     drop(){ return 1; }
     get(){ return 1; }

     int block;

     id(str){
       return str == "jartell_object" || str == "mark";
}

     query_auto_load(){ return "/players/jareel/toys/telldevice:"; }

     extra_look(){ return environment()->query_name()+" bares the mark of a Luner Hero"; }


     long(){
       write(
         "This is a private line to Jareel. Use jt <message> to\n"+
         "talk to her. The message will go through whether he is on\n"+
         "or not. Jareel will respond if she is able too.\n");
     return 1;
}

     init(){
       if(!environment()) return;
       add_action("tell_jar", "jt");
     }

     tell_jar(str){
       if(!str){ write("jt <message> -or- jt :<emote>\n"); return 1; }
       if(find_living("jareel")){
       if(str[0] == ':'){
         tell_object(find_living("jareel"), HIB+"(EMOTE)"+TP->query_real_name()+" "+str[1..(strlen(str) -1)]+NORM+"\n");
         find_living("jareel")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
           write(HIB+"<EMOTE>"+NORM+" You "+str[1..(strlen(str) -1)]+"\n");
    }
    else{
      tell_object(find_living("jareel"), HIB+TP->query_real_name()+" tells you: "+str+NORM+"\n");
      find_living("jareel")->add_tellhistory(TP->query_real_name()+" tells you: "+str+"\n");
      write(HIB+"<>"+NORM+" You tell Jareel: "+str+"\n");
    }
    }
else{ write_file("/players/jareel/closed/jt", TP->query_real_name()+" :: "+str+" <--> "+ctime(time())+".\n"); }
  return 1;
  }
