int HBeats;                    /* HB in guild - used to determine age in guild */
int OldXP;                     /* Dealing with exp gain in HB */
int *Schools;                  /* 8 schools of magic: abju, conj, ench, evoc, divi, illu, necr, tran */
static int *SchoolsBonus;      /* school bonuses */
int *Attribs;                  /* guild attributes: */
static int *AttribsBonus;      /* guild attribute bonuses */
int SchoolsXP;                 /* total school exp gained */
int SchoolsLvl;                /* school level */
int SchoolsPts;                /* free points to spend on schools */
static int *SchoolsCosts;      /* exp cost to gain school pts */
int AttribsXP;                 /* total attribute exp gained */
int AttribsLvl;                /* attribute level */
int AttribsPts;                /* free points to spend on attributes */
static int *AttribsCosts;      /* exp cost to gain attribute pts */
static string PreviousCast;    /* some spells cast over and over is lessened in impact */
static string PreviousCast2;   /* some spells cast over and over is lessened in impact */
static int Casting;            /* casting time */
static string CurrentSpell;    /* spell you are casting at this time */
static mapping Delay;          /* spell delay for spells that have them */
static mapping LearnedSpells;  /* mapping of every spell learned & practice points */
string *LearnedSpellsSave;     /* array for deconstructing/reconstructing LearnedSpells */
static string *spells, cmd;    /* used in command hook loop */
static int c;                  /* counter variable */
