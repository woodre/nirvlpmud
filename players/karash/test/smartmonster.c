/*
 *  players/padrone/obj/smartmonster -- a (slightly) smart(er) monster
 *  Might also be avialable as "/obj/smartmonster".
 *  Thomas Padron-McCarthy, padrone@lysator.liu.se, 1992, 1993
 *  Share and enjoy! No rights reserved except the right to reserve rights.
 *
 *      Clone this object to get a generic monster,
 *	then use the different "set" and "add" functions to configure it.
 *	If this isn't enough, inherit it.
 *      Read the doc file about the smartmonster!
 *
 *  Small warning: Since this object inherits "/obj/monster", its function
 *  (for example, if it works at all) of course depends on what has been
 *  done to "/obj/monster". It also calls "query_cost" in "room/adv_guild".
 *
 *  Latest change to this file: Oct 8, 1993 by Padrone
 *
 */

#define SMARTMONSTER_VERSION	"0.6.2 (Oct 8, 1993)"

#pragma strict_types

inherit "obj/monster";

/* Define this if we are using Caution's wet-code (from NannyMUD): */
#define USE_WETCODE
/* Define this if we want compatibility with the old /obj/monster: */
#define MONSTER_COMPAT

/*---------------------------------------------------------------------------*/

/* For debugging - you can log all messages and actions on a file */

string log_file_name;

void set_log_file(string str) {
    log_file_name = str;
} /* set_log_file */

string query_log_file() {
    return log_file_name;
} /* query_log_file */

/*---------------------------------------------------------------------------*/

/*  More debugging stuff. Turn on whatever you think you need!
 *  SAY_CONFUSED is called when there was a small problem, like someone
 *  entering a room and then leaving before the smartmonster has time
 *  to handle the arrival message.
 *  SAY_ERROR is called when there was a more serious problem, like
 *  a bad argument to one of the setup functions.
 */

void say_confused(string str) {
    if (this_player() != this_object() && !this_player()->query_npc())
	tell_object(this_player(), cap_name + " (" + file_name(this_object()) + ") tells you: I am confused: " + str + "\n");
    else if (previous_object() != this_object() && living(previous_object()) && !previous_object()->query_npc())
	tell_object(previous_object(), cap_name + " (" + file_name(this_object()) + ") tells you: I am confused: " + str + "\n");
    else
	say(cap_name + " looks confused: " + str + "\n");
    if (log_file_name != 0)
	log_file(log_file_name, ctime(time()) + ": " + cap_name + " (" + file_name(this_object()) + ") was confused:\n    " + str + "\n");
} /* say_confused */

void say_error(string str) {
    string tell_message, log_message;

    tell_message = cap_name + " (" + file_name(this_object()) + ") tells you: I am confused: " + str + "\n";
    log_message = ctime(time()) + ": " + cap_name + " (" + file_name(this_object()) + ", creator: " + creator(this_object()) + ")\n    ERROR: " + str + "\n";
    if (this_player() != this_object())
	log_message += "    this_player() = " + this_player()->query_name() + " (" + file_name(this_player()) + ")\n";
    if (previous_object() != this_object())
	log_message += "    previous_object() = " + file_name(previous_object()) + "\n";

    if (this_player() != this_object() && !this_player()->query_npc())
	tell_object(this_player(), tell_message);
    else if (previous_object() != this_object() && living(previous_object()) && !previous_object()->query_npc())
	tell_object(previous_object(), tell_message);
    else
	say(cap_name + " looks very confused: " + str + "\n");
    log_file("smartmonster", log_message);
    if (creator(this_object()) != 0)
	log_file(creator(this_object()), log_message);
    if (log_file_name != 0 && log_file_name != creator(this_object()))
	log_file(log_file_name, log_message);
} /* say_error */

void debug_log(string str) {
    if (log_file_name != 0)
	log_file(log_file_name, ctime(time()) + ": " + cap_name + " (" + file_name(this_object()) + "): " + str + "\n");
} /* debug_log */

/*
#define DEBUG_LOG(str) log_file("smartmonster", cap_name + ": " + str + "\n")
#define DEBUG_LOG(str) 0
#define SAY_CONFUSED(str) 0
#define SAY_CONFUSED(str) say(cap_name + " looks confused: " + str + "\n")
#define SAY_ERROR(str) say(cap_name + " looks very confused: " + str + "\n")
*/

#define DEBUG_LOG(str)		debug_log(str);
#define SAY_CONFUSED(str)	say_confused(str)
#define SAY_ERROR(str)		say_error(str)

/*---------------------------------------------------------------------------*/

status handle_caught_texts;
			/* Do we care about catch_tell's or not? */
int aggressivity;	/* How likely is this monster to attack (0..100)? */
int wimpyness;		/* At which percentage of its hp will this monster run away? */
object kill_ob;		/* The object we will attack in the next heart_beat */

void smartwrite(mixed something);

/*---------------------------------------------------------------------------*/

string *aliases;	/* Array of alias names */

void add_alias(string str) {
    if (aliases == 0)
	aliases = ({ });
    aliases += ({ lower_case(str) });
} /* add_alias */

void set_aliases(string  *all_aliases) {
    if (all_aliases != 0 && !pointerp(all_aliases)) {
	SAY_ERROR("Bad argument to set_aliases.");
	return;
    }
    aliases = all_aliases;
} /* set_aliases */

string *query_aliases() {
    return aliases;
} /* query_aliases */

status id(string str) {
    string lstr;

    lstr = lower_case(str);
    if (lstr == lower_case(name))
	return 1;
    else
	return aliases && member_array(lstr, aliases) != -1;
} /* id */

/*---------------------------------------------------------------------------*/

string *chat_data;	/* The chat messages */
int chat_chance;	/* Chance to chat in every heartbeat */
status chat_in_fight;	/* If true, go on chatting even when in a fight */

void add_chat(string the_chat) {
    if (chat_data == 0)
	chat_data = ({ });
    chat_data += ({ the_chat });
} /* add_chat */

void set_chats(string *all_chats) {
    if (all_chats != 0 && !pointerp(all_chats)) {
	SAY_ERROR("Bad argument to set_chats.");
	return;
    }
    chat_data = all_chats;
} /* set_chats */

string *query_chats() {
    return chat_data;
} /* query_chats */

void set_chat_chance(int percentage) {
    chat_chance = percentage;
}

void set_chat_in_fight(status f) {
    chat_in_fight = f;
}

/*---------------------------------------------------------------------------*/

mixed response_object;	/* The object in which to call the functions */
mixed *response_data;
/*  response_data is an array of multiples of four elements, each of which is
 *    the action the monster will respond to (a string),
 *    the message to print in response to this action (a string),
 *    an (optional) special messages to the "opponent" (also a string),
 *    the chance for each response, if it matched (an integer 0..100)
 *    If the "message to print" starts with '*' or '!',
 *    it is used as a function to call or a command to give.
 *    It could also be an array of actions to perform.
 */

void add_response(string act, mixed response, mixed arg3, mixed arg4) {
    string opponent_msg;
    int chance;

    /*  Usage:
     *      add_response  ACTION  "REPLY-MESSAGE"  [ "PERSONAL-REPLY-MESSAGE" ]  [ CHANCE ]
     *      add_response  ACTION  "*FUNCTION-NAME"  [ CHANCE ]
     *      add_response  ACTION  "!COMMAND"  [ CHANCE ]
     *      add_response  ACTION  ARRAY-OF-RESPONSES  [ CHANCE ]
     */

    if (pointerp(response) || response[0] == '*' || response[0] == '!') {
	if (!intp(arg3) || arg4 != 0) {
	    SAY_ERROR("Bad arguments (arg 3 or 4) to add_response.");
	    return;
	}
	chance = arg3;
    }
    else if (!stringp(response)) {
	SAY_ERROR("Bad argument (response) to add_response.");
	return;
    }	
    else if ((stringp(arg3) || arg3 == 0) && intp(arg4)) {
	opponent_msg = arg3;
	chance = arg4;
    }
    else if (intp(arg3) && arg4 == 0) {
	chance = arg3;
    }
    else {
	SAY_ERROR("Bad arguments to add_response.");
	return;
    }

    if (chance == 0)
	chance = 100;

    if (response_data == 0)
	response_data = ({ });
    response_data += ({ act, response, opponent_msg, chance });

    handle_caught_texts = 1;
} /* add_response */

void set_responses(mixed *all_responses) {
    if (all_responses != 0 && !pointerp(all_responses)) {
	SAY_ERROR("Bad argument to set_responses.");
	return;
    }
    response_data = all_responses;
    if (response_data)
	handle_caught_texts = 1;
} /* set_responses */

mixed *query_responses() {
    return response_data;
} /* query_responses */

void set_response_object(mixed obj) {
    response_object = obj;
}

/*---------------------------------------------------------------------------*/

mixed *say_response_data;
/*  say_response_data is an array of multiples of four elements, each of which is
 *    the word or word the monster will respond to
 *	(a string, or an array of strings or arrays of strings)
 *    the message to print in response to this action (a string),
 *    an (optional) special messages to the "opponent" (also a string),
 *    the chance for each response, if it matched (an integer 0..100)
 *    If the "message to print" starts with '*' or '!',
 *    it is used as a function to call or a command to give.
 *    It could also be an array of actions to perform.
 */

void add_say_response(mixed word, mixed response, mixed arg3, mixed arg4) {
    string opponent_msg;
    int chance;

    /*  Usage:
     *      add_say_response  WORD  "REPLY-MESSAGE"  [ "PERSONAL-REPLY-MESSAGE" ]  [ CHANCE ]
     *      add_say_response  WORD  "*FUNCTION-NAME"  [ CHANCE ]
     *      add_say_response  WORD  "!COMMAND"  [ CHANCE ]
     *      add_say_response  WORD  ARRAY-OF-RESPONSES  [ CHANCE ]
     *	WORD can be either a string, or an array of strings or arrays of strings.
     */

    if (pointerp(response) || response[0] == '*' || response[0] == '!') {
	if (!intp(arg3) || arg4 != 0) {
	    SAY_ERROR("Bad arguments (arg 3 or 4) to add_say_response.");
	    return;
	}
	chance = arg3;
    }
    else if (!stringp(response)) {
	SAY_ERROR("Bad argument (response) to add_say_response.");
	return;
    }	
    else if ((stringp(arg3) || arg3 == 0) && intp(arg4)) {
	opponent_msg = arg3;
	chance = arg4;
    }
    else if (intp(arg3) && arg4 == 0) {
	chance = arg3;
    }
    else {
	SAY_ERROR("Bad arguments to add_say_response.");
	return;
    }

    if (chance == 0)
	chance = 100;

    if (say_response_data == 0)
	say_response_data = ({ });
    say_response_data += ({ word, response, opponent_msg, chance });

    handle_caught_texts = 1;
} /* add_say_response */

void set_say_responses(mixed *all_say_responses) {
    if (all_say_responses != 0 && !pointerp(all_say_responses)) {
	SAY_ERROR("Bad argument to set_say_responses.");
	return;
    }
    say_response_data = all_say_responses;
    if (say_response_data)
	handle_caught_texts = 1;
} /* set_say_responses */

mixed *query_say_responses() {
    return say_response_data;
} /* query_say_responses */

/*---------------------------------------------------------------------------*/

/* Substitute "$OTHER" with the opponent's name */
string substitute_other(string str, string opponents_name) {
    string part1, part2;

    while (sscanf(str, "%s$OTHER%s", part1, part2) == 2)
	str = part1 + opponents_name + part2;
    while (sscanf(str, "%s$LOWOTHER%s", part1, part2) == 2)
	str = part1 + lower_case(opponents_name) + part2;
    return str;
} /* substitute_other */

/*  This function is called when the response is to be performed
 *  - i. e. it matched, and the dice rolled our way!
 */
void perform_response(string opponents_name, string what, string how,
		      mixed response, string opponent_msg)
{

    DEBUG_LOG("perform_response('" + opponents_name + "', '" + what + "', '" + how + "', ...)");

    if (pointerp(response)) {
	/* This "response" is really an array of responses */
        if (opponent_msg) {
	    SAY_ERROR("Bad argument (opponent_msg) to perform_response.");
	    return;
	}
	else {
	    int i, n;

	    n = sizeof(response);
	    for (i = 0; i < n; ++i)
		perform_response(opponents_name, what, how, response[i], 0);
	}
    }
    else if (!stringp(response)) {
	SAY_ERROR("Bad argument (response) to perform_response.");
	return;
    }
    else if (response[0] == '!') {
	string cmd;
	sscanf(response, "!%s", cmd);
	command(substitute_other(cmd, opponents_name));
    }
    else if (response[0] == '*') {
	string fun;

	sscanf(response, "*%s", fun);
	fun = substitute_other(fun, opponents_name);

	DEBUG_LOG("Calling " + fun + "(\"" + opponents_name +
		  "\", \"" + what + "\", \"" + how + "\")");

	call_other(response_object, fun, opponents_name, what, how);
    }
    else {
	object opponent_obj;

	if (opponent_msg && opponents_name)
	    opponent_obj = present(opponents_name);

	if (opponent_obj) {
	    tell_object(opponent_obj, substitute_other(opponent_msg, opponents_name));
	    say(substitute_other(response, opponents_name), opponent_obj);
        }
	else
	    say(substitute_other(response, opponents_name));
    }
} /* perform_response */

/*---------------------------------------------------------------------------*/

status match_responses(string str) {
    string who, what, how, msg, opponent_msg, junk;
    int i, n;
    object opponent;

#ifdef MONSTER_COMPAT
    if (talk_ob)
	test_match(str);
#endif

    if (response_data == 0)
	return 0;
    n = sizeof(response_data);
    /* Backwards. New responses that are added should be tested before old ones. */
    for (i = n - 4; i >= 0; i -= 4) {
	what = response_data[i];
	/* how = ""; */

	/*  As it is now, the action "smiles" matches all of "X smiles\n",
	 *  "X smiles.\n", "X smiles like a surgeon.\n" and "X smilesiglurps.\n".
	 *  Maybe it should match "X smiles\n", "X smiles.\n"
	 *  and "X smiles like a surgeon.\n" but not "X smilesiglurps.\n"?
	 */
	if (   sscanf(str, "%s " + what + " %s\n", who, how) == 2
	    || sscanf(str, "%s " + what, who) == 1) {

	    if (random(100) < response_data[i + 3]) {
		msg = response_data[i + 1];
		opponent_msg = response_data[i + 2];

		/* The "who" from the last sscanf could be too long! */
		/* sscanf(who, "%s %s\n", who, junk); */

		if (how == 0)
		    how = "";

		perform_response(who, what, how, msg, opponent_msg);
		return 1;
	    }
	} /* if this response matched */
    } /* for all stored responses */
    return 0;
} /* match_responses */

/*---------------------------------------------------------------------------*/

string *split_into_words(string str) {
    int wordstart, pos, afterpos;
    int c, nl;
    string *result;

    afterpos = strlen(str);
    result = ({ });
    pos = 0;
    nl = "\n"[0];  /* Grr! '\n' doesn't work! */
    while (pos < afterpos) {
	/* First, skip leading blanks and interpunctation. */
	while (   pos < afterpos
	       && (((c = str[pos]) == ' ') || c == nl || c == '.'
		   || c == '?' || c == '!' || c == ',' || c == ':'))
	    ++pos;
	wordstart = pos;
	/* If we haven't reached the end of the string,
	 * take the word that starts here.
	 */
	if (pos < afterpos) {
	    while (   pos < afterpos
		   && ((c = str[pos]) != ' ') && c != nl && c != '.'
		   && c != '?' && c != '!' && c != ',' && c != ':')
		++pos;
	    result += ({ str[wordstart..pos-1] });
	}
    }
    return result;
} /* split_into_words */

/*---------------------------------------------------------------------------*/

status match_say_responses(object opponent, string who, string phrase) {
    mixed datawords;
    string msg, opponent_msg;
    int i, n, word_nr, nr_datawords;
    string *inputwords;

    if (say_response_data == 0)
	return 0;
    inputwords = split_into_words(lower_case(phrase));
    n = sizeof(say_response_data);
    /* Backwards. New responses that are added should be tested before old ones. */
    for (i = n - 4; i >= 0; i -= 4) {
	datawords = say_response_data[i];
	if (pointerp(datawords)) {
	    /* "datawords" was an array of words. Match against each of them! */
	    nr_datawords = sizeof(datawords);
	    for (word_nr = 0; word_nr < nr_datawords; ++word_nr) {
		if (member_array(datawords[word_nr], inputwords) != -1) {
		    msg = say_response_data[i + 1];
		    opponent_msg = say_response_data[i + 2];
		    perform_response(who, "(says)", phrase, msg, opponent_msg);		
		    return 1;
		}
	    } /* for each word in the array */
	}
	else {
	    /* "datawords" was just a single word. Match against it! */
	    if (member_array(datawords, inputwords) != -1) {
		msg = say_response_data[i + 1];
		opponent_msg = say_response_data[i + 2];
		perform_response(who, "(says)", phrase, msg, opponent_msg);		
		return 1;
	    }
	}
    } /* for all stored say_responses */
    return 0;
} /* match_say_responses */

/*---------------------------------------------------------------------------*/

mixed say_handler_obj;	/* The object in which to call... */
string say_handler_fun;	/* ...this function when the monster hears a "say" */

void set_say_handler(mixed obj, string fun) {
    if (obj)
	say_handler_obj = obj;
    else
	say_handler_obj = previous_object();
    if (fun)
	say_handler_fun = fun;
    else
	say_handler_fun = "handle_say";
    handle_caught_texts = 1;
} /* set_say_handler */

/*---------------------------------------------------------------------------*/

mixed tell_handler_obj;	    /* The object in which to call... */
string tell_handler_fun;    /* ...this function when the monster hears a "tell" */

void set_tell_handler(mixed obj, string fun) {
    if (obj)
	tell_handler_obj = obj;
    else
	tell_handler_obj = previous_object();
    if (fun)
	tell_handler_fun = fun;
    else
	tell_handler_fun = "handle_tell";
    handle_caught_texts = 1;
} /* set_tell_handler */

/*---------------------------------------------------------------------------*/

mixed give_handler_obj;  /* The object in which to call... */
string give_handler_fun; /* ...this function when the monster is given an object */

void set_give_handler(mixed obj, string fun) {
    if (obj)
	give_handler_obj = obj;
    else
	give_handler_obj = previous_object();
    if (fun)
	give_handler_fun = fun;
    else
	give_handler_fun = "handle_give";
    handle_caught_texts = 1;
} /* set_give_handler */

/*---------------------------------------------------------------------------*/

mixed give_money_handler_obj;  /* The object in which to call... */
string give_money_handler_fun; /* ...this function when the monster is given some money */

void set_give_money_handler(mixed obj, string fun) {
    if (obj)
	give_money_handler_obj = obj;
    else
	give_money_handler_obj = previous_object();
    if (fun)
	give_money_handler_fun = fun;
    else
	give_money_handler_fun = "handle_give_money";
    handle_caught_texts = 1;
} /* set_give_money_handler */

/*---------------------------------------------------------------------------*/

mixed arrive_handler_obj;	/* The object in which to call... */
string arrive_handler_fun;	/* ...this function when someone arrives */

void set_arrive_handler(mixed obj, string fun) {
    if (obj)
	arrive_handler_obj = obj;
    else
	arrive_handler_obj = previous_object();
    if (fun)
	arrive_handler_fun = fun;
    else
	arrive_handler_fun = "handle_arrive";
    handle_caught_texts = 1;
} /* set_arrive_handler */

/*---------------------------------------------------------------------------*/

mixed leave_handler_obj;	/* The object in which to call... */
string leave_handler_fun;	/* ...this function when someone leaves */

void set_leave_handler(mixed obj, string fun) {
    if (obj)
	leave_handler_obj = obj;
    else
	leave_handler_obj = previous_object();
    if (fun)
	leave_handler_fun = fun;
    else
	leave_handler_fun = "handle_leave";
    handle_caught_texts = 1;
} /* set_leave_handler */

/*---------------------------------------------------------------------------*/

/* Maybe we should put "smartpresent" in 'obj/simul_efun.c' or somewhere? */

static object smartpresent2(mixed what, mixed where) {
    object obj, foundobj, *all_inv;
    string lwhat, lwhat2, junk;
    int i, n, the_number;

    if (what == 0)
	return 0;
    obj = present(what, where);
    if (obj || !stringp(what))
	return obj;
    lwhat = lower_case(what);
    obj = present(lwhat, where);
    if (obj)
	return obj;
    while (   sscanf(lwhat, "the %s", lwhat) == 1
	   || sscanf(lwhat, "a %s", lwhat) == 1
	   || sscanf(lwhat, "an %s", lwhat) == 1
	   || sscanf(lwhat, "%s.", lwhat) == 1) {
	obj = present(lwhat, where);
	if (obj)
	    return obj;
    }
    while (sscanf(lwhat, "%s %d", lwhat2, the_number) == 2) {
	if (where == 0)
	    where = environment(this_object());
	all_inv = all_inventory(where);
	if (pointerp(all_inv)) {
	    n = sizeof(all_inv);
	    foundobj = 0;
	    for (i = 0; i < n && the_number > 0; ++i) {
		if (all_inv[i]->id(lwhat2)) {
		    if (--the_number == 0)
			return obj;
		    else if (!foundobj)
			foundobj = all_inv[i];
		}
	    }
	    if (foundobj)
		return foundobj;
	}
	lwhat = lwhat2;
    }
    while (   sscanf(lwhat, "%s, %s", lwhat2, junk) == 2
	   || sscanf(lwhat, "%s - %s", lwhat2, junk) == 2
	   || sscanf(lwhat, "%s %s", lwhat2, junk) == 2) {
	obj = present(lwhat2, where);
	if (obj)
	    return obj;
	lwhat = lwhat2;
    }
    return 0;
} /* smartpresent2 */

object smartpresent(mixed what, mixed where) {
    object foundobj;

    if (where == 0) {
	foundobj = smartpresent2(what, environment(this_object()));
	if (foundobj)
	    return foundobj;
	foundobj = smartpresent2(what, this_object());
	return foundobj;
    }
    else
	return smartpresent2(what, where);
} /* smartpresent */

/*---------------------------------------------------------------------------*/

status do_matching(string str) {
    string who, phrase, what, whom, how;
    object who_obj, what_obj;
    int the_number;

    DEBUG_LOG("do_matching(\"" + str + "\")");

    /* Was this something that someone said? */
    /* The second sscanf is for Morgar's say with quotes! */
    if (   (say_handler_obj || say_response_data)
	&& (   (sscanf(str, "%s says: %s\n", who, phrase) == 2)
	    || (sscanf(str, "%s says \"%s\"\n", who, phrase) == 2))) {
	who_obj = smartpresent(who, environment(this_object()));
	if (who_obj) {
	    if (say_response_data && match_say_responses(who_obj, who, str)) {

	    }
	    else if (say_handler_obj)
		call_other(say_handler_obj, say_handler_fun, who_obj, who, phrase);
	}
	else {
	    SAY_CONFUSED(who + " said something, but doesn't seem to be here now.");
	}
    } /* if (say_handler_obj) */

    /* Was this something that someone told this monster? */
    if (   (tell_handler_obj || say_response_data)
	&& (sscanf(str, "%s tells you: %s\n", who, phrase) == 2)) {
	who_obj = smartpresent(who, environment(this_object()));
	if (!who_obj)
	    who_obj = find_living(lower_case(who));
	if (who_obj) {
	    if (say_response_data && match_say_responses(who_obj, who, str)) {

	    }
	    else if (tell_handler_obj)
		call_other(tell_handler_obj, tell_handler_fun, who_obj, who, phrase);
	}
	else {
	    SAY_CONFUSED(who + " told me something, but can't be found.");
	}
    } /* if (tell_handler_obj) */

    /* Did someone just give this monster some money? */
    if (   give_money_handler_obj
	&& (sscanf(str, "%s gives you %d gold coins.\n", who, what) == 2)) {
	/* Ok, someone gave this monster some gold coins! Now: who? */
	who_obj = smartpresent(who, environment(this_object()));
	if (!who_obj) {
	    SAY_CONFUSED(who + " gave me some gold, but doesn't seem to be here now.");
	}
	else
	    call_other(give_money_handler_obj, give_money_handler_fun, who_obj, who, what);
    } /* if (give_money_handler_obj && ...) */

    /* Did someone just give this monster something? */
    if (   give_handler_obj
	&& (sscanf(str, "%s gives %s to %s.\n", who, what, whom) == 3)
	&& (   id(whom)
	    || id(lower_case(whom))
	    || (   (sscanf(whom, "%s %d", whom, the_number) == 2)
		&& (id(whom) || id(lower_case(whom)))))) {
	/* Ok, someone gave this monster something! Now: who and what? */
	who_obj = smartpresent(who, environment(this_object()));
	if (!who_obj) {
	    SAY_CONFUSED(who + " gave me something, but doesn't seem to be here now.");
	}
	else {
	    /* Ok, a known someone gave this monster something! Now: what? */
	    what_obj = smartpresent(what, this_object());
	    if (what_obj)
		call_other(give_handler_obj, give_handler_fun, who_obj, who, what_obj, what);
	    else {
		SAY_CONFUSED(who + " gave me '" + what + "', but I don't seem to have it now.");
	    }
	}
    } /* if (give_handler_obj && ...) */

    /* Was this a message about someone arriving? */
    if (   arrive_handler_obj
	&& (sscanf(str, "%s arrives%s.\n", who, how) == 2)) {
	who_obj = smartpresent(who, environment(this_object()));
	if (who_obj)
	    call_other(arrive_handler_obj, arrive_handler_fun, who_obj, who, how);
	else {
	    SAY_CONFUSED(who + " arrived, but doesn't seem to be here now.");
	}
    } /* if (arrive_handler_obj) */

    /* Was this a message about someone leaving? */
    if (   leave_handler_obj
	&& (sscanf(str, "%s leaves %s.\n", who, how) == 2)) {
	call_other(leave_handler_obj, leave_handler_fun, 0, who, how);
    } /* if (leave_handler_obj) */

    if (response_data && match_responses(str))
	return 1;
    return 0;
} /* do_matching */

/*---------------------------------------------------------------------------*/

/* Additional attacks: spells, extra arms etc. */

mixed *attack_data;
/*  attack_data is an array of multiples of four elements, each of which is
 *    the messages printed to the room (a string),
 *    an special messages to the "opponent" (also a string, or 0),
 *    the max damage for the attack (an integer),
 *    the chance for each attack (an integer 0..100)
 */

void add_attack(string msg, mixed arg2, mixed arg3, mixed arg4) {
    string opponent_msg;
    int damage;
    int chance;

    /* Usage:  add_attack  ATTACK-MESSAGE  [ PERSONAL-ATTACK-MESSAGE ]  MAX-DAMAGE  CHANCE */

    if (!stringp(msg)) {
	SAY_ERROR("Bad arguments to add_attack.");
	return;
    }

    if (stringp(arg2) || (arg2 == 0 && arg4 != 0)) {
	opponent_msg = arg2;
	damage = arg3;
	chance = arg4;
    }
    else if (intp(arg2) && intp(arg3)) {
	damage = arg2;
	chance = arg3;
    }
    else {
	SAY_ERROR("Bad arguments to add_attack.");
	return;
    }

    if (chance == 0)
	chance = 100;

    if (attack_data == 0)
	attack_data = ({ });
    attack_data += ({ msg, opponent_msg, damage, chance });
} /* add_attack */

void set_attacks(mixed *all_attacks) {
    if (all_attacks != 0 && !pointerp(all_attacks)) {
	SAY_ERROR("Bad argument to set_attacks.");
	return;
    }
    attack_data = all_attacks;
} /* set_attacks */

mixed *query_attacks() {
    return attack_data;
} /* query_attacks */

/*  This function will, with some chance, perform ONE of the extra attacks.
 *  It should NOT be called if the monster isn't currently in a fight,
 *  or if there are no extra attacks to choose from.
 */
void extra_attacks() {
    string attackers_name;
    int i, n;

    if (attack_data == 0)
	return;
    n = sizeof(attack_data);
    for (i = 0; i < n; i += 4) {
	if (random(100) < attack_data[i + 3]) {
	    attackers_name = (string)attacker_ob->query_name();
	    if (attack_data[i + 1])
		tell_object(attacker_ob, substitute_other(attack_data[i + 1], attackers_name));
	    else
		tell_object(attacker_ob, substitute_other(attack_data[i], attackers_name));
	    say(substitute_other(attack_data[i], attackers_name), attacker_ob);
	    spell_dam += random(attack_data[i + 2]);
	    /* Don't just call "hit_player": attacker_ob->hit_player(random(attack_data[i + 2])); */
	    return;
	}
    } /* for all stored attacks */
} /* extra_attacks */

/*---------------------------------------------------------------------------*/

object fight_beat_obj;	/* The object in which to call... */
string fight_beat_fun;	/* ...this function each heartbeat when fighting */

void set_fight_beat(object obj, string fun) {
    if (obj)
	fight_beat_obj = obj;
    else
	fight_beat_obj = previous_object();
    if (fun)
	fight_beat_fun = fun;
    else
	fight_beat_fun = "fight_beat";
} /* set_fight_beat */

/*---------------------------------------------------------------------------*/

object peace_beat_obj;	/* The object in which to call... */
string peace_beat_fun;	/* ...this function each heartbeat when NOT fighting */

void set_peace_beat(object obj, string fun) {
    if (obj)
	peace_beat_obj = obj;
    else
	peace_beat_obj = previous_object();
    if (fun)
	peace_beat_fun = fun;
    else
	peace_beat_fun = "peace_beat";
} /* set_peace_beat */

/*---------------------------------------------------------------------------*/

mixed *friends;	/* All this monster's friends - their names or the objects */

status is_friend(mixed the_name) {	/* Either a name or an object */
    return member_array((stringp(the_name) ? lower_case(the_name) : the_name), friends) != -1;
} /* is_friend */

void add_friend(mixed the_name) {
    mixed low_name;

    if (the_name == 0)
	return;
    low_name = (stringp(the_name) ? lower_case(the_name) : the_name);
    if (friends == 0)
	friends = ({ });
    if (!is_friend(low_name))
	friends += ({ low_name });
} /* add_friend */

void set_friends(mixed *all_friends) {
    if (all_friends != 0 && !pointerp(all_friends)) {
	SAY_ERROR("Bad argument to set_friends.");
	return;
    }
    friends = all_friends;
} /* set_friends */

mixed *query_friends() {
    return friends;
} /* query_friends */

/* Call my friends for help */
void call_friends(object enemy) {
    int i, n;
    mixed this_friend;

    if (friends == 0)
	return;
    n = sizeof(friends);
    for (i = 0; i < n; ++i) {
	if (random(2)) {
	    this_friend = friends[i];
	    if (stringp(this_friend))
		this_friend = present(this_friend, environment(this_object()));
	    if (this_friend)
		this_friend->help_friend(enemy, this_object());
	}
    }
} /* call_friends */

void help_friend(object enemy, object friend) {
    if (enemy && !attacker_ob) {
	attacked_by(enemy);
	say(cap_name + " turns to help " + query_possessive() +
	    " friend " + friend->query_name() + " against " +
	    enemy->query_name() + ".\n");
    }
} /* help_friend */

/*---------------------------------------------------------------------------*/

/*  This "random_move" knows about more exits than the one in /obj/monster,
 *  and uses them in a smarter way.
 */
void random_move()
{
    object old_env;

    old_env = environment(this_object());
    command( ({ "n", "e", "s", "w" }) [random(4)] );
    if (environment(this_object()) == old_env) {
	command( ({ "up", "down", "out", "exit" }) [random(4)] );
	if (environment(this_object()) == old_env) {
	    command( ({ "ne", "se", "sw", "ne" }) [random(4)] );
	}
    }
} /* random_move */

/*---------------------------------------------------------------------------*/

/*  If the monster is set up to react to things that happend,
 *  then all messages that the monster sees (with "catch_tell"),
 *  are queued on this variable, "waiting_texts".
 *  The variable will be 0, a simple string, or an array of strings,
 *  depending on whether there are 0, 1 or more texts on the queue.
 */
mixed waiting_texts;
int latest_catch_tell_time;

void queue_text(string str) {
    if (waiting_texts == 0)
	waiting_texts = str;
    else if (stringp(waiting_texts))
	waiting_texts = ({ waiting_texts, str });
    else
	waiting_texts += ({ str });
} /* queue_text */

/* Don't call this function if waiting_texts is empty! */
string get_queued_text() {
    string temp;

    if (stringp(waiting_texts)) {
	temp = waiting_texts;
	waiting_texts = 0;
    }
    else if (sizeof(waiting_texts) == 2) {
	temp = waiting_texts[0];
	waiting_texts = waiting_texts[1];
    }
    else {
	temp = waiting_texts[0];
	waiting_texts = waiting_texts[1..sizeof(waiting_texts)-1];
    }
    return temp;
} /* get_queued_text */

int nr_waiting_texts() {
    if (waiting_texts == 0)
	return 0;
    else if (stringp(waiting_texts))
	return 1;
    else
	return sizeof(waiting_texts);
} /* nr_waiting_texts */

/*  This catch_tell() replaces the one in /obj/monster.
 *  We never do anything with the texts here, just queue them on the
 *  queue and let the next heart_beat() handle the first text in the queue.
 *  If the latest addition to the queue was more than ten seconds ago,
 *  then we reset throw away all the messages on the queue.
 *  Problem:
 *	If a function that is called as a response writes strings
 *	that the monster can see, for example using write(),
 *	we might get an infinte loop.
 */
void catch_tell(string str) {
    DEBUG_LOG("catch_tell(\"" + str + "\")");
    /* No "set_heart_beat(1);" here - Harry and Jennifer would talk forever! */
    if (previous_object() != this_object() && handle_caught_texts) {

	if (waiting_texts && time() - latest_catch_tell_time > 10)
	    waiting_texts = 0;
	latest_catch_tell_time = time();

	queue_text(str);
    }
} /* catch_tell */

/*---------------------------------------------------------------------------*/

/*  Handle the texts on the catch_tell queue.
 *  DON'T handle additional texts that may arrive now.
 */
void match_the_queue() {
    int i, n;

    n = nr_waiting_texts();
    for (i = 0; i < n; ++i)
	do_matching(get_queued_text());
} /* match_the_queue */

/*---------------------------------------------------------------------------*/

void heart_beat()
{
    age += 1;

#ifdef USE_WETCODE
    if (wet_time > 0 &&
	!environment(this_object())->query_property("waterfilled"))
    {
      wet_time--;
      
      if (random(40) == 0)
	say("Some water drips from " + capitalize(name) + ".\n");
    }
#endif

    if(!test_if_any_here()) {
	/* No players (real, interactive ones, that is!) in this room */
	if (waiting_texts) {
	    /*  There are texts from catch_tell() waiting.
	     *  And that will happen only if we have things to match against.
	     */
	    match_the_queue();
	}
	else {
	    /* No texts waiting, and no players in the room */
	    set_heart_beat(0);
	    if (!healing)
		heal_slowly();
	    return;
	}
    }

    /* Ok, now: There is at least one real player in the room. */

    if (kill_ob && present(kill_ob, environment(this_object()))) {
	/* The player (or monster) we fight is here! */
	if (random(2) == 1)
	    return;		/* Delay attack some */
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }

    /* spell_mess1 etc: removed */

    if (attacker_ob && present(attacker_ob, environment(this_object()))) {
	if (friends)
	    call_friends(attacker_ob);
	if (attack_data)
	    extra_attacks();
	if (fight_beat_obj)
	    call_other(fight_beat_obj, fight_beat_fun, attacker_ob);
    }
    else if (peace_beat_obj)
	call_other(peace_beat_obj, peace_beat_fun, attacker_ob);


    /* The function "attack" is defined in obj/living: */
    attack();

    /* Shall I stay and fight, or run for my life? */
    if (attacker_ob && wimpyness && hit_point < (wimpyness*max_hp) / 100)
	run_away();

    if (   chat_data && (!attacker_ob || chat_in_fight)
	&& random(100) < chat_chance)
	say(chat_data[random(sizeof(chat_data))]);

    if (random_pick && random(100) < random_pick)
	pick_any_obj();

    if (waiting_texts) {
	/*  There are texts from catch_tell() waiting.
	 *  And that will happen only if we have things to match against.
	 */
	match_the_queue();
    }
} /* heart_beat */

/*---------------------------------------------------------------------------*/

/*  Call the following functions to set up the monster.
 *  Call them in the order they appear.
/*  The functions "set_name" and "set_level" must be called,
 *  and they must be called before the optional functions!
 */
void set_name(string n) {
    name = n;
    cap_name = capitalize(n);
    if (n != lower_case(n)) {
	n = lower_case(n);
	add_alias(n);
    }
    set_living_name(n);
    alignment = 0;		/* Neutral monster */
    set_short(cap_name);	/* Will also set long! */
}

void set_str(int i) { Str = i; }
void set_int(int i) { Int = i; max_sp = 42 + Int * 8; heal_self(max_sp); }
void set_con(int i) { Con = i; max_hp = 42 + Con * 8; heal_self(max_hp); }
void set_dex(int i) { Dex = i; }

void set_level(int l) {
    int sane_level;

    if (l < 1)
	sane_level = 1;
    else if (l > 20)
	sane_level = 20;
    else
	sane_level = l;
    /* "level" can be anything >= 0, but the experience points are limited! */
    if (l < 0)
	level = 0;
    else
	level = l;
    set_str(level); set_int(level); set_con(level); set_dex(level);
    weapon_class = level/2 + 3;
    armour_class = level/4;
    experience = (int)call_other("room/adv_guild", "query_cost", sane_level-1);
    /* This is for level 1 monsters. */
    if (experience == 0)
	experience = random(500);
} /* set_level */

/*---------------------------------------------------------------------------*/

void reset(int arg)
{
    ::reset(arg);
    if (!arg) {
	set_name("monster");
	set_short("an unspecified monster");
	set_level(1);
	set_race("monster");
    }
} /* reset */

/*---------------------------------------------------------------------------*/

void set_short(string sh) {
    short_desc = sh;
    if (sh == 0)
	set_long("You see nothing.\n");
    else
	set_long("You see nothing special.\n");
} /* set_short */

void set_aggressivity(int a) {
    if (a > 100)
	a = 100;
    if (a < 0)
	a = 0;
    aggressivity = a;
} /* set_aggressivity */

void set_soul() {
    move_object(clone_object("obj/soul"), this_object());
}
/*---------------------------------------------------------------------------*/

void long() {
    string cap_pronoun;

    write(long_desc);
#ifdef USE_WETCODE
    if (wet_time > 0 && !environment(this_object())->query_property("waterfilled"))
      write(cap_pronoun +
	    " is soaking wet, dripping water all over the place.\n");
#endif
    cap_pronoun = capitalize((string)query_pronoun());
    if (hit_point < max_hp/10)
	write(cap_pronoun + " is in very bad shape.\n");
    else if (hit_point < max_hp/5)
	write(cap_pronoun + " is in bad shape.\n");
    else if (hit_point < max_hp/2)
	write(cap_pronoun + " is not in a good shape.\n");
    else if (hit_point < max_hp - 20)
	write(cap_pronoun + " is slightly hurt.\n");
    /* else write(cap_pronoun + " is in good shape.\n"); */
} /* long */

/*---------------------------------------------------------------------------*/

string query_race() { return race; }
int query_aggressivity() { return aggressivity; }
int query_wimpyness() { return wimpyness; }

/*---------------------------------------------------------------------------*/

/* Set the wimpy mode */
void set_wimpyness(int w) {
    if (w > 100)
	w = 100;
    if (w < 0)
	w = 0;
    wimpyness = w;
    whimpy = (w != 0);	/* So the inherited /obj/living knows about it! */
}

/*---------------------------------------------------------------------------*/

/*  Two functions to compute a double or half chance.
 *  A simple "times 2" or "divide by 2" isn't enough:
 *  what do you get if you have a 90% chance, and double it?
 */
int double_chance(int old_chance) {
    if (old_chance <= 0)
	return 0;
    else if (old_chance >= 100)
	return 100;
    else if (old_chance < 20)
	return old_chance * 2;
    else if (old_chance > 60)
	return 50 + old_chance / 2;
    else /* between 20 and 60 */
	return 20 + old_chance;
} /* double_chance */

int half_chance(int old_chance) {
    if (old_chance <= 0)
	return 0;
    else if (old_chance >= 100)
	return 100;
    else if (old_chance < 40)
	return old_chance / 2;
    else if (old_chance > 80)
	return 2 * old_chance - 100;
    else /* between 40 and 80 */
	return old_chance - 20;
} /* half_chance */

/*---------------------------------------------------------------------------*/

void init() {
    if (!create_room && this_object())
	create_room = environment(this_object());
    if (this_player() == this_object())
	return;
    if (init_ob)
	if(init_ob->monster_init(this_object()))
	    return;

    if (attacker_ob)
	set_heart_beat(1);

    if (!this_player())
	return;	/* Shouldn't ever happen, should it? */

    if (this_player()->query_npc())
	return;

    set_heart_beat(1);

    /* Will this monster attack the player (not monster) that it just saw? */
    if (aggressivity == 0) {
	/* I don't beleive in violence, man! I'd never start a fight! */
    }
    else if (aggressivity == 100) {
	/* Slobber slobber! I'll attack anything that moves! */
	kill_ob = this_player();
    }
    else {
	int others_alignment, mod_agg;

	/* Calculate som adjustments. First, according to alignment: */
	others_alignment = (int)this_player()->query_alignment();
	if (   (alignment >= 0 && others_alignment >= 0)
	    && (alignment < 0 && others_alignment < 0))
	    /* He's on the same side as I, so I'm not so likely to attack! */
	    mod_agg = half_chance(aggressivity);
	else
	    /* He's stinking evil (alt. filthy good)! Kill! */
	    mod_agg = double_chance(aggressivity);

	/* Now, let's be a trifle pragmatic here: */
	if (level > this_player()->query_level())
	    /* Such a wimp! I'll handle him easily! */
	    mod_agg = double_chance(mod_agg);
	else if (level < this_player()->query_level())
	    /* Hm... That one looks awfully big... */
	    mod_agg = half_chance(mod_agg);

	if (random(100) < mod_agg)
	    kill_ob = this_player();
    }
} /* init */

/*---------------------------------------------------------------------------*/

/* Maybe we should put this function in 'obj/simul_efun.c' or somewhere? */
void smartwrite(mixed something) {
    int i, n;
    mixed this_element;
    string temp, temp2;

    if (stringp(something)) {
	n = sscanf(something, "%s\n%s", temp, temp2);
	if (n == 2) {
	    if (temp2 != "")
		write("'" + temp + "\\n'...");
	    else
		write("'" + temp + "\\n'");
	}
	else
	    write("'" + something + "'");
    }
    else if (objectp(something)) {
	temp = (string)something->query_name();
	if (temp)
	    write(temp);
	else
	    write("OBJ(" + file_name(something) + ")");	/* write(something); */
    }
    else if (pointerp(something)) {
	n = sizeof(something);
	write("[");
	for (i = 0; i < n; ++i) {
	    if (i != 0)
		write(", ");
	    this_element = something[i];
	    smartwrite(this_element);
	}
	write("]");
    }
    else
	write(something);
} /* smartwrite */

void show_responses() {
    int i, n;

    write("Smartmonster responses:\n");
    if (response_data == 0)
	return;
    n = sizeof(response_data);
    for (i = 0; i < n; i += 4) {
	write("  '" + response_data[i] + "': ");
	smartwrite(response_data[i + 1]);
	if (response_data[i + 2] != 0) {
	    write("\n    (");
	    smartwrite(response_data[i + 2]);
	    write(")");
	}
	write(" - " + response_data[i + 3] + "%\n");
    }
} /* show_responses */

void show_say_responses() {
    int i, n;

    write("Smartmonster responses to say:\n");
    if (say_response_data == 0)
	return;
    n = sizeof(say_response_data);
    for (i = 0; i < n; i += 4) {
	write("  "); smartwrite(say_response_data[i]); write(": ");
	smartwrite(say_response_data[i + 1]);
	if (say_response_data[i + 2] != 0) {
	    write("\n    (");
	    smartwrite(say_response_data[i + 2]);
	    write(")");
	}
	write(" - " + say_response_data[i + 3] + "%\n");
    }
} /* show_say_responses */

void show_stats() {
    ::show_stats();
    write("Additional smartmonster data:\n");

    if (aliases) {
	write("  aliases: "); smartwrite(aliases); write("\n");
    }

    if (chat_data)
	write("  chat_data: " + sizeof(chat_data) + " chats, chat_chance: " +
	      chat_chance + ", chat_in_fight: " + chat_in_fight + "\n");

    if (say_handler_obj) {
	write("  say_handler: '" + say_handler_fun + "' in ");
	write(say_handler_obj); write("\n");
    }
    if (tell_handler_obj) {
	write("  tell_handler: '" + tell_handler_fun + "' in ");
	write(tell_handler_obj); write("\n");
    }
    if (give_handler_obj) {
	write("  give_handler: '" + give_handler_fun + "' in ");
	write(give_handler_obj); write("\n");
    }
    if (give_money_handler_obj) {
	write("  give_money_handler: '" + give_money_handler_fun + "' in ");
	write(give_money_handler_obj); write("\n");
    }
    if (arrive_handler_obj) {
	write("  arrive_handler: '" + arrive_handler_fun + "' in ");
	write(arrive_handler_obj); write("\n");
    }
    if (leave_handler_obj) {
	write("  leave_handler: '" + leave_handler_fun + "' in ");
	write(leave_handler_obj); write("\n");
    }

    write("  handle_caught_texts = " + handle_caught_texts + "\n");
    write("  Waiting texts from catch_tell(): ");
    if (waiting_texts == 0)
	write(0);
    else if (stringp(waiting_texts))
	write(1);
    else
	write(sizeof(waiting_texts));
    write("\n");

    write("  aggressivity: " + aggressivity + "%\n");
    write("  wimpyness: " + wimpyness + "%\n");
    if (attack_data)
	write("  attack_data: " + sizeof(attack_data) / 4 + " attacks\n");

    if (friends) {
	write("  friends: "); smartwrite(friends); write("\n");
    }

    if (say_response_data)
	write("  say_response_data: " + sizeof(say_response_data) / 4 +
	      " say-responses\n");
    if (response_data)
	write("  response_data: " + sizeof(response_data) / 4 +
	      " responses\n");
    if (response_object) {
	write("  response_object = "); write(response_object); write("\n");
    }
    if (response_data)
	show_responses();
    if (say_response_data)
	show_say_responses();
    if (log_file_name)
	write("Logging on file '" + log_file_name + "'.\n");
} /* show_stats */

/*---------------------------------------------------------------------------*/

#ifdef MONSTER_COMPAT

/* For (some) compatibility with /obj/monster: */

void set_alias(string a) { add_alias(a); }
void set_alt_name(string a) { add_alias(a); }
void set_aggressive(status s) { set_aggressivity(100*s); }
void set_whimpy() { set_wimpyness(20); }

void load_chat(int chance, string *strs) {
    set_chat_chance(chance);
    set_chats(strs);
    set_chat_in_fight(1);
}

void load_a_chat(int chance, string *strs) {
    int i, n, c;

    n = sizeof(strs);
    c = chance/n;
    if (c == 0)
	c = 1;
    for (i = 0; i < n; ++i)
	add_attack(strs[i], 0, 0, c);
} /* load_a_chat */

int call_counter;
int spell_chance, spell_dam1;
string spell_mess1, spell_mess2;

void fix_spell() {
    add_attack(spell_mess2 + "\n", spell_mess1 + "\n", spell_dam1, spell_chance);
}

void set_chance(int c) { spell_chance = c; if (++call_counter == 4) fix_spell(); }
void set_spell_mess1(string m) { spell_mess1 = m; if (++call_counter == 4) fix_spell(); }
void set_spell_mess2(string m) { spell_mess2 = m; if (++call_counter == 4) fix_spell(); }
void set_spell_dam(int d) { spell_dam1 = d; if (++call_counter == 4) fix_spell(); }

void set_match(object ob, string *func, string *type, string *match) {
    ::set_match(ob, func, type, match);
    if (match)
	handle_caught_texts = 1;
} /* set_match */

#endif

/*---------------------------------------------------------------------------*/
