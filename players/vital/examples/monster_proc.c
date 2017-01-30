/******************************************************************************
 *	File:			monster_proc.c
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 Vital@Nirvana
 *					All Rights Reserved.
 *	Source:			Started 4/19/01.
 *	Notes:			Proctologist: Ouch
 *	Change History: Trying to make it a smart mob [12/17/2003]
 *****************************************************************************/

inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("sphincterani");
    set_alt_name("doctor");
    set_alias("Doctor Sphincterani");
    set_short("Doctor Sphincterani");
    set_long(
  "  The Good Doctor John Sphincterani\n\
  This is a good old-fashioned proctologist. He still makes house \n\
  calls and wants to make you better. He has some special skills \n\
  that will make you cringe.\n"
    );
    set_al(-(random(200)));
    set_gender("male");
    set_race("human");
    set_level(20);
    set_ac(30);
    set_wc(38);
    max_hp = 550;
    hit_point = 550;
    
    set_heal(2,1);
    
    set_dead_ob(this_object());
  
    set_chat_chance(5);
    load_chat("Dr. Sphincterani says: \"Do you need an exam?\"\n");
    load_chat("The doctor looks you over knowingly.\n");
    
    set_a_chat_chance(5);
    load_a_chat("Dr. Sphincterani says: \"Ooooo, Boy! This is going to hurt.\"\n");
    load_a_chat("Dr. Sphincterani says: \"Let me touch your soul!\"\n");
    load_a_chat("The doctor pulls on a new set of rubber gloves.\n");
    
    set_chance(15);
    set_spell_mess1("The doctor probes the inner being of his patient.\n");
    set_spell_mess2("Dr. Sphincterani bends you over and makes you scream.\n");
    
    set_spell_dam(5+random(40));
 
/*	 MONSTER GUILD CODE */
	/* This is needed (a hack) to tell the monsterplus code that we are
	 * properly initalized, able to roam and operate. */
	is_loaded = 1;

	/* monsterplus specific toggles */
	toggle_on(MODE_BRIEF);				   /* This should be left on. The monster spams the channels less this way */
	toggle_on(MODE_SPARING_NEWBIES);	  /* If enabled, the monster does not harrass L5 and under players directly */
	toggle_off(MODE_BALLOON_THROWER);		/* if the monster throws balloons at people */
	toggle_on(MODE_SHIT_THROWER);		   /* If the monster throws shit at people */
	toggle_on(MODE_CALLS_FOR_BACKUP);	  /* If the monster will call for backup */
	toggle_off(MODE_KID_KILLER);		   /* if the monster will attack kids spontaneously */
	toggle_on(MODE_PET_KILLER);			  /* if the monster will attack pets spontaneously */
	toggle_on(MODE_PK_INSTIGATOR);		  /* if the monster will attack PK players spontaneously */
	toggle_off(MODE_USE_REMOTE_WAYPOINTS); /* Enable this if you want the monster be hermitlike, and not wander in the main village spine */
	toggle_on(MODE_CORPSE_EATER);		  /* If the monster consumes corpses whole instead of just taking them (emotes taken from Boltar's hoth monster */
	toggle_off(MODE_SLOW_HITFADES);		  /* If the monster sticks around for a longer period while running hit/fade attacks */

	/* our attributes */
	set_attribute(ATTRIB_VINDICTIVENESS, 90);	 /* how much we hate a player that has attacked us in the past. Not totally used yet. */
	set_attribute(ATTRIB_FEARLESSNESS, 10);		 /* Our % chance we will drop trou and run, in general */
	set_attribute(ATTRIB_PERCEPTION, 75);		 /* Our ability to pick better monsters to fight, and our general battlefield awareness */
	set_attribute(ATTRIB_CRUELTY, 99);			  /* Our % chance of choosing more cruel options in combat or otherwise */
	set_attribute(ATTRIB_INSANITY, 75);			 /* Our likelihood of doing something violently irratic to a player that is fighting us, when we are seriously hurt */
	set_attribute(ATTRIB_GENEROUSITY, 5);		/* Our % chance of doing something nice to players not attacking us, i.e. healing or coining them. */

	set_monster_guild_level(2);					 /* This is almost archair, i dont know what i am going to do with it */
	set_monster_guild_rank("Page");				 /* This is almost archaic. i dont know what i am going to do with it. */
	
	set_string(STR_TEAM_NAME, "Triple-V");	 /* The name of the team the monster is on. Team names take more precedence */
	set_string(STR_CABAL_NAME, "Doctors");		 /* A cabal is like a sub-team name. An army has divisions, a team has cabals. */

	set_chance_of(CHANCE_CORPSE_LOOTING, 95);	 /* % per round that we will loot corpses present */
	set_chance_of(CHANCE_TAKE_ALL_LOOT, 55);	 /* % per round that we will take anything lying around */
	set_chance_of(CHANCE_EMOTE_ATTACKED, 45);	 /* % that we will emote in combat */
	set_chance_of(CHANCE_EMOTE_PANICKED, 45);	 /* % that we will emote when something unexpected has occurred */
	set_chance_of(CHANCE_EMOTE_TAUNTING, 68);	  /* % that we will emote when taunting someone or trash talk in combat */
	set_chance_of(CHANCE_EMOTE_TRIUMPH, 80);	 /* % that we will gloat like bastiges when we defeat something */
	set_chance_of(CHANCE_EMOTE_CASUAL, 20);		  /* normal emote chance when just goofing around */
	set_chance_of(CHANCE_EMOTE_SCARED, 10);		 /* emote chance when we are freaked out */
	set_chance_of(CHANCE_PELTING_THINGS, 10);	 /* the percentile chance that these monsters will throw things at players */

	set_int(VAL_INFUSE_POINT, 4500);			  /* the amount of coins where the monster infuses back to nexus */
	set_int(VAL_MAX_HEAL_QUOTA, 2500);			   /* The amount of maximum heals the monster can draw from the nexus */
	set_int(VAL_HUNTING_THRESHOLD, 5);			 /* How many rounds of combat before the monster gets pissed off... and choose to hunt or hitfade */
	set_int(VAL_RANDOM_MOVE_FREQUENCY, 5);		 /* How many callouts before the monster decides to move randomly */

	/* lots of channel and emote stuff */
	attacked_emotes = ({
		"Doctor Sphincterani screams wildly!\n",
		"Doctor Sphincterani chants: Pain, Pain, Pain!\n",
		"Doctor Sphincterani gets out a rubber glove.\n",
		"Doctor Sphincterani prepares to administer the colonoscope.\n",
		"Doctor Sphincterani yells, \"Hey! Now you know how a Muppet feels!\"\n",
		"Doctor Sphincterani yells, \"Can you hear me NOW?\"\n",
	});

	attacked_mchannels = ({
		"I am currently the object of anal retentive aggression.\n",
		"I am busy rectal-fying a situation!\n",
		"Pain Pain Pain!\n",
		"Time for check-up.\n",
		"I cannot abide by all this fudge.\n",
		"Hey! Now you know how a Muppet feels!\n",
	});


	panicked_emotes = ({
		"Doctor Sphincterani is a doctor!\n",
		"Doctor Sphincterani warns you about the risks of colon cancer!\n",
		"Doctor Sphincterani scrambles to find his rubber glove.\n",
		"Doctor Sphincterani screams loudly.\n",
	});

	panicked_mchannels = ({
		"What the hell!\n",
		"This is not true Pain!\n",
		"I'm going to go now.\n",
		"I am needed elsewhere.\n",
	});

	
	hit_hard_emotes = ({
		"Doctor Sphincterani screams wildly!\n",
		"Doctor Sphincterani cowers in pain!\n",
		"Doctor Sphincterani suffers along with you in pain!\n",
	});

	hit_hard_mchannels = ({
		"OW! Probe reversal!\n",
		"I just took probing from a player, bah!\n",
		"Who let the players attack innocent physicians.\n",
	});


	taunting_emotes = ({
		"Doctor Sphincterani calls your colon clogged.\n",
		"Doctor Sphincterani thinks you're a bit too slow.\n",
		"Doctor Sphincterani thinks you're all a bunch of assholes.\n",
		"Doctor Sphincterani knows you can't handle the probe.\n",
		"Doctor Sphincterani says, \"This is your proctologist calling. \n\
		                  I found your head.\".\n",
	});

	taunting_mchannels = ({
		"That's right, run you narrow hole, pansy!\n",
		"Who's your Doctor!\n",
		"With regular checkups, you can avoid polyps.\n",
		"Aha, there's my watch.\n",
	});


	triumph_emotes = ({
		"Doctor Sphincterani asks: I'm thinking you won't sit so soon.\n",
		"Doctor Sphincterani cracks a smile, er... smiles at your crack.\n",
	});

	triumph_mchannels = ({
		"Stick that in your colon and smoke it!\n",
		"That'll hurt for a bit!\n",
		"Oh boy, that was sphincterrific!\n",
	});


	casual_emotes = ({
		"Doctor Sphincterani gets out a clean rubber glove.\n",
		"Doctor Sphincterani looks for a new colon to clean.\n",
		"Doctor Sphincterani asks: Have you had your exam today?\n",
		"Doctor Sphincterani asks: Where is my watch?\n",
		"Doctor Sphincterani says, \"I used to have malpractice insurance.\"\n",
		"Doctor Sphincterani says, \"I am a brainsurgeon for lawyers.\"\n",
		"Doctor Sphincterani says, \"I just put in a hard day at the orifice.\"\n",
		"Doctor Sphincterani says, \"I used to have malpractice insurance.\"\n",
	});

	casual_mchannels = ({
		"I feeling a probing coming on!\n",
		"Com'ere Weeb. Take it like a man.\n",
		"Not enough colon to go 'round!\n",
		"You put your left hand in, you take your left hand out. You do the Hokey Pokey....\n",
	});


	scared_emotes = ({
		"Doctor Sphincterani needs a cigarette.\n",
		"Doctor Sphincterani looks a little bit put out.\n",
	});
	
	scared_mchannels = ({
		"Yeah. I need a smoke.\n",
		"I will not tolerate such horrible working conditions.\n",
	});


	death_emotes = ({
		"Doctor Sphincterani will return to probe your children!\n",
		"Doctor Sphincterani screams and threatens your general well being.\n",
		"Doctor Sphincterani is mad enough to probe.\n",
	});

	death_mchannels = ({
		"You can't keep a good probing down.\n",
		"This is not the end of Doctor Sphincterani!\n",
		"Pain. Pain! PAIN! It's all in the name of health!\n",
	});


	shit_throw_emotes = ({
		"Doctor Sphincterani is very happy now that he has flung feces.\n",
		"Doctor Sphincterani tosses some patient residue.\n",
	});
	
	shit_throw_mchannels = ({
		"I think my glove came off in that pile.\n",
		"And thus another inferior lifeform is covered in rectal refuse.\n",
		"That came off my rubber gloves!\n",
	});

	
	balloon_throw_emotes = ({
		"Doctor Sphincterani's face contorts into an evil grin.\n",
		"Doctor Sphincterani grins sadistically.\n",
	});

	balloon_throw_mchannels = ({
		"I'm going to make you wet your pants!\n",
		"Here's to you kid!\n",
		"This is for my mother, you little person.\n",
	});


	arrival_emotes =({
		"Doctor Sphincterani arrives in the full glory of pain.\n",
		"Doctor Sphincterani has come bringing plastic gloves of pain!\n",
	});

	arrival_mchannels =({
		"Pain has a new name. Doctor Sphincterani.\n",
		"Your anal discomfort has arrived!\n",
	});


}

id(str)
{
    return str == "dr" 
        ||str == "doc" 
        || str == "Doc" 
        || str == "proctologist" 
        || str == "masochist" 
        || str == name 
        || str == alias 
        || str == race 
        || str == alt_name;
}

heart_beat() {
    object bob;
    bob = clone_object("/players/vital/dest/acadie/obj/pain.c");
	::heart_beat();
/* This calls the heart_beat in monster.c to handle attacks. */
	if(attacker_ob)
	{
		if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("wil") <
			random(30) )
		{
			if ( !present( "pain_object", attacker_ob) )
			    move_object(bob, attacker_ob);
			say("The doctor pushes "+attacker_ob->query_name()+
				"'s head down between "+ attacker_ob->query_objective()+
				" knees \n\and begins to give an exam to "+
				attacker_ob->query_possessive()+
				" lower gastro-intestinal tract.\n");
		}
	}
}

monster_died()
{
	object rubgloves;
	object corpse;
	corpse=present("corpse",environment());
	if(corpse)
	{
		rubgloves=clone_object("/players/vital/dest/acadie/obj/rubgloves.c");
		move_object(rubgloves,this_object());
		say("\nDr. Sphincterani says: \"Why? Why?!?! WHY!\n I only wanted to probe...er, help people.\"\n");
	}
}
