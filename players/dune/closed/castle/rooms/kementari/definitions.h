#define MAIN              "players/dune/closed/castle/rooms"
#define CASTLEROOM        "players/dune/closed/castle/rooms/kementari"
#define HIKEHIKAYOROOM    "players/dune/closed/castle/rooms/hikehikayo"
#define JAO_TINUKAIIROOM  "players/dune/closed/castle/rooms/jao_tinukaii"
#define KEMENTARIROOM     "players/dune/closed/castle/rooms/kementari"
#define TUMETAIROOM       "players/dune/closed/castle/rooms/tumetai"
#define MEZUTUAROOM       "players/dune/closed/castle/rooms/mezutua"
#define DAAICHIKIZAROOM   "players/dune/closed/castle/rooms/daai_chikiza"
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

realm() { return "NT"; }
