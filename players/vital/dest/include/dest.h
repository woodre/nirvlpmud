/*==============================================================*/
/*
/*   Shuttle Destination global include/define file.
/*   to be included in every destination file.
/*   Copyright vital@nirvana
/*   Friday, June 11, 2004 2:13:37 AM
/*==============================================================*/


/*==============================================================*/
/*  General include files.                                      */

#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

/*==============================================================*/
/*  General efun/lfun defines                                   */

/*#pragma combine_strings   Nirvana doesn't seem to support this*/


/*==============================================================*/
/*      Destination Object defines                              */
  

#undef  ACADIE
#undef  AQUITAINE
#undef  ASGARD
#undef  ASSAWOMPSET
#undef  ASTRAKHAN
#undef  BAFUT
#undef  BLOIS
#undef  BREVON
#undef  CALEDONIA
#undef  CUMBERLAND
#undef  DALRIADA
#undef  DENALI
#undef  DUAT
#undef  EARTH
#undef  ENGONG
#undef  EXILE
#undef  FINNMARK
#undef  FOIX
#undef  FRANONIA
#undef  HIBERNIA
#undef  LENE
#undef  LONDINIUM
#undef  LUSATIA
#undef  MANAPOURI
#undef  MULTNOMAH
#undef  NEUSTRIA
#undef  NOVOJAN
#undef  NPC
#undef  OKANAGON
#undef  ORCADIA
#undef  ORISSA
#undef  RIVIERA
#undef  SHQIPNI
#undef  TALLAHAT
#undef  TAUMOTU
#undef  TRONDELAG
#undef  VULHYNIA
#undef  SPT
#undef  DEST
#define DEST            "/players/vital/dest/"
#define SPT             "/players/vital/dest/spaceport/"
#define ACADIE          "/players/vital/dest/acadie/"
#define AQUITAINE       "/players/vital/dest/aquitaine/"
#define ASGARD          "/players/vital/dest/asgard/"
#define ASSAWOMPSET     "/players/vital/dest/assawompset/"
#define ASTRAKHAN       "/players/vital/dest/astrakhan/"
#define BAFUT           "/players/vital/dest/bafut/"
#define BLOIS           "/players/vital/dest/blois/"
#define BREVON          "/players/vital/dest/brevon/"
#define CALEDONIA       "/players/vital/dest/caledonia/"
#define CUMBERLAND      "/players/vital/dest/cumberland/"
#define DALRIADA        "/players/vital/dest/dalriada/"
#define DENALI          "/players/vital/dest/denali/"
#define DUAT            "/players/vital/dest/duat/"
#define EARTH           "/players/vital/dest/earth/"
#define ENGONG          "/players/vital/dest/engong/"
#define EXILE           "/players/vital/dest/exile/"
#define FINNMARK        "/players/vital/dest/finnmark/"
#define FOIX            "/players/vital/dest/foix/"
#define FRANCONIA       "/players/vital/dest/franconia/"
#define HIBERNIA        "/players/vital/dest/hibernia/"
#define LENE            "/players/vital/dest/lene/"
#define LONDINIUM       "/players/vital/dest/londinium/"
#define LUSATIA         "/players/vital/dest/lusatia/"
#define MANAPOURI       "/players/vital/dest/manapouri/"
#define MULTNOMAH       "/players/vital/dest/multnomah/"
#define NEUSTRIA        "/players/vital/dest/neustria/"
#define NOVOJAN         "/players/vital/dest/novojaneiro/"
#define NPC             "/players/vital/dest/npc/"
#define OKANAGON        "/players/vital/dest/okanagon/"
#define ORCADIA         "/players/vital/dest/orcadia/"
#define ORISSA          "/players/vital/dest/orissa/"
#define RIVIERA         "/players/vital/dest/riviera/"
#define SHQIPNI         "/players/vital/dest/shqipni/"
#define TALLAHAT        "/players/vital/dest/tallahat/"
#define TAUMOTU         "/players/vital/dest/taumotu/"
#define TRONDELAG       "/players/vital/dest/trondelag/"
#define VULHYNIA        "/players/vital/dest/vulhynia/"


/*==============================================================*/
/*  General System-Directory defines. [out for now, 12/16/00]   */

/*#define SYS   */         
/*#define LIB   */        
#undef  STD
#define STD     "/players/vital/closed/std/"



/*==============================================================*/
/* Later General Room-Directory defines. [out for now, 12/16/00]*/


/*==============================================================*/
/*   General Chat Reaction defines.  [out for now, 12/16/00]    */

#define SAY_ASK_WHISPER ({ "say", "ask", "whisper" })

#define C_HELLO ({ "hi", "hiho", "hey", "greetings", "hiya", "hello" })

#define C_BYE ({"l8r","later","bubye","bye","byebye","good-bye","see you","cu","bye-bye", "goodbye", "cya"  })


#define F_ABUSE ({"kick","spit","knee","punch","squeeze","pat","grope" })

#define F_LOVE ({ "hug","kiss","french","love","admire" })

#define F_FRIENDLY ({ "smile","wink","tease","giggle","grin" })


object armor, ring, helmet, misc, amulet, boots, shield;
object coins;
object human;
string str;
int x, y, z;
