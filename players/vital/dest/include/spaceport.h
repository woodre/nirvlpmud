/*==============================================================*/
/*
/*   Spaceport global include/define file.
/*   to be included in every Spaceport file.
/*   Copyright vital@nirvana
/*
/*==============================================================*/

/*
 .pragma combine_strings   Nirvana doesn't seem to support this
*/
#pragma combine_strings

/*==============================================================*/
/*  General include files.                                      */

#include <ansi.h>

/*==============================================================*/
/*  General efun/lfun defines                                   */


/*==============================================================*/
/*      Spaceport Object defines                                */
  

#undef  SPROOM
#undef  SPNPC
#undef  SPWEAP
#undef  SPARMOR
#undef  SPSAVE
#undef  SPOBJ
#undef  SPT
#undef  STD
#define STD "/players/vital/std"
#define SPT "/players/vital/dest/spaceport/"
#define SPROOM 		SPT+"rooms/"
#define SPNPC 		SPT+"npc/"
#define SPSAVE      SPT+"save/"
#define SPOBJ       SPT+"obj/"
#define SPWEAPON	SPOBJ+"weapon/"
#define SPARMOR  	SPOBJ+"armor/"
