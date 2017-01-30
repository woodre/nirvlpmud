#ifdef NEW_LEVELS

/****************************************************************************
 global/server/quests.c, (C) by Carador, Mar/Apr-95, Tubmud
                         big changes in August/September-97, Carador.
****************************************************************************/

/*

  !No changes to this file are necessary for adding quests or scenarios!

  To add scenarios, add them in /global/quests/SCENARIOS,
  To add a quest put a file inheritting complex/quest into
    /global/quests. Read /global/quests/HOWTO_QUESTS for details

*/

#pragma strong_types 

#include <is_wizard.h>
#include <kernel.h>
#include <wizlevels.h>
#include <quests.h>
#include <prop/player.h>
#include <event.h>
#include <server.h>

// Where shall our .o-file be put?
#define SAVE_FILE "/save/quests"

// Where are the questfiles found
#define QUEST_DIR "/global/quests/"

static variables inherit ACCESS;

static int quest_points_sum;
static mixed quests;

// A mapping containing statistical information about quest(/scenario)-solvings.
// (It's intended to be saved in the .o-file).
mapping statistics;
mapping sc_statistics;



/////////////////////////////////////////////////////////////////////////
//
// First of all, everything which deals with SCENARIOS
//

static mapping scenarios;

// The player needs to know if s is a scenario and how many quest_points
// shall be granted for it

int query_scenario_qp(string s) 
{
   if ( !s ||                          // No scenario,
        !member(scenarios, s)          // This is no valid scenario!
      ) return 0;

   return scenarios[s];
}


/////////////////////////////////////////////////////////////////////////
//
// Now back to the quests...
//


// Sort the quests

status my_quest_sort(mixed q1, mixed q2) 
{
#if 1
   return q1[Q_SHORT] > q2[Q_SHORT];
#else
   return strlen(q1[Q_SHORT]) > strlen(q2[Q_SHORT]);
#endif
}


// This functions returns the number of questpoints for a given quest

int query_quest_qp(string quest) 
{
   int i, tmp;

   for (i=sizeof(quests); i--; ) if (quests[i][Q_NAME] == quest) break;

   if (i<0 || i >= sizeof(quests)) return 0;
   return quests[i][Q_POINTS];
}


// Handle the quest event

void receive_event(mapping e,string t,int p) 
{
  if (e[E_HANDLED])
    return;
  e[E_HANDLED]=1;

  // could be enhanced to take over logging which is done by call_other
  // to notify_solving() and notify_scenario_solving() yet,
  // Chameloid, 07-Jul-96
}



// RESET, setup all important things


private void add_quest_points_sum(string scen, int qp)
{
  quest_points_sum += qp;
}

private mixed load_quest(string f)
{
  mixed att;
  object q;

  catch(q = load_object(QUEST_DIR + f));
  if (!q) return 0;
  att = q->query_attributes();
  if (!att || !pointerp(att) || !sizeof(att)) return 0;
  quest_points_sum += att[Q_POINTS];
  return att;
}

void reset(int arg) 
{
   string *scen, *line;
   int i, qp;

   if (arg || clonep()) return;

   set_global_listening_event("quest",1);
   listen_event("quest");

   unguarded(1, #'restore_object, SAVE_FILE);

   if (!statistics) statistics = ([]);
   if (!sc_statistics) sc_statistics = ([]);

   quests = sort_array(map(get_dir(QUEST_DIR + "*_quest.c"),
                      #'load_quest) - ({ 0 }), "my_quest_sort");

   scenarios = ([]);

   scen = 
     explode(unguarded(1, #'read_file, QUEST_DIR + "SCENARIO_LIST"), 
       "\n")[0..<2];

   for (i=sizeof(scen); i--;) {
     if (scen[i][0..0] == "#") continue;
     line = explode(scen[i], " ") - ({ "" });
     qp = (int)line[0];
     if (!qp) continue;
     scenarios += ([ line[1] : qp ]);         
   }

   walk_mapping(scenarios, #'add_quest_points_sum);
}


// Return the short-description to a quest with a given name,

string quest_short(string name) {
  int i;

  for (i=0; i<sizeof(quests); i++) {
    if (quests[i][Q_NAME] == name)
      return quests[i][Q_SHORT];
  }
  return 0;  // Coogan, 26-Mar-2011
}


// Return the very short-description, that's the one that must fit
// into a sentence like 'Solve the quest <veryshort>'

string query_very_short(string name) {
  int i;

  for (i=0; i<sizeof(quests); i++) {
    if (quests[i][Q_NAME] == name)
      return quests[i][Q_VERY_SHORT];
  }
  return 0;  // Coogan, 26-Mar-2011
}


// Returns the total of all questpoints

int query_quest_points_sum() {
  return quest_points_sum;
}


// Return an array of names of all quests.

string *query_names() { 
  return map(quests, #'[, Q_NAME);
}


// Return the complete quest-array containing all information.

mixed *query_quests() {
  return quests [0..];
}

mapping query_scenarios() {
  return copy(scenarios);
}


// Return a string of selected quests.
varargs string do_list() {
  string result, tmp, del, indent, *rest;
  int i, count, level;

  level = this_player()->query_level();

  del = "\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

  indent = "       ";

  result = sprintf(indent + "(%:-61s)\n", del) +
     sprintf(indent + ") %:|59s (\n", 
          "Tubmud's quests") + 
      sprintf(indent + "(%:-61s)\n", "");

  result += sprintf(indent + ") %:-59s (\n", del);
      
  for (i=0; i<sizeof(quests); i++) {
    result += sprintf(indent + "%s  %:-57s  %s\n",
                      (count % 2 ? ")" : "("),
                      quests[i][Q_SHORT],
                      (count % 2 ? "(" : ")")
                     );
    count++;
  }

  result += sprintf(indent + "%s %:|59s %s\n",
                    (count % 2 ? ")" : "("), "", (count % 2 ? "(" : ")"));

  result += sprintf(indent + " %:-61s\n", del);
  return "\n" + result;
}


// The statistic-part
void notify_scenario_solving(string qname, object pl, status again) {
   int lvl;
   string qstr;

   if ( !qname ||
        !pl ||
        !interactive(pl) ||
        pl != previous_object() ||
        is_wizard(pl) ||
        is_wizard(pl, IW_TESTPLAYER) 
      ) return;

   lvl = pl->query_level();
   qstr = pl->query_scenarios();

   if (!member(sc_statistics,qname))
      sc_statistics += ([ qname : ({ 0, 0, 0, 0 }) ]);

   if (again) {
     sc_statistics[qname][3] ++;
   }
   else {
     sc_statistics[qname][0] ++;
     sc_statistics[qname][1] += lvl;
     sc_statistics[qname][2] += (!qstr || qstr=="" ? 
           1 : (sizeof(explode(qstr, "#"))+1));
   }
   unguarded(1, #'save_object, SAVE_FILE);
}

void notify_solving(string qname, object pl, status again) {
   int lvl;
   string qstr;

   if ( !qname ||
        !pl ||
        !interactive(pl) ||
        pl != previous_object() ||
        is_wizard(pl) ||
        is_wizard(pl, IW_TESTPLAYER) 
      ) return;

   lvl = pl->query_level();
   qstr = pl->query_quests();

   if (!member(statistics,qname))
      statistics += ([ qname : ({ 0, 0, 0, 0 }) ]);

   if (again) {
     statistics[qname][3] ++;
   }
   else {
     statistics[qname][0] ++;
     statistics[qname][1] += lvl;
     statistics[qname][2] += (!qstr || qstr == "" ? 
          1 : (sizeof(explode(qstr, "#"))+1));
   }
   unguarded(1, #'save_object, SAVE_FILE);
}

private mixed make_average(mixed arg) {
   return ({ arg[0] + arg[3],             // overall no. of solutions
             arg[0],                      // no. of first solutions
             arg[3],                      // no. of second solutions
             (arg[0] && arg[1]/arg[0]),   // mean level
             (arg[0] && arg[2]/arg[0])    // how many quest solutions
          });                             // (in german: die wievielte quest)
}


varargs mixed print_statistics(int how_sorted) 
{
   int i;
   mixed *sorted;
   string result;

   if (!sizeof(statistics)) return "No statistics yet.\n";

   if (how_sorted < 0 || how_sorted > 4) return 0;

   sorted = sort_array(
      transpose_array(
         ({ m_indices(statistics),
            map(m_values(statistics), #'make_average)
         })
      ),
      lambda(
         ({ 'x, 'y }), 
         ({ #'<, 
            ({ #'[, ({ #'[, 'x, 1 }), how_sorted }), 
            ({ #'[, ({ #'[, 'y, 1 }), how_sorted })
         })
      )
   );

   result = "";

   for (i=0; i<sizeof(sorted); i++)
      result += 
       sprintf("%:-20s |     %4d      %4d      %4d      %4d      %4d\n",
         capitalize(sorted[i][0]) + " [" + query_quest_qp(sorted[i][0]) + "]",
         sorted[i][1][0],
         sorted[i][1][1],
         sorted[i][1][2],
         sorted[i][1][3],
         sorted[i][1][4]);

   return "\n\
QUEST                | SOLVINGS     FIRST     AGAIN     LEVEL     ORDER\n\
---------------------+-------------------------------------------------\n"+ 
      result + "\
-----------------------------------------------------------------------\n";
}

varargs mixed print_sc_statistics(int how_sorted) 
{
   int i;
   mixed *sorted;
   string result;

   if (!sizeof(sc_statistics)) return "No statistics yet.\n";

   if (how_sorted < 0 || how_sorted > 4) return 0;

   sorted = sort_array(
      transpose_array(
         ({ m_indices(sc_statistics),
            map(m_values(sc_statistics), #'make_average)
         })
      ),
      lambda(
         ({ 'x, 'y }),
         ({ #'<,
            ({ #'[, ({ #'[, 'x, 1 }), how_sorted }),
            ({ #'[, ({ #'[, 'y, 1 }), how_sorted })
         })
      )
   );

   result = "";

   for (i=0; i<sizeof(sorted); i++)
      result +=
       sprintf("%:-20s |     %4d      %4d      %4d      %4d      %4d\n",
         capitalize(sorted[i][0]) + " [" + query_scenario_qp(sorted[i][0]) +
                "]",
         sorted[i][1][0],
         sorted[i][1][1],
         sorted[i][1][2],
         sorted[i][1][3],
         sorted[i][1][4]);

   return "\n\
SCENARIO             | SOLVINGS     FIRST     AGAIN     LEVEL     ORDER\n\
---------------------+-------------------------------------------------\n"+
      result + "\
-----------------------------------------------------------------------\n";
}


// The information-section

status server_info(string str) {
   mapping groups;
   mixed a, b;
   int i, j, sum;
   string result, vb, tmp;
   if (str) str = lower_case(str);

   result = "\
----------------------------------------------------------------------------\n"+
   sprintf("%:|78s\n", "quest-server-info-facility  ---  " +
      this_player()->query_commandline()) + "\
----------------------------------------------------------------------------\n\
\n";

   switch(str) {

      case 0 :
         sum = 0;
         result += "\
Quests        : " +sizeof(quests) + "\n";
         groups = ([]);
         for (i=0; i<sizeof(quests); i++) {
            sum += quests[i][Q_POINTS];
            if (!groups[quests[i][Q_POINTS]])
               groups[quests[i][Q_POINTS]] = ({ quests[i][Q_NAME] });
            else
               groups[quests[i][Q_POINTS]] += ({ quests[i][Q_NAME] });
         }

         a = m_indices(groups);
         b = m_values(groups);
         a = sort_array(transpose_array(({ a, b })), lambda(({ 'x, 'y }),
            ({ #'>, ({ #'[, 'x, 0 }), ({ #'[, 'y, 0 }) })));

         for (i=0; i<sizeof(a); i++)
            result += sprintf("  %2d of %3d qp: ", 
               sizeof(a[i][1]), a[i][0]) + 
               break_string(make_list(a[i][1]), 78, 16, 1) +"\n";

         result += "\
Scenarios     : " + sizeof(scenarios) + "\n";

         groups = ([]);
         a = m_indices(scenarios);

         for (i=0; i<sizeof(a); i++) {
            sum += scenarios[a[i]];
            if (!groups[scenarios[a[i]]]) 
               groups[scenarios[a[i]]] = ({ a[i] });
            else
               groups[scenarios[a[i]]] += ({ a[i] });
         }

         a = m_indices(groups);
         b = m_values(groups);
         a = sort_array(transpose_array(({ a, b })), lambda(({ 'x, 'y }),
            ({ #'>, ({ #'[, 'x, 0 }), ({ #'[, 'y, 0 }) })));

         for (i=0; i<sizeof(a); i++)
            result += sprintf("  %2d of %3d qp: ",
               sizeof(a[i][1]), a[i][0]) +
               break_string(make_list(a[i][1]), 78, 16, 1) +"\n";

         result += "\
Questpoints   : " + sum + "qp\n";
         result += "\
Avgavglevel   : ";
         sum = 0;
         for (i=0; i<sizeof(quests); i++)
            sum += ( (quests[i][Q_LOW_LEVEL] || 1) +
                     (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL)
                   ) / 2;
         result += (sum / i) + "\n\
                (That's the avg-level of all quest's avg-levels :). If it's\n\
                 too low, there are too many utti-quests, if it's too high,\n\
                 there are too many hlp-quests.)\n";
         break;

      case "stat" :
      case "stat solvings" :
         result += print_statistics(0);
         break;
 
      case "stat first" :
         result += print_statistics(1);
         break;

      case "stat again" :
         result += print_statistics(2);
         break;

      case "stat level" :
      case "stat lvl" :
         result += print_statistics(3);
         break;

      case "stat order" :
         result += print_statistics(4);
         break;

      case "stat sc" :
         result += print_sc_statistics(0);
         break;

      case "stat sc first" :
         result += print_sc_statistics(1);
         break;

      case "stat sc again" :
         result += print_sc_statistics(2);
         break;

      case "stat sc level" :
      case "stat sc lvl" :
         result += print_sc_statistics(3);
         break;

      case "stat sc order" :
         result += print_sc_statistics(4);
         break;

      default :
         vb = query_verb();
         result += 
   vb + "            : Common information about quests and scenarios\n"+
   vb + " stat       : Statistics about quest-solvings, (sorted: how often)\n"+ 
   vb + " stat first : As above, but only first-time solvings\n"+ 
   vb + " stat again : As above, but only again-solvings\n"+ 
   vb + " stat lvl   : As above, but sorted by average level of solver\n" +
   vb + " stat order : As above, but sorted by the order of the solvings,\n\
  that means, if a quest has a 3 in that column, this quest is the third\n\
  quest, the player solved (utti-quests have low, hlp-quests high numbers)\n\n"+
   vb + " stat sc ...: Same for scenarios, i.e. 'stat sc', 'stat sc lvl',\n\
  'stat sc first', 'stat sc order'.\n" +
   vb + " help       : This information\n" +

   "";
         break;
   }
   this_player()->view_text(result, str);
   this_player()->start_view();
   return 1;
}



/*********** end of global/server/quests.c for NEW_LEVELS *****************/




#else




/****************************************************************************
 global/server/quests.c, written by Carador, Mar/Apr-95, Tubmud
****************************************************************************/

#pragma strong_types 

#include <kernel.h>
#include <grammar.h>
#include <wizlevels.h>
#include <quests.h> // Arkon, 21-Apr-1995
#include <prop/player.h>
#include <event.h> // Chameloid, 07-Jul-96

//////////////////////////////////////////////////////////////////////////////
//             U S E R - D E F I N E D   S E C T I O N                      //
//                                                                          //
// Add quests and scenarios here, or alter the qp-limits for advancing      //
// beyond certain levels.                                                   //
//                                                                          //

#ifdef TUBMUD

// You have to add Tubmud's scenarios here.

#define SCENARIOS ([ \
      "hooligans"       :  5, \
      "pieks"           :  5, \
      "rabbit_and_frog" :  5, \
      "sheep"           :  5, \
      "werewolf"        :  5, \
      "boomerang"       :  5, \
      "orc_slayer"      :  5, \
      "morath"          :  5, \
      "candu"           :  5, \
      "farm"            :  5, \
      "deadzone"        :  5, \
      "schnitzel_chase" :  5, \
      "drag_scen_01"    :  5, \
      "drag_scen_02"    :  5, \
      "monster_ring"    :  5, \
      "sick_tree"       :  5, \
      "mill"            :  5, \
      "w_crown"         :  5, \
      "w_ghost"         :  5, \
      "w_table"         :  5, \
      "natives"         :  5, \
      "shopkeeper"      :  5, \
      "dddms"           :  5, \
      "gnomish_mine"    :  5, \
      "diadem_and_doll" : 10, \
      "deathbat"        : 10, \
      "solution"        : 10, \
      "kantele"         : 10, \
      "windrose"        : 10, \
      "bael"            : 10, \
      "pirates_cave"    : 10  \
   ])

#else

#define SCENARIOS ([ \
      "orc_slayer"      :  5, \
   ])

#endif





// Change here when you want to change the qp-limits for the levels!!!

// This is the amount of QP necessary for wizzing
// Change it here when it changes. :)

#ifdef TUBMUD

#define QP_FOR_WIZZING 800

#else

#define QP_FOR_WIZZING 5

#endif


// These are the qp's necessary to advance beyond the given levels,
// this was formely the information extracted from /global/quests/limits
// which is obsolete now. Change here if the values change.

#ifdef TUBMUD

#define QP_LIMITS ([ \
      5 :  60, \
     10 : 240, \
     15 : 480, \
     19 : QP_FOR_WIZZING \
   ])

#else

#define QP_LIMITS ([ \
     19 : QP_FOR_WIZZING \
   ])

#endif



// Add Tubmud's quests here, read /global/quests/HOWTO_QUESTS as a
// guideline for doing so. If you have questions please contact the admin.
// Note that there has to be a file called qname.quest for every quest in the 
// QUEST_DIR-directory containing nothing but the text to be displayed in the 
// guild.


#ifdef TUBMUD

// Carador, 18-Aug-97, added creators to every quest

static mixed quests = ({
//  Q_POINTS LVL_LOW LVL_HIGH  TIME PART_TIME  PLAYERS BEGINNER

   ({ "imbalance", "Are you brave enough to...", "Carador",
       20,      0,      4,      2,      0,      0,      1 }),

   ({ "momu_baby", "What is going on in those bushes???", "Domain Momu",
       20,      5,      11,     1,      0,      0,      0 }),

   ({ "moon", "Help the President of the sleepwalkers.", "Ernest and Joe",
       20,      0,      6,      2,      0,      0,      1 }),

   ({ "prince-violens", "Har-Salan has a quest for you.", "Ereborn",
       20,      2,      7,      2,      0,      0,      0 }),

   ({ "sand-castle", "Build your own castle.",
      "Lila, maintained by Domain Deathbat",
       20,      0,      7,      2,      0,      0,      0 }),

//  Q_POINTS LVL_LOW LVL_HIGH  TIME PART_TIME  PLAYERS BEGINNER

   ({ "babydream", "Babydream is in danger!", "Some",
       30,      0,      7,      3,      1,      0,      1 }),

   ({ "concert", "Herbert needs your help!",  "Ernest and Joe",
       30,      2,      9,      2,      1,      0,      0 }),

   ({ "excalibur", "Free the magic sword Excalibur from its prison.", "Yaro",
       30,      2,      8,      3,      1,      0,      0 }),

   ({ "padrone", "Find Padrone's walking castle and return it to him.",
      "Padrone, maintained by Glimrol",
       30,      7,      13,     3,      0,      0,      0 }),

   ({ "rainforest", "Solve the problems of the rainforest.",
      "Iolo",
       30,      5,      12,     3,      1,      0,      0 }),

   ({ "zweiblum", "Get an iconograph and make seven pictures.",
      "Zweiblum, maintained by Domain Avalon",
       30,      4,      11,     2,      1,      0,      0 }),
   ({ "wayhome", "Rescue Dareius and find your way home!", "Fafnir",
       30,      3,      10,     2,      0,     -1,      0 }),

//  Q_POINTS LVL_LOW LVL_HIGH  TIME PART_TIME  PLAYERS BEGINNER

   ({ "ardanna", "The Realm of Witches is in danger.",
      "Ardanna, maintained by domain Deathbat",
       40,      7,      14,     3,      0,      0,      0 }),

   ({ "argonath", "Help the poor inhabitants of Argonath.", "Fangorn",
       40,      5,      13,     3,      0,      0,      0 }),

   ({ "arillinn", "Revive some glorious knights of a long forgotten age.",
      "Ethakar",
       40,      11,     18,     3,      0,      0,      0 }),

   ({ "robin_hood", "Help Robin Hood to free the Lady Morgaine.",
      "Yaro",
       40,      5,      11,     3,      1,      0,      0 }),

   ({ "teddyland", "Discover the magical Teddyland!",
      "Leonardo",
       40,      13,     18,     3,      0,      0,      0 }),

   ({ "yendor", "Retrieve the Amulet of Yendor!",
      "Murks, maintained by Domain Avalon",
       40,      9,      14,     3,      0,      0,      0 }),

//  Q_POINTS LVL_LOW LVL_HIGH  TIME PART_TIME  PLAYERS BEGINNER

   ({ "angmar", "Break into Angmar's treasury!", "Angmar",
       50,      14,     0,      3,      0,      0,      0 }),

   ({ "rabba", "Free the golden country!", "Some",
       50,      11,     16,     3,      0,      0,      0 }),

   ({ "stonehenge", "Find the seven magic swords of Wayland.",  "Yaro",
       50,      4,      11,     4,      0,      0,      0 }),

   ({ "wales", "Restore the crown of the Welsh dragon.",  "Mllynwrlch",
       50,      8,      16,     4,      0,      2,      0 }),

//  Q_POINTS LVL_LOW LVL_HIGH  TIME PART_TIME  PLAYERS BEGINNER

   ({ "chaosdemon", "The secret police has a mission to fulfill for you.",
      "Padrone, maintained by Glimrol",
       60,      14,     0,      4,      0,      0,      0 }),

   ({ "momu", "Go to another world??? Why not? It might be possible!", 
      "Domain Momu",
       60,      6,      0,      5,      1,      -1,     0 }),

   ({ "momu++", "Return to another world!",
      "Domain Momu",
       60,      6,      0,      5,      1,      -1,     0 }),

   ({ "darkblade", "Stop the Return of Zydonia!",
      "Domain Deathbat",
       70,      16,     0,      5,      2,      0,      0 }),

   ({ "dragoncrown", "The crown of the dragons, a famous legend.", "Carador",
       70,      10,     18,     5,      0,      2,      0 }),

   ({ "dragonland_2", "Find the lost expedition!", "Domain Dragonland",
       70,      17,     0,      4,      0,      0,      0 }),

   ({ "chrisp", "Slay the evil necromancer kobayashi!", 
      "Chrisp, maintained by Coogan",
       80,      15,     0,      4,      0,      -1,     0 }),

   ({ "dol_guldur", "Stop the Breeding!", "Sauron",
       80,      16,     0,      4,      0,      0,      0 }),

   ({ "cauliflower", "Be kind to an Old Lady!", "Alethia",
       90,     11,    16,      5,      2,      0,      0 }),

   ({ "havoc", "The Lands of Havoc!", "Wizward",
       120,     16,     0,      5,      3,      0,      0 })
});


#else

static mixed quests = ({ });

#endif



// This is the amount of questexperience which is given when somebody
// reached the amount of QP necessary for becoming a wizard
// (As there are many possibilities of scoring 800qp this value is just
// a rough boundary).

#define QUEST_XP        750000



// This is the level when a player no longer receives hints about the
// possible usages of the quest list command.

#define NO_MORE_HINTS_WITH_LEVEL 6



// with this function the quests are sorted, possible values are:
// "alphasort"      : alphabetically by short
// "avg_levelsort"  : sorted by (low_level + high_level) / 2
// "levelsort"      : sorted by low_level, if equal by high_level
//

// PLEASE don't change this!!!

#define SORT_FUN "alphasort"



// Where shall our .o-file be put?

#define SAVE_FILE "/save/quests"



// Where are the descriptions of the quests to be found?

#define QUEST_DIR "/global/quests/"



static variables inherit ACCESS;
static variables inherit "/basic/list";



// These are for the time-groups:

#define TIME_KEY  "XL = 0h-1h, L = 1h-2h, M = 2h-3h, H = 3h-6h, XH = 6h-"

static string *ti_groups=({ "extralow","low", "medium", "high", "extrahigh" });
static string *ti_groups_short = ({ "XL", "L", "M", "H", "XH" });


//                                                                          //
//          E N D   O F   U S E R - D E F I N E D   S E C T I O N           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////



// The limits for advancing beyond certain levels.

static mapping qp_at_level;


// A very internal factor which shouldn't bother you.
// (It's intended to be saved in the .o-file).

int tune_factor;


// Some information-variables to show how many questexperience is given.

static string odd_table, even_table;
static int *qexp;


// A mapping containing statistical information about quest(/scenario)-solvings.
// (It's intended to be saved in the .o-file).

mapping statistics;
mapping sc_statistics;



/////////////////////////////////////////////////////////////////////////
//
// First of all, everything which deals with SCENARIOS
//

static mapping scenarios;

// The player needs to know if s is a scenario and how many quest_points
// shall be granted for it

int query_scenario_qp(string s) {
   if ( !s ||                          // No scenario,
        !member(scenarios, s)          // This is no valid scenario!
      ) return 0;

   return scenarios[s];
}


int query_scenario_exp(string s, int level) {
   int i, reward, max_rw;

   if ( !level ||
        !member(scenarios, s)
      ) return -1;

   max_rw = "/room/adv_guild"->get_next_exp(level-1);

   if (level > 19) level = 19;

   reward = (int)(level * tune_factor * scenarios[s]);
   if (reward > max_rw) return max_rw;
   return reward;
}



/////////////////////////////////////////////////////////////////////////
//
// Now back to the quests...
//


// Several ways of sorting the quests, we only use alphasort, the others
// only were during testing-phase.

status alphasort(mixed q1, mixed q2) {
   return q1[Q_SHORT] > q2[Q_SHORT];
}

status avg_levelsort(mixed q1, mixed q2) {
   float avg1, avg2;

   avg1 = (float)((float)((q1[Q_LOW_LEVEL] || 1) + (q1[Q_HIGH_LEVEL] || 19)) / 
          (float)2);
   avg2 = (float)((float)((q2[Q_LOW_LEVEL] || 1) + (q2[Q_HIGH_LEVEL] || 19)) / 
          (float)2);

   if (avg1 > avg2) return 1;
   if (avg1 == avg2) return q1[Q_SHORT] > q2[Q_SHORT];
   return 0;
}

status levelsort(mixed q1, mixed q2) {
   if ((q1[Q_LOW_LEVEL] || 1) > (q2[Q_LOW_LEVEL] || 1)) return 1;
   if ((q1[Q_LOW_LEVEL] || 1) == (q2[Q_LOW_LEVEL] || 1)) {
      if ((q1[Q_HIGH_LEVEL] || 19) > (q2[Q_HIGH_LEVEL] || 19)) return 1;
      if ((q1[Q_HIGH_LEVEL] || 19) == (q2[Q_HIGH_LEVEL] || 19)) {
         if (q1[Q_SHORT] > q2[Q_SHORT]) return 1;
      }
   }
   return 0;
}


// This function calculates how many quest-points a player of
// level 'level' receives when he solves quest 'qname'.
// If no level is specified the unmodified amount of questpoints
// of quest 'qname' is returned.


varargs int query_quest_qp(mixed quest, int level) {
   int i, tmp;

   if (!intp(quest)) {
      for (i=sizeof(quests) - 1; i>-1; i--) {
         if (quests[i][Q_NAME] == quest) break;
      }
   }
   else i = (int)quest;

   if (i<0 || i >= sizeof(quests)) return 0;

   if (!level || level >= WL_APPRENTICE) return quests[i][Q_POINTS];

   if (level > PL_MAX_PLAYER_LEVEL) level = PL_MAX_PLAYER_LEVEL;

   // He we will change the qp depending on the level!

   // Level is higher than suggested.

   if (level > (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL)) {
      tmp = - 10 * (level - (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL));
      if (tmp < -80) tmp = -80;
   }

#if 0

   // We decided, NOT to do that. At first... :)

   else if (level < (quests[i][Q_LOW_LEVEL] || 1)) {
      tmp = 2 * ((quests[i][Q_LOW_LEVEL] || 1) - level);
      if (tmp > 10) tmp = 10;
   }
#endif

   return (quests[i][Q_POINTS] * (100 + tmp)) / 100;
}


// This function calculates how many quest-experience a player of
// level 'level' will receive when he solves quest 'qname'.
// It is called by /obj/player/quest.

varargs int query_exp_reward(mixed quest, int level, int player_level) {
   int i, reward, max_rw, tmp;

   if (!level) return 0;

   if (!intp(quest)) {
      for (i=sizeof(quests) - 1; i>-1; i--) {
         if (quests[i][Q_NAME] == quest) break;
      }
   }
   else i = (int)quest;

   if (i<0 || i >= sizeof(quests)) return -1;


// Level == -1 means average level of suggested level-range for that quest.
   if (level == -1)
      level = ( (quests[i][Q_LOW_LEVEL] || 1) + 
                (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL) ) / 2;


   if (player_level && player_level < level) level = player_level;

   max_rw = "/room/adv_guild"->get_next_exp(level-1);
 
   tmp = level;
   if (tmp > (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL))
      tmp = (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL);

   reward = (int)(tmp * tune_factor * query_quest_qp(i, level));
   if (reward > max_rw) return max_rw;
   return reward;
}

// handling the quest event, Chameloid, 07-Jul-96     

void receive_event(mapping e,string t,int p) {
  if (e[E_HANDLED])
    return;
  e[E_HANDLED]=1;

  // could be enhanced to take over logging which is done by call_other
  // to notify_solving() and notify_scenario_solving() yet,
  // Chameloid, 07-Jul-96
}

// RESET, setup all important things


void reset(int arg) {
   float correction;
   int i, factor_sum, qp_sum;

   if (arg || clonep()) return;

   set_global_listening_event("quest",1); // Chameloid, 07-Jul-96
   listen_event("quest"); // Chameloid, 07-Jul-96

   unguarded(1, #'restore_object, SAVE_FILE);

   if (!statistics) statistics = ([]);
   if (!sc_statistics) sc_statistics = ([]);

   quests = sort_array(quests,SORT_FUN);

   scenarios = SCENARIOS;
   qp_at_level = QP_LIMITS;

   if (!tune_factor) tune_factor = 1;

   for (i=0; i<sizeof(quests); i++) {

// Some nasty checks for weird quest-entries.
      while(sizeof(quests[i]) < ATTRIBUTES) quests[i] += ({ 0 });
      if (quests[i][Q_LOW_LEVEL] == 1) quests[i][Q_LOW_LEVEL] = 0;
      if (quests[i][Q_HIGH_LEVEL] == PL_MAX_PLAYER_LEVEL) 
          quests[i][Q_HIGH_LEVEL] = 0;
      if (quests[i][Q_PLAYERS] == 1) quests[i][Q_PLAYERS] = 1;


// Some calculation to actualize the tune_factor. The tune_factor's
// job is to make sure that for somebody who solves the quests 
// necessary for wizzing receives about 750000 Questexperience.
// So we calculate the amount of qexp which is given when somebody solves
// all quests, regard QP_FOR_WIZZING and the overall questpoint-sum and ...

      qp_sum += quests[i][Q_POINTS];
      factor_sum += query_exp_reward(i, -1);
   }


// ... are able to calculate a correction-factor which the tune_factor has
// to be multiplied with.

   if (!factor_sum) factor_sum = 1;

   correction = (float)
      ((float)(QUEST_XP * qp_sum) / (float)(factor_sum * QP_FOR_WIZZING));
   tune_factor = (int) ((float)tune_factor * (float)correction);


// Set up some information about the questserver. We want to see how
// many Questexperience is given in certain situations.

   call_out("setup_information", 0);


// Save the corrected tune_factor

   unguarded(1, #'save_object, SAVE_FILE);
}


// Print some manpages...

string print_show_manpage() {
   return "\n\
QUEST SHOW:\n\
-----------\n\
Command    : quest show <number>|<text>\n\
Description: Displays more information about quests\n\
Arguments  :\n\
  <number>\n\
     Information about quest <number> as in the quest-list is printed.\n\
  <text>\n\
     If the name of a quest contains <text>, detailed information\n\
     about that quest is printed.\n\
Examples   :\n\
  quest show 3\n\
  quest show walking castle\n";
}


string print_list_manpage() {
   return "\n\
QUEST LIST:\n\
-----------\n\
Command    : quest list [arg1 [arg2 [arg3 ... ]]]\n\
Description: Displays a list of selected quests\n\
Arguments  :\n\
 You may specify as many of these arguments as you want in any order.:\n\
  verbose\n\
     a more informative listing of the quests is printed, that means,\n\
     recommended level-ranges, estimated time duration and questspoints\n\
     are included in the list.\n\
  level <level>\n\
  level <low> to <high>\n\
     only quests suitable for level <level> or levels <low> to <high> are\n\
     printed. You may also use 'mine' as <level>, that is your current level.\n\
  time <time>\n\
  time <low> to <high>\n\
     <time> has to be " + make_list(ti_groups_short,0, " or ") + ",\n\
     quests belonging to the given time-group are printed, time groups are\n\
     " + TIME_KEY + "\n\
  players <amount>\n\
     displays all quests playable for <amount> players simultaneously\n\
  dividable\n\
     lists quests which are divided in parts and can be played during\n\
     several sessions\n\
  beginner\n\
     only lists quests which are especially desinged for beginners\n\
  all\n\
     list the unsolved and solved quests\n\
  solved\n\
     only list the solved quests\n\
Examples  :\n\
  quest list all\n\
  quest list level 3 time low\n\
  quest list all level 3 to 13 time medium to high players 1\n\
Notes     :\n\
  - The quests are listed in alphabetical order, level specifications are\n\
    nothing but recommendations, you haven't stick to them.\n\
  - Something like 'M/L' in the time-column means that the overall time \n\
    needed to solve the quest is 'M'. But the quest is divided in parts which\n\
    can be played with time 'L'.\n" +
    "\
  - The column 'QP' contains the amount of questpoints you receive when\n\
    solving the quest at your current level. This value can change whenever\n\
    your level changes.\n" +
    "\
  - An entry 'S' in the 'S'-column means that you already solved that quest.\n";
}



int make_integer(mixed arg) {
   int result;

   if (!arg) return 0;
   result = to_int(arg);
   if (result) return result;
   return "/lib/parse"->parse_numeral((string)arg);
}


int make_time(string arg) {
   int index;

   if ((index = member(ti_groups, arg)) > -1) return index + 1;
   return (member(map(ti_groups_short, #'lower_case), arg)) + 1;
}


// Return the short-description to a quest with a given name,

string quest_short(string name) {
   int i;

   for (i=0; i<sizeof(quests); i++)
      if (quests[i][Q_NAME] == name) return quests[i][Q_SHORT];
}


// Return an array of names of all quests.

string *query_names() { 
   return map(quests, #'[, Q_NAME);
}


// Return the complete quest-array containing all information.
// Arkon, 21-Apr-1995

mixed *query_quests () {
  return quests [0..];
}


// 'Calculate' (nowadays it's more query than calculate) the amount of 
// questpoints the specified player has.

varargs int count(object player) {
    string *pl_quests;
    int sum, i;

    if ( !player &&
         !(player = this_player())
       ) return 0;

    return player->query_quest_points();
}


// Calculate the next level stage for which player has to solve a
// certain amount of quests.

varargs int next_stage(object player) {
    int level;

    if ( !player &&
         !(player = this_player())
       ) return 0;

    level = (int)player->query_level();
    while (level<WL_APPRENTICE && !qp_at_level[level])
        level++;
    return level;
}


// Return the amount of questpoints still necessary for player to advance
// beyond the next level-stage.

varargs int needed(object player) {
    int sum,level;

    if ( !player &&
         !(player = this_player())
       ) return 0;

    level = next_stage(player);

    if (level>=WL_APPRENTICE) return 0;

    sum = qp_at_level[level] - count(player);

    if (sum<0) sum = 0;

    return sum;
}


// Return a string telling the player whether he still has to solve quests
// or not

varargs string requirements(object player, status unbroken) {
    string result;
    int i, need;
    int next;
    int percent;

    if ( !player &&
         !(player = this_player())
       ) return 0;

    next = next_stage(player);

    if (next >= WL_APPRENTICE) return "";

    percent = count(player) * 100 / qp_at_level[next];

    if (percent >= 100) return "";

// Looks nasty, but isn't. :)
    percent /= 10;
    percent *= 10;

    result = "You solved about "+ 
       "/lib/language"->word_number(percent) + 
       " per cent of the quests" +
       " necessary for advancing beyond level " +
       "/lib/language"->word_number(next_stage(player)) + ".";

    if (unbroken) return result;

    return break_string(result + "\n", 78, 2, 1);
}



// Return a string of selected quests.

varargs string do_list(int *indices, status verbose, string header) {
   string result, tmp, del, indent, *rest;
   int i, count, length, level;

   level = this_player()->query_level();

   del = "\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

   if (!indices) {
      indices = ({});
      for (i=0; i<sizeof(quests); i++) indices += ({ i });
   }

   if (!verbose) {
      length = 61;
      indent = "       ";
   }
   else {
      length = 76;
      indent = "";
   }

   result = sprintf(indent + "(%:-" + length + "s)\n", del) +
      sprintf(indent + ") %:|" + (length - 2) + "s (\n", 
         (header ? header : "Tubmud's quests")) + 
      sprintf(indent + "(%:-" + length + "s)\n", "");

   if (verbose) result += "\
) Nr              Name of the quest                        Level  Time  QP S (\n\
(                                                                            )\n";

   result += sprintf(indent + ") %:-" + (length - 2) + "s (\n", del);

      
   for (i=0; i<sizeof(quests); i++) {
      if (member(indices, i) > -1) {
         if (!verbose)
            result += 
                 sprintf (indent + "%s  %2d  %:-" + (length - 8) + "s  %s\n",
                    (count % 2 ? ")" : "("),
                    (i+1), 
                    quests[i][Q_SHORT],
                    (count % 2 ? "(" : ")")
                 );
            else result += 
                sprintf("%s %2d %:-" + (length - 23) + 
                   "s %2s-%2s %:2s%:-3s %3d %1s %s\n",
                   (count % 2 ? ")" : "("),
                   (i+1),
                   quests[i][Q_SHORT],
                   (string)(quests[i][Q_LOW_LEVEL] ? 
                       quests[i][Q_LOW_LEVEL] : ""),
                   (string)(quests[i][Q_HIGH_LEVEL] ? 
                      quests[i][Q_HIGH_LEVEL] : ""),
                   (quests[i][Q_TIME] ? 
                      ti_groups_short[quests[i][Q_TIME]-1] : ""),
                   (quests[i][Q_DIVIDABLE] ? 
                      "/" + ti_groups_short[quests[i][Q_DIVIDABLE]-1] : ""),
                   query_quest_qp(i, level),
                   (this_player()->query_quests(quests[i][Q_NAME]) ? "S" : ""), 
                   (count % 2 ? "(" : ")")
                );
            count++;
         }
      }

      rest = ({ "" });

      if (verbose) rest += 
         ({ del,
            "Key: Time  : " + TIME_KEY,
            "" 
         });

      if ((tmp = requirements(this_player(), 1)) != "") {
          rest += ({ del });
          if (strlen(tmp) >= (length - 2)) {
             rest += (explode(break_string(tmp, (length - 10)), "\n"));
          }
          else rest += ({ tmp });
          rest += ({ "" });
      }

      for (i=0; i<sizeof(rest); i++) {
         result += sprintf(indent + "%s %:|" + (length - 2) + "s %s\n",
            (count % 2 ? ")" : "("),
            rest[i],
            (count % 2 ? "(" : ")")
         );
         count++;
      }

      result += sprintf(indent + " %:-" + length + "s\n", del);

      return "\n" + result;
}




string do_show(int tmp) {
   string file;
   string result;

   result = "level: ";
   if (!quests[tmp][Q_LOW_LEVEL] && !quests[tmp][Q_HIGH_LEVEL])
      result += "any";
   else {
      result += (quests[tmp][Q_LOW_LEVEL] || 1);
      result += "-";
      if (quests[tmp][Q_HIGH_LEVEL]) result += quests[tmp][Q_HIGH_LEVEL];
   }
   result += ", time: ";
   if (!quests[tmp][Q_TIME]) result += "unknown";
   else result += ti_groups[quests[tmp][Q_TIME]-1];

   if (quests[tmp][Q_DIVIDABLE]) 
      result += " (parts " + ti_groups[quests[tmp][Q_DIVIDABLE]-1] + ")";

   if (quests[tmp][Q_PLAYERS]) {
      result += ", players: ";
      if (intp(quests[tmp][Q_PLAYERS])) {
         if (quests[tmp][Q_PLAYERS] == -1) result += "any";
         else result += quests[tmp][Q_PLAYERS];
      }
      else result += quests[tmp][Q_PLAYERS][0] + "-" + 
         quests[tmp][Q_PLAYERS][1];
   }

   if (quests[tmp][Q_BEGINNER]) result += ", beginner";
   result += ", points: " + query_quest_qp(tmp, this_player()->query_level())
      + "";

   result = sprintf("\n%|77'~'s\n\n", " " + quests[tmp][Q_SHORT] + " ") +
// added creator, Carador, 18-Aug-97
      sprintf("%|77s\n\n", "written by " + quests[tmp][Q_CREATOR]) +
      sprintf("%|78s\n\n", result);

   if (file_size(QUEST_DIR + quests[tmp][Q_NAME] + ".quest") < 0) {
      file = QUEST_DIR + "quest." + quests[tmp][Q_POINTS] +"." + 
         quests[tmp][Q_NAME];
      if (file_size(file) < 0) {
         result += quests[tmp][Q_SHORT] + "\n";
      }
      else {
         result += read_file(file, 2);
      }
   }
   else result += read_file(QUEST_DIR + quests[tmp][Q_NAME] + ".quest");
   return result;
}

// The commands... (available in the player's guild).

status do_action(string verb, mapping args) {
   int *quests_to_list;
   int i, max_i, tmp;
   string result, file;
   string *words;

   int solved;   // 0 = unsolved, 1 = solved, 2 = all;
   int low_level, high_level;   // the lower and higher level boundary
   int low_time, high_time;     // the same for the time
   int players;                 // the amount of players
   status dividable, beginner;  // dividable or beginner-flag.
   status verbose;

   if (verb != "quest") return 0;

   if (!args[G_TEXT] || args[G_TEXT] == "help") {
      result = "\
-----------------------------------------------------------------------------\n\
   QUEST LIST / QUEST SHOW  -  Facility for informing yourself about quests  \n\
-----------------------------------------------------------------------------\n\
\n\
Two commands for informing yourself about Tubmud's quests are provided here:\n"+
         print_list_manpage() + "\n" + print_show_manpage();
      this_player()->view_text(result, "quest");
      this_player()->start_view();
      return 1;
   }

   words = explode(lower_case(args[G_TEXT]), " ");
   max_i = sizeof(words) - 1;

   if ( (tmp = make_integer(words[0])) ||
        words[0] == "show"
      ) {
      if (!tmp) {
         if (sizeof(words) == 1) {
            write("\
Well, 'quest show' doesn't tell us which quest you meant, so read this:\n" +
               print_show_manpage());
            return 1;
         }
         tmp = make_integer(words[1]);
         if (!tmp) {
            result = lower_case(implode(words[1..], " "));
            quests_to_list = ({});
            for (i=0; i<sizeof(quests); i++)
               if (strstr(lower_case(quests[i][Q_SHORT]), result) > -1)
                  quests_to_list += ({ i });

            if (!sizeof(quests_to_list)) {
               write(break_string("There's no quest which deals with '" +
                  result + "'.", 78, 2, 1) + "\n");
               return 1;
            }
            if (sizeof(quests_to_list) > 1) {
               result = break_string("There are " + 
                  "/lib/language"->word_number(sizeof(quests_to_list)) + 
                  " quests dealing with '" + result + "':", 78, 2, 1) + "\n" +
                  do_list(quests_to_list) + "\n" +
                  "Be more specific please!\n";

               this_player()->view_text(result, "quest show");
               this_player()->start_view();
               return 1;
            }
            tmp = quests_to_list[0] + 1;
         }
      }
      tmp --;

      if (tmp >= sizeof(quests)) {
         write("Hu, Tubmud hasn't that much quests, okay?\n");
         return 1;
      }
      result = do_show(tmp);
      this_player()->view_text(result, "quest show");
      this_player()->start_view();
      return 1;
   }

   if (words[0] != "list") {
      write("Didn't understand 'quest " + args[G_TEXT] + 
         "'.\nPerhaps you'd like to study the usage of the "+
         "quest-command by typing 'quest'?\n");
      return 1;
   }
   

   for (i=1; i<=max_i; i++) {
     switch(words[i]) {
        case "level" :
           if (i == max_i) {
              write("Missing or illegal level.\n");
              return 1;
           }

           if (low_level) {
              write("Specified level more than once.\n");
              return 1;
           }

           i++;

           if (words[i] == "mine") low_level = this_player()->query_level();
           else low_level = make_integer(words[i]);

           if (!low_level) {
              write("Missing or illegal level.\n");
              return 1;
           }

           if (i == max_i) {
              high_level = low_level;
              break;
           }

           if (words[i+1] == "to" || words[i+1] == "-") {
              i++;

              if (i == max_i) {
                 write("You must specify an upper level boundary.\n");
                 return 1;
              }

              i++;

              if (words[i] == "mine") 
                 high_level = this_player()->query_level();
              else high_level = make_integer(words[i]);
             
              if (!high_level) {
                 write("No or illegal upper level boundary.\n");
                 return 1;
              }
           }
           else high_level = low_level;
           break;


        case "time" :
           if (i == max_i) {
              write("Missing or wrong time.\n");
              return 1;
           }

           if (low_time) {
              write("Specified time more than once.\n");
              return 1;
           }

           i++;
           low_time = make_time(words[i]);

           if (!low_time) {
              write("Missing or wrong time group.\n");
              return 1;
           }

           if (i == max_i) {
              high_time = low_time;
              break;
           }

           if (words[i+1] == "to" || words[i+1] == "-") {
              i++;

              if ( i == max_i ||
                   !(high_time = make_time(words[++i]))
                 ) {
                 write("You must specify an upper time group.\n");
                 return 1;
              }
           }
           else high_time = low_time;
           break;


        case "players" :
        case "player" :
           if (i == max_i) {
              write("Missing or wrong number of players.\n");
              return 1;
           }

           if (players) {
              write("Specified players more than once.\n");
              return 1;
           }

           i++;
           players = make_integer(words[i]);
           break;

   
        case "verbose" :
           verbose = 1;
           break;

        case "unsolved" :
           solved = 0;
           break;

        case "solved" :
           solved= 1;
           break;

        case "all" :
           solved= 2;
           break;

        case "beginner" :
        case "beginners" :

           beginner = 1;
           break;

        case "dividable" :

           dividable = 1;
           break;

        default :
           this_player()->view_text("\
Wrong usage of 'quest list'. Error detected near '" + words[i] + "'.\n\
Perhaps you'd like to read the instructions for the 'quest list'-command?\n\
Here we go:\n" + print_list_manpage(), "quest list");
           this_player()->start_view();
           return 1;
           break;
     }
   }

   if (high_level < low_level) {
      write("The upper level boundary shouldn't be lower than the lower.\n");
      return 1;
   }

   if (high_time < low_time) {
      write("The upper time boundary shouldn't be lower than the lower.\n");
      return 1;
   }


   if (low_level >= WL_APPRENTICE) {
      write("There are no quests which are suitable for wizards.\n");
      return 1;
   }

   quests_to_list = ({ });
   for (i=0; i<sizeof(quests); i++) {
      tmp = this_player()->query_quests(quests[i][Q_NAME]);

      if (solved < 2) {
         if (tmp && !solved || !tmp && solved) continue;
      }

      if (beginner && !quests[i][Q_BEGINNER]) continue;
      if (dividable && !quests[i][Q_DIVIDABLE]) continue;

      if (players) {
         if (intp(quests[i][Q_PLAYERS])) {
            if ( quests[i][Q_PLAYERS] != -1 &&
                 players != (quests[i][Q_PLAYERS] || 1)
               ) continue;
         }
         else if ( players > quests[i][Q_PLAYERS][1] || 
                   players < quests[i][Q_PLAYERS][0]
                 ) continue;
      }

      if (low_level) {
         if ( high_level < (quests[i][Q_LOW_LEVEL] || 1) ||
              low_level > (quests[i][Q_HIGH_LEVEL] || 1000)
            ) continue;
      }

      if (low_time) {
         if ( ( high_time < quests[i][Q_TIME] ||
                low_time > quests[i][Q_TIME] 
              ) &&
              ( !quests[i][Q_DIVIDABLE] ||
                high_time < quests[i][Q_DIVIDABLE] ||
                low_time > quests[i][Q_DIVIDABLE]
              )
            ) continue;
      }

      quests_to_list += ({ i });

   }

   words = ({});
   if (low_level) words += 
      ({ "suitable for level " + low_level + 
         (high_level != low_level ? " to " + high_level : "") });

   if (low_time) words +=
      ({ "with duration " + ti_groups[low_time-1] +
         (high_time != low_time ? " to " + ti_groups[high_time-1] : "") });

   if (players) words += 
       ({ "playable for "+players + " player" + (players != 1 ? "s" : "") });

   if (beginner) words +=
       ({ "which are special beginner-quests" });

   if (dividable) words +=
       ({ "which are divided in several parts" });

   if (!solved) words +=
       ({ "which you didn't already solve" });
 
   if (solved == 1) words +=
       ({ "which you already solved" });

   if (sizeof(quests_to_list)) {
      if (sizeof(words))
         result = break_string("Requesting a list of quests " +
            make_list(words) + ":", 78, 2, 1) + "\n";
      else result = "";
      result += do_list(quests_to_list, verbose);

      if (this_player()->query_level() == 1 &&
          !low_level &&
          (!beginner || !verbose)
         ) {
         if (!beginner) result += "\n\
Hint: You could also try 'quest list beginner' for a list of quests which are\n\
      specially designed for utter " +
         (!this_player()->query_gender() ? "creatures" : "novices") + ".\n";

         else if (!verbose) result += "\n\
Hint: Now you could do a 'quest list verbose beginner' for a more informative\n\
      listing of beginner-quests.\n";
      }

      else 
       if (this_player()->query_level() < NO_MORE_HINTS_WITH_LEVEL) {
         if (!verbose) result += "\n\
Hint: You could also try 'quest list verbose' for a more informative listing\n\
      of the quests.\n";
         else if (!low_level) result += "\n\
Hint: Another possibility could be 'quest list verbose level mine'. That\n\
      would show you an informative listing of all quests suitable for your\n\
      current level.\n";
         else result += "\n\
Hint: Did you ever try just 'quest' for a list with many valid options which \n\
      can be used for 'quest list'?\n";
      }

      this_player()->view_text(result);
      this_player()->start_view();
   }
   else {
      if (!sizeof(words)) write("No quests.\n");
      write(break_string("There are no quests " +
         make_list(words) + ".", 78, 2, 1) + "\n");
   }
   return 1;
}



// The statistic-part

void notify_scenario_solving(string qname, object pl, int reward) {
   int lvl;

   if ( !qname ||
        !pl ||
        !interactive(pl) ||
        pl != previous_object() ||
        (lvl = pl->query_level()) >= WL_APPRENTICE ||
        pl->test_flag(96) ||
        pl->query_property(P_TESTPLAYER)
      ) return;

   if (!member(sc_statistics,qname))
      sc_statistics += ([ qname : ({ 0, 0, 0 }) ]);

   sc_statistics[qname][0] ++;
   sc_statistics[qname][1] += lvl;
   sc_statistics[qname][2] += reward;
   unguarded(1, #'save_object, SAVE_FILE);
}


void notify_solving(string qname, object pl, int reward, int qp_reward) {
   int lvl, qp;
   string qstr;
   int quest_index;

   if ( !qname ||
        !pl ||
        reward <= 0 ||
        !interactive(pl) ||
        pl != previous_object() ||
        (lvl = pl->query_level()) >= WL_APPRENTICE ||
        pl->test_flag(96) ||
        pl->query_property(P_TESTPLAYER)
      ) return;

   qstr = pl->query_quests();

   if (!member(statistics,qname))
      statistics += ([ qname : ({ 0, 0, 0, 0,0 }) ]);

   statistics[qname][0] ++;
   statistics[qname][1] += lvl;
   statistics[qname][2] += reward;
   statistics[qname][3] += (!qstr ? 1 : (sizeof(explode(qstr, "#"))+1));
   statistics[qname][4] += qp_reward;

   unguarded(1, #'save_object, SAVE_FILE);
}

private mixed make_average(mixed arg) {
   return ({ arg[0], arg[1]/arg[0], arg[2]/arg[0], 
             arg[3]/arg[0], arg[4]/arg[0] });
}

private mixed make_sc_average(mixed arg) {
   return ({ arg[0], arg[1]/arg[0], arg[2] / arg[0] });
}


varargs mixed print_statistics(int how_sorted) {
   int i;
   mixed *sorted;
   string result;

   if (!sizeof(statistics)) return "No statistics yet.\n";

   if (how_sorted < 0 || how_sorted > 4) return 0;

   sorted = sort_array(
      transpose_array(
         ({ m_indices(statistics),
            map(m_values(statistics), #'make_average)
         })
      ),
      lambda(
         ({ 'x, 'y }), 
         ({ (how_sorted != 3 ? #'< : #'>), 
            ({ #'[, ({ #'[, 'x, 1 }), how_sorted }), 
            ({ #'[, ({ #'[, 'y, 1 }), how_sorted })
         })
      )
   );

   result = "";

   for (i=0; i<sizeof(sorted); i++)
      result += sprintf("%:-15s |   %4d       %2d     %7d     %2d     %3d / %3d%%\n",
         capitalize(sorted[i][0]),
         sorted[i][1][0],
         sorted[i][1][1],
         sorted[i][1][2],
         sorted[i][1][3],
         sorted[i][1][4],
         (sorted[i][1][4] * 100) / query_quest_qp(sorted[i][0]));

   return "\n\
QUEST           | SOLVINGS   LEVEL        XP    ORDER     QP / QP in %\n\
----------------+-----------------------------------------------------\n" + 
      result + "\
----------------------------------------------------------------------\n";
}

varargs mixed print_sc_statistics(int how_sorted) {
   int i;
   mixed *sorted;
   string result;

   if (!sizeof(sc_statistics)) return "No statistics yet.\n";

   if (how_sorted < 0 || how_sorted > 2) return 0;

   sorted = sort_array(
      transpose_array(
         ({ m_indices(sc_statistics),
            map(m_values(sc_statistics), #'make_sc_average)
         })
      ),
      lambda(
         ({ 'x, 'y }),
         ({ #'<,
            ({ #'[, ({ #'[, 'x, 1 }), how_sorted }),
            ({ #'[, ({ #'[, 'y, 1 }), how_sorted })
         })
      )
   );

   result = "";

   for (i=0; i<sizeof(sorted); i++)
      result += sprintf("%:-15s |   %4d       %2d     %5d\n",
         capitalize(sorted[i][0]),
         sorted[i][1][0],
         sorted[i][1][1],
         sorted[i][1][2]);

   return "\n\
SCENARIO        | SOLVINGS   LEVEL       XP\n\
----------------+---------------------------\n" +
      result + "\
--------------------------------------------\n";
}



// The information-section

status server_info(string str) {
   mapping groups;
   mixed a, b;
   int i, j, sum;
   string result, vb, tmp;
   if (str) str = lower_case(str);

   result = "\
----------------------------------------------------------------------------\n"+
   sprintf("%:|78s\n", "quest-server-info-facility  ---  " +
      this_player()->query_commandline()) + "\
----------------------------------------------------------------------------\n\
\n";

   switch(str) {

      case 0 :
         sum = 0;
         result += "\
Quests        : " +sizeof(quests) + "\n";
         groups = ([]);
         for (i=0; i<sizeof(quests); i++) {
            sum += quests[i][Q_POINTS];
            if (!groups[quests[i][Q_POINTS]])
               groups[quests[i][Q_POINTS]] = ({ quests[i][Q_NAME] });
            else
               groups[quests[i][Q_POINTS]] += ({ quests[i][Q_NAME] });
         }

         a = m_indices(groups);
         b = m_values(groups);
         a = sort_array(transpose_array(({ a, b })), lambda(({ 'x, 'y }),
            ({ #'>, ({ #'[, 'x, 0 }), ({ #'[, 'y, 0 }) })));

         for (i=0; i<sizeof(a); i++)
            result += sprintf("  %2d of %3d qp: ", 
               sizeof(a[i][1]), a[i][0]) + 
               break_string(make_list(a[i][1]), 78, 16, 1) +"\n";

         result += "\
Scenarios     : " + sizeof(scenarios) + "\n";

         groups = ([]);
         a = m_indices(scenarios);

         for (i=0; i<sizeof(a); i++) {
            sum += scenarios[a[i]];
            if (!groups[scenarios[a[i]]]) 
               groups[scenarios[a[i]]] = ({ a[i] });
            else
               groups[scenarios[a[i]]] += ({ a[i] });
         }

         a = m_indices(groups);
         b = m_values(groups);
         a = sort_array(transpose_array(({ a, b })), lambda(({ 'x, 'y }),
            ({ #'>, ({ #'[, 'x, 0 }), ({ #'[, 'y, 0 }) })));

         for (i=0; i<sizeof(a); i++)
            result += sprintf("  %2d of %3d qp: ",
               sizeof(a[i][1]), a[i][0]) +
               break_string(make_list(a[i][1]), 78, 16, 1) +"\n";

         result += "\
Questpoints   : " + sum + "qp\n\
Wizardhood    : " + QP_FOR_WIZZING + "qp (That are " + 
            (QP_FOR_WIZZING * 100 / sum) + "%.)\n\
Limits        : ";
         a = ({});
         for (i=0; i<50; i++)
            if (qp_at_level[i])
               a += ({ "Lvl " + i + ": " +qp_at_level[i] + "qp" });
         result += make_list(a) + "\n";
         result += "\
Avgavglevel   : ";
         sum = 0;
         for (i=0; i<sizeof(quests); i++)
            sum += ( (quests[i][Q_LOW_LEVEL] || 1) +
                     (quests[i][Q_HIGH_LEVEL] || PL_MAX_PLAYER_LEVEL)
                   ) / 2;
         result += (sum / i) + "\n\
                (That's the avg-level of all quest's avg-levels :). If it's\n\
                 too low, there are too many utti-quests, if it's too high,\n\
                 there are too many hlp-quests.)\n";
         result += "\
Tune factor   : " + tune_factor + "\n";
         if (sizeof(qexp) && qexp[10])
         result += "\
Estim. 800-exp: " + qexp[6]/qexp[10] + " (calculated out of " + qexp[10] + 
            " random datas)\n";
         break;

     case "qp" :

         result += "\
Name of        origin.|     new QP when solved with given level\n\
the quest         QP  |   1   3   5   7   9  11  13  15  17  19++\n\
----------------------+--------------------------------------------\n";

         tmp = "";
         for (i=0; i<sizeof(quests); i++) {
            tmp += sprintf("%-:15s [%3d] | ",
               capitalize(quests[i][Q_NAME]),quests[i][Q_POINTS]);
            for (j=1; j<=19; j+=2)
               tmp += sprintf("%3d ", query_quest_qp(i, j));
            tmp += "\n";
         }
         tmp = implode(sort_array(explode(tmp, "\n")[0..<2], #'>), "\n");
     
         result += tmp;
         break;


      case "table" :
      case "tabular" :
      case "odd table" :
      case "odd tabular" :

         result += "\
Quest          :      1     3     5     7     9    11    13    15    17    19\n\
---------------+-------------------------------------------------------------\n"+
            odd_table + "\
-----------------------------------------------------------------------------\n";
         break;

      case "table even" :
      case "even table" :
      case "even tabular" :
          result += "\
Quest          :      2     4     6     8    10    12    14    16    18\n\
---------------+-------------------------------------------------------\n" +
              even_table + "\
-----------------------------------------------------------------------\n";
          break;
         
      case "exp" :
      case "qexp" :
         if (sizeof(qexp) && qexp[10]) result += "\
\n\
Questexperience:\n\
----------------\n\
\n\
                          All quests solved         "+QP_FOR_WIZZING+" qp solved\n\
----------------------------------------------------------------------------\n\
\n\
Level  1               " + sprintf("%15d %20d", qexp[0], qexp[4]/qexp[10]) +"\n\
(THAT'S stupid info :))\n\
\n\
Low Lvl of suggested   " + sprintf("%15d %20d", qexp[1], qexp[5]/qexp[10]) +"\n\
\n\
Avg Lvl of suggested   " + sprintf("%15d %20d", qexp[2], qexp[6]/qexp[10]) +"\n\
\n\
Lvl 19 (or higher)     " + sprintf("%15d %20d", qexp[3], qexp[7]/qexp[10]) +"\n\
(or higher)\n\
\n\
These information are calculated out of " + qexp[10] + " datas.\n";
         else result = "Service not yet available.\n";

         break;

      case "stat" :
      case "stat solvings" :
         result += (print_statistics(0));
         break;

      case "stat level" :
      case "stat lvl" :
         result += (print_statistics(1));
         break;

      case "stat xp" :
      case "stat experience" :
      case "stat exp" :
         result += (print_statistics(2));
         break;

      case "stat order" :
         result += (print_statistics(3));
         break;

      case "stat qp" :
         result += (print_statistics(4));
         break;

      case "stat sc" :
         result += print_sc_statistics(0);
         break;

      case "stat sc lvl" :
      case "stat sc levels" :
      case "stat sc level" :
         result += print_sc_statistics(1);
         break;

      case "stat sc xp" :
      case "stat sc exp" :
      case "stat sc experience" :
         result += print_sc_statistics(2);
         break;

      default :
         vb = query_verb();

         result += 
   vb + "            : Common information about quests and scenarios\n"+
   vb + " stat       : Statistics about quest-solvings, (sorted: how often)\n"+ 
   vb + " stat lvl   : As above, but sorted by average level of solver\n" +
   vb + " stat exp   : As above, but sorted by average given questexp\n" +
   vb + " stat qp    : As above, but sorted by average given questpoints\n" +
   vb + " stat order : As above, but sorted by the order of the solvings,\n\
  that means, if a quest has a 3 in that column, this quest is the third\n\
  quest, the player solved (utti-quests have low, hlp-quests high numbers)\n\n"+
   vb + " stat sc    : Statistics about scenario-solvings\n" +
   vb + " stat sc lvl: As above, but sorted by average level of solver\n" +
   vb + " stat sc exp: As above, but sorted by average amount of exp\n\n" +
   vb + " table      : A table showing how many questexperience is given for\n\
  every quest for all odd player-levels\n" +
   vb + " table even : As above, but for even player-levels\n\n" +
   vb + " qp         : A tabular displaying how many questpoints are granted\n\
  for solving the quests on certain levels\n\n" + 
   vb + " exp        : More detailed information about the questexperience\n\n"+
   vb + " help       : This information\n" +

   "";
         break;
   }
   this_player()->view_text(result, str);
   this_player()->start_view();
   return 1;
}


void setup_information(int count) {
   int qp;
   int l, i;
   int *qu;
   string tmp;

   if (!qexp || qexp[10] < 499) {
      call_out("setup_information", 0, count + 1);
   }

   if (count < sizeof(quests)) {
      if (!count) {
         odd_table = even_table = "";
         qexp = allocate(11);
      }
      odd_table += 
         (tmp = sprintf("%:-15s: ", capitalize(quests[count][Q_NAME])));
      even_table += tmp;

      for (l=1; l<=19; l++) {
         tmp = sprintf(" %5.1f", 
            (float)((float)query_exp_reward(count, l) /
            (float) 1000));
         if (!(l%2)) even_table += tmp;
         else odd_table += tmp;
      }
      odd_table += "\n";
      even_table += "\n";
   
      if (count == sizeof(quests) - 1) {
        odd_table = 
           implode(sort_array(explode(odd_table,"\n")[0..<2], #'>),"\n") +"\n";
        even_table = 
           implode(sort_array(explode(even_table,"\n")[0..<2], #'>),"\n") +"\n";
      }
   }
   else if (qexp) {
      if (count == sizeof(quests)) {
         for (i=0; i<sizeof(quests); i++) {
            qexp[0] += query_exp_reward(i, 1);
            qexp[1] += query_exp_reward(i, (quests[i][Q_LOW_LEVEL] || 1));
            qexp[2] += query_exp_reward(i, -1);
            qexp[3] += query_exp_reward(i, 19);
         }
      }
      else {
         qu = ({ });
         for (i=0; i<sizeof(quests); i++) qu += ({ i });
         qexp[10]++;
         qp = 0;
         while(qp < QP_FOR_WIZZING) {
            qexp[8]++;
            i = random(sizeof(qu));
            qp += quests[qu[i]][Q_POINTS];
            qexp[4] += query_exp_reward(qu[i], 1);
            qexp[5] += query_exp_reward(qu[i],
               (quests[qu[i]][Q_LOW_LEVEL] || 1));
            qexp[6] += query_exp_reward(qu[i], -1);
            qexp[7] += query_exp_reward(qu[i], 19);
            qu -= ({ qu[i] });
         }
         qexp[9] += qp;
      }
   }
}

#endif

