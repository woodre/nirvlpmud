#include <ansi.h>
inherit "/obj/monster";
object gold;

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("desert snake" );
  set_alias("snake");
  if(!random(2))
    set_short("A snake of the desert");
  else
    set_short("A desert snake");
  set_long(
"This powerful creature is only partially visible in the sands of the\n"+
"desert.  Its body glides over and through the sands almost invisible\n"+
"to the naked eye.  Its head has a strange gland on it that looks as\n"+
"though it could be used to emit some sort of gas.  This snake looks\n"+
"like a very vicious beast, you should not fight it unless you are\n"+
"adequately prepared and a strong warrior.\n");
  set_level(22);
  set_ac(22);
  set_wc(41);
  set_wc_bonus(8); /* 6 * 1.25 ~ 8 */
  set_hp(1000);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(1);
  load_chat("The snake slides across the sand.\n");
  load_chat("The snake seems unaware of your presence.\n");
  load_chat("The snake hisses softly.\n");
  set_dead_ob(this_object());
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  tell_room(environment(),
    "You discover a pile of coins among the remains of the snake.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(4000 + random(5000));
  move_object(gold, environment());
  if(!(random(5)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}


heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(present(attacker_ob, environment()) && !random(6))
  {
    tell_room(environment(),
      GRN+"The snake protects itself by expelling a cloud of gas at "+
      attacker_ob->query_name()+"!\n"+NORM, ({ attacker_ob }));
    tell_object(attacker_ob,
      GRN+"The snake expells a cloud of poisonous gas at you!\n"+NORM);
    attacker_ob->hit_player(50 + random(35), "other|poison");
  }
}

