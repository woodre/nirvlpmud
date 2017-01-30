#include "/players/maledicta/ansi.h"
#define R_DIR "/players/maledicta/ares/"
#define OBJS R_DIR+"obj/"
#define MOBS R_DIR+"mobs/"
#define ROOMS R_DIR+"rooms/"
#define ROOM "/players/maledicta/inherit/v_room.c"
#define MO move_object
#define CO clone_object
#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define TPL TP->query_level()
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
