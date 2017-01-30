#include "/players/guilds/bards/def.h"

status main()  {
  object ob, ob2;
  object *inv;
  int i, cost_count, num_inv, index_inv;
  string NAM;
  ob2 = present("gem", TP);
  if (!ob2) {
    ob2 = present("stone", TP);
  }
  if (!ob2) {
    ob2 = present("rock", TP);
  }
  if (!ob2) {
    write("You must have a gemstone to play the requiem of the stars.\n");
    return 1;
  }
  if((int)ob2->query_value() < 100) {
    write("Your gemstone is not valuable enough.\n");
    return 1;
  }
  NAM= (string)ob2->short();
  if(spell(-170, 7, 50) == -1)
    return 0;
  tell_room(ENV, tp + " holds up " + NAM + ".\n");
  write("You play a requiem to the stars upon your " + INST + ".\n");
  say(tp + " plays a requiem upon " + POSS(TP) + " " + INST + ".\n");
  tell_room(ENV, "\nA burst of STARFIRE explodes around you.\n");
  cost_count = 0;
  inv=all_inventory(environment(this_player()));
  num_inv=sizeof(inv);
  index_inv=0;
  while (index_inv<num_inv) {
    ob = inv[index_inv];
    if (ob->is_player()) {
      tell_room(ENV,
        ob->query_name() +
      " is shielded from the STARFIRE.\n\n");
      tell_object(ob, "You feel very lucky.\n\n");
    } else if (ob->is_pet()) {
      tell_room(ENV,
        "The " + ob->query_name() +
      " is shielded from the STARFIRE.\n");
    } else if (ob->query_npc()) {
      tell_room(ENV,
        ob->query_name() +
      " is FRIED by a burst of STARFIRE.\n");
      if (!ob->query_attack()) {
        if (living(ob))
        ob->attack_object(TP);
        TP->attack_object(ob);
      }
      ob->hit_player(4+random(20),"other|fire");
      cost_count = cost_count + 1;
    }
    index_inv++;
  }
  cost_count = cost_count * 20;
  if (cost_count < 40) {
    cost_count = 50;
  }
  call_other(TP, "add_spell_point", -cost_count);
  tell_room(ENV, NAM + " fades from view.\n");
  destruct(ob2);
  return 1;
}
