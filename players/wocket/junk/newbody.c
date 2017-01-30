#include "/players/wocket/closed/ansi.h"
inherit "/obj/living.c";
string who;

id(str){ return str == "newbody"; }
short(){ return "newbody of "+who; }


new_soul(str){
  who = str;
  enable_commands();
  add_commands();
}

add_commands(){
  add_action("look","look");
  add_action("say","say");
}

look(){
object ob,next;
object env;
env = environment(this_object());
 env->long();
ob = first_inventory(env);
while(ob){
  next = next_inventory(ob);
  write(ob->short()+"\n");
  ob = next;
}
}

say(str){
  write("You say: "+str+"\n");
  say("Neo"+who+" says: "+str+"\n");
return 1;
}
