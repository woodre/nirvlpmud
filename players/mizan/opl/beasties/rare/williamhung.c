inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"

#define STATS_DM       "/players/mizan/opl/daemons/statsDM.c"

reset(arg)
{
    object what, what2, gold;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("William Hung");
    set_race("human");
    set_alias("william");
    set_short("William Hung");
    set_long("This a strange little Asian man. He is wearing a gaudy semi-tropical \n" +
    "shirt that makes your eyeballs visibly cringe from shock. He is amazingly\n" +
    "goofy yet in a somewhat endearing sort of manner. His 'singing' voice can\n"+
	"curdle cheese and his permanently cross-eyed expression of confusion makes you\n"+
	"want to leave the immediate area before being tagged with his infectious\n" +
    "strangeness. Folks, this is someone even more annoying than the legendary\n"+
	"village bastard- Harry the Affectionate.\n");

    set_level(12);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 180;
    hit_point = 180;

    set_al(-550);
    set_wc(15);
    set_ac(7);
    set_chance(1);

    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 0;
    
    load_chat("William Hung picks his nose.\n");
    load_chat("William Hung adjusts his pants.\n");
    load_chat("William Hung adjusts his shirt.\n");
    load_chat("William Hung appears to be confused.\n");
    load_chat("William Hung looks at you, cross-eyed.\n");

    /* our rate of healing... 3 hp, every 2 hb */
    set_heal(10, 1);
    
    gold = clone_object("obj/money");
    gold->set_money(1000);
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
    toggle_on(MODE_BALLOON_THROWER);       /* if the monster throws balloons at people */
    toggle_on(MODE_SHIT_THROWER);          /* If the monster throws shit at people */
    toggle_off(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    toggle_off(MODE_KID_KILLER);           /* if the monster will attack kids spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PET_KILLER);           /* if the monster will attack pets spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PK_INSTIGATOR);        /* if the monster will attack PK players spontaneously, but honors no-fight rooms. */
    toggle_off(MODE_USE_REMOTE_WAYPOINTS); /* Enable this if you want the monster be hermitlike,
                                              and not wander in the main village spine. It instead
                                              stays in the perimeter (like south forest) rooms as waypoints. */
    toggle_on(MODE_CORPSE_EATER);         /* If the monster consumes corpses whole instead of just 
                                              taking them (emotes taken from Boltar's hoth monster.
                                              Used in conjunction with its chance of consuming corpses. */
    toggle_off(MODE_SLOW_HITFADES);        /* If the monster sticks around for a longer period
                                              while running hit/fade attacks. Typically monsters only
                                              try to get 3/6 attacks in. This extends to about 15/20. */

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 10);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 10);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 10);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 1);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 70);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 80);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(1);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Jester");              /* This is almost archaic. i dont know what i am going to do with it. */

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
    set_string(STR_CABAL_NAME, "Juniors");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


                                                 /* These are all set to a per 100 round setting. If a chance is '1', it means that
 * the event will have the odds of 1 in 100 rounds of happening. Same as the core monster
 * chat capabilites in monster.c
 *
 */
    set_chance_of(CHANCE_CORPSE_LOOTING, 55);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 75);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 40);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 50);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 7);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 6);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 50);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 30);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 1000);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 400);             /* The amount of maximum heals the monster can draw from the nexus */
	set_int(VAL_HUNTING_THRESHOLD, 4);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 6);       /* How many callouts before the monster decides to move randomly */

    /* lots of channel and emote stuff */

/* these should be self-explanatory... a variety of emotes when the monster is
 * under certain emotional conditions. */
/* The arrays can be any size and do not have to be equal sized in pairs. For example
 * the _emotes array might have 5 elements, but does not mean that _mchannels needs 5 too.
 * but should have one member if you want to see the emotes, otherwise, nothing is said. */

    attacked_emotes = ({
        "William Hung screams wildly!\n",
        "William Hung cries: What is wrong! What is wrong!\n",
        "William Hung cries: That is not nice and personable!\n",
        "William Hung screams: I am just trying to make people happy!\n",
        "William Hung screams: Why are you attacking me?!\n",
        "William Hung gasps loudly!\n",
        "William Hung cries: What did I ever do to you!\n",
        "William Hung cries: I will stop singing if you stop hitting me!\n",
    });

	attacked_mchannels = ({
		"I am under attack and very scared! This is not part of my career!\n",
        "I do not like being attacked! This is not fun!\n",
        "Why am I being attacked? I just want to spread happy!\n",
		"Ouch! I am being attacked painfully!\n",
	});


    panicked_emotes = ({
        "William Hung screams loudly!\n",
        "William Hung panics!\n",
        "William Hung leaps up in sheer terror!\n",
        "William Hung winces pitifully!\n",
    });

	panicked_mchannels = ({
		"Ay yah! What is going on?!\n",
		"AAAGH!\n",
		"This is not fun, i am trying to make the best of it but this is not fun!\n",
	});

    
    hit_hard_emotes = ({
        "William Hung screams in sheer terror!\n",
        "William Hung crumples painfully from the hit!\n",
        "William Hung winces and screams piteously!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! OW! That hurt!\n",
        "I was just struck painfully!\n",
        "ACK! Ow!\n",
		"That hurt severely!\n",
    });


    taunting_emotes = ({
        "William Hung sings: 'SHE BANGS! SHE BANGS!'\n",
        "William Hung sings: 'SHE MOVES! SHE MOVES!'\n",
        "William Hung sings: 'OOOOH BABY! BaaaaaAAAYYYBE!!'\n",
    });

    taunting_mchannels = ({
        "'SHE BANGS! SHE BANGS!'\n",
        "'SHE MOVES! SHE MOVES!'\n",
    });


    triumph_emotes = ({
        "William Hung exclaims: Thank you! You are the best audience ever!\n",
        "William Hung beams happily!\n",
    });

    triumph_mchannels = ({
        "She bangs! She bangs!\n",
        "Ooooh ah baby, pimping isnt easy! She bangs!\n",
    });


    casual_emotes = ({
        "William Hung smiles happily.\n",
        "William Hung sings: She bangs! She bangs!\n",
        "William Hung sings: She moves! She moves!\n",
        "William Hung cries: Thank you everyone!\n",
        "William Hung sings: Hey baby! Hey baby light my fi-yer!\n",
        "William Hung sings: Pretty baby, sexy baby, smiling at me!\n",
        "William Hung sings: SHE BANGS!!\n",
        "William Hung says: I have not had any formal musical training!\n",
        "William Hung says: But i am giving it my best! SHE BANGS!!\n",
    });

    casual_mchannels = ({
        "I really like to sing!\n",
        "Karaoke show down monster fight!\n",
        "I have not had any formal musicial training.\n",
    });


    scared_emotes = ({
        "William Hung appears very nervous.\n",
        "William Hung sweats nervously.\n",
        "William Hung blinks.\n",
    });
    
    scared_mchannels = ({
        "I am very scared.\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ({
        "William Hung crumples to the ground, rejected.\n",
    });

    death_mchannels = ({
        "I gave it my best, I gave it my all...\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ({
        "William Hung grins biggly!\n",
    });
    
    shit_throw_mchannels = ({
		"This is fun! But is it illegal?\n",
		"I love throwing feces!\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ({
        "William Hung giggles inanely.\n",
        "William Hung whistles innocently.\n",
    });

    balloon_throw_mchannels = ({
        "Hee.\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =({
        "Holy shit! William Hung materializes before you.\n",
        "William Hung materializes into the pitch.\n",
    });

    arrival_mchannels =({
        "Music is my hobby and good times!\n",
        "Who wants to sing?!\n",
    });

}

/* inside this function you can call your code to do special combat.
 * It is called when an attacker is present, and engaged in combat.
 * Have fun :)
 */
heartbeat_attack()
{
    /* beanos are boring in combat, so they don't do anything. */
}

/* eof */
