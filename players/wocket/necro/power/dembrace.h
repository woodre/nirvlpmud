dembrace() {
object ob;
if(tp->query_sp() < 25) { write("You do not have enough spell points for this.\n"); return 1; }
ob = present("necro_ob",this_player());
write("A wall of despair assails your senses.\n"+
      "You think to yourself...\n\n"+
      "Its for the good of the magic...\n\n"+
      "     Its for the good of the magic...\n\n"+
      "          Its for the good of the magic...\n\n"+
      "Its something you must do...\n\n"+
      "You embrace death...\n\n");
write_file(LOG+"/DEMBRACE",ctime(time())+" "+tprn+" level:"+
     (tp->query_level()+tp->query_extra_level())+"  guildlevel:"+tp->query_guild_rank()+"\n");
ob->add_blood(10);
ob->add_skin(5);
ob->add_eye(2);
ob->add_spine(1);
ob->add_val(3);
ob->save_me();
tp->raise_stamina(-1);
tp->add_spell_points(-25);
tp->hit_player(1000000);
return 1;
}
