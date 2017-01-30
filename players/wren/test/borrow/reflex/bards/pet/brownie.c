/* <change by="Erasmios" date="2001-07-08"> */
/*  Brownie Pet is a nonstandard pet that attacks
    only occassionally, (vs. 20th level mob, 5%
	chance per round).  It doesn't get directly
	into combat, and has no purpose other than
	sitting back and firing now and then.  It is
	the 'safe' pet for combat.  Not as effective
	as a drake.
*/

inherit "/players/reflex/guilds/bards/pet/petbase2";
#include "/players/maledicta/ansi.h"
#define BROWNIE YEL+"Brownie"+NORM 

create()
{
	::create();
	set_self_damage(50);
	walk = 1;
	no_allow_attack = 1;
	set_name("brownie");
	set_short("a "+BROWNIE+" "+HIW+"archer"+NORM);
	set_alt_name("archer");
	set_gender("creature");
	set_race("brownie");
	set_long(
		"This is a 2' tall humanoid with jet black hair and\n"+
		"grey eyes.  His skin is a light brown, and he wears\n"+
		"clothes that seem to blend with the surroundings. He\n"+
		"is holding a very small, but powerful bow.\n");
	set_level(15);
	set_heal(4, 10);
	set_ac(10);
	set_wc(8);
	set_hp(100);
	set_al(1000);
	set_aggressive(0);
	set_chat_chance(3);
	set_a_chat_chance(2);
	load_chat("The "+BROWNIE+" sniffs the air.\n");
	load_chat("The "+BROWNIE+" glances up at his friend.\n");
	load_chat("The "+BROWNIE+" watches patiently.\n");
	load_chat("The "+BROWNIE+" adjusts his bow.\n");
	load_chat("The "+BROWNIE+" steps carefully.\n");
	load_chat("The "+BROWNIE+" guards his friend.\n");
	load_a_chat("The "+BROWNIE+" sneers in anger!\n");
	set_spell_mess1("The "+BROWNIE+" fires a piercing arrow!");
	set_spell_mess2("The "+BROWNIE+" strikes you with a piercing arrow!");
	set_chance(15);
	set_spell_dam(15);
}

a_short()
{
	return "A Brownie";
}

the_short()
{
	return "The Brownie";
}

sic_sound(str)
{
	return ("The Brownie steps towards " + capitalize(str) + ".\n");
}

munch_sound()
{
	return ("The Brownie flies down to the corpse and sprinkles dust on it."+
		"The corpse disappears!\n");
}
/* </change> */

heart_beat(){
	object mff;
	object att;
	int dam;
	::heart_beat();
	if(!environment()) return;
	mff = present(query_master_name(), environment());
	if(!mff) return;
	if(att = mff->query_attack()){
		if(att->is_player()) return;
		if(att->query_level() > 20){
			if(!random(10)){
				tell_object(mff,
					BROWNIE+" says,\"You see the size of that thing?!?\"\n");
			}
                return;
		}
		if(random(100) < 27 - att->query_level() &&
			att->query_hp() > 15){
				dam = random(10) + 1;
				att->heal_self(-dam);
				switch(dam){
		   case 10: 
			   tell_room(environment(),
				   BROWNIE+"'s eyes narrow as he lines up a perfect shot...\n"+
				   att->query_name()+" is struck in the neck!\n");
			   break;
		   case 7..9:
			   tell_room(environment(),
				   BROWNIE+"'s eyes narrow as he lines up a good shot...\n"+
				   att->query_name()+" is struck in the chest!\n");
			   break;
		   case 4..6:
			   tell_room(environment(),
				   BROWNIE+" searches for an open as he lines up a decent shot...\n"+
				   att->query_name()+" is struck in the arm!\n");
			   break;
		   case 2..3:
			   tell_room(environment(),
				   BROWNIE+" jumps around as he tries to find a shot...\n"+
				   att->query_name()+" is struck in the leg!\n");
			   break;
		   case 1:
			   tell_room(environment(),
				   BROWNIE+" looks at you in frustration as you get in his way...\n"+
				   att->query_name()+" is barely struck by a glancing arrow!\n");
			   break;
		   default:
			   tell_room(environment(),
				   BROWNIE+"'s eyes narrow as he lines up a good shot...\n"+
				   att->query_name()+" is struck in the chest!\n");
			   break;
				}
				return;
			}
			if(!random(15)){
				tell_object(mff,
					BROWNIE+" searches for an opening to fire!\n");
			}
				return;

	}
}