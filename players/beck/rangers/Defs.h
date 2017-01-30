/*  Power Ranger Definitions            */

#define GUILDNAME "rangers"
#define AUTOLOAD "/players/beck/rangers/RangerCommunicator:"

/* Guild Objects */
#define GUILDOBJ "/players/beck/rangers/RangerCommunicator"
#define MASTER "/players/beck/rangers/RangerMaster"
#define GLOBE "/players/beck/rangers/ViewingGlobe"

/* Guild Directories */
#define RANGERDIR "players/beck/save/rangers/"

/* Guild Commanders */
#define LEADERS ({ "roland","vital","tick","skan", })

/* Banished Members */
#define BANISHED ({ "yorick","kazer", })

/* Useful Shortcuts */
#define TP this_player()
#define TO this_object()
#define NAME this_player()->query_real_name()
#define CAPREALNAME capitalize(this_player()->query_real_name())
#define CAPNAME this_player()->query_name()
#define ENVTP environment(this_player())
#define ENVOB environment(this_object())
#define COMM present("RangerCommunicator", this_player())
#define COMME present("RangerCommunicator", environment(this_object()))
#define COMMR present("ranger_object",rangers[i])
#define COLOR QRangerColor()
#define DINO QRangerDino()
#define ANIMAL QRangerAnimal()
#define WEAPON QRangerWeapon()
#define NUMBER QRangerNumber()
#define KARATE QKarateLevel()
#define SKILL QSkillExp()
#define MARTIAL QMartialExp()
#define COMBAT QCombatExp()
#define SP query_sp()
#define HP query_hp()
#define EXP query_exp()
#define GEXP query_guild_exp()
#define LEVEL query_level()
#define GLEVEL query_guild_rank()
justify(str, len) { return extract(str+"                     ",0,len-1);}
#include "/players/beck/esc.h"
