#define GUILDNAME "Jedi"
#define CMDDIR "/players/dragnar/Jedi/power/"
#define CMDBASE "/players/dragnar/Jedi/lib/command"
#define SAVE_PATH "players/dragnar/Jedi/member/"
#define USER environment(previous_object())
#define meditate present("meditate_object_jedi", environment())
#define hp USER->add_hit_point()
#define SP USER->query_spell_point()
#define attack USER->query_attack()
#define user USER
#define JEDI previous_object()
#define NAME(x) capitalize(x->query_real_name() || "someone")
#define ROOM(x) tell_room(environment(USER), x)
#define SKILL previous_object()->query_skill(skill_type)

#define MAP "players/dragnar/Jedi/daemons/mapping"
#define ACTIONS "players/dragnar/Jedi/daemons/actions"
#define CHAN "players/dragnar/daemons/channel"
#define GUILD_FILE "players/dragnar/Jedi/jedi"
#define cp previous_object()->query_cp()
#define mcp previous_object()->query_mcp()
#define percent_cp cp*100/mcp
#define ATTHP ((attack->query_hp()*10)/(attack->query_mhp()))
#define POS this_player()->query_possessive()
#define Rank this_player()->query_guild_rank()
#define ATTN attack->query_name()
#define PO previous_object()
