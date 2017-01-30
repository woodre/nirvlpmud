inherit "/players/mizan/core/monster.c";

int hps;

reset(arg)
{
    object weapon;
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("amelia");
    set_alias("girl");
    set_short("Amelia");
    set_long("To your surprise, Amelia is a young girl, appearing to be just\n"+
    "about eleven or twelve. Charmed by her innocence and beauty, you can't\n"+
    "help but let out a smile as you watch her play with the glowing blobs\n"+
    "of stuff that drift about.\n");
    set_level(17);
    set_hp(246);
    set_al(980);
    set_wc(14);
    set_ac(8);
    gold=clone_object("obj/money");
    gold->set_money(random(500)+500);
    move_object(gold,this_object());
    set_chat_chance(9);
    load_chat("Amelia giggles happily.\n");
    load_chat("Amelia pokes a glowing mass of stuff. It quivers.\n");
    load_chat("Amelia smiles happily.\n");
    weapon=clone_object("players/mizan/etheriel/heals/divine-harmony.c");
    move_object(weapon,this_object());
    enable_commands();
}

heart_beat()
{
  int dam;
  object attacker,room;
  string attacker_name;
  string rmove;
  ::heart_beat();
  room=environment(this_object());
  attacker=this_object()->query_attack();
  if(attacker){
    attacker_name=attacker->query_real_name();
    if(present(attacker_name,environment(this_object()))){
      if(1 == random(10) && (attacker->query_level()) > 10) {
        tell_room(room,"A low rumbling is felt as "+capitalize(attacker_name)+" is hurled into the unknown.\n");
        rmove=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
        move_object(attacker, "players/mizan/etheriel/ROOMS/"+rmove);
      }
      if(1 == random(3)) {
	tell_room(room, capitalize(attacker_name)+" is smashed by a tidal shockwave.\n");
	attacker->run_away();
      }
      if(1 == random(20)) {
	tell_room(room, "Amelia is healed by a passing Boofer.\n");
	this_object()->heal_self(50);
      }
    }
  }
}

