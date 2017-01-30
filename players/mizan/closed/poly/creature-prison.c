/**
 * The purpose of this object is to be a general template for things that
 * temporarily trap monsters. 
 *
 * Note that in order to actually use this, the player needs to have a higher
 * level than the monster being trapped.
 *
 */

string my_name;
string my_alias;
string my_short_desc;
string my_long_desc;
string my_escape_say_message;
string my_escape_tell_message;

object my_prisoner;

int prison_duration;

id(str) { return str == my_name || str == my_alias; }

get()  { return 0; }
add_weight() { return 0; }
can_put_and_get() { return 1; }
query_save_flag() { return 1; }
query_realm() { return "NT"; }

short() { return my_short_desc; }

long()
{
    write(my_long_desc + "\n");
}

reset(arg)
{
    if(arg) return;

    set_name("crystal");
    set_alias("prison");
    set_short("A crystal prison");
    set_long("This is a crystalline prison. There appears to be someone trapped inside...\n");
    set_prison_duration(30);
    set_escape_say_message("The crystal explodes in a violent crash!\n");
    set_escape_tell_message("The crystal explodes in a violent crash! You are freed!\n");

    remove_call_out("delayed_reset");
    call_out("delayed_reset", 1);
}

delayed_reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", prison_duration);
}

erase_me()
{
    if(environment()) tell_room(environment(), my_escape_say_message);
    if(my_prisoner) tell_object(my_prisoner, my_escape_tell_message);
    destruct(this_object());
    return 1;
}

set_short(arg)
{
    my_short_desc = arg;
}

set_long(arg)
{
    my_long_desc = arg;
}

set_name(arg)
{
    my_name = arg;
}

set_alias(arg)
{
    my_alias = arg;
}

set_prisoner(arg)
{
    my_prisoner = arg;
}

set_prison_duration(arg)
{
    prison_duration = arg;
}

set_escape_say_message(arg)
{
    my_escape_say_message = arg;
}

set_escape_tell_message(arg)
{
    my_escape_tell_message = arg;
}