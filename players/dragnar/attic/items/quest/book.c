/*
    Changelog:
	Bal 1996-03-15:
	+ added an #ifdef around save_object() to stop self-desting
	- fixed some typos in summary and made some lines < 80 chars
*/
#define SAVE_PATH "players/dragnar/code/"

int XYZ;

status
id(string str)
{
    return str == "notebook";
}

void
reset(int arg)
{
    if (!arg)
	XYZ=random(100000);
}

status get()
{
    return 1;
}

int
query_weight()
{
    return 1;
}

int
query_value()
{
    return 5000;
}

string
short()
{
    return "A notebook";
}

void
long()
{
	write(
"This is the notebook the scientist had, but it seems all of the\n"+
"pages have been ripped out except for one.  The top of the page is titled\n"+
"'Summary'.  It must have been important for the scientist to die to\n"+
"keep you from reading it.\n");
}

status
save_code()
{
    string file, code;

    code = "code";
    file = SAVE_PATH + code;

#ifdef __VERSION__
    // returns void
    save_object(file);
#else
    if (!save_object(file))
	destruct(this_object());
#endif

    return 1;
}

void
init()
{
    save_code();
    add_action("save_code","save_code");
    add_action("read","read");
}

status
read(string str)
{
    if (str != "summary") {
	notify_fail("Read what?\n");
	return 0;
    }
    write(
"\t\t\t\tSummary\n" +
"\t\t\t\t\t\tDr: Edward Kugler\n" +
"\t\t\t\t\t\tWest Virginia University\n" +
"\t\t\t\t\t\tAuthorization Code : "); 
    write(XYZ); 
    write(
"\n\n"+
"In the year 2003, there was a Nuclear war.  The land was destroyed.  Only\n"+
"the strongest of people survived.  Chaos ruled the land.  To survive the\n"+
"people joined together.  Two groups formed.  One group, the ancients, have\n"+
"gone back to a fighting lifestyle to protect themselves.  The other group,\n"+
"the darkside cult, worships Satan to get their powers.  I am neither and\n"+
"fear for my life...\n"+
"\tBoth groups believe in a portal within the ice mines that is connected\n"+
"connected to the past, before the war.  The ancients protect the caves with\n"+
"their lives.  They believe one day a chosen one will come into this world and\n"+
"save it.  The cult don't want to lose their power, and wish to destroy the\n"+
"portal.  It is believed that the portal needs a magical key, and the Darkside\n"+
"has the key it it's grasp.  The legend says they broke the key into 4 pieces,\n"+
"and one of the pieces is kept within the gates of Hell.  The other 3 are\n"+
"said to be protected in this world.\n"+
"\tI have written everything that I know in this notebook, although\n"+
"reality seems to have left with the sun.  I was a scientist once, but nothing\n"+
"in this world is like the one which I came from.  I am doomed here, but so is\n"+
"the rest of the Wastelands.\n");
    return 1;
}
