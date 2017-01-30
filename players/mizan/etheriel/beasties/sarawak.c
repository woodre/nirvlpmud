inherit "/players/mizan/core/monster.c";
/* 07/14/06 Earwax: made it so the callouts don't occur without a 
 * player present - no need for 7 sarawaks all doing callouts every
 * 20 seconds or less from reboot til reboot.
 */
/* evaluation errors fixed by verte 3.24.01.  the suckage
    works now, and won't stop after one player is sucked.
    */
#include "/players/mizan/closed/Tracking-D.c"
#include "/players/boltar/things/esc.h"
#define BLINK esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"
#define UNBLINK esc+"[0m"

/**
 * sarawak.c
 *
 * This sarawak is a bit different from the original. It used to
 * ingest players randomly, wait a while, and then digest them,
 * quitting them out.
 *
 * The new sarawak ingests players randomly, and gives them 5total
 * commands to run, after which the player quits themselves out.
 *
 *
 * CONFIGURATION:
 *
 * MAX_INGEST_COMMANDS the is max number of commands a player gets
 * to free themselves before being eaten.
 *
 * DEBUG
 * Set this to 1 to see debug messages. Leave it at 1 for production
 * mode.
 *
 */

#define MAX_INGEST_COMMANDS     5
#define DEBUG                   0


int digestion_counter = 0;
status called, sumthin;

reset(arg)
{
    object gold,armor,weapon;

    ::reset(arg);
    if(arg) return;

    set_no_clean(1);
    set_name("Sarawak");
    set_race("sarawak");
    set_short("A hungry-looking Sarawak");

    set_long("Sarawak looks like a smaller version of Spuck. It seems to\n"+
    "like engulfing things, almost anything, so you should be careful when\n"+
    "you stay nearby. Don't hover too close or linger around too long or\n"+
    "your fate may match that of the poor Spuckball it just sucked up!\n");

    set_level(15);
    set_hp(775 + random(300));
    set_al(-670);
    set_wc(14);
    set_ac(42);
    set_chance(10);
    set_spell_dam(15);
    set_spell_mess1("Sarawak "+BLINK+"noggles"+UNBLINK+" you uncontrollably!");
    set_spell_mess2("You are caught in the shrapnel of Sarawak exploding.");
    set_chat_chance(20);
    load_chat("Sarawak makes a low, throbbing beat.\n");
    load_chat("Sarawak bobbles.\n");
    load_chat("You twitch nervously in the presence of a Sarawak.\n");
    load_chat("Sarawak appears to be hungry.\n");
    gold=clone_object("obj/money");
    gold->set_money(1);
    move_object(gold,this_object());
}


init() 
{
/*
    if(environment() && !called)
*/
    if (environment() && !called && present("GlobalPlayerId", environment(this_object())))
    {
      call_out("ingestion", 1 + random(20));
      called = 1;
    }

    if(this_player() && environment(this_player()) &&
      environment(this_player()) == this_object()) 
    {
#ifndef __LDMUD__ /* Rumplemintz */
        add_action("digestion"); add_xverb("");
#else
        add_action("digestion", "", 3);
#endif
    }
}

ingestion() 
{
    object ob;

    if(DEBUG != 0)
        say("[DEBUG] SARAWAK::ingestion() called...\n");
    else
        say("Sarawak shuffles about hungrily.\n");

    if(environment(this_object())) 
    {
        ob = first_inventory(environment(this_object()));
        while(ob) 
        {
            /* suck them in if they are MONSTERS, and between L5 and L21*/
            if(living(ob) && 1 == random(5) && ob->is_player() &&
               ob != this_object() && ob->query_name() != "sarawak" &&
               ob->query_level() > 5 && ob->query_level() < 21) 
            {

                if(ob != this_object()) 
                {
                   if(ob->query_guild_name() == "polymorph" && 1 == random(2))
                   {
                      say("Sarawak maliciously eyes " + ob->query_name() + " but backs off for some reason.\n");
                      tell_object(ob, "Something prevents you from being eaten by the Sarawak... This time...\n");
                      tell_object(ob, "You clutch your lump of clay tightly.\n");
                   }
                   else
                   {
                      if(DEBUG != 0)
                          say("[DEBUG] SARAWAK::ingestion() called on " + ob->query_name() + "\n");
                      else
                          say("Sarawak maliciously envelopes itself around " + ob->query_name() +".\n");
                          say((ob->query_name())+" is absorbed by Sarawak.\n");
                      tell_object(ob, "You are now stuck inside the Sarawak.\n");
                      move_object(ob,this_object());
                   }
                }
            } /* end if sucking */
          ob = next_inventory(ob);
        } /* end of while */
        while(remove_call_out("ingestion") != -1);
        if (present("GlobalPlayerId", environment(this_object())))
          call_out("ingestion", (10 + random(10)));
    } /* end if environment */
    return 1;
}

digestion(str) 
{
    if(!sumthin) {
    /* more than MAX_INGEST_COMMANDS commands... player gets eaten. */
    if(digestion_counter > MAX_INGEST_COMMANDS)
    {
        sumthin = 1;
        
        write_file("/players/mizan/logs/CREATURE_DIGESTION", 
           "[" + ctime() + "] " + this_player()->query_name() + " was eaten by a Sarawak.\n");
           
        if(this_player()) call_other(this_player(), "save_me");
        if(this_player()) call_other(this_player(), "quit");
        if(this_player()) call_other(this_player(), "do_quit");
        sumthin = 0;
        digestion_counter = 0;
        say("Sarawak burps.\n");
        return 1;
    }

    /* if the magic move is given... the player escapes... maybe */
    else if(str == "tickle" && 1 == random(MAX_INGEST_COMMANDS))
    {
        write_file("/players/mizan/logs/CREATURE_DIGESTION", 
           "[" + ctime() + "] " + this_player()->query_name() + " escaped a Sarawak!\n");

        write("You tickle the sarawak and it spews you out!\n");
        say("Sarawak gags as if tickles and hwarfs out the dripping body of " + this_player()->query_name() + " to destination unknown...\n");
        this_player()->transfer_all_to(this_object());
        this_player()->move_player("X#players/mizan/etheriel/ROOMS/spuck.c");
        digestion_counter = 0;
        return 1;
    }
    else
    {
        write("You are stuck inside the Sarawak.\nIt may help to do something to it in an effort to escape.\n");
        digestion_counter++;
        return 1;
    }
  }
}
  
query_realm()
{
   if(1 == random(2)) return "NT";
   else return 0;
}

realm()
{
   if(1 == random(2)) return "NT";
   else return 0;
}

