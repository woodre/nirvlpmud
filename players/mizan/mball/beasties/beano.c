inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

reset(arg)
{
    object what, what2;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Beano");
    set_race("beano");
    set_alias("x12beano");
    set_short("Beano");
    set_long("This is Beano. It is orange, fuzzy-like, and seems to be made \n" +
    "entirely of light and fuzz. He is intended for levels 3 and under, so\n" +
    "if you fit in that category, kill it with your newbie sword and you'll\n" +
    "(hopefully) get a kicking weapon :) \n");

    set_level(3);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 39;
    hit_point = 39;

    set_al(0);
    set_wc(6);
    set_ac(4);
    set_chance(1);
    set_spell_dam(4);
    set_spell_mess1("Beano does something to you.");
    set_spell_mess2("Beano ebverflugs you.");
    set_chat_chance(10);
    
    load_chat("Beano quibbles.\n");
    load_chat("Beano goes: wibble.\n");
    load_chat("Beano does something.\n");
    load_chat("Beano goes: Gwak.\n");
    load_chat("Beano goes: Gwak!\n");
    load_chat("Beano goes: woot.\n");
    
    set_heal(3,2);
    
    what = clone_object("players/mizan/etheriel/items/thingamajig.c");

    if(1 == random(3))
        what2 = clone_object("players/mizan/mbv2/items/balance.c");
    else if(1 == random(20))
        what2 = clone_object("players/mizan/mbv2/items/walkie-talkie.c");
    else
        what2 = clone_object("players/mizan/mbv2/items/pda.c");

    move_object(what, this_object());
    move_object(what2, this_object());


    
    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_off(MODE_SPARING_NEWBIES);
    toggle_on(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);
    set_attribute(ATTRIB_FEARLESSNESS, 20);
    set_attribute(ATTRIB_PERCEPTION, 20);
    set_attribute(ATTRIB_CRUELTY, 5);
    set_attribute(ATTRIB_INSANITY, 80);
    set_attribute(ATTRIB_GENEROUSITY, 10);

    set_monster_guild_level(1);
    set_monster_guild_rank("Page");

    set_chance_of(CHANCE_CORPSE_LOOTING, 75);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 75);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 40);
    set_chance_of(CHANCE_EMOTE_PANICKED, 90);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 7);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);
    set_chance_of(CHANCE_EMOTE_CASUAL, 8);
    set_chance_of(CHANCE_EMOTE_SCARED, 50);
    set_chance_of(CHANCE_PELTING_THINGS, 50);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 500);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 50);
	set_int(VAL_HUNTING_THRESHOLD, 4);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 3);

    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Beano screams wildly!\n",
        "Beano goes: woot!\n",
        "Beano squits itself against the ground.\n",
        "Beano squints nervously.\n",
    });

	attacked_mchannels = ({
		"I am under attack and very nervous.\n",
        "I do not like being attacked!\n",
        "Being attacked is not fun!\n",
	});


    panicked_emotes = ({
        "Beano wails wildly!\n",
        "Beano goes: Buh!\n",
        "Beano squits itself nervously.\n",
        "Beano screams loudly.\n",
    });

	panicked_mchannels = ({
		"Ack! Shit! Crap!\n",
        "Ow! Eep! Ugh!\n",
        "I am very scared :(\n",
        "I am not liking this :(\n",
	});

    
    hit_hard_emotes = ({
        "Beano screams wildly!\n",
        "Beano cowers in pain!\n",
        "Beano squits against the ground in pain!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! OW! That hurt!\n",
        "I just took a bone-crushing hit! :(\n",
        "ACK! Ow! ow! ow...\n",
    });


    taunting_emotes = ({
        "Beano snurfs at you.\n",
        "Beano grins biggly.\n",
    });

    taunting_mchannels = ({
        "HAH! Hee. Hoo! Heh!\n",
        "Beanos just rule. Woot!\n",
    });


    triumph_emotes = ({
        "Beano goes: WOOT! BUH!\n",
        "Beano wiggles a happy wiggle.\n",
    });

    triumph_mchannels = ({
        "Boohah! Hee! Woot woot woot!\n",
        "Yeah! take that! Stupid carbon-based lifeforms!\n",
    });


    casual_emotes = ({
        "Beano grobbles happily.\n",
        "Beano goes: mmmmrug.\n",
    });

    casual_mchannels = ({
        "Whee!\n",
        "Woot...\n",
        "Nog nog nog!\n",
    });


    scared_emotes = ({
        "Beano appears very stressed.\n",
        "Beano appears very scared.\n",
    });
    
    scared_mchannels = ({
        "Fuck. I am very scared.\n",
        "I DO NOT LIKE THIS!\n",
        "Nervous a Beano I am.\n",
        "Crap! crap! crap!\n",
    });


    death_emotes = ({
        "Beano does not enjoy dying.\n",
        "Beano is not happy.\n",
        "Beano appears depressed.\n",
    });

    death_mchannels = ({
        "Buh! I died! Ack!\n",
        "I'll be back...\n",
        "Doh...\n",
    });


    shit_throw_emotes = ({
        "Beano grins greasily.\n",
        "Beano cackles biggly!\n",
    });
    
    shit_throw_mchannels = ({
        "Nothing says HAH! like a pile of shit in the face!\n",
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Fecalpottyhumor.com!\n",
    });

    
    balloon_throw_emotes = ({
        "Beano makes a funny face at you.\n",
        "Beano grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Someone is soaking wet. Whee!\n",
        "Hee.\n",
    });


    arrival_emotes =({
        "Beano is here!\n",
        "Beano is here! Woot!\n",
    });

    arrival_mchannels =({
        "1 foot, 2 inches, 32 lbs. Beano has a posse.\n",
        "I am here! Yaay!\n",
    });

}

/* eof */