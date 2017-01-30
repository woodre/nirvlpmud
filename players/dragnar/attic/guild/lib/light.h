#include "/players/dragnar/guild/defs/def.h"
light() {
	object lantern;
	if(usp < 5) {
	write("You don't have enough spell points to sacrifice.\n");
	return 1; }
	guildobj->set_light_on();
	write("You raise your hands to the sky and the room is blasted with light.\n");
	say(""+capname+" raises his hands to the sky and you are blinded by light.\n");
	user->add_spell_point(-5);
	return 1; }
