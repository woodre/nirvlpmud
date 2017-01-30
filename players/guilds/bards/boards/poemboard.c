/** Reflex's Poem Board - Adjust Templar board for this. */

#define ERROR_LOG "/log/BOARD"
#define BOARD_NAME "players/guilds/bards/boards/poemboard"
#define SIZE 50
#define TP this_player()
string new_head, new_text, tmp_head, tmp_text;
int msg_num;
int dates,circle;

static string  messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) {
	return str == "writings" || str == "poems" || str == "poet writings" ||
          str == "writing";
}

long() {
	int ind;
	write("On this wall a Bard may write down their greatest poems.\n");
	write("write <poem title> \n");
   write("read <poem number>\n");
 if(TP->query_level() > 19){
   write("As a wizard, you may remove <poem number> and \n"+
         "store <poem number> <filepath>.\n");
   }
	if (!msg_num) {
		write("The wall is empty.\n");
		return;
	}
	write("The walls contains " + msg_num);
	if (msg_num == 1)
		write(" poem :\n\n");
	else 
		write(" poems :\n\n");
	
	say(this_player()->query_name() + " studies the wall.\n");
	
	ind = 0;
	while (ind < msg_num) {
		write("["+ (ind + 1) + "]\t" + headers[ind] + "\n");
		ind++;
	}
  return 1;
}

get() {
	write("It is a wall!\n");
	return 0;
}

init() {
    object gob;
	if(!environment()) return;
     gob=present("bard_obj",this_player());
     if(!gob) return;
    add_action("long", "msgs");
        add_action("new_msg", "write");
	add_action("read_msg", "read");
    if( TP->query_level() > 19 || gob->query_is_gc() ) {
    	    add_action("remove_msg", "remove");
	    add_action("move_msg", "move");
	    add_action("store_msg", "store");
    }
	if (!looked_at) {
	        int i;
		string arr;
		messages = allocate(SIZE);
		headers = allocate(SIZE);
                dates = allocate(SIZE);
		looked_at = 1;
		if (!restore_object(BOARD_NAME))
		    return;
		arr = explode(tmp_head, "\n**\n");
		i = 0;
		while(i < sizeof(arr)) {
		    headers[i] = arr[i];
		    i++;
		}
		arr = explode(tmp_text, "\n**\n");
		i = 0;
		while(i < sizeof(arr)) {
		    messages[i] = arr[i];
		    i++;
		}
		tmp_text = "";
		tmp_head = "";
	}
}

reset(arg) {
	if (!arg) return;
	}

new_msg(msg_head) {
	line = 1;
	if (!msg_head)
		return 0;
	if (curr_writer && environment(curr_writer) ==
		environment(this_object())) {
		write(this_player()->query_name() + " is busy writing a masterpiece.\n");
		return 1;
	}
	if (msg_num == 50) {
                write("This wall is now full, removing note #1\n");
                write("Please start again.\n");
                circle = 1;
                remove_msg("1");
		return 1;
	}
	if (strlen(msg_head) > 30) {
		write("Poem title is too long. 30 characters max.\n");
		return 1;
	}
	curr_writer = this_player();
	say(curr_writer->query_name() + " starts writing a poem.\n");
	new_head = msg_head;
	new_text = "";
	input_to("get_msg");
	write("Enter poem text. End with '**', abort with '~q'.\n");
	write("1>>");
	return 1;
}

get_msg(str) {
	if (str == "~q") {
		say(curr_writer->query_name() + " aborts writing a poem.\n");
		write("Note aborted.\n");
		curr_writer = 0;
		new_head = "";
		new_text = "";
		return;
	}
	if (str == "**") {
		if (line == 1) {
			write("No text entered. Poem discarded.\n");
			say(curr_writer->query_name() + " quits writing.\n");
			curr_writer = 0;
			new_head = "";
			new_text = "";
			return;
		}
		say(curr_writer->query_name() + " has completed a poem titled,\"" +
			new_head + "\"\n");
		headers[msg_num] = new_head + "(" + this_player()->query_real_name() +
			", " + extract(ctime(time()), 4, 9) +
			", " + this_player()->query_level() + ")";
		messages[msg_num] = new_text + "\n";
                dates[msg_num] = time();
		msg_num++;
		save_board();
		write("Ok.\n");
		curr_writer = 0;
		return;
	}
	new_text = new_text + str + "\n";
	line++;
	write(line + ">>");
	input_to("get_msg");
}

read_msg(what_msg) {
	int note;
  if(!what_msg) return 0;
	if (!sscanf(what_msg, "%d", note))
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("Not that many Poems.\n");
		return 1;
	}
	note -= 1;
	
	say(this_player()->query_name() + " reads a Poem entitled, '" +
		headers[note] + "'.\n");
	
	write("The Poem is entitled, '" + headers[note] + "':\n\n");
	write(messages[note]);
	return 1;
}

remove_msg(what_msg) {
	string player, title, date;
	int note, ind,tim;
	if (!sscanf(what_msg, "%d", note)) 
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("That poem doesn't exist.\n");
		return 1;
	}
	note -= 1;
	if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
		error_log("Header error");
		write("Board : error - header corrupt.\n");
		return 1;
	}
       
        if(!circle)
	say(this_player()->query_name() + " removes a poem entitled '" +
		headers[note] + "'.\n");
        circle = 0;
	ind = note;
	while (ind < msg_num - 1) {
		messages[ind] = messages[ind + 1];
		headers[ind] = headers[ind + 1];
                dates[ind] = dates[ind + 1];
		ind++;
	}
	messages[ind] = 0;
	headers[ind] = 0;
	msg_num -= 1;
	save_board();
	write("Ok.\n");
	return 1;
}
store_msg(str) {
	int note;
	string file;
	if (!str) 
		return 0;
	if (sscanf(str, "%d %s", note, file) != 2)
		if (sscanf(str, "note %d %s", note, file) != 2)
			return 0;
	if (note < 1 || note > msg_num) {
		write("That message doesn't exist.\n");
		return 1;
	}
	note -= 1;
	file = file + ".note";
	write_file(file, headers[note] + "\n" + messages[note] + "\n");
	return 1;
}

save_board() {
	int ind;
	ind = 1;
	tmp_head = implode(headers, "\n**\n") + "\n**\n";
	tmp_text = implode(messages, "\n**\n") + "\n**\n";
	save_object(BOARD_NAME);
	tmp_head = "";
	tmp_text = "";
	return 1;
}


error_log(str) {
	tell_room(environment(this_object()), "Board says '" + str + "'.\n");
	log_file(ERROR_LOG, "Board : " + str);
	return;
}

move_msg(what_msg) {
	string player, title, date, movemesg;
	object oboard;
	int note, ind;
	if (!sscanf(what_msg, "%d", note)) 
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("That message doesn't exist.\n");
		return 1;
	}
	note -= 1;
	if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
		error_log("Header error");
		write("Board : error - header corrupt.\n");
		return 1;
	}
	if ((this_player()->query_name() != player &&
		this_player()->query_level() < 24) ||
		!query_ip_number(this_player())) {
		write("Only Archwizards may move other wizard's notes.\n");
		say(this_player()->query_name() + " failed to move " +
			"a note.\n");
		return 1;
	}
	say(this_player()->query_name() + " moved a note titled '" +
		headers[note] + "'.\n");
	ind = note;
        movemesg = headers[ind] + "\n**\n"  + messages[ind] + "\n**\n";
	while (ind < msg_num - 1) {
		messages[ind] = messages[ind + 1];
		headers[ind] = headers[ind + 1];
		ind++;
	}
	messages[ind] = 0;
	headers[ind] = 0;
	msg_num -= 1;
	save_board();
	write("Ok.\n");
        call_other("obj/wiz_bull_board4", "moved", movemesg); 
	return 1;
}
