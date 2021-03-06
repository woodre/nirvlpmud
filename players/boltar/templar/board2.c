/* Groo 90-12-02 */
/**********************************
 * The new, great bulletin board! *
 * (The manic wanderer - version) *
 * (with the nasty bug #1 fixed.) *
 **********************************/

#define ERROR_LOG "/log/BOARD"
#define BOARD_NAME "players/boltar/templar/board"

#include "/players/jaraxle/ansi.h"
string new_head, new_text, tmp_head, tmp_text;
string *has_read;
int msg_num;
int dates;

static string  messages, headers;
static int line, looked_at;
static object curr_writer;

id(str) {
	return str == "board" || str == "bulletin board" || str == "bulletinboard";
}

long() {
	int ind;
   string *temp;
has_read = present("KnightInvite",this_player())->query_has_read();
if(!has_read) has_read = ({ });
	write("This is a bulletin board.\n");
	write("Usage : note <headline>, read/remove <message number>\n");
	write("        store <message number> <file name>\n");
	if (!msg_num) {
		write("The board is empty.\n");
		return;
	}
	write("The bulletin board contains " + msg_num);
	if (msg_num == 1)
		write(" note :\n\n");
	else 
		write(" notes :\n\n");
	/*
	say(this_player()->query_name() + " studies the bulletin board.\n");
	*/
	ind = 0;
	while (ind < msg_num) {
temp = explode(headers[ind],",");
if(member(has_read,temp[1]) == -1) write(HIG+"*"+NORM);
		write(ind + 1 + ":\t" + headers[ind] + "\n");
		ind++;
	}
  return 1;
}

short() {
	return "A bulletin board(" + msg_num + " msg(s))";
}

get() {
	write("It is firmly secured to the ground.\n");
	return 0;
}

init() {
  add_action("long", "msgs");
	add_action("new_msg", "note");
	add_action("read_msg", "read");
	add_action("remove_msg", "remove");
	add_action("move_msg", "move");
	add_action("store_msg", "store");
	if (!looked_at) {
	        int i;
		string arr;
		messages = allocate(50);
		headers = allocate(50);
                dates = allocate(50);
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
	if (arg)
		if (!random(5)) {
			say("A small gnome appears and secures some " +
			"notes on the board that were loose.\n");
			say("The gnome leaves again.\n");
		}
}

new_msg(msg_head) {
	line = 1;
	if (!msg_head)
		return 0;
        if(this_player()->query_level() < 100 && !present("KnightInvite", this_player())){
	   write("You receive a jolt of magical energy.\n");
	   write("Gadvey, the Templar Mage, thanks you for trying.\n");
	   this_player()->hit_player(200);
	   return 1;
	}
	if (curr_writer && environment(curr_writer) ==
		environment(this_object())) {
		write(this_player()->query_name() + " is busy writing.\n");
		return 1;
	}
	if (msg_num == 50) {
		write("You have to remove an old message first.\n");
		return 1;
	}
	if (strlen(msg_head) > 30) {
		write("Message header too long. Try again.\n");
		return 1;
	}
	curr_writer = this_player();
	say(curr_writer->query_name() + " starts writing a note.\n");
	new_head = msg_head;
	new_text = "";
	input_to("get_msg");
	write("Enter message text. End with '**', abort with '~q'.\n");
	write("1>>");
	return 1;
}

get_msg(str) {
	if (str == "~q") {
		say(curr_writer->query_name() + " aborts writing a note.\n");
		write("Note aborted.\n");
		curr_writer = 0;
		new_head = "";
		new_text = "";
		return;
	}
	if (str == "**") {
		if (line == 1) {
			write("No text entered. Message discarded.\n");
			say(curr_writer->query_name() + " quits writing.\n");
			curr_writer = 0;
			new_head = "";
			new_text = "";
			return;
		}
		say(curr_writer->query_name() + " has completed a note : " +
			new_head + "\n");
         headers[msg_num] = new_head + " (" + capitalize(this_player()->query_real_name()) +
                 ", " + ctime() + ")";
		messages[msg_num] = new_text + "\n";
                dates[msg_num] = time();
		msg_num++;
		save_board();
		write("Ok.\n");
		curr_writer = 0;
command("tce has finished a new note on the guild board!",this_player());
		return;
	}
	new_text = new_text + str + "\n";
	line++;
	write(line + ">>");
	input_to("get_msg");
}

read_msg(what_msg) {
	int note;
   string *has_read, *temp;
has_read = present("KnightInvite",this_player())->query_has_read();
if(!has_read) has_read = ({ });
  if(!what_msg) return 0;
  if(!present("KnightInvite", this_player()) && this_player()->query_level() < 21) {
	   write("You receive a jolt of magical energy.\n");
	   write("Gadvey, the Templar Mage, thanks you for trying.\n");
	   this_player()->hit_player(200);
	   return 1;
  }
	if (!sscanf(what_msg, "%d", note))
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("Not that many messages.\n");
		return 1;
	}
	note -= 1;
	/*
	say(this_player()->query_name() + " reads a note titled '" +
		headers[note] + "'.\n");
	*/
	write("The note is titled '" + headers[note] + "':\n\n");
temp = explode(headers[note],",");
if(member(has_read,temp[1]) == -1)
present("KnightInvite",this_player())->add_has_read(temp[1]);
	write(messages[note]);
	return 1;
}

remove_msg(what_msg) {
	string player, title, date;
	int note, ind,tim;
        if(this_player()->query_level() < 21)
	if(!present("KnightInvite", this_player())){
	   write("You receive a jolt of magical energy.\n");
	   write("Gadvey, the Templar Mage, thanks you for trying.\n");
	   this_player()->hit_player(200);
	   return 1;
  }
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
	if ((this_player()->query_real_name() != player &&
		this_player()->query_guild_rank() < 9) ||
		!query_ip_number(this_player())) {
                write("Only GCs may remove other people's notes.\n");
		say(this_player()->query_name() + " failed to remove " +
			"a note.\n");
		return 1;
	}
        tim = time();
        if (this_player()->query_real_name() != player &&
                604800 > tim-dates[note] &&
                this_player()->query_guild_rank() < 11) {
                write("That note is not a week old yet.\n");
                say(this_player()->query_name() + " failed to remove " +
                        "a note.\n");
                return 1;
        }
	say(this_player()->query_name() + " removes a note titled '" +
		headers[note] + "'.\n");
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
        if(this_player()->query_level() < 21)
	if(!present("KnightInvite", this_player())){
	   write("You receive a jolt of magical energy.\n");
	   write("Gadvey, the Templar Mage, thanks you for trying.\n");
	   this_player()->hit_player(200);
	   return 1;
  }
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
        if(this_player()->query_level() < 21)
	if(!present("KnightInvite", this_player())){
	   write("You receive a jolt of magical energy.\n");
	   write("Gadvey, the Templar Mage, thanks you for trying.\n");
	   this_player()->hit_player(200);
	   return 1;
  }
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

clean_me() {
string hold, *temp, *temp2, *has_read; 
int x;
has_read = present("KnightInvite",this_player())->query_has_read();
if(!has_read) has_read = ({ });
temp2 = ({ });
for(x = 0; (x+1) < sizeof(headers); x++) {
if(headers[x]) temp = explode(headers[x],",");
if(sizeof(temp) > 1) hold = temp[1];
temp2 += ({ hold }); }
for(x = 0; x < sizeof(has_read); x++)
if(member(temp2,has_read[x]) == -1)
present("KnightInvite",this_player())->remove_has_read(has_read[x]);
return; }
