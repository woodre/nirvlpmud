inherit "/room/room";
#include "/players/pain/color.h"

int elf;

reset() {
	short_desc = "Deeper in the "+BOLD+GREEN+"Vale"+END;
	long_desc = "The path continues deeper into the "+BOLD+GREEN+"Vale"+END+",\n"+
		"drawing you further into the secret world of the Elves. It is very\n"+
		"quiet in this section of the Vale, the trees are much older here,\n"+
		"and the leaves form a sort of awning above you, covering the path\n"+
		"in a blanket of cool shade. A peaceful feeling overcomes you as you\n"+
		"journey further along. You wonder what secrets nature will share with\n"+
		"you as you wander through this ancient place.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/flet/fpath3", "northwest",
		"/players/pain/NEW/flet/fpath1", "southeast",
		});

	items = ({
		"path", "A crude dirt path leading through the Vale",
		"leaves", "The leaves overhead are so thick they almost choke out the light",
		"trees", "The oldest trees you have ever seen, you wonder if they are the\n"+
			"mythical Mallorn trees you've heard of in legend",
		});
	
	call_out("noises",10);
}

init() {
	::init();
	add_action("northwest","northwest");
}

northwest() {
if(!elf) {
	tell_room(this_object(),"You hear a rustling to the right of the path and stop.\n");
	tell_room(this_object(),"An old Elf steps onto the path in front of you.\n");
	tell_room(this_object(),"Old Elf says: Wait! There is something you must know before you go on.\n\n");
	call_out("next_say",10);
	elf = 1;
	return 1;
}
else this_player()->move_player("northwest#/players/pain/NEW/flet/fpath3");
return 1;
}

next_say() {
	tell_room(this_object(),"Old Elf says: Our Elven Warlord can be a powerful ally.\n\n");
	tell_room(this_object(),"Old Elf says: He is wise about more than just the ways of battle.\n\n");
	tell_room(this_object(),"Old Elf says: However, he has been deeply saddened since the death of his sons,\n"+
		"Elban the Starbringer and Ethori the Smokeshadow at the hand of Mortus the Necromancer.\n\n");
	tell_room(this_object(),"The Old Elf pauses for a moment and looks around.\n\n\n\n");
	call_out("next_say2",20);
	return 1;
}

next_say2() {
	tell_room(this_object(),"Old Elf says: Having conquered Elban and Ethori, Mortus has crushed the\n"+
		"Elven hopes of freedom from his looming tyranny.\n\n");
	tell_room(this_object(),"Old Elf whispers to you: I've been hearing rumors....\n\n");
	tell_room(this_object(),"The Old Elf quickly scans the trees along the path.\n\n");
	tell_room(this_object(),"Old Elf says: Perhaps I shouldn't be telling you this.\n\n");
	tell_room(this_object(),"The Old Elf wavers and thinks to himself for a moment\n");
	call_out("next_say3",25);
	return 1;
}

next_say3() {
	tell_room(this_object(),"The Old Elf sighs deeply.\n\n");
	tell_room(this_object(),"Old Elf says: I fear I have no choice but to ask your help, as my\n"+
		"people are desperate.\n\n");
	tell_room(this_object(),"Old Elf says: Please go see our King, you'll find him in his stronghold\n"+
		"high up in the Flet. We need your help.\n\n");
	tell_room(this_object(),"Old Elf says: All of the races are threatened, the Elves, the Dwarves, and\n"+
		"even the Humans. We must band together to defeat this evil. The King will tell you more.\n\n");
	tell_room(this_object(),"The Old Elf looks fearfully about and then vanishes just as abruptly as\n"+
		"he appeared.\n\n");
	return 1;
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
	number = random(3);
	if(number == 0) {
		/* noise 1 */
		tell_room(this_object(),"You think you hear quiet whispering in the trees around you.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"The wind blows softly through the leaves overhead.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"You hear some rustling along the path up ahead.\n");
	}
	call_out("noises",30);
	return 1;
}
