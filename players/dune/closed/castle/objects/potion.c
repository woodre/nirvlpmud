inherit "obj/clean";


int full;

init() { add_action("drink","drink"); }

get() { return 1; }
query_weight() { return 1; }

id(str)
{
    if (str == "tesula" && full)
        return 1;
    return str == "bottle";
}

short()
{
    if (full) return "bottle of tesula";
    return "empty bottle";
}

query_value()
{
    return (full * 2000);
}

long()
{
    write(
"     This is an odd concoction of what looks like swamp moss\n"+
"and certain tree barks.  There is not hint upon the bottle for\n"+
"what it could be used for.  The only letters upon the bottle\n"+
"spell out the word 'tesula'a'.\n");
}

reset(arg)
{
    if (arg) return;
    full = 5;
}

drink(str)
{
    if (str && str != "tesula" && str != "from bottle")
        return 0;
    if (full == 0)
        return 0;
    this_player()->heal_self(20);
    full -= 1;
    write(
"     You pour some of the natural concoction down your throat.\n"+
"Suddenly your muscles spaz out.  AAARRRGHHH!!.\n"+
"After a while you recover.  However, you begin to feel better than\n"+
"you have before.  As a matter of fact, you like the stuff!\n");
    say(call_other(this_player(), "query_name", 0) +
        " drinks a bottle of tesula.\n");
    say(call_other(this_player(), "query_name", 0) +
        " suddenly spaz's out!\n");
    say(call_other(this_player(), "query_name", 0) +
        " recovers from drinking the odd tesula liquid.\n");
    return 1;
}

status query_save_flag() { return 1; }
/* above added by Vertebraker [6.4.01] */
