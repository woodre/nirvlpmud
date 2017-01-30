/*  Power Ranger Definitions            */

#define GUILDNAME "dark rangers"
#define AUTOLOAD "/players/beck/Rangers/RangerCommunicator:"

/* Guild Objects */
#define GUILDOBJ "/players/beck/DarkRangers/RangerCommunicator"
#define MASTER "/players/beck/DarkRangers/RangerMaster"
#define GLOBE "/players/beck/DarkRangers/ViewingWindow"

/* Guild Directories */
#define RANGERDIR "players/beck/DarkRangers/Save/"
#define LOGDIR "/players/beck/DarkRangers/Log"

/* Guild Commanders */
#define LEADERS ({ "roland","vital","tick","skan", })

/* Banished Members */
#define BANISHED ({ "yorick","minus", })

#define SKILLS ({ "ri","rsc","skills","ranger", })
#define COLOR QRangerColor()
#define DINO QRangerDino()
#define ANIMAL QRangerAnimal()
#define WEAPON QRangerWeapon()
#define NUMBER QRangerNumber()
#define KARATE QKarateLevel()
#define SKILL QSkillExp()
#define MARTIAL QMartialExp()
#define COMBAT QCombatExp()
#define COMM present("DarkRangerCommunicator", this_player())
#define COMME present("DarkRangerCommunicator", environment(this_object()))
#define COMMR present("dark_ranger_object",rangers[i])

