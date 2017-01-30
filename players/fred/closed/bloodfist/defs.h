#ifndef __LDMUD__
#include "/players/zeus/closed/ansi.h"
#else
#include "/sys/ansi.h"
#endif

#define GUILDNAME "bloodfist"
#define DIR "/players/fred/closed/bloodfist/"
#define CMDDIR DIR+"power/"
#define SAVE_PATH "players/fred/closed/bloodfist/member/"
#define SAVE_PATH2 SAVE_PATH+"bak/"
#define GUILD_FILE "players/fred/closed/bloodfist/gob"
#define MASTER "players/fred/closed/bloodfist/obj/master"
#define ROOM "players/fred/closed/bloodfist/r/private/"
#define CHAN_DAEMON "/players/fred/closed/bloodfist/daemon/channel"
#define ARENA_DAEMON "/players/fred/closed/bloodfist/daemon/arena_daemon"
#define HONOR_DAEMON "/players/fred/closed/bloodfist/daemon/honor_daemon"
#define TITLE_DAEMON "/players/fred/closed/bloodfist/daemon/title_daemon"
#define WEP_DAEMON "/players/fred/closed/bloodfist/daemon/wep_daemon"
#define GUARD_DAEMON "/players/fred/closed/bloodfist/daemon/guard_daemon"
#define HONOR_RATE 300 /* Rate at which honor is gained, higher = less */
#define MAX_GEMS 25
#define GEM_REWARDS ({ 0,2,2,3,4,5,6,7,8 });
#define MAX_STUDY 15       /* max NPCs any player can have studied aat  */
#define USER environment(this_object())
#define NAME USER->query_real_name()
#define Name capitalize((string)User->query_real_name())
#define POS query_possessive()    /*  his her  */
#define PRO query_pronoun()       /*  he she  */
#define OBJ query_objective()     /*  him her  */
#define TOU tell_object(User,
#define TRU tell_room(environment(User),
#define MAX 25              /* Used in chan history */
#define GOD 0                     /* dmg modifier */

#define AGL ((int)PO->query_attrib(0) + (int)PO->query_attribb(0))
#define MIT ((int)PO->query_attrib(1) + (int)PO->query_attribb(1))
#define ACC ((int)PO->query_attrib(2) + (int)PO->query_attribb(2))
#define VIG ((int)PO->query_attrib(3) + (int)PO->query_attribb(3))
#define WIS ((int)PO->query_attrib(4) + (int)PO->query_attribb(4))
#define FAI ((int)PO->query_attrib(5) + (int)PO->query_attribb(5))

#define LAGL (attribs[0] + attribsb[0])
#define LMIT (attribs[1] + attribsb[1])
#define LACC (attribs[2] + attribsb[2])
#define LVIG (attribs[3] + attribsb[3])
#define LWIS (attribs[4] + attribsb[4])
#define LFAI (attribs[5] + attribsb[5])

#define WAGL (query_attrib(0) + query_attribb(0))
#define WMIT (query_attrib(1) + query_attribb(1))
#define WACC (query_attrib(2) + query_attribb(2))
#define WVIG (query_attrib(3) + query_attribb(3))
#define WWIS (query_attrib(4) + query_attribb(4))
#define WFAI (query_attrib(5) + query_attribb(5))

#define FAITH ((int)this_object()->query_attrib(5) + (int)this_object()->query_attribb(5))

