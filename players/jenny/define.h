#ifndef __JENNYLIB__
#define __JENNYLIB__
#include "/players/jenny/ansi.h"
#define TP this_player()
#define POS TP->query_possessive()
#define MEAT (TO ? TO->query_attack() : 0)
#define MEATN capitalize(MEAT->query_name())
#define MO move_object
#define TPRN this_player()->query_real_name()
#define TPN this_player()->query_name()
#define MOCO move_object(clone_object
#define TPL this_player()->query_level()
#define TO this_object()
#define TI this_interactive()
#define PO previous_object()
#define ENV(x) environment(x)
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)
#define STESTAT TP->query_attrib("ste")
#define LUCSTAT TP->query_attrib("luc")
#define STRSTAT TP->query_attrib("str")
#define STASTAT TP->query_attrib("sta")
#define MAGSTAT TP->query_attrib("mag")
#define PIESTAT TP->query_attrib("pie")
#define INTSTAT TP->query_attrib("int")
#define WILSTAT TP->query_attrib("wil")
#define STEMEAT MEAT->query_attrib("ste")
#define LUCMEAT MEAT->query_attrib("luc")
#define STRMEAT MEAT->query_attrib("str")
#define STAMEAT MEAT->query_attrib("sta")
#define MAGMEAT MEAT->query_attrib("mag")
#define PIEMEAT MEAT->query_attrib("pie")
#define INTMEAT MEAT->query_attrib("int")
#define WILMEAT MEAT->query_attrib("wil")
object gold;
#endif
