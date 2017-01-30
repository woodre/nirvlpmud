/*****************************************************************************
 *      File:                   phantom_shitter.c
 *      Function:               He's a phantom... and he shits!
 *                              Everything they say is in all capitals
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:    
 *      Change History:         
 ****************************************************************************/

inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"

#define STATS_DM       "/players/mizan/opl/daemons/statsDM.c"

reset(arg)
{
    object ring, chaps, gold;
    ::reset(arg);
    if (arg) return;


    /* standard game lib stuff */
    set_name("Phantom Shitter");
    set_race("human");
    set_alias("shitter");
    set_alt_name("phantom");
    set_short(HIW + "The Phantom Shitter" + NORM);
    set_long("    Cloaked in a mysterious brown cloud of mystery, the Phantom Shitter\n"+
             "  has control of the mystical art of prompted defecation. He wields a\n"+
             "  uncanny mastery of the ability to poop on demand, adjusting the texture\n"+
             "  and consistency of his primary weapon on the fly. Be very careful of\n"+
             "  this supremely dangerous individual.\n");


    if (!ring) ring = move_object(clone_object("/players/mizan/opl/beasties/rare/phantom_shitter/ring.c"), this_object());
    if (!chaps) chaps = move_object(clone_object("/players/mizan/opl/beasties/rare/phantom_shitter/chaps.c"), this_object());

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());

    set_level(STATS_DM->get_level_medum());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_medium();
    hit_point = max_hp;

    set_al(-599);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);

    load_chat(short() + " picks his nose.\n");
    load_chat(short() + " prances about the area happily.\n");
    load_chat(short() + " flutters his eyelashes at you.\n");
    load_chat(short() + " cries: Oh JOY!!!\n");
    load_chat(short() + " I LIKE POOP!\n");

    set_hp_bonus(STATS_DM->get_hp_bonus_medium());
    set_heal(17, 1);

/*
    what2 = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(what2, this_object());
 */
 
    /* This is needed (a hack) to tell the monsterplus code that we are
     * properly initalized, able to roam and operate. Mandatory. Don't remove. */
    is_loaded = 1;

    /*
     * These are on-off toggle switches. You may toggle them on/off at any time after
     * the monster is cloned. All behavior is dynamic. Have fun :)
     *
     */

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);                 /* This should be left on. The monster spams the channels
                                              less this way. NOTE that in the future, severity levels will be
                                              available. */

    toggle_off(MODE_SPARING_NEWBIES);      /* If enabled, the monster does not harrass L5 and under players directly */
    toggle_off(MODE_BALLOON_THROWER);       /* if the monster throws balloons at people */
    toggle_on(MODE_SHIT_THROWER);          /* If the monster throws shit at people */
    toggle_off(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    toggle_on(MODE_KID_KILLER);           /* if the monster will attack kids spontaneously but honors no-fight rooms.*/
    toggle_on(MODE_PET_KILLER);           /* if the monster will attack pets spontaneously but honors no-fight rooms.*/
    toggle_on(MODE_PK_INSTIGATOR);        /* if the monster will attack PK players spontaneously, but honors no-fight rooms. */
    toggle_off(MODE_USE_REMOTE_WAYPOINTS); /* Enable this if you want the monster be hermitlike,
                                              and not wander in the main village spine. It instead
                                              stays in the perimeter (like south forest) rooms as waypoints. */
    toggle_on(MODE_CORPSE_EATER);         /* If the monster consumes corpses whole instead of just
                                              taking them (emotes taken from Boltar's hoth monster.
                                              Used in conjunction with its chance of consuming corpses. */
    toggle_on(MODE_SLOW_HITFADES);        /* If the monster sticks around for a longer period
                                              while running hit/fade attacks. Typically monsters only
                                              try to get 3/6 attacks in. This extends to about 15/20. */

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 60);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 20);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 80);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 50);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 75);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 1);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(3);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Oddball");              /* This is almost archaic. i dont know what i am going to do with it. */

    /* some notes along the way...
     *
     * Monsters that have a guild level 1 will not automatically heal. They need to be L2 to do that.
     *
     * The monster guild rank is archaic in a way, but i will keep it for now.
     * Most likely it will be the only attribute the players will see in respect to ranking.
     *
     *
     *
     */

    set_string(STR_TEAM_NAME, "MonstersInc");    /* The name of the team the monster is on. Team names take more precedence */
    set_string(STR_CABAL_NAME, "Pooper");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


    /* These are all set to a per 100 round setting. If a chance is '1', it means that
    * the event will have the odds of 1 in 100 rounds of happening. Same as the core monster
    * chat capabilites in monster.c
    *
    */
    set_chance_of(CHANCE_CORPSE_LOOTING, 100);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 55);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 30);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 30);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 20);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 50);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 99);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 100000);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 6412);             /* The amount of maximum heals the monster can draw from the nexus */
    set_int(VAL_HUNTING_THRESHOLD, 10);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 10);       /* How many callouts before the monster decides to move randomly */

    /* lots of channel and emote stuff */

    /* these should be self-explanatory... a variety of emotes when the monster is
     * under certain emotional conditions. */
    /* The arrays can be any size and do not have to be equal sized in pairs. For example
     * the _emotes array might have 5 elements, but does not mean that _mchannels needs 5 too.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */

    attacked_emotes = ( {
        short() + " cries: I LOOOOOVE POOP!!!\n",
        short() + " says: You need to have a fecaltacular day!\n",
        short() + " mumbles about something or another not being poopy enough.\n",
    });

    attacked_mchannels = ( {
        "Hey... someone is attacking me!\n",
        "Wow, this guy has no sense of humor...\n",
        "Something about poop seems to drive some people BATTY!\n",
    });


    panicked_emotes = ( {
        short() + " squeals in delight.\n",
        short() + " wiggles his butt.\n",
        short() + " prances about excitedly!\n",
    });

    panicked_mchannels = ( {
        "Well! Well! Well!\n",
        "What was THAT all about?\n",
    });


    hit_hard_emotes = ( {
        short() + " catcalls and whistles at you: 'HARDER!'\n",
        short() + " moans at you.\n",
        short() + " says: OH YES! HARDER! HARDER!\n",
    });

    hit_hard_mchannels = ( {
        "OW! Right in the tender parts!\n",
        "My... that hurt somewhat. Kinky!\n",
    });


    taunting_emotes = ( {
        short() + " says: You know you want to tap this ass!\n",
        short() + " says: Ass wiggle! Ass wiggle! Sexy pose! Strut! Strut... Shake it!\n",
        short() + " says: Two snaps... UP!\n",
        short() + " shakes his booty through those assless chaps.\n",
    });

    taunting_mchannels = ( {
        "Ass wiggle! Ass wiggle! Sexy pose! Strut! Strut... Shake it!\n",
    });


    triumph_emotes = ( {
        short() + " says: OH YES BABY!\n",
        short() + " says: Now THAT's how you work it, baby!\n",
    });

    triumph_mchannels = ( {
        "How sweet it is, sugar!\n",
    });


    casual_emotes = ( {
        short() + " grins lustily at you.\n",
        short() + " adjusts his asscheeks. Carefully.\n",
    });

    casual_mchannels = ( {
        "Hey guys...\n",
        "HEY SEXY GUYS!\n",
    });


    scared_emotes = ( {
        short() + " soils himself.\n",
    });

    scared_mchannels = ( {
        "I am very scared.\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ( {
        short() + " crumples to the ground. Some poop evacuates itself from his... butt.\n",
    });

    death_mchannels = ( {
        "I'll be BACK!!!!\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ( {
        short() + " laughs at you!\n",
        short() + " says: POOP TIME!\n",
    });

    shit_throw_mchannels = ( {
        "Hahahaha... Poop tossing time!\n",
        "I'm releasing the chocolate hostages!\n",
        "I'm eliminating some evidence!\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ( {
        short() + " says: THAT'S FUNNY!!!\n",
    });

    balloon_throw_mchannels = ( {
        "If I could only figure out how to load these balloons with poop...\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =( {
        "Behold. The Phantom Shitter emerges from the sewers.\n",
        "Powersliding down White Rock Canyon, the Phantom Shitter emerges.\n",
    });

    arrival_mchannels =( {
        "Poopity poop poop POOP!\n",
	"Oh yeah... it's POOPY TIME!\n",
    });

}


heart_beat()
{
    ::heart_beat();
    if(1 == random(20)) make_shit();
}


make_shit()
{
    object shit;
    if(query_obj(OBJ_SHITPILE)) return;

    shit = clone_object("/players/mizan/etheriel/items/shit.c");
    move_object(shit, this_object());
    say(short() + " makes like a chocolate frozen yogurt machine\nand receives a warm, sticky prize.\n");
    set_obj(OBJ_SHITPILE, shit);
}


/* inside this function you can call your code to do special combat.
 * It is called when an attacker is present, and engaged in combat.
 * Have fun :)
 */
heartbeat_attack()
{
    if (attacker_ob) singing_fecaltacular();
}


singing_fecaltacular()
{
    string result;
    result = short() + " sings: " + "/players/mizan/opl/daemons/randobjDM"->sing_phantom_shitter_song();
    say(result + NORM + "\n");
}


/* eof */
