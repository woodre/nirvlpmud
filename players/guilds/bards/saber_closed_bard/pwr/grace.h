/*
 *  The first step in sponsoring a new Bard.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

grace(str)  {
object OB, GRACE;
string who;

if(spell(-100,8,0) == -1) return 0;

if(!str || sscanf(str, "%s", who) !=1)  {
  write("Syntax: grace < bard to be >\n");
  return 1;
        }

if(!present(who, environment(TP)))  {
  write(CAP+" is not close enough to grace.\n");
  return 1;
        }

  OB = find_player(who);

if(OB->query_level() < 4)  {
  write("Players must be at least level four to join the Bardic Guild.\n");
  return 1;
        }

if(OB->query_guild_name() == "none" ||
   OB->query_guild_name() == 0 ||
   OB->query_guild_exp() == "0")  {

 GRACE = clone_object("/players/saber/closed/bard/itm/bard_grace.c");
    move_object(GRACE, OB);
    write("You give "+CAP+" your graces to become a Bard.\n");
    say(tp+" gives "+CAP+" "+POSS+" graces to become a Bard.\n",OB);
    tell_object(OB, tp+" gives you "+POSS+" graces to become a Bard.\n");
    return 1;
       } 

  write("This player is a member of another guild.  If there is a problem\n"+
    "ask a wizard for help.\n");
    return 1;
        }
