
inherit "/players/mizan/mbv2/monsterplus.c";
#include "/players/mizan/mbv2/definitions.h"

#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())

reset(arg) {
   ::reset(arg);
   if (!arg) {

     object gold;
     gold = clone_object("obj/money");
     gold->set_money(random(15000) + 35000);
     move_object(gold,this_object());
     move_object(clone_object("/players/pain/closed/weapons/widow"),this_object());
     move_object(clone_object("/players/pain/closed/wands/orb"),this_object());
	 init_command("wield widowmaker");
	 init_command("ready orb");
     set_name("mortus");
     set_short("Mortus, the Necromancer");
     set_race( "human");
     set_alias("necromancer");
     set_long(
"This is the legendary Mortus the necromancer.\n"+
"There is an aura of death about him. He is cloaked in fear and pain.\n"+
"In his hand he holds a dark onyx orb that seems to suck the light out\n"+
"of the room. he wields a bright blade made of gleaming silver that is \n"+
"well worn, yet razor sharp. He has the face of death.\n");
     set_level(30);
/* don't use set_hp
     set_hp(2000);
*/
/* changes for monsterplus */
     max_hp = 4000;
     hit_point = 4000;

     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Mortus sends a few hard nogs out in your direction.\n");
     load_chat("Mortus says: Prepare to meet your maker mortal!\n");
     load_chat("Mortus brandises his blade in preperation for battle.\n");
     load_a_chat("Mortus says: Foolish mortal, now you die!\n");
     load_a_chat("Mortus chortles at your imminent demise.\n");
     set_chance(35);
     set_spell_mess1("Mortus attacks in a rage!\n");
     set_spell_mess2("Mortus grins and fires a deathball!\n");
     set_spell_dam(80);
     set_ac(20+random(20));
     set_wc(50+random(30));
     call_out("rebeat",10);

    /* monsterplus additions */
    is_loaded = 1;

    /* monsterplus specific toggles */
    toggle_on(MODE_BRIEF);
    toggle_on(MODE_SPARING_NEWBIES);
    toggle_off(MODE_BALLOON_THROWER);
    toggle_off(MODE_SHIT_THROWER);
    toggle_off(MODE_CALLS_FOR_BACKUP);

    /* our attributes */
    set_attribute(ATTRIB_VINDICTIVENESS, 80);
    set_attribute(ATTRIB_FEARLESSNESS, 80);
    set_attribute(ATTRIB_PERCEPTION, 90);
    set_attribute(ATTRIB_CRUELTY, 100);
    set_attribute(ATTRIB_INSANITY, 5);
    set_attribute(ATTRIB_GENEROUSITY, 5);

    set_monster_guild_level(3);
    set_monster_guild_rank("True Grit");

    set_chance_of(CHANCE_CORPSE_LOOTING, 75);
    set_chance_of(CHANCE_TAKE_ALL_LOOT, 75);
    set_chance_of(CHANCE_EMOTE_ATTACKED, 30);
    set_chance_of(CHANCE_EMOTE_PANICKED, 10);
    set_chance_of(CHANCE_EMOTE_TAUNTING, 75);
    set_chance_of(CHANCE_EMOTE_TRIUMPH, 75);
    set_chance_of(CHANCE_EMOTE_CASUAL, 5);
    set_chance_of(CHANCE_EMOTE_SCARED, 5);
    set_chance_of(CHANCE_PELTING_THINGS, 5);    /* the chance that these monsters will throw things at players */
    set_int(VAL_INFUSE_POINT, 7500);           /* the amount of coins where the monster infuses back to nexus */
    set_int(VAL_MAX_HEAL_QUOTA, 7500);
	set_int(VAL_HUNTING_THRESHOLD, 4);
    set_int(VAL_RANDOM_MOVE_FREQUENCY, 3);

    /* lots of channel and emote stuff */
    attacked_emotes = ({
        "Beano screams wildly!\n",
        "Beano goes: woot!\n",
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


    shit_throw_emotes = ({
        "Beano grins greasily.\n",
        "Beano cackles biggly!\n",
    });
    
    shit_throw_mchannels = ({
        "Nothing says HAH! like a pile of shit in the face!\n",
        "Shit. Pile. Face. Hilarity ensued.\n",
        "Fecalpottyhumor.com!\n",
    });

    
    balloon_throw_emotes = ({
        "Beano makes a funny face at you.\n",
        "Beano grins biggly.\n",
    });

    balloon_throw_mchannels = ({
        "Woo! Water balloon madness!\n",
        "Someone is soaking wet. Whee!\n",
        "Hee.\n",
    });


    arrival_emotes =({
        "Beano is here!\n",
        "Beano is here! Woot!\n",
    });

    arrival_mchannels =({
        "1 foot, 2 inches, 32 lbs. Beano has a posse.\n",
        "I am here! Yaay!\n",
    });
   }
}

heart_beat() {
  ::heart_beat();
if(MEAT) {
	fearsome(MEAT);
}
return 1;
}

flap() {
  int X;

X = random(15);
call_other(TO,"heal_self",X);
  if(X > 10) {
    say("Mortus's calls on dark spirits to heal himself.\n");
  }
return 1;
}

fearsome(object ob) {
int i;
object meat;
meat = present(ob,environment(TO));
	if(meat) {
		i = random(11);
		switch(i){

	    case 0: cast(ob);
		  break;

	    case 1: widow(ob);
		  break;

	    case 2: cast_wide(ob);
		  break;

	    case 3..4: heal_me();
		  break;

	    case 5..10: return 0;
		  break;
	    }
	  return 1;
	}
}

cast(object ob) {
  tell_room(environment(ob),
    "Mortus casts a deathball at "+ob->query_name()+"!\n");
  tell_object(ob,
    "Mortuss nogs as a Deathball engulfs you!\nYou are hit by a Deathball!\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(50)+10)); return 1; }
  ob->hit_player(random(50)+50);
  return 1;
}

widow(object ob) {
  tell_room(environment(ob),
    "Mortus slashs at "+ob->query_name()+" with Widowmaker, the sword of the Berseker.\n");
  tell_object(ob,
    "Widowmaker rends your flesh from your bones.\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(20)+10)); return 1; }
  ob->hit_player(random(40)+50);
  return 1;
}

cast_wide() {
  object dest, list;
  int i;
  dest = environment(TO);
  tell_room(dest,
"Mortus casts a Deathball that engulfs the entire area!\n\n"+
"As the Deathball engulfs you, you catch a glimpse of infinity.\n");
  list = all_inventory(dest);
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i],dest)) {
      if(list[i]->is_player()) list[i]->add_hit_point(-(random(60)+5));
      if(living(list[i]) && !list[i]->is_player() && list[i]->id() != "mortus") list[i]->hit_player(30);
    }
  }
  return 1;
}

heal_me() {
tell_room(environment(this_object()),
	"Mortus chortles demonically as dark mists surround him!\nMortus draws power and strength from the dark.\n");
call_other(TO,"heal_self",40+random(20));
return 1;
}

rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }

monster_died() {
tell_room(environment(this_object()),
        "Mortus screams one final curse upon you and your descendents and falls lifeless.\n");
write_file("/players/pain/NEW/mon/mortus_log",ctime(time())+this_player()->query_name()+" killed Mortus.\n");
return 0;
}
