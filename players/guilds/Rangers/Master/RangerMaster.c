/* The Guild Power Level (pool) */
#pragma strict_types

#include "../RangerDefs.h"
#include <ansi.h>

mapping PowerPoints;
string playername;
string pathname;
string guildname;

void
SPowerPoints()
{
  PowerPoints = ([ ]);
  PowerPoints["Power Ranger"] = 0;
  PowerPoints["Dark Ranger"] = 0;
}

int
QPowerPoints(string channel)
{
  if(!PowerPoints)
    SPowerPoints();
  return PowerPoints[channel];
}

void
ResetPowerPoints(string channel)
{
  PowerPoints[channel] = 0;
}

/*  Called by object or function to add or subtract from guild power */
varargs status
APowerPoints(int num, string channel)
{
  if(!PowerPoints)
    SPowerPoints();
  if( "/players/guilds/Rangers/CommandCenter/CommandCenter.c"->PowerCheck( 
      channel))
  {
    PowerPoints[channel] += num;
  }
  else
  {
    return 0;
  }
/*  No cap to power --Vital Friday, July 6, 2007  */
/* if( (PowerPoints[channel]) >= (17250)) PowerPoints[channel] = 17250; */
  "/players/guilds/Rangers/CommandCenter/CommandCenter.c"->APower(num,channel);
  return 1;
}

mixed
CheckPower(string channel) /* For Player to Check Guild Power Level */ 
{
  string msg;
  if(!PowerPoints)
    APowerPoints(0, channel);
  switch(PowerPoints[channel])
  {
    case 0            : msg = BOLD + "GONE" + NORM;             break;
    case 1..3000      : msg = HIR + "Critical" + NORM;          break;
    case 3001..5000   : msg = RED + "Very Low" + NORM;          break;
    case 5001..9000   : msg = YEL + "Low" + NORM;               break;
    case 9001..13000  : msg = "at " + HIY + "Normal" + NORM;    break;
    case 13001..15000 : msg = "in" + GRN + "Good Shape" + NORM; break;
    case 15001..17249 : msg = HIG + "Very Good" + NORM;         break;
    case 17250..30000 : msg = "is " + HIC + "Extreme" + NORM;    break;
    case 30001..50001 : msg = MAG + "Ridiculous" + NORM;         break;
    default: msg = HIB + "Sweet" + NORM;
  }
  if(!this_player())
    return "GUILD POWER LEVEL: "+msg+".\n";
  write("GUILD POWER LEVEL: "+QPowerPoints(channel)+".\n");
  return 1;
}

void
set_up()
{
  if(this_player()->is_player())
  {
    call_out("find_monster",1);
    playername = (string) this_player()->query_name();
    pathname = file_name( this_object() );
    guildname = (string) this_player()->query_guild_name();
  }
}

status
find_monster()
{
  if(guildname == "rangers" || guildname == "dark rangers")
  {
    if(random(100) < 20)
    {
      if(!find_living("RangerMonster"))
      {
        MASTER->CreateMonster(playername, this_object()->short(), pathname);
        return 0;
      }   
    }
  }     
  if(random(100) < 5)
  {
    if(!find_living("RangerMonster"))
    {
      MASTER->CreateMonster(playername, this_object()->short(), pathname);
    }   
  }
  return 1;
}   
