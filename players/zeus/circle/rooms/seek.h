/* seek.h -  the seek command */
/* part of ghall.c */

status seek_cmd(string str)
{
  int x;
  if(!str) return 0;
  if(!uncovered) return 0;
  if(!query_touched(TP))
  {
    write("You are not touching the circle.\n");
    return 1;
  }
  circle = present("circle_object", TP);
  geeber = 0;
  if(TP->test_dark()) return 1;  /* no dark seek */
  if(str == "rules")
    cat("/players/zeus/circle/misc/rules");
  else if(str == "story")                                 /* info on area */
  {
    write("You may seek the story of the following chapters...\n\n"+
      "    Chapter 1:  Conquest\n"+
      "    Chapter 2:  New Beginning\n"+
      "    Chapter 3:  Retaliation\n"+
      "    Chapter 4:  Conclusion\n"+
      "    Chapter 5:  The Circle today\n\n");
  }
  else if(str == "1" || str == "chapter 1" || str == "conquest")
    cat("/players/zeus/circle/misc/chp1");
  else if(str == "2" || str == "chapter 2" || str == "new beginning")
    cat("/players/zeus/circle/misc/chp2");
  else if(str == "3" || str == "chapter 3" || str == "retaliation")
    cat("/players/zeus/circle/misc/chp3");
  else if(str == "4" || str == "chapter 4" || str == "conclusion")
    cat("/players/zeus/circle/misc/chp4");
  else if(str == "5" || str == "chapter 5" || str == "the circle today")
    cat("/players/zeus/circle/misc/chp5");
  else if(str == "information" || str == "info")           /* info on guild */
  {
    if(GUILD)
    {
      write(
        "\n\n\t\tThe Fallen\n"+RED+
        " ********************************************************\n"+
        " *\t\t\t\t\t\t\t*\n"+
        " *  "+NORM+
        "seek power\t\tadvance your abilities"+RED+
        "\t\t*\n *  "+NORM+
        "seek knowledge\tknow of your abilities"+RED+
        "\t\t*\n *  "+NORM+
        "chelp\t\tbasic commands"+RED+
        "\t\t\t*\n *  "+NORM+
        "seek rules\t\tthe rules of the Fallen"+RED+
        "\t\t*\n *  "+NORM+
        "seek story\t\tthe history of the Fallen Lands"+RED+
        "\t*\n *  "+NORM+
        "touch symbol [1-7]\tthe wisdom of the Circle"+RED+
        "\t*\n *  "+NORM+
        "seek facts\t\tsee older news info"+RED+
        "\t\t*\n *  "+NORM+
        "seek masters\tsee the masters of the Circle"+RED+
        "\t*\n *  "+NORM+
        "free self\t\tleave this path"+RED+
        "\t\t\t*\n *\t\t\t\t\t\t\t*\n"+
        " ********************************************************\n"+NORM+
        "\n\n");
    }
    else if(NOGUILD)
      cat("/players/zeus/circle/misc/info");
  }
  else if(str == "facts")
    cat("/players/zeus/circle/misc/player_facts");
  else if(str == "masters")
  {
    peeps = get_dir("/players/zeus/closed/circle_member/*.o");
    chh = sizeof(peeps);
    y = 0;
    write(RED+pad(" ", 26)+"Masters of the Circle\n"+NORM);
    for(z = 0; z < chh; z++)
    {
      sscanf(peeps[z], "%s.", why);
      if(restore_object("players/zeus/closed/circle_member/"+why))
      {
        if(guild_exp == 8000000 && index(excluded, why) < 0)
        {
          y++;
          write(pad(" ",30)+y+pad(".",3)+capitalize(why)+"\n");
        }
      }
      why = 0;
    }
    write("\n");
    return 1; 
  }
  else if(str == "knowledge")                             /* info on spells */
  {
    if(GUILD && circle)
    {
      write("These are your spells...\n\n");
      circle->tell_skills(1);
      write("You may 'seek' information on any of them.\n");
    }
    else if(GUILD && !circle)
    {
      write("You lost your guild object!\n");
      MO(CO("/players/zeus/circle/circle.c"), TP);
      command("restoreme", TP);
      if(TP->query_level() < 21)
      {
        write_file("/players/zeus/circle/log/restore", ctime(time())+
        "   "+capitalize((string)TP->QRN)+
        " restored guild obj from ghall.\n");
      }
    }
  }
  else if(str == "power")                           /* get new spells/stats */
  {
    circle = present("circle_object", TP);
    if(NOGUILD && circle){
      if(TP->query_level() > 19){
        write("\nYou have the obj but not the name...\n"+
          "\t\tContact Zeus.\n\n");
        return 1;
      }
      return 1;
    }
    if(GUILD && !circle)
    {
      write("You lost your guild object!\n");
      MO(CO("/players/zeus/circle/circle.c"), TP);
      if(TP->query_level() < 21)
      {
      write_file("/players/zeus/circle/log/restore", ctime(time())+
        "   "+TP->QRN+" restored guild obj from ghall.\n");
      }
      return 1;
    }
    else if(GUILD && circle)
    {
      circle = present("circle_object", TP);
      if((int)TP->query_level() < 19)
      {
        write_file("/players/zeus/circle/log/EXP", ctime(time())+
          " - "+capitalize((string)TP->QRN)+"   gxp: "+circle->GXP+
          "   xp: "+TP->query_exp()+"\n");
      }
      else if((int)TP->query_level() == 19)
      {
        write_file("/players/zeus/circle/log/EXP_19", ctime(time())+
          " - "+capitalize((string)TP->QRN)+"   gxp: "+circle->GXP+
          "   xp: "+TP->query_exp()+"\n");
      }
      x = random(7);
      switch(x)
      {
      case 0:
        write("You close your eyes and seek guidance from the circle.\n");
        break;
      case 1:
        write("You close your eyes and let the circle guide you.\n");
        break;
      case 2:
        write("You close your eyes and look within yourself.\n");
        break;
      case 3:
        write("You close your eyes and let the shadows guide you.\n");
        break;
      case 4:
        write("You close your eyes and allow the circle to guide"+
          " your mind.\n");
        break;
      case 5:
        write("You close your eyes as shadows drift around you.\n");
        break;
      case 6:
        write("You close your eyes as shadows rise up around you.\n");
        break;
      }
      stats(TP);
      circle = present("circle_object", TP);
      if(circle->GXP >= 0 && check("focus"))
        learn("focus");
      else if(circle->GXP >= 50000  && check("beckon shadows"))
        learn("beckon shadows");
      else if(circle->GXP >= 100000 && check("wither corpse"))
        learn("wither corpse");
      else if(circle->GXP >= 250000 && check("drain"))
        learn("drain");
      else if(circle->GXP >= 450000 && check("teleport"))
        learn("teleport");
      else if(circle->GXP >= 600000 && check("shield"))
        learn("shield");
      else if(circle->GXP >= 750000 && check("weaken"))
        learn("weaken");
      else if(circle->GXP >= 950000 && check("meditate"))
        learn("meditate");
      else if(circle->GXP >= 1200000 && check("web"))
        learn("web");
      else if(circle->GXP >= 1500000 && check("blast"))
        learn("blast");
      else if(circle->GXP >= 1800000 && check("empower"))
        learn("empower");
      else if(circle->GXP >= 1950000 && check("know") 
        && TP->query_level() > 17)
        learn("know");
      else if(circle->GXP >= 2100000 && check("shadowform"))
        learn("shadowform");
      else if(circle->GXP >= 2400000 && check("descend"))
        learn("descend");
      else if(circle->GXP >= 2700000 && check("shadowcloak"))
        learn("shadowcloak");
      else if(circle->GXP >= 3000000 && check("dark assistance"))
        learn("dark assistance");
      else if(circle->GXP >= 3300000 && check("repulsion"))
        learn("repulsion");
      else if(circle->GXP >= 3600000 && check("vanish"))
        learn("vanish");
      else if(circle->GXP >= 3900000 && check("rage"))
        learn("rage");
      else if(circle->GXP >= 4300000 && check("dark prayer"))
        learn("dark prayer");
      else if(circle->GXP >= 5000000 && check("weave"))
        learn("weave");
      else if(circle->GXP >= 5500000 && check("see"))
        learn("see");
      else if(circle->GXP >= 6000000 && check("vigor"))
        learn("vigor");
      else if(circle->GXP >= 7000000 && check("embrace"))
        learn("embrace");
      else if(circle->GXP >= 8000000 && check("siphon"))
        learn("siphon");
      else if(!geeber)
      {
        x = random(3);
        switch(x){
        case 0:
          write("You are not ready yet to advance your knowledge.\n");
          break;
        case 1:
          write("You open your eyes and feel the same.\n");
          break;
        case 2:
          write("You open your eyes and feel nothing new.\n");
          break;
        }
        if(!random(20))
          randmsg();
      }
      circle = present("circle_object", TP);
      TP->save();
      circle->save_circle(1);
      /*  circle->update_obj(1); not necessary */
      call_other(TP, "reset", 1);
      return 1;
    }  /* end GUILD and circle */
    return 1;
  } /* end seek power */
  else if(circle && !check(str))
    info(str);
  else return 0;
  return 1;
}

