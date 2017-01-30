#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string msg, string channel)
{
  object gob, gobb, target;
  string who;
  int amt, has;
  int cost, cost2;
  
  if(!msg)
  {
    tell_object(this_player(), "Please use: rpt <amt> <name>\n");
    return 1;
  }
  if(!(sscanf(msg, "%d %s", amt, who)))
  {
    tell_object(this_player(), "Please use: rpt <amt> <name>\n");
    return 1;     
  }

  target = find_player(who);
  
  if(!target)
  {
    tell_object(this_player(), capitalize(who)+" is not logged in right now.\n");
    return 1;
  }
  if(target == this_player())
  {
    tell_object(this_player(), "You can't give Skill Points to yourself!\n");
    return 1;
  }
  if(amt < 0)
  {
    tell_object(this_player(), "You must use a positive amount.\n");
    return 1;
  }
  
  gob = present("communicator", this_player());
  gobb = present("communicator", target);
 
  if(!gobb)
  {
    tell_object(this_player(), capitalize(who)+" is not a Power Ranger!\n");
    return 1;
  }
   
  cost = (int)gob->QNextSkillCost();
  cost2 = (int)gobb->QNextSkillCost();

  if(cost2 > cost)
  {
    tell_object(this_player(), "You can't give points to someone that has a higher cost than you.\n");
    return 1;
  }

  has = (int)gob->QSkillPoints();

  if(amt > has)
  {
    tell_object(this_player(), "You only have "+has+" Unused Skill Points to give.\n");
    return 1;
  }
  
  gob->ASkillPoints(-amt);
  gobb->ASkillPoints(amt);

  tell_object(this_player(),  "By the grace of Zordon, you transfer "+amt+" Skill Point(s) to "+capitalize(who)+".\n");
  tell_object(target, "By the grace of Zordon, "+this_player()->query_name()+" transfers "+amt+" Skill Point(s) to you.\n");

  gob->SaveRanger();
  gobb->SaveRanger();
             
write_file("/players/guilds/Rangers/Log/POINT_TRANSFERS", this_player()->query_name()+" transfered "+amt+" Skill Point(s) to "+capitalize(who)+" on "+ctime()+".\n");

  return 1;
}

status
RangerInfo(string str)
{
  write(format("\
  The \'rpt\' command allows you to transfer unused Skill Points to a fellow Ranger. \
 The only requirement is that your cost level is equal to or above that of the\
 person you are transferring points to.\n"));
  return 1;
}

status
QRangerInfo(){ return 1; }

  
