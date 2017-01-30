/*
 * Editor was done by Balowski/Rasmus, 1996-04-14
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#define IPROMPT (InsLine + ">>")
#define CPROMPT ":"
inherit BASE;

int             Line, InsLine;
status          Numbers;
string         *Text, *NewText;
mixed           Header;
object          Server;

void InsertLoop(string str);
void CommandLoop(string cmd);

void
init()
{
    add_action("cmdScribble", "scribble");
}

int
id(string str)
{
    return str == "editor";
}

string
short()
{
    return "editor";
}

int
get()
{
    return 1;
}

int
drop()
{
    write("You cannot drop the editor.\n");
    return 1;
}

status
evBegin(mixed header)
{
    Line = 0;
    Text = 0;
    Header = header;
    Server = previous_object();
    CommandLoop("i");
    return 1;
}

status
cmdScribble(string arg)
{
    if (this_player()->query_level() < 20) return 0;
    evBegin(arg);
    return 1;
}

void
evNewNote(mixed header, string *text)
{
#ifdef __VERSION__
    printf("Header:\n%O\nText:\n%O\n", header, text);
#endif
}

mixed
DeleteLines(mixed a, int start, int end)
{
    if (!pointerp(a)) return a;
#ifdef __VERSION__
    if (start <= 0) return a[end + 1 .. ];
    if (end >= sizeof(a)) return a[0 .. start - 1];
    return a[0 .. start - 1] + a[start + 1 .. ];
#else
#  ifndef __LDMUD__ /* Rumplemintz */
    if (start <= 0) return a[end + 1 .. -1];
    if (end >= sizeof(a)) return a[0 .. start - 1];
    return a[0 .. start - 1] + a[start + 1 .. -1];
#  else
    if (start <= 0) return a[end + 1 .. <1];
    if (end >= sizeof(a)) return a[0..start-1];
    return a[0..start-1] + a[start+1..<1];
#  endif
#endif

}

int
ShowLines(int start, int end)
{
    int i;

    if (!Text) return 0;
    if (start < 0) start = 0;
    if (end >= sizeof(Text)) end = sizeof(Text) - 1;
    if (end - start > 19) end = start + 19;

    for (i = start; i <= end; i++)
	write(pad(i + 1, -3) + " " + Text[i] + "\n");
    return end;
}

void
CommandLoop(string cmd)
{
    int x;

    switch (cmd) {
    case 0:
	break;

    case "d":
	Text = DeleteLines(Text, Line, Line);
	break;

#ifdef __VERSION__
    case "debug":
	printf("Text:%O\nNewText:%O\nLine:%O\n", Text, NewText, Line);
	break;
#endif

    case "f":
	Text = explode(format(implode(Text, " ")), "\n");
	break;

    case "h":
	write(
		"EvilEd. A product of the Underworld.\n" +
		"d - delete current line\n" +
		"f - format text to 70 columns\n" +
		"h - show help\n" +
		"i - insert text (** or . to stop insert mode)\n" +
		"l - show current line\n" +
		"q - quit (discard everything)\n" +
		"x - conclude editing\n" +
		"z - show writings\n" +
		"<number> - set current line\n"
		);
	break;

    case "i":
	InsertLoop(0);
	return;

    case "l":
	ShowLines(Line, Line);
	break;

    case "q":
	write("Note abandoned.\n");
	destruct(this_object());
	return;

    case "x":
	if (Server) {
	    Server->evNewNote(Header, Text);
	    destruct(this_object());
	    return;
	}
	write("Editor error: Nowhere to send the note to.\n");
	break;

    case "z":
	Line = ShowLines(Line, sizeof(Text) - 1);
	break;

    default:
	if (sscanf(cmd, "%d%s", x, cmd)) {
	    if (x < 1 || x > sizeof(Text))
		write("No such line.\n");
	    else {
		Line = x - 1;
		ShowLines(Line, Line);
	    }
	}
	else
	    write("Unrecognized command.\n");
    }

    write(CPROMPT);
    input_to("CommandLoop");
}

void
InsertLoop(string str)
{
    switch (str) {
    case 0:
	NewText = 0;
	InsLine = Line + 1;
	break;

    case ".":
    case "**":
	if (NewText)
	    /* insert the NewText array in the Text array */
	    if (!Text) Text = NewText;
	    else if (Line >= sizeof(Text)) Text += NewText;
#ifdef __VERSION__
	    else Text = Text[0..Line - 1] + NewText + Text[Line..];
#else
#ifndef __LDMUD__ /* Rumplemintz */
	    else Text = Text[0..Line - 1] + NewText + Text[Line..-1];
#else
            else Text = Text[0..Line-1] + NewText + Text[Line..<1];
#endif
#endif
	CommandLoop(str == "**" ? "x" : 0);
	return;

    default:
	/* build the NewText array */
	if (NewText) NewText += ({ str }); else NewText = ({ str });
	InsLine++;
    }
    write(IPROMPT);
    input_to("InsertLoop");
}
