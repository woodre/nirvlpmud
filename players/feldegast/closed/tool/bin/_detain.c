do_cmd(str) {
  object player;
  notify_fail("Usage: detain <player>\n");
  if(!str) return 0;
  player=find_player(str);
  if(!player) return 0;
  tell_room(environment(player),"A pair of guards arrive and take "+player->query_name()+" away in shackles.\n",({ player }));
  tell_object(player,"A pair of guards arrive and take you to the Crystal Tower where you\nare swiftly tossed into the dungeon.\n");
  move_object(player,"/players/feldegast/closed/tower/dungeon");
  write("You send a pair of guards to detain "+player->query_name()+".\n");
  return 1;
}
