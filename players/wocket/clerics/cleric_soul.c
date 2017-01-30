#include "defs.h"
#define G_MSG "<"+BOLD+"Cleric"+OFF+"> "
int position; 
/* 
0 = standing
1 = kneeling
2 = sitting
3 = meditating
4 = flying
*/
int g_level; 			/*guild level*/

id(str){ return (str == GUILD_ID || str == "cleric_soul"); }
short(){ return 0; }
long(){ write("How are you looking at this?\nSee Wocket.\n"); return 1; }

init(){
/*
  object shad;
  shad = clone_object(PATH+"/shadows/cleric_shadow.c");
  shad->start_shadow(this_player());
*/
	if(environment(this_object()) == this_player()) {
		if(!restore_object(SAVE+tprn)) {
		/* Guild Initial Setup */
		save_object(SAVE+tprn);
		}
	}
	/* Guild Initial Reset */
	if(tp->query_level () < 20){
		tp->set_guild_name("cleric");
		tp->set_pretitle("|");
		tp->set_title(BOLD+"of the order of Clerics"+OFF);
		write(G_MSG+"Guild Status Restored.\n");
		save_me();
		tp->save_character();
	}
	add_action("cmd_hook","");
}

save_me(){ save_object(SAVE+epn); return 1; }

cleric_save(){ 
	save_me(); 
	tell_object(ep,"Your soul has been remembered.\n"+
	G_MSG+" Guild Status Saved.\n");
	return 1;
}
										
cmd_hook(str){
	int i;
	string temp;
	string arg1, arg2;
	if(!str) return 0;
	if(sscanf(str,"%s %s",arg1,arg2) != 2){
		arg1 = str;
	}
	if(arg1 == "") arg1 = "blah";
	i = strlen(arg1);
	if(arg1[i-1] == 046) return 0;
	temp = CMDS+"/"+arg1+".c";
	if(file_size(temp) > 0){
		if(temp->cmd(arg1)){
			return 1;
		}
	}
	return 0;
}

	  
clericEnsoul(){
  object obj;
  obj =  clone_object("/players/wocket/clerics/cleric_soul.c");
  move_object(obj,this_player());
  destruct(this_object());
  return 1;
}

positionCheck(){
string msg;
  switch(position){
    case 0: return 0; break;
    case 1: msg = "kneeling"; break;
    case 2: msg = "sitting"; break;
    case 3: msg = "meditating"; break;
    case 4: return 0; break;
    default: return 0;
  }	
  write("You can not do that while you are "+msg+".\n");
  return 1;

}

query_standing(){ return position == 0; }
query_kneeling(){ return position == 1; }
query_sitting(){ return position == 2; }
query_meditating(){ return position == 3; }
query_flying(){ return position == 4; }
query_position(){ return position; }

startSitting(){
  if(position == 2){
    notify_fail("You are already sitting.\n");
    return 0;
  }
  write("You sit down.\n");
  say(this_player()->query_name()+" sits down.\n");
  position = 2;
  return 1;
}

startStanding(){
  if(position == 0){
    notify_fail("You are already standing.\n");
    return 0;
  }
  write("You stand up.\n");
  say(this_player()->query_name()+" stands up.\n");
  position = 0;
  return 1;
}

startKneeling(){
  if(position == 1){
    notify_fail("You are already kneeling.\n");
    return 0;
  }
  write("You start kneeling.\n");
  say(this_player()->query_name()+" starts kneeling.\n");
  position = 1;
  return 1;
}
