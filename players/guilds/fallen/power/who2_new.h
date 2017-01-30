
who2_new(str)
{
  int x, y, z, sz, swap;
  object *a, atemp;
  swap = 1;
  a = users();
  sz = sizeof(a);
  TOU"\n");
  TOU BOLD+BLK+"\tThe Denizens of Nirvana");
  if(str == "s" || str == "sort" || str == "sorted" || str == "p" || str == "pk")
    TOU HIR+" ["+str+"]\n");
  else TOU "\n");
  TOU NORM+RED+"\t-------- -------- ------ ----- --- --- -\n"+NORM);
  TOU 
    pad("", 6)+
    pad("Name", 14)+
    pad("Level", 8)+
    pad("PK", 4)+
    pad("Idle", 6)+
    pad("Guild", 21));
  if(str == "p" || str == "pk")
    TOU "Location");
  TOU "\n\n");

  if(str == "p" || str == "pk") /* pk who sort */
  {
    for(x = 0; x < sz; x++)  /* count through a [users] */
    {
      if(a[x]->query_level() < 20) /* if not a wizard */
      {
        if(a[x]->environment() && a[x]->check_fight_area()
	      || a[x]->query_pl_k())  /* if pk or in pk area*/
        { 
	        if(a[x]->query_ghost()) /* if ghost */
          {
		        if(y < 10){
		          TOU "  "+y+":  "+HIW);
		          TOU pad(capitalize((string)a[x]->query_real_name()), 14));
            }
		        else {
		          TOU "  "+y+": "+HIW);
		          TOU pad(capitalize((string)a[x]->query_real_name()), 15));
            }
		        TOU NORM);
          }
	        else if(y < 10)
		        TOU pad("  "+y+":  "+a[x]->query_name(), 20));
	        else
		        TOU pad("  "+y+": "+a[x]->query_name(), 20));
	        if(a[x]->query_extra_level())
		        TOU pad(a[x]->query_level()+"+"+a[x]->query_extra_level(), 8));
	        else
		        TOU pad(a[x]->query_level(), 8));
	        if(a[x]->environment() && a[x]->check_fight_area())
	        {
		        TOU RED);
		        TOU pad("PK", 5));
		        TOU NORM);
	        }
	        else if(a[x]->query_pl_k())
		        TOU pad("PK", 5));
	        else
		        TOU pad("", 5));
	        if(query_idle(a[x]) > 960)
		        TOU pad("16+", 5));
	        else if(query_idle(a[x]) > 720)
		        TOU pad("12+", 5));
	        else if(query_idle(a[x]) > 480)
		        TOU pad("8+", 5));
	        else if(query_idle(a[x]) > 240)
		        TOU pad("4+", 5));
	        else
		        TOU pad("", 5));
	        if(a[x]->query_guild_name())
		        TOU pad(capitalize((string)a[x]->query_guild_name()), 21));
	        else
		        TOU pad("None", 16));
          if(!a[x]->query_invis() || ((a[x]->query_level()
            < User->query_level()) && a[x]->query_level() < 19))
	          TOU environment(a[x])->short());
          else
            TOU "-----");
	        y++;
	        TOU"\n");
        } /* end pk */
      } /* end if not a wiz */
    } /* end for loop */
    TOU"\n");
    return 1;
  } /* end if str is p */
  if(str == "s" || str == "sort" || str == "sorted")
  {
    y = 1; z = 1;
    while(swap)
    {
      swap = 0;
      for(x = 0; x < sz; x++)  /* count through a [users] */
      {
        if(a[x]->query_level() < 20)  /* if not a wizard */
        {
          if((x + 1) < sz) /* if there is one more element in a */
          {
            if(a[x]->query_exp() < a[x+1]->query_exp())  /* 2 has more xp */
            {
              atemp = a[x+1];  /* swap the two */
              a[x+1] = a[x];
              a[x] = atemp;
              swap = 1;
            }
          }
        }
        else /* if it is a wizard */ 
        {
          swap = 1;
          if((x + 1) < sz) /* if there is one more element in a */
          {
            for(z = x; z < sz; z++)
            {
              if((z + 1) < sz) /* if there is one more element in a */
                a[z] = a[z+1];
              else
                sz--;  /* make it think array is 1 less */
            }
          }
          else /* no more elements in the a array */
            sz--;  /* make it think array is 1 less */
        }
      }
    }
    for(x = 0; x < sz; x++)
    {
      if((x + 1) < sz) /* if there is one more element in a */
      {
        if(a[x]->query_exp() < a[x+1]->query_exp())  /* 2 has more xp */
        {
          atemp = a[x+1];  /* swap the two */
          a[x+1] = a[x];
          a[x] = atemp;
        }
      }
    }
  }
  else
    y = 1;
  for(x=0; x<sz; x++)
  {
    if(a[x]->query_level() < 21)
    {
      if(a[x]->query_ghost())
      {
        if(y < 10){
          TOU "  "+y+":  "+HIW);
          TOU pad(capitalize((string)a[x]->query_real_name()), 14));
        }
        else {
          TOU "  "+y+": "+HIW);
          TOU pad(capitalize((string)a[x]->query_real_name()), 15));
        }
        TOU NORM);
      }
      else if(y < 10)
        TOU pad("  "+y+":  "+a[x]->query_name(), 20));
      else
        TOU pad("  "+y+": "+a[x]->query_name(), 20));
      if(a[x]->query_extra_level())
        TOU pad(a[x]->query_level()+"+"+a[x]->query_extra_level(), 8));
      else
        TOU pad(a[x]->query_level(), 8));
      if(a[x]->environment() && a[x]->check_fight_area())
      {
        TOU RED);
        TOU pad("PK", 5));
        TOU NORM);
      }
      else if(a[x]->query_pl_k())
        TOU pad("PK", 5));
      else
        TOU pad("", 5));
      if(query_idle(a[x]) > 960)
        TOU pad("16+", 5));
      else if(query_idle(a[x]) > 720)
        TOU pad("12+", 5));
      else if(query_idle(a[x]) > 480)
        TOU pad("8+", 5));
      else if(query_idle(a[x]) > 240)
        TOU pad("4+", 5));
      else
        TOU pad("", 5));
      if(a[x]->query_guild_name())
        TOU pad(capitalize((string)a[x]->query_guild_name()), 21));
      else
        TOU pad("None", 16));
        y++;
        TOU"\n");
    }
    else if(a[x]->query_level() >= 21 && !a[x]->query_invis())
    {
      if(y < 10)
        TOU pad("  "+y+":  "+a[x]->query_name(), 20));
      else
        TOU pad("  "+y+": "+a[x]->query_name(), 20));
      if(a[x]->query_level() > 1000)
        TOU pad("GOD", 8));
      else if(a[x]->query_level() >= 100)
        TOU pad("SWIZ", 8));
      else
        TOU pad("WIZ", 8));
        TOU pad("", 5));
      if(query_idle(a[x]) > 960)
        TOU pad("16+", 5));
      else if(query_idle(a[x]) > 720)
        TOU pad("12+", 5));
      else if(query_idle(a[x]) > 480)
        TOU pad("8+", 5));
      else if(query_idle(a[x]) > 240)
        TOU pad("4+", 5));
      else
        TOU pad("", 5));
      if(a[x]->query_guild_name())
        TOU pad(capitalize((string)a[x]->query_guild_name()), 21));
      else
        TOU pad("None", 16));
      y++;
      TOU"\n");
    }
  }
  TOU"\n");
  return 1;
}

