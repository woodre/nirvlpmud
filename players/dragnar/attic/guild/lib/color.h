#include "/players/dragnar/guild/defs/def.h"
color() {
	int cl;
	if(guildobj->query_color_flag() == 0) {
	cl = 1;
	guildobj->set_color(cl);
	write("Guild Color is now ON.\n");
	return 1; }
	if(guildobj->query_color_flag() == 1) {
	cl = 0;
	guildobj->set_color(cl);
	write("Guild Color now set to OFF.\n");
	return 1; }
}
