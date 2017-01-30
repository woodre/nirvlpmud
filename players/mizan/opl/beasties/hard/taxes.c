inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object gold;
    ::reset(arg);
    if (arg) return;

    /* standard game lib stuff */
    set_name("Taxes");
    set_race("tax");
    set_alias("taxes");
    set_short(HIW + "Taxes" + NORM + " (" + HIR + "The Universal Pestilence" + NORM + ")");
    set_long("    The beast of the east, the thunder from down under, the universal plague\n"+
             "  of hard-working people everywhere... taxation. Not that taxes in and of itself\n"+
             "  is a purely evil thing, but over time it grows from a healthy, idealistic\n"+
             "  creature to a fat, bloated pit of sucking. From starting off as just being\n"+
             "  a responsible system of maining roads and postal services... it turns into a\n"+
             "  vast military industrial complex designed to fool young stupid people into\n"+
             "  fighting wars for old, evil ones.\n");
    set_hp_bonus(2000);
    set_heal(25, 1);

    set_level(29);
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 18888;
    hit_point = 18888;

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 4;

    set_al(0);
    set_wc(250);
    set_ac(78);

    set_chance(15);
    set_spell_mess1(query_name() + " hits you VERY hard!\n");
    set_spell_mess2(query_name() + " hits you with a BONE SHATTERING CRUNCH!\n");
    set_spell_dam(400);

    gold = clone_object("/obj/money.c");
    gold->set_money(250000);
    move_object(gold, this_object());

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_on(MODE_KID_KILLER);
    toggle_on(MODE_PET_KILLER);
    toggle_on(MODE_PK_INSTIGATOR);
    toggle_on(MODE_COVERS_PRESENT_ALLIES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 30);
    set_attribute(ATTRIB_FEARLESSNESS, 100);
    set_attribute(ATTRIB_PERCEPTION, 70);
    set_attribute(ATTRIB_CRUELTY, 5);
    set_attribute(ATTRIB_INSANITY, 80);
    set_attribute(ATTRIB_GENEROUSITY, 90);

    set_monster_guild_level(4);
    set_monster_guild_rank("Cornerman");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 100);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 2);
    set_chance_of(CHANCE_EMOTE_PANICKED, 2);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 6);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 80);
    set_chance_of(CHANCE_EMOTE_CASUAL, 2);
    set_chance_of(CHANCE_EMOTE_SCARED, 2);
    set_chance_of(CHANCE_PELTING_THINGS, 4);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 500000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 18000);
    set_int(VAL_HUNTING_THRESHOLD, 30);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);


    /* lots of channel and emote stuff */
    attacked_emotes = ( {
        query_name() + " says: My complexity is how I defeat you.\n",
        query_name() + " says: Even now, you still submit to my will.\n",
        query_name() + " says: Those tips you collect, I should still be entitled to them.\n",
        query_name() + " says: Interest, fines, more interest, that is how I roll.\n",
        query_name() + " says: I am enforced by your legislative authority.\n",
        query_name() + " says: It's not an issue of Democrat vs. Republican. It's about rich vs. the poor.\n",
        query_name() + " says: The rich are winning. I am their tool of first strike.\n",
        query_name() + " says: I am the tip of the spear to make the rich wealthier, and the poor poorer.\n",
        query_name() + " says: It's not about liberal vs. conservative. Either way the wealthy profit.\n",
        query_name() + " says: Your paycheck. Give it to me!\n",
    });

    attacked_mchannels = ( {
        "Someone is attacking me.\n",
        "So boring.\n",
        "When will they ever learn.\n",
    });


    panicked_emotes = ( {
        query_name() + " blinks.\n",
    });

    panicked_mchannels = ( {
        "Hmm. I was not expecting that.\n",
    });


    hit_hard_emotes = ( {
        query_name() + " says: How can you expect to win? Even if I die, defeat is temporary.\n",
        query_name() + " says: You hit me rather hard, but I hit you just as hard in the paycheck.\n",
        query_name() + " says: One day, you will learn that I am your master.\n",
        query_name() + " says: You hit me almost as hard as I hit you in the balance sheet.\n",
        query_name() + " says: So? You hit me. But I will still own you.\n",
    });


    hit_hard_mchannels = ( {
        "When will they ever learn?\n",
        "Even if I am defeated here it is temporary. They still pay my tributes offline.\n",
        "They try. I'll give them that.\n",
    });


    taunting_emotes = ( {
        query_name() + " says: I will squeeze you dry.\n",
        query_name() + " says: I will vanquish your bank account, garnish your wages...\n",
        query_name() + " says: I will drain you for every penny you are worth. Plus interest.\n",
    });

    taunting_mchannels = ( {
        "They are weak.\n",
        "I will beat them into submission one penny at a time.\n",
    });


    triumph_emotes = ( {
        query_name() + " exclaims: The tax code is victorious today.\n",
    });

    triumph_mchannels = ( {
        "Victory. That is to be expected.\n",
    });


    casual_emotes = ( {
        query_name() + " says: Pay me. Now.\n",
    });

    casual_mchannels = ( {
        "Awaiting payment...\n",
    });


    scared_emotes = ( {
        query_name() + " says: Fascinating.\n",
    });

    scared_mchannels = ( {
        "...\n",
    });


    death_emotes = ( {
        query_name() + " says: You have beaten me \n" + query_name() + ", but it is temporary...\n",
    });

    death_mchannels = ( {
        "I have been beaten.\n",
    });


    shit_throw_emotes = ( {
        query_name() + " says: Bobba.\n",
    });

    shit_throw_mchannels = ( {
        "Look at them, all dirty and nasty.\n",
    });


    balloon_throw_emotes = ( {
        query_name() + " says: If only this were fines and late fees...\n",
    });

    balloon_throw_mchannels = ( {
        "Pathetic humans.\n",
    });


    arrival_emotes =( {
        query_name() + " says: I am here to collect. Give me your money.\n",
        query_name() + " says: That's right. Just throw the money my way.\n",
    });

    arrival_mchannels =( {
        "I'm here to collect my tributes. Yes, yes.\n",
    });

}


heartbeat_attack()
{
    object attacker;
    object wealthiest;
    object room;

    /* Setup some vars */
    room = environment(this_object());
    attacker = this_object()->query_attack();
    wealthiest = get_wealthiest_player_present(this_object());

    if(1 == random(3) && wealthiest && attacker != wealthiest && room)
    {
        tell_room(room, query_name() + " senses " + HIY + "WEALTH and RICHES" + NORM + " in " + wealthiest->query_name() + "...\n");
        tell_room(room, HIY + query_name() + " turns to attack " + wealthiest->query_name() + NORM + "!\n");
        this_object()->attack_object(wealthiest);
    }

}

/* Called when the monster dies */
death(string str)
{
    string result;

    say(HIY + " >>> > > C O N G R A T U L A T I O N S ! ! ! < < <<<" + NORM + "\n");
    say(HIY + " >>> > > C O N G R A T U L A T I O N S ! ! ! < < <<<" + NORM + "\n");

    say(HIY + "  You have defeated a boss in hand to hand combat!" + NORM + "\n");
    say(HIY + "  Unfortunately your target is in another corner..."  + NORM + "\n");
    say(HIY + "  Venture forth and seek out OverPowerLord. Good luck!"  + NORM + "\n");

/*
    result = HIY + "\n" + format("(junk) A Level Boss has been DEFEATED!", 76) + NORM + "\n";

    chan_msg(result);
    emit_channel("junk", result);
*/

    ::death(str);
}


/* eof */
