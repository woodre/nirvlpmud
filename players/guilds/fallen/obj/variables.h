
int guild_exp;                 /*  amount of guild experience              */
int beats;                     /*  number of hbs [age] [thanx Snow]        */
int percent;                   /*  % of xp to go into gxp                  */
int endurance, max_endurance;  /*  Endurance-  current and total           */
string special_title;          /*  for special custom titles               */
int weave;                     /*  can't wield a wep unless set [by weave] */
int endurance_monitor;         /*  if on player sees the endurance monitor */
string posendcol, negendcol, norm; /*  color the endurance monitor is +/-  */
static int c, d, e, f;         /*  used in endurance_check for end monitor */
static int dark_ass;           /*  for the Dark Assistance spell           */
static int shadowcloak;        /*  Shadowcloak- used for drain in hb       */
static int siphon;             /*  toggle for siphon ability               */
static int rage;               /*  used to limit rage to one per hb        */
static int shadow_shield;      /*  used when shield spell is active        */
static int focus, duration;    /*  Focus ability- power and length         */
static int vigor;              /*  Vigor provides wc bonus for end drain   */
static int vigor_level;        /*  different types (1,2,3) of vigor spell  */
static int vigor_bonus;        /*  The wc bonus for vigor                  */
static string *history;        /*  channel history var                     */
static object item;            /*  used in hb for kid protection code      */
static object combat;          /*  USER->query_attack() temp val in hb.h   */
static int casting;            /*  used in spells that have casting delay  */
int old_exp;                   /*  dealing with xp gain in hb              */
string custom_monitor;         /*  verte code - for showing end in mon     */

