#include <ansi.h>

#define CMDS   "/players/x/guilds/knights/cmds/"
#define POWERS "/players/x/guilds/knights/powers/"
#define SPELLS "/players/x/guilds/knights/spells/"
#define WIZ    "/players/x/guilds/knights/wiz/"
#define EMOTES "/players/x/guilds/knights/emotes/"
#define SAVE   "players/x/guilds/knights/save/"
#define GC     "/players/x/guilds/knights/gc/"

#define EFFECTS "/players/x/guilds/druid/spells/effects/"

#define CHANNEL "/players/x/guilds/knights/daemons/channel"
#define LANG    "/players/x/guilds/knights/daemons/lang"

#define SPELL "/players/x/guilds/knights/std/spell"

#define gob present("knight_object", this_player())

#define l_write(x) write((string)LANG->translate_sentence(x))
