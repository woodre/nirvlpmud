#include "/players/balowski/lib.h"
#include "/players/balowski/std/ansi.h"
#include <security.h>
#define MAX_HISTORY 10
#define MAX_TELLBLOCK 20

inherit OBJECT;
inherit ANSI;

string SayColour, TellColour, WhisperColour, ResetColour;
mixed *TellHistory, *SayHistory;
string LastName;
string AfkMessage;
string *TellBlocks;

string query_afk_message() { return AfkMessage;}

void
create()
{
    ::create();

    set_name("bucket");
    set_ids(({"paint", "bucket of paint",}));
    set_short("A bucket of paint");
    set_long("\
The gleaming metal bucket features a white label partly covered in\n\
paint residues.  You are able to make out most of the writing:\n\
  Pry off the lid and stick your sharp tongue in the paint\n\
  Carefully read the instructions (help bucket) before use\n\
");
    SayColour = TellColour = WhisperColour = ESC + FOREGROUND + CYAN + "m";
    ResetColour = ESC + RESET + "m";
    TellHistory = ({ });
    SayHistory = ({ });
    TellBlocks = ({ });
}

status drop(int silently) { return 1;}

string
query_auto_load()
{
    return basename(this_object()) + ":" +
      SayColour + "-" + TellColour + "-" + WhisperColour + "-" + ResetColour;
}

void
init_arg(string arg)
{
    call_out("move_me", 10);
    if (!arg) return;
    sscanf(arg, "%s-%s-%s-%s",
	   SayColour, TellColour, WhisperColour, ResetColour);
}

void move_me() { move_object(this_object(), environment());}

status wizardp(object ob) { return (int) ob->query_level() > WIZARD;}

status IsVisible(object item, object viewer)
{
    return ((int) item->query_invis((int) viewer->query_level()) <= 0);
}

status IsBlocking(string name)
{
    return
      (member_array("*", TellBlocks) >= 0 ||
       member_array(lower_case(name), TellBlocks) >= 0);
}

void
init()
{
    if (environment() == this_player()) {
	add_action("cmdTell", "tell");
	add_action("cmdAfk", "afk");
	add_action("cmdReply", "reply");
	add_action("cmdTellblock", "tellblock");
	add_action("cmdWhisper", "whisper");
	add_action("cmdSay", "say");
	add_action("cmdSay"); add_xverb("'");
	add_action("cmdPaint", "paint");
	add_action("cmdRefresh", "refrez");
	add_action("cmdSplash", "splash");
	add_action("cmdTurpentine", "turpentine");
	add_action("cmdHelp", "help");
    }
}

status
cmdRefresh(string arg)
{
    if (id(arg)) return (move_object(this_object(), this_player()), 1);
    return 0;
}

void
receive_message(string type, string name, string msg)
{
    switch (type) {
    case "tell":
	/* this is (a little) patchy */
	if (name[0] == '*') {
	    name = "You tell " + extract(name, 1) + ": ";
	}
	else {
	    LastName = name;	/* save name for reply */
	    name = name + " tells you: ";
	}
	msg = format(name + msg + "\n");
	msg = extract(msg, strlen(name));
	msg = TellColour + name + ResetColour + msg;
	tell_object(environment(), msg);
	
	if (sizeof(TellHistory) >= MAX_HISTORY) {
#ifdef __VERSION__
	    TellHistory = TellHistory[1 .. ];
#else
	    TellHistory = extract(TellHistory, 1);
#endif	    
	}
	TellHistory += ({ msg });
	break;

    case "say":
    case "moan":
	if (name == "*") {
	    name = "You " + type + ": ";
	}
	else {
	    name = name + " " + type + "s: ";
	}
	msg = format(name + msg + "\n");
	msg = extract(msg, strlen(name));
	msg = SayColour + name + ResetColour + msg;
	tell_object(environment(), msg);

	if (sizeof(SayHistory) >= MAX_HISTORY) {
#ifdef __VERSION__
	    SayHistory = SayHistory[1 .. ];
#else
	    SayHistory = extract(SayHistory, 1);
#endif	    
	}
	SayHistory += ({ msg });
	break;
    case "whisper":
	break;
    default:
	tell_object(environment(), "Unknown message received.\n");
	break;
    }
}

status
show_tells()
{
    int i;
    
    for (i = 0; i < sizeof(TellHistory); i++) {
	write(TellHistory[i]);
    }
}

status
do_tell(string who, string msg)
{
    object ob, paint;
    int mylevel, rlevel;
    string nom, afk;
    
    if (this_player()->query_ghost()) {
	write("Your ghostly state prevents you.\n");
	return 1;
    }
    if (this_player()->query_sp() < 0) {
	write("You are low on power.\n");
	return 1;
    }
    who = lower_case(who);
    mylevel = (int) this_player()->query_level();
    if (!(ob = (find_player(who) || find_living(who)))
    ||	(int) ob->query_invis(mylevel) > 0) {
	write("No person with that name.\n");
	return 1;
    }
    if (ob == this_player()) return (write("Don't be silly.\n"), 1);

    rlevel = (int) ob->query_level();
    who = (string) ob->query_name();
    paint = present("bucket of paint", ob);

    if (interactive(ob)) {
        if (mylevel < GOD && in_editor(ob)) {
	    write("That person is editing. Please try again later.\n");
	    return 1;
	}
	if (mylevel < WIZARD) {
	    if ((paint && paint->IsBlocking(this_player()->query_real_name()))
	    ||  (!paint && ob->query_tellblock())) {
		write("That person is not listening to tells at the moment.\n");
		return 1;
	    }
	    if (IsBlocking(who)) {
		write("You are blocking communcation with that person.\n");
		return 1;
	    }
	}
	if (query_idle(ob) > 120)
	  write(who + " is idle at the moment. You may not get a response right away.\n");
    }
    else {
	if (!ob->query_npc()) write(who + " is disconnected.\n");
    }

    /* only allow elders to do the Someone thang */
    if (mylevel < ELDER && this_player()->query_invis(rlevel) > 0) {
	write("Don't be annoying.  Become visible before you talk to someone!\n" );
	return 1;
    }
    /* if I am a wizard and talking to a equal/superior, show my real name */
    if (mylevel >= EXPLORE && mylevel < ELDER && rlevel >= mylevel &&
	this_player()->query_invis())
      nom = "(Invis) " + (string) this_player()->query_real_name();
    else
      nom = (string) this_player()->query_name();


    if (ob->is_player()) {
	if (paint) {
	    /* check if receiver has set an afk msg */
	    if (afk = (string) paint->query_afk_message()) {
		write("You sense that " + who + " has left a message:\n'" +
		      afk + "'\n");
	    }
	    /* let receiver do the formatting */
	    paint->receive_message("tell", nom, msg);
	}
	else {
	    string str;
	    str = format(nom + " tells you: " + msg + "\n");
/*
	    str = extract(str, strlen(nom) + 12);
	    str = TellColour + nom + " tells you: " + ResetColour + str;
*/
	    tell_object(ob, str);
	}
    }
    else tell_object(ob, nom + " tells you: " + msg + "\n");

    receive_message("tell", "*" + who, msg);

    if (mylevel < EXPLORE) this_player()->add_spell_point(-1);
    return 1;
}

status
cmdTell(string arg)
{
    string who, msg;

    if (!arg) return (notify_fail("You tell.\n"), 0);
    
    if (arg == "/hist") {
	show_tells();
	return 1;
    }
    if (sscanf(arg, "%s %s", who, msg) == 2) {
	do_tell(who, msg);
	return 1;
    }
    return (notify_fail("Tell what?\n"), 0);
}

status
cmdWhisper(string arg)
{
    object ob;
    string who, msg, name;
    
    if (!arg || sscanf(arg, "%s %s", who, msg) != 2) {
	notify_fail("Usage: whisper <whom> <what>\n");
	return 0;
    }
    if (this_player()->query_ghost()) {
	write("Your ghostly state prevents you.\n");
	return 1;
    }
    ob = present(who, environment(this_player()));
    if (!ob || !living(ob)) {
	write("Nobody with that name in this room.\n");
	return 1;
    }
    who = ob->query_name() || "Someone";
    name = this_player()->query_name() || "Someone";

    write("You whisper to " + who + ": " + msg + "\n");
    tell_object(ob, name + " whispers to you: " + msg + "\n");
    say(name + " whispers something to " + who + ".\n", ob);
    return 1;
}

status
show_says()
{
    int i;
    
    for (i = 0; i < sizeof(SayHistory); i++) {
	write(SayHistory[i]);
    }
}

status
cmdSay(string arg)
{
    string nom, str, type, temp, uncooked;
    object next, ob, me, paint;
    
    if (!arg) return (notify_fail("Say what?\n"), 0);
    if (!environment(this_player())) return (write("You are nowhere.\n"), 1);

    if (arg == "/hist") {
	show_says();
	return 1;
    }
    
    me = this_player();
    nom = (string) me->query_name() || "Someone";
    type = "say";
    if (me->query_ghost()) {
	nom = "The ghost of " + nom;
	type = "moan";
    }
    
    receive_message(type, "*", arg);

    temp = nom + " " + type + "s: ";
    uncooked = temp + arg + "\n";
    str = format(uncooked);
/*
    str = extract(str, strlen(temp));
    str = SayColour + temp + ResetColour + str;
*/

    /* this is more or less a simulation of the say() function */
    /* first send messages to all living creatures in same room */
    next = first_inventory(environment(this_player()));
    while (ob = next) {
	next = next_inventory(ob);
	if (!living(ob) || ob == me) continue;
	if (ob->is_player()) {
	    if (paint = present("bucket of paint", ob)) {
		paint->receive_message(type, nom, arg);
	    }
	    else tell_object(ob, str);
	}
	else tell_object(ob, uncooked);
    }
    
    /* send message to environment if it's alive */
    ob = environment(this_player());
    if (living(ob)) {
	if (ob->is_player()) {
	    if (paint = present("bucket of paint", ob)) {
		paint->receive_message(type, nom, arg);
	    }
	    else tell_object(ob, str);
	}
	else tell_object(ob, uncooked);
    }

    /* send message to all livings in players inv */
    next = first_inventory(this_player());
    while (ob = next) {
	next = next_inventory(ob);
	if (living(ob)) {
	    if (ob->is_player()) {
		if (paint = present("bucket of paint", ob)) {
		    paint->receive_message(type, nom, arg);
		}
		else tell_object(ob, str);
	    }
	    else tell_object(ob, uncooked);
	}
    }
    
    return 1;
}

status
cmdReply(string arg)
{
    if (!arg) return (notify_fail("Reply what?\n"), 0);

    if (!LastName) {
	write("You have nobody to reply to.\n");
	return 1;
    }

    /* a little crude, maybe I'll change it.. */
    return cmdTell(LastName + " " + arg);
}

status
cmdAfk(string arg)
{
    if (!arg) {
	if (AfkMessage) write("Current afk message is: " + AfkMessage + "\n");
	else write("Afk message is not set.\n");
	return 1;
    }
    
    if (arg == "|") {
	AfkMessage = 0;
	write("Afk message has been cleared.\n");
	return 1;
    }

    if (strlen(arg) > 160) {
	write("Control yourself!\n");
	return 1;
    }
    
    AfkMessage = arg;
    write("Your afk message has been set.\n");
    return 1;
}

void
show_tellblocks()
{
    int i, end;
    string str;
    
    end = sizeof(TellBlocks);
    for (i = 0; i < end; i++) {
	write(TellBlocks[i] + "\n");
    }
    if (!end) {
	write("Whoa, nobody!\n");
    }
}

status
cmdTellblock(string arg)
{
    string *names, *tmp;
    
    if (!arg) {
	write("You are currently blocking communication with:\n");
	show_tellblocks();
	return 1;
    }
    if (arg == "|") {
	TellBlocks = ({	});
	write("Tellblock has been cleared.\n");
	this_player()->set_tellblock(0);
	return 1;
    }
    if (arg == "-") {
	write("You can't do that.\n");
	return 1;
    }
    if (arg[0] == '-') {
	arg = extract(arg, 1);
	names = explode(arg, ",");
	TellBlocks -= names;
    }
    else {
	int i;
	names = ({ });
	i = sizeof(tmp = explode(arg, ",") - ({ "" }));
	while (i--) {
	    if (member_array(tmp[i], TellBlocks) < 0) names += ({ tmp[i] });
	}
	if (sizeof(TellBlocks) + sizeof(names) > MAX_TELLBLOCK) {
	    write("You can't have more than " + MAX_TELLBLOCK + " entries.\n");
	    return 1;
	}
	TellBlocks += names;
    }
    this_player()->set_tellblock(sizeof(TellBlocks));
    write("You are now blocking communication with:\n");
    show_tellblocks();
    return 1;
}

status
cmdPaint(string arg)
{
    string item, colour, tmp;
    string *arr;
    int i, mask;
    
    if (!arg) {
	write("Your colours are:\n" +
	      SayColour + "say" + ResetColour + ", " +
	      TellColour + "tell" + ResetColour + ", and " +
	      WhisperColour + "whisper" + ResetColour + ".\n");
	return 1;
    }
    if (sscanf(arg, "%s %s", item, colour) != 2) {
	item = arg;
	colour = 0;
    }

    if (colour) {
	tmp = makeansi(colour);
	if (!tmp) {
	    /*write("'" + colour + "' is not a valid colour. See the help.\n");*/
	    return 1;
	}
    }
    
    switch (item) {
    case "tell":
	TellColour = tmp || "";
	break;
    case "say":
	SayColour = tmp || "";
	break;
    case "whisper":
	WhisperColour = tmp || "";
	break;
    default:
	write("Hmm.. You can only paint tell, say, and whisper.\n");
	return 1;
    }
    if (tmp) {
	write("You have selected a colour for " + tmp + item + ResetColour + ".\n");
    }
    else {
	write("You have reset the colour for " + item + ".\n");
    }
    return 1;
}

status
cmdSplash(string arg)
{
    object ob, bucket;
    int i;
    
    ob = find_player(arg);
    if (!ob || !IsVisible(ob, this_player())) {
	write("No such person found.\n");
	return 1;
    }
    if (wizardp(ob) && !wizardp(this_player())) {
	write("You cannot splash wizards.\n");
	return 1;
    }
    if (present("bucket of paint", ob)) {
	write(ob->query_name() + " already has a bucket of paint.\n");
	return 1;
    }
    bucket = clone_object(basename(this_object()));
    if (i = transfer(bucket, ob)) {
	write("Failure code: " + i + "\n");
	return 1;
    }
    tell_object(ob, this_player()->query_name() +
		" splashes you with paint. You should look at your bucket.\n");
    write("Whee! You just covered " + ob->query_name() + " with paint.\n");
    return 1;
}

status
cmdTurpentine(string arg)
{
    if (arg) return 0;
    write("You rid yourself of your bucket and return to the grey world.\n");
    destruct(this_object());
    return 1;
}

status
cmdHelp(string arg)
{
    if (arg != "bucket") return 0;
    write("\
This piece of rubbish will cunningly enable you to:\n\
\n\
tell somebody Will you be my bosom friend?\n\
say /* remember to put something clever here */\n\
\n\
afk I am just taking a 5 minute nap on the divan\n\
afk |\n\
reply Oh man, do I really have to party with you?\n\
tell /hist\n\
say /hist\n\
\n\
The last five items work best if your neighbour has a bucket too.\n\
Splash the unfortunate! (that's a command too)\n\
Do 'turpentine' to get rid of the bucket again.\n\
New! paint tell/say/whisper some-colour\n\
And: tellblock rudeboy,rudegirl\n\
     (* means all, | to clear, prepend with - to remove names)\n\
Trimmed for brevity and because it is no fun to write help files.\n\
");
    return 1;
}
