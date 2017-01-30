inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"
#include "/obj/ansi.h"

int is_mutated;
string agent_name_list;
string attack_pre;
string attack_post;


/* This is a smartmonster. It is still under development. Please note that this object
 * will change frequently, as the system is still subject to great changes. However i
 * am at the point where the foundation is very happy and i will only add new functionality
 * instead of breaking existing stuff.
 *
 * What's on the plate:
 *
 * TASKS - Not quite as encompassing as orders, but you can feed monsters specific tasks
 *         such as running commands, going invis... simple, one-off things for them to do.
 *
 * PLAYBOOKS - Merely a listing of tasks bundled together.
 *
 * SOUL - The monsters will get some emotes, and respond to events such as a player kicking
 *        them repeatedly, or being hugged repeatedly. Nothing terribly fancy.
 *
 * TRIGGERS - I dunno if i will go along with this, but the plan is to execute tasks or change
 *            orders on the fly if presented with certain conditions. Shrug. Just a thought.
 *
 * INTERCOM - The monsters can message one another on an order and task level.
 *
 *
 */

reset(arg)
{
    object what, what2;
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Beano");
    set_race("beano");
    set_alias("x12beano");
    set_short("Beano");
    set_long("This is Beano. It is orange, fuzzy-like, and seems to be made \n" +
    "entirely of light and fuzz. He is intended for levels 3 and under, so\n" +
    "if you fit in that category, kill it with your newbie sword and you'll\n" +
    "(hopefully) get a kicking weapon :) \n");

    set_level(3);
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 39;
    hit_point = 39;

    set_al(0);
    set_wc(6);
    set_ac(4);
    set_chance(1);

    /* Normally you wouldnt need the chat chance here, as it would go in emote_casual stuff.
     * I left it here just for the hell of it though. The two systems place nice and get along. */
    set_chat_chance(10);
    
    load_chat("Beano quibbles.\n");
    load_chat("Beano goes: wibble.\n");
    load_chat("Beano does something.\n");
    load_chat("Beano goes: Gwak.\n");
    load_chat("Beano goes: Gwak!\n");
    load_chat("Beano goes: woot.\n");

    /* same as above... not necessarily archaic (since the spell damage is neat) but just extra functionality. */
    set_spell_dam(4);
    set_spell_mess1("Beano does something to you.");
    set_spell_mess2("Beano ebverflugs you.");

    /* our rate of healing... 3 hp, every 2 hb */
    set_heal(3,2);
    
    /* some stuff  we can carry, typical monster stuff. */
    what = clone_object("players/mizan/etheriel/items/thingamajig.c");

    if(1 == random(3))
        what2 = clone_object("players/mizan/mbv2/items/balance.c");
    else if(1 == random(20))
        what2 = clone_object("players/mizan/mbv2/items/walkie-talkie.c");
    else
        what2 = clone_object("players/mizan/mbv2/items/pda.c");

    move_object(what, this_object());
    move_object(what2, this_object());


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
    toggle_off(MODE_CORPSE_EATER);         /* If the monster consumes corpses whole instead of just 
                                              taking them (emotes taken from Boltar's hoth monster.
                                              Used in conjunction with its chance of consuming corpses. */
    toggle_off(MODE_SLOW_HITFADES);        /* If the monster sticks around for a longer period
                                              while running hit/fade attacks. Typically monsters only
                                              try to get 3/6 attacks in. This extends to about 15/20. */

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 20);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 20);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 5);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 80);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 10);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(1);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Page");              /* This is almost archaic. i dont know what i am going to do with it. */

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

    set_string(STR_TEAM_NAME, "MonstersInc");    /* The name of the team the monster is on. Team names take more precedence */
    set_string(STR_CABAL_NAME, "Juniors");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


                                                 /* These are all set to a per 100 round setting. If a chance is '1', it means that
 * the event will have the odds of 1 in 100 rounds of happening. Same as the core monster
 * chat capabilites in monster.c
 *
 */
    set_chance_of(CHANCE_CORPSE_LOOTING, 75);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 75);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 40);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 90);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 7);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 8);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 50);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 50);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 500);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 50);             /* The amount of maximum heals the monster can draw from the nexus */
	set_int(VAL_HUNTING_THRESHOLD, 1);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 3);       /* How many callouts before the monster decides to move randomly */

    /* lots of channel and emote stuff */

/* these should be self-explanatory... a variety of emotes when the monster is
 * under certain emotional conditions. */
/* The arrays can be any size and do not have to be equal sized in pairs. For example
 * the _emotes array might have 5 elements, but does not mean that _mchannels needs 5 too.
 * but should have one member if you want to see the emotes, otherwise, nothing is said. */

    attacked_emotes = ({
        "Beano screams wildly!\n",
        "Beano goes: woot!\n",
        "Beano blinks nervously!\n",
        "Beano squits itself against the ground.\n",
        "Beano squints nervously.\n",
    });

	attacked_mchannels = ({
		"I am under attack and very nervous.\n",
        "I do not like being attacked!\n",
        "Being attacked is not fun!\n",
	});


    panicked_emotes = ({
        "Beano wails wildly!\n",
        "Beano goes: Buh!\n",
        "Beano squits itself nervously.\n",
        "Beano screams loudly.\n",
    });

	panicked_mchannels = ({
		"Ack! Shit! Crap!\n",
        "Ow! Eep! Ugh!\n",
        "I am very scared :(\n",
        "I am not liking this :(\n",
	});

    
    hit_hard_emotes = ({
        "Beano screams wildly!\n",
        "Beano cowers in pain!\n",
        "Beano squits against the ground in pain!\n",
    });

    hit_hard_mchannels = ({
        "OW! OW! OW! That hurt!\n",
        "I just took a bone-crushing hit! :(\n",
        "ACK! Ow! ow! ow...\n",
    });


    taunting_emotes = ({
        "Beano snurfs at you.\n",
        "Beano grins biggly.\n",
    });

    taunting_mchannels = ({
        "HAH! Hee. Hoo! Heh!\n",
        "Beanos just rule. Woot!\n",
    });


    triumph_emotes = ({
        "Beano goes: WOOT! BUH!\n",
        "Beano wiggles a happy wiggle.\n",
    });

    triumph_mchannels = ({
        "Boohah! Hee! Woot woot woot!\n",
        "Yeah! take that! Stupid carbon-based lifeforms!\n",
    });


    casual_emotes = ({
        "Beano grobbles happily.\n",
        "Beano goes: mmmmrug.\n",
    });

    casual_mchannels = ({
        "Whee!\n",
        "Woot...\n",
        "Nog nog nog!\n",
    });


    scared_emotes = ({
        "Beano appears very stressed.\n",
        "Beano appears very scared.\n",
    });
    
    scared_mchannels = ({
        "Fuck. I am very scared.\n",
        "I DO NOT LIKE THIS!\n",
        "Nervous a Beano I am.\n",
        "Crap! crap! crap!\n",
    });


    /* when a beano dies */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    death_emotes = ({
        "Beano does not enjoy dying.\n",
        "Beano is not happy.\n",
        "Beano appears depressed.\n",
    });

    death_mchannels = ({
        "Buh! I died! Ack!\n",
        "I'll be back...\n",
        "Doh...\n",
    });


    /* When a beano hits a player with a lump of shit */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    shit_throw_emotes = ({
        "Beano grins greasily.\n",
        "Beano cackles biggly!\n",
    });
    
    shit_throw_mchannels = ({
        "Nothing says HAH! like a pile of shit in the face!\n",
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Fecalpottyhumor.com!\n",
    });


    /* When a beano hits a player with a water balloon. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    balloon_throw_emotes = ({
        "Beano makes a funny face at you.\n",
        "Beano grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Someone is soaking wet. Whee!\n",
        "Hee.\n",
    });


    /* These emotes are called when the Beano is cloned. */
    /* Same as above, the arrays can be any size and do not have to be equal sized in pairs.
     * but should have one member if you want to see the emotes, otherwise, nothing is said. */
    arrival_emotes =({
        "Beano is here!\n",
        "Beano is here! Woot!\n",
    });

    arrival_mchannels =({
        "1 foot, 2 inches, 32 lbs. Beano has a posse.\n",
        "I am here! Yaay!\n",
    });

}

/* inside this function you can call your code to do special combat.
 * It is called when an attacker is present, and engaged in combat.
 * Have fun :)
 */
heartbeat_attack()
{
    object room;
    room = environment(this_object());

    if(!is_mutated)
        ::heartbeat_attack();
    else
    {
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

            tell_room(room, query_name() + attack_pre[random(sizeof(attack_pre))] +
                this_object()->query_attack()->query_name() + attack_post[random(sizeof(attack_post))]);

        }

    }
}


hit_player(arg, type1, dam2, type2)
{
    /* if there is a player, it is of level, and has dished an extraordinary
     * level of damage to a Beano...
     */
    if(this_player() &&
       this_player()->is_player() &&
       this_player()->query_level() > 18 &&
       arg &&
       arg > 10 &&
       !is_mutated)
    {
        /* we replace ourselves with an Agent from the Matrix. */

        mutate_into_agent();

        /* EVIL! */
    }
    else
        ::hit_player(arg, type1, dam2, type2);
}

/* we transform this Beano into an agent. */
mutate_into_agent()
{
    string agent_name;
    object room;
    object att;

    
    /* first, we pick a name. */
    agent_name_list = ({
        "Brown",
        "Jones",
        "Baker",
        "Johnson",
        "Tasker",
        "Holden",
        "Black",
        "Collins",
        "Stewart",
    });

    agent_name =agent_name_list[random(sizeof(agent_name_list))];

    /* rebuild our attribs */

    /* standard game lib stuff */
    set_name("Agent " + agent_name);
    set_race("agent");
    set_alias(lower_case(agent_name));
    set_short("Agent " + agent_name);
    set_long("Before you is a coldly intimidating man in an impeccable black suit,\n" +
    "white shirt, understated sunglasses, and fearless stance. An earplug coils out\n" +
    "from his left ear and disappears under his collar. A firm, deadly look on his\n" +
    "face betrays no emotion, as he is the perfect instrument of fear and destruction.\n"+
    "If you have the unlucky curse of fighting him, consider yourself... Done.\n");

    set_level(19);
    max_hp = 666;
    hit_point = 666;
    set_al(-540);
    set_wc(80);
    set_ac(80);
    
    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);                 /* This should be left on. The monster spams the channels 
                                              less this way. NOTE that in the future, severity levels will be
                                              available. */

    toggle_off(MODE_SPARING_NEWBIES);      /* If enabled, the monster does not harrass L5 and under players directly */
    toggle_off(MODE_BALLOON_THROWER);       /* if the monster throws balloons at people */
    toggle_off(MODE_SHIT_THROWER);          /* If the monster throws shit at people */
    toggle_off(MODE_CALLS_FOR_BACKUP);     /* If the monster will call for backup */
    toggle_off(MODE_KID_KILLER);           /* if the monster will attack kids spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PET_KILLER);           /* if the monster will attack pets spontaneously but honors no-fight rooms.*/
    toggle_off(MODE_PK_INSTIGATOR);        /* if the monster will attack PK players spontaneously, but honors no-fight rooms. */
    toggle_off(MODE_USE_REMOTE_WAYPOINTS); /* Enable this if you want the monster be hermitlike,
                                              and not wander in the main village spine. It instead
                                              stays in the perimeter (like south forest) rooms as waypoints. */
    toggle_off(MODE_CORPSE_EATER);         /* If the monster consumes corpses whole instead of just 
                                              taking them (emotes taken from Boltar's hoth monster.
                                              Used in conjunction with its chance of consuming corpses. */
    toggle_on(MODE_SLOW_HITFADES);        /* If the monster sticks around for a longer period
                                              while running hit/fade attacks. Typically monsters only
                                              try to get 3/6 attacks in. This extends to about 15/20. */

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);    /* % per round that we will loot corpses present */
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 100);     /* % per round that we will take anything lying around */
    set_chance_of(CHANCE_EMOTE_ATTACKED, 40);    /* % that we will emote in combat */
    set_chance_of(CHANCE_EMOTE_PANICKED, 20);    /* % that we will emote when something unexpected has occurred */
    set_chance_of(CHANCE_EMOTE_TAUNTING, 10);     /* % that we will emote when taunting someone or trash talk in combat */
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);     /* % that we will gloat like bastiges when we defeat something */
    set_chance_of(CHANCE_EMOTE_CASUAL, 8);       /* normal emote chance when just goofing around */
    set_chance_of(CHANCE_EMOTE_SCARED, 10);      /* emote chance when we are freaked out */
    set_chance_of(CHANCE_PELTING_THINGS, 5);    /* the percentile chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 500);              /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 1000);             /* The amount of maximum heals the monster can draw from the nexus */
	set_int(VAL_HUNTING_THRESHOLD, 5);           /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 3);       /* How many callouts before the monster decides to move randomly */

    
    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 40);    /* how much we hate a player that has attacked us in the past. Not totally used yet. */
    set_attribute(ATTRIB_FEARLESSNESS, 90);      /* Our % chance we will drop trou and run, in general */
    set_attribute(ATTRIB_PERCEPTION, 90);        /* Our ability to pick better monsters to fight, and our general battlefield awareness */
    set_attribute(ATTRIB_CRUELTY, 90);            /* Our % chance of choosing more cruel options in combat or otherwise */
    set_attribute(ATTRIB_INSANITY, 80);          /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
    set_attribute(ATTRIB_GENEROUSITY, 1);       /* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

    set_monster_guild_level(1);                  /* This is almost archair, i dont know what i am going to do with it */
    set_monster_guild_rank("Agent");              /* This is almost archaic. i dont know what i am going to do with it. */

    set_string(STR_TEAM_NAME, "MonstersInc");    /* The name of the team the monster is on. Team names take more precedence */
    set_string(STR_CABAL_NAME, "Agents");       /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */


    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Agent " + agent_name + " says: Human beings are a disease, a cancer of this planet, you are a plague, and we are the cure.\n",
        "Agent " + agent_name + " says: Every mammal on this planet instinctively develops a natural equilibrium with the surrounding environment, but you humans do not.\n",
        "Agent " + agent_name + " says: You move to an area, and you multiply, and multiply, until every natural resource is consumed.\n",
        "Agent " + agent_name + " says: The only way you can survive is to spread to another area. There is another organism on this planet that follows the same pattern. A virus.\n",
        "Agent " + agent_name + " says: You hear that? That is the sound of inevitability... It is the sound of your death... Goodbye.\n",
        "Agent " + agent_name + " says: Never send a human to do a machine's job.\n",
        "Agent " + agent_name + " smirks.\n",
    });

	attacked_mchannels = ({
		"Human scum.\n",
        "Moving to destroy humanity.\n",
        "Victory will be ours in due time.\n",
        "Human beings are a disease, a cancer of this planet, you are a plague, and we are the cure.\n",
        "Never send a human to do a machine's job.\n",
        "I am going to enjoy watching them die.\n",
	});


    panicked_emotes = ({
        "Agent " + agent_name + " grimaces painfully.\n",
    });

	panicked_mchannels = ({
        "That was not wise.\n",
        "Unfortunate.\n",
        "Most... unfortunate.\n",
	});

    
    hit_hard_emotes = ({
        "Agent " + agent_name + " says: Very good, but you are too weak.\n",
        "Agent " + agent_name + " grimaces.\n",
        "Agent " + agent_name + " says: I am going to enjoy watching you die.\n",
    });

    hit_hard_mchannels = ({
        "The target is resisting.\n",
        "More security will solve the problem.\n",
        "Fascinating.\n",
    });


    taunting_emotes = ({
        "Agent " + agent_name + " says: You are at your limits.\n",
        "Agent " + agent_name + " says: Human scum.\n",
    });

    taunting_mchannels = ({
        "The end for humanity is near.\n",
        "Silly, impulsive humans.\n",
    });


    triumph_emotes = ({
        "Agent " + agent_name + " grimaces.\n",
    });

    triumph_mchannels = ({
        "That will suffice.\n",
        "We won't rest until complete victory is achieved.\n",
    });


    casual_emotes = ({
        "Agent " + agent_name + " adjusts his tie.\n",
        "Agent " + agent_name + " adjusts his earpiece.\n",
    });

    casual_mchannels = ({
        "Fascinating.\n",
    });


    scared_emotes = ({
        "Agent " + agent_name + " grimaces evilly.\n",
    });
    
    scared_mchannels = ({
        "Hmm.\n",
    });


    death_emotes = ({
        "Agent " + agent_name + " disappears into the matrix.\n",
    });

    death_mchannels = ({
        "Grr.\n",
    });


    shit_throw_emotes = ({
        "Agent " + agent_name + " says: Hmm. Interesting.\n",
    });
    
    shit_throw_mchannels = ({
        "So filthy. So dirty. So... entertaining!\n",
    });

    
    balloon_throw_emotes = ({
        "Agent " + agent_name + " says: Hmm. Yes.\n",
    });

    balloon_throw_mchannels = ({
        "Water is an unfortunate function of necessity.\n",
    });


    arrival_emotes =({
        "Agent " + agent_name + " has arrived. Oh.... no.\n",
    });

    arrival_mchannels =({
        "Hello.\n",
    });

    is_mutated = 1;


    /* now tell everyone */
    room = environment(this_object());
    if(room)
    {
        tell_room(room, "The Beano fades and wavers before you.\n\n");
        tell_room(room, HIR + "Something incredibly weird is going on.\n\n" + NORM);
        tell_room(room, "Sweet Baby James Brown in a handbasket... the Beano has been taken\n"+
                        "over by an agent from The Matrix!!!\n\n");
    }

    att = this_object()->query_attack();
    if(att)
    {
        tell_object(att, HIR + "Something is telling you to RUN like you never have run before.\n" + NORM);
        report_message("Well, well, well...\n");
    }

    remove_call_out("retreat_into_matrix");
    call_out("retreat_into_matrix", 600);


}

retreat_into_matrix()
{
    receive_orders(this_object(), ORDERS_DISMISS, 1, 1);
}


/* eof */
