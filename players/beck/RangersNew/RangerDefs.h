/*  Power Ranger Definitions            */

#define GUILDNAME "rangers"
#define AUTOLOAD "/players/beck/Rangers/RangerCommunicator:"

/* Guild Objects */
#define GUILDOBJ "/players/beck/Rangers/RangerCommunicator"
#define MASTER "/players/beck/closed/Master"
#define GLOBE "/players/beck/Rangers/ViewingGlobe"

/* Guild Directories */
#define RANGERDIR "players/beck/Rangers/Save/"
#define LOGDIR "/players/beck/Rangers/Log"

/* Guild Commanders */
#define LEADERS ({ "roland","vital","tick","skan", })

/* Banished Members */
#define BANISHED ({ "yorick","guest","soundgarden","rundar","lebonan","usagi","dirk","outrage", })

/* Skills that everyone has */
#define SKILLS ({"rsc","ri","rt","rte","rwho","encourage","ranger","skills","ansi","generate"})

#define COLOR QRangerColor()
#define DINO QRangerDino()
#define ANIMAL QRangerAnimal()
#define WEAPON QRangerWeapon()
#define NUMBER QRangerNumber()
#define KARATE QKarateLevel()
#define SKILL QSkillExp()
#define MARTIAL QMartialExp()
#define COMBAT QCombatExp()
#define COMM present("RangerCommunicator", this_player())
#define COMME present("RangerCommunicator", environment(this_object()))
#define COMMR present("ranger_object",rangers[i])

