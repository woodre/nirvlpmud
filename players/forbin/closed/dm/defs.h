#include "/players/forbin/ansi.h"

#define GUILDNAME "Dark Mages"
#define GUILD_FILE "players/forbin/closed/dm/dm"
#define DIR "/players/forbin/closed/dm/"
#define CMDDIR "/players/forbin/closed/dm/cmds/"
#define SPELLS "/players/forbin/closed/dm/spells/"
#define EFFECTS "/players/forbin/closed/dm/OBJ/effects/"
#define SPELL "/players/forbin/closed/dm/std/spell.c"
#define HELP "/players/forbin/closed/dm/help/"
#define SAVE_PATH "players/forbin/closed/dm/member/"
#define SAVE_BAK SAVE_PATH+"/bak/"
#define TASKS "/players/forbin/closed/dm/task/"
#define DM environment(this_object())
#define DMGOB present("forbin_dm_object", this_player())

#define QN query_name()
#define QRN query_real_name()
/* his her */
#define QP query_possessive()
/* him her */
#define QO query_objective()
/* he she */
#define QPN query_pronoun()

#define TP this_player()
#define PO previous_object()
#define GOB previous_object()