int HBeats;                    /* HB in guild - used to determine age in guild */
int OldXP;                     /* dealing with exp gain in HB */

int GuildLevel;                /* guild level */
int GuildXP;                   /* total exp put into advancing guild level */
static int *GuildLevelCosts;   /* exp cost for each guild level */

mapping Schools;               /* 8 schools of magic: abju, conj, ench, evoc, divi, illu, necr, tran */
string *SavedSchools;          /* array save of mapping Schools */
static mapping SchoolsBonus;   /* school bonuses */
int SchoolsXP;                 /* total school exp gained */
int SchoolsLvl;                /* school level */
int SchoolsPts;                /* free points to spend on schools */
static int *SchoolsCosts;      /* exp cost to gain school pts */

mapping Attribs;               /* guild attributes: */
string *SavedAttribs;          /* array save of mapping Attribs */
static mapping AttribsBonus;   /* guild attribute bonuses */
int AttribsXP;                 /* total attribute exp gained */
int AttribsLvl;                /* attribute level */
int AttribsPts;                /* free points to spend on attributes */
static int *AttribsCosts;      /* exp cost to gain attribute pts */

static int SizeofGLC;          /* holding variable for sizeof() GuildLevelCosts */
static int SizeofSC;           /* holding variable for sizeof() SchoolsCosts */
static int SizeofAC;           /* holding variable for sizeof() AttribsCosts */

static mapping PreviousCast;   /* single key and value (last spell cast : #s of time cast in row) used
                                  to lessen spell impact when same spell is cast over and over again */
static int Casting;            /* casting time */
static string CurrentSpell;    /* spell you are casting at this time */
static mapping Delays;         /* spell delay for spells that have them */
string *SavedDelays;           /* array save of mapping Delays */

int SpellLevelTrains;          /* # of spell levels that you can learn: i.e. level 6 spell takes 6 pts */

string *LearnedAbju;					 /* array of all spells player knows of given school */
string *LearnedConj;
string *LearnedEnch;
string *LearnedEvoc;
string *LearnedDivi;
string *LearnedIllu;
string *LearnedNecr;
string *LearnedTran;

string *LearnedOne;            /* array of all spells player knows of given level */
string *LearnedTwo;
string *LearnedThree;
string *LearnedFour;
string *LearnedFive;
string *LearnedSix;
string *LearnedSeven;

string *FullSpellList;         /* List of all the spells a mage knows in simple array (added as learned) */
int    *FullSpellCasts;        /* Number of times given spell has been cast at current level (tied to FullSpellList) */
int    *FullSpellLevels;       /* Level of spell (ranges 1-4, tied to FullSpellList) */

static string *cmds, cmd;      /* used in command hook loop */
static int c;                  /* counter variable */

static object mageshadow;      /* temp object for player shadow during init() */

mixed GuildColor;              /* base guild color, selectable by player */