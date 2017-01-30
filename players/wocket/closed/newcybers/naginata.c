#include "/players/wocket/closed/cyber/DEFS.h"
#define MOVES ({ "sweeping_slice","chop", })
inherit "/players/wocket/closed/newcybers/nagi_moves/sweeping_slice.c";
inherit "/obj/weapon.c";
int wc;
int ac;

id(str){ return str == "nagi"; }
reset(){
  set_short("A naginata");
  set_long("A 5 1/2 foot long pole arm.  A razor-edged blade adorns the\n"+
           "stout black staff.  An instrument of destruction when wielded\n"+
           "by a trained ninja.\n");
}

init(){
int i,a;
  ::init();
  if(present("implants",environment(this_object()))){
  for(i=0,a=sizeof(MOVES);i<a;i++){
    add_action("cmd_hook",MOVES[i]);
  }
  }
}

cmd_hook(str){
int belt,strength,stamina;
int tempac,tempwc;
string cmd; 
  cmd = "/players/wocket/closed/newcybers/nagi_moves/"+query_verb()+".c";
  if(cmd)
  belt = IPTP->query_art_level();
  strength = this_player()->query_attrib("str");
  stamina =  this_player()->query_attrib("sta");
  tempwc = cmd->move(belt,strength,stamina);
  str = cmd->get_emote(tempwc);
  write("belt "+belt+" str: "+strength+" sta: "+stamina+" tempwc: "+tempwc+"\n");
  write(str);
  wc += tempwc;
  ac += tempac;
  return 1;
}    

hit(){
int tempwc;
  write("Ac: "+ac+"  Wc: "+wc+"\n");
  tempwc = wc;
  wc = 0;
  return tempwc;
}