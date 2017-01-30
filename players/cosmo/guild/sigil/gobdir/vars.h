/* Saving vars */
string location;             /* Major and minor sigil placement */
int powerlevel;              /* Major sigil power levels */
string major_type;           /* Type of major sigil */
int statpt;                  /* Number of stat points */
string *spelllist;           /* Array of spell names */

/* Non-saving vars */
static mapping major_map;    /* Messages, etc for each major sigil type */
static int max_lessers;      /* Max number of lessers */
static int max_instants;     /* Max number of instants */
