#include "ansi.h"
#define TP          this_player()
#define TPN         capitalize(TP->query_name())
#define MOCO        move_object(clone_object
#define TPRN        TP->query_real_name()
#define MHP         TP->query_max_hp()
#define MSP         TP->query_max_sp()
#define TPSP        TP->query_spell_points()
#define TPHP        TP->query_hit_point()
#define TPRSP       this_player()->add_sp
#define ENV         environment
#define POS         TP->query_possessive()
#define QOB         TP->query_objective()
#define PRO         TP->query_pronoun()
#define CAP         capitalize
#define LOWER       lower_case
#define PROMPT(x)   write(data["prompt"]=x)
#define TO          this_object()
