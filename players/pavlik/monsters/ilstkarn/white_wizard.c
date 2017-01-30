inherit "/obj/monster";

/*
 * The White Wizard is the only way to gain access to the Fortress.
 * She has the rune key which will unlock the secret door.  Players
 * with good alignment can offer to help her and she will follow them
 * and assist them in battle (like a pet).  Evil players must kill her
 * to get the key.  There is only one White Wizard and if she is killed
 * she will not reclone for at least 1 hour after her death.
 */

int is_help;
int has_key;
int count;
int leave_time;
object owner;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Ploreria");
  set_alias("ploreria");
  set_short("Ploreria the White Wizard");
  set_long(
  "A tall dark skinned woman dressed in torn white robes leans against the\n"+
  "rocks to catch her breath.  Her cracked and bleeding fingers are\n"+
  "wrapped tightly around an ivory tipped wand.\n");
  set_race("human");
  set_gender("female");
  set_level(19);
  set_hp(600);
  set_ac(22);
  set_al(1000);
  set_aggressive(0);
  set_a_chat_chance(20);
  set_dead_ob(this_object());
  load_a_chat("Ploreria screams: You will not get away with this!\n");
  move_object(clone_object("players/pavlik/weapons/ilstkarn/ice_wand"),
  this_object());
  command("wield wand");
  set_wc(25);
  call_out("random_move", 15+random(10));
  is_help = 0;
  has_key = 1;
  count = 0;
}

id(str) {
  return str == "ploreria" || str == "wizard" || str == "white_wizard";
}

query_attrib(str) { return 30; }
query_count(){ return count; }
query_is_help(){ return is_help; }
query_leave_time(){ return leave_time; }
query_ilstkarn(){ return 1; }

init() {
  ::init();
  if(this_player()->is_player()) {
    add_action("whisper_to","whisper");
    if(!is_help && !query_attack())
      call_out("white_msg", 3+random(5), this_player());
  }
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
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
 * If not assisting a player the Wizard will wander aimlessly.
 */
random_move() {
  int n;

  if(this_object()->query_attack() || is_help) {
    call_out("random_move", 20);
    return 1;
  }

  n = random(8);
  if(n == 0) { command("west"); }
  else if(n == 1) { command("east"); }
  else if(n == 2) { command("north"); }
  else if(n == 3) { command("south"); }
  else if(n == 4) { command("northwest"); }
  else if(n == 5) { command("northeast"); }
  else if(n == 6) { command("southwest"); }
  else if(n == 7) { command("southeast"); }

  call_out("random_move", 20+random(30));
  return 1;
}

follow() {
  string tmp1, tmp2;

  if(!owner) {
    tell_room(environment(),
    "Ploreria sighs and disappears in a puff of smoke.\n");
    move_object(this_object(), "players/pavlik/waste_room");
    destruct(this_object());
    return 1;
  }

  /* cannot follow when fighting */
  if(query_attack()) {
    call_out("follow", 5);
    return 1;
  }

  /* if the owner has turned evil on us */
  if(owner->query_alignment() < -10) {
    move_object(this_object(), environment(owner));
    tell_room(environment(this_object()),
    "Ploreria screams: You cannot fool me, You decietful Demon!\n");
    this_object()->attack_object(owner);
    owner = 0;
    is_help = 0;
    return 1;
  }

  if(!present(owner, environment(this_object()))) {

    /*
     * What is the player leaves the Ilstkarn realm?
     */
    if(sscanf(object_name(environment(owner)), "%spavlik/ilstkarn/%s", tmp1,
    tmp2)!=2) {
      /*
       * If the player is gone too long then leave.
       * The player can move 6 times outside the realm before she leaves
       */
      if(count > 6) {
        tell_object(owner,
        "Ploreria tells you: I must return to my quest.  Good luck to you!\n");
        tell_room(environment(),
        "Ploreria bows and disappears in a puff of smoke.\n");
        move_object(this_object(), "players/pavlik/waste_room");
        destruct(this_object());
        return 1;
      /*
       * Otherwise just increment the counter.
       */
      }
      else {
        count++;
      }
    }

    tell_room(environment(this_object()), "Ploreria leaves.\n");
    move_object(this_object(), environment(owner));
    tell_room(environment(this_object()), "Ploreria enters.\n");

    /* reset the counter if we reenter the realm */
    if(environment()->query_ilstkarn()) {
      count = 0;
    }

    /*
     * if this is the location of the secret door, then give the
     * the fortress key to our owner
     */
    if(environment(this_object())->query_ilstkarn() == "secret") {
      call_out("give_key", 3);
    }

  }

  /* if our owner is fighting maybe we should help out */
  if(owner->query_attack() && !query_attack()) {
    assist();
  }

  call_out("follow", 3);
  return 1;
}

/*
 * Help owner in combat.
 */
assist() {
  object ob;
  ob = owner->query_attack();
  if(query_attack()) return 1;
  if(!environment()->query_ilstkarn()) return 1;
  if(ob->query_alignment() >= 0) return 1;
  tell_object(owner, "Ploreria tells you: I love a good fight!\n");
  tell_room(environment(), "Ploreria joins the battle!\n");
  ob->set_can_kill(1);
  set_can_kill(1);
  attack_object(ob);
  return 1;
}

give_key() {
  if(!has_key) {
    return;
  }
  if(environment(this_object())->query_ilstkarn() != "secret") {
    return;
  }
  tell_object(owner,
  "Ploreria tells you:  Look!  We have found it!  Look at those markings!\n"+
  "Ploreria tells you:  Here, take this key.  It will unlock the door.\n"+
  "Ploreria the White Wizard gives you a key.\n");

  /* give key to player */
  move_object(clone_object("players/pavlik/items/ilstkarn/fortress_key"),
  owner);
  has_key = 0;

  return 1;
}

white_msg(obj) {
  int n, i;

  if(!present(obj, environment(this_object()))) {
    return 1;
  }

  n = obj->query_alignment();
  i = random(3);

  if(n > 0 && is_help == 0) {
    if(i == 0) {
    tell_object(obj,
    "Ploreria whispers to you:  I must get to the hidden Fortress!\n"+
    "Ploreria whispers to you:  I have the key to the secret entrance.\n"+
    "Ploreria whispers to you:  Will you help me?\n");
    }
    else if(i == 1) {
    tell_object(obj,
    "Ploreria whispers to you:  We must find the secret entrance!\n"+
    "Ploreria whispers to you:  Will you help me?\n");
    }
    else if(i == 2) {
    tell_object(obj,
    "Ploreria whispers to you:  The evil wizards are locked away in their Fortress.\n"+
    "Ploreria whispers to you:  I have the key, but I can't find the secret entrance.\n"+
    "Ploreria whispers to you:  Will you help me?\n");
    }
  }
  else if(n < 1) {
    if(i == 0) {
    tell_object(obj,
    "Ploreria tells you:  You will never get inside the Fortress!\n"+
    "Ploreria tells you:  I will die before you get my key!\n");
    }
    else if(i == 1) {
    tell_object(obj,
    "Ploreria tells you:  You will be destoryed, Demon, just like the other villians!\n");
    }
    else if(i == 2) {
    tell_object(obj,
    "Ploreria tells you:  Once I am inside your evil Fortress I will crush your evil\n"+
    "allies.  You cannot stop me now that I have the key!\n");
    }

  }
  return 1;
}

whisper_to(str) {
  string tmp1, tmp2;
  int aln;

  if(!str) return 0;

  if((sscanf(str, "ploreria %syes%s", tmp1, tmp2)==2) ||
     (sscanf(str, "to ploreria %syes%s", tmp1, tmp2)==2)) {

    /* make sure we are dealing with a player */
    if(!this_player()->is_player()) return 1;

    /* don't make any promises will fightning */
    if(this_object()->query_attack()) {
      tell_object(this_player(),
      "Ploreria says: I'm a little busy at the momement...\n");
      return  1;
    }
    
    aln = this_player()->query_alignment();

    /* we don't like evil players! */
    if(aln < 1 && !is_help) {
      say("Ploreria shrieks: I will not be decieved you evil demon!\n");
      say("Ploreria brandishes her magical wand and attacks!\n");
      this_object()->attack_object(this_player());
      return 1;
    }

    /* what if we are already helping someone? */
    if(is_help) {
      write("Ploreria says: Thank you, kind one, but "+
      capitalize(owner->query_name())+" is already helping me.\n");
      return 1;
    }

    write(
    "Ploreria says: Oh, thank you!  If you help me find the hidden fortress\n"+
    "I have the key to get us inside.  I will follow you.\n");
    say(capitalize(this_player()->query_name())+" agrees to help Ploreria.\n");
    say("Ploreria now follows "+capitalize(this_player()->query_name())+".\n");

    is_help = 1;
    owner = this_player();
    leave_time = time() + 3600;
    call_out("follow", 3);

    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" agreed to help the White Wizard. ["+ctime()+"]\n");

    return 1;
  }
}

leave() {
  if(!is_help) {
    return 1;
  }
  move_object(this_object(), "players/pavlik/waste_room");
  if(owner) tell_object(owner,
  "Ploreria whispers to you:  Something urgent has arisen and I must\n"+
  "leave you.  Good luck, and thank you!\n");
  destruct(this_object());
  return 1;
}
    
monster_died() {

  if(is_help) {
    tell_room(environment(this_object()),
    "Ploreria whispers: ...avenge...me....!\n");
    return 0;
  }
  else {
    tell_room(environment(this_object()),
    "Ploreria screams in anguish and topples to the ground.\n"+
    "'You will rot in Hell!' she croaks with her dying breath.\n");
  }

  if(this_player()->is_player()) {
    move_object(clone_object("players/pavlik/items/ilstkarn/fortress_key"),
    present("corpse", environment(this_object())));

    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the White Wizard. ["+ctime()+"]\n");
  }

  /*
   * Set timer so that another wizard will not clone for 60 min
   */
  ("players/pavlik/ilstkarn/ilstkarn_portal")->set_next_wizard(time() + 3600);

  return 0;
}

