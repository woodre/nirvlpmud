/*
 * SPY spell for Shardak guild.
 * By Balowski
 */
#pragma strict_types
#include "../std.h"
#include "../macros.h"
inherit CMD;

#define COST 19

status
main(string str)
{
    object          ob, item, dragon;
    string          name;
    int             mhp, hp, shape;

    if (!str) {
        notify_fail("Spy on who?\n");
        return 0;
    }
    needmana(COST);
    needrank(5);
    if (!(dragon = (object) previous_object()->Dragon())) {
        notify_fail("You must have a dragon.\n");
        return 0;
    }
    if (!sscanf(str, "on %s", name))
        name = str;

    if(!(ob = find_player(name)) || !environment(ob) || (ob->query_invis()) || wizardp(ob))
    {
        write("Your dragon takes off, but quickly returns without any information.\n");
    }
    else {
        if (ob == this_player()) {
            write("Your dragon turns it head and stares at you.\n");
            write("You have a sudden feeling that you said something stupid.\n");
            return 1;
        }
        if (present(ob, environment(this_player()))) {
            write("The spirits in the dragon hiss: " + ob->query_name() +
                " is very close, master.\n");
            return 1;
        }
        /*
         * I would rather do a call_out and things here, but it
         * is a problem since the room long desc only is avail on write()
         * Should we switch to 3.2 my troubles will be over..
         */

        /* This looks pretty bad if the player is indoors */
        if (random(100) >= 40)
            tell_room(environment(ob), "\
High overhead a large dragon briefly soars.\n");

        write("Your dragon takes off, and returns with this image:\n");
        environment(ob)->long();
        for (item = first_inventory(environment(ob)); item;
             item = next_inventory(item)) {
            if (!(name = (string) item->short()))
                continue;
            if (living(item) && !item->query_ghost()) {
                shape = qmhp(item)/(qhp(item) || 1);
                if (shape >= 10) write(name + " [very bad shape].\n");
                else if (shape >= 5) write(name + " [bad shape].\n");
                else if (shape >= 2) write(name + " [somewhat hurt].\n");
                else if (qhp(item) + 20 < qmhp(item)) write(name + " [slightly hurt].\n");
                else write(name + " [good shape].\n");
            }
            else write(name + ".\n");
        }
        
        if (item = (object) ob->query_weapon()) {
            if (!(name = (string) item->short())) name = "a weapon";
#ifdef __VERSION__
            else if (name[<10..<1] == " (wielded)") name = name[0..<11];
#else
            else if (name[-10..-1] == " (wielded)") name = name[0..-11];
#endif
            write("The spirits in the dragon hiss: " +
                capitalize((string) ob->query_pronoun()) + " is wielding " +
                name + ".\n");
        }
        else
            write("The spirits in the dragon hiss: " +
                capitalize((string) ob->query_pronoun()) + " is unarmed.\n");
    }
    this_player()->add_spell_point(-COST);
    return 1;
}
