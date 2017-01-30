inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

int original_wc;
int att_rounds_count;

reset(arg)
{
    object radio, what;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Roy Batty");
    set_race("roy");
    set_alias("batty");
    set_short(HIW + "Roy Batty" + NORM + " (replicant)");
    set_long("Muscular yet subtly so, powerful yet reclusive, ordinary yet not...\n"+
        "Roy Batty is a Nexus 6 replicant, a construct built in the image of his\n"+
        "maker- Mankind. His piercing eyes mark you, and pick you apart without even\n"+
        "so much of a long stare. He is not out for trouble, but his intensity and\n"+
        "inner rage are unmistakable. He is on a mission, a personal quest that\n"+
        "he won't let anyone get in the way of. Be warned, traveler. This is not\n"+
        "someone you want to trifle with... especially if you are high-levelled.\n");
    set_level(20);
    set_al(-300);

    original_wc = 85;
    set_wc(original_wc);
    set_ac(60);
    set_heal(3,2);    
    
    radio = clone_object("players/mizan/mbv2/items/walkie-talkie.c");
    move_object(radio, this_object());

   
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 4650;
    hit_point = 4650;

    
    set_heal(3,2);    
    
    what = clone_object("players/mizan/mbv2/items/goggles.c");
    move_object(what, this_object());

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

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 95);
    set_attribute(ATTRIB_FEARLESSNESS, 95);
    set_attribute(ATTRIB_PERCEPTION, 75);
    set_attribute(ATTRIB_CRUELTY, 5);
    set_attribute(ATTRIB_INSANITY, 10);
    set_attribute(ATTRIB_GENEROUSITY, 80);

    set_monster_guild_level(4);
    set_monster_guild_rank("Black Knight");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "Archangels");

    set_chance_of(CHANCE_CORPSE_LOOTING, 75);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 50);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 5);
    set_chance_of(CHANCE_EMOTE_PANICKED, 4);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 4);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 3);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 5);
    set_chance_of(CHANCE_PELTING_THINGS, 5);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 70000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 18000);
	set_int(VAL_HUNTING_THRESHOLD, 10);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 5);
    
    
    /* lots of channel and emote stuff */
    attacked_emotes = ({
        HIW + "Roy Batty exclaims: Ha ha ha... Where are you going?\n" + NORM,
        HIW + "Roy Batty exclaims: Painful to live in fear, isn't it?\n" + NORM,
        HIW + "Roy Batty exclaims: That hurt.\n" + NORM,
        HIW + "Roy Batty exclaims: Come on! Show me what you're made of!\n" + NORM,
        HIW + "Roy Batty laughs loudly!\n" + NORM,
    });

	attacked_mchannels = ({
        "Ha ha ha... Where is he going?\n",
        "Painful for them to live in fear, isn't it?\n",
        "That hurt.\n",
        "Ha ha ha!\n",
        "Knight to bishop-queen six!\n",
    });


    panicked_emotes = ({
        HIW + "Roy Batty exclaims: Come on! Show me what you're made of!\n" + NORM,
    });

	panicked_mchannels = ({
		"Ahh!\n" + NORM,
	});

    
    hit_hard_emotes = ({
        HIW + "Roy Batty exclaims: I thought you were supposed to be good. Aren't you the 'good' man?\n" + NORM,
        HIW + "Roy Batty exclaims: Where are you going?\n" + NORM,
        HIW + "Roy Batty exclaims: That was irrational, not to mention... unsportsmanlike!\n" + NORM,
        HIW + "Roy Batty exclaims: That's the spirit!\n" + NORM,
        HIW + "Roy Batty exclaims: Shooting straight doesn't seem to be good enough!\n" + NORM,
    });

    hit_hard_mchannels = ({
        "That was irrational, not to mention... unsportsmanlike!\n",
        "That's the spirit!\n",
        "Shooting straight doesn't seem to be good enough!\n",
    });


    taunting_emotes = ({
        HIW + "Roy Batty exclaims: Quite an experience to live in fear, isn't it?\n" + NORM,
        HIW + "Roy Batty exclaims: That's what it feels like to be a slave.\n" + NORM,
        HIW + "Roy Batty exclaims: Fiery the angels fell. Deep thunder rolled about their shores... burning with the fires of Orc.\n" + NORM,
        HIW + "Roy Batty exclaims: You better get it up... or I'll have to kill ya!\n" + NORM,
        HIW + "Roy Batty exclaims: Six... Seven... Go to hell, or go to Heaven!\n" + NORM,
        HIW + "Roy Batty howls like a wolf!\n" + NORM,
        HIW + "Roy Batty exclaims: Ha ha. Where are you going?\n" + NORM,
        HIW + "Roy Batty laughs loudly.\n" + NORM,
    });

    taunting_mchannels = ({
        "Ha ha ha!\n",
        "Six.. Seven... Go to hell, or go to Heaven!\n",
        "Aoooooooooooooo!\n",
        "Quite an experience to live in fear, isn't it?\n",
        "That what it is, to be a slave.\n",
    });


    triumph_emotes = ({
        HIW + "Roy Batty howls like a mad wolf!\n" + NORM,
    });

    triumph_mchannels = ({
        "Ha ha ha!\n",
        "Heh!\n",
        "Ah, kinship!\n",
    });


    casual_emotes = ({
        HIW + "Roy Batty looks at you.\n" + NORM,
    });

    casual_mchannels = ({
        "Ahhh.\n",
    });


    scared_emotes = ({
        "Thorgrim Beano appears somewhat agitated.\n",
        "Thorgrim Beano appears somewhat nervous.\n",
        "Thorgrim Beano goes: hwarf.\n",
    });
    
    scared_mchannels = ({
        "I am somewhat nervous.\n",
        "Hmm.\n",
        "Damn!\n",
    });


    death_emotes = ({
        HIW + "Roy Batty crumples to the ground.\n" + NORM,
    });

    death_mchannels = ({
        "All those moments will be lost in time, like tears in rain. Time to die.\n",
    });


    shit_throw_emotes = ({
        HIW + "Roy Batty cackles maniacally!\n" + NORM,
    });
    
    shit_throw_mchannels = ({
        "Lumps of shit... quite amusing!\n",
    });

    
    balloon_throw_emotes = ({
        HIW + "Roy Batty cackles maniacally!\n" + NORM,
    });

    balloon_throw_mchannels = ({
        "Buckets of fun, this is!\n",
    });


    arrival_emotes =({
        HIW + "Roy Batty materializes into view.\nBehold.\n" + NORM,
    });

    arrival_mchannels =({
        "Did you get my precious photos.\n",
    });

}


heart_beat()
{
    object attacker;
    attacker = query_attack();

    if(attacker && attacker == query_obj(OBJ_TRAVEL_ATTACKER))
    {
        att_rounds_count ++;

        if(att_rounds_count > 10)
        {
            set_wc(query_wc() + 30);
            att_rounds_count = 0;
        }
    }
    else
    {
        set_wc(original_wc);
        att_rounds_count = 0;
    }

/*
    tell_object(find_player("mizan"), "WC: " + query_wc() + "\n");
*/
    ::heart_beat();
}

/* eof */