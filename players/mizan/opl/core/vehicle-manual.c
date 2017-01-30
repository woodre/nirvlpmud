inherit "/players/mizan/core/object.c";

/* This is the manual for our vehicle. You can customize it with inherits
 * and changing the variables that are available. In addition you can copy
 * over the contents of the 'manual' directory and edit it for your own
 * purposes. I think this stuff should all make sense.
 *
 * Note that you should leave the .txt extension for files. It makes it
 * harder in case this object can be used for a hack.
 *
 * -miz
 */

string manual_dir;

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    if(!manual_dir) manual_dir = "/players/mizan/core/vehicle_manual/";
    set_name("manual");
    set_get(1);
    set_weight(1);
    set_value(1);

}

set_manual_root(str) { manual_dir = str; }

init()
{
    ::init();

    /* override our read function with local one */
    add_action("on_read", "read");
}


on_read(str)
{
    if(!str) return 0;
    else if(str == "manual")
        return show_section("foreword");
    else if(str == "roles")
        return show_section("roles");
    else if(str == "intercom")
        return show_section("intercom");
    else if(str == "driving")
        return show_section("driving");
    else if(str == "engine")
        return show_section("engine");
    else if(str == "refueling")
        return show_section("refueling");
    else if(str == "hatch")
        return show_section("hatch");
    else if(str == "cannon")
        return show_section("cannon");

    else
    {
        write("There is no such section in the manual.\n");
        say(this_player()->query_name() + " appears confused by the manual.");
    }

}

show_section(str)
{
    say(this_object()->short() + "'s '" + str + "' section is carefully studied by " + this_player()->query_name() + "\n");
    cat(manual_dir + str + ".txt");
/*    write("\n"); */
    return 1;
}
