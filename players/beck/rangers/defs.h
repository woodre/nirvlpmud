/*  Power Ranger Definitions            */

#define GUILDNAME "rangers"
#define AUTOLOAD "/players/beck/rangers/ranger_communicator:"

/* Guild Objects */
#define GUILDOBJ "/players/beck/rangers/ranger_communicator"
#define MASTER "/players/beck/rangers/ranger_master"
#define GLOBE "/players/beck/rangers/viewing_globe"

/* Guild Directories */
#define RANGERDIR "players/beck/save/rangers/"

/* Guild Commanders */
#define LEADERS ({ "tick","jazz","frankie", })

/* Useful Shortcuts */
#define NAME this_player()->query_real_name()
#define CAPNAME capitalize(this_player()->query_real_name())
#define ENV environment(this_object())
#define COMM present("ranger_communicator", this_player())
#define COMME present("ranger_communicator", environment(this_object()))
#define COLOR query_ranger_color()
#define ANSI query_ranger_ansi()
#define ANIMAL query_ranger_animal()
#define THUNDER query_ranger_thunderzord()
#define WEAPON query_ranger_weapon()
#define KARATE query_karate_level()
#define QUERCOLOR present("ranger_communicator", environment(this_object()))->query_ranger_color()
#define QUERWEAPON present("ranger_communicator", environment(this_object()))->query_ranger_weapon()
justify(str, len) { return extract(str+"                     ",0,len-1);}
#include "/players/beck/esc.h"
