/* advance.h  -  smear / randmsg / learn / check / stats / guilded */
/* part of ghall.c */

smear_cmd(str)                       /*  drop to level 17 */
{
  int newxp, newxp2;
  if(!uncovered) return 0;
  if(str != "blood on the circle") return 0;
  newxp = 1040028;  /* level 17 */
  write("You cut your hand and smear blood on the circle.\n"+
    "The circle begins to glow, lighting up the forest.\n\n"+
    "Suddenly you feel a wrenching deep down...\n"+
    "You may now read the incantation.\n\n");
  TP->set_level(17);
  TP->set_extra_level(0);
  if(TP->query_exp() > newxp)
  {
    newxp2 = TP->query_exp() - newxp;
    TP->add_exp(newxp2 * -1);
  }
  TP->save();
  TP->reset();
  write_file("/players/zeus/circle/log/JOIN", ctime(time())+
    "   "+capitalize((string)TP->QRN)+" lost "+newxp2+
    " when "+TP->query_pronoun()+" joined.\n");
  return 1;
}


randmsg()
{
  int dogooder;
  dogooder = random(5);
  switch(dogooder)
  {
  case 0:
    write(BOLD+
    "\n\tThe only true power comes from complete knowledge.\n\n"+NORM);
    break;
  case 1:
    write(BOLD+
    "\n\tKilling newbies will get you nowhere.\n\n"+NORM);
    break;
  case 2:
    write(BOLD+
    "\n\tTrue power comes with true bravery...  face your foes.\n\n"+NORM);
    break;
  case 3:
    write(BOLD+"\n\tStrength is but a tool of true power.\n\n"+NORM);
    break;
  case 4:
    write(BOLD+"\n\tAssert your bravery to overcome spell failure.\n\n"+NORM);
    break;
  }
}

learn(string str)
{
  if(TP->query_level() < 21){
    write_file("/players/zeus/circle/log/ADV", ctime(time())+
    " - "+capitalize((string)TP->QRN)+" lrnd "+str+"  [L "+
    TP->query_level()+"+"+TP->query_extra_level()+"] "+
    "gxp: "+circle->GXP+"\n");
  }
  write(
    "\n\tEnergy surges from the circle...\n"+
    "\tYou are filled with knowledge...\n"+
    "\tYou have learned the spell '"+str+"'...\n\n");
    circle->set_skills(str);
    TP->save();
    circle = present("circle_object", TP);
    circle->update_obj(1);
    call_other(TP, "reset", 1);
    return 1;
}

check(string str)  /* does this_player have str spell */
{
  if(!circle) return 1;
  if(circle->qs(str)) return 0;
  else return 1;
}

stats(object bob)   /* If enough guild exp, increased mag, ste, end */
{
  int x,y,z,w;
  if(!bob) return 0;
  circle = present("circle_object", bob);
  if(!circle) return 0;

  /*  Set endurance to max - 8 mil gxp for max */
  y = (int)bob->query_level();
  w = (int)circle->query_guild_exp();
  if(y > 19)
    y = 19;
  if(w < 1000000)  /* mainly based on stealth, with level  [cap of 38] */
  {
    x = 8 + (y / 2) + ((int)bob->query_attrib("ste") + (w / 100000));
    if(x > 38)
      x = 38;
  }
  else   /* mainly based on gxp, with stealth and level   [cap of 80] */
    x = y + (int)bob->query_attrib("ste") + (w / 195000);
  if(x < 25)
    x = 25;
  else if(x > 80) 
    x = 80;
  if(x > circle->query_max_endurance())
    circle->set_max_endurance(x);

/*  10.31.02 - COMMENTED OUT ATTRIB INCREASES DUE TO ATTRIB SYSTEM CHANGES
  if(bob->query_level() < 20)
  {
    for(z = 0; z < 6; z++)
    {
      if(bob->query_attrib("mag") == (20 + z))
      {
        if(circle->GXP >= mag_cost[z])
        {
          geeber = 1;
          bob->set_attrib("mag", (21 + z));
          tell_object(bob, "\tYour magic increases.\n");
        }
      }
    }
    for(z = 0; z < 10; z++)
    {
      if(bob->query_attrib("ste") == (20 + z))
      {
        if(circle->GXP >= ste_cost[z])
        {
          geeber = 1;
          bob->set_attrib("ste", (21 + z));
          tell_object(bob, "\tYour stealth increases.\n");
        }
      }
    }
  }
  END 10.31.02 COMMENTS BY ZEUS  */

  if(circle->GXP >= 8000000)
  {
    circle->set_guild_exp(8000000);
    circle->set_perc(0);
  }
}


guilded(object guy)
{
  if(!guy) return 0;
  if(guy->query_guild_name() && guy->query_guild_name() != "none") 
	  return 0;
  if(guy->query_guild_rank()) return 0;
  if(guy->query_guild_exp()) return 0;
  return 1; 
}

