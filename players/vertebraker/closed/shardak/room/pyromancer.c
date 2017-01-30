
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

#include "../../../ansi.h"

inherit "/players/vertebraker/closed/std/monster";

string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */

void reset(status arg)
{
    if(arg) return;
    ::reset(arg);
    set_race("human");
    set_name("pyromancer");
    set_gender("male");
    set_short("A pyromancer");
    set_long("\
Swaddling red robes wrap themselves around the torso of\n\
this dark pyromancer.  Fiery orange hair cascades out from\n\
the top of his head and settles down around his shoulders.\n\
A simple leather breastplate free of adornments decorates\n\
his chest beneath the robes, and a dagger hewn from black\n\
obsidian hangs from his side.\n" +
RED + "\tAn aura of fire surrounds him.\n" + NORM);
    set_level(22);
    set_ac(10);
    set_wc(70);
    set_hp(400);
    set_al(-400);
    set_chat_chance(2);
    load_chat("The pyromancer snickers.\n");
    load_chat("The pyromancer smiles darkly.\n");
    load_chat("The pyromancer arches his eyebrow at you.\n");
}

void DoTalk() {
    if (!text || !receiver) { text = 0; return;}
    tell_object(receiver, text);
    text = receiver = 0;
}

init()
{
    ::init();
    add_action("cmdItems","items");
    add_action("cmdItems","list");
    add_action("cmdPurchase","purchase");
    add_action("cmdPurchase","buy");
}

void long(string str)
{
    ::long(str);
    if (!text) {
	receiver= this_player();
	text= "\
The priest nods at you and says, \"Ah.  A fellow brother of\n\
the Dark.  What wouldst thou wish?  I carry a fine selection of\n\
'items' for his Lordship.  I am willing to part with them for\n\
a cheap price .. so that our Army may unite.\n";
	call_out("DoTalk", 2);
    }
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
	    if (mark->query_solved(FLAMES_TASK)) {
		text= "\
The pyromancer answers,\
\"I believe the Smith conducts your next trial.\"\n";
	    }
	    else {
		text= read_file(ABSPATH + "flames_task");
	    }
	}
	else if (sscanf( what, "%sabilities", who)) {
            if(mark->query_solved(FLAMES_TASK)) {
                text = "\
The pyromancer says,\
\"You can now conjure flames from the Underworld to assist\n\
 you in your struggle for the Master.\n\
 Read through the help files to determine the nature of these\n\
 abilities.  As you advance in power, you may also gain more\n\
 of these abilities, so be sure to read up on them.\"\n";
	}
       }
	else return;
	receiver = this_player();
	call_out("DoTalk", 2);
    }
}

mixed add_weight(int w)
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
    object etorch;
    object mark;

    etorch = first_inventory(this_object());
    if (etorch && from) {
	if ((mark = present( GUILD_ID, from))
	&&  !((int) mark->query_solved(FLAMES_TASK))
        && etorch->id("eternal torch") && etorch->shardakEternalFlame()
         ) {

        tell_room(environment(), "\
The pyromancer grins wickedly at " + (string)from->query_name() + ".\n",
   ({ from }) );
        tell_object(from, "\
The pyromancer grins wickedly at you.\n");
        tell_room(environment(), "\
He places the torch in the middle of the cradle, and says a few\n\
gutteral words in incantation.\n\
Smoke puffs from the stone dragon's head...\n");
        tell_object(from, "\
Your body locks up...\n");
        present(GUILD_ID, from)->stop_cmds();
	    call_out("congrat", 1, from);
	}
	else {
	    say("\
The pyromancer frowns and obliterates something.\n");
	}
    }

    if (etorch)
	destruct(etorch);
}

void congrat(object from)
{
    object mark;

    if (from) {
	say("A red aura envelopes " + from->query_name() +
	    " for a mere instant.\n", from);
	tell_object(from, "\
Enveloped in a frail red aura you hear a message from Shardak,\n\
\"You have proven yourself worthy to hold the skill of\n\
flame conjuration.  The Army of the Dark is counting on you,\n\
my slave.\n\
Go now and do your Master proud.\"\n\
You feel enlightened.\n");
	mark= present( GUILD_ID, from);
    }

    if (mark) {
	mark->add_solved(FLAMES_TASK);
	mark->save_me();
        mark->enable_cmds();                /* save guild info, init() restores */
    }
}

cmdItems()
{
    if(!present(GUILD_ID, this_player())) return;
    write("\
The pyromancer states,\n\
\"I carry the following items with me:\"\n\
   Name                   Price\n\
 --+ ------------------- -+ --\n\
   Black Obsidian         356\n\
   A flask of Nitropyr    453\n\
   Blood Chalk            632\n\n\
He continues, \"You may 'purchase' any items you like.\"\n"); 
    return 1;
}

cmdPurchase(string str)
{
    int cost, num;
    object comp;
    string msg;

    if(!present( GUILD_ID, this_player())) return;
    if(str == "chalk" || str == "blood chalk")
    {
      cost = 632;
      num = 3;
      msg = "Ah, you wish to purchase Blood Chalk?";
    }
    else if(str == "flask" || str == "nitropyr")
    {
      cost = 453;
      num = 2;
      msg = "Hmm.. Nitropyr.  A volatile substance indeed.";
    }
    else if(str == "obsidian" || str == "black obsidian")
    {
      cost = 356;
      num = 1;
      msg = "Precious black obsidian.";
    }
    else
    {
      notify_fail("The pyromancer says, \"We don't carry that.\"\n");
      return 0; 
    }
    write("The pyromancer nods and says,\
 \"" + msg + "\"\n");
    if((int)this_player()->query_money() < cost)
    {
      notify_fail("The pyromancer looks at you strangely.\n\
\"Sorry\", he says, \"You don't have the funds for it.\"\n");
      return 0;
    }
    if(!this_player()->add_weight(1))
    {
      notify_fail("The pyromancer says,\
\"You can't carry it.  Sorry.\"\n");
      return 0;
    }
    comp = clone_object(OBJDIR + "component");
    this_player()->add_money(-cost);
    comp->set_type(num);
    comp->Set_Uses(66 + random(22));
    move_object(comp, this_player());
    write("The pyromancer hands you \
" + (string)comp->short() + ".\n\
You hand him the cash.\n");
    this_player()->remote_say("The pyromancer hands " + (string)comp->short()
    + " to " + (string)this_player()->query_name() + ".\n");
    return 1;
}

