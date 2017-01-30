#include "../DEFS.h"
#define LEVEL  2
#define DRAIN 10

status main(string str) {
  object ob;
  if(!gotrank(TP, LEVEL)) return 0;
  if(str){
    notify_fail("Cyber Usage: lead\nNirvana Usage: lead <player>\n");
    return 0;
  }
  if(!gotsp(TP,   DRAIN)) return 1;
  if(!TP->query_attack()) {
    write("You cannot lead a fight when not in combat.\n");
    return 1; }
  ob = (object)TP->query_attack();
  if(ob->is_player()) {
    write("You cannot use this command against players.\n");
    return 1; }
  TP->add_spell_point(-DRAIN);
  ob->attack_object(TP);
  TP->attack_object(ob);
  write("You boldly step into the heat of the battle!\n");
  say(TPN+" boldy steps into the heat of the battle!\n");
  return 1;
}
