#include "/players/x/x.h"

#define GUILDNAME "NIMH Rat"

#define OBJID "nimh_rat_object"
#define GUILD_ID OBJID

#define PATH "/players/x/guilds/nimh/"

#define N_OBJ (PATH+"obj/")
#define N_BIN  (PATH+"cmds/")
#define N_LOG  (PATH+"log/")
#define N_HELP (PATH+"help/")
#define N_DAEM  (PATH+"daemon/")
#define N_ROOM (PATH+"room/")
#define N_SAVE "players/x/guilds/nimh/save/"
#define N_BACKUP "players/x/guilds/nimh/backup/"
#define CRYSTALS "players/x/guilds/nimh/save/crystals/"

#define LOGIN   (ROOMDIR+"???")
#define DEST    "/players/x/workroom"

#define NEWS    "/players/x/guilds/nimh/news"

#define OBJFILE "/players/x/guilds/nimh/gob"
#define MASTER  "/players/x/guilds/nimh/daemon/master"
#define CHANNELD (DAEMDIR+"channeld")
#define N_EFUN  "/players/x/guilds/nimh/daemon/efun"
#define GUILDROOM "/players/x/guilds/nimh/obj/guild_room"

#define IS_NIMH_TESTER(ob) ((string)ob->query_real_name()=="x")
#define HOLE_ID "nimh_guild_hole"

