#ifndef  _DEF_H_
#define  _DEF_H_

#include "COLOR.h"


/* Guild Owners */
#define TP     this_player()
#define OWNER1 "Mizan"
#define OWNER2 "Shinshi"


/* Main Path Names */
#define DUNEPATH     "/players/dune/closed/guild"
#define ALTDUNEPATH  "players/dune/closed/guild"
#define SNOWPATH     "/players/dune/closed/guild/snow"
#define ALTSNOWPATH  "players/dune/closed/guild/snow"
/*
#define SNOWPATH     "/players/snow/closed/cyber"
#define ALTSNOWPATH  "players/snow/closed/cyber"
*/


/* Command Libraries */
#define LIB_GENCMDS  DUNEPATH+"/lib_genCmds/"
#define LIB_ADVCMDS  DUNEPATH+"/lib_advCmds/"
#define LIB_ADMCMDS  DUNEPATH+"/lib_admCmds/"
#define LIB_TOOLS    DUNEPATH+"/lib_tools/"
#define LIB_EMOTES   DUNEPATH+"/lib_emotes/"


/* Directories */
#define DAEMDIR        DUNEPATH+"/daemons"
#define DUNELOGDIR     DUNEPATH+"/logs"
#define SNOWLOGDIR     SNOWPATH+"/logs"
#define LOGDIR         DUNELOGDIR    /* default log dir */
#define ROOMDIR        DUNEPATH+"/rooms"
#define FAXDIR         DUNEPATH+"/fax"
#define DOCDIR         DUNEPATH+"/doc"
#define SAVEDIR        ALTDUNEPATH+"/ninjas"
#define NINJADIR       DUNEPATH+"/ninjas"
#define TOURNDIR       DUNEPATH+"/tournaments"
#define OBJDIR         DUNEPATH+"/objects"
#define ARMORDIR       DUNEPATH+"/armor"
#define BOARDDIR       DUNEPATH+"/boards"
#define LOREDIR        DUNEPATH+"/lore"
#define MECHDIR        SNOWPATH+"/mechs"
#define WEAPONDIR      SNOWPATH+"/weapons"
#define VOTEDIR        DUNEPATH+"/votes"
#define SVOTEDIR       DUNEPATH+"/votes_secret"
#define EMOTESAVEDIR   ALTDUNEPATH+"/lib_emotes/emoteData"


/* General Defines */
#define GUILDNAME      "cyberninja"
#define FUNKYNAME      "CyberNinja"
#define NEWS           DOCDIR+"/news.txt"
#define MAX_CREDITS    200000
#define LINE "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
#define MEMBER_STATS   DAEMDIR+"/membershipStats.txt"
#define OFFICER_STATS  DAEMDIR+"/officerStats.txt"
#define ATTACK_MODE2   "stealth"
#define ATTACK_MODE1   "hyper"
#define ATTACK_MODE0   "normal"


/* Daemon Objects */
#define ACTIOND      DAEMDIR+"/actions.c"
#define ALEVELD      DAEMDIR+"/art_levels.c"
#define GLEVELD      DAEMDIR+"/guild_levels.c"
#define HLEVELD      DAEMDIR+"/honor_levels.c"
#define MORED        DAEMDIR+"/_more.c"
#define CHANNELD     DAEMDIR+"/channels.c"
#define BEATD        DAEMDIR+"/fake_beat.c"
#define COMBATD      DAEMDIR+"/combat.c"
#define ENHANCEMENTD DAEMDIR+"/enhancements.c"
#define MECHD        DAEMDIR+"/mechs.c"
#define WEAPOND      DAEMDIR+"/weapons.c"
#define OFFICED      DAEMDIR+"/offices.c"
#define MEMBERD      DAEMDIR+"/membership.c"
#define RECRUITD     DAEMDIR+"/recruit_d.c"
#define VOTED        DAEMDIR+"/vote.c"
#define POOLD        DAEMDIR+"/pool.c"


/* Special Rooms */
#define LOGIN        ROOMDIR+"/guildhall.c"
#define ALTLOGIN     ROOMDIR+"/phase_hall.c"
#define GUILDEXIT    "/players/snow/gate.c"
#define GUILDENTR    "/players/snow/gate.c"
#define GUILDLEAD    ROOMDIR+"/council.c"

/* Objects */
#define GUILDOBJ     DUNEPATH+"/implants.c"
#define RECRUITOBJ   OBJDIR+"/recruitob.c"
#define CHIPOBJ      OBJDIR+"/die_set.c"
#define BALLOTS      DUNEPATH+"/ballots.txt"
#define EMOTES       DUNEPATH+"/emotes.txt"


/* Object Identification */
#define GUILD_ID     "guild_implants"
#define WEAPON_ID    "guild_weapon"
#define WEAPON_HANDS "unarmed"
#define TRANSFER_ID  "guild_transferobj"
#define LEGS_ID      "guild_legs"
#define MECH_ID      "guild_mech"
#define MICROCHIP_ID "guild_microchip"


/* Player Identification */
#define AFFILIATE    "guild_affiliate"
#define RECRUIT      "guild_recruit"


/* Npc's */
#define DOCTOR_NPC   "guild_doctor"
#define MERCHANT_NPC "guild_merchant"
#define MECH_NPC     "guild_mechsmith"
#define WEAPON_NPC   "guild_weaponmaster"
#define ARMOR_NPC    "guild_armorsmith"
#define FAB_NPC      "guild_technician"


/* Macros */
#define IPTP   present(GUILD_ID, TP)
#define IPOB   present(GUILD_ID, ob)
#define ETO    environment(this_object())
#define ETN    capitalize((string)ETO->query_name())
#define TPN    capitalize((string)TP->query_name())
#define OPN    capitalize((string)ob->query_name())
#define TRN    capitalize((string)TP->query_real_name())
#define ORN    capitalize((string)ob->query_real_name())
#define POS    query_possessive()
#define MEAT   (TP->query_attack())
#define MEAN   capitalize((string)(MEAT->query_name()))


/* Code & Contributions From Other Wizards */
#define ANSHAR_ROOMS   "/players/anshar/closed/cninja/b_room.c"
#define ULATH_WEPS     "/players/ulath/closed/ninjaweps"
#define VERTE_COLOR    DAEMDIR+"/vertecolor.c"

/* Definition Files */
#define DEFS_ENHANCEMENTS   "/players/dune/closed/guild/includes/enhancements.h"
#define DEFS_GLEVELS       "/players/dune/closed/guild/includes/glevels.h"
#define DEFS_ALEVELS       "/players/dune/closed/guild/includes/alevels.h"
#define DEFS_HLEVELS       "/players/dune/closed/guild/includes/hlevels.h"
#define DEFS_OFFICES       "/players/dune/closed/guild/includes/offices.h"
#define DEFS_WEAPONS       "/players/dune/closed/guild/includes/weapons.h"
#define DEFS_MECHS         "/players/dune/closed/guild/includes/mechs.h"
#define DEFS_VOTE          "/players/dune/closed/guild/includes/vote.h"
#define DEFS_COLORPAD      "/players/dune/closed/guild/includes/color_pad.h"


/* Utility Functions (Keep short and few) */
status gotrank(object ob, int level)
{
  if ((int)IPOB->guild_lev() < level) return 0;
  return 1;
}
status gotsp(object ob, int cost)
{
  if ((int)ob->query_spell_point() < cost)
  {
    tell_object(ob, "You are too low on power\n");
    return 0;
  }
  return 1;
}


#endif
