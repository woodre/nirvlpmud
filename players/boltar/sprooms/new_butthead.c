inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

#define MY_FILENAME "/players/boltar/sprooms/new_butthead.c"
object butthead;

reset(arg)
{
    object weapon,leather_jacket;
    butthead = this_object();
    ::reset(arg);
    if(arg) return;

    /* standard game lib stuff */
    set_name("Butthead");
    set_race("human");
    set_alias("butthead");
    set_alt_name("buttheadedmoron");
    set_short("Butthead the moron (stupid)");
    set_long("Butthead is an ugly teenager that loves heavy metal music.\n");

    set_level(12);
    set_gender("male");
    
    /* we use raw numbers because i overrode set_hp() */
    max_hp = 350;
    hit_point = 350;

    set_al(-60);
    set_wc(5);
    set_ac(0);

	set_object(this_object());
	set_function("why_did");
	set_type("sells");
	set_match(" ");
	set_type("attack");
	set_match(" ");
	set_type("left");
	set_match("the game");
	set_type("takes");
	set_match(" ");
	set_type("drops");
	set_match(" ");
	set_function("how_does_it_feel");
	set_type("is now level");
	set_match(" ");
	set_function("smiles");
	set_type("smiles");
	set_match(" happily.");
	set_function("say_hello");
	set_type("arrives");
	set_match("");
	set_function("test_say");
	set_type("says:");
	set_match(" ");
	set_type("tells you:");
	set_match(" ");
	set_function("follow");
	set_type("leaves");
	set_match(" "); 
	set_function("gives");
	set_type("gives");
	set_match(" ");
	

    
    /* autoheals twice as fast other monsters, cos it cannot call from the pink laser */
    set_heal(6,2);

    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_off(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_on(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);
    toggle_off(MODE_KID_KILLER);
    toggle_on(MODE_PET_KILLER);
    toggle_off(MODE_PK_INSTIGATOR);
    toggle_on(MODE_USE_REMOTE_WAYPOINTS);
    toggle_off(MODE_CORPSE_EATER);
    toggle_off(MODE_SLOW_HITFADES);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 30);
    set_attribute(ATTRIB_FEARLESSNESS, 10);
    set_attribute(ATTRIB_PERCEPTION, 40);
    set_attribute(ATTRIB_CRUELTY, 60);
    set_attribute(ATTRIB_INSANITY, 90);
    set_attribute(ATTRIB_GENEROUSITY, 20);

    set_monster_guild_level(1);
    set_monster_guild_rank("Chaotic");

    set_string(STR_TEAM_NAME, "ArmyOfBoltar");
    set_string(STR_CABAL_NAME, "Gangstahs");

    set_chance_of(CHANCE_CORPSE_LOOTING, 100);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 20);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 20);
    set_chance_of(CHANCE_EMOTE_PANICKED, 50);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 20);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 10);
    set_chance_of(CHANCE_EMOTE_CASUAL, 20);
    set_chance_of(CHANCE_EMOTE_SCARED, 15);
    set_chance_of(CHANCE_PELTING_THINGS, 9);    /* the chance that these monsters will throw things at players */

    set_int(VAL_INFUSE_POINT, 15000);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 500);
	set_int(VAL_HUNTING_THRESHOLD, 100);        /* make him extra hard to get pissed off */
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 25);     

    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Butthead says: Blood's cool.\n",
        "Butthead says: Fire! Fire!\n",
        "Butthead says: heh hehehhe hehheh\n",
        "Butthead says: Swords are cool.\n",
        "Butthead pukes all over you!\n",
        "Butthead says: Bastard\n",
    });

	attacked_mchannels = ({
        "This is Joey Buttafuoco's theme song.\n",
        "Drums, guitar and Death. They finally got it right.\n",
        "I like to blow up lizards.\n",
        "Eh heh heh, yeah. And I like to burn things.\n",
        "That's not funny, dumbass!\n",
        "I wish this video had some explosions. That would be cool.\n",
        "Heh heh henh hmm heh. It does have some explosions. Heh henh hmm.\n",
        "Hammers are cool.\n",
        "Yeah, I like to take hammers, and just break stuff, just break stuff.\n",
	});


    panicked_emotes = ({
        "Butthead screams wildly!\n",
        "Butthead appears flustered!\n",
    });

	panicked_mchannels = ({
        "My arm! \n",
        "The great cornholio!\n",
        "yaahhehaahggga\n",
	});

    
    hit_hard_emotes = ({
        "Butthead screams painfully!\n",
        "Butthead cries loudly!\n",
    });

    hit_hard_mchannels = ({
        "OUCH that hurt bunghole!\n",
        "Heheh that was coool.\n",
        "Bunghole! Bunghole!\n",
    });


    taunting_emotes = ({
        "Butthead glares at you with a blank stare.\n",
        "Yeah. You could, like, fill a balloon with snot and throw it at someone.\n",
        "I wonder how Axl Rose would feel if he got his ass kicked by a couple of 14 year olds.\n",
        "Butthead drools in anticipation.\n",
    });

    taunting_mchannels = ({
        "Fire!!\n",
        "That chick is coool!\n",
        "Yeah, that would really suck. Getting your asses kicked by Kris Kross. Heh\n",
    });


    triumph_emotes = ({
        "Butthead grins stupidly.\n",
        "This chainsaw is pretty cool. Pruning is cool.\n",
    });

    triumph_mchannels = ({
        "I'm gonna slap you around like a red-headed step child.\n",
        "Words suck.\n",
        "I wish this video had some explosions. That would be cool.\n",
        "He said butt.. heh...heheh.\n",
        "Everything I know, I learned from my Dad.\n",
    });


    casual_emotes = ({
        "Butthead says: This sucks.\n",
        "Butthead says: Stop in the name of all that does not suck.\n",
        "Butthead says: Fire! Fire!.\n",
        "Butthead says: Fire's cool.\n",
        "Butthead says: huh huh ha ha ha.\n",
        "Butthead says: He said sex.. heh...heheh.\n",
        "Butthead says: Diareia cha cha cha.\n",
        "Butthead says: Shut up dumb ass.\n",
        "Butthead says: Let's go buy some balloons, dude.\n",
        "Butthead says: heh heh heh hah.\n",
        "Butthead says: Pull my finger.\n",
        "Butthead says: If I wanted to read I would be in school.\n",
        "Butthead says: This sucks!\n",
        "Butthead says: We're going down to Babes R Us.\n",
        "Butthead grins evilly.\n",
    });

    casual_mchannels = ({
    "Look, I'm strokin' my weiner.\n",
    "Hey Beavis, let's pretend we're dead.\n",
    "Yeah. It looks cool.\n",
    "Calm down Beavis. You're gonna soil your drawers.\n",
    "We're going to explore the world of getting high?  Cool!\n",
    "Hey Beavis. Guess where his hand's been.\n",
    });


    scared_emotes = ({
        "Butthead appears somewhat flustered.\n",
    });
    
    scared_mchannels = ({
        "You'd complain too if you sucked!\n",
        "You asswipe! I was about to have a wet dream!\n",
        "That's not funny, dumbass!\n",         
    });


    death_emotes = ({
        "Butthead falls  to the ground. Dead.\n",
    });

    death_mchannels = ({
        "I died...Whoa. Is this like the weather channel?\n",
    });


    shit_throw_emotes = ({
        "Drums, guitar and Death. They finally got it right.\n",
    });
    
    shit_throw_mchannels = ({
        "Heh heh heh eh eh eh heh heh heh\n",
    });

    
    balloon_throw_emotes = ({
        "Rurhruhruhruhruhruhruhruhruhruhruhruhruhrurh!!!!!!.\n",
    });

    balloon_throw_mchannels = ({
        "Rurhruhruhruhruhruhruhruhruhruhruhruhruhrurh!!!!!!\n",
    });


    arrival_emotes =({
        "Butthead wanders in aimlessly.\n",
    });

    arrival_mchannels =({
        "The future sucks. Change it.\n",
    });

        leather_jacket = clone_object("obj/armor");
        call_other(leather_jacket, "set_name", "Metalica shirt");
        call_other(leather_jacket, "set_short", "An Metalica shirt");
        call_other(leather_jacket, "set_alias", "shirt");
        call_other(leather_jacket, "set_long", "A plain ordinary Metalica T-shirt\n");
        call_other(leather_jacket, "set_value", 600);
        call_other(leather_jacket, "set_weight", 2);
        call_other(leather_jacket, "set_ac", 3);
        call_other(leather_jacket, "set_type", "armor");
        move_object(leather_jacket, butthead);
        call_other(butthead, "init_command", "wear shirt");
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "A chain saw");
        call_other(weapon, "set_alias", "saw");
        call_other(weapon, "set_class", 14);
        call_other(weapon, "set_value", 750);
        call_other(weapon, "set_weight", 4);
        move_object(weapon, butthead);
        call_other(butthead, "init_command", "wield saw");

}

/* eof */

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Butthead says:  " + what + "'s are cool.\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Butthead says:  " + who + " fighting " + what + " sucks.\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Butthead says:  quiting's cool.\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Butthead says:  " + who + " sucks.\n" + what + "'s suck!\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Butthead says:  " + who + " droped a " + what + " heheh heh cool. \n");
      }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Butthead says: level " + what+" is cool.");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "butthead" || who == "Butthead")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Butthead") {
	notify("Butthead grins evilly.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Butthead says: " + who + " sucks.\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "butthead" || a == "Butthead")
	return;
    if(a == "butthead" || a == "Butthead")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Butthead says: You suck.\n";
    }
    if (str == "shut up") {
	message = "Butthead says: Shut up yourself.\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Butthead says: Ok then.\n";
    }
    if(!message)
	message = "Butthead says: '" + str + "' sucks\n";
    notify(message);
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	call_other(butthead, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Butthead")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Butthead sighs and says: I guess you're gonna kill me now.\n");
		obj = first_inventory(butthead);
		while(obj) {
		    next_obj = next_inventory(butthead);
		    transfer(obj, environment(butthead));
		    notify("Butthead drops " + call_other(obj, "short") + ".\n");
		    obj = next_obj;
		}
		call_other(butthead, "init_command", "west");
	    }
	}
	if(rand == 1) {
	    call_other(butthead, "init_command", "drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(butthead);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, environment(butthead));
	    notify("Butthead drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(butthead);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Butthead returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Butthead says: HEY, bury your corpses yourself, asshole.\n");
	obj = first_inventory(butthead);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Butthead returned the " + what + " to " + who + ".\n");
    } else {
	notify("Butthead says: Thank you very much, sir.\n");
    }
}
