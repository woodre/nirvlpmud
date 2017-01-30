/*  My file of crap...  */
#include <ansi.h>

#ifndef TP
#define TP this_player()
#endif
#ifndef ENV
#define ENV environment(this_object())
#endif
#ifndef MP
#define MP move_player
#endif
#ifndef MO
#define MO move_object
#endif
#ifndef CO
#define CO clone_object
#endif
#ifndef QN
#define QN query_name()
#endif
#ifndef TO
#define TO this_object()
#endif
#ifndef POS
#define POS query_possessive()   /*  his her  */
#endif
#ifndef PRO
#define PRO query_pronoun()    /*  he she  */
#endif
#ifndef OBJ
#define OBJ query_objective()    /*  him her  */
#endif
#ifndef TR
#define TR tell_room
#endif
#ifndef QRN
#define QRN query_real_name()
#endif
#ifndef AO
#define AO attacker_ob
#endif
#ifndef AAO
#define AAO alt_attacker_ob
#endif

#ifndef TFL_TLP
#define TFL_TLP 2
#endif
#ifndef DD
#define DD "/players/zeus/realm/OBJ/demon_daemon"
#endif
