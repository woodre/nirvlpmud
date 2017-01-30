/*****************************************************************************
 *      File:                   li-mao-ching.c
 *      Function:               High value monster with goodies. Rare monster
 *                              and does not appear often in the game (ideally
 *                              just once per boot.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         New file
 ****************************************************************************/

inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"

#define STATS_DM       "/players/mizan/opl/daemons/statsDM.c"

string attack_pre;
string attack_post;

reset(arg)
{
    object gold;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Li Mao-Ching");
    set_alias("li");
    set_race("man");
    set_short("A little old Chinese man (mostly harmless)");
    set_long("Smiling happily at you with a twinkle in his eye is a wizened little old\n" +
             "Chinese man. He is wearing a simple tee-shirt and sweatpants, with a pair of\n"+
             "cloth shoes fitting the era of the 1950's. Wood chips and sawdust hang\n"+
             "in his otherwise cleanly maintained beard. He isn't quite hunched, but carries\n"+
             "himself in a way that seems to fit his years. However you have a feeling that\n"+
             "underneath the shell of this harmless looking little old man lies a raging\n"+
             "beast of a fighter than if provoked will probably rip your arms off and stuff\n"+
             "them into what's left of your glory hole.\n\n");

    set_level(STATS_DM->get_level_hard() + STATS_DM->get_level_easy());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_hard();
    hit_point = max_hp;

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;
    
    set_al(650);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());
    
    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(29,1);    

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard() * 2);
    move_object(gold,this_object());
    
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
    set_attribute(ATTRIB_VINDICTIVENESS, 10);
    set_attribute(ATTRIB_FEARLESSNESS, 100);
    set_attribute(ATTRIB_PERCEPTION, 100);
    set_attribute(ATTRIB_CRUELTY, 50);
    set_attribute(ATTRIB_INSANITY, 5);
    set_attribute(ATTRIB_GENEROUSITY, 80);

    set_monster_guild_level(4);
    set_monster_guild_rank("White Bishop");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "Archangels");

    set_chance_of(CHANCE_CORPSE_LOOTING, 50);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 0);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 4);
    set_chance_of(CHANCE_EMOTE_PANICKED, 3);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 3);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 3);
    set_chance_of(CHANCE_EMOTE_CASUAL, 3);
    set_chance_of(CHANCE_EMOTE_SCARED, 3);
    set_chance_of(CHANCE_PELTING_THINGS, 0);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 80000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 22000);
	set_int(VAL_HUNTING_THRESHOLD, 10);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);




    /* lots of channel and emote stuff */
    attacked_emotes = ({
        HIW + "Master Li Mao-Ching smiles calmly and readies his next combination...\n" + NORM,
        HIW + "Master Li Mao-Ching smirks wickedly at you.\n" + NORM,
        HIW + "Master Li Mao-Ching says: You are not ready to fight. But you are ready to die at my fists.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: Your fighting technique is most pitiful, young stupid.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: You disrespectful, and smelly.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: You are already at the end of your road, young turtle!\n" + NORM, 
        HIW + "Master Li Mao-Ching says: Ignorant! Bumbling ignorant toad!\n" + NORM, 
    });

	attacked_mchannels = ({
		"Speed, might, power. Flow like the water, kill like machine gun.\n",
        "I am in combat, and my enemy should buy casket.\n",
        "They disrespectful, and smelly.",
        "Silly! Stupid! They are only ready to die!\n",
	});


    panicked_emotes = ({
        HIW + "Master Li Mao-Ching laughs heartily.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: Is that the best you can do?\n" + NORM, 
        HIW + "Master Li Mao-Ching says: You have much to learn, but it is pity you will not live long enough.\n" + NORM, 
    });

	panicked_mchannels = ({
		"They will taste the back of my hand... through their heads!\n",
        "Remember your forms! Through rigidity they give imagination!\n",
        "Ahh, fascinating!\n",
	});

    
    hit_hard_emotes = ({
        HIW + "Master Li Mao-Ching smiles wryly at you.\n" + NORM, 
        HIW + "Master Li Mao-Ching asks: Is that all you can do, little turtle egg?\n" + NORM, 
        HIW + "Master Li Mao-Ching says: So that's the extent of your fighting technique?\n" + NORM, 
        HIW + "Master Li Mao-Ching says: I am not impressed.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: Your fighting technique is like dead fish on warm day!\n" + NORM, 
    });

    hit_hard_mchannels = ({
        "I am not impressed by my opponent. I am disappointed.\n",
        "My opponent has the fighting style of a drunken ass!\n",
    });


    taunting_emotes = ({
        HIW + "Master Li Mao-Ching says: I am not your judge... but its that you should be punished!\n" + NORM, 

    });

    taunting_mchannels = ({
        "These opponents are most... ignorant.. and uncreative.\n",
    });


    triumph_emotes = ({
        HIW + "Master Li Mao-Ching says: You have been beaten. Learn your lesson that there is always a bigger fish.\n" + NORM, 
        HIW + "Master Li Mao-Ching says: You fight like a drunken YAK!\n" + NORM, 
        HIW + "Master Li Mao-Ching says: You move... like a pregnant cow.\n" + NORM, 

    });

    triumph_mchannels = ({
        "Most good.\n",
        "Careful!\n",
    });


    casual_emotes = ({
        HIW + "Master Li Mao-Ching looks up at the sky.\n" + NORM, 
        HIW + "Master Li Mao-Ching smiles happily.\n" + NORM, 
    });

    casual_mchannels = ({
        "Sleep.\n",
    });


    scared_emotes = ({
        HIW + "Master Li Mao-Ching focuses intently.\n" + NORM, 
    });
    
    scared_mchannels = ({
        "Hmm.\n",
    });


    death_emotes = ({
        HIW + "Master Li Mao-Ching is defeated!\n" + NORM, 
    });

    death_mchannels = ({
        "I will be back.\n",
    });


    shit_throw_emotes = ({
        HIW + "Master Li Mao-Ching laughs at you!\n" + NORM, 
        HIW + "Master Li Mao-Ching grins evilly.\n" + NORM, 
    });
    
    shit_throw_mchannels = ({
        "Ahh! Shit... stink!\n",
    });

    
    balloon_throw_emotes = ({
        HIW + "Master Li Mao-Ching makes a funny face and grins evilly.\n" + NORM, 
    });

    balloon_throw_mchannels = ({
        "Hah hah! Funny!\n",
    });


    arrival_emotes =({
        HIW + "Master Li Mao-Ching appears suddenly out of nowhere.\n" + NORM, 
    });

    arrival_mchannels =({
        "Hello! Have you all eaten?\n",
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

        if(1 == random(2)) 
            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        if(1 == random(2)) 
            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);
    }
}



/* eof */
