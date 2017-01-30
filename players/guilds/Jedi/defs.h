#define GUILDNAME "Jedi"
/** Directories **/
#define CMDDIR "/players/guilds/Jedi/bin/"
#define SPELLDIR "/players/guilds/Jedi/force/"
#define CMDBASE "/players/guilds/Jedi/lib/command"
#define OBJDIR "/players/guilds/Jedi/obj"
#define LIB "/players/guilds/Jedi/lib/"
#define HALL "/players/guilds/Jedi/hall"
#define SAVE_PATH "players/guilds/Jedi/member/"
#define CHAN "/bin/channel_daemon"
#define GUILD_FILE "players/guilds/Jedi/gob"
#define ERROR "/players/guilds/Jedi/logs/ERROR"
#define LOG "/players/guilds/Jedi/logs/"

/** Daemons **/
#define ACTIONS "players/guilds/Jedi/daemons/actions"
#define LEV "/players/guilds/Jedi/daemons/JediLevels.c"
#define DEATH "/players/guilds/Jedi/daemons/JediDeath.c"

/** Skills **/
#define SABER "saber"
#define PHYS  "physical"
#define TELE  "telepathy"
#define KIN   "telekinesis"
#define SKILL_TYPES ({ SABER, PHYS, TELE, KIN })

/** Need to get rid of these **/
#define USER environment(this_object())
#define meditate present("meditate_object_jedi", environment())
#define HP USER->query_hp()
#define attack USER->query_attack()
#define user USER
#define MSP user->query_msp()
#define wielded_saber present("lightsaber", environment(this_object()))->query_wielded()
#define Rank USER->query_guild_rank()
#define GXP USER->query_guild_exp()
#define PO previous_object()

/** Defines **/
#define RDIR (!random(2) ? "left" : "right")
#define MAXCOINS 40000
#define MIN_SP -30
#define CHAN_NAME "jedi"
#define MAX_SABERS 2
#define SABER1 0
#define SABER2 1
#define JEDI_CLAN "jedi"
#define SITH_CLAN "sith"
