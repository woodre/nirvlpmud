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
#define SAVE_PATH "/players/guilds/bards/bard_lib/save/boards/"
#define MEMOBJ(x) (x ? present("guild_object", x) : 0)
inherit BASE;

string          *messages;      /* array of messages */
				/* ^^^ for backwards comp only */
string          *headers;       /* array of headers */
				/* ^^^ for backwards comp only */
int             *identifiers;   /* ids for the current notes */
mixed           Headers;        /* array of arrays */
mixed           Threads;        /* another array of arrays */
int             NextID;         /* next available id */

static string   BoardName;      /* will be saved to this file name */
				/* if not set, the board is never saved */
static int      Size;           /* maximum number of messages */
static string   ShortDesc;      /* used to compose short() */
static string   *EditOk;        /* people allowed to remove notes */
static mixed    ValidRead;  

#define ART_FILE(x) (SAVE_PATH + BoardName + "/" + x)

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
    add_action("cmdCatchup", "catchup");
    add_action("cmdJoin", "join");
    add_action("cmdList", "list");
    add_action("cmdGook", "gook");
}

/* backwards compatibility start */
static int save_board();
status cmdGook() {
    int i;
    string f;

    if (!messages || this_player()->query_level() < 50) return 0;
    mkdir(SAVE_PATH + BoardName);
    for (i = 0; i < sizeof(identifiers); i++) {
	f = ART_FILE(identifiers[i]);
	write("Saving file " + i + "\n");
	/*rm(f);*/
	if (!write_file(f, messages[i]))
	    write("Failed to save: " + f + "\n");
    }
    messages = 0;
    save_board();
    return 1;
}


int DayFromDate(string date) {
    int t;
    t = atoi(extract(date, 4));
    switch (date[0..2]) {
	case "Dec": t += 30;
	case "Nov": t += 31;
	case "Oct": t += 30;
	case "Sep": t += 31;
	case "Aug": t += 31;
	case "Jul": t += 30;
	case "Jun": t += 31;
	case "May": t += 30;
	case "Apr": t += 31;
	case "Mar": t += 29; /* 1996 */
	case "Feb": t += 31;
	case "Jan": break;
    }
    return t;
}
/* backwards compatibility end */

void
set_name (string str)
{
    BoardName = str;

    /* load old messages. this allocates the arrays too */
    if (!restore_object(extract(SAVE_PATH + BoardName, 1))) {
	mkdir(SAVE_PATH + BoardName);
	Headers = ({ });
	identifiers = ({ });
    }

/* backwards compatibility start */
    if (!Headers) {
	int i, level, t, today, midnight;
	string title, author, date;

	Headers = allocate(sizeof(headers));
	today = DayFromDate(ctime()[4..9]);
	midnight = time();
	midnight -= midnight%86400;

	for (i = 0; i < sizeof(headers); i++) {
	    if (sscanf( headers[i],
			"%s(%s, %s, %d)",
			title, author, date, level) == 4)
	    {
		t = DayFromDate(date);
		if (t > today) t -= 366;
		t = (t - today)*86400 + midnight;
		Headers[i] = ({ author, level, title, t, });
	    }
	    else {
		Headers[i] = ({ "Unknown", 0, headers[i], time(), });
	    }
	}
    }
    headers = 0;
    
    if (!identifiers) {         /* the identifiers were added later */
	int j;
	identifiers = ({ });
	for (j = 0; j < sizeof(headers); j++)
	    if (headers[j])
		identifiers += ({ NextID++ });
	headers = headers[0..sizeof(identifiers) - 1];
	messages = messages[0..sizeof(identifiers) - 1];
    }
/* backwards compatibility end */
}

void
set_editors(string *eds)
{
    EditOk = eds;
}

void
set_readers(mixed x)
{
    ValidRead = x;
}

void
set_size (int n)
{
    Size = n;
}

void
set_short (string str)
{
    ShortDesc = str;
}


static status
valid_edit(string author)
{
    string name;

    name = (string) this_player()->query_real_name();
    if (author && name == lower_case(author)) return 1;
    if ((int) this_player()->query_level() >= ELDER) return 1;
    if (pointerp(EditOk) && member_array(name, EditOk) >= 0) return 1;
    return 0;
}

static status
valid_read(object who)
{
    if (valid_edit(0)) return 1;
    if (closurep(ValidRead)) 
	if (!funcall(ValidRead, who)) return 0;
    return 1;
}

static int
save_board ()
{
    if (BoardName)
	save_object(extract(SAVE_PATH + BoardName, 1));
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
long (string arg)
{
    int         i, j;
    object      ob;
    int        *read;

    say(this_player()->query_name() + " studies the bulletin board.\n");
    if (!valid_read(this_player())) {
	write("\
It is a bulletin boards.\n\
The notes are written in a language that you cannot understand.\n");
	return;
    }
    write("\
This is a bulletin board.\n\
Usage : note <headline>, read/remove <message number>, catchup,\n\
	store <message number> <file name>\n");

    switch (i = sizeof(identifiers)) {
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
	write((j + 1) + ":\t" + Headers[j][2] + " (" + Headers[j][0] + ")\n");
    }
}


string
short ()
{
    string          str;
    object          ob;
    int             new;

    if (str = ShortDesc) {
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

    if (!header || !valid_read(this_player()))
	return 0;
    if (Size && sizeof(identifiers) >= Size) {
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
	time(),
	}));
    return 1;
}


void
evNewNote(mixed *header, string *text)
{
    if (!text || !sizeof(text)) {
	write("You decide to throw the empty piece of paper away.\n");
	return;
    }
    write_file(ART_FILE(NextID), implode(text, "\n") + "\n");
    Headers += ({ header });
    identifiers += ({ NextID++ });
    save_board();

    say(header[0] + " has completed a note : " + header[2] + "\n");
    write("You stick your note onto the bulletin board.\n");
}


int
cmdRead (string str)
{
    int             note;
    object          ob;
    mixed           header;

    if (!str || !valid_read(this_player()) ||
	(!sscanf(str, "%d", note) && !sscanf(str, "note %d", note)))
	return 0;
    if (note < 1 || note > sizeof(identifiers)) {
	write("Not that many messages.\n");
	return 1;
    }
    header = Headers[--note];
    say(this_player()->query_name() + " reads a note titled '" +
	header[2] + "'.\n");
    write("The note is titled '" + header[2] + "'\n");
    write("Written " + ctime(header[3])[4..9] +
	  " by " + header[0] + " (level " + header[1] + ")\n\n");
    cat(ART_FILE(identifiers[note]));
    /* it might be better to more the file..
    write(read_file(ART_FILE(identifiers[note])));*/
    write("\n\t\t\t*** End of note " + (note + 1) + " ***\n");

    if (ob = MEMOBJ(this_player()))
	ob->read_note(BoardName, ({ identifiers[note] }));
    return 1;
}


int
cmdRemove (string str)
{
    mixed           header;
    int             note;

    if (!str || (!sscanf(str, "%d", note) &&
		 !sscanf(str, "note %d", note)))
	return 0;
    if (note < 1 || note > sizeof(identifiers)) {
	write("That message doesn't exist.\n");
	return 1;
    }
    if (note > sizeof(Headers) || !(header = Headers[--note])) {
	error_log("Error - header corrupt");
	return 1;
    }
    if (!(interactive(this_player()) && valid_edit(header[0]))) {
	write("You are not allowed to do that.\n");
	say(this_player()->query_name() + " failed to remove a note.\n");
	return 1;
    }
    if (!rm(ART_FILE(identifiers[note])))
	error_log("Failed to remove file: " + identifiers[note] + "\n");
    Headers = deletea(Headers, note, note);
    identifiers = deletea(identifiers, note, note);
    save_board();

    say(this_player()->query_name() + " removes a note titled '" +
	header[2] + "'.\n");
    write("Ok.\n");
    return 1;
}


status
cmdCatchup (string str)
{
    object      ob;

    if (ob = MEMOBJ(this_player())) {
	ob->read_note(BoardName, identifiers);
	write("All notes are now marked as read.\n");
    }
    return 1;
}

static void
ListAll(object ob, status unread)
{
    int         *read, i, j;

    switch (i = sizeof(identifiers)) {
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

    if (ob)
	read = (int *) ob->new_notes(BoardName);
    if (!pointerp(read))
	read = ({ });

    for (j = 0; j < i; j++) {
	if (member_array(identifiers[j], read) >= 0) {
	    if (unread) continue;
	    write(" ");
	}
	else
	    write("*");
	write(pad(j + 1, -4) + ": " + Headers[j][2] + " (" + Headers[j][0] + ")\n");
    }
}

static void
ListThreads(object ob)
{
    int         *read, i, j;

    if (pointerp(Threads))/* 3.1.2-DR comp */
    i = sizeof(Threads);

    for (j = 0; j < i; j++) {
	write(pad(j + 1, -2) + ": ");
	if (sizeof(Threads[j]) > 1)
	    write("+" + pad(sizeof(Threads[j]), 2) + " ");
	else
	    write("    ");
    }
}

status
cmdList(string str)
{
    if (!str) str = "unread"; /* 312dr does not allow mixed case labels */
    switch (str) {
	case "all":
	    ListAll(MEMOBJ(this_player()), 0);
	    break;
	case "unread":
	    ListAll(MEMOBJ(this_player()), 1);
	    break;
	case "threads":
	    ListThreads(MEMOBJ(this_player()));
	    break;
	default:
	    notify_fail("List what?\n");
	    return 0;
    }
    return 1;
}
