/*****************************************************************************
 *      File:                   powerpig.c
 *      Function:               Annoying heavy monster..
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

#define PIG_DM          "/players/mizan/opl/daemons/pigDM.c"
#define STATS_DM        "/players/mizan/opl/daemons/statsDM.c"

#include "/obj/ansi.h"

string monster_name;


reset(arg)
{
    object coins, what2, what3;
    ::reset(arg);
    if (arg) return;

    /* standard game lib stuff */
    monster_name = PIG_DM->get_name(); 

    set_name(lower_case(monster_name));
    set_race("pig");
    set_alias("powerpig");

    set_short(monster_name + ", the " + HIW + "Power Pig" + NORM);
    set_long(
    "    A terribly disfigured freakshow of science raping nature stands before you.\n"+
    "  These powerpigs are the result of genetic engineering gone wrong. Originally built\n"+
    "  to some nameless specification as villains for a computer game involving some bird\n"+
    "  projectiles, these versions were cast off the project on the virtue of being far too\n"+
    "  effective at their job of henching and villainy. Hence, they are employed here under\n"+
    "  the steady hand of the OverPowerLord. They are here to menace you instead.\n");

    coins = clone_object("/obj/money.c");
    coins->set_money(STATS_DM->get_gold_hard());
    move_object(coins, this_object());

    set_level(STATS_DM->get_level_hard());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_hard();
    hit_point = max_hp;

    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(15, 1);

    set_al(-550);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());

    set_chance(15);
    set_spell_dam(200);
    set_spell_mess1(query_name() + " hits you with a hangover-inducing, skull-shattering crunch.\n");
    set_spell_mess2(query_name() + " hits you with a bitchingly butthurt bonecrushing blow.\n");


    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);

    load_chat(monster_name + " grunts loudly.\n");
    load_chat(monster_name + " says: Don't mention that goddamn video game ever. I hate it.\n");
    load_chat(monster_name + " says: I don't get paid well. But at least the OverPowerLord honors his contracts.\n");
    load_chat(monster_name + " growls and whines loudly.\n");


    set_heal(50,2);

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

    if(1 == random(3)) toggle_on(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    else toggle_off(MODE_CALLS_FOR_BACKUP);

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
    set_attribute(ATTRIB_VINDICTIVENESS, 100);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 30);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 50);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 70);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 2);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 1);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(3);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Law Enforcement");              /* This is almost archaic. i dont know what i am going to do with it. */

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
    set_string(STR_CABAL_NAME, "Powerpigs");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


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

    set_int(VAL_INFUSE_POINT, 100000);              /* the amount of coins where the monster infuses back to nexus */
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
        monster_name + " says: Oh lookie over here, Mister Short Dick wants to fight.\n",
        monster_name + " says: So cute, penis sauce over here is trying to fight ME.\n",

    });

    attacked_mchannels = ( {
        "These dipshits have the balls to attack... ME?!\n",
        "What the shit is up with these stupid humans?\n",
    });


    panicked_emotes = ( {
        monster_name + " appears to be distraught.\n",
    });

    panicked_mchannels = ( {
        "AAAGH!\n",
    });


    hit_hard_emotes = ( {
        monster_name + " says: Hey butthurt, is that all you got!?\n",
        monster_name + " says: Come on, shitface, you can hit harder than that!\n",
        monster_name + " says: Someday soon your mommy can stop wiping your ass for you right!?\n",
        monster_name + " says: Yeah, that's right. Bring it.\n",
        monster_name + " says: You hit like a little chicken.\n",
        monster_name + " says: You hit like one of those stupid little angry birds.\n",
        monster_name + " says: COME ON... Are you for real?! That shit didn't hurt!\n",
    });

    hit_hard_mchannels = ( {
        "OW! That hurt!\n",
        "These humans are getting better or something...\n",
    });


    taunting_emotes = ( {
        monster_name + " says: Yeah. Suck it down, you stupid humans.\n",
    });

    taunting_mchannels = ( {
        "Hey yeah... Suck it down!\n",
    });


    triumph_emotes = ( {
        monster_name + " defecates at your general direction!\n",
    });

    triumph_mchannels = ( {
        "YEAH MOTHERFUCKERS.\n",
    });


    casual_emotes = ( {
        monster_name + " picks his nose.\n",
        monster_name + " says: Hey asshole.\n",
        monster_name + " says: Yeah, I'm talking to you... asshole.\n",
        monster_name + " says: AAAAAASSSHOOOOLE.\n",
        monster_name + " says: Asshole. You.\n",
        monster_name + " says: Tonight... You.\n",
    });

    casual_mchannels = ( {
        "BORED...\n",
    });


    scared_emotes = ( {
        monster_name + " squeals loudly!\n",
    });

    scared_mchannels = ( {
        "I am very scared.\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ( {
        monster_name + " crumples to the ground, dead!\n",
    });

    death_mchannels = ( {
        "AAAARGH!!!\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ( {
        monster_name + " laughs at you!\n",
    });

    shit_throw_mchannels = ( {
        "I'm throwing shit! I usually only TALK shit! HEHEHE.\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ( {
        monster_name + " says: THAT'S FUNNY!!!\n",
    });

    balloon_throw_mchannels = ( {
        "These stupid water balloons are hilarious...\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =( {
        "A Powerpig suddenly materializes before you!\n",
    });

    arrival_mchannels =( {
        "AAAAAAAAAAAAAAAGH! I'm in the house! OH YEAH!\n",
    });

}

heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(5)) mamasnap();
}

mamasnap()
{
    string result;
    result = query_name() + " says: " + HIC + "/players/mizan/opl/daemons/mamasnapsDM.c"->query_snap() + NORM + "\n";
    say(result);
}

/* eof */
