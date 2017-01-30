#define TP this_player()
#define TO this_object()
#define ETO ENV(TO)
#define ETP ENV(TP)
#define TPN CAP(TP->query_name())
#define TE tell_object
#define TR tell_room
#define ETON ETO->query_name()
#define GOB present("CyberNinja Implants",TP)
#define GLEV GOB->guild_lev()
#define ARTR GOB->query_art_level()
#define MEAT TP->query_attack()
#define MEATN CAP(MEAT->query_name())
#define GEN TP->query_possessive()
#define RAN random
#define PRE present
#define CAP capitalize
#define TR tell_room
#define ENV environment
#define CO call_other
#define NI RED+"*~*"+OFF
#define OH REV_CYAN+"~##~"+OFF
#define MYWEP TP->query_weapon()
#define TOT MYWEP->query_totaldam()
#define RE return 1
#define KG BOLD+"Kusari Gama"+OFF
#define NO BOLD+"Ninja-To"+OFF
#define NAG BOLD+"Naginata"+OFF
