void
heart_beat()
{
    casting = 0; /* clear casting */

    if(!User)
    {
      set_heart_beat(0);
      return;
    }
    if((int)User->query_level() < 19)
    {
      object ob;

      if(sac_pts > 0) sac_pts --;
      if(!random(1000) && sac_type && (sac_pts <= 0))
      {
        string cmd_to_swipe;

        string *ks;  ks = keys(cmds);
        cmd_to_swipe = (ks[random(sizeof(ks))]);

        if(member_array(cmd_to_swipe, (string *)ACTIOND->query_base()) == -1)
        {
          tell_object(User, "\
Shardak frowns upon you from afar.\n");
          User->hit_player(66 + random(33), "other|evil");
          if(!swiped_powers)
            swiped_powers = ({ });
          swiped_powers += ({ cmd_to_swipe });
          tell_object(User, "\
You have lost the ability to " + BOLD +
                  cmd_to_swipe + NORM + ".\n");
          this_object()->save_me();
        }

      }
      if((ob = present("crusader shield", User)) ||
         (ob = present("crucifix", User)) ||
         (ob = present("cross", User)) || 
         (ob = present("holy symbol", User)))
      {
        string sh, nm;

        if((sh = (string)ob->short()) && (int)ob->query_value()
           && (int)ob->query_weight() && !ob->query_auto_load()
           && (nm = (string)ob->query_name()))
        {
          object e;
          if(e = environment(User))
            if(!transfer(ob, e)) /* success ! */
              tell_object(User, "Something is very wrong...\n");
        }         
      }     
    }
}
