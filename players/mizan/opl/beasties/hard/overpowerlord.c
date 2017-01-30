/* STILL WORKING ON THIS ONE. LAST MONSTER TO BE COMPLETED. */

inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

int redeem_code;
int combat_announce;

reset(arg)
{
    object belt, secpass, radio;
    ::reset(arg);
    if(arg) return;

    /* This is the redemption code if the player wins */
    redeem_code = random(899999) + 100000; 

    /* standard game lib stuff */
    set_name("OverPowerLord");
    set_race("overpowerlord");
    set_alias("opl");
    set_alt_name("beast");
    set_short(HIY + "OverPowerLord" + NORM);
    set_long("    Here he is in all of his regal glory... The five time, undisputed\n"+
        "  World Wrestling Smackdown Champion... The reigning Combat Sambo Heavyweight\n"+
        "  Champion... The current chairman of the International Cat Rescue Board, and an\n"+
        "  all-around generally nice guy- " + HIY + "THE ONE, THE ONLY... OVERPOWERLORD" + NORM + ".\n"+
        "  At least ten feet tall and tipping the scales at roughly twelve hundred kilos,\n"+
        "  OverPowerLord cuts a horrifyingly imposing figure. You realize at this point\n"+
        "  that he wasn't wearing a Viking helmet in all of his photos. Those horns are\n"+
        "  actually HIS. He must have the genes of a bull somewhere or somehow. He greets\n"+
        "  you with a wide, genuine smile and shakes your hand. At this point you realize\n"+
        "  that his skin is a ridiculously tough cowhide of some sort.\n\n"+
        "  This is going to be one hell of a fight, if you make it out alive.\n");

    set_hp_bonus(8888);
    set_heal(20, 1);

    set_level(31);
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 38888;
    hit_point = 38888;

    set_al(0);
    set_wc(250);
    set_ac(88);
    
    radio = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(radio, this_object());

    belt = clone_object("players/mizan/opl/items/opl-champ-belt.c");
    move_object(belt, this_object());

    secpass = clone_object("obj/key");
    secpass->set_type("high-security");
    secpass->set_code("clubdoor");
    move_object(secpass, this_object());
    
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 4; 

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(400);
    
    
    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_COVERS_PRESENT_ALLIES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);
    set_attribute(ATTRIB_FEARLESSNESS, 100);
    set_attribute(ATTRIB_PERCEPTION, 20);
    set_attribute(ATTRIB_CRUELTY, 10);
    set_attribute(ATTRIB_INSANITY, 35);
    set_attribute(ATTRIB_GENEROUSITY, 90);

    set_monster_guild_level(6);
    set_monster_guild_rank("The Boss");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 0);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 0);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 6);
    set_chance_of(CHANCE_EMOTE_PANICKED, 6);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 6);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 50);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 1);
    set_chance_of(CHANCE_PELTING_THINGS, 1);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 500000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 5000);
    set_int(VAL_HUNTING_THRESHOLD, 30);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 600);
    
    
    /* lots of channel and emote stuff */
    attacked_emotes = ({
        query_name() + " says: " + HIY + "Yeah! Let's see some fighting!" + NORM + "\n",
        query_name() + " says: " + HIY + "ALL RIGHT! Let's go!" + NORM + "\n",
        query_name() + " laughs heartily.\n",
        query_name() + " grins biggly.\n",
    });

    attacked_mchannels = ({
	"OOOooooh yeah! I'm getting attacked!\n",
        "Now this is my kind of music!\n",
        "OOOH Yeah!\n",
    });


    panicked_emotes = ({
        query_name() + " peers at you quizzically.\n",
        query_name() + " appears to be confused.\n",
    });

    panicked_mchannels = ({
         "UHey, this is a little strange...\n",
         "Wow, that's really weird...\n",
    });

    
    hit_hard_emotes = ({
        query_name() + " says: " + HIY + "OFF THE HOOK! Now that's the kind of hard hitting shit we're talking about!" + NORM + "\n",
        query_name() + " says: " + HIY + "All right! With some GUSTO! Let's go!" + NORM + "\n",
        query_name() + " says: " + HIY + "YEAH! NICE SHOT! Try THIS one for size!" + NORM + "\n",
        query_name() + " says: " + HIY + "AHAHAHAHA! Good hit! Yeah!" + NORM + "\n",
        query_name() + " says: " + HIY + "YEAH KEEP THEM COMING! Now THIS is a FIGHT!" + NORM + "\n",
    });

    hit_hard_mchannels = ({
        "Hey, hey, hey, If these guys make it, I'm inviting them to the parties!\n",
        "Oh yeah! Showing some fight. That's the spirit!\n",
        "Yeah! These guys know how to PLAY!\n",
        "Hard hitting music from these players! My kind of jazz!\n",
    });


    taunting_emotes = ({
        query_name() + " sticks his chin out and says: " + HIY + "Come on, you've gotta hit THAT!" + NORM + "\n",
        query_name() + " says: " + HIY + "You can do better! Come on!" + NORM + "\n",
        query_name() + " says: " + HIY + "I KNOW you guys can hit harder, after all you made it here!" + NORM +"\n",
    });

    taunting_mchannels = ({
        "Bahahaha!\n",
        "Righteous!\n",
    });


    triumph_emotes = ({
        query_name() + " says: " + HIY + "OWNED! Good fight, my friends. Well met!" + NORM + "\n",
        query_name() + " says: " + HIY + "BAM! Gotcha! Good fight, my friends!" + NORM + "\n",
    });

    triumph_mchannels = ({
        "CRAAAAAAAAAAAAAAAAGH!\n",
        "RAAAAAAAAAAAAAAAAARRH!\n",
    });


    casual_emotes = ({
        query_name() + " says: " + HIY + "You ready for some hardcore fighting?" + NORM + "\n",
        query_name() + " says: " + HIY + "Oh, I'm ready. Whenever you're good to go, it's on." + NORM + "\n",
        query_name() + " says: " + HIY + "Yup. I'm ready for combat. Start whenever you're good." + NORM + "\n",
    });


    casual_mchannels = ({
        "Raar.\n",
        "Mrraaaargh.\n",
        "Mraaah.\n",
    });


    scared_emotes = ({
        query_name() + " says: " + HIY + "Whoa. That was weird." + NORM + "\n",
    });
    
    scared_mchannels = ({
        "...\n",
    });


    death_emotes = ({
        query_name() + " says: " + HIY + "VERY WELL DONE! You have defeated me..." + NORM +"\n",
    });

    death_mchannels = ({
        "Well... they got me... fair and square.\n",
    });


    shit_throw_emotes = ({
        query_name() + " beams with a shit-eating grin...\n",
    });
    
    shit_throw_mchannels = ({
        "Pooooooooop!\n",
    });

    
    balloon_throw_emotes = ({
        query_name() + " blinks loudly.\n",
    });

    balloon_throw_mchannels = ({
        "These water balloons kind of... suck.\n",
        "Haha. Water balloons.\n",
    });


    arrival_emotes =({
        "OverPowerLord salutes you.\n",
    });

    arrival_mchannels =({
        "Ooooh yeah. Time for work baby! WOOOO! WOOOO!\n",
    });

}


/* Called when the monster dies */
death(string str)
{
    object portal;
    string result;

    portal = clone_object("/players/mizan/opl/environs/victory_portal.c");
    move_object(portal, environment(this_object()));

    say(HIY + " >>> > > C O N G R A T U L A T I O N S ! ! ! < < <<<" + NORM + "\n");
    say(HIY + " >>> > > C O N G R A T U L A T I O N S ! ! ! < < <<<" + NORM + "\n");
    
    say(HIY + "  You have defeated OverPowerLord in the ultimate, most awesomely" + NORM + "\n");
    say(HIY + "  manly contest of arena combat! Your claim code is " + redeem_code + "."  + NORM + "\n");

    say("\n" + HIY + "  What do you do with this claim code? Simple! Mail Mizan" + NORM + "\n");
    say(HIY + "  and provide him a valid shipping address- because YOU HAVE JUST" + NORM + "\n");
    say(HIY + "  WON SOME REAL-LIFE LOOT! That's right! OverPowerLord and Nirvana" + NORM + "\n");
    say(HIY + "  themed, exclusive LOOT that is now just one free shipment away!" + NORM + "\n");

    say("\n" + HIY + "  Now go forth to MAIL MIZAN and tell him 'I BEAT OVERPOWERLORD" + NORM + "\n");
    say(HIY + "  NOW GIMME MY LOOT!!!!' Don't forget your claim code of '" + redeem_code + "'" + NORM + "\n");
/*
    say(HIY + "The ghost of OverPowerLord tells you: WELL DONE MOTHERFUCKERS!!! YEAH!" + NORM + "\n");
*/

    result = HIY + "\n" + format("(junk) The OverPowerLord has been DEFEATED!", 76) + NORM + "\n";

/*
    say(result);
 */

    chan_msg(result);
    emit_channel("junk", result);


    ::death(str);
}


/* inside this function you can call your code to do special combat.
 * It is called when an attacker is present, and engaged in combat.
 * Have fun :)
 */
heartbeat_attack()
{
    if (!combat_announce && attacker_ob) junk_combat_announce();
    if (attacker_ob && 1 == random(2)) tell_story();
    if (attacker_ob && 1 == random(3)) smash_pets();
}

junk_combat_announce()
{
    object ob;
    object oc;
    object room;
    string message;
    string result;
    int opponents;

    room = environment(this_object());
    message = "";

    if(room)
    {
        /* We are going to tell the whole mud who is fighting OPL. */
        ob = first_inventory(room);
        while(ob)
        {
            oc = next_inventory(ob);
            if(living(ob) && !ob->is_maze_monster())
            {
                if(opponents)
                {
                     message += ", " + ob->query_name();
                }
                else
                {
                    message += ob->query_name();
                    opponents++;
                }
            } 
            ob = oc;
        }


    result = HIY + "\n" + format("(junk) " + message + ", and Lady Luck herself have entered DEATHMATCH COMBAT with the OverPowerLord.", 76) + NORM + "\n";

/*
    say(result);
*/

    chan_msg(result);
    emit_channel("junk", result);

    }
    combat_announce = 1;
}

tell_story()
{
    string result;
    result = short() + " says: " + "/players/mizan/opl/daemons/oplDM"->tell_story();
    say(result + NORM + "\n");
}

smash_pets()
{
    object pet;

    if(!environment(this_object())) return;
    pet = present("pet", environment(this_object()));
    if(pet && pet->is_pet() && !pet->query_ghost())
    {
        say(HIY + "OverPowerLord strikes " + pet->query_name() + " with a sidearm hit!" + NORM + "\n");
        pet->hit_player(random(180), "other|manliness");

    }
}

init()
{
    ::init();
    add_action("log_everything", "", 3);
}


log_everything(str)
{
    string ipaddr;
    string temp;
    object room;
    string attacker_filename;

    int attacker_wc;
    int attacker_ac;
    int attacker_hp;
    int attacker_mhp;

    int player_wc;
    int player_ac;
    int player_hp;
    int player_mhp;
    int player_sp;
    int player_msp;

    /* gather data */
    ipaddr = query_ip_number(this_player());
    room = environment(this_player());

    player_ac = this_player()->query_ac();
    player_wc = this_player()->query_wc();
    player_hp = this_player()->query_hp();
    player_mhp = this_player()->query_mhp();
    player_sp = this_player()->query_sp();
    player_msp = this_player()->query_msp();

    if(attacker_ob)
    {
       attacker_filename = object_name(attacker_ob);
       attacker_hp = attacker_ob->query_hp();
       attacker_mhp = attacker_ob->query_mhp();
       attacker_ac = attacker_ob->query_ac();
       attacker_wc = attacker_ob->query_wc();

       temp = "\"" + ctime() + "\",\t";
       temp += "\"" + redeem_code + "\",\t";
       temp += "\"" + this_player()->query_name() + "\",\t";
       temp += "\"" + attacker_filename + "\",\t";
       temp += "\"" + attacker_hp + "\",\t";
       temp += "\"" + attacker_mhp + "\",\t";
       temp += "\"" + attacker_wc + "\",\t";
       temp += "\"" + attacker_ac + "\",\t";
       temp += "\"" + player_hp + "\",\t";
       temp += "\"" + player_mhp + "\",\t";
       temp += "\"" + player_sp + "\",\t";
       temp += "\"" + player_msp + "\",\t";
       temp += "\"" + player_wc + "\",\t";
       temp += "\"" + player_ac + "\",\t";

       write_file("/players/mizan/opl/logs/opl_combat.csv", temp + "\n");

    }


    /* records commands */
    temp = ctime() + " " + redeem_code + " " + this_player()->query_name() + " (" + ipaddr + ") [" + player_hp + "/" + player_mhp + "h ";
    temp += player_sp + "/" + player_msp + "s]";

    if(attacker_ob) temp += " #" + attacker_hp + "/" + attacker_mhp + "#";
    else temp += " #nc#";

    temp += " " + str + "\n";

    write_file("/players/mizan/opl/logs/opl_snoop.log", temp);

}



/* eof */
