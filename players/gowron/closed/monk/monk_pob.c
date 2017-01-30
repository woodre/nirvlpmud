#include "/players/gowron/closed/monk/def.h"

int rank,gxp;
status muff;

static mapping coms;

id(str) { return str == "new_mrobe"; }
query_value() { return 0; }
query_weight() { return 0; }
get() { return 1; }
drop() { return 0; }

query_rank() { return rank; }
query_gxp() { return gxp; }
set_rank(num) { rank = num; }
set_gxp(num) { gxp = num; }

query_muffle() { return muff; }
set_muffle(m) { muff = m; }

save_me() {
	save_object("players/gowron/closed/monk/save/"+ME);
	write("Saving guild stats...\n");
}

restore_me() {
	write("Restoring guild stats.\n");
	restore_object("players/gowron/closed/monk/save/"+ME);
}	

query_auto_load() {
	save_me();	
	if (query_verb() == "quit") {
           write("Monk quit sequence...\n");
	   write("  -Saving guild stats\n");
	   save_me();
	   write("  -Remove you from channel daemon.\n");
	   CHATD->remove_user(TP);
	}
	return "players/gowron/closed/monk/monk_pob:";	   		
}

short() { 
 	return "NEW Monk Robes(worn)";
}

long() {
	write("These are the monk robes for monk guild members.\n");
	write("Type mhelp dir for more info.\n");
}

/* Thanks Balowski :)				*/

set_commands() {
	int i;
	string *f,cmd;

	i = sizeof(f = files("/players/gowron/closed/monk/bin/" + "*.c"));
	write("# of files to load = "+i+"\n");
	coms = allocate_mapping(i);
	while (i--) {
	      sscanf(f[i], "%s.c", cmd);
	      coms[cmd] = "/players/gowron/closed/monk/bin/" + cmd;
	}
}
	      	
reset(arg) {
	object ob;

	if (arg) {
           save_me(); 
           return;
	}
	muff = 0;
	restore_me();
	if (!CHATD->activate()) {
	   write("Fixing chat daemon...\n");
	   ob = clone_object("players/gowron/closed/monk/chatd");
	   move_object(ob, "/players/gowron/workroom");
	}	
	if (!CHATD->is_user(TP))
	   CHATD->add_user(TP);   
	if (rank < 1)
           rank = 1;
	if (rank < 1) 
           gxp = 1;
	if (rank < 4) 
      	   TP->set_ac(4);
	else
	   TP->set_ac(rank+1);
	set_commands();
}
	
cmd_hook(str) {
	string cmd;

	if (cmd = coms[query_verb()]) 
	   return cmd->main(str);		
}

query_commands() { return coms; }

init() {
	int i;
	string *ks;

	write("Updating commands.\n");
	if (!coms) 
	   set_commands();
	i = sizeof(ks = keys(coms));
	while (i--) 
	      add_action("cmd_hook", ks[i]);
}
	
	
	
	

	
