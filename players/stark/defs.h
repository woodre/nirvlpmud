#include <ansi.h>
#define TP this_player()
#define TPN TP->query_name()
#define TPL TP->query_level()
#define TPRN TP->query_real_name()
#define TO this_object()
#define PO previous_object()
#define TO this_object()
#define ETO environment(this_object())
#define ETP environment(this_player())
#define FAIL(x) { notify_fail(x); return 0; }
#define MOCO move_object(clone_object
#define add_sp add_spell_point
#define add_hp add_hit_point
#define ENV environment
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPADDSP this_player()->add_spell_points
#define TPADDHP this_player()->add_hit_points
