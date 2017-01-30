inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

#define MY_FILENAME "/players/mizan/mbv2/beasties/hoth.c"


reset(arg)
{
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Hoth Monster");
    set_race("monster");
    set_alias("hoth");
    set_short("The Hoth Monster (hungry)");
    set_long("A very large white furry beast with huge claws, powerful arms and legs.\n"+
             "The Hoth Monster stands about 15 feet tall, his claws are about 3ft across.\n"+
             "It would be wise not to anger this beast.\n");

    set_level(19);
    set_gender("male");
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 900;
    hit_point = 900;

    set_al(-200);
    set_wc(35);
    set_ac(9);
    
    /* autoheals twice as fast other monsters, cos it cannot call from the pink laser */
    set_heal(6,2);

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_off(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_on(MODE_KID_KILLER);
    toggle_on(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_USE_REMOTE_WAYPOINTS);
    toggle_on(MODE_CORPSE_EATER);
    toggle_on(MODE_SLOW_HITFADES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 30);
    set_attribute(ATTRIB_FEARLESSNESS, 90);
    set_attribute(ATTRIB_PERCEPTION, 50);
    set_attribute(ATTRIB_CRUELTY, 90);
    set_attribute(ATTRIB_INSANITY, 70);
    set_attribute(ATTRIB_GENEROUSITY, 0);

    set_monster_guild_level(1);
    set_monster_guild_rank("Chaotic");

    set_string(STR_TEAM_NAME, "ArmyOfBoltar");
    set_string(STR_CABAL_NAME, "Gangstahs");

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 20);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 9);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 5);
    set_chance_of(CHANCE_EMOTE_CASUAL, 9);
    set_chance_of(CHANCE_EMOTE_SCARED, 9);
    set_chance_of(CHANCE_PELTING_THINGS, 9);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 15000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 500);
	set_int(VAL_HUNTING_THRESHOLD, 100);        /* make him extra hard to get pissed off */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 15);     /* make him slow */

    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Hoth Monster bellows wildly!\n",
        "Hoth Monster flails its wickedly sharp claws in anger!\n",
        "Hoth Monster appears to be absolutely delighted in your impending death.\n",
        "Hoth Monster roars like a wild drunken banshee!\n",
    });

	attacked_mchannels = ({
		"I must say, gentle creatures, that humans most definitely are distasteful.\n",
        "I am not angry or bitter at humans! I am merely disappointed.\n",
        "Bloody hell! These people have attacked me and I must respond in kind.\n",
        "I dareday, these ruffians and scoundrels will meet their end at my claws!\n",
        "Tally ho! Nasty little buggers they are!\n",
        "Bodge this, bodge that, here I come with a baseball bat!\n",
        "Quite the biggie, this barmy squat bastard!\n",
        "This whole random combat business has me bodgered all up.\n",
        "What in the blazes do they think they are doing!\n",
        "Earl grey tea... Check. Biscuits and cream... Check. Bodybags... Check.\n",
	});


    panicked_emotes = ({
        "Hoth Monster groans wildly!\n",
        "Hoth Monster appears flustered!\n",
    });

	panicked_mchannels = ({
		"Oh dear, we can't have any of this messiness now, shall we?\n",
        "Drat! What is wrong with these people?\n",
        "What a bender, he's hitting me as if i were all bladdered!\n",
	});

    
    hit_hard_emotes = ({
        "Hoth Monster grunts painfully!\n",
        "Hoth Monster growls loudly!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! Bite my arm off for a jar of chutney!\n",
        "Cheeky little bastard! That hurt!\n",
        "Why that daff bastard, I ought to turn him into some pavement pizza!\n",
    });


    taunting_emotes = ({
        "Hoth Monster stares menacingly at you.\n",
        "Hoth Monster grins wickedly, in bloody anticipation.\n",
    });

    taunting_mchannels = ({
        "Bloody booger bastard!\n",
        "Taking the piss on it then!\n",
        "All sixes and sevens they'll be!\n",
        "Someone's going to get thumped in the face!\n",
    });


    triumph_emotes = ({
        "Hoth Monster grins wickedly.\n",
    });

    triumph_mchannels = ({
        "Have at you! Here's a spanner in your works!\n",
        "Bloody booger! Ha HAH!\n",
        "Brilliant!\n",
    });


    casual_emotes = ({
        "Steam slowly wafts from the bloody, sharpened claws of the Hoth Monster.\n",
        "The Hoth Monster hovers nearby, looking for something to eat.\n",
        "Your stomach rumbles. The Hoth Monster shoots an evil glance at you.\n",
    });

    casual_mchannels = ({
        "If I find a tasty mudkid or pet, well I'll be mighty chuffed, I'll say.\n",
        "Mudkid corpses are my speciality!\n",
        "Well isn't that the mutt's nuts! I found some money!\n",
        "I certainly hope everyone is well this fine day!\n",
        "Can anyone recommend a good nail clipper? My claws seem quite a bit dull.\n",
    });


    scared_emotes = ({
        "Hoth Monster appears somewhat flustered.\n",
    });
    
    scared_mchannels = ({
        "Well have at you then! This is not a good time to be knackered about!\n",
        "Not acceptable! Not acceptable at all indeed!\n",
        "The daftness of them! Punk ruffian booger bastards!\n",
    });


    death_emotes = ({
        "Hoth Monster crumples to the ground. Dead.\n",
    });

    death_mchannels = ({
        "BLOODY BOOGER BASTARD! I died...\n",
    });


    shit_throw_emotes = ({
        "Hoth Monster whistles innocently.\n",
    });
    
    shit_throw_mchannels = ({
        "Well here's a pavement pie right at you!\n",
    });

    
    balloon_throw_emotes = ({
        "Hoth Monster grins evilly.\n",
    });

    balloon_throw_mchannels = ({
        "Hah hah! Chuffed me all up to bits, that is...\n",
    });


    arrival_emotes =({
        "Hoth Monster rides in on an icy wave of death.\n",
    });

    arrival_mchannels =({
        "Greets, mates! Top of the morning to ya!\n",
    });

}

/* eof */


int done;
int busyct;

int handnum, gold, flg, stophb;
int last_move;
int atflg;
object yesply, notply;

/* most of the functionality was moved into the monsterplus core since it is supported... */
catch_tell(str) 
{
    int rr,i;
    object blah;
    string where,who,what;
    object check;
    if(busyct) return;
    busyct = 1;
    check = allocate(50);


    if (sscanf(str, "%s Monster %s\n", who , what) == 2 ) 
    {
        busyct=0;
        return 1;
    }

    /* Hoth eats corpses instead of picking them up like other monsterplus.c  -miz */
/*
    blah = present("corpse");
    if(blah) 
    {
        move_object(blah,this_object());
        say("The Hoth Monster takes "+blah->short()+"\n");
        say("The Hoth Monster consumes the corpse whole.\n");
        say("The Hoth Monster burps rudely.\n");
        log_file("hoth_monster", "consumed "+blah->short()+"\n");
        destruct(blah);
    }
*/

    /*
    if(!this_player() || !environment()) return;
    if(sscanf(str,"%s leaves %s.\n",who,where) == 2)
    if(find_living(lower_case(who)))
    if(find_living(lower_case(who))->is_pet())
    if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) )
    {
        say("The Hoth Monster leaves following "+who+"\n");
        move_object(this_object(), environment(find_living(lower_case(who))));
        say("The Hoth Monster arrives.\n");
    } else
    command(where);

    if(sscanf(str, "%s leaves %s\n", who, where) == 2 )
    if(find_living(lower_case(who)))
    if(find_living(lower_case(who))->query_npc())
    if(sscanf(str, "%s leaves %s\n", who, where) == 2 && call_other(find_living(lower_case(who)), "is_pet", 0) == 1)
    if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) )
    {
        say("The Hoth Monster leaves following "+who+"\n");
        move_object(this_object(), environment(find_living(lower_case(who))));
        say("The Hoth Monster arrives.\n");
    } else
        command(where);
    */

    check = all_inventory(environment(this_object()));
    i = 0;
    while (i<sizeof(check)){
    if (call_other(check[i], "is_pet",0) == 1) {
    /*
    log_file("hoth_monster", "attacked "+check[i]->short()+"\n");
    */
    say("The Monster sees a tasty treat.\n");
    say("The Hoth Monster proceeds to make "+check[i]->query_name()+" his next meal.\n");
    say("The Hoth Monster attacks with his giant claws, sending his prey flying several\nfeet.\n");
    attack_object(check[i]);
    busyct=0;
    return 1;
    
    i = sizeof(check);
    }
        i += 1;
    }
    rr = random(50);
/*
    if (rr < 8)
    random_move();

  */
    busyct = 0;

    /* added by mizan for monsterplus.c super */
    ::catch_tell(str);
    
    return 1;
}


second_life() 
{
    if(attacker_ob) 
/*
  log_file("hoth_monster","Attacker:"+attacker_ob->query_name()+" ");
  log_file("hoth_monster","Hoth Died.\n");
*/
    if(random(100) < 20)
        move_object(clone_object(MY_FILENAME),"/room/clearing");
    return;
}
