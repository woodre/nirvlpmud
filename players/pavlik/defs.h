#include "/players/pavlik/guild/colors.h"
#include "/players/pavlik/guild/mapping.h"
#define GUILDNAME "meijin"
#define GUILDID GUILDNAME+"_obj"
#define ALLYID GUILDNAME+"_ally_obj"
#define GUILDFILE "/players/pavlik/guild/gob.c"
#define POWERS "/players/pavlik/guild/powers/"
#define DAEMON "/players/pavlik/guild/master.c"
#define SAVEPATH "players/pavlik/guild/players/"
#define ALLYSAVEPATH "players/pavlik/guild/players/allies/"
#define START_ROOM "players/pavlik/guild/room/start"
#define OBJ_ROOM "players/pavlik/guild/room/obj_room"
#define GOB present(GUILDID, this_player())
#define ENV environment(this_object())
#define TP this_player()
#define ME capitalize((string)this_player()->query_name())
#define IT capitalize((string)obj->query_name())
#define MYNAME capitalize((string)ENV->query_name())
#define POS this_player()->query_possessive()
#define HAND handed[0]
#define OFFHAND handed[1]
#define STATSTART 1
#define BASE_GUILD_COST 510
#define MONEY_MAX 50000
#define DONATION_MAX 65000
#define PRE HIB+"> "+NORM
#define PREW HIW+"> "+NORM
#define PRED HIB+">> "+NORM
