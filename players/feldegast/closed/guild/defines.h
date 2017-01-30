#include "/players/feldegast/defines.h"
#define GUILD_ID "guardian guild object"
#define GUILD_NAME "guardian"
#define GUILD_OBJ "/players/feldegast/closed/guild/gob"
#define SAVE_PATH "players/feldegast/closed/guild/save/"
#define RANK present(GUILD_ID,this_player())->query_rank()
#define MYOB present(GUILD_ID,this_player())
#define OWNER environment(this_object())
#define COMMANDS "/players/feldegast/closed/guild/commands.c"
#define SPELLS "/players/feldegast/closed/guild/cmds/"
#define CMDPATH "/players/feldegast/closed/guild/cmds/"
#define CHANNEL "/players/feldegast/closed/guild/channel"
