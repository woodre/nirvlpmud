inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

#define MY_FILENAME "/players/boltar/sprooms/xmas_turkey.c"
object beavis;

reset(arg)
{
    object weapon,leather_jacket;
    beavis = this_object();
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Christmas Turkey");
    set_race("human");
    set_alias("turkey");
    set_alt_name("christmas turkey");
    set_short("A Christmas Dinner Turkey (alive)");
    set_long("This is what they call FRESH FOOD.\n");

    set_level(2);
    set_gender("male");
    set_dead_ob(this_object());    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 80;
    hit_point = 80;
    set_al(0);
    set_wc(3);
    set_ac(0);
    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_off(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_USE_REMOTE_WAYPOINTS);
    toggle_off(MODE_CORPSE_EATER);
    toggle_off(MODE_SLOW_HITFADES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 5);
    set_attribute(ATTRIB_FEARLESSNESS, 5);
    set_attribute(ATTRIB_PERCEPTION, 40);
    set_attribute(ATTRIB_CRUELTY, 5);
    set_attribute(ATTRIB_INSANITY, 50);
    set_attribute(ATTRIB_GENEROUSITY, 10);

    set_monster_guild_level(1);
    set_monster_guild_rank("Chaotic");

    set_string(STR_TEAM_NAME, "ArmyOfBoltar");
    set_string(STR_CABAL_NAME, "XMAS");

    set_chance_of(CHANCE_CORPSE_LOOTING, 5);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 5);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 2);
    set_chance_of(CHANCE_EMOTE_PANICKED, 5);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 2);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 2);
    set_chance_of(CHANCE_EMOTE_CASUAL, 10);
    set_chance_of(CHANCE_EMOTE_SCARED, 5);
    set_chance_of(CHANCE_PELTING_THINGS, 1);    /* the chance that these monsters will throw things at players */
    set_int(VAL_INFUSE_POINT, 15000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 500);
	set_int(VAL_HUNTING_THRESHOLD, 100);        /* make him extra hard to get pissed off */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 25);     

    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Turkey goes: Gobble. Gobble.\n",
        "The Turkey fans it's wings.\n",
        "The Turkey pecks the ground.\n",
        "The Turkey buggs it's eyes out.\n",
        "The Turkey looks around.\n",
    });

	attacked_mchannels = ({
        "SCREAMS!\n",
        "Gobble Gobble\n",
	});


    panicked_emotes = ({
        "The Turkey screams!\n",
        "The Turkey appears flustered!\n",
    });

	panicked_mchannels = ({
        "FEATHERS! \n",
        "gobble GOBBLE!\n",
	});

    
    hit_hard_emotes = ({
        "The Turkey screams painfully!\n",
    });

    hit_hard_mchannels = ({
        "FEATHERS!\n",
    });


    taunting_emotes = ({
        "gobble gobble.\n",
    });

    taunting_mchannels = ({
        "GOBBLE GOBBLE\n",
    });


    triumph_emotes = ({
        "The Turkey flaps it's wings.\n",
    });

    triumph_mchannels = ({
        "Showin' the tail feathers.\n",
    });


    casual_emotes = ({
        "Turkey goes: Gobble. Gobble.\n",
        "The Turkey fans it's wings.\n",
        "The Turkey pecks the ground.\n",
        "The Turkey buggs it's eyes out.\n",
        "The Turkey looks around.\n",
    });

    casual_mchannels = ({
        "Turkey goes: Gobble. Gobble.\n",
        "The Turkey fans it's wings.\n",
        "The Turkey pecks the ground.\n",
        "The Turkey buggs it's eyes out.\n",
        "The Turkey looks around.\n",
    });


    scared_emotes = ({
        "The turkey appears somewhat flustered.\n",
    });
    
    scared_mchannels = ({
        "Flapps it's wings.\n",
    });


    death_emotes = ({
        "The Turkey falls dead. DINNER!\n",
    });

    death_mchannels = ({
        "I died... Dinner Time!\n",
    });


    shit_throw_emotes = ({
        "Doin' what a bird does.\n",
    });
    
    shit_throw_mchannels = ({
        "Doin' what a bird does.\n",
    });

    
    balloon_throw_emotes = ({
        "Gobble Gobble\n",
    });

    balloon_throw_mchannels = ({
        "Gobble Gobble\n",
    });


    arrival_emotes =({
        "The Turkey wanders in aimlessly.\n",
    });

    arrival_mchannels =({
        "Gobble Gobble!!\n",
    });
}

monster_died() {
    set_short("A Christmas Dinner Turkey (ready to cook)");
}  

calculate_worth() { return 80; }
/* eof */

