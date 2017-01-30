teleport(str) {
   object env;
 string where; 
   env = environment(TP);
   if(str && TP->query_level() > 20) return 0;
   if(env->realm()=="NT") {
      write("You cannot teleport from this location...\n");
      return 1;
   }
if(this_player()->query_guild_rank() < 3){ write("You can't use ability yet.\n"); return 1; }
    if(USER->query_sp() < 90){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }

     if(where = call_other("obj/base_tele","teleport")) {
               TP->move_player("with an astonished look#"+where);
        write("Something goes wrong.....\n");
        return 1;
      }
   write("You travel through the realm of darkness, ending up in the guild hall.\n");
   this_player()->move_player("into the realm of Darkness#/players/pestilence/closed/dark/room/hall.c");
   this_player()->add_spell_point(-80);
   return 1;
}
