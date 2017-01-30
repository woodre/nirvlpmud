
/* 
 * Shardak guild - (tm) Dragnar/John
 * Shopkeeper is (c) Balowski/Rasmus, April 1st 1995.
 * Last change: Apr 16th '95 (teleport trial)
 *              Oct 16th '95 (list, buy, value commands)
 * To do: place command logging in log master..
 */
inherit "/obj/monster";

#include "../def.h"
#include "../tasks.h"
#define CMDLOG (LOGDIR + "commands")
#define HOME (PATH + "shop")
#define STORAGE (PATH + "backshop")
#define AT_HOME (file_name(environment()) == HOME)
#define IN_GUILD (file_name(environment())[0..strlen(PATH) - 1] == PATH)
#define TIME_TO_LEAVE 30


string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */
object          solvee;         /* the poor soul attempting a solve */
object          summoner;       /* the person who summoned me */


void
reset(status arg)
{
    if(arg) return;
   ::reset();
    mmsgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    set_race("demon");
    set_name("Demon merchant");
    set_alias("merchant");
    set_alt_name("demon");
    set_short("A demon merchant");
    set_long("\
This being is definitely not your average eight foot, awe-inspiring\n\
demon. It is of more human proportions and has a light grey hide,\n\
but at least it has large reptile eyes and tiny horns in its skull.\n\
The demon is shopkeeper and servant of Shardak.\n\
It is hauling a great brown sack.\n");
    set_race("demon");
    set_level(14);
    set_ac(11);
    set_wc(18);
    set_hp(210);
    set_al(-50);
}

/* No killing me */
status query_npc() { return 0;}

void init()
{
    ::init();
    add_action("cmdSell", "sell");
    add_action("cmdList", "list");
    add_action("cmdValue", "value");
    add_action("cmdBuy", "buy");

    if (this_player() == summoner)
	add_action("dismiss", "dismiss");  /* end business */
    if ((int) this_player()->query_level() > 19)
	add_action("debug", "debug");  /* for wizzes only */
}

status debug(string str)
{
    if (str && present(str, environment()) == this_object()) {
	write("catch_tell:\n\ttext = "); write(text);
	write("\n\treceiver = "); write(receiver);
	write("\nTrial:\n\tsolvee = "); write(solvee); write("\n");
	return 1;
    }
}

status cmdSell(string str)
{
    return (status) HOME->sell(str);
}

status cmdList(string str)
{
    return (status) HOME->list(str);
}

status cmdValue(string str)
{
    return (status) HOME->value(str);
}

status cmdBuy(string str)
{
    return (status) HOME->buy(str);
}

status dismiss(string str)
{
    /* okay, so this check is fooling a bit around.. */
    if (str && present(str, environment()) == this_object()) {
	if (AT_HOME) {
	    write("The demon merchant refuses to budge.\n");
	}
	else {
	    remove_call_out("leave");
	    say(this_player()->query_name() + " dismisses the demon merchant.\n");
	    this_object()->move_player("X#" + HOME);
	}
	return 1;
    }
    notify_fail("Dismiss who?\n");
    return 0;
}

status summon(object dest)
{
    if (AT_HOME && (find_call_out("move") < 0) && !solvee) {
	summoner = this_player();
	call_out("move", 2, dest);
	return 1;
    }
    else {
	write("\
The merchant tells you: Rather busy right now. Please, do call again.\n");
	return 0;
    }
}

void move(object dest)
{
    if (dest) {
        move_player("X#" + file_name(dest));
	call_out("leave", TIME_TO_LEAVE);
    }
}

void leave()
{
    move_player("X#" + HOME);
}

/*
 * Now the task/trial code
 * Perhaps parts could be placed in a seperate file..
 */
add_weight(int w)
{
    if (w > 0)
	if (!AT_HOME || first_inventory(this_object()))
	    return 0;           /* refuse more than one thing */
	else {
	    solvee = this_player();     /* only listen to this person */
	    call_out("received", 1);    /* proceed */
	    call_out("time_out", 30);   /* will end solve attempt */
	}

    return ::add_weight(w);
}

/*
 * The attempt made by 'solvee' is forfeit.
 */
void time_out()
{
    object ob;

    ob = first_inventory(this_object());
    if (ob) {
	/* now the thing is mine :-> */
	solvee = 0;
	say("\
The demon shrugs its shoulder and throws something into its sack.\n");
	if (transfer(ob, STORAGE))      /* returns 0 for success */
	    destruct(ob);       /* be very sure to get rid of it */
    }
}

void received()
{
    if (solvee && first_inventory(this_object())) {
        command("2heheheheheh", this_object());
	say("The demon looks curiously at the item it received.\n");
	say("The demon whispers something to " + solvee->query_name() + ".\n",
	    solvee);
	tell_object(solvee, "\
The demon whispers a little embarrassed to you: Er, excuse me. This\n\
Object of magical Teleportation.. How does One operate it? Just say\n\
the exact Words, nothing more, nothing less, and I shall make a Try.\n");
    }
}

void DoTalk()
{
    if (!text || !receiver) { text = 0; return;}
    tell_object(receiver, text);
    text = receiver = 0;
}

void catch_tell(string msg)
{
    string who, what;
    object mark;

    if (this_player())
	mark = present( GUILD_ID, this_player());
    if (!mark || !msg)
	return;

    /* while a trial is in process: */
    if (solvee && (this_player() == solvee)) {
	if (sscanf(msg, "%s says: %s", who, what) == 2) {
	    remove_call_out("time_out");
	    call_out("try_cmd", 1, what);
	    return;
	}
    }

    /* your basic chatting */
    if (!text && (sscanf( msg, "%s says: %s", who, what) == 2 ||
		  sscanf( msg, "%s asks: %s", who, what) == 2 ||
		  sscanf( msg, "%s tells you: %s", who, what) == 2)) {
	what = lower_case(what);
	if (sscanf(what, "%strial%s", who,who)) {
	    if (mark->query_solved(TELEPORT_TASK))
		text= "\
The demon answers, \"Seek out the Pyromancer, for he conducts your next Trial.\"\n";
	    else if (!(mark->query_solved(CORPSE_TASK)))
		text= "\
The demon answers, \"Seek out the Priest and pass his Trial first.\"\n";
	    else
		text= read_file(ABSPATH + "teleport_task");
	}
	else return;
	receiver = this_player();
	call_out("DoTalk", 2);
    }
}

/*
 * Issue the command spoken by 'solvee'
 */
void try_cmd(string cmd)
{
    object          ob;         /* object in inventory */
    string          ob_name;    /* file name of ob */

    /* log the command */
    if (ob = first_inventory(this_object()))
	ob_name = file_name(ob);
    else
	ob_name = "nothing";
    if (solvee)
	write_file( CMDLOG,
		    "Solvee: " + solvee->query_real_name() +
		    "\tObject: " + ob_name +
		    "\tCommand: " + cmd + "\n");

    /* something strange has happened */
    if (!AT_HOME) {
	say("The demon looks around at the unfamiliar surroundings.\n");
	time_out();
    }

    /* execute the command spoken by 'solvee' */
    cmd = implode(explode(cmd, "\n"), "");
    if (command(cmd)) {        /* did something */
	if (AT_HOME)
	    say("The demon mutters: Hmm.. I am afraid it didn't move me Anywhere.\n");
	else {
	    call_out("solved", 1);
	    return;
	}
    }
    else
	say("The demon exasperates: That surely didn't work. Any other fine Suggestions?\n");
    call_out("time_out", 10);
}

/*
 * 'Solvee' moved me
 * If I am outside the guild, then move back and reward him/her
 */
void solved()
{
    object ob, mark;

    if (IN_GUILD) {
        move_player("X#" + HOME);
	say("The demon hisses: I said 'outside the guild'. Understand?\n");
	call_out("time_out", 5);
	return;
    }

    move_player("X#" + HOME);
    if (ob = first_inventory(this_object()))
	destruct(ob);

    if (solvee) {
	say("The demon exclaims: A most able Device you have supplied.\n");
	say("The demon whispers something in demon tongue and " +
	    solvee->query_name() + " is enveloped\nin a frail red aura.\n",
	    solvee);
	tell_object(solvee, "\
The demon whispers something in demon tongue and you feel a small\n\
surge of knowledge and power.\n\
The demon tells you: You have been granted the Ability of Teleportation.\n\
Also feel free to summon me, if my Services are needed.\n");
	mark = present(GUILD_ID, solvee);
	if (mark) {
	    mark->add_solved(TELEPORT_TASK);
	    mark->save_me();            /* save guild info, init() restores */
	}
	solvee = 0;                     /* concluded */
    }
}
