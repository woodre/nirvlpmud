#ifndef  _DEF_H_
#define  _DEF_H_

/* hotel definitions */
#define HOTELNAME         "Bed and Breakfast"
#define HOTELEXIT         "/players/eurale/workroom.c"
#define RATE              1000           /* cost per day of stay */
#define REFUNDPERCENT     30             /* % refund on early checkout */
#define MAXSAVE           4              /* max saveable items */
#define ROOMS             12              /* # rooms in hotel */
#define ROOMSPERFLOOR     4              /* must divide ROOMS evenly */
#define MANAGER           "eurale"         /* current hotel wiz overseer */
#define NPCID             "hotel_clerk"  /* npc desk receptionist */

/* file directories */
#define SAVEPATH     "players/eurale/BED/save/"  /* save file dirs */
#define FULLSAVEPATH "/players/eurale/BED/save/" /* same dirs */
#define PATH         "/players/eurale/BED/"      /* main path */
#define ROOMPATH     PATH+"roomfiles/"           /* self-build room dir */

/* macros */
#define TP this_player()
#define TO this_object()
#define TPRN this_player()->query_real_name()

/* quick functions (commonly used funcs) */
#define check_npc(); \
if(!present(NPCID)) { \
  write("There is no one here to serve you.\n"); \
  return 1; } 

#endif
