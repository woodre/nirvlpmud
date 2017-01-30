/* 
  a reworking of the white rose with permission from balowski
  wocket 6.99
*/

#include "/players/wocket/closed/ansi.h"

string ask_msg;
string accept_msg;

object partner;
object partner_rose;

id(str){ return str == "rose" || str == "white rose"; }
short(){ return BOLD+"@"+OFF+GRN+"}-,-`---"+OFF; }
long(){
  write("This is the white rose.\n");
}

reset(){
}

init(){
  add_action("sex","sex");
  add_action("set_acceptmsg","set_acceptmsg");
  add_action("set_askmsg","set_askmsg");
  accept_msg = this_player()->query_name()+" whispers to you, \"I'm yours.\"\n";
  ask_msg = this_player()->query_name()+" whispers to you, \"I want you.\"\n";
}

sex(str){
  if(!str){
    notify_fail("Who would you like to have sex with?\n");
  }
  if(str == "yes"){
    if(!partner){
      notify_fail("Who are you having sex with?\n");
      return 0;
    }
    if(partner && environment(partner) == environment(this_player()) && !partner->query_invis()){
      tell_object(partner,accept_msg+"\n");
      write(accept_msg+"\n");
      if(this_player()->query_gender() == "male" && partner->query_gender() == "female" && random(100) < 15){
        partner->set_pregnancy();
        tell_object(partner,BOLD+"You are pregnant.\n"+OFF);
      }
      if(this_player()->query_gender() == "female" && partner->query_gender() == "male" && random(100) < 15){
        this_player()->set_pregnancy();
        write(BOLD+"You are pregnant.\n"+OFF);
      }
      return 1;
    }
    else{
      write("That person is not here to have sex with.\n");
      return 1;
    }
  }  
  partner = find_player(str);
  if(!partner || environment(partner) != environment(this_player()) || partner->query_invis() ){
    notify_fail("That person is not here to have sex with.\n");
    return 0;
  }
  partner_rose = present("w_whiterose",partner);
  if(!partner_rose){
    partner_rose = clone_object("/players/wocket/wedding/whiterose.c");
    move_object(partner_rose,partner);
  }
  partner_rose->set_partner(this_player());
  tell_object(partner,ask_msg+"\n");
  tell_object(partner,"Type 'sex yes' to accept.\n");
  write(ask_msg+"\n");
  return 1;
}

set_acceptmsg(str){
  accept_msg = str;
}

set_askmsg(str){
  ask_msg = str;
}
set_partner(ob){ partner = ob; }  
