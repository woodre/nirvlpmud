inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object what, heals, radio;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Fedor Emelianenko");
    set_race("human");
    set_alias("fedor");
    set_alt_name("emelianenko");
    set_short(HIW + "Fedor Emelianenko" + NORM + " (paladin)");
    set_long("This is someone who by all appearances is a harmless, slightly chubby\n"+
        "guy who could just as well be your plumber or cable TV installer.\n"+
        "However make no mistake... this is Fedor Emelianenko, one of the most feared\n"+
        "and respected professional mixed martial artist fighters in the world.\n"+
        "He has established himself as a dominant heavyweight champion with his\n"+
        "variety of attack styles, willingness to learn new skills, and an insanely\n"+
        "sharp wit- as he is able to quickly change his fighting strategy and\n"+
        "demoralize his opponents.\n");

    set_heal(25, 3);

    set_level(19);
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 3880;
    hit_point = 3880;

    set_al(900);
    set_wc(60);
    set_ac(30);

    radio = clone_object("players/mizan/mbv2/items/pda.c");
    move_object(radio, this_object());

    set_heal(3,2);



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
    set_attribute(ATTRIB_VINDICTIVENESS, 20);
    set_attribute(ATTRIB_FEARLESSNESS, 95);
    set_attribute(ATTRIB_PERCEPTION, 95);
    set_attribute(ATTRIB_CRUELTY, 1);
    set_attribute(ATTRIB_INSANITY, 1);
    set_attribute(ATTRIB_GENEROUSITY, 90);

    set_monster_guild_level(3);
    set_monster_guild_rank("White Bishop");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 1);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 5);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 1);
    set_chance_of(CHANCE_EMOTE_PANICKED, 1);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 1);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 50);
    set_chance_of(CHANCE_EMOTE_CASUAL, 1);
    set_chance_of(CHANCE_EMOTE_SCARED, 1);
    set_chance_of(CHANCE_PELTING_THINGS, 0);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 50000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 15000);
    set_int(VAL_HUNTING_THRESHOLD, 15);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Fedor appears to be annoyed.\n",
        "Fedor says: I will break you.\n",
    });

    attacked_mchannels = ({
        "I am being provoked.\n",
        "Someone is trying to hurt me. I will have to extinguish.\n",
        "I am being provoked, yes.\n",
        });


    panicked_emotes = ({
        "Fedor appears to be annoyed.\n",
        "Fedor appears startled, momentarily.\n",
    });

    panicked_mchannels = ({
        "I do not like to be... surprise.\n",
        "This is very not good.\n",
    });


    hit_hard_emotes = ({
        "Fedor appears to be dazed... for a split second.\n",
        "Fedor says: That was good shot.\n",
        "Fedor says: That was strong but not fully strong.\n",
        "Fedor says: You will have to hit harder than that, yes.\n",
    });

    hit_hard_mchannels = ({
        "That was somewhat painful.\n",
        "I have open cut. Very annoy.\n",
    });


    taunting_emotes = ({
        "Fedor smiles happily.\n",
    });

    taunting_mchannels = ({
        "I do not enjoy taunt. But I will have to use it.\n",
    });

    triumph_emotes = ({
	"Fedor grins biggly.\n",
        "Fedor salutes to the crowd.\n",
    });

    triumph_mchannels = ({
        "I have win.\n",
        "Yes. I will have win.\n",
        "Yes!\n",
    });


    casual_emotes = ({
        "Fedor smiles happily.\n",
        "Fedor says: Hello. I am much happy to meet you.\n",
    });

    casual_mchannels = ({
        "Very good. I am happy to be heres.\n",
        "There is not very good food here.\n",
        "You have to try run. Run more for hours, yes?\n",
    });


    scared_emotes = ({
    "Fedor is not happy.\n",
        "Fedor scowls.\n",
    });

    scared_mchannels = ({
   "Not happy good.\n",
        "I do not enjoy that kind of surprise.\n",
    });


    death_emotes = ({
	"WTF! BUH!\n",
        "Fedor Emelianenko is defeated! OMFGWTFBBQ!?!\n",
    });

    death_mchannels = ({
        "I have been defeat. But I will return, yes.\n",
        "I have been defeat. But you will see me again, yes.\n",
    });



    shit_throw_emotes = ({
        "Fedor grins biggly.\n",
    });

    shit_throw_mchannels = ({
        "This poo throw is bad but very... fun!\n",
        "The poo sticks badly to wall!\n",
        "I have missed with throwing of poo.\n",
    });


    balloon_throw_emotes = ({
        "Fedor smiles broadly.\n",
    });

    balloon_throw_mchannels = ({
        "This water of balloon is fun! Yes!\n",
    });


    arrival_emotes =({
        "Fedor fades into view.\n",
    });

    arrival_mchannels =({
        "Hello everyone. I am have come here to help fight!\n",
    });

}

/* eof */
