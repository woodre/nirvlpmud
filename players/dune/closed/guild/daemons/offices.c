#include "../DEFS.h"
#include DEFS_OFFICES
#include DEFS_GLEVELS


status officerStatsUpdated;


status query_officers_updated()
{
  return officerStatsUpdated;
}


void set_officers_updated(status updated)
{
  officerStatsUpdated = updated;
}


string findRoleGivenStone(string stone)
{
  switch(stone)
  {
    case "adamantium": return ADAMANTIUM;
    case "diamond":    return DIAMOND;
    case "sapphire":   return SAPPHIRE;
    case "emerald":    return EMERALD;
    case "onyx":       return ONYX;
    case "ruby":       return RUBY;
    case "pearl":      return PEARL;
    case "opal":       return OPAL;
    case "jade":       return JADE;
  }
  return 0;
}


string findRole(object ob)
{
  string role;
  role = findRoleGivenStone((string)IPOB->query_stone());
  return role;
}


string findStone(string role)
{
  switch(role)
  {
    case ADAMANTIUM: return "adamantium";
    case DIAMOND:    return "diamond";
    case SAPPHIRE:   return "sapphire";
    case RUBY:       return "ruby";
    case EMERALD:    return "emerald";
    case ONYX:       return "onyx";
    case PEARL:      return "pearl";
    case OPAL:       return "opal";
    case JADE:       return "jade";
  }
  return 0;
}


int getRoleRank(string role)
{
  switch(role)
  {
    case ADMINIUM:   return 8;
    case ADAMANTIUM: return 8;

    /* set all unused and wiz-appointed-only
       offices at a higher rank than DIAMOND */
    case JADE:       return 7;
    case OPAL:       return 7;
    case PEARL:      return 7;

    case DIAMOND:    return 6;
    case SAPPHIRE:   return 4;
    case EMERALD:    return 3;
    case ONYX:       return 2;
    case RUBY:       return 1;
  }
  return 0;
}


int getTier(string sphere)
{
  switch(sphere)
  {
    case WIZ_TIER3_A:
    case WIZ_TIER3_B: 
    case WIZ_TIER3_C:
    case WIZ_TIER3_D:
      return 3;
    case WIZ_TIER2_A:
    case WIZ_TIER2_B:
      return 2;
    case WIZ_TIER1_A:
    case WIZ_TIER1_B:
      return 1;
  }
  return 0;
}


void list(object player, string role)
{
  string msg;
  int myRank;
  myRank = getRoleRank(role);

  msg = "Offices you may grant:\n"+
        RED+".*.....*.....*."+OFF+"\n";
  if (myRank > getRoleRank(RUBY))     msg+= capitalize(RUBY)     +"\n";
  if (myRank > getRoleRank(ONYX))     msg+= capitalize(ONYX)     +"\n";
  if (myRank > getRoleRank(EMERALD))  msg+= capitalize(EMERALD)  +"\n";
  if (myRank > getRoleRank(SAPPHIRE)) msg+= capitalize(SAPPHIRE) +"\n";
  if (myRank > getRoleRank(DIAMOND))  msg+= capitalize(DIAMOND)  +"\n";

  /* place all unused and wiz-appointed-only offices past DIAMOND */
  if (myRank > getRoleRank(OPAL))     msg+= capitalize(OPAL)     +"\n";
  if (myRank > getRoleRank(JADE))     msg+= capitalize(JADE)     +"\n";
  if (myRank > getRoleRank(PEARL))    msg+= capitalize(PEARL)    +"\n";

  msg += RED+".*.....*.....*."+OFF+"\n";
  tell_object(player, msg);
}


status checkStone(object ob, string stones)
{
  string * stoneArray;
  int i;

  if(!ob || !IPOB || !stones) return 0;
  if(IPOB->guild_wiz()) return 1;
  stoneArray = explode(stones, " ");
  for(i = 0; i < sizeof(stoneArray); i++) {
    if((string)IPOB->query_stone() == stoneArray[i]) return 1;
  }
  return 0;
}


/* lists spheres of influence that Immortals play a part in */
void listSpheres(string str)
{
  write(
      pad(WIZ_TIER3_A, 20)+WIZ_TIER3_A_DUTY+"\n"
    + pad(WIZ_TIER3_B, 20)+WIZ_TIER3_B_DUTY+"\n"
    + pad(WIZ_TIER3_C, 20)+WIZ_TIER3_C_DUTY+"\n"
    + pad(WIZ_TIER3_D, 20)+WIZ_TIER3_D_DUTY+"\n"
    + pad(WIZ_TIER2_A, 20)+WIZ_TIER2_A_DUTY+"\n"
    + pad(WIZ_TIER2_B, 20)+WIZ_TIER2_B_DUTY+"\n"
    + pad(WIZ_TIER1_A, 20)+WIZ_TIER1_A_DUTY+"\n"
    + pad(WIZ_TIER1_B, 20)+WIZ_TIER1_B_DUTY+"\n"
  );
}


/* Returns the full title of the guild member by the name of
   "pName" with sphere "sphere".
 */
string getSphereTitle(string pName, string sphere)
{
  if (pName == OWNER1) 
    return capitalize(ADMINIUM) + " of " + capitalize(WIZ_TIER1_A);

  if (pName == OWNER2) 
    return capitalize(ADMINIUM) + " of " + capitalize(WIZ_TIER1_B);

  switch(sphere)
  {
    case WIZ_TIER3_A:
    case WIZ_TIER3_B: 
    case WIZ_TIER3_C:
    case WIZ_TIER3_D:
    case WIZ_TIER2_A:
    case WIZ_TIER2_B:
      return capitalize(ADAMANTIUM) + " of " + capitalize(sphere);
  }

  return 0;
}


/* checks validity of a sphere name for player ob */
string findSphere(object ob, string sphere)
{
  string title;
  if (!IPOB) return 0;
  title = getSphereTitle(ORN, sphere);
  return title;
}


void empowerUsage(string role)
{
   tell_object(TP, "Usage: empower <who> <type> [grant/remove]\n"+
                   "       *[grant/remove] grants/removes the position\n"+
                   "       *Choose <type> among the list below...\n");
   list(TP, role);
}


status empowerFunc(string str, status verbose)
{
  object playerOnline, statOb;
  string myRole, who, type, flag, promoteStone, capName, preRole;
  int promoteRoleRank, preRoleRank;
  status cloned;

  if (!verbose)
  {
    myRole = ADMINIUM;
  }
  else if (TP->query_level() >= 21)
  {
    myRole = ADMINIUM;
  }
  else
  {
    myRole = findRoleGivenStone((string)IPTP->query_stone());
  }

  if (!sscanf(str, "%s %s %s", who, type, flag))
  {
    if (verbose) empowerUsage(myRole);
    return 0;
  }

  if (!type || !flag)
  {
    if (verbose) empowerUsage(myRole);
    return 0;
  }

  flag = lower_case(flag);
  who  = lower_case(who);
  capName = capitalize(who);

  if (!(flag == "grant" || flag == "remove")) return 0;

  if (!findStone(type)) return 0;
  promoteStone = findStone(type);
  if (type == ADAMANTIUM)
  {
    if (verbose) write("Use the 'set_immortal' command to set guild wizhood.\n");
    return 0;
  }

  playerOnline = find_player(who);
  if (playerOnline)
  {
    cloned = 0;
    statOb = present(GUILD_ID, playerOnline);
  }
  else
  {
    /* target does not have to be online, isn't that cool! */
    statOb = clone_object(GUILDOBJ);
    cloned = 1;
    if (!statOb->external_restore_me(who))
    {
      if (verbose) write("Unable to obtain "+capName+"'s guild info.\n");
      destruct(statOb);
      return 0;
    }
  }

  promoteRoleRank = getRoleRank(findRoleGivenStone(promoteStone));
  if (getRoleRank(myRole) <= promoteRoleRank &&
      !((string)this_player()->query_real_name() == who && flag == "remove"))
  {
    write("You are not THAT powerful!\n");
    if (cloned) destruct(statOb);
    return 0;
  }

  preRole = findRoleGivenStone((string)statOb->query_stone());
  preRoleRank = getRoleRank(preRole);

  if (flag == "grant")
  {
    if ((string)statOb->query_stone() == promoteStone)
    {
      if(verbose) write(capName+" was already a "+type+".\n");
      if (cloned) destruct(statOb);
      return 0;
    }
    else if (preRoleRank > promoteRoleRank)
    {
      if(verbose)
        write(capName+" is already of higher rank.\n"+
              capName+" must first be removed from "+capitalize(preRole)+".\n");
      if (cloned) destruct(statOb);
      return 0;
    }
    else
    {
      set_officers_updated(0);
      statOb->set_stone(promoteStone);
      if (playerOnline)
      {
        statOb->save_me();
        /* force init */
        move_object(statOb, playerOnline);
        tell_object(playerOnline, "You have been empowered as "+capitalize(type)+"!\n");
      }
      else
      {
        statOb->external_save_me(who);
      }
      call_other(CHANNELD, "overchannel", capName+" has become "+capitalize(type)+"!\n");
      if(verbose)
      {
        write("You empower "+capName+
          " with the office of "+capitalize(type)+".\n");
        write_file(LOGDIR + "/EMPOWER", TRN+" made "+capName+
          " a "+type+". ("+ctime()+")\n");
      }
      else write_file(LOGDIR + "/EMPOWER", 
        capName+" became "+type+". ("+ctime()+")\n");
    }
  }

  if (flag == "remove")
  {
    if((string)statOb->query_stone() != promoteStone)
    {
      write(capName+" is not a "+type+" in the first place.\n");
      if (cloned) destruct(statOb);
      return 0;
    }
    else
    {
      set_officers_updated(0);
      statOb->set_stone(0);
      if (playerOnline)
      {
        statOb->save_me();
        /* force init */
        move_object(statOb, playerOnline);
        tell_object(playerOnline, "You have been removed from the office of "+
          capitalize(type)+".\n");
      }
      else
      {
        statOb->external_save_me(who);
      }
      call_other(CHANNELD, "overchannel", 
        capName+" is no longer "+capitalize(type)+".\n");
      if (verbose)
      {
        write("You remove "+capName+
          " from the office of "+capitalize(type)+".\n");
        write_file(LOGDIR + "/EMPOWER", TRN+" removed "+capName+
          " from the office of "+type+". ("+ctime()+")\n");
      }
      else write_file(LOGDIR + "/EMPOWER", 
        capName+" removed from "+type+". ("+ctime()+")\n");
    }
  }

  if (verbose) write("Deed accomplished.\n");
  if (cloned) destruct(statOb);
  return 1;
}


status empowerForce(string str)
{
  return empowerFunc(str, 0);
}


status empower(string str)
{
  return empowerFunc(str, 1);
}
