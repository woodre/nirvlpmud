#ifndef coldwindfile
#define tp         this_player()
#include "/players/coldwind/ansi.h"
#define tpn        tp->query_name()
#define tprn       tp->query_real_name()
#define tpl        tp->query_level()
#define tpxl       tp->query_extra_level()
#define tpp        tp->query_possessive()
#define ep         environment(this_object())
#define epn        ep->query_real_name()
#define MV         call_other(this_player(),"move_player" 
#define tl         tp->query_level()
#define tx         tp->query_extra_level()
#define epl        ep->query_level()
#define epx        ep->query_extra_level()
#define egl        ep->query_guild_rank()
#define tgl        tp->query_guild_rank()
#define to         this_object()
#define MO move_object
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define MOCO move_object(clone_object
#define TPL this_player()->query_level()
#define TO this_object()
# define percentofhp attacker->query_hp()*100/attacker->query_mhp()
#define USER player
#define GOB gob
#define USERN USER->query_name()
#define USERRN USER->query_real_name()
#define POW main(str, TO, USER)
#define POS query_possessive()   /*  his her  */
#define PRO query_pronoun()    /*  he she  */
#define OBJ query_objective()    /*  him her  */
#define UPOS USER->POS
#define UPRO USER->PRO
#define UOBJ USER->OBJ
#define STR USER->query_attrib("str")
#define UP USER->POS
#define UPR USER->PRO
#define UO USER->OBJ
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define GLVL GOB->query_glvl()
#define DELAY GOB->query_spell_delay()
#define WEP USER->query_weapon()
#define WEPN WEP->query_name()
#define WEPSH WEP->short()
#define coldwindfile BLAH
#endif
