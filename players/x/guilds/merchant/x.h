#include "/players/x/x.h"

#define GUILDNAME "Merchant"

#define OBJID "merchant_object"
#define GUILD_ID OBJID

#define PATH "/players/x/guilds/merchant/"

#define M_OBJ  (PATH+"obj/")
#define M_BIN  (PATH+"cmds/")
#define M_LOG  (PATH+"log/")
#define M_HELP (PATH+"help/")
#define M_DAEM (PATH+"daemon/")
#define M_ROOM (PATH+"room/")
#define M_SAVE   "players/x/guilds/merchant/save/"
#define M_BACKUP "players/x/guilds/merchant/backup/"

#define LOGIN   (M_ROOM+"???")
#define DEST    "/players/x/workroom"

#define NEWS    "/players/x/guilds/merchant/news"

#define OBJFILE "/players/x/guilds/merchant/gob"
#define MASTER  "/players/x/guilds/merchant/daemon/master"
#define M_EFUN  "/players/x/guilds/merchant/daemon/efun"

#define GUILDROOM "/players/x/guilds/merchant/obj/guild_room"

#define IS_MERCHANT_TESTER(ob) ((string)ob->RN=="x" ||\
                                (string)ob->RN=="a" ||\
                                (string)ob->RN=="ahnuld")

