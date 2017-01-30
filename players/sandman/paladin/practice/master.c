
/*
 * MASTER PRACTICE OBJECT
 * Practice rooms call this object to carry out functions
 */

get_monster(str) {
   object monster, where;
   int level, number;
   
   if(!str || sscanf(str, "%d %d", level, number) != 2) {
     write("Usage: summon <monster level> <number of monsters>\n");
     return 1;
   }
   if(level > 25) {
     write("Highest level available is 25.\n");
     return 1;
   }
   if(number > 7) {
     write("Largest number of monsters is 7.\n");
     return 1;
   }
   where = environment(this_player());
   while(number) {   
     monster = clone_object("players/sandman/paladin/practice/gmonster");
     monster->set_level(level);
     monster->set_wc(level);
     monster->set_ac(level/3);
     monster->set_ep(0);
     move_object(monster, where);
     number -= 1;
   }
   return 1;
}

place_practice_shadow(player) {
   object shadow;
   if(player->query_practice_shadow())
     return 1;
   shadow = clone_object("players/sandman/paladin/practice/shadow");
   shadow->start_practice_shadow(player);
   tell_object(player, "You are now ready to begin practicing.\n");
   return 1;
}

remove_practice_shadow(player) {
   if(!player->query_practice_shadow())
     return 1;
   player->stop_practice_shadow();
   tell_object(player, "You are no longer protected for practicing.\n");
   return 1;
}

