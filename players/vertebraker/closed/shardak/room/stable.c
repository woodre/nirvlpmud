/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 950422 - created
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../tasks.h"

inherit ROOM;

static object   man;            /* the guy who opens and closes grating */
static status   open;           /* true if the grating is open */
string         *Names;          /* names of dragons */

void
create()
{
    ::create();
    set_short("Above the pit");
    set_long("\
The awful smell fills the cramped room that you have entered. An iron\n\
grating covers a man-sized hole in the middle of the floor, and and if\n\
you are not badly mistaken the acrid stench comes from below.\n\
In the western end of the room stands a small wooden stool, and next\n\
to it a black iron lever rises from the floor.\n\
East will lead you back out.\n");
    set_items( ([
"grating" : "\
The grating is set a few inches into the floor and looks like it can\n\
slide in under it. In the mesh of thin iron bars, the image of a dragon\n\
has been weaved. It is impossible to see anything in the dark below.\n",
"stool" : "\
It is just a rickety three legged stool.\n",
"lever" : "\
It is a slim iron lever. The knob is shaped like a dragon's head.\n",
    ]) );
    set_exits( ([
        "east" : (PATH + "deepdown"),
        "down" : this_object(),
    ]) );
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!man || !present(man)) {
        man = clone_object(PATH + "trainer");
        man->move_player("in#" + file_name(this_object()));
    }
}

status
down()
{
    if (open) {
        this_player()->move_player("down#" + PATH + "pit");

        /* only let one person go down */
        write("The grating slams shut above you.\n");
        say("The grating immediately slams shut.\n");
        open = 0;
    }
    else
        write("The grating is shut, so you cannot.\n");
    return 1;
}

void
init()
{
    ::init();
    add_action("pull_lever", "pull");
    add_action("name_dragon", "name");
}

status
pull_lever(string arg)
{
    if (arg != "lever") {
        notify_fail("Pull what?\n");
        return 0;
    }

    if (man && this_player() != man)
        write("The bowed man slaps you on the wrist.\n");
    else {
        write("You pull the lever.\n");
        say(this_player()->query_name() + " pulls the lever.\n");

        if (open)
            tell_room(this_object(), "Nothing happens.\n");
        else {
            tell_room(this_object(), "\
As hidden mechanics begin to rumble and creak, the grating slowly\n\
opens it jaws and slides in under the floor.\n");
            open = 1;
        }
    }
    return 1;
}

status
name_dragon(string arg)
{
    object gob;

    if (!man) return 0;
    if (arg != "dragon") return 0;
    if (!(gob = present(OBJID, this_player()))) return 0;
    if ((int) this_player()->query_guild_rank() < 5 ||
        !gob->query_solved(DRAGON_TASK)) {
        write("The bowed man tells you, \"It is too early for you to name your dragon.\"\n");
        return 1;
    }
    if (gob->DragonName()) {
        write("The bowed man tells you, \"You have already chosen a name.\nYou cannot alter your choice.\"\n");
        return 1;
    }
    write("\
The bowed man says, \"You must now tell me your choice of name.\n\
If you have not yet considered the name well, I urge you to do so\n\
immediately. The moment you give me the name, the spirits of past\n\
warriors will form together and become the dragon you have given\n\
name. Thus, your choice cannot be altered.\n\n\
(lower and uppercase letters, space, hyphen, and apostrophe allowed)\n\
Enter name:");
    input_to("give_name");
    return 1;
}

void
give_name(string arg)
{
    object gob;
    string nom, key;
    int i;

    if (!arg || arg == "") {
        write("The bowed man says, \"Come back when your mind is set on a name.\"\n");
        return;
    }
    if (strlen(arg) < 4) {
        write("The bowed man says, \"That name is too short.\"\n");
        return;
    }
    if (strlen(arg) > 18) {
        write("The bowed man says, \"That name is too long.\"\n");
        return;
    }
    /* derive a "key" name (fx. "Ba'l owski" -> "balowski") */
    nom = lower_case(arg);
    key = "";
    for (i = 0; i < strlen(arg); i++) {
        if (index("abcdefghijklmnopqrstuvwxyz -'", nom[i]) < 0) {
            write("The bowed man says, \"Letter number " + (i + 1) + " is no good.\"\n");
            return;
        }
        if (nom[i] >= 'a' && nom[i] <= 'z')
            key += nom[i..i];
    }
    /* exists() would be nicer, but 3.2 doesn't emulate it right */
    if (restore_object("players/" + key) ||
        restore_object("pfiles/" + key[0] + "/" + key) ||
        restore_object("players/inactive_saved/" + key) || 
        restore_object("banish/" + key)) {
        write("The bowed man says, \"That name is not acceptable.\"\n");
        return;
    }

    if (!(gob = present(OBJID, this_player()))) return;
    write("The bowed man says, \"" + arg + " awaits your summoning.\"\n");
    gob->DragonName(arg);
}
