/***************************************************************************
 * PK Tracker Statistics Daemon
 * 
 * Earwax 08/03/03
 *
 * Track all the various stats for PKs
 *
 * *************************************************************************
 *
 * The following statistics are going to be tracked.
 *
 * Weapons   - Overall (most popular weapons used, basically)
 * Kills     - By guild, player
 * Deaths    - by guild, player
 * Points    - By guild, player
 * Gangbangs - By guild, player - not sure how to work this one
 * Solos     - By guild, player
 *
 * *************************************************************************
 *
 * NOTE: I use mappings for convenience.  Those mappings have to save as 
 *       arrays, however, because this driver doesn't handle mappings
 *       properly.  Inefficient, but nothing I can do about it.
 *
 * Format: 
 *
 * ([ name: ({ kills, deaths, points, bang_with, bang_against, solos }) ])
 *
 * *************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

#define GKILLS Guilds[gname][0]
#define GDEATHS Guilds[gname][1]
#define GPOINTS Guilds[gname][2]
#define GBANG_W Guilds[gname][3]
#define GBANG_A Guilds[gname][4]
#define GSOLOS Guilds[gname][5]
#define GDT Guilds[gname][6]
#define PKILLS Players[pname][0]
#define PDEATHS Players[pname][1]
#define PPOINTS Players[pname][2]
#define PBANG_W Players[pname][3]
#define PBANG_A Players[pname][4]
#define PSOLOS Players[pname][5]
#define PDT Players[pname][6]

/* Global Variables */

static mapping  Guilds;                /* Guild stats                     */
       string  *Gindices;              
       int     *Gvalues;               
static mapping  Players;               /* Player Stats                    */
       string  *Pindices;
       int     *Pvalues;
static mapping  Weapons;               /* Weapon stats                    */
       string  *Windices;              /* For saving purposes             */
       int     *Wvalues;               /* Saving purposes.                */

/* ******
 * Temporary for debugging 
*/
void tell_wax(string msg) {
  object wax;
  if (wax = find_player("earwax")) tell_object(wax,msg);
}



/* *************************************************************************
 * load_info, save_info
 *
 * Convert mappings to arrays to save, convert arrays to mappings to load
 *
*/

void
load_info()
{
  int i;

  restore_object("/"+STAT_SAVE);
  Guilds = ([ ]);
  Players = ([ ]);
  Weapons = ([ ]);

  i = sizeof(Gindices);
  while(i--)
    Guilds += ([ Gindices[i] : Gvalues[i] ]);

  i = sizeof(Windices);
  while(i--)
    Weapons += ([ Windices[i] : Wvalues[i] ]);

  i = sizeof(Pindices);
  while(i--)
    Players += ([ Pindices[i] : Pvalues[i] ]);
}

void
save_info()
{
  Gindices = m_indices(Guilds);
  Gvalues  = m_values(Guilds);
  Pindices = m_indices(Players);
  Pvalues = m_values(Players);
  Windices = m_indices(Weapons);
  Wvalues = m_values(Weapons);
  save_object(STAT_SAVE);
}

/* *************************************************************************
 * reset
 *
*/

void
reset(status arg)
{
  if (arg)
    return;

  load_info();

  if (!Guilds)
  {
    Guilds = ([ ]);
  }
  else
  {
  }
}

/* *************************************************************************
 * add_stats
 *
 * In format: weapon short
 *            guildname
 *            player
 *            points (0 for a death)
 *            with
 *            against
 *
*/

void
add_stats(string w, string gname, string pname, int num, int with, int against)
{

  if (!member(Guilds,gname))
    Guilds[gname] = ({ 0, 0, 0, 0, 0, 0, 0, 0 });
  if (!member(Players,pname))
    Players[pname] = ({ 0, 0, 0, 0, 0, 0, 0, 0 });

/*
  tell_wax("========================================================\n"
    + "Information already existing:\n"
    + "Player name: "+pname+"\t\t"
    + "Guildname: "+gname+"\n"
    + "Guild array: Kills/Deaths/Points/With/Against/Solos\n"
    + GKILLS+"\t"+GDEATHS+"\t"+GPOINTS+"\t"+GBANG_W+"\t"+GBANG_A+"\t" 
    + GSOLOS+"\n");
*/

  if (!num) /* it's a death to record */
  {
    GDEATHS++;
    GDT += with;
    PDEATHS++;
    PDT += with;
  }        

  else /* It's a kill to record */
  {
    if (Weapons[w])
      Weapons[w]++;
    else
      Weapons[w] = 1;

    GKILLS++;                PKILLS ++;
    GPOINTS += num;          PPOINTS += num;
    GBANG_W += with;         PBANG_W += with;
    GBANG_A += against;      PBANG_A += against;

    if (with == 1)
    {
      PSOLOS++;
      GSOLOS++;
    }
  }

  save_info();

/*
  tell_wax("--------------------------------------------------------\n"
    + "Information added by add_stats:\n"
    + "Player name: "+pname+"\t\t"
    + "Guildname: "+gname+"\n"
    + "Guild array: Kills/Deaths/Points/With/Against/Solos\n"
    + GKILLS+"\t"+GDEATHS+"\t"+GPOINTS+"\t"+GBANG_W+"\t"+GBANG_A+"\t" 
    + GSOLOS+"\n"
    + "========================================================\n");
*/

}

/* *************************************************************************
 * Sort Functions
 *
*/


/* *************************************************************************
 * Output Statistics
 *
*/
