/* std potion object */

inherit "/players/vertebraker/closed/std/treasure";

void potion_effect();

int empty;

void
init()
{
    ::init();
    add_action("cmd_drink", "drink");
    add_action("cmd_drink", "quaff");
    add_action("cmd_drink", "gulp");
    add_action("cmd_drink", "sip");
    add_action("cmd_drink", "swallow");
    add_action("cmd_drink", "chug");
}

void
do_drink()
{
    name = "glass bottle";
    alias_name = "bottle";
    short_desc = "An empty glass bottle";
    long_desc = "\
An empty glass bottle, drained of all of its contents.\n\
A wooden cork sticks inside the mouth of the bottle.\n";
    empty = 1;
    aliases = ({ "empty bottle", "empty glass bottle" });
    set_value(10);
}

status
cmd_drink(string str)
{
    string sh, what;

    if(empty) return 0;

    if(!str || !id(str))
    {
      notify_fail("Drink what?\n");
      return 0;
    }
    
    what = query_verb();

    write("You pull the cork out and " + what + " the contents of a potion.\n");
    say((string)this_player()->query_name() + " \
pulls the cork out and " + what + "s the contents of a potion.\n");
    potion_effect();
    do_drink();
    
    return 1;
}

status
query_save_flag() { return 1; }

void
long(string str)
{
    if(str == "cork" || str == "the cork")
      write("A tan, puffy cork that sticks out of the top of the bottle.\n");
    else ::long(str);
}

status
id(string str)
{
    return str == "cork" || ::id(str);
}

