#include <ansi.h>
#define ATN capitalize(attacker->query_real_name())
inherit "obj/monster";
  object ob, ob1, ob2;
  int hps, items;
reset(arg){
   object weapon, gold;
   ::reset(arg);
   if(arg) return;
   set_name("boogey man");
   set_race("monster");
   set_alias("boogey");
   set_short(GRN+"The Boogey Man"+NORM);
   set_level(41);
   set_hp(550);
   set_al(-1000);
   set_wc(32);
   set_ac(18);
   items = 0;
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+1000);
   move_object(gold,this_object());
   set_dead_ob(this_object());
   set_heart_beat(1);
}

heart_beat(){
  int dam, int n;
  object attacker;
   ::heart_beat();
  do_stuff();
  attacker=this_object()->query_attack();
  if(!present(attacker, environment(this_object()))){
    tell_object(attacker,
  GRN+"The Boogey Man"+NORM+" tells you: You won't get away so easily next time!\n"+
  GRN+"Boogey's"+NORM+" sinister laughter echoes through your head.\n");
    this_object()->stop_fight(); this_object()->stop_fight();
    return 1;
    }
  n = random(15);
  dam = random(15);
  if(n == 1){
    tell_object(attacker,
  GRN+"The Boogey Man"+NORM+" puts one of his large "+GRN+"green"+NORM+
  " hands on your forehead.\n"+
  "       "+HIR+"... You feel tired.\n"+NORM+
  GRN+"The Boogey Man"+NORM+" drains some life force from "+ATN+".\n");
    attacker->hit_player(dam);
    attacker->add_spell_point(-dam);
    this_object()->heal_sealf(dam * 2);
  }
  if(n == 2){
    tell_object(attacker,
    GRN+"The Boogey Man"+NORM+" casts a "+HIR+"nightmare!"+NORM+" at you!\n"+
    "Feelings of guilt, terror and hopelessness assualt your mind!\n");
    attacker->hit_player(random(20));
  }
  if(n == 3){
    tell_object(attacker,
    GRN+"The Boogey Man"+NORM+" scares the living shit out of you!!!\n"+
    "You try to run away, but fail.\n");
  }
  if(n == 4){
    tell_object(attacker,
    "You panic and freak out!\n"+
    "In your panicked state you drop some items ... \n");
    command("drop all", attacker);
  }
  if(n == 5){
    tell_object(attacker,
    GRN+"The Boogey Man"+NORM+" feeds of your "+HIY+"fears!\n"+NORM+
    "The Boogey Man smiles wickedly.\n");
    attacker->add_spell_point(-10);
  }
  if(n == 6){
    tell_object(attacker,
    GRN+"The Boogey Man"+NORM+" rips you to pieces with his sharp talons.\n");
    attacker->hit_player(10);
  }
  if(n == 10){
      tell_object(attacker,
      GRN+"The Boogey Man"+NORM+" senses the "+HIB+"terror"+NORM+" in the air.\n"+
      "He renews his attacks with added strength!\n");
      if(this_object()->query_wc() < 50) 
      this_object()->set_wc(this_object()->query_wc() + 1);
  }
}

do_stuff(){
  object ob, dob;
  string nam;
  ob = first_inventory(environment(this_object()));
  while(ob){
    object cur;
    cur = ob;
    ob = next_inventory(ob);
    if(living(cur)){
    if((cur->query_npc() == 0)&&(find_player(cur->query_real_name()))){
        cur->attack_object(this_object());
        this_object()->attack_object(cur);
     } else {
        if(cur != this_object()){
          tell_room(environment(this_object()),
    GRN+"Boogey Man"+HIR+" rips the heart out of your puny pet!\n"+NORM);
          cur->hit_player(10001);
          }
      }
    } else if( (cur->get() == 1) && (random(4) < 2) ){
      tell_room(environment(this_object()),
      "Boogey Man picks up "+cur->short()+".\n");
      move_object(cur, this_object());
      items++;
    }
  }  /* end of while */
  if((items > 0) && (random(5) > 3)){
      dob = first_inventory(this_object());
      tell_room(environment(this_object()),
      "The Boogey Man fumbles "+dob->short()+" and drops it.\n");
      move_object(dob, environment(this_object()));
      items--;
      }
  return 1;
}

monster_died(){
  object obj, obj2;
  tell_room(environment(this_object()),
   "The Boogey Man utters a horrid gasp and falls to the ground, dead.\n"+
   "A rusted sword slips from his grasp and clatters on the ground next\n"+
   "to his lifeless body.\n");
  obj = clone_object("players/pavlik/weapons/jewel_sword");
  move_object(obj, this_object());
  obj = clone_object("players/pavlik/items/bag");
  move_object(obj, this_object());
  obj2 = clone_object("players/pavlik/armor/warpring");
  move_object(obj2, obj);
  return 0;
}
