#define ERROR_LOG "/players/angel/log/BOARD"
#include <ansi.h>

inherit "/obj/treasure";

#define BOARD_NAME "players/angel/masons/aboard"

string new_head, new_text, tmp_head, tmp_text;
int msg_num;

static string  messages, headers;
static int line, looked_at;
static object curr_writer;

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bulletin board");
   set_alias("bulletin");
   set_alias("board");
   set_short(YEL+"An Ancient Bulletin Board"+NORM);
   set_long("This is a ancient bulletin board found while recovering\n\
the old masons guild files. It's possible to read the\n\
dilapidating bulletin board. It contains 10 messages.\n\
         You can read <message number>.\n");
}

get() {
	write("It is firmly secured to the ground.\n");
	return 0;
}

init() {
  ::init();
  	add_action("read_msg", "read");
	add_action("store_msg", "store");
	if (!looked_at) {
	        int i;
		string arr;
		messages = allocate(30);
		headers = allocate(30);
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

read_msg(what_msg) {
	int note;
	if (!sscanf(what_msg, "%d", note))
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("Not that many messages.\n");
		return 1;
	}
	note -= 1;
	
	write("The note is titled '" + headers[note] + "':\n\n");
	write(messages[note]);
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