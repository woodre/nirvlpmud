/*
 * Shardak guild - (tm) Dragnar/John
 * Ghost is (c) Balowski/Rasmus, March 11th 1995.
 * Last change: Mar 11th '95
 */
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
inherit "/obj/monster";

reset(x)
{
    if(x) return;
    ::reset(x);
    set_name("warrior");
    set_short("Ghost of a warrior");
    set_long(HIK+"\
A tenuous grey mist is drifting around here. Constantly changing and\n\
moving about, but you from watching a while you piece together the\n\
image of a battle clad warrior.\n"+NORM);
    set_alias("ghost");
    set_ghost(1);
    set_chat_chance(8);
    load_chats(({
	"The ghost drifts around.\n",
	"You hear a silent wailing.\n",
	"A gush of cold air chills you to the bone.\n",
	"There is the sound of movement deeper inside the cave.\n",
    }));
}

string          text;           /* caught catch_tell */
object          receiver;       /* talk to this object */

void DoTalk()
{
    if (!text || !receiver) { text = 0; return;}
    tell_object(receiver, "The ghost whispers to you:");
    tell_object(receiver, text);
    text = receiver = 0;
}

void long(string id)
{
    ::long(id);
    if (!text) {
	receiver = this_player();
	text = read_file(ABSPATH + "warrior");
	call_out("DoTalk", 2);
    }
}

void catch_tell(string str)
{
    string      who, what;

    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s asks: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) {

	what = lower_case(what);
	if (sscanf(what, "%sshardak", who))
	    text = read_file(ABSPATH + "speak1");
	else if (sscanf(what, "%smembers", who))
	    text = read_file(ABSPATH + "speak2");
	else if (sscanf(what, "%squalities", who))
	    text = read_file(ABSPATH + "speak3");
	else if (sscanf(what, "%sjoining", who))
	    text = read_file(ABSPATH + "speak4");
	else return;
	receiver = this_player();
	call_out("DoTalk", 2);
    }
}
