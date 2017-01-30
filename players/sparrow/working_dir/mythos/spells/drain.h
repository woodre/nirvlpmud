#include "/players/mythos/closed/guild/def.h"
drain(str) {
object ob;
string name;
int num;
if(!str) { write("Usage: drain <who>\n"); return 1;}
if(qtf < 13) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 45) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 900) { write("The darkness calls for a sacrifice.\n"); return 1;}
name = str;
if(!present(name,environment(tp))) {
 write("That is not here.\n"); return 1;}
  if(!(present(name,environment(tp))->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
    num = present(name,environment(tp))->query_level();
    if(num < 5) { write("You may not use this on a creature so low in life.\n");
    return 1;}
present(name,environment(tp))->set_level(num - 1);
tp->add_sxp(num * 100);
tp->add_hit_point(random(num/2));
tp->add_spell_point(-45);
pp->add_sacrifice(-900);
write("You reach out with a hand.\n");
tell_room(environment(tp),"\nSuddenly, a high pitched whistling is heard through the room!\n\n"+
                          "Then.........       \n\n"+BOLD+
                          "* *  *   * DARKNESS *   *  * *\n\n"+NORM+
                          "The room clears and there is deadly silence!\n\n");
write("You drained the life from "+capitalize(name)+".\n");
say(capitalize(tpn)+" has drained the life from "+capitalize(name)+"!\n");
present(name,environment(tp))->attack_object(tp);
return 1;}
