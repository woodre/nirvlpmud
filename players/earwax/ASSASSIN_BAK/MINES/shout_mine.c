
id(str){ return str == "shoutmine" || str == "mine"; }
string message;
string who;
object target;
int set, armed;
get(){ return 0; }
value() { return 300; }
query_value(){ return 600; }

init(){
     add_action("set","set");
     add_action("unset","unset");
     add_action("drop","drop");
     add_action("message", "message");
     set_heart_beat(1);
}

message(str){ 
      message = str;
      write("Mine message set to: "+str+"\n");
      return 1;
}
set(str){
     target = find_player(str);
     if(!str){
       write("Usage: set <player>\n");
       return 1;
     }
     if(set == 0){
     write("Land mine set for "+target->query_name()+".\n");
     set = 1;
     return 1;
     }
     if(set == 1){
       write("Land mine already set for someone.\n");
       return 1;
     }
}
short() {return "A land mine"; }
long(){
     write("This is a land mine.  To operate, here are the commands:\n");
     write("set <player>          sets which player will set off the mine.\n");
     write("unset                 unsets the mine.\n");
      write("drop mine             arms the mine and drops it in the room.\n");
      write("message <message>     sets a the mine's message when it goes off.\n");
     write("Remember that once dropped the mine cannot be picked up.\n");
     write("This particular mine does:\n");
      write("Shouts a message set by you when tripped off.\n");
}

unset(){
     if(set == 0){
       write("Land mine has not been set.\n");
       return 1;
     }
     if(set == 1){
       write("Land mine disarmed.\n");
      set = 0;
       return 1;
     }
}

drop(str){
     if(str == "mine"){
     if(set == 0){
       write("You can't just go around dropping land mines randomly!\n");
       return 1;
     }
     if(set == 1){
       write("Land mine set and armed.\n");
      armed = 1;
       return 1;
     }
}
}
heart_beat(){
     object victim, here;
     here = environment(this_object());
     if(set == 1 && armed == 1){
     victim = present(target, environment(this_object()));
     if(victim){
       tell_object(target, "You feel the force of a land mine blast!\n");
       tell_room(here, 
       capitalize(target->query_name())+" is blasted by a land mine!\n");
       }
       if(message){
          shout("A land mine shouts: "+message+"\n");
         destruct(this_object());
         return 1;
       }
       else
       shout(capitalize(target->query_name())+" is so stupid that he  \n");
       shout("tripped on a land mine!\n");
       destruct(this_object());
       return 1;
}
}
