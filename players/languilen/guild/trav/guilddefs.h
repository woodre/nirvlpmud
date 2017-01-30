/*
 * Defines for The Traveler's Guild
 * Created by languilen for Nirvana.
*/

#define GUILDNAME "traveler"
#define GUILDDIR "/players/languilen/guild/trav/"
#define AUTOLOAD GUILDDIR+"gob:"
#define GUILDOBJ GUILDDIR+"gob"
#define GUILDCMDS GUILDDIR+"cmds/"
#define GUILDSAVE "players/languilen/guild/trav/save/"
#define MODULE GUILDDIR+"room/mod.c"

#define GUILD_D "/players/languilen/guild/trav/guild_d.c"
#define TPGO present("TRAV_OB", this_player())
#define MOD TPGO->query_mod()

#define TP this_player()
#define TPN TP->query_name()
#define ENVOB environment(this_object())
#define ENVTP environment(this_player())

