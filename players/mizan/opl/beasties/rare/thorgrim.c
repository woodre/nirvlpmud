inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

#define STATS_DM       "/players/mizan/opl/daemons/statsDM.c"

int crazy_hunt;

reset(arg)
{
    object weapon, armor, heals, radio, gold;
    ::reset(arg);
    if(arg) return;

    crazy_hunt = 0;

    /* standard game lib stuff */
    set_name("Thorgrim Beano");
    set_race("beano");
    set_alias("thorgrim");
    set_short(HIK + HBGRN + "Thorgrim" + NORM + NORM + " Beano");
    set_long("This is the largest Beano you have seen yet. Closing in at just\n"+
        "under seven feet tall, Thorgrim is truly a king-sized version of creatures\n"+
        "that normally do not surpass two feet or so. His silicon-based body makes\n"+
        "his muscle mass denser than your puny human flesh, and he probably weighs\n"+
        "in somewhere in the one thousand kilogram range. Thorgrim is also dressed\n"+
        "and armed in a Viking fashion, which is suitable given his size and\n"+
        "imposing presence, but he seems to be a generally amicable and approachable\n"+
        "creature. You notice he seems very protective of lower level creatures\n"+
        "around him and is very concious about not bumping into anyone with his bulk.\n"+
        "You also notice that he is a " + HIW + "little mentally not valid" + NORM + ", since he is a Beano\n"+
        "that thinks he is some kind of a Viking. Who is going to argue with him though?\n"+
        "Thorgrim has a tattoo reading: Monster's Guild.\n");
    set_level(STATS_DM->get_level_hard());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_hard() * 2;
    hit_point = max_hp;

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 3;

    set_al(865);
    set_wc(STATS_DM->get_wc_hard());
    set_ac(STATS_DM->get_ac_hard());
    set_chance(10);
    
    set_spell_dam(140);
    set_spell_mess1("With a Viking yell, Thorgrim Beano appears rejuvenated!");
    set_spell_mess2("Thorgrim Beano focuses his next shot carefully.");
    set_chat_chance(2);
    
    set_hp_bonus(STATS_DM->get_hp_bonus_hard());
    set_heal(20,1);    
    
    load_chat("Thorgrim Beano quibbles silently.\n");
    load_chat("Thorgrim Beano goes: GWAK.\n");
    load_chat("Thorgrim Beano goes: WOOT.\n");
    load_chat("Thorgrim Beano does something.\n");
    
    weapon = clone_object("players/mizan/etheriel/items/thorgrim-hammer.c");
    move_object(weapon, this_object());

    radio = clone_object("players/mizan/mbv3/items/walkie-talkie.c");
    move_object(radio, this_object());

    heals = clone_object("players/mizan/etheriel/items/thorgrim-pouch.c");
    move_object(heals, this_object());
    
    armor = clone_object("players/mizan/etheriel/items/thorgrim-helmet.c");
    move_object(armor, this_object());

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_hard());
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
    toggle_on(MODE_COVERS_PRESENT_ALLIES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);
    set_attribute(ATTRIB_FEARLESSNESS, 100);
    set_attribute(ATTRIB_PERCEPTION, 65);
    set_attribute(ATTRIB_CRUELTY, 10);
    set_attribute(ATTRIB_INSANITY, 60);
    set_attribute(ATTRIB_GENEROUSITY, 80);

    set_monster_guild_level(3);
    set_monster_guild_rank("White Rook");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 25);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 10);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 10);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 10);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 60000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 10500);
    set_int(VAL_HUNTING_THRESHOLD, 45);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 8);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Thorgrim Beano grobbles loudly!\n",
        "Thorgrim Beano goes: GRONK!\n",
        "Thorgrim Beano squits itself against you angrily.\n",
        "Thorgrim Beano adjusts his stance.\n",
    });

	attacked_mchannels = ({
		"I am under attack. Buh.\n",
        "Someone is attacking me. They are crazy.\n",
        "Someone needs to be taught a lesson.\n",
        "I wonder if i should beat this creature down soundly or just kill them.\n",
        "Hmm. Fascinating.\n",
	});


    panicked_emotes = ({
        "Thorgrim Beano blinks loudly.\n",
        "Thorgrim Beano goes: Buh!\n",
        "Thorgrim Beano appears to be somewhat annoyed.\n",
    });

	panicked_mchannels = ({
		"Urrrrrr!\n",
        "Hmm.\n",
        "That was not cool.\n",
	});

    
    hit_hard_emotes = ({
        "Thorgrim Beano shakes off the hard hit.\n",
        "Thorgrim Beano goes: HAHAHA!\n",
        "Thorgrim Beano exclaims: That's the spirit!\n",
        "Thorgrim Beano exclaims: Yes! Fight like a man! Allright!\n",
    });

    hit_hard_mchannels = ({
        "Oof! That hurt somewhat!\n",
        "Hey that actually kind of hit hard! grrrr...\n",
        "Ouch. Okay, need to focus shots more.\n",
    });


    taunting_emotes = ({
        "Thorgrim Beano looks at you.\n",
        "Thorgrim Beano grins biggly.\n",
    });

    taunting_mchannels = ({
        "I think its time to call out the Fat Lady.\n",
        "Wagner time!\n",
        "Blunt head beatdown time!.\n",
        "I really could use some beer.\n",
    });


    triumph_emotes = ({
        "Thorgrim Beano goes: WOOT! BUH!\n",
        "Thorgrim Beano exclaims: AHA! By the stars I am victorious!\n",
        "Thorgrim Beano exclaims: By Valhalla I will be victorious!\n",
        "Thorgrim Beano grins heartily.\n",
    });

    triumph_mchannels = ({
        "I triumph! I win! Yes!\n",
        "Yeah! Once again my hammer has crushed an evildoer!\n",
        "Death becomes those who challenge the righteous!\n",
        "Destruction, mayhem, chaos, all in the name of good!\n",
    });


    casual_emotes = ({
        "Thorgrim Beano grobbles happily.\n",
        "Thorgrim Beano goes: mmmmrug.\n",
        "Thorgrim Beano says: Hello!\n",
        "Thorgrim Beano says: Howdys!\n",
        "Thorgrim Beano says: Good day to you.\n",
        "Thorgrim Beano says: Hello everyone!\n",
        "Thorgrim Beano says: It's a beautiful day out.\n",
        "Thorgrim Beano says: You look excellent!\n",
        "Thorgrim Beano says: Excuse me.\n",
        "Thorgrim Beano smiles happily.\n",
        "Thorgrim Beano says: I apologize for the shit-flinging Beanos.\n",
        "Thorgrim Beano says: The shit-flinging Beanos are... rather simple minded.\n",
        "Thorgrim Beano says: Hey HEY!\n",
    });

    casual_mchannels = ({
        "Whee!\n",
        "Woot...\n",
        "Nog nog nog!\n",
        "This MUD needs more newbies.\n",
        "Look!\n",
    });


    scared_emotes = ({
        "Thorgrim Beano appears somewhat agitated.\n",
        "Thorgrim Beano appears somewhat nervous.\n",
        "Thorgrim Beano goes: hwarf.\n",
    });
    
    scared_mchannels = ({
        "I am somewhat nervous.\n",
        "Hmm.\n",
        "Damn!\n",
    });


    death_emotes = ({
        "Thorgrim Beano does not enjoy dying.\n",
        "Thorgrim Beano is not happy.\n",
        "Thorgrim Beano appears angry.\n",
    });

    death_mchannels = ({
        "Curses! I died! Ack!\n",
        "I'll be back... Grr.\n",
        "Doh... I died, but I am not ready for Valhalla just yet!\n",
        "I SHALL RETURN!\n",
    });


    shit_throw_emotes = ({
        "Thorgrim Beano grins greasily.\n",
        "Thorgrim Beano cackles biggly!\n",
    });
    
    shit_throw_mchannels = ({
        "Fecal humor while base... is till humor... FUNNY!\n",
        "Splat. You've got shit!\n",
    });

    
    balloon_throw_emotes = ({
        "Thorgrim Beano makes a funny face at you.\n",
        "Thorgrim Beano grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Hee. Water balloons are too fun.\n",
    });


    arrival_emotes =({
        "Thorgrim Beano is here!\n",
        "Thorgrim Beano is here! Woot!\n",
    });

    arrival_mchannels =({
        "7 foot, 1 inches, 1740 lbs. Thorgrim Beano has a posse.\n",
        "I am here! RAAR!\n",
        "Midgard! My presence shall save you! Okay, maybe just some of you!\n",
    });

}



/* eof */
