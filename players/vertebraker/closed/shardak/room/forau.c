#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

#include "../../../ansi.h"

inherit "/players/vertebraker/closed/std/monster";
mapping Counts;

string          text;           /* reply from catch_tell */
object          receiver;       /* talk to this object */

void reset(status arg)
{
    if(arg) return;
    ::reset(arg);
    Counts = ([ ]);
    set_race("demon");
    set_name("forau");
    set_gender("male");
    set_short("Forau");
    set_long("\
Forau is dressed all up in black. His silk shirt glows softly in the dim\n\
light. He is the bartender of this joint and one of Satan's disciples.\n");
    set_level(16);
    set_chat_chance(3);
    load_chats(({
            "Forau wipes up some glasses.\n",
            "With experienced hands Forau concocts a foul smelling drink.\n",
            "Forau casually remarks, \"Rumour is that Pitsniffer waxed Boltar incognito.\"\n",
            "Forau grins and says to you, \"Maledicta used to be one of us...\"\n",
            "Forau ponders, \"I wonder whatever became of Balowski...\"\n", }));
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
        text= "Forau smirks at you.\n";
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
            if (mark->query_solved(WASTE_TASK)) {
                text= "\
Forau says,\
\"You have completed my trial. You wish to speak to the imp.\"\n";
            }
            else {
                text= read_file(ABSPATH + "forau_task");
            }
        }
        else if (sscanf( what, "%sabilities", who)) {
            if(mark->query_solved(WASTE_TASK)) {
                text = "\
Forau says,\
\"You can now summon the power of \"waste\", a most fearsome\n\
spell indeed.\n";
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
    int cnt;
    object gore, mark;

    gore = first_inventory(this_object());
    if (gore && from) {
        if ((mark = present( GUILD_ID, from))
        &&  !((int) mark->query_solved(FLAMES_TASK))
        && (int)gore->id("pile of gore") &&
           (int)gore->query_real_mccoy())
        {

        tell_room(environment(), "\
Forau smiles at " + (string)from->query_name() + ".\n",
   ({ from }) );
        tell_object(from, "\
Forau smiles at you.\n");
        tell_room(environment(), "\
Forau dumps some demon's gore into a potion behind the bar.\n");
         Counts[(string)from->query_real_name()] ++;
         cnt = Counts[(string)from->query_real_name()];
         if(cnt < 4)
          tell_object(from, "\
Forau frowns.\n\
Forau says, \"I'm sorry.  I need " + (4 - cnt) + " more piles of gore.\"\n");
        else
        {
          tell_object(from, "A red aura encompasses your body.\n\
Your body locks up...\n");
          mark->stop_cmds();
            call_out("congrat", 1, from);
        }
      }
        else {
            say("Forau frowns and chants a phrase.\n");
        }
    }

    if (gore)
        destruct(gore);
}

void congrat(object from)
{
    object mark;

    if (from) {
        say("A red aura envelopes " + from->query_name() +
            " for a mere instant.\n", from);
        tell_object(from, "\
Enveloped in a red aura, Shardak's voice rings into your head,\n\
\"You may summon the spell of \"waste\". Discover how you\n\
may manipulate the apppearance in the help files. Tread safely,\n\
warrior.\"\n");
        mark= present( GUILD_ID, from);
    }

    if (mark) {
        mark->add_solved(WASTE_TASK);
        mark->save_me();
        mark->enable_cmds();
    }
}
