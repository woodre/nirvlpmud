/*
 * A header file for the MOB guild daemon.
 * Created by languilen for Nirvana.
 * 
 */

#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define ENVOB environment(this_object())
#define ENVTP environment(this_player())

#define ATT TP->query_attack()

#define GUILDNAME "mob"
#define GUILDDIR "/players/languilen/guild/mob/"
#define AUTOLOAD GUILDDIR+"gob:"
#define GUILDOBJ GUILDDIR+"gob"
#define GUILDCMDS GUILDDIR+"cmds/"
#define GUILDSAVE "players/languilen/guild/mob/save/"
#define GUILDROOMS GUILDDIR+"cmds/"

#define GUILD_D "/players/languilen/guild/mob/guild_d.c"
#define TPGO present("MOB_OB", this_player())

#define GUNS ({ ".22 caliber pistol", ".38 caliber pistol", ".45 caliber pistol", ".44 caliber magnum", "tommy gun", "silencer" })

/*  The limit of giving abilities indexed by mtitle  */
#define MAX_GIFT ({ 500, 10000, 25000, 50000, 0 })

