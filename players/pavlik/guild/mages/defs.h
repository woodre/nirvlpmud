#include "/players/pavlik/closed/colors.h"

/* guild object version (INTEGERS ONLY!) */
#ifndef GOB_VERSION
#define GOB_VERSION			3
#define GOBID				"mageobj"

/*
 * TODO: add a changelog here!
 */

#define MAXGUILDRANK			71
#define MAXSPELLLEVEL			7
#define WIZLEVEL			20
#define MIN_SP				-30
#define STAT_MAX			120
#define MAX_ALTERATION_NUM		4
#define AUTOSAVE_INTERVAL		200	/* heart_beats between autosaves */
#define GENERAL_WEAPON_PENALTY		2	/* general deduction to all weapon attacks */
#define NONMAGE_WEAPON_PENALTY		3	/* additional deduction for using non-mage weapon types */
#define ARMOR_PHYSICAL_PENALTY		-10	/* extra physical damage */
#define CHAN_NAME "mage"

#define LEVEL_HP_PENALTY		3
#define EXTRALEVEL_HP_PENALTY		1
#define LEVEL_SP_BONUS			4
#define EXTRALEVEL_SP_BONUS		2
#define SP_REGEN_INTERVAL		3	/* how many heart_beats between regen bonus */
#define SP_REGEN_BONUS			query_total_guild_stat("power")/25

#define MAGEWEPS ({"staff","wand","rod","dagger","knife","exotic",})
#define SCHOOLS	({"conjuration","enchantment","evocation","illusion","necromancy"})
#define STATS	({"intelligence","power","wisdom","will power"})

#define DTYPES ({ ({ "magical", "Magic", NORM }) \
                 ,({ "other|fire", "Fire", HIR }) \
                 ,({ "other|ice", "Ice" , HIB }) \
                 ,({ "other|evil", "Evil" , RED }) \
                 ,({ "other|good", "Good" , HIW }) \
                 ,({ "other|light", "Light" , HIY }) \
                 ,({ "other|dark", "Dark" , HIK }) \
                 ,({ "other|poison", "Poison" , HIG }) \
                 ,({ "other|electric", "Electric" , YEL }) \
                 ,({ "physical", "Physical" , NORM }) \
                 ,({ "other|sonic", "Sonic" , HIM }) })

#define LOG_DIR		"/players/pavlik/guild/mages/log/"
#define CMD_DIR		"/players/pavlik/guild/mages/commands/"
#define SPELL_DIR	"/players/pavlik/guild/mages/spells/"
#define SAVE_DIR	"players/pavlik/guild/mages/players/"
#define INHERIT_DIR	"/players/pavlik/guild/mages/inherit/"
#define OBJ_DIR		"/players/pavlik/guild/mages/objects/"
#define HELP_DIR	"/players/pavlik/guild/mages/help/"
#define ROOM_DIR	"/players/pavlik/guild/mages/room/"
#define NPC_DIR		"/players/pavlik/guild/mages/npc/"

#define OUTSIDE_ROOMS ({ "church", "green", "hotel", "daycare", "casino", "post", \
                         "portal", "lockers", "sun", "pass", "bank", "hut", })
#define OUTSIDE_DEST ({ "/room/church", "/room/vill_green", "/players/boltar/hotel/hotel", \
                        "players/boltar/sprooms/daycare", "/players/boltar/casino/front_desk",\
                        "/room/post", "players/saber/ryllian/portal",\
                        "/players/catwoman/tl", "/room/sunalley2", "players/mythos/entrance",\
                        "/players/earwax/bank/bank","/room/vill_shore", })

/* rooms */
#define GUILD_HOME	"/players/pavlik/guild/mages/room/guild_room5"

/* logs */
#define COMMENTLOG	"/players/pavlik/guild/mages/log/COMMENT"
#define BUGLOG		"/players/pavlik/guild/mages/log/BUG"
#define TRAINLOG	"/players/pavlik/guild/mages/log/TRAINING"

/* guild object filenames */
#define GOB_FILENAME	"/players/pavlik/guild/mages/gob"
#define BELT_FILENAME	"/players/pavlik/guild/mages/mage_belt"

/* guild daemon objects */
#define DAEMON		"/players/pavlik/guild/mages/guild-daemon.c"
#define DONATOR		"/players/pavlik/guild/mages/donation-master.c"
#define ADVANCE		"/players/pavlik/guild/mages/room/advance_room.c"
#define GUILD_TELL	"/players/pavlik/guild/mages/commands/gt.c"
#define COLOR_PARSER	"/obj/user/color_parser.c"
#define CHAND           "/bin/channel_daemon.c"

/* aliases */
#define rlname this_player()->query_real_name()
#define rname environment(this_object())->query_real_name()
#define ME capitalize(this_player()->query_real_name())
#define PO this_player()->query_possessive()
#define PN this_player()->query_pronoun()
#define en environment(this_object())
#define tp this_player()
#define env environment(this_player())
#define attk this_player()->query_attack()
#define IT capitalize(obj->query_name())
#define Me capitalize(environment(this_object())->query_real_name())
#define It capitalize(OBJ->query_name())
#define guild present("mageobj", this_player())
#define mage this_object()
#define OWN capitalize(owner->query_name())

#define SPELL_PROMPT HIR+"*"+NORM+HIC+">>>"+NORM
#define MPROMPT HIR+"*"+NORM+HIC+">>"+NORM+" "

#endif
