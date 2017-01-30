#include "defs.h"
#include "cleric_soul.h"

#define G_MSG "<"+BOLD+"Cleric"+OFF+"> "


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
	add_action("cleric_update","cleric_update");
	}
}

save_me(){ save_object(SAVE+epn); return 1; }

cleric_save(){ 
	save_me(); 
	tell_object(ep,"Your soul has been remembered.\n"+
	G_MSG+" Guild Status Saved.\n");
	return 1;
}
										
cleric_update(){
	save_me();
	write(G_MSG+"Guild Status Saved.\n");
	move_object(clone_object(PATH+"/guildob.c"),tp);
	write(G_MSG+"Guild Stats Updated.\n");
	destruct(this_object());
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
		if(temp->cmd(arg2)){
			return 1;
		}
	}
	return 0;
}


