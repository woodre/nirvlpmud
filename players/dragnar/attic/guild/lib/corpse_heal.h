#include "/players/dragnar/guild/defs/def.h"
corpse_heal() {
	object corpse;
	corpse = present("corpse", environment(user));
	if(!corpse) { write("There is no corpse here to sacrifice.\n"); return 1; }
	user->heal_self(corpse->heal_value());
	destruct(corpse);
	write("You whisper some words and the corpse bursts into flames.\n");
	say(capname+" whispers some words and the corpse bursts into flames.\n");
	return 1;
}
