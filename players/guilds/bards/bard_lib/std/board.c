/*
 * Some kinda stupid bulletin board.
 * Not compatible with savefiles of old boards
 * Based on Groo's/The manic wanderer's board
 * Board was done by Balowski/Rasmus, March 17th 1995
 * 2nd revision, '96 - me again
 */
#pragma strict_types
#include <security.h>
#include "/players/guilds/bards/bard_lib/lib.h"
#define ERROR_LOG "BOARD"
#define MEMOBJ(x) (x ? present("guild_object", x) : 0)
inherit BASE;

string          *messages;      /* array of messages */
string          *headers;       /* array of headers */
int             *identifiers;   /* ids for the current notes */
int             NextID;         /* next available id */

static string   BoardName;      /* will be saved to this file name */
				/* if not set, the board is never saved */
static int      size;           /* maximum number of messages */
static string   short_desc;     /* used to compose short() */
static string   *EditOk;        /* people allowed to remove notes */

int
clean_up (int refcount)
{
    if (environment())
	return 0;
    if (refcount)
	return 1;
    destruct(this_object());
}

void
reset (int arg)
{
    if (arg && !random(5))
	tell_room(environment(), "\
A small gnome appears and secures some notes on the board that were\n\
loose. The gnome leaves again.\n");
}

void
init ()
{
    add_action("cmdNote", "note");
    add_action("cmdRead", "read");
    add_action("cmdRemove", "remove");
    add_action("cmdStore", "store");
    add_action("cmdCatchup", "catchup");
}


void
set_name (string str)
{
    BoardName = str;

    /* load old messages. this allocates the arrays too */
    if (!restore_object(BoardName)) {
	headers = ({ });
	messages = ({ });
	identifiers = ({ });
    }
    
    if (!identifiers) {         /* the identifiers were added later */
	int i;
	identifiers = ({ });
	for (i = 0; i < sizeof(headers); i++)
	    if (headers[i])
		identifiers += ({ NextID++ });
	headers = headers[0..sizeof(identifiers) - 1];
	messages = messages[0..sizeof(identifiers) - 1];
    }
}

void
set_editors(string *eds)
{
    EditOk = eds;
}

void
set_size (int n)
{
    size = n;
}

void
set_short (string str)
{
    short_desc = str;
}


static status
valid_edit(string author)
{
    string name;

    name = (string) this_player()->query_real_name();
    if (name == lower_case(author)) return 1;
    if ((int) this_player()->query_level() >= ELDER) return 1;
    if (EditOk && member_array(name, EditOk) >= 0) return 1;
    return 0;
}    

static int
save_board ()
{
    if (BoardName)
	save_object(BoardName);
    return 1;
}

static void
error_log (string str)
{
    tell_room(environment(), "Board says '" + str + "'.\n");
    log_file(ERROR_LOG, "Board : " + str);
    return;
}


int
id (string str)
{
    return str == "board" || str == "bulletin board";
}

void
long ()
{
    int         i, j;
    object      ob;
    int        *read;

    say(this_player()->query_name() + " studies the bulletin board.\n");
    write("\
This is a bulletin board.\n\
Usage : note <headline>, read/remove <message number>, catchup,\n\
	store <message number> <file name>\n");

    switch (i = sizeof(headers)) {
	case 0:
	    write("The board is empty.\n");
	    break;
	case 1:
	    write("The bulletin board contains 1 note :\n\n");
	    break;
	default:
	    write("The bulletin board contains " + i + " notes :\n\n");
	    break;
    }

    if (ob = MEMOBJ(this_player()))
	read = (int *) ob->new_notes(BoardName);
    if (!pointerp(read))
	read = ({ });

    for (j = 0; j < i; j++) {
	if (member_array(identifiers[j], read) >= 0)
	    write(" ");
	else
	    write("*");
	write((j + 1) + ":\t" + headers[j] + "\n");
    }
}


string
short ()
{
    string          str;
    object          ob;
    int             new;

    if (str = short_desc) {
	switch (new = sizeof(identifiers)) {
	    case 0: str += ". It is empty"; break;
	    case 1: str += ". It contains a single note"; break;
	    default: str += ". It contains " + new + " notes"; break;
	}
	if (ob = MEMOBJ(this_player())) {
	    new = (int) ob->new_notes(BoardName, identifiers);
	    str += " [" + new + " new]";
	}
    }
    return str;
}


int
get ()
{
    write("It is firmly secured.\n");
    return 0;
}



status
cmdNote (string header)
{
    object ed;

    if (!header)
	return 0;
    if (sizeof(headers) >= size) {
	write("You have to remove an old message first.\n");
	return 1;
    }
    if (strlen(header) > 50) {
	write("Message header too long. Try again.\n");
	return 1;
    }
    say(this_player()->query_name() + " starts writing a note.\n");

    ed = clone_object(EDITOR);
    move_object(ed, this_player());
    write("\
You have been given a piece of parchment on which to write the note.\n");
    ed->evBegin(({
	capitalize((string) this_player()->query_real_name()),
	this_player()->query_level(), 
	header,
	ctime()[4..9],
	}));
    return 1;
}


void
evNewNote(string *header, string *text)
{
    if (!text || !sizeof(text)) {
	write("You decide to throw the empty piece of paper away.\n");
	return;
    }
    headers += ({
	header[2] +
	"(" + header[0] + ", " + header[3] + ", " + header[1] + ")"
	});
    messages += ({ implode(text, "\n") });
    identifiers += ({ NextID++ });
    save_board();

    say(header[0] + " has completed a note : " + header[2] + "\n");
    write("Ok.\n");
}


int
cmdRead (string str)
{
    int             note;
    object          ob;

    if (!str || (!sscanf(str, "%d", note) &&
		 !sscanf(str, "note %d", note)))
	return 0;
    if (note < 1 || note > sizeof(headers)) {
	write("Not that many messages.\n");
	return 1;
    }
    note--;
    say(this_player()->query_name() + " reads a note titled '" + headers[note] + "'.\n");
    write("The note is titled '" + headers[note] + "':\n\n");
    write(messages[note]);
    write("\n\t\t\t*** End of note " + (note + 1) + " ***\n");

    if (ob = MEMOBJ(this_player()))
	ob->read_note(BoardName, ({ identifiers[note] }));
    return 1;
}


int
cmdRemove (string str)
{
    string          author, title, date;
    int             note;

    if (!str || (!sscanf(str, "%d", note) &&
		 !sscanf(str, "note %d", note)))
	return 0;
    if (note < 1 || note > sizeof(headers)) {
	write("That message doesn't exist.\n");
	return 1;
    }
    if (sscanf(headers[--note], "%s(%s,%s", title, author, date) != 3) {
	error_log("Header error");
	write("Board : error - header corrupt.\n");
	return 1;
    }
    if (!(interactive(this_player()) && valid_edit(author))) {
	write("You are not allowed to do that.\n");
	say(this_player()->query_name() + " failed to remove a note.\n");
	return 1;
    }
    title = headers[note];
    messages = deletea(messages, note, note);
    headers = deletea(headers, note, note);
    identifiers = deletea(identifiers, note, note);
    save_board();

    say(this_player()->query_name() + " removes a note titled '" + title + "'.\n");
    write("Ok.\n");
    return 1;
}


int
cmdStore(string str)
{
    int             note;
    string          file;

    if (1 || !str)
	return 0;
    if ((int) this_player()->query_level() < APPRENTICE)
	return 0;

    if (!str || (sscanf(str, "%d %s", note, file) != 2 &&
		 sscanf(str, "note %d %s", note, file) != 2))
	    return 0;
    if (note < 1 || note > sizeof(headers)) {
	write("That message doesn't exist.\n");
	return 1;
    }
    note--;
    file = file + ".note";
    write_file(file, headers[note] + "\n" + messages[note] + "\n");
    return 1;
}


status
cmdCatchup (string str)
{
    object      ob;

    if (ob = MEMOBJ(this_player()))
	ob->read_note(BoardName, identifiers);
    write("All notes are now marked as read.\n");
    return 1;
}
