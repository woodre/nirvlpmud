/*  leave.h  */
/****************************************************************************/
/*************************** Leaving guild **********************************/
/* part of ghall.c */

status free_cmd(string str)
{
  int gexp, grank;
  object circle;
  if(!str) return 0;
  if(NOGUILD) return 0;
  if(!uncovered) return 0;
  if(str == "sparks")
  {
    if((string)TP->QRN != "sparks") return 0;
    write("sparks-----\n");
      write_file("/players/zeus/circle/log/LEAVE", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" [L "+
        TP->query_level()+"+"+TP->query_extra_level()+"] - errored\n");
      rm("/players/zeus/closed/circle_member/"+TP->QRN+".o");
      TP->set_home(0);
      TP->set_guild_name(0);
      TP->set_guild_file(0);
      TP->set_home("/room/church");
      command("save",TP);
      circle = present("circle_object", TP);
      if(!circle){ write("------done w/o gob\n"); return 1; }
      else
        destruct(circle);
      write("------done w/ gob\n");
      return 1;
  }
  if(str == "self")
  {
    if(!query_touched(TP))
    {
      write("You must be touching the circle.\n");
      return 1;
    }
    say(TP->QN+" is struck down by the force of the circle.\n");
    write("You forsake your chosen path...\n"+
      "You feel a strong pain shoot through your body...\n"+
      "You are left lying on the ground, writhing in pain...\n"+
      "But you gain your freedom...\n\n");
    sub_touched(TP);
    if(TP->query_level() < 20)
    {
      circle = present("circle_object", TP);
      if(!circle) return 0;
      write_file("/players/zeus/circle/log/LEAVE", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" [L "+
        TP->query_level()+"+"+TP->query_extra_level()+"]  Gxp: "+
        circle->GXP+"\n");
      circle->back_me_up();
      rm("/players/zeus/closed/circle_member/"+TP->QRN+".o");
      TP->set_home(0);
      TP->set_guild_name(0);
      gexp = (int)TP->query_guild_exp();
      grank = (int)TP->query_guild_rank();
      TP->add_guild_rank(-grank);
      TP->add_guild_exp(-gexp);
      TP->set_guild_file(0);
      TP->set_attrib("mag", 1);
      TP->set_attrib("ste", 1);
      destruct(circle);
      TP->set_home("/room/church");
      command("save",TP);
      TP->heal_self(-666);
      TP->hit_player(666);
      return 1;
    }
    else 
    {
      write("Don't be such a... player!\n");
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}

