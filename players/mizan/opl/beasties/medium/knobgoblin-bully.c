/*****************************************************************************
 *      File:                   knobgoblin-bully.c
 *      Function:               Patrolling kid/pet killer, PK instigator, and
 *                              targets the weakest player present.
 *                              A lot stronger than the regular knobgoblin.
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

#define GOBLIN_DM       "/players/mizan/opl/daemons/goblinDM.c"
#define STATS_DM        "/players/mizan/opl/daemons/statsDM.c"
#define MAMASNAPS_DM    "/players/mizan/opl/daemons/mamasnapsDM.c"

string my_name;

reset(arg)
{
    object gold, heal;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    my_name = GOBLIN_DM->get_knobgoblin_bully_name();

    set_name(my_name);
    set_race("knobgoblin");
    set_alias(lower_case(my_name));
    set_short(my_name + " the " + HIG + "bully knobgoblin" + NORM);

    set_long(
    "    Right when you turned to look at this knobgoblin, you answered the\n"+
    "  question that shot to mind... 'What could be worse than being a goblin?\n"+
    "  That's right... being a reject goblin. It seems that the knobgoblins\n"+
    "  have a chip on their shoulder and feel this need to prove themselves.\n"+
    "  This one however is significantly larger than the scrawnier knobgoblin\n"+
    "  stock you have seen before, and no doubt is a more dangerous foe.\n");

    set_level(STATS_DM->get_level_easy());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_easy();
    hit_point = max_hp;

    set_al(-750);

    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;
    
    set_heal(55,2);    
    
    set_hp_bonus(STATS_DM->get_hp_bonus_easy());

    set_chat_chance(5);
    load_chat(my_name + " picks his nose.\n");
    load_chat(my_name + " scratches his butt.\n");
    load_chat(my_name + " burps rudely!\n");
    load_chat(my_name + " adjusts his crotch.\n");
    load_chat(my_name + " scratches himself.\n");
    load_chat(my_name + " farts loudly. POOOOOT!\n");
    
    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(250);

    gold = clone_object("obj/money");
    gold->set_money(1000);
    move_object(gold,this_object());
    
    if(1 == random(5))
    {
        heal = clone_object("/players/mizan/opl/heals/weinernut.c");
        move_object(heal, this_object());
    }

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);

    /* once in a while these guys can get help */
    if(1 == random(10)) toggle_on(MODE_CALLS_FOR_BACKUP); 
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
    set_attribute(ATTRIB_INSANITY, 70);
    set_attribute(ATTRIB_GENEROUSITY,20);

    set_monster_guild_level(2);
    set_monster_guild_rank("Super Jerk");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "Knobgoblins");

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 100);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 6);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 6);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 200000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 2000);
    set_int(VAL_HUNTING_THRESHOLD, 27);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 4);
    
    /* monsterplus specific toggles */


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        query_name() + " says: You want to fight? Yeah! Fuck you too!\n",
        query_name() + " says: I'll fight you, goddamnit!\n",
    });

	attacked_mchannels = ({
	"I am under attack... send help!\n",
        "I don't like being attacked by stupid human uglies!\n",
	});


    panicked_emotes = ({
        query_name() + " freaks out!\n",
        query_name() + " panics and starts screaming!\n",
    });

	panicked_mchannels = ({
        "Whisky Tango Foxtrot!\n",
        "Ow! Ow! Ow!!\n",
        "What in the sweet Satan was THAT!?\n",
        "I am not happy with this. Things do not look good.\n",
	});

    
    hit_hard_emotes = ({
        query_name() + " cringes from the impact!\n",
        query_name() + " screams loudly!!\n",
        query_name() + " reels in terrible pain!\n",
    });

    hit_hard_mchannels = ({
        "OW! Fuck! That hurt!\n",
        "Those bone-crushing hits... Fuck!\n",
    });


    taunting_emotes = ({
        query_name() + " says: Come suck my BONER, you uglies!\n",
        query_name() + " says: You guys are a bunch of cowards!\n",
        query_name() + " flashes you!\n",
        query_name() + " pulls his loincloth down and MOONS you!\n",
        query_name() + " dangles his manhood menacingly at you.\n",
    });

    taunting_mchannels = ({
        "Stupid humans.\n",
        "Goddamn assfaced humans.\n",
    });


    triumph_emotes = ({
        query_name() + " says: YEAH! SUCK THAT DOWN STUPID HUMANS!\n",
        query_name() + " says: IN YOUR FUCKING FACE!\n",
        query_name() + " says: IN YOUR MOUTH!\n",
    });

    triumph_mchannels = ({
        "WOOT! WOOT! WOOT! YEAH I SHOWED THEM HUMANS! Hah!\n",
        "Yeah! take that! FUCKERS!\n",
    });


    casual_emotes = ({
        query_name() + " smirks.\n",
        query_name() + " grins smugly.\n",
    });

    casual_mchannels = ({
        "Wandering around.... fucking BORING.\n",
        "I WANT TO BULLY SOME HUMANS!\n",
    });


    scared_emotes = ({
        query_name() + " appears somewhat nervous.\n",
        query_name() + " twitches nervously.\n",
    });
    
    scared_mchannels = ({
        "Yo. This shit is bugging me out, man.\n",
        "Hmm. What the daisy is going on here...\n",
    });


    death_emotes = ({
        query_name() + " crumples to the ground, dead.\n",
        query_name() + " collapses... He's dead, Jim.\n",
        query_name() + " says with his dying breath: Fuuuuck.... Yooooou...\n",
    });

    death_mchannels = ({
        "Like the Terminator, I'll be back...\n",
        "Aaaaauuugh...\n",
    });


    shit_throw_emotes = ({
        query_name() + " grins greasily.\n",
        query_name() + " cackles menacingly!\n",
    });
    
    shit_throw_mchannels = ({
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Splat. You have shit!\n",
    });

    
    balloon_throw_emotes = ({
        query_name() + " says: SUCKER!!!\n",
        query_name() + " grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Someone is soaking wet. Whee!\n",
        "Hee.\n",
    });


    arrival_emotes =({
        query_name() + " emerges from the shadows.\n",
        query_name() + " suddenly appears out from behind you.\n"
    });

    arrival_mchannels =({
        "Yo... Where the bitches at?!\n",
        "I'm fucking HERE... yeaaaaah...\n",
    });

}


heartbeat_attack()
{
    object attacker;
    object weakest;
    object room;

    /* Setup some vars */
    room = environment(this_object());
    attacker = this_object()->query_attack();
    weakest = get_weakest_player_present(this_object());

    if(1 == random(3) && weakest && attacker != weakest && room)
    {
        tell_room(room, query_name() + " senses weakness in " + weakest->query_name() + "...\n");
        tell_room(room, HIG + query_name() + " turns to attack " + weakest->query_name() + "!\n");
        this_object()->attack_object(weakest);
    }

}

heart_beat()
{
    ::heart_beat();
    if (attacker_ob && 1 == random(5)) mamasnap();
}

mamasnap()
{
    string result;
    result = query_name() + " says: " + HIG + MAMASNAPS_DM->query_snap() + NORM + "\n";
    say(result);
}


/* eof */