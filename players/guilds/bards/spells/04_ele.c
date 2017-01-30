#include "/players/guilds/bards/def.h"


status main(string str) {
  object ob;
  string target;
  string type;
  int damage;
  int cost;
  
  if(TP->query_spell_dam())
    FAIL("You've already cast a spell.\n");
  if (!str && !TP->query_attack())
    FAIL("You must direct the tune at an opponent.\n");
  if (!str && TP->query_attack()) {
    ob = (object)TP->query_attack();
  } else {
    ob = present(str, environment(TP));
  }
  if (!ob) {
    FAIL("You must direct the tune towards an opponent.\n");
  }
  target = (string)ob->query_name();
  damage=random(24);
  damage+=BLVL;
  cost=15;
  cost+=BLVL;  
  if (attack_spell(-129, 4, cost, ob) == -1)
    return 0;
  write("\n");
  switch(random(8)) {
    case 0:
      write("You sing the tune of Elemental Earth.\n");
      say(tp + " sings the tune of Elemental Earth.\n");
      tell_room(ENV,
        target +
      " is buried under a rain of sharp gray stones.\n");
      type="other|earth";
      break;
    case 1:
      write("You whistle up a storm.\n");
      say(tp + " whistles up a storm.\n");
      tell_room(ENV,
        "\n*Clouds gather overhead.\n" +
        "\n   *Thunder is heard in the distance.\n" +
        "\n      *It begins to rain on " + target + ".\n" +
        "\n         *" + target +
      " is struck by a BLAZING bolt of lightning.\n\n");
      type="other|electric";
      break;
    case 2:
      write("You throw a small iron sphere at " + target +
      " and hum an off key tune.\n");
      say(tp + " throws a small iron sphere at " + target + 
      " and hums an off key tune.\n");
      tell_room(ENV,
        "The ball EXPLODES, piercing " + target +
      " with sharp slivers of shrapnel.\n");
      type="physical";
      break;
    case 3:
      write("You play a light tune upon your " + INST + ".\n" +
      "Extending your hand, you point at " + target + ".\n");
      say(tp + " plays a light turn upon " + POSS(TP) + " " + INST +
      ".\n" + tp + " points at " + target + ".\n");
      tell_room(ENV,
        target +
      " is picked up by a sudden gust of wind and smashed against the ground.\n");
      type="physical";
      break;
    case 4:
      write("You play a blazing melody upon your " + INST + ".\n");
      say(tp + " plays a blazing melody upon " + POSS(TP) + " " + INST +
      ".\n");
      tell_room(ENV,
        "A column of searing crimson fire descends from the heavens upon "
        + target + ".\n" + target +
      " is engulfed in an inferno of flame.\n");
      type="other|fire";
      break;
    case 5:
      write("You play the tune of Elemental Ice upon your " + INST +
      ".\n" + "Glancing up, you point at " + target + ".\n");
      say(tp + " plays the tune of Elemental Ice upon " + POSS(TP) + " " +
        INST + ".\n" + "You feel a slight chill as " + tp +
      " points at " + target + ".\n");
      tell_room(ENV,
        target +
      " is nearly decapitated by large slivers of falling ice.\n");
      type="other|ice";
      break;
    case 6:
      write("You play a tune on your " + INST + ".\n" +
        "Singing the words 'Rikca Solamnos Larlus' you point at " +
      target + ".\n");
      say(tp + " plays a tune upon " + POSS(TP) + " " + INST + ".\n" + tp +
        " sings the words 'Rikca Solamnos Larlus' and points at " +
      target + ".\n");
      tell_room(ENV,
        target +
      " is blinded by a burst of scintillating white light.\n");
      type="other|light";
      break;
    case 7:
      write("You whistle a pastoral tune and glare at " + target +
      ".\n");
      say(tp + " whistles a pastoral tune and glares at " + target +
      ".\n");
      tell_room(environment(TP),
        target +
      " is impaled by hundreds of large wooden splinters.\n");
      type="physical";
      break;
  }
  if(!type)
    type="physical";
  if (damage > ob->query_hp()) 
    damage = (int)ob->query_hp() - 1;
  TP->spell_object(ob, "elemental", damage, cost, "", "", "");
  TP->set_spell_dtype(type);

  return 1;
}
