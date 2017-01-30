inherit "/players/mizan/mbv3/monsterplus.c";
#include "/players/mizan/mbv3/definitions.h"

#define STATS_DM       "/players/mizan/opl/daemons/statsDM.c"

string monster_name;
string monster_alias;

fellow_monster() {
    return 0;
}
is_fellow_monster() {
    return 0;
}
make_random_shortdesc()
{
    string result;

    result = ( {
        "thief",
        "code thief",
        "pedo-fiyle",
        "pedophile",
        "pee doe file",
        "prison bitch",
        "general wanker",
        "loser",
        "donkey drinker",
        "fizz guzzler",
        "cream sucker",
        "cheese fondler",
        "monkey spanker",
        "crank spanker",
        "stalky-stalky!",
        "asshole",
    });
    return " (" + result[random(sizeof(result))] + ")";
}

reset(arg)
{
    object what, what2, what3, gold;
    ::reset(arg);
    if (arg) return;

    if (1 == random(2))
    {
        monster_name = "Reflex";
        monster_alias = "reflex";
    }
    else
    {
        monster_name = "Xelfer";
        monster_alias = "xelfer";
    }


    /* standard game lib stuff */
    set_name(monster_name);
    set_race("human");
    set_alias(monster_alias);

    set_short(monster_name + make_random_shortdesc());
    set_long("With a unhealthily slobbering laugh, " + capitalize(monster_alias)  +" likes to make his\n"+
             "presence known. He is a pudgy, bearded, squinty eyed idiot that bears the\n"+
             "uncanny resemblance to Hans Moleman's and some fat native of the American\n"+
             "Pacific Northwest sasquatch's love child. \n"+
             "\n"+
             "He has an extraordinary amount of sneakiness, loathing, and treachery that\n" +
             "makes him somewhat of a nuisance to deal with. He like to steal things and\n" +
             "claim credit for them as his own. He likes to talk a lot of smack, inflating\n"+
             "his own stature at the expense of others. He likes to think of himself as\n"+
             "a grand creator of things but unfortunately has the imaginative prowess of\n" +
             "a bag of wet socks, and the work ethic of a hot pile of shit on a shingle.\n\n"+

             "His main claim to fame is stealing a copy of Nirvana's MUD code and setting\n"+
             "up a derived server with the assistance of another equally repugnant assloaf.\n"+

             "\nPlease kill this mantrain operator. Do the MUD proud!\n");


    if (!what) what = move_object(clone_object("/players/mizan/mbv2/items/tfdkey.c"), this_object());
    if (!what2) what2 = move_object(clone_object("/players/mizan/mbv2/items/tfdbox.c"), this_object());
    if (!what3) what3 = move_object(clone_object("/players/mizan/mbv2/items/tfdlicense.c"), this_object());

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_easy());
    move_object(gold,this_object());

    set_level(STATS_DM->get_level_easy());

    /* we use raw numbers because i overrode set_hp() */
    max_hp = STATS_DM->get_hp_easy();
    hit_point = max_hp;

    set_hp_bonus(STATS_DM->get_hp_bonus_easy());
    set_heal(15, 1);

    set_al(-999);
    set_wc(STATS_DM->get_wc_easy());
    set_ac(STATS_DM->get_ac_easy());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 1;

    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);

    load_chat(monster_name + " says: I am a super duper coder man. I can code anything!\n");
    load_chat(monster_name + " picks his nose.\n");
    load_chat(monster_name + " carefully stores some snot into his scruffy brown beard.\n");
    load_chat(monster_name + " scratches his buttcrack. HARD.\nYou are sickened at the sight of it.\n");
    load_chat(monster_name + " scratches himself.\n");
    load_chat(monster_name + " picks his ear with a corncob.\n");
    load_chat(monster_name + " licks his greasy palms.\nYou are confused by this socially inept behavior.\n");
    load_chat(monster_name + " exclaims: BAH! BAH! You are a cock! I flip you! I FLIP YOU!\n");
    load_chat(monster_name + " says: I am the best at everything.\n");
    load_chat(monster_name + " says: I have the FASTEST computer. Sorry. You are WRONG!\n");
    load_chat(monster_name + " says: I HAVE A PENTIUM THREE PROCESSOR! YOU ARE WRONG!\n");
    load_chat(monster_name + " says: My computer has more RAM than yours.\n");
    load_chat(monster_name + " says: I don't just deliver pizzas, i take them for a... silver... ride.\n");
    load_chat(monster_name + " says: I am running Windows NT 4.0. That makes me a fucking MAN!\n");
    load_chat(monster_name + " exclaims: SHUT UP ALL OF YOU! I KNOW WHAT I AM DOING! \n");
    load_chat(monster_name + " snickers.\n");
    load_chat(monster_name + " pokes himself in the anal.\n");
    load_chat(monster_name + " exclaims: No you are sooooooo... wrong.\n");
    load_chat(monster_name + " exclaims: I am WIN!\n");
    load_chat(monster_name + " exclaims: I will cast magic missile and cut off your genitals!\n");
    load_chat(monster_name + " asks: Do you know of any ugly women who need USA visas?\n" + monster_name + " says: I don't care how ugly and dumpy they are. As long as they are ASIANS!\n");
    load_chat(monster_name + " exclaims: Sailor Moon rocks my Underoos.\n");
    load_chat(monster_name + " gurgles loudly.\n");
    load_chat(monster_name + " squints at your crotch.\n");
    load_chat(monster_name + " says: You are all wrong, people. I am so... soooooo right.\n");
    load_chat(monster_name + " exclaims: I am a MUD MASTOR! MASTOR MUDDOR!\n");
    load_chat(monster_name + " suddenly rubs his crotch vigorously, but just as suddenly stops.\n");
    load_chat(monster_name + " throws a penny at you.\n");

    load_chat(monster_name + " says: My penis tells me to MURDER!\n");
    load_chat(monster_name + " says: I need to find some impressionable young bimbo to brainwash.\n");
    load_chat(monster_name + " says: I need to find some young idiot people to impress with my masterlike ways!\n");

    load_chat(monster_name + " exclaims: I like little boys in tight underwear!\n");
    load_chat(monster_name + " exclaims: I am a leet haxor!\n");
    load_chat(monster_name + " exclaims: I can think in hexadecimal and YOU CAN'T!\n");
    load_chat(monster_name + " says: My underwear never gets runny!\n");
    load_chat(monster_name + " says: I found something in my butt! Isn't that EXCITING!\n");
    load_chat(monster_name + " asks: Can i poke you in the anal?\n");
    load_chat(monster_name + " exclaims: I AM THE KING OF NIRVANA!\n");

    load_chat(monster_name + " exclaims: I STOLE A COPY OF NIRVANA'S LIB CODE!\n");
    load_chat(monster_name + " exclaims: I STOLE MUD FROM BOLTAR! BAHAHA!\n");
    load_chat(monster_name + " says: Damn! I have no idea how to code this MUD driver...\n");
    load_chat(monster_name + " cries: I HAVE A COPY OF NIRVANA AND NOBODY CAN DO ANYTHING ABOUT IT!\n");
    load_chat(monster_name + " says: Do you know i stole a copy of Nirvana's lib code??\n");
    load_chat(monster_name + " says: I stole Nirvana's code but left most of the code intact!! HAHAHA!\n");


    /* our rate of healing... 3 hp, every 2 hb */
    set_heal(30,8);


    /* This is needed (a hack) to tell the monsterplus code that we are
     * properly initalized, able to roam and operate. Mandatory. Don't remove. */
    is_loaded = 1;

    /*
     * These are on-off toggle switches. You may toggle them on/off at any time after
     * the monster is cloned. All behavior is dynamic. Have fun :)
     *
     */

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);                 /* This should be left on. The monster spams the channels
                                              less this way. NOTE that in the future, severity levels will be
                                              available. */

    toggle_off(MODE_SPARING_NEWBIES);      /* If enabled, the monster does not harrass L5 and under players directly */
    toggle_on(MODE_BALLOON_THROWER);       /* if the monster throws balloons at people */
    toggle_on(MODE_SHIT_THROWER);          /* If the monster throws shit at people */
    toggle_off(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    toggle_off(MODE_KID_KILLER);           /* if the monster will attack kids spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PET_KILLER);           /* if the monster will attack pets spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PK_INSTIGATOR);        /* if the monster will attack PK players spontaneously, but honors no-fight rooms. */
    toggle_off(MODE_USE_REMOTE_WAYPOINTS); /* Enable this if you want the monster be hermitlike,
                                              and not wander in the main village spine. It instead
                                              stays in the perimeter (like south forest) rooms as waypoints. */
    toggle_on(MODE_CORPSE_EATER);         /* If the monster consumes corpses whole instead of just
                                              taking them (emotes taken from Boltar's hoth monster.
                                              Used in conjunction with its chance of consuming corpses. */
    toggle_on(MODE_SLOW_HITFADES);        /* If the monster sticks around for a longer period
                                              while running hit/fade attacks. Typically monsters only
                                              try to get 3/6 attacks in. This extends to about 15/20. */

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 60);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 40);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 50);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 30);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 1);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 1);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(1);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Outcast");              /* This is almost archaic. i dont know what i am going to do with it. */

    /* some notes along the way...
     *
     * Monsters that have a guild level 1 will not automatically heal. They need to be L2 to do that.
     *
     * The monster guild rank is archaic in a way, but i will keep it for now.
     * Most likely it will be the only attribute the players will see in respect to ranking.
     *
     *
     *
     */

    set_string(STR_TEAM_NAME, "CmdrAssium");    /* The name of the team the monster is on. Team names take more precedence */
    set_string(STR_CABAL_NAME, "Goatse");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


    /* These are all set to a per 100 round setting. If a chance is '1', it means that
    * the event will have the odds of 1 in 100 rounds of happening. Same as the core monster
    * chat capabilites in monster.c
    *
    */
    set_chance_of(CHANCE_CORPSE_LOOTING, 55);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 75);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 30);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 30);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 30);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 20);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 50);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 99);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 10000);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 3000);             /* The amount of maximum heals the monster can draw from the nexus */
    set_int(VAL_HUNTING_THRESHOLD, 10);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 4);       /* How many callouts before the monster decides to move randomly */

    /* lots of channel and emote stuff */

    /* these should be self-explanatory... a variety of emotes when the monster is
     * under certain emotional conditions. */
    /* The arrays can be any size and do not have to be equal sized in pairs. For example
     * the _emotes array might have 5 elements, but does not mean that _mchannels needs 5 too.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */

    attacked_emotes = ( {
        monster_name + " cries: DO YOU KNOW THAT I AM A GOD ON MY MUD?!!!\n",
        monster_name + " consults his stolen copy of the Nirvana mudlib for help\n",
        monster_name + " cries: I AM A MASTOR! DO NOT MESS WITH A MASTOR!!!\n",
        monster_name + " flashes his junior sized genital package at you.\n",
        monster_name + " screams: DO YOU KNOW WHO YOU ARE MESSING WITH???\n",
        monster_name + " begs for mercy!\n",
        monster_name + " pleads: Please stop hitting me, i can't fight you!\n",
        monster_name + " pleads: I'm a lover, not a fighter! Please stop!\n",
        monster_name + " cries: I surrender! Uncle! UNCLE! UNCLE! PLEASE STOP!!\n",
        monster_name + " cries: MOMMY oh my god PLEASE STOP THIS!\n",
        monster_name + " cries: WHAT IS YOUR GODDAMN PROBLEM!!!\n",
        monster_name + " screams: MY PENIS WILL BEAT YOU TO A PULP!\n",
        monster_name + " screams: This is NOT FAIR! Die! DIE!\n",
        monster_name + " cringes and screams loudly!\n",
        monster_name + " whines piteously!\n",
        monster_name + " tries to slap you in the face!\n",
        monster_name + " tries to punch you in the arm!\n",
        monster_name + " exclaims: DO YOU KNOW I THINK I CAN CODE!\n",
        monster_name + " tries to kick you in the shins!\n",
        monster_name + " cries: YOU WILL BE A DISASTER!\n",
        monster_name + " cries: ALL YOUR BASE WILL BELONG TO MY PENIS!\n",
        monster_name + " cries: MY HONEYBUNNY SLUGBITCH WILL BEAT YOUR THE UP!\n",
        monster_name + " cries: STOP!\n",
        monster_name + " cries loudly!\n",

        monster_name + " exclaims: NO! WAIT! MALEDICTA! WHERE ARE YOU GOING!!!\n",
        monster_name + " cries: NO! WAIT! DARANATH! DON'T FORSAKE ME!!!\n",
        monster_name + " cries: Moadeep... you are my only hope.\n",
        monster_name + " cries: Tril... you are my only hope.\n",
        monster_name + " cries: MALEDICTA! NO! PLEASE DONT LEAVE ME!!!\n",
        monster_name + " cries: BALOWSKI! HELP ME! HEMLPEM TEH ME!\n",
        monster_name + " cries: DARANATH! Please don't leave me now!!!\n",

        monster_name + " cries: If my PENIS was big enough i would WIELD it and SMACK YOU ACROSS THE FACE!\n",
        monster_name + " cries: DO YOU KNOW THAT I AM A MASTER OF NERF PORN!!\n",
        monster_name + " fights like a fricking sissy.\n",
        monster_name + " punches like a quadripeligic drunkard...\n",
        monster_name + "'s greasy fat-pack abdomen ripples in the wind like a pregnant yak.\n",
        monster_name + " has the fighting grace of a bloated goat corpse.\n",
        monster_name + " moves like a pregnant bumblebee, and stings like a styrofoam peanut.\n",

        "Game driver tells you: Keep fighting him, you're doing the right thing!\n",
        "Game driver tells you: A wise choice, my friend.\n",
        "Game driver tells you: Please kill " + capitalize(monster_alias) + ". He is a worthless prick.\n",
        "Game driver tells you: Awesome!\n",
        "Game driver tells you: Wombats everywhere are pleased that you attacked this '" + capitalize(monster_alias) + "' asshole.\n",
        "Game driver tells you: I would hit it! And i would hit it again!\n",
        "Game driver tells you: Right on, almost there, keep hitting him!\n",
        "Game driver tells you: Excellent. Keep fighting.\n",
        "Game driver tells you: " + capitalize(monster_name) + " is a cocksmoker. That's right, a hair-lip cocksmoker!\n",
        "Game driver tells you: ALL RIGHT! Good job! Keep killing this " + capitalize(monster_name) + " idiot!\n",
        "Game driver tells you: Keep it up! This idiot is worth a decent amount of EXP!\n",
        "Game driver tells you: THANK YOU for attacking this idiot!\n",
    });

    attacked_mchannels = ( {
        "Hey guys, why won't you help me! I'm being attacked!\n",
        "Guys... help!\n",
        "Guys... please!\n",
        "Help! Why are you ignoring me?!\n",
        "Oh no...\n",
        "I don't want to die...\n",
        "*cry*\n",
    });


    panicked_emotes = ( {
        monster_name + " bites his fingernails at hyper-speed.\n",
        monster_name + " screams and whines for help!\n",
        monster_name + " cries piteously.\n",
        monster_name + " sobs and panics, trying to 'fight' back but looking like a total... dicknose.\n",

        monster_name + " asks: Are you that 'special' Priest?\n",
        monster_name + " asks: Is it crotch touchy time already?!?!?!\n",

        monster_name + " grabs at his crotch tightly.\n" + capitalize(monster_name) + " screams: DON'T MAKE FUN OF MY WILLY!!!\n",
        monster_name + " grabs at his crotch tightly.\n" + capitalize(monster_name) + " screams: DON'T TOUCH ME THERE AGAIN MICHAEL!!!\n",
        monster_name + " grabs at his crotch tightly.\n" + capitalize(monster_name) + " screams: I DON'T WANT TO GO IN THAT BOX AGAIN MOMMY!!!\n",
        monster_name + " grabs at his crotch tightly.\n" + capitalize(monster_name) + " screams: MY ANUS IS BLEEDING AGAIN!!!\n",
        monster_name + " panics in a Richard Simmons sort of manner. How... sad.\n",
        monster_name + " screams loudly and tries to cover his crotch (for no apparent reason).\n",
        monster_name + " seems to be experiencing an impromptu bout of 'afterburner diarrhea'.\n",

        "Game driver tells you: " + capitalize(monster_name) + " is panicking! Awesome...\n",
        "Game driver tells you: HAHAHA You made him panic!\n",
        "Game driver tells you: Right on, he's panicking!\n",
        "Game driver tells you: Keep focusing, he might run away...\n",
        "Game driver tells you: Be aware that he is panicking, and might run away...\n",
    });

    panicked_mchannels = ( {
        "AAAGH!\n",
    });


    hit_hard_emotes = ( {
        monster_name + " cowers piteously from the impact!\n",
        monster_name + " sobs unconsolably.\n",

        "Game driver tells you: Brilliant... you just did a lot of damage on " + capitalize(monster_name) + ".\n",
        "Game driver tells you: Good shot!\n",
        "Game driver tells you: BOOM! Nice shot!\n",

    });

    hit_hard_mchannels = ( {
        "OW! OW! OW! That hurt!\n",
        "I was just struck painfully!\n",
        "ACK! Ow!\n",
        "That hurt severely!\n",
    });


    taunting_emotes = ( {
        monster_name + " says: I am so... rationally right.\n",
        monster_name + " exclaims: YOU ARE TERRIBLY WRONG!\n",
        monster_name + " says: You wish you could be me.\n",
        monster_name + " exclaims: SHUT UP! I AM SPEAKING!\n",
        monster_name + " exclaims: I am officially better than... YOU.\n",

        "Game driver tells you: Please kill " + capitalize(monster_name) + ".\n",
        "Game driver tells you: Are you going to let him get away with THAT?\n",
    });

    taunting_mchannels = ( {
        "Hey guys?\n",
        "Please don't ignore me...\n",
        "Hey...\n",
    });


    triumph_emotes = ( {
        monster_name + " stuffs a bean burrito into his rectum in triumph!\n",
        "Game driver tells you: Are you going to let him get away with THAT?\n",
    });

    triumph_mchannels = ( {
        "Did anyone notice that!?\n",
    });


    casual_emotes = ( {
        monster_name + " tries to impress you with his minimal knowledge of CPUs.\n",
        monster_name + " tries to impress you with his powerful Pentium III computer.\n",
        monster_name + " tries to impress you with his absolute lack of LPC coding skills.\n",
        monster_name + " tries to talk like a whigga. 'WERD!'\n",
        monster_name + " tries to impress you with a stick of 128MB PC100 memory.\n",
        monster_name + " tries to impress you with a copy of MAD Magazine.\n",
        monster_name + " tries to impress you with his stolen MUD code.\n",

        "Game driver tells you: " + capitalize(monster_name) + " is a idiot and must be exterminated.\n",
        "Game driver tells you: Hey, please kill this " + capitalize(monster_name) + " bastard... he's worth a lot of EXP...\n",
        "Game driver tells you: *nudge nudge* This " + capitalize(monster_name) + " asshole is an easy kill...\n",
        "Game driver tells you: If you're L12 or higher, you should consider killing this " + capitalize(monster_name) + " chump...\n",
        "Game driver tells you: You know you WANT to do it...\n",
        "Game driver tells you: DO it! DO it!\n",
        "Game driver tells you: Yeeees....\n",
        "Game driver tells you: Kill " + capitalize(monster_name) + " and i'll be your official friend.\n",
    });

    casual_mchannels = ( {
        "Guys?!\n",
        "Please don't ignore me...\n",
        "Hey guys...\n",
    });


    scared_emotes = ( {
        monster_name + " soils himself.\n",
        monster_name + "'s pants meets his sphincter, which in turn introduces his life partner... Used Chili.\n",
        monster_name + "'s crotch eminates a most spectacularly horrid stench.\n",
        monster_name + "'s giant pantular wet spot has a stench you are not prepared for.\n",
        monster_name + " urinates profusely. Pants however remain zippered up.\n",

        "Game driver tells you: " + monster_name + " is scared... woo!\n",
        "Game driver tells you: Kill!\n",
        "Game driver tells you: " + monster_name + " is urinating on himself again!\n",
        "Game driver tells you: Look! The sissyboy peed his pants!\n",
        "Game driver tells you: REDRUM!\n",
    });

    scared_mchannels = ( {
        "I am very scared.\n",
        "None of you are helping me...\n",
        "Help!\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ( {
        monster_name + " takes a dirt nap! Hilarity ensues!\n",
        "Game driver tells you: YES! FUCKING AWESOME JOB! THANK YOU!\n",
        "Game driver tells you: Me and the rest of the MUD... salutes you!\n",
        "Game driver tells you: EXCELLENT!\n",
        "Game driver tells you: GOOD RIDDANCE! Awesome job, whacking that buttknocker!\n",
    });

    death_mchannels = ( {
        "MOMMMMMMMY!!!!!\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ( {
        monster_name + " laughs at you!\n",
        "Game driver tells you: You know you want to kill him. He thinks he is a Beano.\n",
        "Game driver tells you: Look at this jerk. Kill him!\n",
    });

    shit_throw_mchannels = ( {
        "I'm throwing shit! I usually only TALK shit! HEHEHE.\n",
        "I'm throwing shit!!\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ( {
        monster_name + " says: THAT'S FUNNY!!!\n",
        monster_name + " says: YOU SUCK!! \n",
        "Game driver tells you: Look, this sissy cheeselicker is throwing water balloons...\n",
    });

    balloon_throw_mchannels = ( {
        "C'mon guys, i just want to throw some water balloons...\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =( {
        "TEH FAVID DLEETWOOD falls to the earth with a shrill scream!\n",
        "Game driver tells you: Oh shit, it's " + monster_name + ". Please kill him.\n",
        "Game driver tells you: " + monster_name + " needs to be shown the interior of a casket.\n",
    });

    arrival_mchannels =( {
        "AAAAAAAAAAAAAAAGH!\n",
        "Why do all of you guys hate me?\n",
    });

}

/* inside this function you can call your code to do special combat.
 * It is called when an attacker is present, and engaged in combat.
 * Have fun :)
 */
heartbeat_attack()
{
    /* beanos are boring in combat, so they don't do anything. */
}

/* eof */
