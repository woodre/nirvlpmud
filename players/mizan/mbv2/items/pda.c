inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"
/*
 * New little bit of evil. I noticed that some players like to spam
 * commands, in the order of 10-20 cmds per second (such as Jenny's laptop)
 * so to protect against spam i will make this device explode if accessed more
 * than 10 times in a 2 second period.
 *
 *
 */

int access_clear;
int access_counter;

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_short("A beaten-up little handheld device (Version 0.81)");
   set_long("This is a beaten up little handheld device that has just one\n"+
            "application burned into it.. It seems that there is a button\n"+
            "that has been specifically labelled of interest. It simply reads:\n"+
            "   'Refresh'...\n" +
            HIR + "\nNEW:" + NORM + " You can also now 'mattrib <indexnum>' of a monster.\n\n");

   set_name("device");
   set_alias("handheld");
   set_weight(1);
   set_save_flag(1);
   set_value(200);

   set_read("The words 'Blackberry 857' are still inscribed on this decrepit little thing.\n");
   set_smell("The device smells like manure.\n");
   set_taste("The device tastes a lot like manure.\n");
}


query_value() { return 130; }

init() 
{
    ::init();
	add_action("on_refresh","refresh");
	add_action("on_mattrib","mattrib");
}

on_refresh() 
{
    say(this_player()->query_name() + " glances quickly at a beaten-up handheld device.\n");
    write("You click the button marked 'Refresh' on the handheld.\n");
    "players/mizan/mbv2/tacticalDM"->on_monster_guild_who();

    access_clear = 0;
    access_counter++;

    /* more than 5 times is enough */
    if(access_counter >= 5)
    {
        write("You have clicked the device too many times, too quickly... it explodes!\n");

        if(this_player())
        {
            say(this_player()->query_name() + " clicked the device too many times... it explode violently!\n");
            log_file("mizan.explosivedevice", ctime() + " " + this_player()->query_name() + " clicked too many times.\n");
            this_player()->hit_player(1000000);
            destruct(this_object());
            return 1;
        }

    }

    remove_call_out("clear_counters");
    call_out("clear_counters", 1);

    return 1;
}

clear_counters()
{
    access_clear= 1;
    access_counter = 0;
}

on_mattrib(arg)
{
    if(!arg || arg < 0)
    {
        write("A pixellated image appears on the screen and pronounces its name as 'HUGH'.\n");
        write("Hugh says: You gotta pick a number, ya farging icehole!\n");
        write("Suddenly the image fades away.\n\n");

        write("You grin stupidly at the device.\n");
        say(this_player()->query_name() + " grins stupidly at a beaten-up handheld device.\n");
        return 1;
    }

    say(this_player()->query_name() + " glances quickly at a beaten-up handheld device.\n");
    write("You click the button marked 'Refresh' and selected 'mattrib' for a monster.\n");
    "players/mizan/mbv2/tacticalDM"->on_attrib_monster(arg);

    return 1;
}
