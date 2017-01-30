/* <change by="Erasmios" date="2001-07-08"> */
inherit "/players/guilds/bards/pet/petbase2";
#include "/players/maledicta/ansi.h"
#define FAERIE HIY+"F"+HIB+"a"+HIG+"e"+HIM+"r"+HIW+"i"+HIR+"e"+NORM 
int spell_pts;  /*  Requires them for special stuff */

create()
{
	::create();
    spell_pts = 200;
	set_self_damage(50);
    no_allow_attack = 1;
	set_name("faerie");
	set_short("a "+FAERIE+" folk");
	set_alt_name("faerie folk");
	set_gender("creature");
	set_race("faerie");
	set_long(
		"The "+FAERIE+" looks like a tiny 8 inch tall human with\n"+
		"beautiful butterfly wings on its back.  It hovers\n"+
		"around its Bard friend with fluttering motions.\n");
	set_level(15);
	set_heal(4, 10);
	set_ac(10);
	set_wc(5);
	set_hp(250);
	set_al(1000);
	set_aggressive(0);
	set_chat_chance(3);
	set_a_chat_chance(2);
	load_chat("The "+FAERIE+" giggles.\n");
	load_chat("The "+FAERIE+" flies around its Bard friend's head.\n");
	load_chat("The "+FAERIE+" says \"\Whoa! Strong breeze!\"\n");
	load_chat("The "+FAERIE+" asks \"\Can I help you?\"\n");
	load_chat("The "+FAERIE+" dances on its Bard's shoulder.\n");
	load_chat("The "+FAERIE+" circles overhead.\n");
	load_a_chat("The "+FAERIE+" seems VERY angry!\n");
	set_spell_mess1("The "+FAERIE+" casts a "+HIY+"charged bolt"+NORM+" at its enemy!");
	set_spell_mess2("The "+FAERIE+" strikes you with a "+HIY+"charged bolt"+NORM+"!");
	set_chance(10);
	set_spell_dam(5);
}

a_short()
{
	return "A Faerie";
}

the_short()
{
	return "The Faerie Folk";
}

sic_sound(str)
{
	return ("The Faerie flies towards " + capitalize(str) + ".\n");
}

munch_sound()
{
	return ("The Faerie flies down to the corpse and sprinkles dust on it."+
		"The corpse disappears!\n");
}
/* </change> */

heart_beat(){
	object mff;
	object poison, next;
	string a, b;
	int done;
	::heart_beat();
    if(!environment()) return;
	if(spell_pts < 0) spell_pts = 0;
	if(spell_pts < 198 && !random(3)) spell_pts += 2;
    done = 0;
	mff = present(query_master_name(), environment());
    if(attacker_ob) {
tell_room(environment(), short()+" goes INSANE!\n"); attacker_ob->hit_player(50+random(50),"other|good"); return; 
    }
    if(!mff || spell_pts < 6) return;
	if(spell_pts > 15 && random(100) < 5 && mff){
		if(mff->query_hp() < mff->query_mhp()){
			mff->add_hit_point(10);
			switch(random(4) + 1){
				 case 4:				
					 tell_object(mff,
						 "The "+FAERIE+" reaches out and touches you on the nose!\n"+
						 "You feel better.\n");
					 break;
				 case 3:
					 tell_object(mff,
						 "The "+FAERIE+" lands on your shoulder and winks at you.\n"+
						 "You feel better.\n");
					 break;
				 case 2:
					 tell_object(mff,
						 "The "+FAERIE+" hovers before your face and blows dust at you.\n"+
						 "You feel better.\n");
					 break;
				 case 1:
					 tell_object(mff,
						 "The "+FAERIE+" winks at you and touches you lightly.\n"+
						 "You feel better.\n");
					 break;
			}
			spell_pts -= 15;
		}
	}
	else if(spell_pts > 5 && random(100) < 8 && mff){
		if(mff->query_stuffed()){
			tell_object(mff, 
				"The "+FAERIE+" touches your belly..\n"+
				"You feel better.\n");
			mff->add_stuffed(-2);
		}
		if(mff->query_soaked()){
			tell_object(mff, 
				"The "+FAERIE+" pats you on the back..\n"+
				"You burp.\n");
			mff->add_soaked(-2);
		}
		spell_pts -= 5;
	}

	else if(spell_pts > 100 && random(100) < 20 && mff){
		poison = first_inventory(mff);
		while(poison){
			next = next_inventory(poison);
			if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
      poison->id("toxin") || poison->id("poison") || poison->id("toxin2") ||
      poison->id("toxin3") || poison->id("crotchrot") || poison->id("disease") ||
     poison->id("virus") || poison->id("worm") || poison->id("illness") ||
      poison->id("sickness") || poison->id("darkness") || poison->id("ill") ||
      poison->id("sick") || poison->id("curse") || poison->id("rot"))
   {
					if(!done){
						tell_object(mff, 
							"The "+FAERIE+" circles anxiously over your head!\n"+
							FAERIE+" says,\"Oh my! Oh my!  You are poisoned!\"\n"+
							FAERIE+" touches you on the forehead and you instantly feel better!\n");
						spell_pts -= 100;
						done = 1;
						destruct(poison);
					}
				}
				poison = next;
		}
	}
}
