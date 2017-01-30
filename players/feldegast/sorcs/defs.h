#include "/players/feldegast/closed/ansi.h"
#define ROOT "/players/feldegast/sorcs/"

#define ROOMDIR "/players/feldegast/sorcs/rooms/"
#define NPCDIR "/players/feldegast/sorcs/npc/"
#define SPELLDIR "/players/feldegast/sorcs/spells/"
#define SAVEDIR "players/feldegast/sorcs/members/"
#define MEMBERDIR "/players/feldegast/sorcs/members/"
#define OBJDIR "/players/feldegast/sorcs/obj/"
#define DOCDIR ROOT+"docs/"
#define CMDDIR ROOT+"cmds/"
#define LOGDIR "/players/feldegast/sorcs/logs/"

#define CHANNELD "/players/feldegast/sorcs/daemons/channelD.c"

#define GUILD_ID "secret_mage_guild_ob_name"

#define BOOK present(GUILD_ID,this_player())

/* inherits */
#define ROOM "/players/feldegast/std/room.c"
#define PAGE "/players/feldegast/sorcs/obj/page.c"
#define TEACHER "/players/feldegast/sorcs/npc/teacher.c"

/* Shortcuts */
#define TP this_player()
#define TPN (string)this_player()->query_name()
