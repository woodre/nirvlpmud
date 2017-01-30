/*
 ~ A header file for the Sigil guild daemon.
 */

#include "/players/cosmo/closed/ansi.h"

#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define TPGR TP->query_guild_rank()
#define USER environment(previous_object())
#define level USER->query_level()
#define extralevel USER->query_extra_level()
#define AT USER->query_attack()
#define AAT USER->query_alt_attack()

#define GDIR "/players/cosmo/guild/sigil/"
#define TPGO present("SIGIL_OB", this_player())
#define QMI TPGO->query_major_info
