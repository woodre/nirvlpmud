
id(str){ return str == "modamine" || str == "mine"; }
string who;
object target;
int set, armed;
get(){ return 0; }
value(){ return 10000; }

init(){
     add_action("set","set");
     add_action("unset","unset");
     add_action("drop","drop");
     set_heart_beat(1);
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
     write("Remember that once dropped the mine cannot be picked up.\n");
     write("This particular mine does:\n");
     write("Heavy damage to player it is set to.\n");
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
       target->add_hit_point(-150);
       destruct(this_object());
       return 1;
}
}
}
