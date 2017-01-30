int HBeats;                    /* HB in guild - used to determine age in guild */
int OldXP;                     /* dealing with exp gain in HB */

int Sacrifice;                 /* sacrifice points required for abilities */
int Fae;                       /* primary guild stat */
int GuildLevel;                /* guild level */
int GuildXP;                   /* total exp put into advancing guild level */
int GXPGain;                   /* the rate at which exp is converted to guild exp */
                               /* this is randomly set at joining */
static int *GuildLevelCosts;   /* exp cost for each guild level */
static int SizeofGLC;          /* size variable */

int Talent;                    /* is this player a talented adept? */
                               /* also set randomly at joining 1 in 6 male, 1 in 4 female */
 
string *Learned;    					 /* array of all abilities a player knows */

static int Casting;            /* casting time */
static string CurrentSpell;    /* spell you are casting at this time */
static mapping Delays;         /* spell delay for spells that have them */
string *SavedDelays;           /* array save of mapping Delays */

static string *cmds, cmd;      /* used in command hook loop */
static int c;                  /* counter variable */

static object dms;             /* temp object for player shadow during init() */

static int SymbolPain;          /* limiting variable for symbol pain ability */