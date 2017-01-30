/* *************************************************************************
 * /players/earwax/closed/TRACKER/bin/twho.c
 *
 * PKS Who List
 *
 * Earwax 7/28/03
 *
 * *************************************************************************
 * 
 * Shows all visible people on.  If They are invisible, it shows 'Unknown'
 * as their location, and their name in () - ie, (Earwax), (Someone), etc
 *
 * Color codes:
 * PK set:             red
 * PK area:            yellow
 * PK set, in PK area: bold red
 * 
 * Breaks the list into wizard and player sections, and totals them.
 * N/A indicates they don't have the pk tracker on them.
 * Wizard kills don't show, of course.
 * How it looks:
 *
 * =========================================================================
 * =                       PKS Who Listing                                 =
 * =========================================================================
 *        Boltar       God     Knights       Blues Brothers Location     
 *        Vertebraker  1000    Shardak       The Grotto
 *        (Linus)      40      Shardak       Unknown
 * -------------------------------------------------------------------------
 *     0  Hardly       19+100  Black Circle  Village Green [n,w,e]
 *  3569  (Orb)        19+33   Cyberninja    Unknown
 *   N/A  Feyth        19+30   Healer        Village Green [n,w,e]
 *    32  Fatslapper   18      Dark Order    Dark Room
 *   N/A  Jiveturkey   10      Symbiote      The Altar [w,e]
 * =========================================================================
 * = Wizards: 3  Players: 5  Total Visible: 8                              =
 * =========================================================================
 * 
 * 10/05/05 Earwax - Added an idle indicator
 * 10/07/07 Earwax - No longer shows wizards.
*/

#include "../defs.h"
#define TWHO_SAVE "players/earwax/closed/TRACKER/bin/twho"

inherit WAXFUNS;

/* Global Variables */
int Max_Ever;
string Max_Ever_Time;
static int Max_This_Reboot;

void tell_wax(string arg) { object ob; if (ob = find_player("earwax")) tell_object(ob,arg); }

string
format_line(string str)
{
  int i, q, t;

  i = ansi_strlen(str);
  if (i <= 78) return str+"\n";
  q = strlen(str);
  t = (q - i) + 77;

  return str+NORM+NORM+"\n";
/* this doesn't work right
  return str[0..t]+NORM+NORM+"\n";
*/
}

string
format_guild(object ob)
{
  string name;

  name = (string)ob->query_guild_name();
  if (name == 0 || name == "0") name = "none";
  return capitalize(name);
}

status
sort_by_level(object ob1, object ob2)
{
  int la,lb;

  la = (int)ob1->query_level();
  lb = (int)ob2->query_level();
  if (la == lb && la == 19)  
    return ((int)ob1->query_extra_level() < (int)ob2->query_extra_level());
  return la < lb;
}

string
*dump_who_list()
{
  object *temp;
  int i, siz, wizzes, players;
  string line, *output;
  string idle;
  string *colors;
  status wiz_flag;

  colors = ({ NORM, YEL, RED, HIR });
  wizzes = 0; players = 0;
  wiz_flag = ((int)this_player()->query_level() > 19 ? 1 : 0);

  output  = ({ HIB + "=============================================================================\n"+NORM +
               HIB + " "+ NORM+"PKS   Name           Level  Guild           Location                   "+HIB+"\n" +
          HIB + "=============================================================================\n"+NORM });

  siz = sizeof(temp = (object *)CHANNELD->filter_invis(users()));
  temp = sort_array(temp, "sort_by_level");

  /* Generate the actual list 
   * Points | Name | Level | Guild | Location 
   * PK players are in red, players in pk areas are in yellow, 19+ only 
   * Invisible players show up in (), and their location as 'Unknown'
  */
  for (i = 0; i < siz; i++)
  {
    string info, name, points, loc, t2;
    int t, l, color;
    object ob;

    l = (int)temp[i]->query_level();
    /* Added idle indicator 10/05/05
    name = (query_idle(temp[i]) > 500 ? HIK+"I"+NORM+NORM : " ")
      + (string)temp[i]->query_name();
    */
    name = (string)temp[i]->query_name();
    idle = (query_idle(temp[i]) > 300 ? HIK+"(I)"+NORM+NORM : "   ");
    
    if (!environment(temp[i])) loc = "None";
    else
    {
      if (temp[i]->query_invis())
      {
        name = "("+name+")";
        if ((int)this_player()->query_level() < 20)
          loc = "Unknown";
        else 
          loc = (string)environment(temp[i])->short()+NORM+NORM;
      }
      else
      {
        if ((int)environment(temp[i])->set_light(0) < 0)
          loc = "Dark Room";
        else
          loc = (string)environment(temp[i])->short()+NORM+NORM;
      }
    }

    /* Construct Wizard Info */
    if(temp[i]->is_testchar()) continue; /* verte */
    if (l > 20 && !wiz_flag)
      continue;

    /* Only wizards can see other wizards now - Earwax 10/07/05 */
    if (l > 20)
    {
      t2 = (l >= 99999 ? "God" : l + "");

      info = "       "+HIG+lalign((name+idle),14)
           + HIG + lalign(" "+t2+" ",8)
           + lalign(format_guild(temp[i]), 16)
           + NORM + loc + NORM ; 
      output += ({ format_line(info) });
      wizzes++;
      continue;
    }

    /* Construct Player Info */
    color = 0; /* 0 = nonpk, 1 = pk area, 2 = pk, 3 = pk + pk area */


    if (i > 0 && (int)temp[i - 1]->query_level() > 19)
      output += ({ HIB + "-----------------------------------------------------------------------------\n" + NORM });
    
    if (ob = present(TRACKER_ID,temp[i]))
      points = ralign((int)ob->query_points(),5);
    else
      points = " ----";

    t2 = ( l == 19 ? l+"+"+(int)temp[i]->query_extra_level(): l + "");
    t2 = lalign(t2,6);

    /* Changed this to check this info better - EW 
    if (temp[i]->query_fight_area() && !temp[i]->query_invis()) color +=1;
    */
    if (temp[i] && environment(temp[i]))
      if ((environment(temp[i])->query_property("fight_area")
      || temp[i]->query_fight_area()) && !temp[i]->query_invis())
        color++;
    if ((status)temp[i]->query_pl_k()) color += 2;

    info = colors[color] + points +"  "
         + lalign((name+idle),14) + " " + colors[color]
         + t2 + " "
      + lalign(capitalize(format_guild(temp[i])), 16) 
         + NORM + loc + NORM ;
    output += ({ format_line(info) });
    players++;
  }

  output += ({ HIB + "=============================================================================\n" + NORM });

  if (wiz_flag)
    output += ({ BLU + " "+NORM+"Wizards: "+wizzes+"  Players: "+players+"  Total Visible: "+(players+wizzes)+BLU+"\n"+NORM });
  else
    output += ({ BLU + "Total Visible: "+NORM+players+"\n" });
  output += ({ HIB + "-----------------------------------------------------------------------------\n" + NORM });
  if ((int)this_player()->query_level() <= 19 && players >= Max_This_Reboot)
  {
    Max_This_Reboot = players;
    if (players >= Max_Ever)
    {
      Max_Ever = players;
      Max_Ever_Time = ctime();
      save_object(TWHO_SAVE);
    }
  }
  output += ({ " Max this reboot: "+Max_This_Reboot+"\tMax Since 08/10/06: "+Max_Ever+" at "+Max_Ever_Time+"\n" });

  output += ({ HIB + "=============================================================================\n" + NORM });

  return output;
}

status
main(string arg)
{
  int i, siz;
  string *t;


  siz = sizeof(t = dump_who_list());
  for (i = 0; i < siz; i++)
    write(t[i]);
  return 1;
}

void reset(status arg) {
  if (arg) return;

  Max_Ever = Max_This_Reboot = 0;
  Max_Ever_Time = ctime();
  restore_object(TWHO_SAVE);
}
