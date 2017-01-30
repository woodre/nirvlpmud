inherit "obj/monster";
#include "/players/pavlik/closed/colors.h"
#define ME capitalize(attacker->query_real_name())
#define ROOM environment(this_object())
#define HZ HIW+"Hzsade"+NORM

object attacker;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name(HIW+"Hzsade"+NORM);
  set_race("dragon");
  set_alias("hzsade");
  set_short(HIW+"Hzsade the "+HIR+"Lava Dragon"+NORM);
  set_level(30);
  set_hp(900+random(300));
  set_al(-1000);
  set_wc(32);
  set_ac(20);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(20);
  set_a_chat_chance(30);
  load_chat("The Lava Dragon flexes his long body.\n");
  load_chat(HZ+" looks at you and chuckles to himself.\n");
  load_chat("Lava Dragon claws at the ground.\n");
  load_chat(HZ+" spreads his wings out across the chamber.\n");
  load_chat(HZ+" casually breaks rocks with his huge tail.\n");
  load_a_chat(HZ+" snaps his jaws down on you!\n");
  load_a_chat("The Lava Dragon scrapes you with his barbed scales.\n");
  load_a_chat(HZ+" grabs a handful of lava and throws it at you!\n");
  load_a_chat("Lava Dragon rakes you with his sharp talons!\n");
  set_wc_bonus(30);
  call_out("fake_beat", 3);
  money = 2000 + random(1000);
}

long() {
  write(
  "Hzsade is a powerful ancient Lava Dragon.  He has lived deep below\n"+
  "the surface of the world for many, many centuries.  Hzsade's enormous\n"+
  "body is covered with shiny red scales, each of which is tipped with\n"+
  "a sharp barbed point.  Many dagger-like horns protrude from his\n"+
  "long head and snout.  Tendrils of black smoke pour from his mouth and\n"+
  "nostrils.  His red eyes burn with intensity.\n");
  return 1;
}

query_hp() {
  if(this_player()->query_level() > 20) ::query_hp();
  else return random(800)+50;
}

stop_fight() {
  if(this_player() != this_object()) this_object()->heal_self(random(50));
  else ::stop_fight();
}

stop_fight2() {
  return ::stop_fight();
}

fake_beat(){
  int ranx;
  object ob;

  if(!this_object()->query_attack()){
    call_out("fake_beat", 5);
    return 1;
  }

  attacker = this_object()->query_attack();

  if(!present(attacker, environment(this_object()))){
     tell_object(attacker, MAG+"Hzsade"+NORM+" tells you: "+
     "You won't get away so easily next time!\n"+
     "The ancient dragon's evil laughter echoes through you head.\n");
     this_object()->stop_fight2();
     call_out("fake_beat", 5);
     return 1;
  }

  ranx = random(15);

  if(ranx == 1) {
    tell_room(ROOM,
    HZ+" slashes "+ME+" across the throat with his wicked talons!\n");
    attacker->hit_player(10);
  }
  else if(ranx == 3) {
    object rall;
    int z;
    tell_room(ROOM,
    HZ+" takes a deep breath.\n"+
    HZ+" exhales and "+HIW+"SPEWS"+HIR+" molten LAVA"+NORM+" all over!\n");
    rall = all_inventory(ROOM);
    for(z=0; z<sizeof(rall); z++) {
      if(living(rall[z]) && rall[z] != this_object()) {
        tell_object(rall[z],
        "The molten lava "+HIR+"< BURNS >"+NORM+" your body!\n");
        if(rall[z]->query_npc()) rall[z]->hit_player(100+random(100));
        else rall[z]->hit_player(20+random(30), "other|fire");
      }
    }
  }
  else if(ranx == 4) {
    tell_room(ROOM,
    HZ+" slices through "+ME+"'s flesh with his mighty claws!\n"+
    ME+"'s severed limb drops into the dust.\n");
    attacker->hit_player(20+random(20));
    ob = clone_object("obj/treasure");
    if(random(2)==1){ 
      ob->set_short(ME+"'s severed arm"); ob->set_id("arm"); 
    } else {
      ob->set_short(ME+"'s severed leg"); ob->set_id("leg");
    }
    ob->set_long(ME+"'s severed limb.\n");
    ob->set_alias("corpse");
    ob->set_value(0);
    ob->set_weight(4);
    move_object(ob, environment(this_object()));
  }
  else if(ranx == 5) {
    tell_room(ROOM,
    HZ+" swings his mighty tail and SMASHES "+ME+" into the ground!\n");
    attacker->hit_player(random(50));
  }
  else if(ranx == 6) {
    char_armor();
  }
  else if(ranx == 7) {
    tell_room(ROOM,
    ME+" grows weak as "+HZ+HIR+" steals"+NORM+" his life away!\n");
    attacker->add_spell_point(-10+random(30));
    this_object()->add_hit_point(10+random(30));
  }
  else if(ranx == 8 || ranx == 9) {
    if(random(90)+1 == 13){
      /* INSTA-DEATH! */
      tell_room(ROOM, "\n\n"+
      HZ+" grabs "+ME+HIR+" around the neck and "+HIW+"rips his head from his body!!!!\n"+
      HIR+"Hzsade drops "+ME+"'s "+HIC+"shattered corpse"+HIR+" into the dust.\n\n"+NORM);
      attacker->death();
    } else {
      tell_room(ROOM,
      HZ+" nearly decapitates "+ME+" with a swiping claw.\n");
    }
  }
  else if(ranx == 13) {
    tell_room(ROOM,
    HZ+" grabs "+ME+" in his maw and shakes him like a ragdoll!\n");
    tell_object(attacker,
    "You are "+HIY+"thrashed"+NORM+" around and then thrown away like a broken toy!\n");
    attacker->hit_player(random(100));
  }
  else if(ranx == 14) {
    if(this_object()->query_wc() < 50){
    tell_room(ROOM,
    HZ+" casts a magical spell and his talons glow with deathly power!\n");
    this_object()->set_wc(this_object()->query_wc() + 1);
    } else {
    tell_room(ROOM,
    HZ+" flaps his ancient wings and knocks you to the ground with a\n"+
    "hurricane like wind!\n");
    }
  }
  call_out("fake_beat", 5+random(10));
  return 1;
}

/*
 * Ruin a piece of the attackers armor.
 */
char_armor(){
  object obj;
  int cont;

  obj = first_inventory(attacker);
  cont = 0;

  tell_room(ROOM,
  HZ+" draws a deep breath.\n"+
  "The Dragon exhales and "+HIR+"BLASTS"+NORM+" with a "+HIR+"murderous "+
  "Storm of Fire!\n"+NORM+
  "The awesome fire storm lights "+ME+HIY+" Ablaze!\n"+NORM);

  while(obj && cont == 0) {
    object cur;
    cur = obj;
    obj = next_inventory(obj);
    if(cur->armor_class() && cur->query_worn() && !cur->drop()){
      if(random(3)==1){
        tell_room(environment(this_object()),
         "> Hzsade's devestating breath melts a piece of "+ME+"'s armor!\n");
        tell_object(attacker, ">> "+cur->short()+" is pitted and charred.\n");
        cur->remove(cur->query_name());
        cur->set_ac(0);
        cur->set_short(cur->short()+" [pitted]");
        cont = 1;
      }
    }
  }
}

monster_died(){
  object obj;

  /*********************************************************
   * The Lava Shield is a unique object and only 1 can
   * exist at any time.  If the shield already exists than
   * it will not be cloned again.
   *********************************************************/ 

  obj = present("corpse", environment(this_object()));

  if(!find_object("players/pavlik/items/ilstkarn/lava_shield")) {
    move_object(clone_object("players/pavlik/items/ilstkarn/lava_shield"), obj);
  }

  move_object(clone_object("players/pavlik/items/ilstkarn/lava_heart"), obj);

  if(this_player()->query_real_name()) {
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed Hzsade. ["+ctime()+"]\n");
  }

  return 0;
}

