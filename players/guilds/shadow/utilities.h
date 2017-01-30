query_possesive() {
   if(TP->query_gender()=="male") return "his";
     else if(TP->query_gender()=="female") return "her";
   return "its";
}

query_max_shp() {
   max_shp = (shlevel *7);
   return max_shp;
}

query_shlevel() {
   return shlevel;
}

query_shadow_xp() {
   return shxp;
}

query_muffled() {
   return muffled;
}


level_check(level) {
   if(level > shlevel) {
      return 0;
   }
   return 1;
}

query_carry() {
   int strength;
   strength = TP->query_attribute("str");
   if(this_player()->query_level()==1) 
      return (this_player()->query_level() + 6 + strength/2);
  else return (this_player()->query_level()+6+strength/5);
}

query_summon() {
   return summon;
}

promote_me(num) {
*/
   if(CN == "Blue") {
/*
if(CN == "Gemini") {
      shlevel += num;
      return 1;
   }
   if(shlevel + num > 12) return 0;
   shlevel += num;
   shpoints = query_max_shp();
   ENVTO->set_guild_rank(shlevel);
   ENVTO->set_guild_exp(shxp);
   return 1;
}

add_shxp_me(num) {
   shxp += num;
   return 1;
}

end() {
   destruct(TO);
   return 1;
}

time_check() {
   if(shlevel > 11) return 1;
   if(time() - spell_time < 3) {
      write("It is too soon since your last attack.\n");
      return 0;
   }
   return 1;
}

drain_damage(str) {
   int num;
   if(sscanf(str, "%d", num) !=1) return;
   if(5*shlevel < num) {
      write("You may set your drain damage at up to five times you shadow\n"+
            "level.\n");
      return 1;
   }
   drain_damage = num;
   write("Drain damage now set at "+num+".\n");
   return 1;
}

end_game() {
   if(servant&&has_servant) {
      write("Dismissing servant...\n");
      command("dismiss servant",TP);
   }
}

lost_mark() {
   int tmp;
   string cn;
   cn = CAP(ENVTO->query_real_name());
   if(ENVTO->query_guild_name()=="shadow") {
      TEOWN("Restoring shadow mark...\n");
      shxp = ENVTO->query_guild_exp();
      shlevel = ENVTO->query_guild_rank();
   } else {
      write_file("/players/guilds/shadow/logs/NEW", cn+" joined the "+
       "shadows at "+ctime(time())+"\n\n");
      shlevel = 1;
      tmp = ENVTO->query_guild_rank();
      shxp = 1;
      ENVTO->add_guild_rank(1 - tmp);
   }
   TEOWN("Done.\n");
   return 1;
}

query_shpoints() {
   return shpoints;
}
