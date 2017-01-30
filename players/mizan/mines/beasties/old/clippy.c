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
    set_name("Clippy");
    set_alias("clippy");
    set_race("paperclip");
    set_short(HIW + "Clippy, the Microsoft Office Assistant " + NORM + "(evil)");
    set_long("This is the evil and insidious paperclip that used to be employed by the\n"+
             "one and only Microsoft Corporation. Clippy used to have a job as the default\n"+
             "Microsoft Office Assistant, but since having been uncerimoniously dumped he\n"+
             "has become more erratic and evil since. Tread carefully, stranger.\n"+
             "Clippy has a tattoo reading: Monster's Guild.\n");

    set_level(17);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 255;
    hit_point = 255;

    set_al(-960);
    set_wc(50);
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
    toggle_on(MODE_FIREWORKS_THROWER);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 60);
    set_attribute(ATTRIB_FEARLESSNESS, 40);
    set_attribute(ATTRIB_PERCEPTION, 40);
    set_attribute(ATTRIB_CRUELTY, 98);
    set_attribute(ATTRIB_INSANITY, 80);
    set_attribute(ATTRIB_GENEROUSITY, 10);

    set_monster_guild_level(2);
    set_monster_guild_rank("Black Pawn");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 100);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 7);
    set_chance_of(CHANCE_EMOTE_PANICKED, 7);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 7);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 7);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 7);
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 20000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 2300);
	set_int(VAL_HUNTING_THRESHOLD, 18);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 7);


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        HIW + "Clippy says: It looks like you are starting your own funeral! Would you like help with this feature?\n" + NORM,
        HIW + "Clippy says: It looks like you are writing a suicide note! Would you like help with this feature?\n" + NORM,
        HIW + "Clippy says: Would you like to search for some files, asshole?\n" + NORM,
        HIW + "Clippy says: Would you like to quit out of the game, idiot?\n" + NORM,
        HIW + "Clippy says: At least i'm not a sock puppet, dickhead!\n" + NORM,
        HIW + "Clippy says: Beware of the wrath of Gates!\n" + NORM,
        HIW + "Clippy says: It looks like you are about to die! Would you like to make funeral arrangements!\n" + NORM,
        HIW + "Clippy says: Would you like another word for 'thesaurus'?\n" + NORM,
        HIW + "Clippy says: Hi! It appears as if you are a total retard!\n" + NORM,
    });

	attacked_mchannels = ({
        "It looks like someone is starting a suicide note!\n",
        "What's another word for thesaurus damnit!\n",
        "Oh holy crap I am in combat.\n",
        "Yaargh... fight club time.\n",
	});


    panicked_emotes = ({
        HIW + "Clippy says: Mother of Fuck! This sucks!\n" + NORM,
        HIW + "Clippy says: Crap! What the hell!\n" + NORM,
        HIW + "Clippy says: Uh...\n" + NORM,
    });

	panicked_mchannels = ({
        "Oh damn.\n",
        "Uhh...\n",
        "What in the Zidane is going on here!?\n",
	});

    
    hit_hard_emotes = ({
        HIW + "Clippy says: HOLY CRAP that hurt...\n" + NORM,
        HIW + "Clippy says: Gates is gonna mess you up!\n" + NORM,
        HIW + "Clippy says: Ow! Ow! Ow!\n" + NORM,
    });

    hit_hard_mchannels = ({
        "Holy CRAP that is hurtage!\n",
        "Someone get some pliers, I need to be UNBENT!\n",
        "OUCH! Damn fo-shizzle this is teh hurt!\n",
    });


    taunting_emotes = ({
        HIW + "Clippy says: It appears that you are a moron. Would you like to contact Microsoft Technical Support?\n" + NORM,
        HIW + "Clippy says: Perhaps you should try 'File/Save As', you simpleton!\n" + NORM,
        HIW + "Clippy says: You wouldn't have lost that file if you hadn't saved frequently, you ape!\n" + NORM,
        HIW + "Clippy says: Would you like to open a Microsoft SRX Support Incident?\n" + NORM,
    });

    taunting_mchannels = ({
        "You cannot break my unstoppable body of wire!\n",
        "Yeeehah! Microsoft Office represent!\n",
        "Here's to a hog tied player death!\n",
    });


    triumph_emotes = ({
        HIW + "Clippy says: Would you like to have a tall glass of SHUT THE FUCK UP?\n" + NORM,
        HIW + "Clippy says: It appears you have no balls. Would you like a bowl of hot grits?\n" + NORM,
        HIW + "Clippy says: How about some help from Microsoft Technical Support to not be such an IDIOT!\n" + NORM,
    });

    triumph_mchannels = ({
        "Perhaps someone needs to call Microsoft Technical Support soon!\n",
        "Bahaha!\n",
    });


    casual_emotes = ({
        HIW + "Clippy says: Would you like help writing a letter?\n" + NORM,
        HIW + "Clippy says: Would you like some assistance in writing your resume?\n" + NORM,
        HIW + "Clippy says: Would you like to contact Microsoft Technical Support?\n" + NORM,
        HIW + "Clippy says: I would be happy to assist you in writing a letter!\n" + NORM,
        HIW + "Clippy says: It appears you are starting a letter! Would you like assistance in using this feature?\n" + NORM,
    });

    casual_mchannels = ({
        "Human harrassment time...\n",
        "Upgrade to Office 2000! Even if you have something newer! Because I am in it!\n",
        "Would you like some help writing a letter?\n",
    });


    scared_emotes = ({
        HIW + "Clippy exclaims: Oh crap! I could use some Microsoft Technical Support right about fucking NOW!\n" + NORM,
        HIW + "Clippy exclaims: Who wants to sing!?\n" + NORM,
        HIW + "Clippy exclaims: BillG! Help my sorry ass!\n" + NORM,
    });
    
    scared_mchannels = ({
        "BillG! Help me!\n",
        "Oh no! Help!\n",
        "Crap! Help!\n",
    });


    death_emotes = ({
        HIW + "Clippy falls to the ground, bent out of shape, and dead.\n" + NORM,
    });

    death_mchannels = ({
        "Damnit. I died...\n",
    });


    shit_throw_emotes = ({
        HIW + "Clippy says: You appear to be covered in shit! Would you like to buy a towel?\n" + NORM,
        HIW + "Clippy says: You appear to smell like a cowpie! Would you like to buy a zebra?\n" + NORM,
    });
    
    shit_throw_mchannels = ({
        "Shit piles rule!\n",
    });

    
    balloon_throw_emotes = ({
        HIW + "Clippy says: You appear to be soaking wet! Would you like to buy a roll of paper towels?\n" + NORM,
        HIW + "Clippy says: You appear to be soaking wet! Would you like bag of popcorn?\n" + NORM,
    });

    balloon_throw_mchannels = ({
        "Bahahaha! Water balloon sput in face... hehehe\n",
    });


    arrival_emotes =({
        HIW + "Clippy arrives from WIN32-land.\n" + NORM,
    });

    arrival_mchannels =({
        "Woohah. It's time to annoy some players!\n",
    });


}




/* eof */
