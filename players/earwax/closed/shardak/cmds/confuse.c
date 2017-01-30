/*
 * CONFUSE spell for the Servants of Shardak
 * Just a kind of calm spell. Costs 13 sps per person calmed.
 * 960401 Balowski
 */
#pragma strict_types
#include "/players/vertebraker/ansi.h"
#include "../std.h"
#include "../macros.h"
inherit CMD;
#define COST 13
#define magic_resistance(ob) ((int)ob->query_attrib("wil") ? (int)ob->query_attrib("wil") : (int)ob->query_level())
#define POWER 15 + random(10)

void
babble()
{
    say("\n" +
        this_player()->query_name() + " reaches up into the air with both "
        + this_player()->query_possessive() +
        " arms.\n\
A globe of swirling " + GRN + "green" + NORM + " light appears above " +
        this_player()->query_name() +
        ".\nThe globe explodes in a crescendo of glittering beams of light.\n");
    write("\
\n\
You stop fighting and reach up into the air with both arms.\n\
A globe of swirling " + GRN + "green" + NORM + " light appears just within your grasp.\n\
The globe explodes in a crescendo of glittering beams of light.\n");
}

varargs int
stop_fight(object target, object who)
{
    /* should ask for an extension to the mudlib stop_fight... */
    if (!who || (object) target->query_attack() == who) {
        target->stop_fight();
        if (!who || (object) target->query_attack() == who)
            target->stop_fight();

        tell_object(target,
"The glittering rays shine directly into your eyes. You feel dazed.\n");
        say(target->query_name() + " looks dazed.\n", target);
        write(target->query_name() + " is blinded by the light.\n");
        return 1;
    }
}

int
confuse_all(object this)
{
    object ob, next;
    int i;

    babble();
    this->stop_fight();
    this->stop_fight();

    next = first_inventory(environment(this));
    while (ob = next) {
        next = next_inventory(ob);
        if (living(ob) && ob != this && ob->query_attack()) {
            if (magic_resistance(ob) > POWER) {
                tell_object(ob, "The alluring light fails to affect you.\n");
                write(ob->query_name() + " resists your spell.\n");
            }
            else
                stop_fight(ob);
            i++;
        }
    }
    return i;
}

int
confuse_opps(object this)
{
    object ob, next;
    int i;

    babble();
    this->stop_fight();
    this->stop_fight();

    next = first_inventory(environment(this));
    while (ob = next) {
        next = next_inventory(ob);
        if (living(ob) && ob != this && (object) ob->query_attack() == this) {
            if (magic_resistance(ob) > POWER) {
                tell_object(ob, "The alluring light fails to affect you.\n");
                write(ob->query_name() + " resists your spell.\n");
            }
            else
                stop_fight(ob, this);
            i++;
        }
    }
    return i;
}

int
confuse(object target)
{
    object ob, next;
    int i;

    babble();
    if (magic_resistance(target) > POWER) {
        tell_object(target, "The alluring light fails to affect you.\n");
        write(target->query_name() + " resists your spell.\n");
    }
    else {
        stop_fight(target);

        next = first_inventory(environment(target));
        while (ob = next) {
            next = next_inventory(ob);
            if (living(ob) && ob != target)
                i += stop_fight(ob, target);
        }
    }
    return i + 1;
}

status
main(string arg)
{
    object      target;
    int         count;

    needrank(4);
    needmana(COST);

    if(this_player()->query_ghost()) return 0;
    if (!arg) {
        count = confuse_opps(this_player());
    }
    else if (arg == "all") {
        count = confuse_all(this_player());
    }
    else {
        target = present(lower_case(arg), environment(this_player()));
        if (!target) {
            write("There is no " + arg + " here.\n");
            return 1;
        }
        if (!living(target) || target == this_player()) {
            write("You open your mouth to speak, but have suddenly forgot what to say.\n");
            say(this_player()->query_name() + " mumbles some gibberish.\n");
            return 1;
        }
        if (!target->query_attack()) {
            write(target->query_name() + " is not in combat.\n");
            return 1;
        }
        count = confuse(target);
    }
    if (!count) {
        count++;
        write("Nobody were affected by your spell.\n");
    }
    this_player()->add_spell_point(-COST*count);
    return 1;
}
