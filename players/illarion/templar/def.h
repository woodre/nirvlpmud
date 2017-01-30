/* change this line if shifting the location of the guild */
#define BASE_DIR "players/illarion/templar/"

/* giuld directory defs */
#define ROOM_DIR   BASE_DIR+"room/"
#define DAEM_DIR   BASE_DIR+"daemon/"
#define DOC_DIR    BASE_DIR+"doc/"
#define MEMBER_DIR BASE_DIR+"member/"
#define POWER_DIR  BASE_DIR+"power/"
#define LOG_DIR    BASE_DIR+"log/"
#define LIB_DIR    BASE_DIR+"lib/"

/* important objects */
#define MASTER_DAEM DAEM_DIR+"master"

/* macros for emotes and such */
#define TP          this_player()
#define TO          this_object()
#define ETO         environment(this_object())
#define ENV(x)      environment(x)
#define NAME(x)     (string)x->query_name()
#define RNAME(x)    (string)x->query_real_name()
#define GEND(x)     (string)x->query_gender()
#define POSS(x)     (string)x->query_possessive()
#define OBJE(x)     (string)x->query_objective()
#define PRON(x)     (string)x->query_pronoun()
#define LEV(x)      (int)x->query_level()
#define XLEV(x)     (int)x->query_extra_level()
#define TLEV(x)     (int)x->query_total_level()
#define GLEV(x)     (int)x->query_guild_rank()
#define SP(x)       (int)x->query_sp()
#define HP(x)       (int)x->query_hp()
#define MSP(x)      (int)x->query_msp()
#define MHP(x)      (int)x->query_mhp()
#define ALIGN(x)    (int)x->query_alignment()
#define ATTRIB(a,b) (int)a->query_attrib(b)
#define FAIL(x)     { notify_fail(x); return 0; }

#define check_spell(a,b,c,d,e) call_other(MASTER_DAEM,"spell",a,b,c,d,e)
#define check_combat_spell(a,b,c,d,e,f) call_other(MASTER_DAEM,"combat_spell",a,b,c,d,e,f)

/* set numbers for abilities */
#define CUTOFF_ALIGN -5

/* debug info */
#define DEB_WIZ     "illarion"
#define DEB_MSG(x)  if(find_player(DEB_WIZ)) tell_object(find_player(DEB_WIZ),x);

/* ansi colors */
#include "ansi.h"
