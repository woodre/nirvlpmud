#define GUILDNAME "Jedi"
#define CMDDIR "/players/dragnar/Jedi/power/"
#define CMDBASE "/players/dragnar/Jedi/lib/command"
#define LIB "/players/dragnar/Jedi/lib/"
#define SAVE_PATH "players/dragnar/Jedi/member/"
#define USER environment(this_object())
#define meditate present("meditate_object_jedi", environment())
#define HP USER->query_hp()
#define attack USER->query_attack()
#define user USER
#define SP user->query_spell_point()
#define MSP user->query_msp()
#define wielded_saber present("lightsaber", environment(this_object()))->query_wielded()
#define Rank USER->query_guild_rank()
#define GXP USER->query_guild_exp()
#define MAXCOINS 40000
#define MIN_SP -30
#define CHAN_NAME "jedi"

#define MAP "players/dragnar/daemons/mapping"
#define ACTIONS "players/dragnar/Jedi/daemons/actions"
#define CHAN "/bin/channel_daemon"
#define GUILD_FILE "players/dragnar/Jedi/jedi"
#define ERROR "/players/dragnar/Jedi/ERROR"
#define LOG "/players/dragnar/Jedi/logs/"
#define LEV "/players/dragnar/Jedi/daemons/JediLevels.c"
#define DEATH "/players/dragnar/Jedi/daemons/JediDeath.c"
