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
    set_name("Afei");
    set_alias("afei");
    set_race("human");
    set_short(HIR + "Afei" + NORM + HIW +" the fearless martial artist " + NORM + "(unrelenting)");
    set_long("Standing before you is an intense, severely caffineated cartoon character\n" +
             "cut in the form of the legendary Bruce Lee. This is Afei, and if it wasn't\n"+
             "for the fact that he is somewhat shorter, and something that stepped out\n"+
             "of a Japanese Anime styled flick, it would be a convincing match.\n"+
             "Still, all those basic features are there, from the smouldering intensity\n"+
             "in his eyes to the cleanly chiseled and well defined features that fill out\n"+
             "his slender frame.\n" +
             "Afei has a tattoo reading: Monster's Guild.\n");

    set_level(17);

    /* we use raw numbers because i overrode set_hp() */
    max_hp = 302;
    hit_point = 302;
    
    set_al(450);
    set_wc(30);
    set_ac(25);
    
    set_heal(3,2);    
    
    what = clone_object("players/mizan/mbv2/items/pda.c");
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
    set_attribute(ATTRIB_VINDICTIVENESS, 55);
    set_attribute(ATTRIB_FEARLESSNESS, 80);
    set_attribute(ATTRIB_PERCEPTION, 80);
    set_attribute(ATTRIB_CRUELTY, 55);
    set_attribute(ATTRIB_INSANITY, 30);
    set_attribute(ATTRIB_GENEROUSITY, 30);

    set_monster_guild_level(2);
    set_monster_guild_rank("White Pawn");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 75);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 50);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 5);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 5);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 5);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 5);
    set_chance_of(CHANCE_PELTING_THINGS, 5);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 20000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 5000);
	set_int(VAL_HUNTING_THRESHOLD, 18);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);




    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Afei screams wildly!\n",
        "Afei goes: Whoaaaaaaaaaauh!!\n",
        "Afei wipes a dab of blood off his lip, and tastes it.\n",
        "Afei stares at you intently.\n",
    });

	attacked_mchannels = ({
		"Violence. I do not enjoy it but delivering it is something I do well.\n",
        "I am in combat now.\n",
        "Move like the wind, heat like the fire, and bend like the grass.\n",
	});


    panicked_emotes = ({
        "Afei appears flustered.\n",
        "Afei falls to the ground!\n",
    });

	panicked_mchannels = ({
		"I am concerned, but not fearful!\n",
        "There will be no panic. I will deliver my vengeance!\n",
	});

    
    hit_hard_emotes = ({
        "Afei screams wildly!\n",
        "Afei is sent sprawling!\n",
    });

    hit_hard_mchannels = ({
        "Water can flow... or it can CRASH!\n",
        "Ouch.\n",
    });


    taunting_emotes = ({
        "Afei sneers.\n",
        "Afei grins biggly.\n",
    });

    taunting_mchannels = ({
        "They are not ready for my fists.\n",
    });


    triumph_emotes = ({
        "Afei stares at you intently.\nAfei says: One great cause of failure is lack of concentration.\n",
        "Afei exclaims: True refinement seeks simplicity. You are too complex for your own good.\n",
    });

    triumph_mchannels = ({
        "Excellent.\n",
        "A goal is not always meant to be reached, it often serves simply as something to aim at.\n",
    });


    casual_emotes = ({
        "Afei smiles happily.\n",
    });

    casual_mchannels = ({
        "This is such a fascinating countryside.\n",
        "There is so much exotic life here.\n",
        "To be happy is to be at peace.\n",
    });


    scared_emotes = ({
        "Afei glances sharply at you.\n",
    });
    
    scared_mchannels = ({
        "Hmm.\n",
    });


    death_emotes = ({
        "Afei falls to the ground.\n",
    });

    death_mchannels = ({
        "I have been defeated. But I shall return. Vengeance will be mine.\n",
    });


    shit_throw_emotes = ({
        "Afei smiles wickedly.\n",
        "Afei glances around innocently.\n",
    });
    
    shit_throw_mchannels = ({
        "Base humor... is the great ancestor of all humor!\n",
    });

    
    balloon_throw_emotes = ({
        "Afei grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "I wish I had these as a child.\n",
    });


    arrival_emotes =({
        "Afei materializes before you.\n",
    });

    arrival_mchannels =({
        "Greetings everyone!\n",
    });


}


heartbeat_attack()
{
    object room;
    room = environment(this_object());

    
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
        });

    if(room && this_object()->query_attack())
    {
        /* emote hit four times, for good measure */
        tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
            this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
            this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

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