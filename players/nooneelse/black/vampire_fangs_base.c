/*  VAMPIRE_FANGS_BASE.C  */

#define VERSION "666.0.0"
query_version() { return VERSION; }

#define UPDATE "09/01/94"
query_update() { return UPDATE; }

#include "lib/defs.h"

/* Commands included from /players/nooneense/black/lib */
#include "lib/bat_alarm.h"
#include "lib/assess.h"
#include "lib/awaken.h"
#include "lib/backhand_enemy.h"
#include "lib/bite_player.h"
#include "lib/bury_hole.h"
#include "lib/call_wolf.h"
#include "lib/calm_fighters.h"
#include "lib/cancel_summons.h"
#include "lib/cause_fear.h"
#include "lib/charity_item.h"
#include "lib/create_form.h"
#include "lib/cure_diseases.h"
#include "lib/damn.h"
#include "lib/defend_me.h"
#include "lib/defile_object.h"
#include "lib/dig_hole.h"
#include "lib/disguise_self.h"
#include "lib/dismiss_bat.h"
#include "lib/drain_corpse.h"
#include "lib/emit_mist.h"
#include "lib/emote.h"
#include "lib/emotions.h"
#include "lib/emotions2.h"
#include "lib/eyes_light.h"
#include "lib/fix_title.h"
#include "lib/forbid_entry.h"
#include "lib/glance.h"
#include "lib/go_home.h"
#include "lib/grasp_enemy_new.h"
#include "lib/guild_news.h"
#include "lib/hell_fire.h"
#include "lib/guild_help.h"
#include "lib/illusion.h"
#include "lib/infuse.h"
#include "lib/leave_guild.h"
#include "lib/list_guild_tasks.h"
#include "lib/list_vampires.h"
#include "lib/make_servant.h"
#include "lib/bat_message.h"
#include "lib/obit_list.h"
#include "lib/paralyze.h"
#include "lib/process_skins.h"
#include "lib/quit.h"
#include "lib/regenerate.h"
#include "lib/remember_rooms.h"
#include "lib/sanctuary.h"
#include "lib/rip_throat.h"
#include "lib/scan_monster.h"
#include "lib/scratch_enemy_new.h"
#include "lib/sew_skins.h"
#include "lib/sharpen_fangs.h"
#include "lib/shift_hp.h"
#include "lib/show_inven.h"
#include "lib/show_player.h"
#include "lib/show_score.h"
#include "lib/show_whov.h"
#include "lib/skin_corpse.h"
#include "lib/solve_guild_tasks.h"
#include "lib/spell_fire_ball.h"
#include "lib/spell_missile.h"
#include "lib/spell_shock.h"
#include "lib/start_up.h"
#include "lib/summon.h"
#include "lib/telekenetics.h"
#include "lib/telepathy.h"
#include "lib/telepathyfeel.h"
#include "lib/transfer_item.h"
#include "lib/translate_item.h"
#include "lib/wraith_form.h"

/*---------------------------------------------------*/
/* Guild Lieutenants Commands (in vampire_fangs_base)*/
/*---------------------------------------------------*/
#include "lib/repair_exp.h"
#include "lib/replace_fangs.h"
#include "lib/hop_to_office.h"
#include "lib/return_from_office.h"
#include "lib/check_player.h"
#include "lib/punish_vampire.h"
#include "lib/remove_fangs.h"

/*---------------------------------------------------*/
/*  Guild Assistant Commands (in vampire_fangs_base) */
/*---------------------------------------------------*/
#include "lib/expell_traitor.h"

/*---------------------------------------------------*/
/*  Guild Master Commands (in vampire_fangs_base)    */
/*---------------------------------------------------*/
#include "lib/release_member.h"
#include "lib/goto_guild.h"
#include "lib/goto_office_board.h"
#include "lib/shelf_check.h"


/*---------------------------------------------------*/
/* Local Commands                                    */
/*---------------------------------------------------*/

/* Adjust a field to display n characters for formatted displays */
LADJUST(str, n) { return extract(str+"                   ",0,n-1); }
