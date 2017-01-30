#define TP this_player()
#define TO this_object()
#define ENV environment
#define ENVTO ENV(TO)
#define NOTME TP != ENVTO
#define RN query_real_name()
#define TPRN TP->RN
#define TPN TP->query_name()
#define TE tell_object
#define GOB "/players/shinshi/healers/gob.c"
#define GID "new_healers"
#define CHAN_NAME 	"Healer"
#define CHAND 		"/bin/channel_daemon.c"
#define CHATOB "/players/shinshi/healers/objs/chatob.c"
#define HALLPATH "/players/shinshi/healers/hall/"
#define HALLRMS  "/players/shinshi/healers/hall/rooms/"
#define HALLNPC  "/players/shinshi/healers/hall/mobs/"
#define HELPPATH "/players/shinshi/healers/help/"
#define LOGPATH  "/players/shinshi/healers/logs/"
#define MEMPATH  "players/shinshi/healers/members/"
#define OBJECTPATH "/players/shinshi/healers/objs/"
#define SPELLPATH "/players/shinshi/healers/spells/"
#define LEFTPATH "/players/shinshi/healers/left/"

/*                            lvl,  sp,   hp, heal, diff, type*/
#define HEAL_VAR            ({  5,   1,    0,    1,   20,    1})

