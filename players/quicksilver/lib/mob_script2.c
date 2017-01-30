#include "/players/quicksilver/std/std.h"
#define DEBUG 1

inherit "players/quicksilver/lib/mob_talk.c";

int action_delay;
int length_based_delay;

int current_line;
string current_script;
string *lines;

mapping script_data;

mapping catch_tell_data;

object interacting_ob;  /* who the mob is interacting with */

int set_action_delay(int amount) { return action_delay = amount; }
int query_action_delay() { return action_delay; }

int set_length_based_delay(int bool) {
	return length_based_delay = (bool != 0);
}
int query_length_based_delay() { return length_based_delay; }

object set_interacting_ob(object obj) { return interacting_ob = obj; }
object query_interacting_ob() { return interacting_ob; }

int calculate_delay(string text, int override) {
	if(override) return override;
	
	return action_delay + (strlen(text) / 75);
}

void give_item(string arg) {
	int err;
	string item_id, player_name;
	object item, player;
	
	if(!sscanf(arg, "%s %s", item_id, player_name)) item_id = arg;
	if(DEBUG) tell_object(find_player("quicksilver"), "item_id: "+item_id+"\n");
	if(item = present(item_id, this_object())) {
		if(DEBUG) tell_object(find_player("quicksilver"), "item: "+item->short()+"\n");
		if(!player_name) {
			player_name = (string)interacting_ob->query_name();
			if(DEBUG) tell_object(find_player("quicksilver"), "player_name: "+player_name+"\n");
		}
		player = find_living(lower_case(player_name));
		if(present(player,
		   environment(this_object()))) {
		   	if(DEBUG) tell_object(find_player("quicksilver"), "found: "+player_name+"\n");
		   	err = transfer(item, player);
			if(DEBUG) tell_object(find_player("quicksilver"), "err: "+err+"\n");
			if(!err) {
				mob_emote("gives " + item_id + " to " + player_name + ".", 
				          this_object());
				mob_write("Ok.\n");
			}
		}
	}
}

int reset_actions() {
	int i;
	
	current_line = 0;
	current_script = "";

	/* if the below condition is true, nothing was running */
	if(remove_call_out("exec_script_line") == -1) return 0;
	
	i = 1;
	
	while(remove_call_out("exec_script_line") != 1)
		i++; /* kill 'em all, and tally up the bodies! */
	return i;
}

int load_init_script(string file) {
	string file_data;
	string *data;
	
	string key;
	string script_file;
	
	int i;
	
	script_data = ([ ]);
	reset_actions();  /* flush out pending old actions, if any */
	
	if(!(file_data = read_file(file))) {  /* open failed */
		if(DEBUG) tell_object(find_player("quicksilver"), "Failed opening init script file: "+file+"\n");
		return 0;
	}
	if(DEBUG) tell_object(find_player("quicksilver"), "Opened init script file: "+file+"\n");
	
	data = explode(file_data, "\n");
	
	for(i = 0; i < sizeof(data); i++) {
		if((data[i] == "") || sscanf(data[i], ";%~s")) continue;
		
		if(sscanf(data[i], "%s %s", key, script_file)) {
/*			if(key == "init") {
				script_data += ([ "init": script_file ]);
				current_script = script_file;
			} else { */
				if(!(file_data = read_file(script_file))) {  /* open failed */
					if(DEBUG) tell_object(find_player("quicksilver"), "Failed opening script file: "+script_file+"\n");
				} else {
					script_data += ([ key: explode(file_data, "\n") ]);
					if(DEBUG) tell_object(find_player("quicksilver"), "Opened script file (" + key + "): "+script_file+"\n");
				} /*
			} */
		} 
	}
	
	return sizeof(m_indices(script_data));
}


void exec_script_line(string line) {
	string cmd, arg, newfile;
	int delay, cmd_executed;
	
	if(DEBUG) tell_object(find_player("quicksilver"), "line "+current_line+": "+line+"\n");

	if(!line || line == "") {  /* null lines */
		if(current_line > sizeof(lines)) {  /* EOF handling */
			if(DEBUG) tell_object(find_player("quicksilver"), "Script complete.\n");
			current_line = 0;
			return;
		}
		current_line++;
		return exec_script_line(lines[current_line]);
	}
	
	if(sscanf(line, "%s[%d] %s", cmd, delay, arg) || sscanf(line, "%s %s", cmd, arg)) {
		if(DEBUG) tell_object(find_player("quicksilver"), "cmd: "+cmd+" delay: "+delay+" arg: "+arg+"\n");
		switch(cmd) {
			case ";" : 		/* comment */
							current_line++;
							return exec_script_line(lines[current_line]);
							break;
			case "!say" :	cmd_executed = 1;
							break;
			case "say" :	if(arg[0] == 58) {
								mob_emote(arg[1..strlen(arg)], 0);
							} else {
								mob_talk(arg, 0);
							}
							call_out("exec_script_line", calculate_delay(arg, delay), "!say " + arg);
							current_line++;
							return;
							break;
			case "exec" :	current_line = 0;
							current_script = arg;
							lines = script_data[arg];
							
							if(DEBUG) tell_object(find_player("quicksilver"), "Starting execution of "+arg+"...\n");
							return exec_script_line(lines[current_line]);
							break;
			case "clone" :	move_object(clone_object(arg), this_object());
							cmd_executed = 1;
							current_line++;
							if(delay) {
								return call_out("exec_script_line", delay,
								                lines[current_line]);
							} else {
								return exec_script_line(lines[current_line]);
							}
							break;
			case "!give" :	cmd_executed = 1;
							break;
			case "give" :	give_item(arg);
							call_out("exec_script_line", calculate_delay(arg, delay), "!give " + arg);
							current_line++;
							return;
							break;
		}
	}
	exec_script_line(lines[current_line]);
}

void exec_script(string key, int delay) {
	current_line = 0;
	current_script = key;
	lines = script_data[key];
	
	if(DEBUG) tell_object(find_player("quicksilver"), "Starting execution in "+delay+"...\n");
	exec_script_line(lines[current_line]);
}