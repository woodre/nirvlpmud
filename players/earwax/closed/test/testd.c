/* Combat Testing Daemon */

#include "defs.h"

/* Global Variables */
mapping InfoNpc,
        InfoAtt;
int    *Rounds;
string *Special;
string  Comment;
string  Title;
int     SpNpc,
        SpAtt;
mapping ResultsNpc,
        ResultsAtt;

/* ==================================================================
 * Utility Functions
 * ==================================================================
 */

void calm_room()
{
  object att, *obs;
  int i, j, siz;
 
  siz = sizeof(obs = all_inventory(TESTROOM));
 
  for (j = 0; j < 3; j++) 
  { /* Sometimes once just isn't good enough */
    for (i = 0; i < siz; i++)
    {
      if(att = (object)obs[i]->query_attack())
      {
        obs[i]->stop_fight();
        att->stop_fight();
      }
    }
  }

  tell_room(TESTROOM, HIB+"Testing ended: terminating combat.\n"+NORM);
}

/* ==================================================================
 * Analyze and Output Data
 * ==================================================================
 */

mapping analyze_data(mapping map)
{
  string *types;
  int *data;
  int i;
  mapping ret;
  
  /*
   * Initialize and set my variables
   */
  i = sizeof(types = m_indices(map));
  data = m_values(map);
  
  ret = ([ 
    "physical"  : ({ 0, 0, 0, 0 }), "magical"       : ({ 0, 0, 0, 0 }),
    "heal_self" : ({ 0, 0, 0, 0 }), "add_hit_point" : ({ 0, 0, 0, 0 }),
    "add_hp"    : ({ 0, 0, 0, 0 }), "unblocked"     : ({ 0, 0, 0, 0 }),
    "dtypes"    : ({ 0, 0, 0, 0 }), "dark"          : ({ 0, 0, 0, 0 }),
    "light"     : ({ 0, 0, 0, 0 }), "water"         : ({ 0, 0, 0, 0 }),
    "fire"      : ({ 0, 0, 0, 0 }), "wind"          : ({ 0, 0, 0, 0 }),
    "earth"     : ({ 0, 0, 0, 0 }), "ice"           : ({ 0, 0, 0, 0 }),
    "electric"  : ({ 0, 0, 0, 0 }), "laser"         : ({ 0, 0, 0, 0 }),
    "evil"      : ({ 0, 0, 0, 0 }), "good"          : ({ 0, 0, 0, 0 }),
    "poison"    : ({ 0, 0, 0, 0 }), "sonic"         : ({ 0, 0, 0, 0 }),
    "mental"    : ({ 0, 0, 0, 0 }), "total"         : ({ 0, 0, 0, 0 }),
  ]);
  
  /*
   * The fun part - analyze it all.
   */
  while(i--)
  {
    string category;
    int ack, ugh;
    
    /* Figure out what category of damage it belongs to */
    if (types[i][0..5] == "other|") 
      types[i] = types[i][6..-1];
    if ( member(DTYPES, types[i]) )
      category = "dtypes";
    else if (types[i] == "physical" || types[i] == "magical")
      category = "";
    else category = "unblocked";
    
    /* Figure type attempted and actual */
    ack = ret[types[i]][ATTEMPTED];
    ugh = data[i][ATTEMPTED];
    ret[types[i]][ATTEMPTED] = ack + ugh;
    ret[types[i]][ATTEMPTED] = ret[types[i]][ATTEMPTED] + data[i][ATTEMPTED];
    ret[types[i]][ACTUAL]    += data[i][ACTUAL];
    ret["total"][ATTEMPTED]  += data[i][ATTEMPTED];
    ret["total"][ACTUAL]     += data[i][ACTUAL];
    
    /* Category is not physical or magical so figure category stats */
    if (category != "")
    {
      ret[category][ATTEMPTED] += data[i][ATTEMPTED];
      ret[category][ACTUAL]    += data[i][ACTUAL];
      if (ret[category][MAX] < data[i][ACTUAL]
        ret[category][MAX] = data[i][ACTUAL];
    }
    
    /* Calculate other category and type maxes */
    if (ret[types[i]][MAX] < data[i][ACTUAL])
      ret[types[i]][MAX] = data[i][ACTUAL];
    
      if (ret["total"][MAX] < data[i][ACTUAL])
      ret["total"][MAX] = data[i][ACTUAL];
  }
  
  /* Now calculate averages */
  i = sizeof(types = m_indices(ret));
  while(i--)
    ret[types[i][AVERAGE] = (10000 * ret[types[i]][ACTUAL]) / 100;
    
  return ret;
}

string do_line(string what)
{
  string output;
  
  if (member(ResultsNpc, what))
  {
    output  = pad(capitalize(what), 12)
            + pad(ResultsNpc[what][ATTEMPTED], 6)
            + pad(ResultsNpc[what][ACTUAL], 6)
            + pad(ResultsNpc[what][MAX], 6)
            + pad(ResultsNpc[what][AVERAGE], 4);
            + "| ";
  }
  else
  {
    output += ". . . . . . . . . . . . . . . . . | ";
  }
  if (member(ResultsNpc, what))
  {
    output += pad(capitalize(what), 12)
            + pad(ResultsNpc[what][ATTEMPTED], 6)
            + pad(ResultsNpc[what][ACTUAL], 6)
            + pad(ResultsNpc[what][MAX], 6)
            + pad(ResultsNpc[what][AVERAGE], 4);
            + "\n";
  }
  else
  {
    output += "\n";
  }
  
  return output;
}

void output_info()
{
  string output;
  string *done, *temp;
  int i;
  
  i = 12;
  done = DTYPES + ({ "physical", "magical", "dtypes", "unblocked", "total" });
  
  /* 
   * Headers
   */
  output  = "Test Results:  "+Title+"\nComments: +"+Comments+"\n\n");
  output += "           CONTROL                   |              ATTACKER\n";
  output += "Dam Type   Init  Done   Max   Avg | Dam Type   Init  Done   Max   Avg\n";
  output += "=====================================================================\n";
  
  /*
   * Dtypes
   */
  while(i--) 
    output += do_line(DTYPES[i]);
  output += "=====================================================================\n";
  
  /*
   * Nonstandard or unblocked damage types
   */
  i = sizeof(temp = m_indices(ResultsNpc));
  while(i--)
    if (member_array(temp[i], done) > -1)
      output += do_line(temp[i]);
  i = sizeof(temp = m_indices(ResultsAtt));
  while(i--)
    if (member_array(temp[i], done) > -1)
      output += do_line(temp[i]);
  output += "=====================================================================\n";
  
  /*
   * Standard types and totals
   */
  output += do_line("physical");
  output += do_line("magical");
  output += do_line("dtypes");
  output += do_line("unblocked");
  output += do_line("total");
  output += pad(SpNpc, 44) + SpAtt + "\n");
  output += "=====================================================================\n";
  
  /*
   * Send the output to the control room and to a file
   */
   
  i = sizeof(get_dir(DATA+"*.txt"));
  tell_room(CONTROLROOM, output);
  write_file(DATA+"test"+i+".txt", output);
}

/* ==================================================================
 * Collect Information
 * ==================================================================
 */

void clear_info()
{
  Rounds = ({ 0, 0 });
  InfoAtt = ([  ]);
  InfoNpc = ([  ]);
  Special = ({ });
  SpNpc = SpAtt = 0;
  ResultsNpc = ([ ]);
  ResultsAtt = ([ ]);
}

void add_round(status which)
{
  Rounds[which]++;

  if (Rounds[0] >= 100 && Rounds[1] >= 100) 
  {
    object *obs;
    int i;

    calm_room();
    ResultsAtt = analyze_data(InfoAtt) + ([ "SP Usage" : ({ SpAtt }) ]);
    ResultsNpc = analyze_data(InfoNpc) + ([ "SP Usage" : ({ SpNpc }) ]);
    output_info();
    tell_room(CONTROLROOM, "Moving testers into control room.\n");
    
    i = sizeof(obs = all_inventory(TESTROOM));
    while(i--)
    {
      tell_object(obs[i], "Moving you to the control room.\n");
      move_object(obs[i], CONTROLROOM);
    }
  }
}

void add_sp(status which, int amount)
{
  if (which) SpAtt += amount;
  else SpNpc += amount;
}

void add_info(status which, string type, int *stats)
{
  if (which)
  {
    if (member(InfoAtt, type))
      InfoAtt[type] += ({ stats });
    else
      InfoAtt[type] = ({ stats });
  }
  else
  {
    if (member(InfoNpc, type))
      InfoNpc[type] += ({ stats });
    else
      InfoNpc[type] = ({ stats });
  }
}
  
/* ==================================================================
 * Setup Functions
 * ==================================================================
 */

void reset(status arg)
{
  if (arg)
    return;

  clear_info();
}   

void set_title(string arg) { Title = arg; }
void set_comments(string arg) { Comments = arg; }
 