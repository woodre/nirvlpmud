#include <ansi.h>
inherit "/obj/monster";
#define FE YEL+"Ferucche"+NORM
#define IT capitalize(obj->query_name())
#define ROOM environment(this_object())

string *dog_killers;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"Ferucche"+NORM);
  set_alt_name("ferucche");
  set_alias("king");
  set_short(FE+", the "+RED+"Salamander King"+NORM);
  set_long(
  "Ferucche is the greatest of all Salamanders.  He towers nearly 8 feet\n"+
  "tall and his body ripples with muscle and fire.  Two jet-black horns\n"+
  "protrude from his head and his tail is tipped with several dagger-sharp\n"+
  "spikes.  Ferucche is not only a cunning and deadly warrior, he is also\n"+
  "a master Warlock.  Ferucche can call on the powers of "+HIR+"Fire-Magic\n"+NORM+
  "to slay his enemy with a single word.  It would not be wise to battle him\n"+
  "without some kind of magical protection.  A tiny gold key dangles from a\n"+
  "delicate chain around his neck.\n");
  set_race("salamander");
  set_level(25);
  set_hp(800);
  set_wc(44);
  set_ac(25);
  set_al(-1000);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(30);
  set_a_chat_chance(30);
  load_chat("Ferucche looks at you and laughs!\n");
  load_chat("Ferucche says: You surface-dwellers are such weaklings!\n");
  load_chat("The Salamander King begins to chant.\n");
  load_chat("Ferucche pokes you in the ribs.\n");
  load_chat("The Salamander King says: Do not disturb me!\n");
  load_chat("Ferucche says: Why do you interupt me?\n");
  load_a_chat("Ferucche kicks you.  OUCH!!\n");
  load_a_chat("The Salamander King begins to chant.\n");
  load_a_chat("Ferucche says: You are a Fool!\n");
  load_a_chat("Salamander Kings tries to through you over the falls!\n");
  load_a_chat("Ferucche whips his spiked tail violently.\n");
  set_wc_bonus(30);
  call_out("fake_beat", 3);
  dog_killers = ({ });
  message_hit = ({
    HIY+"GORED"+NORM, " with his sharp horns",
    HIR+"burned"+NORM, " with its "+HIR+"blazing"+NORM+" claws",
    "whips his tail and "+HIG+"bashes"+NORM, "",
    HIM+"BURIES"+NORM+" his sharp horns into the body of", "",
    HIR+"slices"+NORM+" into", "",
    GRN+"smashes"+NORM, " with his spiked tail",
    "grazes", "",
  });
}

query_ilstkarn(){ return 1; }

query_dog_killers() { return dog_killers; }
query_dog_killer(i) { return dog_killers[i]; }
add_dog_killer(str) { dog_killers += ({ str }); }
remove_dog_killer(str) { dog_killers -= ({ str }); }

/*
 * As usual, I don't like players being able to stop a fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * None of this heal_self crap
 */
heal_self(i) {
  if(i <= 0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

/*
 * Do some interesting combat stuff.
 * The main purpose of this is to do most damage through a special
 * function: do_fire_damage.  If the player has the proper armor
 * most of the damage will be avoided.  If the player does not have
 * the proper armor then he will probably end up dead.
 */
fake_beat() {
  object obj, arm;
  int i;

  obj = this_object()->query_attack();
  
  if(!obj || !present(obj, environment(this_object()))) {
    call_out("fake_beat", 3);
    return 1;
  }

  i = random(10);
  arm = present("ilstkarn_magic_armor", obj);

  /*
   * helpers
   */
  helpers(obj);

  if(i == 0) {
    tell_room(ROOM,
    FE+" intones: "+HIG+"Yigma! Vouzri!\n"+NORM+
    "A "+HIR+"huge fireball"+NORM+" shoots from its fingertips and SLAMS "+IT+"!\n");
    tell_object(obj,
    "The "+HIR+"ball of fire"+NORM+" torches you!\n");
    if(arm && arm->query_worn()) arm->do_fire_damage(50);
    else obj->hit_player(50+random(100), "other|fire");
  }

  if(i == 2) {
    object rall;
    int x;

    tell_room(ROOM,
    FE+" raises his clawed hands in the air.\n"+
    FE+" shouts some words in the powerful language of "+HIR+"FIRE-MAGIC!\n"+NORM+
    "The ground shakes and "+HIW+"cracks open"+NORM+" beneath your feet!\n");
    tell_room(ROOM,
    HIR+"A wall of Flames"+NORM+" erupts from the crack and "+HIR+"scorches"+NORM+" you!\n");

    rall = all_inventory(ROOM);
    for(x=0; x<sizeof(rall); x++) {
      if(!rall[x]->is_player()) rall[x]->hit_player(100+random(100), "other|fire");
      else if(!rall[x]->query_ilstkarn()) rall[x]->hit_player(random(50), "other|fire");
    }
  }

  if(i == 4) {
    tell_room(ROOM,
    "The Salamander King casts a powerful "+HIR+"Fire-Magic"+NORM+" spell!\n"+
    "A ring of "+RED+"searing hot flames"+NORM+" encircles "+IT+"!\n");
    tell_object(obj,
    "A ring of flames surrounds you!  The hot flames "+HIR+"BURN!\n"+NORM);
    if(arm && arm->query_worn()) arm->do_fire_damage(20+random(40));
    else obj->hit_player(40+random(60), "other|fire");
  }

  if(i == 6) {
    tell_room(ROOM,
    FE+" strikes "+IT+" in the chest and shouts: "+HIM+"KRAI DEATH!\n"+NORM);
    if(arm && arm->query_worn()) {
      tell_object(obj, HIW+"Your magical armor saves you!\n"+NORM);
      tell_room(ROOM, IT+"'s magical ring blocks the spell!\n");
    }
    else {
      tell_room(ROOM, IT+" cries out and falls to the ground!\n");
      tell_object(obj,
      HIW+"The powerful spell rips your body apart piece by piece!\n"+NORM);
      obj->death();
    }
  }

  if(i == 8) {
    tell_room(ROOM,
    FE+" clasps his hands together and shouts: "+HIG+"Amon Lok Verluc!\n"+NORM+
    "A swirling mass of flames "+HIW+"DETONATES"+NORM+" on "+IT+"!\n");
    if(arm && arm->query_worn()) arm->do_fire_damage(20+random(50));
    else obj->hit_player(50+random(100));
  }

  if(i == 9) {
    tell_room(ROOM,
    FE+" points at "+IT+" and says: "+GRN+"Quanek!\n"+NORM+
    IT+"'s body catch fire and "+HIR+"burns painfully!\n"+NORM);
    if(arm && arm->query_worn()) arm->do_fire_damage(40);
    else obj->hit_player(random(100), "other|fire");
  }
      
  call_out("fake_beat", 3);
  return;
}

helpers(myattacker) {
  object dog, rall;
  int i;
  rall = all_inventory(ROOM);
  for(i=0; i<sizeof(rall); i++) {
    if(rall[i] == myattacker || !rall[i]->is_player()) continue;
    if(rall[i]->query_attack() != this_object()) continue;
    if(killed_hound(rall[i]->query_real_name())) continue;
    tell_room(ROOM,
    FE+" claps his hands twice and a "+HIR+"Hellhound"+NORM+" rushes in!\n"+
    "The Hellhound snarls and attacks "+capitalize(rall[i]->query_name())+"!\n");
    dog = clone_object("players/pavlik/monsters/ilstkarn/hellhound");
    move_object(dog, ROOM);
    dog->sick(rall[i]);
  }
  return 1;
}

killed_hound(str) {
  int i;
  for(i=0; i<sizeof(dog_killers); i++) {
    if(dog_killers[i] == str) return 1;
  }
  return 0;
}

monster_died() {
  object cor;

  cor = present("corpse", environment(this_object()));
  move_object(clone_object("players/pavlik/items/ilstkarn/hell3_chest_key"), cor);

  if(this_player()->query_real_name()) {
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Salamander King. ["+ctime()+"]\n");
  }
  return 0;
}

