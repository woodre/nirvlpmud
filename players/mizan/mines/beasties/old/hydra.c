inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

/* The way multiple heads are represented is code based from Sweetness' original
 * five headed hydra.
 */

int head1_alive;
int head2_alive;
int head3_alive;
int head4_alive;
int head5_alive;

string head1_name;
string head2_name;
string head3_name;
string head4_name;
string head5_name;

string head1_channel_name;
string head2_channel_name;
string head3_channel_name;
string head4_channel_name;
string head5_channel_name;

string head1_att_msgs;
string head2_att_msgs;
string head3_att_msgs;
string head4_att_msgs;
string head5_att_msgs;

reset(arg)
{
    object weapon, armor, heals, radio;
    ::reset(arg);
    if(arg) return;

    head1_name = HIY + "The head of electricity" + NORM;
    head2_name = HIC + "The head of frost" + NORM;
    head3_name = GRN + "The head of acid" + NORM;
    head4_name = HIR + "The head of fire" + NORM;
    head5_name = HIW + BBLK + "The head of death" + NORM + NORM;

    head1_channel_name = HIY + "(head of electricity)" + NORM;
    head2_channel_name = HIC + "(head of frost)" + NORM;
    head3_channel_name = GRN + "(head of acid)" + NORM;
    head4_channel_name = HIR + "(head of fire)" + NORM;
    head5_channel_name = HIW + BBLK + "(head of death)" + NORM + NORM;

    head1_alive = 1;
    head2_alive = 1;
    head3_alive = 1;
    head4_alive = 1;
    head5_alive = 1;

    /* standard game lib stuff */
    set_name("Hydra");
    set_race("dragon");
    set_alias("hydra");
    set_short(HIY + "Hydra" + NORM + " (benevolent)");

    set_long("Under any normal condition your bowels would have been set to\n"+
             "warp speed DUMP at the sight of something like this.\n"+
             "Standing before you is a five-headed hydra some fifty feet tall.\n"+
             "However this creature seems content to just mind its own business,\n"+
             "not particularly interested in killing and devouring people, or\n"+
             "terrorizing cities and buildings.\n"+
             "Consider yourself lucky today.\n" +
             "Hydra has a tattoo reading: Monster's Guild.\n");

    set_name("hydra");
    set_race("dragon");
    set_alias("hydra");
    set_short("Hydra");
    set_level(29);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 5000;
    hit_point = 5000;
    
    set_al(-1000);
    set_wc(40);
    set_ac(90);
    
    set_heal(3,2);   

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
    toggle_on(MODE_CORPSE_EATER);
    toggle_on(MODE_SLOW_HITFADES);


    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);
    set_attribute(ATTRIB_FEARLESSNESS, 80);
    set_attribute(ATTRIB_PERCEPTION, 50);
    set_attribute(ATTRIB_CRUELTY, 75);
    set_attribute(ATTRIB_INSANITY, 10);
    set_attribute(ATTRIB_GENEROUSITY, 70);

    set_monster_guild_level(3);
    set_monster_guild_rank("Black Rook");

    set_string(STR_TEAM_NAME, "MonstersInc");
    set_string(STR_CABAL_NAME, "TheCorps");

    set_chance_of(CHANCE_CORPSE_LOOTING, 25);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 20);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 10);
    set_chance_of(CHANCE_EMOTE_PANICKED, 1);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 10);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 10);
    set_chance_of(CHANCE_PELTING_THINGS, 8);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 80000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 25300);
	set_int(VAL_HUNTING_THRESHOLD, 10);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 14);


    prepare_emote_strings();
}


long()
{
    ::long();
    write(extra_long());
}

prepare_emote_strings()
{
    /* lots of channel and emote stuff */
    attacked_emotes = ({
        head5_name + " says softly: Without a doubt, that was the dumbest thing you have done.\n",
        head5_name + " says softly: That was incredibly stupid.\n",
        head5_name + " says softly: Prepare to die.\n",
        head5_name + " says softly: Your end is near.\n",
        head5_name + " chuckles heartily.\n",
        head5_name + " smirks mischeviously.\n",
        head5_name + " breathes a puff of wispy, smoke tendrils of DEATH.\n",
    });

    if(head4_alive)
        attacked_emotes += ({
            head4_name + " exclaims: You are one dead fool.\n",
            head4_name + " exclaims: THERE IS NOTHING you can do to survive.\n",
            head4_name + " thunders: Meet your end unselfishly. Abandon all hope.\n",
            head4_name + " cackles maniacally!\n",
            head4_name + " exclaims: You stupid idiot.\n",
        });

    if(head3_alive)
        attacked_emotes += ({
            head3_name + " chuckles softly.\n",
            head3_name + " says: Is that the best you can do? You're fucked then.\n",
            head3_name + " exclaims: OMFG that is the weakest ass shit I have ever seen.\n",
            head3_name + " says: What kind of cheapass weapon is that?\n",
            head3_name + " says: Where do you get your armor from, Sears?\n",
            head3_name + " laughs maniacally!\n",
            head3_name + " snickers.\n",
        });

    if(head2_alive)
        attacked_emotes += ({
            head2_name + " says: Hey man, you're pretty weak.\n",
            head2_name + " yawns deeply. My, what fangs you have!\n",
            head2_name + " says: Yo. You had best just GTFO.\n",
            head2_name + " says: Uh, are you for real there buddy?\n",
            head2_name + " says: I think caveman homeslice homosapiens here is trying to cause some trouble.\n",
            head2_name + " says: Are you crazy?\n",
        });

    if(head1_alive)
        attacked_emotes += ({
            head1_name + " says: Whoa, what's wrong with you? We're just tourists!\n",
            head1_name + " says: If you keep this up i am going to have to beat your ass down.\n",
            head1_name + " says: Yo, are you for real?\n",
            head1_name + " says: You are getting me angry.\n",
            head1_name + " says: Hey man, I'm not looking for a fight okay? We're on VACATION you idiot!\n",
            head1_name + " says: Yo, Dumbass. What the hell?\n",
        });



	attacked_mchannels = ({
        head5_channel_name + " Hrm.\n",
	});

    if(head4_alive)
        attacked_mchannels += ({
            head4_channel_name + " Whoa. That was close.\n",
            head4_channel_name + " We need to keep up the pressure.\n",
            head4_channel_name + " Steady! Steady!\n",
            head4_channel_name + " Excellent!\n",
            head4_channel_name + " RAAR!\n",
            head4_channel_name + " Guys, cut down the chatter. Stay focused!\n",
        });

    if(head3_alive)
        attacked_mchannels += ({
            head3_channel_name + " Aim for the nuts!\n",
            head3_channel_name + " Aim for the nuts NOW!\n",
            head3_channel_name + " Will someone aim for the nuts!\n",
            head3_channel_name + " AAAAUGH.\n",
        });

    if(head2_alive)
        attacked_mchannels += ({
            head2_channel_name + " No, aim for the HEAD!\n",
            head2_channel_name + " Look at that puny thing, go for the headshot!\n",
            head2_channel_name + " HEAD SHOT!\n",
            head3_channel_name + " Come on, go for the headshots, they can't move after that!\n",
            head3_channel_name + " Dain Bramagation!\n",
            head2_channel_name + " Woohoo!\n",
            head2_channel_name + " Will you aim for the head already! Jeez!\n",
        });

    if(head1_alive)
        attacked_mchannels += ({
            head1_channel_name + " We need to hit harder.\n",
            head1_channel_name + " Heh!\n",
            head1_channel_name + " Bam! Nice shot...\n",
            head1_channel_name + " Focus! Focus!\n",
            head1_channel_name + " I can't believe they are fighting us...\n",
            head1_channel_name + " GHEY!\n",
        });



    panicked_emotes = ({
        head5_name + " appears somewhat distracted.\n",
        head5_name + " appears fairly angry.\n",
        head5_name + " growls silently.\n",
    });

	panicked_mchannels = ({
        head5_channel_name + " What... Be careful guys. This is troublesome.\n",
        head5_channel_name + " Shit! What the hell?\n",
        head5_channel_name + " Heads up. This can be dangerous.\n",
        head5_channel_name + " Yo Yo Yo. Heads up.\n",
        head5_channel_name + " Uh... guys... Let's take this a little more seriously.\n",
	});

    
    hit_hard_emotes = ({
        head5_name + " growls quietly.\n",
        head5_name + " stares intently at you.\n",
        head5_name + " appears to be somewhat enraged.\n",
        head5_name + " focuses on you.\n",
    });

    if(head4_alive)
        hit_hard_emotes += ({
            head4_name + " turns to face you, angrily.\n",
        });

    if(head3_alive)
        hit_hard_emotes += ({
            head3_name + " grimaces evilly.\n",
            head3_name + " says: You. Are. Dead.\n",
        });

    if(head2_alive)
        hit_hard_emotes += ({
            head2_name + " says: Ow.\n",
            head2_name + " growls loudly.\n",
        });

    if(head1_alive)
        hit_hard_emotes += ({
            head1_name + " says: Hmm.\n",
            head1_name + " says: Ouch.\n",
        });
	


    
    hit_hard_mchannels = ({
        head5_channel_name + " Hey, you okay? That hurt somewhat.\n",
        head5_channel_name + " Hmm, that was a rather hard hit.\n",
    });

    if(head4_alive)
        hit_hard_mchannels += ({
            head4_channel_name + " Whoa, that was whacked.\n",
            head4_channel_name + " What kind of weapon was that?\n",
        });

    if(head3_alive)
        hit_hard_mchannels += ({
            head3_channel_name + " Wow, I actually kinda felt that one.\n",
            head3_channel_name + " Ouch!\n",
        });

    if(head2_alive)
        hit_hard_mchannels += ({
            head2_channel_name + " OW! What the hell? This one is on roids or something?\n",
            head2_channel_name + " Eh! What kinda weapon does this one have?\n",
            head2_channel_name + " Ouch! That smarts!\n",
        });

    if(head1_alive)
        hit_hard_mchannels += ({
            head1_channel_name + " Dangit. That actually hurt.\n",
            head1_channel_name + " Ouch. Crap!\n",
            head1_channel_name + " Hmm... Focus.\n",
            head1_channel_name + " Hey, this guy is a live one!\n",
            head1_channel_name + " Ack. We need to hit harder.\n",
        });
	


    taunting_emotes = ({
        head5_name + " says softly: You will die.\n",
        head5_name + " says softly: You will die, and I will kill you.\n",
        head5_name + " grins evilly.\n",
    });

    if(head4_alive)
        taunting_emotes += ({
            head4_name + " exclaims: I'm gonna rip your head off and shit down your throat.\n",
            head4_name + " exclaims: You call that a face? Holy crap.\n",
        });

    if(head3_alive)
        taunting_emotes += ({
            head3_name + " says: Hi there, Jackass!\n",
            head3_name + " says: I'm not your type. I'm not inflatable.\n",
            head3_name + " says: Yo. Don't breed.\n",
            head3_name + " says: Wow, we've got a stupid one here.\n",
        });

    if(head2_alive)
        taunting_emotes += ({
            head2_name + " exclaims: You suck.\n",
            head2_name + " exclaims: Yo mama dressed you funny and gave you a Newbie sword.\n",
            head2_name + " exclaims: Feh. I give you 10 rounds to die.\n",
            head2_name + " laughs out loud!\n",
        });

    if(head1_alive)
        taunting_emotes += ({
            head1_name + " says: Your mama dresses you funny, Killer.\n",
            head1_name + " says: That's the weapon you're gonna use, Slick? HAH!\n",
            head1_name + " says: You call that armor, Ace?\n",
            head1_name + " says: You're so ugly, I nearly shit myself, Buddy!\n",
            head1_name + " says: Hey there Skippy!\n",
            head1_name + " says: You... want a piece of me, Pal?\n",
        });
		

    taunting_mchannels = ({
        head5_channel_name + " We need to keep it up.\n",
        head5_channel_name + " Stay verbally abusive but focused.\n",
        head5_channel_name + " Let's not get too raunchy.\n",
        head5_channel_name + " Excellent.\n",
    });
    
    if(head4_alive)
        taunting_mchannels += ({
            head4_channel_name + " Yeah, I like this pace.\n",
            head4_channel_name + " Beautiful!\n",
            head4_channel_name + " Hahaha, good one.\n",
            head4_channel_name + " Smooth delivery :)\n",
            head4_channel_name + " Mmmm...\n",
        });

    if(head3_alive)
        taunting_mchannels += ({
            head3_channel_name + " Whoa!\n",
            head3_channel_name + " No mama snaps okay?\n",
            head3_channel_name + " Please, no mama jokes :)\n",
            head3_channel_name + " Cool...\n",
        });

    if(head2_alive)
        taunting_mchannels += ({
            head2_channel_name + " Heh!\n",
            head2_channel_name + " Heh...\n",
            head2_channel_name + " That was good.\n",
            head2_channel_name + " Slick :)\n",
            head2_channel_name + " What's with the pet names? :)\n",
            head2_channel_name + " Woot...\n",
        });

    if(head1_alive)
        taunting_mchannels += ({
            head1_channel_name + " This isn't my style... but I like it.\n",
            head1_channel_name + " Yes, professional bastardism :)\n",
            head1_channel_name + " HAHA!\n",
            head1_channel_name + " NICE!\n",
            head1_channel_name + " DOH!\n",
        });
	


    triumph_emotes = ({
        head5_name + " says: Nice. Someone was royally busted.\n",
        head5_name + " says: Heh.\n",
    });

    if(head4_alive)
        triumph_emotes += ({
            head4_name + " cackles biggly!\n",
            head4_name + " grins biggly.\n",
            head4_name + " says: Ahh yes, victory is sweet.\n",
        });

    if(head3_alive)
        triumph_emotes += ({
            head3_name + " exclaims: SNAP YOU DOWN!\n",
            head3_name + " exclaims: WHOOP!\n",
            head3_name + " exclaims: Yeaaaah, that's 'teh' right.\n",
        });

    if(head2_alive)
        triumph_emotes += ({
            head2_name + " exclaims: YOU ARE 'TEH' LOSE!\n",
            head2_name + " exclaims: STUFFED!\n",
            head2_name + " exclaims: WHO'S YER DADDY! Yeehah!\n",
            head2_name + " exclaims: BUSTED!\n",
            head2_name + " exclaims: HOO-AHH!\n",
            head2_name + " cackles maniacally!\n",
        });

    if(head1_alive)
        triumph_emotes += ({
            head1_name + " says: All your base are belong to us, man.\n",
            head1_name + " says: Snap! We win.\n",
            head1_name + " says: BAHAHAH!\n",
            head1_name + " says: Hey, tough luck dude.\n",
            head1_name + " says: Yeah, that's right. We win.\n",
            head1_name + " says: Huzzah! Busted!\n",
        });



    triumph_mchannels = ({
        head5_channel_name + " Victorious again.\n",
        head5_channel_name + " Nicely done, well met.\n",
        head5_channel_name + " Awesome.\n",
        head5_channel_name + " Brilliant.\n",
    });

    if(head4_alive)
        triumph_mchannels += ({
            head4_channel_name + " Sweet. Good work all!\n",
            head4_channel_name + " We need to hit a little harder, but sweet job!\n",
            head4_channel_name + " Awesome shit!\n",
            head4_channel_name + " BUAHAHAH!\n",
            head4_channel_name + " Viciously good. Excellent work!\n",
        });

    if(head3_alive)
        triumph_mchannels += ({
            head3_channel_name + " Froody as all hell, haha.\n",
            head3_channel_name + " Wicked.\n",
            head3_channel_name + " Yeah, that was shithot!\n",
        });

    if(head2_alive)
        triumph_mchannels += ({
            head2_channel_name + " DAYUM! Hahahaha...\n",
            head2_channel_name + " Sweet. That was good.\n",
            head2_channel_name + " Slammed!\n",
        });

    if(head1_alive)
        triumph_mchannels += ({
            head1_channel_name + " YES!\n",
            head1_channel_name + " YEAH.\n",
            head1_channel_name + " Buh! You love me long time!\n",
            head1_channel_name + " Hizzdrah in da hizzouse!\n",
            head1_channel_name + " AWESOME!\n",
            head1_channel_name + " Woohah! YEAH!\n",
        });





    casual_emotes = ({
        head5_name + " says softly: Greetings.\n",
        head5_name + " says softly: Good day to you.\n",
        head5_name + " says softly: Hello.\n",
        head5_name + " says softly: I am searching for the nearest pub.\n",
        head5_name + " says softly: I am wondering if you can direct us to a pub.\n",
        head5_name + " says softly: I really am in the mood for a good beer.\n",
        head5_name + " says softly: A good lager is what I am in the mood for.\n",
        head5_name + " says softly: The nearest convenient pub would be nice.\n",
    });
	
    if(head4_alive)
        casual_emotes += ({
            head4_name + " says: Hey buddy.\n",
            head4_name + " says: What's up?\n",
            head4_name + " says: I'm looking for a good fabrics warehouse.\n",
            head4_name + " says: You know, i'm looking for some linens and stuff.\n",
            head4_name + " says: I'm looking for retail fabrics, not the wholesaler stuff.\n",
            head4_name + " says: Surprisingly, i'm not looking for a LOT of fabric, just a bit.\n",
            head4_name + " says: Hey, nice hat.\n",
            head4_name + " says: I really don't like Bed Bath and Beyond. Crazy, big-ass corporations.\n",
            head4_name + " smiles toothily.\n",
        });

    if(head3_alive)
        casual_emotes += ({
            head3_name + " exclaims: THIS AIN'T VEGAS but it's still not too shabby.\n",
            head3_name + " exclaims: HOW YA DOIN!\n",
            head3_name + " exclaims: This is kinda neat. Where are the hookers?\n",
            head3_name + " exclaims: I'm really hungry too. Know any good steakhouses?\n",
            head3_name + " exclaims: I could eat a whole cow right about now. Or three.\n",
            head3_name + " exclaims: YO! Can you take our picture?\n",
            head3_name + " grins evilly.\n",
        });

    if(head2_alive)
        casual_emotes += ({
            head2_name + " says: I don't like flying.\n",
            head2_name + " says: Hung over.\n",
            head2_name + " says: Howdys. Sorry I've got nothing much to say.\n",
            head2_name + " smiles broadly.\n",
        });

    if(head1_alive)
        casual_emotes += ({
            head1_name + " says: Not bad, I like getting out every so often for a walk.\n",
            head1_name + " says: Hey man, how are you doing?\n",
            head1_name + " says: There are some nice buildings here\n",
            head1_name + " says: Don't mind me, i'm an architecture buff.\n",
            head1_name + " says: Hey, did you know there are some cool ass skyscrapers in Asia now...\n",
            head1_name + " says: Too bad we aren't too welcome in Japan anymore.\n",
            head1_name + " says: That bastard, Godzilla.\n",
            head1_name + " says: Its crazy!\n",
            head1_name + " smiles happily.\n",
        });



    
    casual_mchannels = ({
        head5_channel_name + " Look, all I am looking for is a good pub.\n",
        head5_channel_name + " Are there no decent pubs on this MUD?\n",
        head5_channel_name + " Lagers are 'thin' beers, yes, but that is besides the point.\n",
        head5_channel_name + " I don't care, I am in the mood for a cold lager beer.\n",
        head5_channel_name + " Even a light ale will suffice.\n",
        head5_channel_name + " It has nothing to do with alcoholism. I am merely thirsty.\n",
        head5_channel_name + " Humans may stink, and are inclined to violence. But I want a BEER.\n",
        head5_channel_name + " Is that too much to ask? I just want some good beer.\n",
    });

    if(head4_alive)
        casual_mchannels += ({
            head4_channel_name + " That's all fine and good but I can't drink alcohol.\n",
            head4_channel_name + " I'm looking for somewhere we can get some linens.\n",
            head4_channel_name + " Well, that curtain in the cave is a little raggedy.\n",
            head4_channel_name + " What's with you guys just wanting to get something to drink?\n",
            head4_channel_name + " Uh, alcoholics?\n",
        });

    if(head3_alive)
        casual_mchannels += ({
            head3_channel_name + " What the hell is wrong with you Death?\n",
            head3_channel_name + " Lagers are wimpy beers. They are for you to kill slugs with.\n",
            head3_channel_name + " NO, Lager beers SUCK. That's the deal. SUCK with a capital SUCK.\n",
            head3_channel_name + " Why not something like whiskey? That is a real drink.\n",
            head3_channel_name + " Jack Daniels! That's the way to go for you!\n",
        });

    if(head2_alive)
        casual_mchannels += ({
            head2_channel_name + " Will all of you... just SHUT UP!\n",
            head2_channel_name + " All of you make me SICK.\n",
            head2_channel_name + " grumble.\n",
        });

    if(head1_alive)
        casual_mchannels += ({
            head1_channel_name + " Hey, look at that guy. I wonder where he got that shirt.\n",
            head1_channel_name + " There are some funny-ass buildings in this place.\n",
            head1_channel_name + " I miss NYC. There were some awesome buildings there!\n",
            head1_channel_name + " Too bad Japan is off-limits. Tokyo is such the bomb!\n",
            head1_channel_name + " I really liked Shanghai, but man, it was hot.\n",
            head1_channel_name + " Any of you guys hungry? I could use some quesadillas...\n",
            head1_channel_name + " Quesadillas?\n",
            head1_channel_name + " Sushi even?\n",
            head1_channel_name + " How about something non-alcoholic for a change?\n",
        });






    scared_emotes = ({
        head5_name + " says softly: This makes me somewhat agitated.\n",
        head5_name + " says: Right. Damn annoying.\n",
        head5_name + " says: Urgh.\n",
        head5_name + " thinks carefully.\n",
        head5_name + " ponders in deep thought.\n",
    });
    
    scared_mchannels = ({
        head5_channel_name + " I don't like the looks of this.\n",
        head5_channel_name + " Yo. Heads up. This isn't cool.\n",
        head5_channel_name + " Uh... Shit.\n",
        head5_channel_name + " Pay attention guys. This is not a good situation.\n",
        head5_channel_name + " Crap. This isn't cool.\n",
    });



    shit_throw_emotes = ({
        head4_name + " exclaims: That was mildly amusing.\n",
        head4_name + " says: Yeehah!\n",
        head4_name + " goes: Heh.\n",
        head4_name + " snickers.\n",
    });
    
    shit_throw_mchannels = ({
        head5_channel_name + " deep sigh.\n",
        head4_channel_name + " Bahahaha! Nice...\n",
        head4_channel_name + " Sput. I love that sound, heh.\n",
        head2_channel_name + " Will you guys stop that!\n",
        head4_channel_name + " Bahaha! Heh. That is so fun.\n",
    });

    
    balloon_throw_emotes = ({
        head5_name + " softly says: That was surprisingly fun.\n",
        head4_name + " exclaims: Yo. That was cool.\n",
        head4_name + " cries: Nice. Hahaha.\n",
        head4_name + " thunders: Bleah!\n",
        head4_name + " says: Riot! Heh!\n",
    });

    balloon_throw_mchannels = ({
        head5_channel_name + " Even I have to admit. These stupid water ballons are pretty fun.\n",
        head4_channel_name + " That.. was priceless.\n",
        head4_channel_name + " Nice shot!\n",
        head4_channel_name + " Stupid yet entertaining.\n",
        head4_channel_name + " BAHAHA! That was hilarious!\n",
    });



    death_emotes = ({
        "Hydra is... DEFEATED!\n",
    });

    death_mchannels = ({
        "Hydra has been defeated!\n",
    });

    arrival_emotes =({
        "The ground shakes, as Hydra appears.\n",
    });

    arrival_mchannels =({
        head1_channel_name + " We are here. Yay.\n",
        head2_channel_name + " Yeehah. Big guns' in the house!\n",
        head3_channel_name + " Righteous.\n",
        head4_channel_name + " Woo!\n",
        head5_channel_name + " We are here.\n",
    });


}


heartbeat_attack()
{
    object room; 
    object att;

    room = environment(this_object());
    att = this_object()->query_attack();

    if(!room || !att) return;

    /* heal */
    head1_attack(att, room);
    head2_attack(att, room);
    head3_attack(att, room);
    head4_attack(att, room);
    head5_attack(att, room);

    if(1 == random(15))
        do_emote_taunting();


}

/* Head one always goes for the player */
head1_attack(att, room)
{
    int dam;
    if(!head1_alive || !att || !room || att->query_dead()) return;

    /* init our messages */
    if(!head1_att_msgs)
    {
        head1_att_msgs = ({
            "slams a lightning bolt at",
            "directs a focused electrical shock at",
            "fires a wave of electricity at",
            "detonates a lighting bolt at",
            "blazes a lightning ball at",
            "spews an electrical storm towards",
            "emits a terrifying lightning blast at",
            "focuses an electrical shower on",
            "cuts loose a wave of lightning bolts at",
            "emits a terrifying lightning storm on",
            "blasts a lightning wave towards",
        });
    }

    if(1 == random(2))
    {
        /* we land our hit! */
        tell_room(room, head1_name + " " +
            head1_att_msgs[random(sizeof(head1_att_msgs))] + " " + att->query_name() + "!\n");
        dam = 20 + random(50);
        att->hit_player(dam);
    }
    else if(1 == random(3) && query_hp() < 4500)
    {
        /* head 1 casts heals */
        tell_room(room, head1_name + " appears to be in some sort of trancelike state....\n");
        /* don't let healing cross 5000 */
        request_healing(this_object(), 200 + random(300));
    }
    else 
    {
        /* we miss our hit */
        tell_room(room, head1_name + " missed " + att->query_name() + ".\n");
    }

    /* the head dies */
    if(this_object()->query_hp() < 4000)
    {
        head1_alive = 0;
        set_ac(110);

        tell_room(room, head1_name + " is destroyed!\n");
        report_message(head1_channel_name + " Crap... i died...\n");

        tell_object(att, HIB + "You have been granted some experience.\n" + NORM);
        att->add_exp(250000);
        call_out("prepare_emote_strings", 1);
    }

}




head2_attack(att, room)
{
    int dam;
    if(!head2_alive || !att || !room || att->query_dead()) return;

    /* init our messages */
    if(!head2_att_msgs)
    {
        head2_att_msgs = ({
            "belches loose a wave of superfrozen air at",
            "slams an icicle storm into",
            "breathes cold death at",
            "cuts loose a lightning storm at",
            "casts ice shards at",
            "focuses and claws at",
            "lunges forth and smashes into",
            "lurches forward and crashes into",
        });
    }

    if(1 == random(2))
    {
        /* we land our hit! */
        tell_room(room, head2_name + " " +
            head2_att_msgs[random(sizeof(head2_att_msgs))] + " " + att->query_name() + "!\n");
        dam = 15 + random(30);
        att->hit_player(dam);
    }
    else if(1 == random(3) && query_hp() < 3500)
    {
        /* head 2 casts heals */
        tell_room(room, head2_name + " appears to be in some sort of trancelike state....\n");
        /* don't let healing cross 5000 */
        request_healing(this_object(), 300 + random(150));
    }
    else 
    {
        /* we miss our hit */
        tell_room(room, head2_name + " missed " + att->query_name() + ".\n");
    }

    /* the head dies */
    if(this_object()->query_hp() < 3000)
    {
        set_ac(115);
        head2_alive = 0;

        tell_room(room, head2_name + " is destroyed!\n");
        report_message(head2_channel_name + " Crap... i died...\n");

        tell_object(att, HIB + "You have been granted some experience.\n" + NORM);
        att->add_exp(250000);
        call_out("prepare_emote_strings", 1);
    }

}


head3_attack(att, room)
{
    int dam;
    if(!head3_alive || !att || !room || att->query_dead()) return;

    /* init our messages */
    if(!head3_att_msgs)
    {
        head3_att_msgs = ({
            "belches a blast of acid gas at",
            "releases a noxious cloudkill at",
            "releases a toxic cloud at",
            "cuts loose with an acrid cloud at",
            "breathes pure acid at",
            "exhales pure acid at",
            "releases acid on",
            "blasts toxic waste at",
            "emits a caustic blast at",
            "focuses and claws at",
            "lunges forth and smashes into",
            "lurches forward and crashes into",
        });
    }

    if(1 == random(2))
    {
        /* we land our hit! */
        tell_room(room, head3_name + " " +
            head3_att_msgs[random(sizeof(head3_att_msgs))] + " " + att->query_name() + "!\n");

        dam = random(40);

        /* if the 1st head is dead we issue a harder hit */
        if(!head1_alive)
        {
            dam += random(20);
            if(1 == random(8))
            {
                tell_room(room, head3_name + " is enraged at the loss of its comrade!\n");
                dam += random(100);
            }
        }
        /* if the 2nd head is dead we get one too */
        if(!head2_alive)
            dam += random(50);


        att->hit_player(dam);
    }
    else if(1 == random(3) && query_hp() < 2500)
    {
        /* head 2 casts heals */
        tell_room(room, head2_name + " appears to be in some sort of trancelike state....\n");
        /* don't let healing cross 5000 */
        request_healing(this_object(), 300 + random(150));
    }
    else 
    {
        /* we miss our hit */
        tell_room(room, head3_name + " missed " + att->query_name() + ".\n");
    }

    /* the head dies */
    if(this_object()->query_hp() < 2000)
    {
        head3_alive = 0;
        set_ac(120);

        tell_room(room, head3_name + " is destroyed!\n");
        report_message(head3_channel_name + " Crap... i died...\n");

        tell_object(att, HIB + "You have been granted some experience.\n" + NORM);
        att->add_exp(250000);
        call_out("prepare_emote_strings", 1);
    }

}


head4_attack(att, room)
{
    int dam;
    if(!head4_alive || !att || !room || att->query_dead()) return;

    /* init our messages */
    if(!head4_att_msgs)
    {
        head4_att_msgs = ({
            "breathes a blast of firey death at",
            "belches a gigantic firey cloud at",
            "breathes a long line of flame at",
            "exhales a gigantic fireball at",
            "blasts a fireball at",
            "cuts loose with a fireball at",
            "opens up a fireball at",
            "smashes into",
            "focuses and claws at",
            "lunges forth and smashes into",
            "lurches forward and crashes into",
        });
    }

    if(1 == random(2))
    {
        /* we land our hit! */
        tell_room(room, head4_name + " " +
            head4_att_msgs[random(sizeof(head4_att_msgs))] + " " + att->query_name() + "!\n");
        dam = random(35);
        att->hit_player(dam);
    }
    else if(1 == random(3) && query_hp() < 1500)
    {
        /* head 2 casts heals */
        tell_room(room, head2_name + " appears to be in some sort of trancelike state....\n");
        request_healing(this_object(), 350 + random(100));
    }
    else 
    {
        /* we miss our hit */
        tell_room(room, head4_name + " missed " + att->query_name() + ".\n");
    }

    /* the head dies */
    if(this_object()->query_hp() < 1000)
    {
        head4_alive = 0;
        set_ac(125);

        tell_room(room, head4_name + " is destroyed!\n");
        report_message(head4_channel_name + " Crap... i died...\n");

        tell_object(att, HIB + "You have been granted some experience.\n" + NORM);
        att->add_exp(250000);
        call_out("prepare_emote_strings", 1);
    }

}


head5_attack(att, room)
{
    int dam;
    if(!head5_alive || !att || !room || att->query_dead()) return;

    /* init our messages */
    if(!head5_att_msgs)
    {
        head5_att_msgs = ({
            "belches a dark, noxious death smoke at",
            "breathes pure, concentrated death at",
            "unleashes noxious black smoke at",
            "belches some rancid black sputum at",
            "exhales deathly cold smoke at",
            "unleashes some horrible, cold death at",
            "releases some black plague at",
            "cuts loose some horrible, dark plague at",
            "focuses and claws at",
            "lunges forth and smashes into",
            "lurches forward and crashes into",
        });
    }

    if(1 == random(2))
    {
        /* we land our hit! */
        tell_room(room, head5_name + " " +
            head5_att_msgs[random(sizeof(head5_att_msgs))] + " " + att->query_name() + "!\n");
        
        /* randomly issue bogus levels of hurt */
        if(1 == random(10))
            dam = 150 + random(50);
        else
        {
            /* our base damage */
            dam = random(55);

            /* if the 3rd head is dead we issue a harder hit */
            if(!head3_alive)
                dam += 50 + random(75);

            /* if the 4th head is dead we get one too */
            if(!head4_alive)
            {
                if(1 == random(4))
                {
                    tell_room(room, head5_name + " is enraged at the loss of its comrades!\n");
                    dam += random(60);
                }
                dam += random(50);
            }

        }

        att->hit_player(dam);
    }
    else if(1 == random(2) && query_hp() < 750)
    {
        /* head 2 casts heals */
        tell_room(room, head1_name + " appears to be in some sort of trancelike state....\n");
        request_healing(this_object(), 200);
    }
    else 
    {
        /* we miss our hit */
        tell_room(room, head5_name + " missed " + att->query_name() + ".\n");
    }

    /* the head dies */
    if(this_object()->query_hp() < 99)
    {
        head5_alive = 0;

        tell_room(room, head5_name + " is destroyed!\n");
        report_message(head5_channel_name + " Crap... i died...\n");

        tell_object(att, HIB + "You have been granted some experience.\n" + NORM);
        att->add_exp(250000);
        call_out("prepare_emote_strings", 1);
    }

    if(query_hp() < 200) request_healing(this_object(), 200);
}


extra_long()
{
    string desc1,desc2,desc3,desc4,desc5;
    string temp;
    int hp;

    hp = this_object()->query_hp();
    desc1 = "in good shape.";
    desc2 = "in good shape.";
    desc3 = "in good shape.";
    desc4 = "in good shape.";
    desc5 = "in good shape.";

    if(hp < 5000){desc1 = "slightly hurt.";}
    if(hp < 4500){desc1 = "somewhat hurt.";}
    if(hp < 4250){desc1 = "in bad shape.";}
    if(hp < 4000){desc1 = "dead."; desc2 = "slightly hurt.";}
    if(hp < 3500){desc2 = "somewhat hurt.";}
    if(hp < 3250){desc2 = "in bad shape.";}
    if(hp < 3000){desc2 = "dead."; desc3 = "slightly hurt.";}
    if(hp < 2500){desc3 = "somewhat hurt.";}
    if(hp < 2250){desc3 = "in bad shape.";}
    if(hp < 2000){desc3 = "dead."; desc4 = "slightly hurt.";}
    if(hp < 1500){desc4 = "somewhat hurt.";}
    if(hp < 1250){desc4 = "in bad shape.";}
    if(hp < 1000){desc4 = "dead"; desc5 = "slightly hurt.";}
    if(hp <  500){desc5 = "somewhat hurt.";}
    if(hp <  250){desc5 = "somewhat hurt.";}
    if(hp <  100){desc5 = "in very bad shape.";}

    temp = head1_name + " is " + desc1 + "\n" +
          head2_name + " is " + desc2 + "\n" +
          head3_name + " is " + desc3 + "\n" +
          head4_name + " is " + desc4 + "\n" +
          head5_name + " is " + desc5 + "\n";

    return temp;
}



/* eof */