#include "/players/chip/ansi.h"
#define USER player
#define GOB gob
#define CON GOB->query_control()
#define COM GOB->query_combat()
#define CRE GOB->query_creation()
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
#define UP USER->POS
#define UPR USER->PRO
#define UO USER->OBJ
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define GLVL GOB->query_glvl()
#define COLOR GOB->query_color()
#define DELAY GOB->query_spell_delay()
#define VNAME GOB->query_venom_name()