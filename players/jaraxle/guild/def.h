#define SAVE_PATH "players/jaraxle/guild/save/"
#define GUILDNAME "mutant" /* ??? */
#define OBJID "mutant_guild_object"
#define CMD_DIR "/players/jaraxle/guild/cmds/"
#define GSTAT_MAX 20
#define SENSEI_RANK 50
#include "/players/jaraxle/ansi.h"

mixed
marked(object ob)
{
    object o;
    o = present(OBJID, ob);
    if(o) return o;
    else return 0;
}

#define AUTOLOAD "/players/jaraxle/guild/gob"

