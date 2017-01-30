inherit "/obj/monster";
#define MAX 400
#define ME capitalize(this_player()->query_name())

int sp;
string crap1, crap2;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Laithyra");
  set_alias("laithyra");
  set_short("Laithyra, High Priestess of Biln");
  set_long(
  "Laithyra is the loyal subject of Biln, a once powerful and arrogant\n"+
  "god.  When Biln ordered his minions to drive the evil wizards from\n"+
  "the mountain fortress of Arcydia, Laithrya was first to lead the\n"+
  "charge.  Her unmatched courage and overwhelming confidence landed her\n"+
  "here in these dark dungeons to rot for the rest of her days.  Not even\n"+
  "Biln could save her from this nexus of evil.  Laithyra still holds her\n"+
  "magnificent mace 'Demonbane', however the weapon is useless without the\n"+
  "magical gem that fits its pummel.\n");
  set_long(
  "Laithyra is the loyal subject of Biln, a once powerful and arrogant\n"+
  "god.  When Biln ordered his minions to drive the evil wizards from\n"+
  "the mountain fortress of Arcydia, Laithrya was first to lead the\n"+
  "charge.  Her unmatched courage and overwhelming confidence landed her\n"+
  "here in these dark dungeons to rot for the rest of her days.  Not even\n"+
  "Biln could save her from this nexus of evil.\n");
  set_race("human");
  set_gender("female");
  set_level(20);
  set_hp(800);
  set_wc(19);
  set_ac(24);
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(30);
  set_a_chat_chance(20);
  set_dead_ob(this_object());
  load_chat("Laithyra kneels and whispers a prayer.\n");
  load_chat("Laithyra screams: Biln!  Help me!\n");
  load_chat("Laithyra sobs softly.\n");
  load_chat("Laithyra shudders.\n");
  load_chat("Laithyra says: These evil wizards must perish for their sins!\n");
  load_chat("Laithyra says: At least some of my prayers are still answered.\n");
  load_chat("Laithyra says: I must escape this horrible dungeon!\n");
  load_chat("Laithyra screams: Biln!  Why don't you answer me!?\n");
  load_a_chat("Laithyra screams: Damn you!\n");
  load_a_chat("Laithyra calls down the wrath of Biln on your worthless soul!\n");
  load_a_chat("Laithyra casts a spell of harming on you!\n");
  load_a_chat("Laithyra says: You fool!  Don't you see what you have done?\n");
  load_a_chat("Laithyra smacks you with her mace.\n");

  /*
   * The Demonbane Mace is a unique item and only one can exist at
   * any time.  If the Mace already exists then another weapon will
   * be cloned in its place.
   */
  if(sscanf(object_name(this_object()), "%s#%s", crap1, crap2) == 2) {
    if(!find_object("players/pavlik/weapons/ilstkarn/demonbane_mace")) {
      move_object(clone_object("players/pavlik/weapons/ilstkarn/demonbane_mace"),
      this_object());
    }
    else {
      move_object(clone_object("players/pavlik/weapons/white_mace"),
      this_object());
    }
  }

  if(!present("demonbane", this_object())) {
  set_long(
  "Laithyra is the loyal subject of Biln, a once powerful and arrogant\n"+
  "god.  When Biln ordered his minions to drive the evil wizards from\n"+
  "the mountain fortress of Arcydia, Laithrya was first to lead the\n"+
  "charge.  Her unmatched courage and overwhelming confidence landed her\n"+
  "here in these dark dungeons to rot for the rest of her days.  Not even\n"+
  "Biln could save her from this nexus of evil.\n");
  }

  sp = 300 + random(100);
  call_out("heal_them", 10+random(30));
  call_out("sp_heal", 10);
}

id(str) {
  return str == "laithyra" || str == "priestess" || str == "ilstkarn_monster"
  || str == "Laithyra" || str == "human" || str == "female";
}

query_sp(){ return sp; }
add_spell_point(i){ sp += i; if(sp < 0) sp = 0; if(sp > MAX) sp = MAX; }

sp_heal() {
  add_spell_point(5+random(10));
  call_out("sp_heal", 10);
  return 1;
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
 * This monster will occasionally heal players with good alignment.
 * She has Spell Points, like a player, and cannot heal anyone until
 * the spell points have recharged.
 */
heal_them() {
  object ob;
  int i, amt;

  /*
   * She gets pissed if someone attackes her.
   */
  if(query_attack()) {
    tell_room(environment(),
    "Laithyra summons a mighty bolt of lightning from the air!\n");
    ob = all_inventory(environment());
    for(i=0; i<sizeof(ob); i++) {
      if(living(ob[i]) && ob[i] != this_object()) {
        tell_object(ob[i],
        "The lightning bolt strikes you in the chest and electrecutes your body!!!\n");
        ob[i]->hit_player(random(50));
      }
    }
    call_out("heal_them", 10+random(20));
    return 1;
  }

  /*
   * Otherwise she may heal good players.
   */
  if(!random(4)) {
    ob = all_inventory(environment());
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->is_player() && ob[i]->query_alignment() >= 0) {
        tell_object(ob[i],
        "Laithyra tells you: Biln will still answer some of my prayers.\n"+
        "Laithyra tells you: Let me heal some of your wounds, Champion of good.\n");
        tell_object(ob[i],
        "The priestess casts a spell of healing on you.\n");
        amt = ob[i]->query_mhp() - ob[i]->query_hp();
        if(amt > sp) amt = sp;
        if(amt > 100) amt = 90 + random(30);
        ob[i]->heal_self(amt);
        add_spell_point(-amt);
      }
      else if(ob[i]->is_player() && ob[i]->query_alignment() < 0) {
        tell_object(ob[i],
        "Laithyra tells you: May the powers of Biln cleanse your evil soul!\n"+
        "Laithyra places a hand on your arm and you feel strange.\n");
        amt = random(50);
        ob[i]->add_spell_point(-amt);
        ob[i]->add_alignment(amt);
        add_spell_point(amt);
      }
    }
  }
  else {
    ob = all_inventory(environment());
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->is_player() && ob[i]->query_alignment() >= 0) {
        if(!random(2))
          tell_object(ob[i],
          "Laithyra tells you: Biln can still help us!\n"+
          "Laithyra tells you: I can heal you if you ask.\n");
        else
          tell_object(ob[i],
          "Laithyra tells you: Demonbane is a powerful weapon against black magic, but\n"+
          "it is nearly useless without its magical pummel.  We must find it!\n");
      }
      else if(ob[i]->is_player() && ob[i]->query_alignment() < 0) {
        tell_object(ob[i],
        "Laithyra tells you: Ask for forgiveness!  Biln will cleanse your soul!\n");
      }
    }
  }
  call_out("heal_them", 20+random(40));
  return 1;
}

monster_died() {
  tell_room(environment(),
  "Laithyra says: ....Biln....I....am.....coming...to...you......\n");
  if(this_player()->query_real_name())
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Priestess. ["+ctime()+"]\n");
  return 0;
}

/*
 * She will also heal good players that ask her to heal them.
 */
catch_tell(str) {
  string who;
  string tmp, tmp2, tmp3;
  int amt;

  if(!this_player()->is_player()) return 1;

  if(query_attack()) return 1;

  if(sscanf(str, "%s tells %s heal %s", tmp, tmp2, tmp3)!=3) {
    return 1;
  }

  if(this_player()->query_alignment() < 0) {
    write("Laithyra tells you: You must atone for your sins first!\n");
    return 1;
  }

  if(sp < 10) {
    write("Laithyra tells you: I cannot heal you now.  I must rest.\n");
    return 1;
  }

  write("Laithyra places her hand on you and mutters a prayer.\n");
  write("The soothing power of magic enters your body.\n");
  write("Laithyra smiles warmly.\n");
  say("Laithyra places her hand on "+ME+" and mutters a prayer.\n");
 
  amt = this_player()->query_mhp() - this_player()->query_hp();
  if(amt > sp) amt = sp;
  if(amt > 100) amt = 90+random(30);
  this_player()->heal_self(amt);
  sp -= amt;

  return 1;
}

