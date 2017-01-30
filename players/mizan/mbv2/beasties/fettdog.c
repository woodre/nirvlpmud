inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/ansi.h"

reset(arg)
{
    object what, ammo, bag;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Fettdog");
    set_race("monkey");
    set_alias("fettdog");
    set_short("A monkey named Fettdog (devious)");
    set_long("Behold... you stand before the glorious creatures that is the one and\n" +
    "only Fettdog! He is a lean, wiry monkey of cartoonish origins that exhudes\n" +
    "swagger and absolute hatred of the human race. Cunning, crafty, and not above\n" +
    "using any method to get the job done, Fettdog is not your ordinary monster\n"+
    "so don't expect him to fight like one. Consider yourself " + HIR + "SEVERELY" + NORM + " warned.\n\n" +
    "Fettdog appears to be the newphew of the almighty Mojo Jojo.\n"+
    "Fettdog has a tattoo reading: Monster's Guild.\n");

    set_level(19);
    set_ep(3750000);

    /* we use raw numbers because i overrode set_hp() */
    max_hp = 275;
    hit_point = 275;

    set_al(0);
    set_wc(60);
    set_ac(23);
    set_chance(1);
    set_spell_dam(80);
    set_spell_mess1("Fettdog appears to be recharged by his rage!\nYou are somewhat concerned.\n");
    set_spell_mess2("Sparks fly.\nFettdog's body glows momentarily.\nHe appears to have been injected with newfound power and energy.\n");
    set_chat_chance(7);
    
    set_heal(3,2);    
    
    load_chat("Fettdog surveys the area carefully.\n");
    load_chat("Fettdog smirks.\n");
    load_chat("Fettdog scratches himself.\n");
    
    bag = clone_object("players/mizan/etheriel/items/backpack.c");
    move_object(bag, this_object());
    
    enable_commands();

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_off(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_FIREWORKS_THROWER);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 90);
    set_attribute(ATTRIB_FEARLESSNESS, 50);
    set_attribute(ATTRIB_PERCEPTION, 70);
    set_attribute(ATTRIB_CRUELTY, 85);
    set_attribute(ATTRIB_INSANITY, 75);
    set_attribute(ATTRIB_GENEROUSITY, 5);

    set_monster_guild_level(2);
    set_monster_guild_rank("Black Pawn");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 85);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 90);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 10);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 10);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 50);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 10);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 30000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 5570);
	set_int(VAL_HUNTING_THRESHOLD, 15);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 2);


    
    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "You are amazed at Fettdog's speed in combat!\n",
        "Fettdog appears only mildly displeased despite being attacked!\n",
        "Fettdog laughs at you.\nFettdog exclaims: Bitz, you're gonna get a beatdown.\n",
        "Fettdog, cool under pressure, extends his middle finger out in salute.\n",
    });

	attacked_mchannels = ({
		"Dude like someone is attacking me and they are going to get bitchslapped.\n",
        "I'm gonna make this mofo run like the slap-happy bitzatch they really are!\n",
        "Being attacked is teh lose. Attacking me? The big time TEH LOSE!\n",
        "Someone's going to get the shait-down!\n",
        "BIZATCH it's time to beat someone's ass!\n",
	});


    panicked_emotes = ({
        "Fettdog exclaims: Fuck! Damnit! Grr.\n",
        "Fettdog goes: Buh!\n",
        "Fettdog exclaims: Motherfucker!\n",
        "Fettdog snarls loudly.\n",
        "Fettdog loses his shit!\n",
        "Fettdog snickers loudly.\n",
    });

	panicked_mchannels = ({
		"Fuck! Fuck! Fuck!\n",
        "GTFO! GTFO! Get the FUQ out!\n",
        "Damnit! Bitz gonna get poofed!\n",
        "Goddamn! GTFO! GTFO!\n",
        "Mother of molten shit. GTFO!",
	});

    
    hit_hard_emotes = ({
        "Fettdog laughs off the hard shot.\n",
        "Fettdog rolls the hard hit away from his body.\n",
        "Fettdog screams: Is that all you can do, bitch?!\n",
        "Fettdog cackles maniacally even after being hit.\n",
        "Fettdog laughs out loudly.\nFettdog exclaims: You hit like a fucking GIRL!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! OW! That hurt!\n",
        "I just took a bone-crushing hit! :(\n",
        "ACK! Ow! ow! ow...\n",
        "Bitch! Must be a cheat weapon, shit!\n",
    });


    taunting_emotes = ({
        "Fettdog says: That's right, step into the ring, and fight me, BEYOTZ!\n",
        "Fettdog exclaims: You ain't got NAH-TAIN... NAH-TAIN.\n",
        "Fettdog thumps his chest proudly.\n",
        "Fettdog goes: WOOO! WOOO! WOOO! WOOO!\n",
        "Fettdog howls like a rabid flying monkey!\nThat's not much of a stretch.\nHE IS A FLYING MONKEY.\n",
        "Fettdog spits on the ground.\n",
        "Fettdog says: Stupidass humans.\n",
        "Fettdog points and laughs at you.\n",
        "Fettdog says: What's pink and stupid and has no fur? Humans.\n",
        "Fettdog says: Yo mama's got an afro and a chinstrap.\n",
        "Fettdog says: Yo mama's so stupid, I asked her do tricks for me and she wagged her tail.\n",
        "Fettdog says: Yo mama's so stupid, she broke her neck at a flashing red light.\n",
        "Fettdog says: Your weapon is so geh-toe, beyotz!\n",
        "Fettdog says: Yo mama has a moustache and they call her Bob!\n",
        "Fettdog says: Yo mama has so much hair on her upper lip, she braids it.\n",
        "Fettdog says: Yo mama's so ugly, she looks like you!\n",
        "Fettdog says: Yo mama's so ugly, she could only be Yo mama!\n",
        "Fettdog says: Yo mama's so ugly, when she looks in the mirror, the reflection ducks!\n",
        "Fettdog says: Yo mama's so ugly, she's uugly. I had to add another u `cause u is ugly too!\n",
        "Fettdog says: Yo mama's so ugly, her mom had to be drunk to breastfeed her.\n",
        "Fettdog says: Yo mama has so many fat rolls that she has to screw her pants on.\n",
    });

    taunting_mchannels = ({
        "Fucking humans. Heh.\n",
        "Heh, I love messing with the players.\n",
        "What the hell is wrong with these people? Idiots.\n",
        "Assholes, shitheads, losers, morons. These players are not worthy opponents.\n",
        "Suck my dick, bitch! Heh, the preferred way to saying 'hi' to some player jackoff.\n",
        "BAHAHAH! Stupidass human motherfuckers.\n",
    });


    triumph_emotes = ({
        "Fettdog says: SNAP YA DOWN BITZ!\n",
        "Fettdog says: Welcome to Federal Pound-Yer-Ass Prison, and i'm the fucking WARDEN.\n",
        "Fettdog says: BAHAHAHAHA!\n",
        "Fettdog says: FWAHAHAHA! Suckah!\n",
    });

    triumph_mchannels = ({
        "Aww yea!\n",
        "BAHAHA!!\n",
        "*snicker*\n",
    });


    casual_emotes = ({
        "Fettdog snickers.\n",
        "Fettdog sizes you up.\n",
        "Fettdog spits on the ground.\n",
        "Fettdog scratches himself.\n",
    });

    casual_mchannels = ({
        "Right. What happens in Vegas, stays in Vegas.\n",
        "*spit*. Lame ass player motherfuckers.\n",
        "I need to take a shit.\n",
        "Who the hell does Mizan think he is?\n",
        "Kinda quiet. Too quiet. Heh.\n",
        "Heh.\n",
        "*snicker*\n",
        "BUH!\n",
    });


    scared_emotes = ({
        "Fettdog appears somewhat stressed.\n",
        "Fettdog asks: Yo what the FUCK!?\n",
    });
    
    scared_mchannels = ({
        "Fuck. I am worried.\n",
        "I DO NOT LIKE THIS!\n",
        "Crap! crap! crap!\n",
    });


    death_emotes = ({
        "Fettdog fades and crumples to the ground.\n",
        "Fettdog screams in agony!\n",
        "Fettdog's lifeless body falls to the ground.\n",
    });

    death_mchannels = ({
        "FUCK! FUCK! FUCK! I died. DAMNIT!\n",
        "Shit! I got blicked... i'll be back motherfuckers!\n",
        "Damnit, I got my ass killed.\n",
        "Grrrrr.\n",
    });


    shit_throw_emotes = ({
        "Fettdog grins greasily.\n",
        "Fettdog cackles biggly!\n",
        "Fettdog says: Yo mama's so dirty, she has to creep up on bath water. \n",
        "Fettdog says: Yo mama's so dirty, she tried to take a bath and the water jumped out and said 'I'll wait.' \n",
        "Fettdog says: Yo mama's so dirty, she uses her dirty clothes as a weapon. \n",
        "Fettdog says: Yo mama's so dirty, she loses weight in the shower. \n",
        "Fettdog says: Yo mama's so dirty, she gets ring around the collar when she wears tank tops. \n",
        "Fettdog says: Yo mama's so dirty, even Swamp Thing told the bitch to shower. \n",
        "Fettdog says: Yo mama's so dirty, the US Government uses her bath water for chemical weapons. \n",
    });
    
    shit_throw_mchannels = ({
        "Nothing says HAH! like a pile of shit in the face!\n",
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Fecalpottyhumor.com!\n",
        "SHIT FACE!\n",
        "SHIT IN TEH FACE!\n",
    });

    
    balloon_throw_emotes = ({
        "Fettdog laughs out loud!\n",
    });

    balloon_throw_mchannels = ({
        "Wacked by a water balloon, beyotz!\n",
        "Someone is soaking wet. Heh this lame ass kiddy shit is actually kind of fun.\n",
        "Heh.\n",
    });


    arrival_emotes =({
        "Fettdog's body crackles and bristles with... electrical energy? Shieeeeeat...\n",
        "Fettdog flexes for you.\n",
    });

    arrival_mchannels =({
        "I'm here, with my army of prostitutes. Byeeaaaah!\n",
        "Okay ladies. Fettdog is in da house.\n",
        "Nog nog nog! Fettdog is here. Where de wimmen be at?!\n",

    });

}

/*
 * Fettdog's personality is flighty. He will not want to engage in combat
 * for long sustained periods if he can afford it.
 *
 * Hey, i modeled him in the image of a player :)
 *
 * He will tend to bail out of combat fast, even at the expense of creatures
 * protecting him, and then return at a later point in sneak attack mode.
 *
 */


/* eof */
