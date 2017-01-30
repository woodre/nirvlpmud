/* Hotel parameter file, by Dune at Nirvana (6/18/97) */
#ifndef  _DEF_H_
#define  _DEF_H_

/* hotel definitions */
#define HOTELNAME         "Beverly Hills Hotel"
#define HOTELEXIT         "/players/dune/workroom.c"
#define RATE              1000           /* cost per day of stay */
#define REFUNDPERCENT     50             /* % refund on early checkout */
#define MAXSAVE           5              /* max saveable items */
#define ROOMS             3              /* # rooms in hotel */
#define ROOMSPERFLOOR     3              /* must divide ROOMS evenly */
#define MANAGER           "dune"         /* current hotel wiz overseer */
#define NPCID             "hotel_clerk"  /* npc desk receptionist */

/* file directories */
#define SAVEPATH     "players/dune/hotel/save/"  /* save file dirs */
#define FULLSAVEPATH "/players/dune/hotel/save/" /* same dirs */
#define PATH         "/players/dune/hotel/"      /* main path */
#define ROOMPATH     PATH+"roomfiles/"           /* self-build room dir */

/* macros */
#define TPN          capitalize(this_player()->query_name())

/* quick functions (commonly used funcs) */
#define check_npc(); \
if(!present(NPCID)) { \
  write("There is no one here to serve you.\n"); \
  return 1; } 

#endif
