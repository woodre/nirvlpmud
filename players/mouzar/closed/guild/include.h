#define VIS "/cmds/wiz/_vis.c"
#define ANSI query_ANSI()
#define MASTER "/players/mouzar/closed/guild/ancients"
#define find(str) find_living(str)
#define STORE "/players/mouzar/closed/guild/store"
#define TAT present("riskadh-tattoo",this_player())
#define PK query_pl_k()
#define can_invis_again 130
#define till_again 600
#define LVL ME->query_level()
#define SP this_player()->query_spell_points()
#define HP this_player()->query_hp()
#define CAP(X) capitalize(X)
#define ME this_player()
#define rn ME->query_real_name()
#define JN CAP(ME->query_name())
#define RN CAP(ME->query_real_name())
#define env_name(obj)environment(obj)->query_name()
#define env(X) environment(X)
#define TOBJ environment(this_object())
#define pse present(str,env(ME))
#define HISTORY 20
string points,target;
int muf, vrmuf, medit, gflag, track, shield_flag; 
int med_count,invis_timer,invis_flag,hb_count;
int lsp,lhp,hm_flag,x,gl,pamt,PK_flag,danger;
int shield;
object cloaker,CLK,trp,fin,medwho;
object SHADOW, cloaker, CLK, trp, fin, medwho;
string *msgbuf = ({ });
 
