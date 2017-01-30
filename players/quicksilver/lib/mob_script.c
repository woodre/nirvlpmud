#include "/players/quicksilver/std/std.h"
#define DEBUG 1

inherit "players/quicksilver/lib/mob_talk.c";

int action_delay;
int length_based_delay;

int current_line;

string *lines;
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

	/* if the below condition is true, nothing was running */
	if(remove_call_out("exec_script_line") == -1) return 0;
	
	i = 1;
	
	while(remove_call_out("exec_script_line") != 1)
		i++; /* kill 'em all, and tally up the bodies! */
	return i;
}

int load_script(string file) {
	string data;
	
	reset_actions();  /* flush out pending old actions, if any */
	
	if(!(data = read_file(file))) {  /* open failed */
		if(DEBUG) tell_object(find_player("quicksilver"), "Failed opening script file: "+file+" err: "+data+"\n");
		return 0;
	}
	if(DEBUG) tell_object(find_player("quicksilver"), "Opened script file: "+file+"\n");
	
	lines = explode(data, "\n");
	
	return sizeof(lines);
}

void exec_script(int delay) {
	current_line = 0;
	
		if(DEBUG) tell_object(find_player("quicksilver"), "Starting execution in "+delay+"...\n");
	call_out("exec_script_line", delay, lines[current_line]);
}

void exec_script_line(string line) {
	string cmd, arg, newfile;
	int delay, cmd_executed;
	
	if(DEBUG) tell_object(find_player("quicksilver"), "line "+current_line+": "+line+"\n");
	if(!line || line == "") {
		current_line++;
		return;
	}
	
	if(sscanf(line, "%s[%d] %s", cmd, delay, arg) || sscanf(line, "%s %s", cmd, arg)) {
		if(DEBUG) tell_object(find_player("quicksilver"), "cmd: "+cmd+" delay: "+delay+" arg: "+arg+"\n");
		switch(cmd) {
			case ";" : 		/* comment */
							cmd_executed = 1;
							current_line++;
							return exec_script_line(lines[current_line]);
							break;
			case "say" :	if(arg[0] == 58) {
								mob_emote(arg[1..strlen(arg)], 0);
							} else {
								mob_talk(arg, 0);
							}
							cmd_executed = 1;
							current_line++;
							break;
			case "exec" :	
	if(!(newfile = read_file("/players/quicksilver/666/cre/bat2.mscr"))) {  /* open failed */
		if(DEBUG) tell_object(find_player("quicksilver"), "Failed opening script file: "+arg+" err: "+newfile+"\n");
		return 0;
	}
			
							return exec_script(delay);
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
			case "give" :	give_item(arg);
							cmd_executed = 1;
							current_line++;
							break;
		}
	}
	call_out("exec_script_line", calculate_delay(line, delay), lines[current_line]);
}