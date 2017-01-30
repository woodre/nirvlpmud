/*****************************************************************************
 *      File:                   ogre.c
 *      Function:               Heavy monster.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                  DONE.
 *      Change History:         
 *
 */
inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"

#define OGRE_DM          "/players/mizan/opl/daemons/ogreDM.c"
#define STATS_DM        "/players/mizan/opl/daemons/statsDM.c"

#include "/obj/ansi.h"

string monster_name;

reset(arg)
{
    object gold;
    ::reset(arg);
    if (arg) return;

    /* standard game lib stuff */
    monster_name = OGRE_DM->get_name();

    set_name(lower_case(monster_name));
    set_race("ogre");

    set_short(monster_name + " the " +  HIW + "Cave Ogre" + NORM);
    set_long("    Aside from the terrifying, imposing figure before you, what really\n"+
    "  grabs your attention about this gigantic, 25 foot tall ogre are his urbane\n"+
    "  attire and the smell of French cologne masking an ominous odor of blood\n"+
    "  and gut stench.\n");

    set_level(STATS_DM->get_level_hard());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_hard();
    hit_point = max_hp;

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(19, 1);


    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_al(860);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(450);

    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);

    load_chat(monster_name + " says: Excuse me sir, but this is not an area you are permitted in.\n");
    load_chat(monster_name + " says: Passage interdit, monsieur! \n");
    load_chat(monster_name + " says: Acces interdit! A toute personne estrangere au service...\n");
    load_chat(monster_name + " says: No entry in this passageway, please.\n");
    load_chat(monster_name + " says: This area is closed.\n");


    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
    move_object(gold,this_object());


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
    toggle_off(MODE_SHIT_THROWER);          /* If the monster throws shit at people */
    toggle_on(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    toggle_on(MODE_KID_KILLER);           /* if the monster will attack kids spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PET_KILLER);           /* if the monster will attack pets spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PK_INSTIGATOR);        /* if the monster will attack PK players spontaneously, but honors no-fight rooms. */
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
    set_attribute(ATTRIB_VINDICTIVENESS, 100);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 80);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 80);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 10);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 1);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 50);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(3);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Access Control");              /* This is almost archaic. i dont know what i am going to do with it. */

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

    set_string(STR_TEAM_NAME, "Security");    /* The name of the team the monster is on. Team names take more precedence */
    set_string(STR_CABAL_NAME, "Ogres");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


    /* These are all set to a per 100 round setting. If a chance is '1', it means that
    * the event will have the odds of 1 in 100 rounds of happening. Same as the core monster
    * chat capabilites in monster.c
    *
    */
    set_chance_of(CHANCE_CORPSE_LOOTING, 3);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 20);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 30);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 30);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 20);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 50);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 1);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 10000);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 2000);             /* The amount of maximum heals the monster can draw from the nexus */
    set_int(VAL_HUNTING_THRESHOLD, 10);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 4);       /* How many callouts before the monster decides to move randomly */

    /* lots of channel and emote stuff */

    /* these should be self-explanatory... a variety of emotes when the monster is
     * under certain emotional conditions. */
    /* The arrays can be any size and do not have to be equal sized in pairs. For example
     * the _emotes array might have 5 elements, but does not mean that _mchannels needs 5 too.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */

    attacked_emotes = ( {
        query_name() + " says: Monsieur, this is not the right way to handle the situation.\n",
        query_name() + " says: Monsieur, you are not supposed to attack the maze staff.\n",
    });

    attacked_mchannels = ( {
        "I'm being attacked by some player here. Situation is under control.\n",
        "There's a part of me which wants to run away, but that would not be sporting.\n",
    });


    panicked_emotes = ( {
        monster_name + " seems to be visibly upset.\n",
        monster_name + " winces from what appears to be mental anguish.\n",
        monster_name + " sighs deeply.\n",
    });

    panicked_mchannels = ( {
        "AAAGH! Was not expecting that...\n",
        "Very disconcerting.\n",
    });


    hit_hard_emotes = ( {
        monster_name + " snarls angrily.\n",
        monster_name + " growls at you.\n",
        monster_name + " winces from what appears to be pain.\n",
        monster_name + " scowls angrily.\n",
    });

    hit_hard_mchannels = ( {
        "OW! OW! OW! That hurt!\n",
        "Ouch. These guys hit hard.\n",
    });


    taunting_emotes = ( {
        monster_name + " smirks.\n",
        monster_name + " gloats knowingly.\n",
    });

    taunting_mchannels = ( {
        "Hah.\n",
        "Hee. Hee.\n",
    });


    triumph_emotes = ( {
        monster_name + " pumps a fist in the air in triumph!\n",
        monster_name + " cheers menacingly.\n",
    });

    triumph_mchannels = ( {
        "Hah HAH! Excellent.\n",
    });


    casual_emotes = ( {
        monster_name + " subtlely tips his chin at you.\n",
        monster_name + " says: Bonjour, monsieur.\n",
    });

    casual_mchannels = ( {
        "Situation all normal here.\n",
        "Nothing to report. Condition is normal.\n",
        "I'm completing my tour. All is well.\n",
    });


    scared_emotes = ( {
        monster_name + " frowns.\n",
    });

    scared_mchannels = ( {
        "Something is not right.\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ( {
        monster_name + " is defeated!\n",
    });

    death_mchannels = ( {
        "Damn. I clocked out.\n",
        "Ack. I tapped out.\n",
        "Drats. The player got me.\n",
        "Sorry guys... I let you down. I have tapped.\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ( {
        monster_name + " laughs at you!\n",
    });

    shit_throw_mchannels = ( {
        "Throwing shit is surprisingly... fun!\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ( {
        monster_name + " says: This... is very entertaining.\n",
    });

    balloon_throw_mchannels = ( {
        "Water balloons. Too funny...\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =( {
        query_name() + " fades into view.\n",
        query_name() + " clambers out of the shadows.\n",
    });

    arrival_mchannels =( {
        monster_name + " reporting for duty.\n",
    });

}


/* eof */
