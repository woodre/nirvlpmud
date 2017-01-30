#include "/players/wocket/closed/ansi.h"
cmd(str){
 object ob;
  string who;
  string msg;
  if(!str || sscanf(str,"%s %s",who,msg) != 2){
  write("Tell what to who?\n");
  return 1;
  }
  who = lower_case(who);
  ob = find_player(who);
  if(!ob) ob = find_living(who);
  if(!ob){
    write("That player is not logged on.\n");
    return 1;
  }
  if(ob->query_invis() >= 39){
    write("That player is not logged on.\n");
    return 1;
  }
  if(in_editor(ob)){
    write("That person is editing.  Please try again latter.\n");
    return 1;
  }
  if(ob->query_tellblock()){
    write("That person is blocking tells.  Please try again later.\n");
    return 1;
  }
  if(this_player()->query_tellblock()){
    write("You may not use tell while your tellblock is on.\n");
    return 1;
  }
  if(query_idle(ob) > 120){
  write(capitalize(who)+" is idle at the moment and may not respond right away.\n");
  }
  ob->add_tellhistory(this_player()->query_name()+" told you, \""+msg+"\"");
  tell_object(ob,this_player()->query_name()+" tells you, \""+msg+"\"\n");
  write("You tell "+capitalize(who)+", \""+msg+"\"\n");
  return 1;
}
