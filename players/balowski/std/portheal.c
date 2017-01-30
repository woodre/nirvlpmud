/*
 * Portable heal thing with charges
 * Awful generic object..
 * Balowski@Nirvana, October '95
 */
#include "/players/balowski/lib.h"
inherit OBJECT;

string          Singular, Plural;       /* like "sausage" and "sausages" */
                                /* defaults to "charge" and "charges" */
string          UseMsg, HearMsg;/* message to user, bystanders when used */

int             MaxCharges,
                ChargeValue,
                Charges;        /* Number of charges left */
int             Intox, Satiate, Quench;
int             Fill;           /* Intox || Satiate || Quench */
int             Heal;
string          Verb;

void
create()
{
    ::create();
    Verb = "use";
    Singular = "charge";
    Plural = "charges";
    MaxCharges = 1;
    Charges = 1;
    set_weight(1);
}

status
query_save_flag()
{
    return (MaxCharges > 1);   /* no saving if many charges */
}

#if 0
status
prevent_insert()
{
    if (Charges && MaxCharges > 1) {
        write("You can not store the " + query_name() + " in bags.\n");
        return 1;
    }
    return 0;                   /* allow insert */
}
#endif

static void
remaining()
{
    /* Never found out which is best, one or many write's */
    if (!Charges)
      write("The " + query_name() + " is empty.\n");
    else {
        write(Charges > 1 ? "There are " + Charges + " " + Plural + " left.\n"
	                  : "There is 1 " + Singular + " left.\n");
    }
}

void
long(string id)
{
    ::long(id);
    if (MaxCharges > 1)
      remaining();
}

int
query_value()
{
    /* rule: if total sobering is more than 30 then cost is 10k */
    /* everything sells at twice the value of query_value */

    if (Charges*Fill < -30 && Charges*ChargeValue < 10000)
      return ::query_value() + 5000;

    return ::query_value() + (Charges*ChargeValue) >> 1;
}

int
query_weight()
{
    /* rule: sobering items have weight 1 : 1 */
    if (Fill < 0)
      return ::query_weight() + Charges;
    return ::query_weight() + Charges/3;
}

void
init()
{
    if (Verb)
      add_action("cmdUse", Verb);
}

status
cmdUse(string str)
{
    int         WeightChange;
    string      what, cont;

    if (!str)
        return 0;

    /* parse command. could be 'drink wine from bottle 2' */
    if (sscanf(str, "%s from %s", what, cont) == 2) {
        if (what != Singular || present(cont) != this_object()) {
            notify_fail(capitalize(Verb + " " + what + " from what?\n"));
            return 0;
        }
    }
    else
        /* or just 'drink wine' */
        if (str != Singular) {      
            notify_fail(capitalize(Verb + " what?\n"));
            return 0;
        }

    if (!Charges) {
        write("There are no " + Plural + " left.\n");
        return 1;
    }
    if (environment() != this_player() && !get()) {
	write("You fail.\n");
	return 1;
    }

    /* only one out of alcohol/food/drink should be used at a time */
    if (Intox && !this_player()->drink_alcohol(Intox))
        return 1;
    if (Satiate && !this_player()->eat_food(Satiate))
        return 1;
    if (Quench && !this_player()->drink_soft(Quench))
        return 1;
    this_player()->heal_self(Heal);

    WeightChange = query_weight();      /* remember old weight */
    Charges--;

    /* give message to user and surroundings */
    /* the auto generated messages are rather bad
       (and may become bad English) */
    if (UseMsg)
        write(UseMsg);
    else
        write("You " + Verb + (Charges ? " a " : " the last ") +
                Singular + ".\n");
    if (HearMsg)
        say(this_player()->query_name() + HearMsg);
    else
        say(this_player()->query_name() + " " + Verb +
                (Charges ? "s a " : "s the last ") + Singular + ".\n");

    if (WeightChange -= query_weight())
        environment()->add_weight(-WeightChange);

    if (!Charges && !query_value()) {
        if (MaxCharges > 1) write("The empty " + query_name() + " vanishes.\n");
        destruct(this_object());
    }
    else
        remaining();

    return 1;
}

/*
 * Functions for setting this object up
 */
void set_charges(int x)
{
    Charges = MaxCharges = x;
}

void set_intox(int x)
{
    Intox = (Fill = x);
    Satiate = (Quench = 0);
}

void set_satiate(int x)
{
    Satiate = (Fill = x);
    Intox = (Quench = 0);
}

void set_quench(int x)
{
    Quench = (Fill = x);
    Satiate = (Intox = 0);
}

void set_charge_name(string s, string p)
{
    Singular = s;
    Plural = p;
}

void set_verb(string v)
{
    Verb = v;
}

void set_charge_value(int v)
{
    ChargeValue = v;
}

void set_messages(string player, string bystanders)
{
    UseMsg = player;
    HearMsg = bystanders;
}

void set_heal(int h)
{
    Heal = h;
    if (Heal > 50) {
        ChargeValue = 10000;
        return;
    }
    switch (Fill) {
        case  0: ChargeValue = h * 60; break;
        case  7: ChargeValue = h * 18; break;
        case  8: ChargeValue = h * 16; break;
        case  9: ChargeValue = h * 15; break;
        case 10: ChargeValue = h * 14; break;
        case 11: ChargeValue = h * 13; break;
        case 12: ChargeValue = h * 12; break;
        case 13: ChargeValue = h * 11; break;
        default:
            if (Fill < 0)
                ChargeValue = (Fill < -15) ? 10000 : -20*Fill;
            else
                if (Fill >= 14)
                    ChargeValue = h * 10;
                else
                    ChargeValue = h * 20;
    }
}

int
query_potence()
{
    return Heal;
}

string
is_heal()
{
    if (Intox) return "intox";
    if (Satiate) return "stuff";
    if (Quench) return "soak";
    return "other";
}
