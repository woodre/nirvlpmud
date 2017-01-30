guild_quit() {
      tp->set_guild_name(0);
      tp->add_exp(tp->query_guild_exp());
      tp->set_home("room/church");
      tp->add_guild_exp(-tp->query_guild_exp());
      tp->add_guild_rank(-tp->query_guild_rank());
      tp->set_home("/room/church");
/*
      tp->add_exp(-(tp->query_exp()/2));
      tp->set_attrib("sta",1);
      tp->set_attrib("str",1);
*/
          tp->reset(1);
          command("save",tp);
          write("Hope to see you again soon!\n");
          destruct(this_object());
return 1; } 
