#include <security.h>
#include <ansi.h>

#define SAVE_CHAR "players/wren/guild/save/"
#define SAVE_ROOM "players/wren/guild/room/save/"
#define SAVE_DAEM "players/wren/guild/daemons/save/"

#define DIR_ROOT   "/players/wren/guild/"
#define DIR_CMD    (DIR_ROOT+"cmds/")
#define DIR_OBJ    (DIR_ROOT+"obj/")
#define DIR_NPC    (DIR_ROOT+"npc/")
#define DIR_LOG    (DIR_ROOT+"log/")
#define DIR_ROOM   (DIR_ROOT+"room/")
#define DIR_DOC    (DIR_ROOT+"doc/")
#define DIR_STD    (DIR_ROOT+"std/")

#define OBJECT     "/obj/treasure"

#define ROOM       "/players/vertebraker/closed/std/room"
#define G_ROOM     "/players/wren/guild/std/guild_room"

#define DIR_DAEM   (DIR_ROOT+"daemons/")
#define DAEM_SHOP  (DIR_DAEM+"shop")

#define TP this_player()
#define TO this_object()
#define TR tell_room
#define TL tell_object
#define PO previous_object()
#define QN query_name()
#define QL query_level()
#define RN query_real_name()
#define MO move_object
#define CO clone_object
#define ENV environment()
#define RN query_real_name()

#define GUILDNAME "Artificers"

#define OBJID (GUILDNAME+"_gob")

