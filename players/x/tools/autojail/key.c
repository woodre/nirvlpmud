#include "/players/x/x.h"

string *pending_jails;

void reset(int x){
  if(x) return;
  call_out("dest_me", 1);
  pending_jails=({});
  restore_object("players/x/tools/autojail/datafile1");
  if(sizeof(pending_jails) > 0){
    call_out("autojail", 1);
  }
}

status id(string str){
  return (str=="jail key" || str=="key");
}

string short(){
  return "The jail key"+(sizeof(pending_jails)?(" [pending]"):"");
}

void dest_me(){ if(!environment()) destruct(this_object()); }
void long(){
  if(IS_WIZARD(TP)){
    write("\
\"autojail\" <person>\n\
\"pending\"\n");
  }
}

void save_me(){
  save_object("players/x/tools/autojail/datafile1");
}

void init(){
  if(TP && IS_WIZARD(TP)){
    add_action("cmd_autojail", "autojail");
    add_action("cmd_pending",  "pending");
  }
}

int cmd_pending(){
  int s;
  s = sizeof(pending_jails);
  write("\n");
  while(s--){
    write(pending_jails[s]+"\n");
  }
  write("\n");
  return 1;
}

int cmd_autojail(string str){
  if(!str) return 0;
  if(valid_active_player(str) != 1){
    write(str+" is not a valid player.\n");
    return 1;
  }
  if(member_array(str,pending_jails)>-1){
    write(str+" is already pending for jailtime.\n");
    return 1;
  }
  
  pending_jails += ({str});
  
  write("You program the jail key to autojail "+str+".\n");
  tell_room(environment(),
   short()+" beeps and whirs.\n");
   
  save_me();
  
  if(find_call_out("autojail") == -1)
    call_out("autojail", 1);
  return 1;
}

void autojail(){
  int ok;
  int s, *positions;
  object x;
  positions = ({});
  s = sizeof(pending_jails);
  while(s--){
    if((x=find_player(pending_jails[s])) && environment(x) &&
        FN(ENV(x)) != "room/prison"){
      "/room/prison"->add_prisoner(pending_jails[s]);
      tell_object(x, "\
\n\tYou have been automatically jailed by X.\n\
\n\tIf you do not understand why you were jailed,\n\
\n\tmail him and ask. If this punishment has been\n\
\n\trendered however, there is irrefutable evidence\n\
\n\tthat you have cheated or otherwise upset the mud.\n\n"); 
      if(!find_object("/players/x/workroom"))
        "/players/x/workroom"->load();
      tell_room(find_object("/players/x/workroom"),
        capitalize(pending_jails[s])+" has been automatically jailed.\n");
      move_object(x, "/room/prison");
      x->set_home("/room/prison");
      x->save_me();
      log_file("PRISON", pending_jails[s]+" imprisoned by xCode[tm] automatically "+ctime()+"\n"); 
      positions += ({ s });
    }
  }
  s = sizeof(positions);
  while(s--){
    pending_jails -= ({ pending_jails[positions[s]] });
   ok=1;
  }
  if(ok) save_me();
  if(!sizeof(pending_jails)){
    while(remove_call_out("autojail") != -1);
    return;
  }
  call_out("autojail", 1);
}
