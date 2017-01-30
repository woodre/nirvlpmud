inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object what, liquor;
    string my_displayname;
    ::reset(arg);
    if(arg) return;

    my_displayname = BBLK + BLINK + BOLD + HIW + "Animated Plastic Light-Up Santa" + NORM + NORM;

    /* standard game lib stuff */
    set_name("Animated Plastic Light-Up Santa");
    set_race("Santa Claus");
    set_alias("santa");
    set_short(my_displayname);
    set_long("This is a living (surprise!) light-up plastic Santa Claus. \n" +
             "He looks surprisingly real, and very disturbing walking around\n" +
             "on his own. You notice however he absolutely reeks of alcohol.\n");

    set_level(19);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 266;
    hit_point = 266;

    set_al(240);
    set_wc(40);
    set_ac(14);
    
    set_heal(3,2);    
    
    what = clone_object("players/mizan/etheriel/items/motorcycle-battery.c");
    move_object(what, this_object());

    liquor = clone_object("players/mizan/etheriel/heals/cheap-liquor.c");
    move_object(liquor, this_object());

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_on(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_FIREWORKS_THROWER);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 90);
    set_attribute(ATTRIB_FEARLESSNESS, 30);
    set_attribute(ATTRIB_PERCEPTION, 20);
    set_attribute(ATTRIB_CRUELTY, 55);
    set_attribute(ATTRIB_INSANITY, 80);
    set_attribute(ATTRIB_GENEROUSITY, 0);

    set_monster_guild_level(2);
    set_monster_guild_rank("White Pawn");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 75);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 50);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 10);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 10);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 50);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 30000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 3300);
	set_int(VAL_HUNTING_THRESHOLD, 12);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 5);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        my_displayname + " says: Dammit, you've been a naughty fucker!\n",
        my_displayname + " says: Ho Ho Ho. F' You.\n",
        my_displayname + " says: You've been a naughty little sonuvabitch.\n",
        my_displayname + " says: You're not getting anything this year, asshole.\n",
    });

	attacked_mchannels = ({
		"I am being attacked goddamn it.\n",
        "I'm being attacked for no good reason goddamn it!\n",
        "Holy mother of liquid shit I am being attacked.\n",
	});


    panicked_emotes = ({
        my_displayname + " says: Goddamn it!\n",
        my_displayname + " says: Suck! Buh!\n",
        my_displayname + " says: Oh Jesus goddamnit.\n",
    });

	panicked_mchannels = ({
		"Oh Holy Jesus Crap!\n",
        "That is so not fucking cool.\n",
        "Goddamn it what am I doing here.\n",
	});

    
    hit_hard_emotes = ({
        my_displayname + "Beano screams wildly!\n",
        my_displayname + "Beano cowers in pain!\n",
        my_displayname + "Beano squits against the ground in pain!\n",
    });

    hit_hard_mchannels = ({
        "Holy molten shit on a stick that hurt!\n",
        "Goddamn that really hurt!\n",
        "Shit! Ease off motherfucker!\n",
    });


    taunting_emotes = ({
        my_displayname + " says: Ho Ho Ho.   You're a cocksucker.\n",
        my_displayname + " says: Ho Ho Ho.   Blow me.\n",
        my_displayname + " says: Ho Ho Ho.   Lick my sack.\n",
        my_displayname + " says: Ho Ho Ho.   You're a cocksucker.\n",
        my_displayname + " says: Ho Ho Ho.   You're a shitface.\n",
        my_displayname + " says: Ho Ho Ho.   Bite me.\n",
        my_displayname + " says: Ho Ho Ho.   Go suck off a goat.\n",
        my_displayname + " says: Ho Ho Ho.   Suck my ass.\n",
    });

    taunting_mchannels = ({
        "Heh. I like taunting people.\n",
        "Yo I need another fucking bottle of scotch!\n",
    });


    triumph_emotes = ({
        my_displayname + " says: Ho Ho Ho.   You SUCK!\n",
        my_displayname + " says: Ho Ho Ho.   BUSTED!\n",
        my_displayname + " says: Ho Ho Ho.   Ha ha ha. You're slammed.\n",
    });

    triumph_mchannels = ({
        "Suckage has been inflicted. Ho Ho Ho.\n",
        "Ho Ho Ho. Busted!\n",
    });


    casual_emotes = ({
        my_displayname + " says: Ho Ho Ho.    Merry Christmas.\n",
        my_displayname + " says: Ho Ho Ho.    Happy Holidays.\n",
        my_displayname + " says: I know when you've been bad or good...\n",
        my_displayname + " says: I know when you've been sleeping...\n",
        my_displayname + " says: I know when you're awake...\n",
        my_displayname + " says: Ho Ho Ho.    I need some more scotch.\n",
    });

    casual_mchannels = ({
        "Ho Ho Ho.    Merry Christmas.\n",
        "Ho Ho Ho.    Happy Holidays.\n",
        "Ho Ho Ho.    I need some more scotch.\n",
    });


    scared_emotes = ({
        my_displayname + " says: OH CRAP!\n",
    });
    
    scared_mchannels = ({
        "Fuck. I am very scared.\n",
        "I DO NOT LIKE THIS!\n",
        "Nervous a Beano I am.\n",
        "Crap! crap! crap!\n",
    });


    death_emotes = ({
        my_displayname + " crumples to the ground, light extinguished.\n",
    });

    death_mchannels = ({
        "Damnit. I died.\n",
    });


    shit_throw_emotes = ({
        my_displayname + " says: Ho Ho Ho.    You're covered in shit.\n",
        my_displayname + " says: Ho Ho Ho.    You're stinky.\n",
    });
    
    shit_throw_mchannels = ({
        "Ho Ho Ho.    Covered in feces!\n",
    });

    
    balloon_throw_emotes = ({
        my_displayname + " says: Ho Ho Ho.    You're soaking wet.\n",
        my_displayname + " says: Ho Ho Ho.    Splash!.\n",
    });

    balloon_throw_mchannels = ({
        "Ho Ho Ho.    Someone's soaking wet.\n",
    });


    arrival_emotes =({
        my_displayname + " comes to life before you.\n",
    });

    arrival_mchannels =({
        "Ho Ho Ho.    Santa's in the house.\n",
    });

}

/* eof */