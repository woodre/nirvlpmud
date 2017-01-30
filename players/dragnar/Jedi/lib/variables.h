static mapping cmds;      /* aval. commands to the user */

mixed *skills;	          /* skills user has gained */

string *tasks;            /* Tasks done by jedi. */
string *secondary_masters;/* Other masters that are allowed BY THE 
                             MASTER to train their apprentice. */

string my_master;         /* Who players master is */
string mon_color;         /* monitor color */
string wep_color;         /* Lightsaber color */

int cp;                   /* concentration points, run Jedi powers */
int mcp;
int skill_points;         /* Avail. points for skill training */
static int absorb;        /* gives a temporary ac, uses the paladin code */
static int rage;          /* Darkside anger */
static int mind_shield;	  /* protect the player from force attacks */                                                            
int council;              /* Is this player a council member */
int darkside;             /* Did this player fall to the darkside? */
int mon_on;	              /* is jedi monitor on? */
static int force_delay;   /* delay before able to cast another jedi power */
int goodness_pool;        /* are we light or dark?  if <= 0 then darkside */
int wep_life;             /* Length of life left in saber */
int saber_type;           /* Type of Saber */
object offwep;
    
static int damage,new_hp,old_hp, exps, old_exps;
static object carry_obj;
static string carry_obj_name;
