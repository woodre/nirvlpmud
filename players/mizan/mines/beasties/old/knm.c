/* 
 * knm.c
 * 
 * Reflex is a faggot.
 *
 */

inherit "/players/mizan/mbv2/monsterplus.c";

#include "/players/mizan/mbv2/definitions.h"
#include "/obj/ansi.h"

string attack_pre;
string attack_post;


reset(arg)
{
    object what;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Karate Normal Man");
    set_alias("karatemanx2");
    set_race("man");
    set_short(HIW + "Karate Normal Man " + NORM + "(raging)");
    set_long("This is a crudely rendered Karate Normal Man, straight from the libraries\n" +
             "of a CorelDraw clipart package. He is blunt, arrogant, and basically 100%\n"+
             "infatuated with his belief that his new fighting technique is unstoppable.\n"+
             "Despite his arrogant ways, he actually has the goods to back some of that\n"+
             "up. If you are a newbie, don't even consider fighting him. If you are a\n"+
             "player of significantly higher level, please consider bringing lots of heals\n"+
             "and make sure you call an ambulance, just in case.\n" +
             "Karate Normal Man has a tattoo reading: Monster's Guild.\n");

    set_level(17);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 302;
    hit_point = 302;

    set_al(-130);
    set_wc(67);
    set_ac(25);
    
    set_heal(3,2);

    what = clone_object("players/mizan/mbv2/items/pda.c");
    move_object(what, this_object());

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
    set_int(VAL_MAX_HEAL_QUOTA, 5300);
	set_int(VAL_HUNTING_THRESHOLD, 20);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        HIW + "Karate Normal Man says: Get the fuck out of my face with your so-called fighting technique!\n" + NORM,
        HIW + "Karate Normal Man says: Boom! Soon there will be a pile of faces in my foot!\n" + NORM,
        HIW + "Karate Normal Man says: You call that unstoppable, motherfucker?\n" + NORM,
        HIW + "Karate Normal Man says: Boom! Get the fuck out of here with your so-called fighting technique!\n" + NORM,
        HIW + "Karate Normal Man says: Please talk some more shit so I can deliver you an ass-kicking!\n" + NORM,
        HIW + "Karate Normal Man says: You're gonna LIVE in that ambulance motherfucker!\n" + NORM,
        HIW + "Karate Normal Man says: I am in a rage!\n" + NORM,
        HIW + "Karate Normal Man says: My foot has made contact with an IDIOT, motherfucker!\n" + NORM,
        HIW + "Karate Normal Man says: Ah, how delightful! A healthy round of good ol fashioned ass-kicking!\n" + NORM,
        HIW + "Karate Normal Man says: Yo, turn back around and face me, you chicken fuck! Deal with Karate Normal Man!\n" + NORM,
        HIW + "Karate Normal Man says: Hey! Thanks for listening! And now, a nice kick in the head for you!\n" + NORM,
        HIW + "Karate Normal Man says: Pure fighting energy!\n" + NORM,
        HIW + "Karate Normal Man says: Motherfucker are you ready to gaze up at the ceiling of the ambulance?\n" + NORM,
        HIW + "Karate Normal Man says: Is your ass ready to hit the ground in less than one second?\n" + NORM,
        HIW + "Karate Normal Man says: To be or not to be... Kicking your ass, that is!\n" + NORM,
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
        "Yo, turn back around and face me, you chicken fuck! Deal with Karate Normal Man!\n",
        "Hey! Thanks for listening! And now, a nice kick in the head for you!\n",
        "Pure fighting energy!\n",
        "Motherfucker are you ready to gaze up at the ceiling of the ambulance?\n",
        "Is your ass ready to hit the ground in less than one second?\n",
        "To be or not to be... Kicking your ass, that is!\n",
	});


    panicked_emotes = ({
        HIW + "Karate Normal Man says: OUCH! Just another day at KARATE PRACTICE!\n" + NORM,
        HIW + "Karate Normal Man says: Fuck THAT shit! I'm on YOUR side!\n" + NORM,
        HIW + "Karate Normal Man says: Holy fuck, though-if the techniques are good, he'd be totally unstoppable! What the fuck!\n" + NORM,
        HIW + "Karate Normal Man says: Holy shit dude, that motherfucker will destroy all of us if it is true!\n" + NORM,
    });

	panicked_mchannels = ({
        "OUCH! Just another day at KARATE PRACTICE!\n",
        "Fuck THAT shit! I'm on YOUR side!\n",
        "Holy fuck, though-if the techniques are good, he'd be totally unstoppable! What the fuck!\n",
        "Holy shit dude, that motherfucker will destroy all of us if it is true!\n",
	});

    
    hit_hard_emotes = ({
        HIW + "Karate Normal Man exclaims: Holy shit! You kicked my in the face!\n" + NORM,
        HIW + "Karate Normal Man exclaims: Damn! You're raging!\n" + NORM,
        HIW + "Karate Normal Man exclaims: HOLY SHIT! You kicked me in the face again! Dude, I am about to tear you apart! Fucking with me when I'm tired!\n" + NORM,
        HIW + "Karate Normal Man exclaims: Damn, you're a total bad-ass now! That hurt!\n" + NORM,
    });

    hit_hard_mchannels = ({
        "Holy shit! You kicked my in the face!\n",
        "Damn! You're raging!\n",
        "HOLY SHIT! You kicked me in the face again! Dude, I am about to tear you apart! Fucking with me when I'm tired!\n",
        "Damn, you're a total bad-ass now! That hurt!\n",
    });


    taunting_emotes = ({
        HIW + "Karate Normal Man says: You cannot break my unstoppable calves of steel!\n" + NORM,
        HIW + "Karate Normal Man says: I am the cure to your disease of Not Getting Enough Ass Kicking!\n" + NORM,
        HIW + "Karate Normal Man says: I am going to kick your ass to PRE-BEGINNER class lessons!\n" + NORM,
        HIW + "Karate Normal Man says: Special discounts on foot induced facelifts!\n" + NORM,
        HIW + "Karate Normal Man says: There you are, motherfucker, come here and receive my knuckles in your facial region!\n" + NORM,
    });

    taunting_mchannels = ({
        "You cannot break my unstoppable calves of steel!\n",
        "I am the cure to your disease of Not Getting Enough Ass Kicking!\n",
        "I am going to kick your ass to PRE-BEGINNER class lessons!\n",
        "Special discounts on foot induced facelifts!\n",
        "There you are, motherfucker, come here and receive my knuckles in your facial region!\n",
    });


    triumph_emotes = ({
        HIW + "Karate Normal Man says: Boom! Enjoy your stay at the hospital!\n" + NORM,
        HIW + "Karate Normal Man says: Boom! Enjoy your ride in that ambulance!\n" + NORM,
        HIW + "Karate Normal Man says: Do you hear that? It's the sound of your ASS hitting the ground in one second!\n" + NORM,
        HIW + "Karate Normal Man says: There you go, motherfucker! Ask the fucking doctor in the hospital for some nutritional information! Now I'm gonna go take my nap!\n" + NORM,
    });

    triumph_mchannels = ({
        "Boom! Enjoy your stay at the hospital!\n",
        "Boom! Enjoy your ride in that ambulance!\n",
        "Do you hear that? It's the sound of your ASS hitting the ground in one second!\n",
        "There you go, motherfucker! Ask the fucking doctor in the hospital for some nutritional information! Now I'm gonna go take my nap!\n",
    });


    casual_emotes = ({
        HIW + "Karate Normal Man says: You get to beat the shit out of people!\n" + NORM,
        HIW + "Karate Normal Man says: My new fighting technique is unstoppable!\n" + NORM,
        HIW + "Karate Normal Man says: Hello there! Join our Karate Temple!\n" + NORM,
    });

    casual_mchannels = ({
        "Trying to get others to join the Karate Temple!\n",
        "You get to beat the shit out of people!\n",
        "My new fighting technique is unstoppable!\n",
    });


    scared_emotes = ({
        HIW + "Karate Normal Man exclaims: Motherfucker, are you my health teacher?\n" + NORM,
        HIW + "Karate Normal Man exclaims: This sucks because it'll be hard to suffer defeat at the hands of this dipshit!\n" + NORM,
    });
    
    scared_mchannels = ({
        "Motherfucker, are you my health teacher?\n",
        "This sucks because it'll be hard to suffer defeat at the hands of this dipshit!\n",
    });


    death_emotes = ({
        HIW + "Karate Normal Man falls to the ground. It's too late for an ambulance.\n" + NORM,
    });

    death_mchannels = ({
        "I have been defeated. But my new fighting technique will be unstoppable, motherfuckers!\n",
    });


    shit_throw_emotes = ({
        HIW + "Karate Normal Man says: It's not a ninja star, freak! It's a stinking pile of shit!\n" + NORM,
        HIW + "Karate Normal Man says: Here, have a stinking pile of shit!\n" + NORM,
    });
    
    shit_throw_mchannels = ({
        "Here, have a stinking pile of shit!\n",
    });

    
    balloon_throw_emotes = ({
        HIW + "Karate Normal Man says: Here's a balloon for you, motherfucker!\n" + NORM,
    });

    balloon_throw_mchannels = ({
        "Here's a balloon for you, motherfucker!\n",
    });


    arrival_emotes =({
        HIW + "Karate Normal Man emerges in a puff of smoke.\n" + NORM,
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
    
    /* init our vars if they aren't */
    if(!attack_pre)
        attack_pre = ({
            " strikes ",
            " smashes ",
            " beats ",
            " viciously kicks ",
            " fiercely punches ",
            " deftly punches ",
            " quickly punches ",
            " jabs ",
            " quickly jabs ",
            " multiple punches ",
            " multiple jabs ",
            " backpunches ", 
            " chops ",
            " chop hits ",
            " crescent kicks ",
            " forward kicks ",
            " side kicks ",
            " jump kicks ",
            " jump elbows ",
            " knee smashes ",
            " whip kicks ",
            " double crescent kicks ",
            " double spinning kicks ",
            " spinning kicks ",
        });

    if(!attack_post)
        attack_post = ({
            " in the groin!\n",
            " in the face!\n",
            " in the chest!\n",
            " in the shoulder!\n",
            " in the ribs!\n",
            " in the neck!\n",
            " in the throat!\n",
            " in the ass!\n",
            " in the crotch!\n",
        });

    if(room && this_object()->query_attack())
    {
        /* emote hit four times, for good measure */
        tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
            this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        if(1 == random(2)) 
            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        if(1 == random(2)) 
            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        if(1 == random(2)) 
            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

    }
}



/* eof */
