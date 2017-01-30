/* 
 * Shardak guild - (tm) Dragnar/John
 * Priest is (c) Balowski/Rasmus, April 8th 1995.
 * Last change: April 8th '95
 * One day I must make this a little more generic..
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit "/obj/monster";

string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */

void reset(int x)
{
    if(x) return;
    ::reset(x);
    set_race("human");
    set_name("priest");
    set_gender("male");
    set_short("A priest");
    set_long("\
The priest is shrouded in a dark black cowl completely concealing his\n\
face. The cowl reflects only little light and has ultramarine embroideries\n\
along the selvage. He moves gracefully about in that floating fashion\n\
most levitating priests seem to fancy.\n");
    set_level(15);
    set_ac(10);
    set_wc(20);
    set_hp(600);
    set_al(-100);
    set_ghost(1);
    set_chat_chance(2);
    load_chat("The priest moves to replace a candle as its flame sputters and dies.\n");
}

void DoTalk() {
    if (!text || !receiver) { text = 0; return;}
    tell_object(receiver, text);
    text = receiver = 0;
}

void long(string str)
{
    ::long(str);
    if (!text) {
	receiver= this_player();
	text= "\
The priest turns towards you and says, \"Seeker of Knowledge, what\n\
information wishest Thou? I am the keeper of this Shrine and can tell\n\
you of the altar and the trial this place holds. Here you can also\n\
`advance' in guild rank, restore your 'title', and see your unsolved\n\
'trials'.\"\n";
	call_out("DoTalk", 2);
    }
}

void
init()
{
    ::init();
    add_action("cmdPray", "pray");
}

void
catch_tell(string str)
{
    string      who, what;
    int         i;
    object      mark;

    if (this_player())
	mark = present(GUILD_ID, this_player());
    if (!mark || !str)
	return;

    if (!text && (sscanf(str, "%s says: %s\n", who, what) == 2 ||
		  sscanf(str, "%s asks: %s\n", who, what) == 2 ||
		  sscanf(str, "%s tells you: %s\n", who, what) == 2)) {
	what = lower_case(what);

	if (sscanf(what, "%strial", who)) {
	    if (mark->query_solved(CORPSE_TASK)) {
		text= "\
The priest answers, \"Seek out the Merchant, for he conducts your next trial.\"\n";
	    }
	    else {
		text= read_file(ABSPATH + "corpse_task");
	    }
	}
	else if (sscanf( what, "%saltar", who)) {
	    text = "\
The priest brightens up, \"This humble altar can transfer energy\n\
directly into the vast depots of our noble master, Shardak. Thus\n\
every man in Shardak's retinue can serve to increase the strength\n\
of his master and with that, his own strength.\"\n";
	}
	else return;
	receiver = this_player();
	call_out("DoTalk", 2);
    }
}

add_weight(int w)
{
#if 0
evil objects with w < 1
    if (w > 0)                  /* I am receiving something of weight */
	if (first_inventory(this_object()))
	    return 0;           /* disallow more than 1 object */
	else
#endif
	    call_out("received", 1, this_player());

     return ::add_weight(w);
}

void received(object from)
{
    object corpse;
    object mark;

    corpse = first_inventory(this_object());
    if (corpse && from) {
	if ((mark = present( GUILD_ID, from))
	&&  !((int) mark->query_solved(CORPSE_TASK))
	&&  (status) corpse->id("corpse")
	&&  (int) corpse->heal_value() >= 4) {

	    /* have to split say in 2, max is 255 chars */
	    say("\
With improper strength the priest lifts the corpse high over his head\n\
and intonates, \"Shard'k, ezem gk'dhar tze ke'hkt.\"\n");
	    say("\
He lowers the body to the altar and you see a vague shadow leaving\n\
the corpse before it vanishes in a flash of light, followed by the\n\
sound of potted thunder.\n");
	    call_out("congrat", 1, from);
	}
	else {
	    say("\
The priest places an item on the altar...\n\
It is dissolved in a flash of light, but nothing happens.\n");
	}
    }

    if (corpse)
	destruct(corpse);
}

void congrat(object from)
{
    object mark;

    if (from) {
	say("A red aura envelopes " + from->query_name() +
	    " for a mere instant.\n", from);
	tell_object(from, "\
Enveloped in a frail red aura you hear a message from Shardak,\n\
\"Promising, promising. You are granted the ability to drain the\n\
strength of slain foes.\"\n\
You feel enlightened.\n");
	mark= present( GUILD_ID, from);
    }

    if (mark) {
	mark->add_solved(CORPSE_TASK);
	mark->save_me();                /* save guild info, init() restores */
    }
}

status
cmdPray()
{
    if(!this_player()->query_ghost()) return 0;
    write("You kneel before the Altar of Shardak.\n");
    say((string)this_player()->query_name() + " kneels before the Altar.\n");
    this_player()->remove_ghost();
    return 1;
}
