#include "COLOR.h"

#define TP  this_player()
#define IPTP present("implants", TP)
#define IPOB present("implants", ob)
#define TN  TP->query_name()
#define RN  TP->query_real_name()
#define ORN ob->query_real_name()
#define CAP capitalize
#define TPN CAP(TN)
#define OPN CAP(ob->query_name())
#define GEN TP->query_possessive()
#define GENOB ob->query_possessive()
#define POSS query_possessive()
#define ATTACK environment(this_object())->query_attack()
#define ENV environment
#define EO  environment(ob)
#define ET  environment(TP)
#define FP  find_player
#define TE  tell_object
#define TR  tell_room
#define AA add_action
#define RE return 1
#define WHO CAP(who)
#define STR CAP(str)
#define PRE present
#define MEAT TP->query_attack()
#define GLEV IP(TP)->guild_lev()
#define OGLEV IP(ob)->guild_lev()
#define log "/players/dune/closed/guild/log/"
#define TOOL "/players/dune/closed/guild/lib/CYBERDAEMON.c"
#define SEQ "/players/snow/closed/cyber/seq_obj.c"
#define WAIT "/players/snow/closed/cyber/WAIT"
#define TO this_object()
#define ETO environment(this_object())
#define SAVE "players/snow/closed/cyber/ninjas/"
#define EMP1 "dune"
#define EMP2 "snow"
#define  FAXPATH    "/players/dune/closed/guild/fax/"
#define  DOCPATH    "/players/dune/closed/guild/docs/"
#define  MOREPATH "/players/dune/closed/guild/_more.c"
