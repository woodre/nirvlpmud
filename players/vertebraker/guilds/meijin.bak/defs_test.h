#include "/players/pavlik/guild/colors.h"
#include "/players/pavlik/guild/map.h"
#define GUILDNAME "meijin"
#define GUILDFILE "/players/pavlik/guild/gob.c"
#define POWERS "/players/pavlik/guild/powers/"
#define DAEMON "/players/pavlik/guild/master.c"
#define SAVEPATH "players/pavlik/guild/players/"
#define START_ROOM "players/pavlik/guild/room/start"
#define OBJ_ROOM "players/pavlik/guild/room/obj_room"
#define GOB present("pavlik_guild_obj", this_player())
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
#define PRE HIB+"> "+NORM
#define PREW HIW+"> "+NORM
#define PRED HIB+">> "+NORM
