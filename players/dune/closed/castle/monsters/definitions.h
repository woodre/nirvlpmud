#define CASTLEROOM        "players/dune/closed/castle/rooms"
#define CASTLEMONSTER     "players/dune/closed/castle/monsters"
#define CASTLEOBJECT      "players/dune/closed/castle/objects"

#define target  this_player()
#define TP      this_player()
#define TO      this_object()
#define QG      query_gender();
#define HP      query_hp();
#define SP      query_sp();
#define MHP     query_mhp()
#define MSP     query_msp()

#define CAP             capitalize
#define LEVEL           query_level()
#define QL              query_level()
#define ENV             environment
#define TE              tell_object
#define TR              tell_room

#define QN              query_name()
#define TPN             CAP(TP->QN)
#define OPN             CAP(ob->QN)
#define WHO             CAP(who)
#define STR             CAP(str)
#define RN              TP->query_real_name()
