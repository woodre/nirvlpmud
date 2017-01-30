/*
 * DRAIN command for the Shardak guild
 * by Dragnar and Balowski, 1995
 * adapted by verte with love
 */
#pragma strict_types

#include "/players/vertebraker/ansi.h"

#include "../std.h"
#include "../tasks.h"
#include "../macros.h"
inherit CMD;
#define COST 10

object
bones(int value)
{
    object ob;

    ob = clone_object("/obj/treasure");
    ob->set_id("bones");
    ob->set_alias("pile of bones");
    ob->set_value(value);
    ob->set_short("A pile of bones");
    ob->set_long("\
In a small pile lies the only remnants of a creature once alive.\n\
Judging from the lime white colour of the bones, they are fresh,\n\
yet they are without a trace of the body they used to support.\n");
    ob->set_save_flag(); /* no saving */
    return ob;
}

status
main(string arg)
{
    object      corpse;
    int         value, chance, cost;
    chance = 50; /* base bones chance */
    if (arg) {
        if (arg != "for bones") return 0;
        chance = 12;
    }
    if (arg) needmana(COST);
    needrank(2);
    needtask(CORPSE_TASK);
    corpse = present("corpse", environment(this_player()));
    if (!corpse)
      {
            write("You find no corpse to drain! You feel sick.\n");
            this_player()->hit_player(this_player()->query_level());
        return 1;
    }
    value = (int) corpse->heal_value();
    if (!value) {
        write("The corpse is already drained of all power.\n");
        return 1;
    }
    write("You whisper some words and the corpse bursts into flames.\n");
    say(this_player()->query_name() +
        " whispers some words and a corpse bursts into flames.\n");
    destruct(corpse);
    if(chance < random(100)) {
        tell_room(environment(this_player()),
"The flames turn clear " + HIC + "blue" + NORM + " and die rapidly.\n\
A pile of bones remain.\n");
        if (!arg) this_player()->heal_self(value/2);
        move_object(bones(value), environment(this_player()));
    }
    else
    if (!arg) this_player()->heal_self(value);
    if (arg) this_player()->add_spell_point(-COST);
    return 1;
}
