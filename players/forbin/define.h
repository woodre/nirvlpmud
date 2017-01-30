#ifndef forbinansi
/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2002 Forbin
 *                  All Rights Reserved.
 *  Function:     Definitions file
 *  Create Date:  2002.01.15
 *  Last Edit:    2004.07.02 -Forbin
 *  Notable Changes:            
 */

#include <ansi.h>
#include "/players/forbin/logging.h"

#define ENV(x) environment(x)
#ifndef TP
#define TP this_player()
#endif
#ifndef TO
#define TO this_object()
#endif

/* Queries */
#define POSSES(x) (string)x->query_possessive()
#define OBJECTIVE(x) (string)x->query_objective()
#define PRONOUN(x) (string)x->query_pronoun()

#define QNAME(x) (string)x->query_real_name()
#define QRNAME(x) (string)x->query_real_name()
#define QPNAME(x) CAP((string)x->query_real_name())

#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)

#define HP(x) (int)x->query_hp()
#define MHP(x) (int)x->query_mhp()
#define SP(x) (int)x->query_sp()
#define MSP(x) (int)x->query_msp()
#define QLEVEL(x) (int)x->query_level()
#define QXLEVEL(x) (int)x->query_extra_level()
#define QALIGN(x) (int)x->query_alignment()
#define QSTAT(x,y) (int)x->query_attrib(y)

/* Function Shortcuts */
#define HIT(who,dmg,type) (!type) ? who->hit_player(dmg) : who->hit_player(dmg,type)
#define CLONETO(whowhere,what) move_object(clone_object(what), whowhere);

/* Tell Object of Environment - tell_object(environment(), what) */
#define TOE(ob,msg) if(ob) tell_object(ob, msg);

/* Tell Room of Environment - tell_room(environment(), what, ({ environment() })) */
#define TRE(ob,msg) if(ob && ENV(ob)) tell_room(ENV(ob), msg, ({ ob }));

/* Tell All of Environment - tell_room(environment(), what) */
#define TAE(ob,msg) if(ob) tell_room(ENV(ob), msg);

#define AOHP attacker_ob->hit_player
#define AOL attacker_ob->query_level()
#define AON attacker_ob->query_name()
#define AOO attacker_ob->query_objective()
#define AOP attacker_ob->query_possessive()
#define AOXL attacker_ob->query_extra_level()
#define CO clone_object
#define ENVTO environment(this_object())
#define ENVTP environment(this_player())
#define FAIL notify_fail
#define MEAT this_object()->query_attack()
#define MEATN capitalize(this_object()->query_attack()->query_name())
#define MO move_object
#define MOCO move_object(clone_object
#define PO previous_object()
#define TI this_interactive()
/* duplicates!!!!!! -Bp.
#define TO this_object()
#define TP this_player()
*/
#define TPHP this_player()->hit_player
#define TPHPS this_player()->query_hp() 
#define TPL this_player()->query_level()
#define TPMHPS this_player()->query_mhp()
#define TPMP this_player()->move_player
#define TPMONEY this_player()->query_money()
#define TPMSPS this_player()->query_msp()
#define TPN this_player()->query_name()
#define TPO this_player()->query_objective()
#define TPP this_player()->query_possessive()
#define TPRN this_player()->query_real_name()
#define TPSPS this_player()->query_sp()
#define TPXL this_player()->query_extra_level()

#define H HIR
#define R NORM+RED
#define N NORM
#define forbindefine BLAH
#endif
