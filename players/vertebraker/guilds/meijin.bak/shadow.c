#include "/players/pavlik/guild/colors.h"

object player;

start_shadow(obj) {
  shadow(obj, 1);
  return 1;
}

stop_shadow() {
  shadow(player, 0);
  return 1;
}

/********************************************************/
/* add_exp: this function is shadowed so that everytime */
/* the player earns experience, a percentage is auto-   */
/* matically converted to guild_experience.  The amount */
/* converted depends on the players "tithe" setting.    */
/********************************************************/
add_exp(amt) {
  int tithe, guild_xp;

  if(!player) {
	stop_shadow();
	return 1;
  }
  if(!present("pavlik_guild_obj", player)) {
	player->add_exp(amt);
	return amt;
  }
  tithe = present("pavlik_guild_obj", player)->query_tithe();
  guild_xp = (amt * tithe) / 100;
  player->add_guild_exp(guild_xp);
  player->add_exp(amt - guild_xp);
  return amt;
}

/******************************************************/
/* move_player: this function is shadowed so that the */
/* the player will lose experience points for leaving */
/* a fight in progress.                               */
/******************************************************/
move_player(str) {
  int loss, op_level, pl_level;
  object attack;

  if(!player) {
	stop_shadow();
	return 1;
  }
  if(!(attack = player->query_attack())) {
	player->move_player(str);
	return 1;
  }
  if(!present(attack, environment(player))) {
	player->move_player(str);
	return 1;
  }

  op_level = attack->query_level();

  /**** extra_levels are considered .5 levels ****/
  pl_level = player->query_level() + (player->query_extra_level() / 2);

  /**** no loss if the opponent is more than 2 levels higher than the player ****/
  if(op_level > pl_level + 2) {
	player->move_player(str);
	return 1;
  }

  loss = ((pl_level+2) - op_level) * (pl_level * 10);
  player->add_guild_exp(-loss);

  tell_object(player, HIB+">> "+NORM+"You run from the fight like a "+HIY+"coward"+NORM+".\n");
  player->move_player(str);

  write_file("/players/pavlik/guild/log/COWARDS",
	capitalize(player->query_real_name())+" ["+player->query_level()+"+"+
	player->query_extra_level()+"] broke combat with "+capitalize(attack->query_name())+
	" ["+attack->query_level()+"].  Experience loss is: "+loss+"\n");

  return 1;
}

