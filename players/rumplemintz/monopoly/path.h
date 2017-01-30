/* path.h
 */
#include "config.h"

/* You need to change these: */
#define PATH    "/players/rumplemintz/monopoly/"
#define RULES   "/open/rumplemintz/mhelp.txt"
#define MHELP   "/open/rumplemintz/mhelp.txt"
#define ENTER_FROM "/players/rumplemintz/workroom"
#define EXIT_DIR   "workroom"

/* Uncomment this define if you are using the 3.1.2-DR driver */
#define DRIVER_HAS_PAD

/* pick one of these: */
#define WRITE(x) return write(x), 1    /* for amylaar */
/* #define WRITE(x) return write(x)  /* for other driver :) */

/*******************************************/
/* You probably don't need to change these */
/*******************************************/
#define MAIN    "/players/rumplemintz/monopoly/main"
#define MOBJ    "/players/rumplemintz/monopoly/mobj"
#define MBIN    "/players/rumplemintz/monopoly/mbin"
#define SQUARE  "/players/rumplemintz/monopoly/square"
#define CARDS   "/players/rumplemintz/monopoly/cards"
#define DOCS    "/players/rumplemintz/monopoly/docs"
#define LOGFILE "monopoly"

/* IF YOU GET TOO DEEP RECURSION ERRORS:
 * max number of bounces..  either make this smaller (around 12) or
 * change the driver so it can handle deeper recursion
 * this is checked in square.c which assume the only important bounce is "go"
 * 11 means only card advances will be affected (you can only roll 12 :)
 * This should work with most drivers, if you get errors, lower it
 */
#define BOUNCE_MAX 12 

/* You really shouldn't change anything below here! */
/* You really shouldn't change anything below here! */
/* You really shouldn't change anything below here! */

/* useful macros */
#define TP this_player()
#define TPMOBJ present("__mobj",this_player())
#define NAME TPMOBJ->query_cname()
#define FAIL return !notify_fail
#ifdef DRIVER_HAS_PAD
#define PAD pad
#endif
#ifndef DRIVER_HAS_PAD  /* many drivers also don't have #elif ;) */
#define PAD MAIN->_pad
#endif
#define MS MONEYSIGN
#define SHOUT(str) MAIN->gameshout(str,TPMOBJ->query_gamename())

#define UNOWNED -3
#define MORTGAGED -2
#define OWNED -1
#define MONOPOLY 0

/* square array..  we need to keep an array of the filenames of the squares */
#define BLOCK1 "go","mediterranean","chest1","baltic","income","reading",\
  "oriental","chance1","vermont","connecticut"
#define BLOCK2 "jail","charles","electric","states","virginia","pennrr"\
 ,"james","chest2","tennessee","new"
#define BLOCK3 "free","kentucky","chance3","indiana","illinois","b&o",\
  "atlantic","ventnor","water","marvin"
#define BLOCK4 "goto","pacific","carolina","chest4","pennave",\
  "short","chance4","park","luxury","boardwalk"
#define SQUARES ({ BLOCK1, BLOCK2, BLOCK3, BLOCK4 })
#define SQSZ 40

/* monopoly number..  100 are railroads and 200 are utilities */
#define MONOPOLIES ({ 0,1,0,1,0,100,2,0,2,2, \
                      0,3,200,3,3,100,4,0,4,4, \
                      0,5,0,5,5,100,6,6,200,6, \
                      0,7,7,0,7,100,0,8,0,8 })

