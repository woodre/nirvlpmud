
/*
 * MASTER SPARRING OBJECT (2/6/94)
 * Starts and removes sparring shadow
 */

place_sparring_shadow(player) {
   object shadow;
   if(player->query_sparring_shadow())
     return 1;
   shadow = clone_object("players/molasar/sparring/shadow");
   shadow->start_sparring_shadow(player);
   tell_object(player, "You are now ready to begin sparring.\n");
   return 1;
}

remove_sparring_shadow(player) {
   if(!player->query_sparring_shadow())
     return 1;
   player->stop_sparring_shadow();
   tell_object(player, "You are no longer protected for sparring.\n");
   return 1;
}

