#include "/players/wocket/closed/ansi.h"
#define MAGEDIR "/players/wocket/mages/"
#define MAGEDIR2 "/players/feldegast/mages/"

#define ROOMDIR "/players/wocket/mages/rooms/"
#define TOWERDIR "/players/feldegast/guild/rooms/"
#define NPCDIR "/players/wocket/mages/npc/"
#define SPELLDIR "/players/wocket/mages/spells/"
#define SAVEDIR "players/wocket/mages/members/"
#define MEMBERDIR "/players/wocket/mages/members/"
#define OBJDIR "/players/wocket/mages/obj/"
#define DOCDIR DOCDIR+"docs/"
#define CMDDIR MAGEDIR+"cmds/"
#define LOGDIR "/players/wocket/mages/logs/"

#define CHANNELD "/players/wocket/mages/daemons/channelD.c"

#define GUILD_ID "secret_mage_guild_ob_name"

#define BOOK present(GUILD_ID,this_player())
#define MAGEAUTO present("secret_mage_autoload_name",this_player())

/* inherits */
#define ROOM "/players/wocket/std/tvroom.c"
#define PAGE "/players/wocket/mages/obj/page.c"
#define TEACHER "/players/wocket/mages/npc/teacher.c"
