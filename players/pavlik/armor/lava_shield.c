#include <ansi.h>
inherit "players/pavlik/armor/armor";
#define IT capitalize(obj->query_name())
#define BONUS 2

reset(arg){
 ::reset(arg);
 set_short(HIR+"Lava "+HIW+"Shield"+NORM);
 set_long(
 "This shield is made from the barbed scales of the "+HIR+"Lava Dragon"+NORM+".\n"+
 "The red shield is very warm to the touch, as if the heat of the Lava\n"+
 "Dragon still burns within.  Numerous barbed points protrude from the\n"+
 "dragon scales, and they might prove harmful for anyone who gets to close.\n");
 set_ac(2);
 set_weight(2);
 set_value(5000);
 set_alias("lava shield");
 set_name("the "+HIR+"Lava "+HIW+"Shield"+NORM);
 set_type("shield");
 set_save_flag(1);
 call_out("shieldbash", 30);
}

shieldbash() {
  object obj;

  if(!worn) {
    call_out("shieldbash", 300);
    return 1;
  }
  if(!worn_by->query_attack()) {
    call_out("shieldbash", 180);
    return 1;
  }

  obj = worn_by->query_attack();
  tell_object(worn_by,
  "You step forward and "+HIW+"*- BASH -* "+NORM+IT+" with the "+HIR+
  "Lava "+NORM+"Shield!\n");
  tell_others(capitalize(worn_by->query_name())+" steps up and "+HIW+
  "*- BASHES -* "+NORM+IT+" with "+worn_by->query_possessive()+" "+HIR+
  "Lava"+NORM+" Shield!\n");

  obj->hit_player(10);
  worn_by->add_spell_point(-random(10));
  call_out("shieldbash", 60+random(180));
  return 1;
}

tell_others(str) {
  object ob;
  int i;
  ob = all_inventory(environment(worn_by));
  for(i=0; i<sizeof(ob); i++) {
    if(ob[i] != worn_by) tell_object(ob[i], str);
  }
  return 1;
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_pow_bonus(BONUS);
    present("mageobj", this_player())->add_int_bonus(BONUS);
    present("mageobj", this_player())->add_wis_bonus(BONUS);
  }
  return 1;
}

remove_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_pow_bonus(-BONUS);
    present("mageobj", this_player())->add_int_bonus(-BONUS);
    present("mageobj", this_player())->add_wis_bonus(-BONUS);
  }
  return 1;
}

