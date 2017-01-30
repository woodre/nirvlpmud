/*
 * Ascension, by Dune and Snow
 * General include file
 */
#ifndef  _DEF_H_
#define  _DEF_H_
#include "color.h"
#include "util.h"

/* directories */
#define PATH       "/players/dune/closed/deva/"
#define FILEPATH   "players/dune/closed/deva/"
#define CMDDIR     (PATH+"cmds/")
#define LOGDIR     (PATH+"logs/")
#define HELPDIR    (PATH+"docs/")
#define ROOMDIR    (PATH+"rooms/")
#define SAVEDIR    (FILEPATH+"spirits/")
#define ALTSAVEDIR (PATH+"spirits/")
#define DAEMDIR    (PATH+"daemons/")
#define SUMMONDIR  (PATH+"helpers/")

/* daemons */
#define SHADOW   (PATH+"deva_shadow")
#define SUMMONC  (SUMMONDIR+"summon.c")
#define ACTIOND  (DAEMDIR+"actions.c")
#define LEVELD   (DAEMDIR+"levels.c")
#define MORED    (DAEMDIR+"_more.c")
#define CHANNELD (DAEMDIR+"channel.c")
#define BEATD    (DAEMDIR+"fake_beat.c")
#define COMBATD  (DAEMDIR+"combat.c")

/* objects */
#define GUILDOBJ (PATH+"spirit")
#define AUTOLOAD (PATH+"spirit:0")

/* guild news */
#define NEWS     (PATH+"news")

/* numbers */
#define MIN_LEV   18  /* minimum level to join guild */

/* names */
#define OWNER1    "Dune"
#define OWNER2    "Snow"
#define GUILDNAME 0
#define GUILDID   "ascension_spirit"

/* special rooms */
#define LOGIN (ROOMDIR+"heavens")

/* macros */
#define PRE  previous_object()
#define TP   this_player()
#define IPTP present(GUILDID, TP)
#define IPOB present(GUILDID, ob)
#define CAP  capitalize
#define TPN  CAP((string)TP->query_name())
#define OPN  CAP((string)ob->query_name())
#define TRN  CAP((string)TP->query_real_name())
#define ORN  CAP((string)ob->query_real_name())
#define ME   environment(this_object())
#define GEN  (string)TP->query_possessive()
#define TO   this_object()
#define TR   tell_room

#endif
