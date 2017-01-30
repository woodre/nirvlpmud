inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object kukhri, gold, heals, radio;
    ::reset(arg);
    if (arg) return;

    /* standard game lib stuff */
    set_name("Dipprasad Rai");
    set_race("gurkha");
    set_alias("rifleman");
    set_alt_name("dipprasad");
    set_short(HIW + "Rifleman Dipprasad Rai" + NORM + " (of the " + HIR + "Royal Gurkha Rifles" + NORM + ")");
    set_long("    Standing a full five feet, two inches tall Rifleman Dipprasad Rai of\n"+
             "  the Royal Gurkha Rifles. His intense black eyes seem to have an iron grip\n"+
             "  your ill-prepared soul. Dipprasad is a Gurkha. If you don't know what a\n"+
             "  Gurkha is, you had best run away first, and if you survive the encounter do\n"+
             "  some reading up. Those who do know what a Ghurka is have most likely run away\n"+
             "  quite some distance by now. Short of the Overpowerlord, there is nothing else\n"+
             "  more doggedly fearsome lurking in the confines of this maze.\n");
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
    gold->set_money(100000);
    move_object(gold, this_object());

    radio = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(radio, this_object());

    heals = clone_object("players/mizan/etheriel/items/backpack");
    move_object(heals, this_object());

    kukhri = clone_object("players/mizan/opl/beasties/hard/gurkha/kukhri.c");
    move_object(kukhri, this_object());

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

    set_chance_of(CHANCE_CORPSE_LOOTING, 5);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 10);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 2);
    set_chance_of(CHANCE_EMOTE_PANICKED, 2);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 2);
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
        query_name() + " says: That was not wise.\n",
        query_name() + " says: Are you looking for a fight, sir?\n",
        query_name() + " says: You had best bring more friends. I am afraid you are outmatched.\n",
        query_name() + " says: It is better to die than be a coward. Are you ready for death, sirs?\n",
        query_name() + "'s eyes light up in giddiness.\nYou have no idea how happy it truly makes a Gurkha to be facing combat.\n",
        query_name() + " is overcome with joy. He says: 'It is now time to FIGHT!'\n",
        "Your inner voice tells you that you might not be prepared for this fight.\n",
        "You feel uneasy and unsettled. Don't worry, it's just fear.\n",
        "You are not sure that if fighting a Gurkha is a very good idea.\n",
    });

    attacked_mchannels = ( {
        "Someone is attacking me.\n",
        "Someone is looking to be beaten until morale improves.\n",
        "I will gladly oblige in combat.\n",
        "This is the sort of thing that I dream of regularly... combat.\n",
    });


    panicked_emotes = ( {
        query_name() + "blinks.\n",
    });

    panicked_mchannels = ( {
        "Hmm. I was not expecting that.\n",
        "Hmm...\n",
    });


    hit_hard_emotes = ( {
        query_name() + " says: That's the fighting spirit!\n",
        query_name() + " says: You'll have to hit me much harder than that!\n",
        query_name() + " says: Yes! Now you're showing some guts!\n",
        query_name() + " says: Maa chikney! Now that's some real fight!\n",
        query_name() + " says: Bandar ko chaaak... That was a good hit!\n",
        query_name() + " cheers wildly and almost seems energized by the violence.\n",
        "It worries you greatly that such a physically small man can be so strong.\n",
        "If you live to see victory in this battle, it shall be epic.\n...because you will have beaten one of the legendary GURKHAS in combat.\n",
    });


    hit_hard_mchannels = ( {
        "Finally! This one is showing some guts!\n",
        "Let's do it!\n",
        "This one is really making the fight worthwhile!\n",
        "The tone of this music is loud and bloody. I love it.\n",
        "There is nothing more enjoyable to be in combat with a worthy foe.\n",
    });


    taunting_emotes = ( {
        query_name() + " smiles and says: I think it is time to fight!\n",
        "You should be pretty nervous right about now.\n",
    });

    taunting_mchannels = ( {
        "Ha ha!!\n",
        "Is it time for drinking?\n",
    });


    triumph_emotes = ( {
        query_name() + " exclaims: That is what Gurkhas do best. Kill anyone else in their way.\n",
        query_name() + " exclaims: We are Gurkha. We are legion.\n",
    });

    triumph_mchannels = ( {
        "Victory!\n",
        "I love it when a plan comes together.\n",
    });


    casual_emotes = ( {
        query_name() + " blinks.\n",
        query_name() + " smiles at you.\n",
    });

    casual_mchannels = ( {
        "Hello.\n",
        "I am thirsty. I think it's time for another beer.\n",
        "Boredom. No combat...\n",
    });


    scared_emotes = ( {
        query_name() + " does not show fear, but is somewhat confounded.\n",
    });

    scared_mchannels = ( {
        "...\n",
    });


    death_emotes = ( {
        query_name() + " says: Congratulations. You have beaten me...\n" + query_name() + " then crumples to the ground.\n",
    });

    death_mchannels = ( {
        "I have been beaten.\n",
    });


    shit_throw_emotes = ( {
        query_name() + " says: This is just far too funny...\n",
    });

    shit_throw_mchannels = ( {
        "Poop! Poop! Poop!\n",
    });


    balloon_throw_emotes = ( {
        query_name() + " says: Sorry... but I can't pass up this sort of fun!\n",
    });

    balloon_throw_mchannels = ( {
        "Werra! Werra! Werra!\n",
    });


    arrival_emotes =( {
        query_name() + " smiles at you.\n",
        query_name() + " says: Namaste, friend.\n",
    });

    arrival_mchannels =( {
        "I'm here to deliver some beatings until morale improves!\n",
    });

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
