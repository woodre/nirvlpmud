inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object what, heals, radio;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Domo-kun");
    set_race("domo-kun");
    set_alias("domo");
    set_alt_name("domokun");
    set_short(HIW + "Domo-Kun" + NORM + " (crusader)");
    set_long("You express both fear and helpless joy at the sight of Domo-kun.\n"+
        "Fully grown, he is about eight feet tall and basically is a gigantic\n"+
        "block of a short-haired, furry brown monster. His mouth seems permanently\n"+
        "agape, exposing gigantic white teeth. His simple black eyes have an almost\n"+
        "expressionless but attentive gloss to them. His demeanor is that of a\n"+
        "wookie melded with that of a twelve year old child. Don't piss him off.\n"+
        "Despite his fraidy-cat personality when young, he is absolutely ruthless\n"+
        "and overzealous in protecting his friends and fellow guild members.\n");

    set_heal(85, 3);

    set_level(19);
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 8850;
    hit_point = 8850;

    set_al(800);
    set_wc(170);
    set_ac(65);
    
    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    radio = clone_object("players/mizan/mbv3/items/pda.c");
    move_object(radio, this_object());

    heals = clone_object("players/mizan/etheriel/items/backpack");
    move_object(heals, this_object());    
    
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
    set_attribute(ATTRIB_FEARLESSNESS, 90);
    set_attribute(ATTRIB_PERCEPTION, 20);
    set_attribute(ATTRIB_CRUELTY, 10);
    set_attribute(ATTRIB_INSANITY, 2);
    set_attribute(ATTRIB_GENEROUSITY, 90);

    set_monster_guild_level(3);
    set_monster_guild_rank("White Rook");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 5);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 10);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 6);
    set_chance_of(CHANCE_EMOTE_PANICKED, 6);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 6);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 50);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 4);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 50000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 10000);
	set_int(VAL_HUNTING_THRESHOLD, 30);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);
    
    
    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Domo-Kun goes: URAAAAAAAAAGH!!\n",
        "Domo-Kun goes: RAAAAAR!!\n",
        "Domo-Kun is really, really, really fucking angry, dude.\n",
        "Domo-Kun goes: MMMMMRAAAAAAGH!\n",
        "Domo-Kun goes: RAAR!!\n",
    });

	attacked_mchannels = ({
		"RAAAR!\n",
        "RooooaaAAAAAR!\n",
        "ROOR!\n",
	});


    panicked_emotes = ({
        "Domo-Kun appears startled!\n",
        "Domo-Kun goes: MMuh?!!\n",
    });

	panicked_mchannels = ({
		"Urrrrrr!\n",
		"MUH!!\n",
	});

    
    hit_hard_emotes = ({
        "Domo-Kun appears somewhat winded...\n",
        "Domo-Kun wobbles (very, very, very slightly).\n",
    });

    hit_hard_mchannels = ({
        "rrrrrrar!\n",
        "rurgh!\n",
    });


    taunting_emotes = ({
        "Domo-Kun stands RIGHT IN FRONT of you. Annoying! Scary! Smelly...\n",
        "Domo-Kun eyes you threateningly.\n",
        "Domo-Kun stares at you intently, teeth fully exposed.\n",
    });

    taunting_mchannels = ({
        "BLAAARGH!\n",
        "BRAAAAAGH!\n",
    });


    triumph_emotes = ({
        "Domo-Kun appears to be grinning.\n",
    });

    triumph_mchannels = ({
        "CRAAAAAAAAAAAAAAAAGH!\n",
        "RAAAAAAAAAAAAAAAAARRH!\n",
    });


    casual_emotes = ({
        "Domo-Kun blinks.\n",
        "A droplet of saliva runs off one of Domo-Kun's exposed teeth and splashes to the ground.\n",
    });

    casual_mchannels = ({
        "Raar.\n",
        "Mrraaaargh.\n",
        "Mraaah.\n",
    });


    scared_emotes = ({
        "Domo-Kun appears somewhat flustered.\n",
    });
    
    scared_mchannels = ({
        "...\n",
    });


    death_emotes = ({
        "Domo-Kun crumples to the ground.\n",
    });

    death_mchannels = ({
        "GRRR.\n",
    });


    shit_throw_emotes = ({
        "Domo-Kun jumps excited and crashes the ground with a earth-shattering THUMP...\n",
    });
    
    shit_throw_mchannels = ({
        "SHRRRRRRAAAAAAGH!\n",
    });

    
    balloon_throw_emotes = ({
        "Domo-Kun blinks loudly.\n",
    });

    balloon_throw_mchannels = ({
        "WERRAAAAAAAGH! BREAAAAAGH!\n",
    });


    arrival_emotes =({
        "Domo-Kun climbs out of a hole in the ground.\n",
    });

    arrival_mchannels =({
        "RAAR! (I'm here!)\n",
    });

}

/* Domokun is unoriginal in his attacks. He has limited skills but
 * incredible amounts of strength and bravery in the face of danger.
 * The canon video footage of him (the TV commercials) depict him
 * as a young monster fraidy-cat but in this case things are different.
 * When defending his friends he becomes an unstoppable force of rage
 * and retribution.
 */


/* eof */
