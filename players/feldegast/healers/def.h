#include "/players/feldegast/defines.h"
#define MASTER      "/players/feldegast/healers/master.c"

#define PATH        "/players/feldegast/healers/"
#define SAVEPATH    "players/feldegast/healers/saves/"
#define BANPATH     "/players/feldegast/healers/banish/"
#define CMDSPATH    "/players/feldegast/healers/cmds/"
#define ROOMPATH    "/players/feldegast/healers/rooms/"
#define DOCSPATH    "/players/feldegast/healers/docs/"
#define OBJPATH     "/players/feldegast/healers/obj/"
#define KNOWPATH    "/players/feldegast/healers/doc/"
#define NPCPATH     "/players/feldegast/healers/npc/"
#define STORAGEPATH "players/feldegast/healers/storage/"

#define DEBUG_FILE  "/players/feldegast/healers/debug.log"
#define AREANAME    CYN+"Healer Hall"+NORM
#define GUILD_STRING "Healer"
#define GUILD_ID    "healer guild object"
#define MYOB        present(GUILD_ID,this_player())
#define KARMA       (int)MYOB->query_karma()
#define KARMA_MSG   "Your thoughts are too chaotic.\n"
#define hlog(x,y) write_file("/players/feldegast/healers/log/"+x, ctime(time())+" "+y)
