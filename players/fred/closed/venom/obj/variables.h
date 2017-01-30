
static int uncovered;                 /* Allows normal speak while changed */
static int shok;
static int bite_delay;
static int webf_delay;
static int anti_webs;
static int shaped;                    /* Extra damage toggle */
static string shapetype;              /* Weapons form */
static int no_harden;
static int burnoff;                   /* Detoxer */
static int has_changed;               /* Keep track of if has used shapetype 
                                         in the current cycle */
static int hyper_mode;                /* higher attack, majorly lowered defense */
static int hardened;     
string player_short;
static int hb_count;
static int defense_bonus;
static int damage_bonus;
static int regen;
static int venomed;                   /* handles if changed into venom */
/*  NEW Party catcher stuff */
int best_xp_score;                    /* Best kill by this player */
string best_xp_name;                  /* Name of best kill */
int total_pks;                        /* Counts up 1 for each pk kill */
int total_level_pks;                  /* total levels of pks */
int best_xp;
/****************************/

int old_exp;                          /* handles loss of xp per gain */
int stored_mon;
int mp;                               /* material points for changing into venom and some
                                         powers */
string symb_name;                     /* The name of this players symbiote, this is named by
                                         the wizard that places them into the guild */
string oldtitle;
string oldpretitle;
string oldalign;
/************ Skill raise by usage **************/
int bitestat;
int slamstat;
int absorbstat;
int shapestat;
int burnstat;
int hyperstat;
int changestat;

