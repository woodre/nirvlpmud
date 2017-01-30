status
rscore(string str) {
  object ob;
  int guild_rank;

  if (!str)
    ob = this_player();
  else
    ob = find_player(str);
  if (!ob) {
    notify_fail("Rscore: Cannot find object.\n");
    return 0;
  }
  write("   Rscore for "+str+"\n");
  write("\n");
  write(".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.\n");
  write(". "+ob->short()+"\n");
  write(". Level: "+ob->query_level()+" / "+ob->query_extra_level()+"\t\t\t");
  write(". Guild: "+ob->query_guild_name()+" / ");
  if (ob->query_guild_rank())
    guild_rank = (int)ob->query_guild_rank();
  if (present("new_venom_object", ob))
    guild_rank = (int)present("new_venom_object", ob)->query_glvl();
  write(guild_rank+"\n");
  write(". Align: "+ob->query_alignment()+" / "+ob->query_al_title()+"\t\t");
  write(". Coins: "+ob->query_money()+"\n");
  write(".   Exp: "+ob->query_exp()+"\t\t\t");
  write(". AC/WC: "+ob->query_ac()+" / "+ob->query_wc()+"\n");
  write(". HP/SP: "+ob->query_hp()+"/"+ob->query_mhp()+"  /  "+
                    ob->query_sp()+"/"+ob->query_msp()+"\n");
  write(".   Age: ");
  if (ob->query_age() > 0) {
    int i;
    i = (int)ob->query_age();
    if (i/43200) {
      write(i/43200 + " days ");
      i = i - (i/43200)*43200;
    }
    if (i/1800) {
      write(i/1800 + " hours ");
      i = i - (i/1800)*1800;
    }
    if (i/30) {
      write(i/30 + " minutes ");
      i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
  }
  write(".   QPS: "+ob->query_quest_point()+"\n");
  return 1;
}
