#include "std.h"

reset(arg){
   


      if(arg)
        return 0;
      set_light(1);
      
}

short(){
  
   return "Hagbard's prison";
}


long(){

   write("You are in Hagbard's prison.  There are NO exits.  Only the\n");
   write("Great Hagbard can release you, if you are lucky.  You must\n");
   write("have done something terrible to get yourself put in here.\n");
}





init(){
  if(call_other(this_player(),"query_real_name",0) == "hagbard") {
    add_action("home");      add_verb("home");
    add_action("getpl");     add_verb("getpl");
    add_action("release");   add_verb("release");
    }
   add_action("quit");       add_verb("quit");
   add_action("dest");       add_verb("dest");
   add_action("dest");       add_verb("destruct");
   add_action("home");       add_verb("home");
   add_action("laugh");       add_verb("clone");
   add_action("goto");       add_verb("goto");
   add_action("shout_in");      add_verb("shout");
   add_action("tell_in");       add_verb("tell");
}





dest(str) {
  object fool;
  string foolname;

  fool = this_player();
  foolname = fool->query_real_name();
  if(foolname == "hagbard")
    return 0;
  else
      return 1;
    return 1;
}
 

laugh(){

  return 1;
}
 

goto(){

  return 1;
}


home(){


    if(call_other(this_player(), "query_real_name",0) == "hagbard")
      return 0;
  return 1;
}

quit(){
  
   return 1;
}


shout_in(){

   return 1;
}


tell_in(){

  return 1;
}
getpl(str){

    string who;

    if(sscanf(str, "%s", who) != 1)
      write("Who!!\n");
    if(!find_player(who))
      write(who + " is not playing now.\n");
    else {
    tell_object(find_player(who), "You have been imprisoned by Hagbard.\n");
    transfer(find_player(who), "players/hagbard/hagsprison");
    }

}



release(str){

    string who;
  
    if(sscanf(str, "%s" , who) != 1)
       write("Who!!\n");
    if(!present(who))
      write(who + " is not in prison now.\n");
    else {
    tell_object(find_player(who), "Hagbard has sent you to the church so\n"
                +  "that you can pray for your soul for what ever it was\n"
                +  "that you did to upset Hagbard.\n");

    transfer(find_player(who), "room/church");
    }
    return 1;
}
