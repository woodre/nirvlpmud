#include <ansi.h>
#define TP this_player()
#define POS TP->query_possessive()                   /* Gender */
#define TPRN this_player()->query_real_name()        /* Returns Name */
#define MOCO move_object(clone_object
#define WW int_command("wield weapon")         /* wields weapon */
#define TPL this_player()->query_level()
#define TO this_object()
#define TI this_interactive()
#define PO previous_object()
#define ENV(x) environment(x)
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)
#define MEATS attacker->query_name()
#define MEAT this_player()->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(this_player()->query_name())
#define TPXL this_player()->query_extra_level()
#define GEN this_player()->query_possessive()
#define TPS call_other(TP,"query_attrib","str")
#define TPI call_other(TP,"query_attrib","int")
#define TPW call_other(TP,"query_attrib","wil")
#define TPM call_other(TP,"query_attrib","mag")
#define TPST call_other(TP,"query_attrib","ste")
#define TPSTA call_other(TP,"query_attrib","sta")
#define ATT USER->query_attack()
#define USER environment(this_object())
#ifndef __LDMUD__object gold;
#endif