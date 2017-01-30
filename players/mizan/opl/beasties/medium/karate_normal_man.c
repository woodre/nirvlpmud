/*****************************************************************************
 *      File:                   karate_normal_man.c
 *      Function:               David Fleetwood is a douchebag.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 *
 ****************************************************************************/

inherit "/players/mizan/mbv3/monsterplus.c";

#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"
#define KARATE_DM       "/players/mizan/opl/daemons/karateDM.c"
#define STATS_DM        "/players/mizan/opl/daemons/statsDM.c"

string attack_pre;
string attack_post;


reset(arg)
{
    object gold;
    string name, desc, style;

    ::reset(arg);
    if(arg) return;

    name = KARATE_DM->get_name();
    desc = KARATE_DM->get_desc();
    style = KARATE_DM->get_style();

    /* standard game lib stuff */
    set_name("Brother " + capitalize(name));
    set_alias(lower_case(name));
    set_alt_name("brother");
    set_race("human");
    set_short(HIW + query_name() + NORM + " of the " + HIW + "Karate Normal School" + NORM);

    set_long("    Standing before you, staring quietly at your crotch is " + query_name() +"\n"+
             "  of the legendary Karate Normal School. Judging from his stance you gather\n"+
             "  he probably was trained in the ancient style of the " + desc + " " + style + "\n"+
             "  by Sensei David Rees himself. " + query_name() + " is calm and supremely\n"+
             "  confident in the belief that his new fighting technique is unstoppable.\n"+
             "  Despite his arrogant ways, he actually has the goods to back some of that\n"+
             "  up. With such grim determination, you might want to tread lightly.\n");

    set_level(STATS_DM->get_level_medium());
    set_heal(48, 2);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_medium();
    hit_point = max_hp;

    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    set_al(-130);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());
    

    
    gold = clone_object("/obj/money.c");
    gold->set_money(5000);
    move_object(gold, this_object());
    

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_on(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_on(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 70);
    set_attribute(ATTRIB_FEARLESSNESS, 80);
    set_attribute(ATTRIB_PERCEPTION, 80);
    set_attribute(ATTRIB_CRUELTY, 55);
    set_attribute(ATTRIB_INSANITY, 40);
    set_attribute(ATTRIB_GENEROUSITY,30 );

    set_monster_guild_level(2);
    set_monster_guild_rank("Black Pawn");

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
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 40000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 3000);
	set_int(VAL_HUNTING_THRESHOLD, 20);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        HIW + query_name() + " says: Get the fuck out of my face with your so-called fighting technique!\n" + NORM,
        HIW + query_name() + " says: Boom! Soon there will be a pile of faces in my foot!\n" + NORM,
        HIW + query_name() + " says: You call that unstoppable, motherfucker?\n" + NORM,
        HIW + query_name() + " says: Boom! Get the fuck out of here with your so-called fighting technique!\n" + NORM,
        HIW + query_name() + " says: Please talk some more shit so I can deliver you an ass-kicking!\n" + NORM,
        HIW + query_name() + " says: You're gonna LIVE in that ambulance motherfucker!\n" + NORM,
        HIW + query_name() + " says: I am in a rage!\n" + NORM,
        HIW + query_name() + " says: My foot has made contact with an IDIOT, motherfucker!\n" + NORM,
        HIW + query_name() + " says: Ah, how delightful! A healthy round of good ol fashioned ass-kicking!\n" + NORM,
        HIW + query_name() + " says: Yo, turn back around and face me, you chicken fuck! Deal with Karate Normal School Style!\n" + NORM,
        HIW + query_name() + " says: Hey! Thanks for listening! And now, a nice kick in the head for you!\n" + NORM,
        HIW + query_name() + " says: Pure fighting energy!\n" + NORM,
        HIW + query_name() + " says: Motherfucker are you ready to gaze up at the ceiling of the ambulance?\n" + NORM,
        HIW + query_name() + " says: Is your ass ready to hit the ground in less than one second?\n" + NORM,
        HIW + query_name() + " says: To be or not to be... Kicking your ass, that is!\n" + NORM,
    });

	attacked_mchannels = ({
        "Get the fuck out of my face with your so-called fighting technique!\n",
        "Boom! Soon there will be a pile of faces in my foot!\n",
        "You call that unstoppable, motherfucker?\n",
        "Boom! Get the fuck out of here with your so-called fighting technique!\n",
        "Please talk some more shit so I can deliver you an ass-kicking!\n",
        "You're gonna LIVE in that ambulance motherfucker!\n",
        "I am in a rage!\n",
        "My foot has made contact with an IDIOT, motherfucker!\n",
        "Ah, how delightful! A healthy round of good ol fashioned ass-kicking!\n",
        "Yo, turn back around and face me, you chicken fuck! Deal with Karate Normal School Style!\n",
        "Hey! Thanks for listening! And now, a nice kick in the head for you!\n",
        "Pure fighting energy!\n",
        "Motherfucker are you ready to gaze up at the ceiling of the ambulance?\n",
        "Is your ass ready to hit the ground in less than one second?\n",
        "To be or not to be... Kicking your ass, that is!\n",
	});


    panicked_emotes = ({
        HIW + query_name() + " says: OUCH! Just another day at KARATE PRACTICE!\n" + NORM,
        HIW + query_name() + " says: Fuck THAT shit! I'm on YOUR side!\n" + NORM,
        HIW + query_name() + " says: Holy fuck, though-if the techniques are good, he'd be totally unstoppable! What the fuck!\n" + NORM,
        HIW + query_name() + " says: Holy shit dude, that motherfucker will destroy all of us if it is true!\n" + NORM,
    });

	panicked_mchannels = ({
        "OUCH! Just another day at KARATE PRACTICE!\n",
        "Fuck THAT shit! I'm on YOUR side!\n",
        "Holy fuck, though-if the techniques are good, he'd be totally unstoppable! What the fuck!\n",
        "Holy shit dude, that motherfucker will destroy all of us if it is true!\n",
	});

    
    hit_hard_emotes = ({
        HIW + query_name() + " exclaims: Holy shit! You kicked me in the face!\n" + NORM,
        HIW + query_name() + " exclaims: Damn! You're raging!\n" + NORM,
        HIW + query_name() + " exclaims: HOLY SHIT! You kicked me in the face again! Dude, I am about to tear you apart! Fucking with me when I'm tired!\n" + NORM,
        HIW + query_name() + " exclaims: Damn, you're a total bad-ass now! That hurt!\n" + NORM,
    });

    hit_hard_mchannels = ({
        "Holy shit! You kicked my in the face!\n",
        "Damn! You're raging!\n",
        "HOLY SHIT! You kicked me in the face again! Dude, I am about to tear you apart! Fucking with me when I'm tired!\n",
        "Damn, you're a total bad-ass now! That hurt!\n",
    });


    taunting_emotes = ({
        HIW + query_name() + " says: You cannot break my unstoppable calves of steel!\n" + NORM,
        HIW + query_name() + " says: I am the cure to your disease of Not Getting Enough Ass Kicking!\n" + NORM,
        HIW + query_name() + " says: I am going to kick your ass to PRE-BEGINNER class lessons!\n" + NORM,
        HIW + query_name() + " says: Special discounts on foot induced facelifts!\n" + NORM,
        HIW + query_name() + " says: There you are, motherfucker, come here and receive my knuckles in your facial region!\n" + NORM,
    });

    taunting_mchannels = ({
        "You cannot break my unstoppable calves of steel!\n",
        "I am the cure to your disease of Not Getting Enough Ass Kicking!\n",
        "I am going to kick your ass to PRE-BEGINNER class lessons!\n",
        "Special discounts on foot induced facelifts!\n",
        "There you are, motherfucker, come here and receive my knuckles in your facial region!\n",
    });


    triumph_emotes = ({
        HIW + query_name() + " says: Boom! Enjoy your stay at the hospital!\n" + NORM,
        HIW + query_name() + " says: Boom! Enjoy your ride in that ambulance!\n" + NORM,
        HIW + query_name() + " says: Do you hear that? It's the sound of your ASS hitting the ground in one second!\n" + NORM,
        HIW + query_name() + " says: There you go, motherfucker! Ask the fucking doctor in the hospital for some nutritional information! Now I'm gonna go take my nap!\n" + NORM,
    });

    triumph_mchannels = ({
        "Boom! Enjoy your stay at the hospital!\n",
        "Boom! Enjoy your ride in that ambulance!\n",
        "Do you hear that? It's the sound of your ASS hitting the ground in one second!\n",
        "There you go, motherfucker! Ask the fucking doctor in the hospital for some nutritional information! Now I'm gonna go take my nap!\n",
    });


    casual_emotes = ({
        HIW + query_name() + " says: You get to beat the shit out of people!\n" + NORM,
        HIW + query_name() + " says: My new fighting technique is unstoppable!\n" + NORM,
        HIW + query_name() + " says: Hello there! Join our Karate Temple!\n" + NORM,
    });

    casual_mchannels = ({
        "Trying to get others to join the Karate Temple!\n",
        "You get to beat the shit out of people!\n",
        "My new fighting technique is unstoppable!\n",
    });


    scared_emotes = ({
        HIW + query_name() + " exclaims: Motherfucker, are you my health teacher?\n" + NORM,
        HIW + query_name() + " exclaims: This sucks because it'll be hard to suffer defeat at the hands of this dipshit!\n" + NORM,
    });
    
    scared_mchannels = ({
        "Motherfucker, are you my health teacher?\n",
        "This sucks because it'll be hard to suffer defeat at the hands of this dipshit!\n",
    });


    death_emotes = ({
        HIW + query_name() + " falls to the ground. It's too late for an ambulance.\n" + NORM,
    });

    death_mchannels = ({
        "I have been defeated. But my new fighting technique will be unstoppable, motherfuckers!\n",
    });


    shit_throw_emotes = ({
        HIW + query_name() + " says: It's not a ninja star, freak! It's a stinking pile of shit!\n" + NORM,
        HIW + query_name() + " says: Here, have a stinking pile of shit!\n" + NORM,
    });
    
    shit_throw_mchannels = ({
        "Here, have a stinking pile of shit!\n",
    });

    
    balloon_throw_emotes = ({
        HIW + query_name() + " says: Here's a balloon for you, motherfucker!\n" + NORM,
    });

    balloon_throw_mchannels = ({
        "Here's a balloon for you, motherfucker!\n",
    });


    arrival_emotes =({
        HIW + query_name() + " emerges in a puff of smoke.\n" + NORM,
    });

    arrival_mchannels =({
        "It's time for some ritual ass kicking, motherfuckers!\n",
    });


}


heartbeat_attack()
{
    object room;
    room = environment(this_object());

    if(query_chance_of(CHANCE_EMOTE_ATTACKED) > random(100))
        do_emote_attacked(this_object());
    
    if(room && this_object()->query_attack())
    {
        /* emote hit four times, for good measure */
        tell_room(room, query_name() + KARATE_DM->get_attack_pre() +
            this_object()->query_attack()->query_name() + KARATE_DM->get_attack_post());

        if(1 == random(2)) 
            tell_room(room, query_name() + KARATE_DM->get_attack_pre() +
                this_object()->query_attack()->query_name() + KARATE_DM->get_attack_post());

        if(1 == random(2)) 
            tell_room(room, query_name() + KARATE_DM->get_attack_pre() +
                this_object()->query_attack()->query_name() + KARATE_DM->get_attack_post());

        if(1 == random(2)) 
            tell_room(room, query_name() + KARATE_DM->get_attack_pre() +
                this_object()->query_attack()->query_name() + KARATE_DM->get_attack_post());

    }
}



/* eof */
