/*
  alchemist_pouch_base.c - the membership object of Nooneelse's Alchemist Guild
                           contains all 'universal' alchemist functions
*/

#define VERSION "1.0.0"
query_version() { return VERSION; }

#define UPDATE "12/31/00"
query_update() { return UPDATE; }

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* Commands included from /players/nooneense/Alchemist/lib */

/* Level 5-7	10	"WHITE"		"STUDENT" */
#include ALCHEMIST_LIB+"guild_news.h"
#include ALCHEMIST_LIB+"guild_help.h"
#include ALCHEMIST_LIB+"display_guild_levels.h"
#include ALCHEMIST_LIB+"list_guild_tasks.h"
#include ALCHEMIST_LIB+"solve_guild_tasks.h"
#include ALCHEMIST_LIB+"loginmsg.h"
#include ALCHEMIST_LIB+"logoutmsg.h"
#include ALCHEMIST_LIB+"light.h"
#include ALCHEMIST_LIB+"assess.h"
#include ALCHEMIST_LIB+"show_who.h"
#include ALCHEMIST_LIB+"emote.h"
#include ALCHEMIST_LIB+"tell.h"
#include ALCHEMIST_LIB+"think.h"
#include ALCHEMIST_LIB+"fix_heartbeat.h"
#include ALCHEMIST_LIB+"show_alchemists.h"
#include ALCHEMIST_LIB+"fix_guild_object.h"
#include ALCHEMIST_LIB+"refine.h"
#include ALCHEMIST_LIB+"resign_guild.h"
#include ALCHEMIST_LIB+"road_to_guild.h"
#include ALCHEMIST_LIB+"set_login_room.h"
#include ALCHEMIST_LIB+"stone_skin.h"
#include ALCHEMIST_LIB+"skin_corpse.h"
#include ALCHEMIST_LIB+"process_skins.h"
#include ALCHEMIST_LIB+"sew_skins.h"

/* Level 8-11	20	"YELLOW"	"ACOLYTE" */
#include ALCHEMIST_LIB+"dig_hole.h"
#include ALCHEMIST_LIB+"detect_disease.h"
#include ALCHEMIST_LIB+"cure_diseases.h"
#include ALCHEMIST_LIB+"flash.h"
#include ALCHEMIST_LIB+"etheral_door.h"
#include ALCHEMIST_LIB+"ice.h"
#include ALCHEMIST_LIB+"reserve_monster.h"
#include ALCHEMIST_LIB+"sanctuary.h"

/* Level 12-14	40	"BLUE"		"LEARNED" */
#include ALCHEMIST_LIB+"acid.h"
#include ALCHEMIST_LIB+"oil_of_slipperiness.h"
#include ALCHEMIST_LIB+"air_elemental.h"
#include ALCHEMIST_LIB+"earth_elemental.h"
#include ALCHEMIST_LIB+"fire_elemental.h"
#include ALCHEMIST_LIB+"dismiss_elemental.h"
#include ALCHEMIST_LIB+"peace.h"
#include ALCHEMIST_LIB+"transport.h"

/* Level 15-18	60	"RED"		"ADEPT" */
#include ALCHEMIST_LIB+"charity.h"
#include ALCHEMIST_LIB+"fear.h"
#include ALCHEMIST_LIB+"poison.h"
#include ALCHEMIST_LIB+"scan.h"
#include ALCHEMIST_LIB+"create_raven.h"
#include ALCHEMIST_LIB+"aid.h"

/* Level 19+	80	"BLACK"		"MASTER" */
#include ALCHEMIST_LIB+"remote_sell.h"
#include ALCHEMIST_LIB+"hail.h"
#include ALCHEMIST_LIB+"repair.h"
#include ALCHEMIST_LIB+"sharpen.h"
#include ALCHEMIST_LIB+"call_vampire.h"
#include ALCHEMIST_LIB+"increase_speed.h"

/* Special (guildmaster)	"PLATINUM"	"GRANDMASTER" */
#include ALCHEMIST_LIB+"check_member.h"
#include ALCHEMIST_LIB+"replace_pouch.h"
#include ALCHEMIST_LIB+"punish_alchemist.h"
#include ALCHEMIST_LIB+"demote_member.h"
#include ALCHEMIST_LIB+"expell_member.h"
#include ALCHEMIST_LIB+"promote_member.h"
#include ALCHEMIST_LIB+"remove_member.h"

/* special versions of standard commands */
#include ALCHEMIST_LIB+"quit.h"
#include ALCHEMIST_LIB+"show_score.h"
#include ALCHEMIST_LIB+"show_inven.h"
#include ALCHEMIST_LIB+"show_who.h"
#include ALCHEMIST_LIB+"show_whoa.h"

/*---------------------------------------------------*/
/* Local Commands                                    */
/*---------------------------------------------------*/

/* Adjust a field to display n characters for formatted displays */
LADJUST(str, n) { return extract(str+"                   ",0,n-1); }
