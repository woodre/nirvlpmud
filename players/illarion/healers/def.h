#include <ansi.h>

#define ROOTDIR      "/players/illarion/healers/"
#define POWER        ROOTDIR+"powers/"
#define POWERBASE    "/players/illarion/healers/powers/base"
#define SAVES        ROOTDIR+"saves/"
#define DAEM         "/players/illarion/healers/daemons/main.c"
#define GOB_PATH     "/players/illarion/healers/gob.c"
#define GUILD_OB_ID  "healer_guild_object"
#define SCALE        "/players/illarion/healers/util/scale"
#define ANSIPAD(x,y) "/players/illarion/healers/util/ansi_pad"->ansi_pad(x,y)

#define TO       this_object()
#define TP       this_player()
#define ENV(x)   environment(x)

#define FAIL(x)  { notify_fail(x); return 0; }
