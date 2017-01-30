
xmove(str) {
  if(!present("pavlik_guild_obj", this_player())) return 0;
  if(this_player()->query_guild_rank() < 10) return 0;
  if(!str) return 0;
  switch (str) {
    case "kentetsu" : this_player()->move_player("in a hurry#players/pavlik/guild/room/advance"); break;
    case "kitaeru"  : this_player()->move_player("in a hurry#players/pavlik/guild/room/roof"); break;
    case "mosakou"  : this_player()->move_player("in a hurry#players/pavlik/guild/room/train_skills"); break;
    case "reidai"   : this_player()->move_player("in a hurry#players/pavlik/guild/room/train_stats"); break;
    case "tainin"   : this_player()->move_player("in a hurry#players/pavlik/guild/room/exchange"); break;
    case "tsukeru"  : this_player()->move_player("in a hurry#players/pavlik/guild/room/join"); break;
    case "uchidasu" : this_player()->move_player("in a hurry#players/pavlik/guild/room/armory"); break;
    default         : return 0;
  }
  return 1;
}

