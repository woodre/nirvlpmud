/*Hogath Defs
Started bah
Finished Prolly never */


#define tph tp->query_hp()
#define tp  this_player()
#define tpn tp->query_name()
#define to  this_object()
#define ton to->query_name()
#define top to->query_possessive()
#define at  tp->query_attack()
#define atn at->query_name()
#define alta alt_attacker_ob()
#define hp  to->query_hp
#define mo(x) move_object(x)
#define co(x) clone_object(x)
#define moco(x) move_object(clone_object(x))
#define tps tp->query_msp
#define tpmh tp->query_mhp
#define tpms tp->query_msp
#define poss tp->query_possessive()
#define tpst tp->query_attrib("str")
#define tpp tp->query_attrib("pie")
