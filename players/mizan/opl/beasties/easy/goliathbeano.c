/*****************************************************************************
 *      File:                   goliathbeano.c
 *      Function:               Patrolling kid/pet killer, PK instigator
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
#include "/obj/ansi.h"

reset(arg)
{
    object what, heals, radio, gold;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Goliath Beano");
    set_race("beano");
    set_alias("goliath beano");
    set_short("Goliath Beano");
    set_long("Oh no. This is a SIGNIFICANTLY larger Beano than you are used\n"+
        "to seeing. Although only barely five feet tall, he is still four feet\n"+
    "taller than the average beano. Plus... he is armed and fairly alery looking\n"+
    "compared to the care-free, happy-go-lucky whimsy of his smaller cousins.\n"+
    "Perhaps this Beano won't go down without putting up a fight.\n");
    set_level(26);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    /* we use raw numbers because i overrode set_hp() */
    max_hp = 2560;
    hit_point = 2560;
    set_hp_bonus(4000);    

    set_al(0);
    set_wc(80);
    set_ac(47);
    set_chat_chance(2);
    
    set_heal(30,10);    
    
    load_chat("Goliath Beano quibbles silently.\n");
    load_chat("Goliath Beano goes: GWAK.\n");
    load_chat("Goliath Beano goes: WOOT.\n");
    load_chat("Goliath Beano does something.\n");
    
/*
    what = clone_object("players/mizan/etheriel/items/tpole.c");
    move_object(what, this_object());

    radio = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(radio, this_object());
*/

    heals = clone_object("players/mizan/etheriel/items/backpack");
    move_object(heals, this_object());

    gold = clone_object("obj/money");
    gold->set_money(5000);
    move_object(gold,this_object());
    
/*
    command("wield pole", this_object());
*/

    
    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);

    if(1 == random(3)) toggle_on(MODE_CALLS_FOR_BACKUP);
    else toggle_off(MODE_CALLS_FOR_BACKUP);

    toggle_on(MODE_KID_KILLER);
    toggle_on(MODE_PET_KILLER);
    toggle_on(MODE_PK_INSTIGATOR);
    toggle_on(MODE_COVERS_PRESENT_ALLIES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 90);
    set_attribute(ATTRIB_FEARLESSNESS, 50);
    set_attribute(ATTRIB_PERCEPTION, 40);
    set_attribute(ATTRIB_CRUELTY, 15);
    set_attribute(ATTRIB_INSANITY, 3);
    set_attribute(ATTRIB_GENEROUSITY,20);

    set_monster_guild_level(2);
    set_monster_guild_rank("White Pawn");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "Beanos");

    set_chance_of(CHANCE_CORPSE_LOOTING, 35);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 20);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 6);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 6);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 20000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 2300);
	set_int(VAL_HUNTING_THRESHOLD, 27);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 4);
    
    /* monsterplus specific toggles */


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Goliath Beano grobbles loudly!\n",
        "Goliath Beano goes: GRONK!\n",
        "Goliath Beano squits itself against you angrily.\n",
        "Goliath Beano adjusts its stance.\n",
    });

	attacked_mchannels = ({
	"I am under attack. Buh.\n",
        "I do not like being attacked by stupid humans.\n",
        "Humans need to be taught a lesson.\n",
        "Carbon based stupidity at work again.\n",
        "Humanity sucks.\n",
	});


    panicked_emotes = ({
        "Goliath Beano freaks out!\n",
        "Goliath Beano goes: Buh!\n",
        "Goliath Beano grobbles angrily!\n",
        "Goliath Beano appears to be somewhat edgy.\n",
    });

	panicked_mchannels = ({
		"Urrrrrr!\n",
        "Ow! Ow! Ow!!\n",
        "This makes me nervous.\n",
        "I am not happy with this. Things do not look good.\n",
	});

    
    hit_hard_emotes = ({
        "Goliath Beano cringes somewhat!\n",
        "Goliath Beano goes: Urgh!\n",
        "Goliath Beano squits against the ground in pain!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! OW! That hurt!\n",
        "I just took a bone-crushing hit... grrrr...\n",
        "ACK! Ow! ow! ow...\n",
    });


    taunting_emotes = ({
        "Goliath Beano snurfles at you.\n",
        "Goliath Beano says: Humans. Hwarf.\n",
        "Goliath Beano says: Blunt heads.\n",
        "Goliath Beano says: Silly humans.\n",
        "Goliath Beano grins biggly.\n",
    });

    taunting_mchannels = ({
        "Stupid elbowed humans.\n",
        "Blunt heads.\n",
        "In Beano we call humans 'Blunt heads'.\n",
    });


    triumph_emotes = ({
        "Goliath Beano goes: WOOT! BUH!\n",
        "Goliath Beano wiggles a happy wiggle.\n",
        "Goliath Beano grins heartily.\n",
    });

    triumph_mchannels = ({
        "WOOT! WOOT! WOOT! Hah!\n",
        "Yeah! take that! Stupid lifeforms!\n",
        "Human bones knitting. Hee.\n",
    });


    casual_emotes = ({
        "Goliath Beano grobbles happily.\n",
        "Goliath Beano goes: mmmmrug.\n",
    });

    casual_mchannels = ({
        "Whee!\n",
        "Woot...\n",
        "Nog nog nog!\n",
        "This is fun.\n",
        "Look!\n",
    });


    scared_emotes = ({
        "Goliath Beano appears somewhat stressed.\n",
        "Goliath Beano appears somewhat nervous.\n",
        "Goliath Beano goes: hwarf.\n",
    });
    
    scared_mchannels = ({
        "I am somewhat nervous.\n",
        "Hmm.\n",
        "Nuhh... urr...\n",
        "Crap! crap! crap!\n",
    });


    death_emotes = ({
        "Goliath Beano does not enjoy dying.\n",
        "Goliath Beano is not happy.\n",
        "Goliath Beano appears depressed.\n",
    });

    death_mchannels = ({
        "Buh! I died! Ack!\n",
        "I'll be back... Grr.\n",
        "Doh... I died.\n",
    });


    shit_throw_emotes = ({
        "Goliath Beano grins greasily.\n",
        "Goliath Beano cackles biggly!\n",
    });
    
    shit_throw_mchannels = ({
        "The look of something being hit with a shit pile is most funny.\n",
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Splat. You have shit!\n",
    });

    
    balloon_throw_emotes = ({
        "Goliath Beano makes a funny face at you.\n",
        "Goliath Beano grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Someone is soaking wet. Whee!\n",
        "Hee.\n",
    });


    arrival_emotes =({
        "Goliath Beano is here!\n",
        "Goliath Beano is here! Woot!\n",
    });

    arrival_mchannels =({
        "5 foot, 2 inches, 760 lbs. Goliath Beano has a posse.\n",
        "I am here! RAAR!\n",
    });

}


/* eof */
