#include "/players/feldegast/closed/ansi.h"
#define ROOT "/players/feldegast/guild/"

#define ROOMDIR "/players/feldegast/guild/rooms/"
#define NPCDIR "/players/feldegast/guild/npc/"
#define SPELLDIR "/players/feldegast/guild/spells/"
#define SAVEDIR "players/feldegast/guild/members/"
#define MEMBERDIR "/players/feldegast/guild/members/"
#define OBJDIR "/players/feldegast/guild/obj/"
#define DOCDIR ROOT+"docs/"
#define CMDDIR ROOT+"cmds/"
#define LOGDIR "/players/feldegast/guild/logs/"

#define CHANNELD "/players/feldegast/guild/daemons/channelD.c"

#define GUILD_ID "secret_mage_guild_ob_name"

#define BOOK present(GUILD_ID,this_player())

/* inherits */
#define ROOM "/players/feldegast/std/room.c"
#define PAGE "/players/feldegast/guild/obj/page.c"
#define TEACHER "/players/feldegast/guild/npc/teacher.c"

/* Shortcuts */
#define TP this_player()
#define TPN (string)this_player()->query_name()
