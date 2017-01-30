#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

int ok_in_room(object ob);

status main(string str) {
  /* peace,aggression,nauseating enhancement */
  object ob;
  string name;
  int level, cost, duration;
  object nob;

  if(!((status)IPTP->item_emt()) && !IPTP->guild_wiz()) return 0;
  if(!str) {
    write("Usage: emt p\n");
    return 1; 
  }

  if(str == "p") {
    if(!gotsp(TP, ENERGY_EMT)) return 1;
    TP->add_spell_point(-ENERGY_EMT);
    ob=first_inventory(environment(TP));
    while (ob) {
      if (living(ob)) {
        if(ob->query_attack()) {
           (ob->query_attack())->stop_fight();
           (ob->query_attack())->stop_hunter();
           (ob->query_attack())->stop_fight();
            ob->stop_fight();
            ob->stop_hunter();
            ob->stop_fight();
        }
      }
      ob = next_inventory(ob);
    }
    write("A visible wave pattern emanates from you.\n");
    write("A soft blue haze envelopes the room.\n");
    write("You feel at peace.\n");
    say("A visible wave pattern emanates from "+TPN+".\n");
    say("A soft blue haze envelopes the room.\n");
    say("You feel at peace.\n");
    return 1; 
  }

/* Disfunctional. Is low priority on the fix list.
  if(str == "a") {
    if(!ok_in_room(TP)) {
      write("You cannot do that here.\n");
      return 1; 
    }
    ob = first_inventory(environment(TP));
    while (ob) {
      if (living(ob)) {
        if(ob == TP) ob = next_inventory(ob);
        if(ob->query_attack())
          if(call_other(COMBATD, "valid_attack", ob->query_attack(), TP))
            (ob->query_attack())->attack_object(TP);
        if(call_other(COMBATD, "valid_attack", ob, TP)) 
          ob->attack_object(TP); 
      }
      ob = next_inventory(ob);
    }
    write("A visible wave pattern emanates from you.\n");
    write("A bright red haze envelopes the room.\n");
    write("You have turned everyone against you!\n");
    say("A visible wave pattern emanates from "+TPN+".\n");
    say("A bright red haze envelopes the room.\n");
    say("You become insane!\n");
    return 1; 
  }
*/

  write("Usage: emt p\n");
  return 1;
}


int ok_in_room(object ob) {
  object room;
  room = environment(ob);
  if( (room == find_object("/room/church.c")) ||
      (room == find_object("/room/adv_guild.c")) ||
      (room == find_object("/room/shop.c")) ||
      (room == find_object("/room/post.c")) ) 
    return 0;
  return 1; 
}
