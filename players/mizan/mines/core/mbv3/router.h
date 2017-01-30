/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

/* router.h
 *
 * the purpose of this file is to map commonly used functions to their
 * proper daemon counter parts. This also serves as a header file of sorts
 * so i can track where everything is going to be used in the development 
 * process.
 *
 * Each daemon has its own special focus.
 */

/*
 * Tactical is the ringleader of the bunch in a way. It's responsibility is
 * to maintain inventory and provide an interface for effectively sending instructions
 * around to the monsters.
 *
 */

#ifndef IS_TACTICAL_DM

#define TACTICAL_DM "/players/mizan/mbv2/tacticalDM.c"

count_active_monsters() { return TACTICAL_DM->count_active_monsters(); }
dispatch_defensive() { return TACTICAL_DM->dispatch_defensive(); }
dispatch_offensive() { return TACTICAL_DM->dispatch_offensive(); }
on_attrib_monster(arg) { return TACTICAL_DM->on_attrib_monster(arg); }
on_orderall(arg) { return TACTICAL_DM->on_orderall(arg); }
on_ordercabal(arg) { return TACTICAL_DM->on_ordercabal(arg); }
on_orderteam(arg) { return TACTICAL_DM->on_orderteam(arg); }
on_ordertype(arg) { return TACTICAL_DM->on_ordertype(arg); }
on_statall(arg) { return TACTICAL_DM->on_statall(arg); }
register_combat_contact() { return TACTICAL_DM->register_combat_contact(); }
request_backup_for(arg) { return TACTICAL_DM->request_backup_for(arg); }
report_event(code, data) { return TACTICAL_DM->report_event(code, data); }
roster_add(arg) { return TACTICAL_DM->roster_add(arg); }
roster_remove(arg) { return TACTICAL_DM->roster_remove(arg); }
query_roster() { return TACTICAL_DM->query_roster(); }
query_roster_member(arg) { return TACTICAL_DM->query_roster_member(arg); } 
validate_cmdcode(arg) { return TACTICAL_DM->validate_cmdcode(arg); }

#endif


/*
 * Waypoint's job is to provide directional information to a monster when needed.
 * Right now all it can provide are simple waypoints for a monster to start pillaging
 * a castle with.
 *
 */

#ifndef IS_WAYPOINT_DM

#define WAYPOINT_DM "/players/mizan/mbv2/waypointDM.c"

get_castle_waypoint(arg) { return WAYPOINT_DM->get_castle_waypoint(arg); }
get_random_castle() { return WAYPOINT_DM->get_random_castle(); }
match_castle(arg) { return WAYPOINT_DM->match_castle(arg); }

#endif


/*
 * Popman's job is to keep the ranks filled.
 * Right now it is very primitive, but expanding its role.
 *
 */

#ifndef IS_POPMAN_DM

#define POPMAN_DM "/players/mizan/mbv2/popmanDM.c"


#endif

/*
 * MonsterDM provides the backbone of functionality for individual monsters.
 * The idea is to turn the monsters themselves into variable bags, and let monsterDM
 * do all the dirty work, client/server style.
 *
 */

#ifndef IS_MONSTER_DM

#define MONSTER_DM "/players/mizan/mbv2/monsterDM.c"

count_attackers(arg) { return MONSTER_DM->count_attackers(arg); }
check_allies_presently_fighting(arg) { return MONSTER_DM->check_allies_presently_fighting(arg); }
check_trapped_inside_object(arg) { return MONSTER_DM->check_trapped_inside_object(arg); }
check_player_stealing_kill(arg) { return MONSTER_DM->check_player_stealing_kill(arg); }
describe_room(arg) { return MONSTER_DM->describe_room(arg); }

destruct_inventory(arg) { return MONSTER_DM->destruct_inventory(arg); }
do_arrive_noisily(arg) { MONSTER_DM->do_arrive_noisily(arg); }
do_attack_mudkid(arg) { return MONSTER_DM->do_attack_mudkid(arg); }
do_attack_pet(arg) { return MONSTER_DM->do_attack_pet(arg); }
do_attack_player_killer(arg) { return MONSTER_DM->do_attack_player_killer(arg); }

do_attack_routines(arg) { return MONSTER_DM->do_attack_routines(arg); }
do_corpse_management_routines(arg) { return MONSTER_DM->do_corpse_management_routines(arg); }
do_emote_attacked(arg) { return MONSTER_DM->do_emote_attacked(arg); }
do_emote_panicked(arg) { return MONSTER_DM->do_emote_panicked(arg); }
do_emote_taunting(arg) { return MONSTER_DM->do_emote_taunting(arg); }
do_emote_hit_hard(arg) { return MONSTER_DM->do_emote_hit_hard(arg); }
do_emote_death(arg) { return MONSTER_DM->do_emote_death(arg); }
do_emote_triumph(arg) { return MONSTER_DM->do_emote_triumph(arg); }
do_emote_shit_throw(arg) { return MONSTER_DM->do_emote_shit_throw(arg); }
do_emote_casual(arg) { return MONSTER_DM->do_emote_casual(arg); }
do_emote_balloon_throw(arg) { return MONSTER_DM->do_emote_balloon_throw(arg); }
do_emote_arrival(arg) { return MONSTER_DM->do_emote_arrival(arg); }
do_emote_scared(arg) { return MONSTER_DM->do_emote_scared(arg); }

do_get_everything(arg) { return MONSTER_DM->do_get_everything(arg); }
do_healing_routines(arg) { return MONSTER_DM->do_healing_routines(arg); }
do_help_newbies(arg) { return MONSTER_DM->do_help_newbies(arg); }
do_look(arg) { return MONSTER_DM->do_look(arg); }

do_orders_cover_object(arg) { return MONSTER_DM->do_orders_cover_object(arg); }
do_orders_defend_spot(arg) { return MONSTER_DM->do_orders_defend_spot(arg); }
do_orders_dismiss(arg) { return MONSTER_DM->do_orders_dismiss(arg); }
do_orders_explode_object(arg) { return MONSTER_DM->do_orders_explode_object(arg); }
do_orders_explode_spot(arg) { return MONSTER_DM->do_orders_explode_spot(arg); }
do_orders_kill_object(arg) { return MONSTER_DM->do_orders_kill_object(arg); }
do_orders_harrass_by_ip(arg) { return MONSTER_DM->do_orders_harrass_by_ip(arg); }
do_orders_harrass_by_name(arg) { return MONSTER_DM->do_orders_harrass_by_name(arg); }
do_orders_harrass_object(arg) { return MONSTER_DM->do_orders_harrass_object(arg); }
do_orders_heal_object(arg) { return MONSTER_DM->do_orders_heal_object(arg); }
do_orders_hitfade_name(arg) { return MONSTER_DM->do_orders_hitfade_name(arg); }
do_orders_hitfade_object(arg) { return MONSTER_DM->do_orders_hitfade_object(arg); }
do_orders_hold_position(arg) { return MONSTER_DM->do_orders_hold_position(arg); }
do_orders_hound_object(arg) { return MONSTER_DM->do_orders_hound_object(arg); }
do_orders_hunt_object(arg) { return MONSTER_DM->do_orders_hunt_object(arg); }
do_orders_kill_by_guildname(arg) { return MONSTER_DM->do_orders_kill_by_guildname(arg); }
do_orders_kill_by_ipaddr(arg) { return MONSTER_DM->do_orders_kill_by_ipaddr(arg); }
do_orders_kill_by_name(arg) { return MONSTER_DM->do_orders_kill_by_name(arg); }
do_orders_loiter(arg) { return MONSTER_DM->do_orders_loiter(arg); }
do_orders_pester(arg) { return MONSTER_DM->do_orders_pester(arg); }
do_orders_pester_name(arg) { return MONSTER_DM->do_orders_pester_name(arg); }
do_orders_pillagecastle(arg) { return MONSTER_DM->do_orders_pillagecastle(arg); }
do_orders_pillageloiter(arg) { return MONSTER_DM->do_orders_pillageloiter(arg); }
do_orders_protect_object(arg) { return MONSTER_DM->do_orders_protect_object(arg); }
do_orders_stealkills_name(arg) { return MONSTER_DM->do_orders_stealkills_name(arg); }
do_orders_stealkills_object(arg) { return MONSTER_DM->do_orders_stealkills_object(arg); }

do_pelt_routines(arg) { return MONSTER_DM->do_pelt_routines(arg); }
do_show_combat_monitor(arg) { return MONSTER_DM->do_show_combat_monitor(arg); }
do_teleport_waypoint(arg) { return MONSTER_DM->do_teleport_waypoint(arg); }
do_walk(arg) { return MONSTER_DM->do_walk(arg); }

follow_orders(arg, orders) { return MONSTER_DM->follow_orders(arg, orders); }

get_object_matching_guildname(name, room) { return MONSTER_DM->get_object_matching_guildname(name, room); }
get_object_matching_ipaddress(ipaddr, room) { return MONSTER_DM->get_object_matching_ipaddress(ipaddr, room); }
get_heaviest_player_present(arg) { return MONSTER_DM->get_heaviest_player_present(arg); }
get_strongest_player_present(arg) { return MONSTER_DM->get_strongest_player_present(arg); }
get_weakest_player_present(arg) { return MONSTER_DM->get_weakest_player_present(arg); }
get_wealthiest_player_present(arg) { return MONSTER_DM->get_wealthiest_player_present(arg); }


pow(arg) { return MONSTER_DM->pow(arg); }

quantify_attribute(arg) { return MONSTER_DM->quantify_attribute(arg); }

receive_orders(arg, code, data, duration) { return MONSTER_DM->receive_orders(arg, code, data, duration); }
receive_task(arg, code, data) { return MONSTER_DM->receive_task(arg, code, data); }
report_status(arg) { return MONSTER_DM->report_status(arg); }
teleport_me(arg, dest) { return MONSTER_DM->teleport_me(arg, dest); }

#endif

/*
 * Nexus is our coin bank. 
 *
 */

#ifndef IS_NEXUS_DM

#define NEXUS_DM "/players/mizan/mbv2/nexusDM.c"

add_nexus_coins(arg) { return NEXUS_DM->add_nexus_coins(arg); }
process_inventory(arg, arg2) { return NEXUS_DM->process_inventory(arg, arg2); }
query_balance() { return NEXUS_DM->query_balance(); }
request_healing(arg, arg2) { return NEXUS_DM->request_healing(arg, arg2); }
report_balance() { return NEXUS_DM->report_balance(); }

#endif

/*
 * Frilly at first, but will show its value later, Soul provides emotes and similar
 * specific functionality to the monsters.
 *
 *
 */

#ifndef IS_SOUL_DM

#define SOUL_DM "/players/mizan/mbv2/soulDM.c"

do_general_emote_buh(arg, arg2) { return SOUL_DM->do_general_emote_buh(arg, arg2); }

#endif


/*
 * I won't even explain what this one does yet :)
 *
 */

#ifndef IS_SADISTIC_DM

#define SADISTIC_DM "/players/mizan/mbv2/sadisticDM.c"

#endif
