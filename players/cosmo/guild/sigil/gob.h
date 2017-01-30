#include "/players/cosmo/closed/ansi.h"
#include "sigildefs/fire.h"
#include "sigildefs/ice.h"
#include "sigildefs/electricity.h"

#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define TPGR TP->query_guild_rank()
#define USER environment(this_object())
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()

#define GNAME "sigilist"
#define AUTOLOAD GDIR+"gob:"
#define GDIR "/players/cosmo/guild/sigil/"
#define GSAVE "players/cosmo/guild/sigil/save/"
#define DAEMON "/players/cosmo/guild/sigil/daemon.c"
