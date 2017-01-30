/*
 * A header file for the MOB guild object.
 * 
 */

#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()

#define ENVOB environment(this_object())
#define ENVTP environment(this_player())

#define GUILDNAME "mobster"
#define GUILDDIR "/players/languilen/guild/mob/"
#define AUTOLOAD GUILDDIR+"gob:"
#define GUILDOBJ GUILDDIR+"gob"
#define GUILDCMDS GUILDDIR+"cmds/"
#define GUILDSAVE "players/languilen/guild/mob/save/"
#define GUILDROOMS GUILDDIR+"room/"

#define GUILD_D "/players/languilen/guild/mob/guild_d.c"
#define TPGO present("MOB_OB", this_player())

