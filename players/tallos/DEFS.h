#include "/players/eurale/closed/ansi.h"

/* player information */
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define TPL this_player()->query_level()
#define TPXL  this_player()->query_extra_level()
#define TPAC this_player()->query_ac()
#define TPWC this_player()->query_wc()
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPSTR this_player()->query_attrib("str")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPMAG this_player()->query_attrib("mag")
#define TPPIE this_player()->query_attrib("pie")
#define TPSTE this_player()->query_attrib("ste")
#define TPLUC this_player()->query_attrib("luc")
#define TPINT this_player()->query_attrib("int")

/* object information */
#define TO this_object()
#define ETP environment(this_player())
#define ETO environment(this_object())

roomspeak(msg) {
string who;
who = first_inventory(environment(this_player()));
while(who) {
  if(living(who) && !who->query_npc() && who != this_player()) {
    tell_object(who, msg+"\n"); }
  who = next_inventory(who);
}
return 1;
}
