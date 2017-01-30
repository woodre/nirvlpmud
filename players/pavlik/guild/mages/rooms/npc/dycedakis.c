#include "/players/pavlik/guild/mages/macs2"
#include "/players/pavlik/guild/mages/rooms/npc/MASTERS"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Dycedakis");
 set_alias("dycedakis");
 set_short("Dycedakis the Black");
 set_long(
 "It is impossible to determine anything about Dycedakis because he\n"+
 "is completely obscured by spells of illusion and misdirection.  The\n"+
 "only constant feature is the sinister gaze of his dark eyes.\n"+
 "  Dycedakis holds a human skull and a handkerchief in his hands.\n");
 set_level(100);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}

init(){
 ::init();
 add_action("exa_object","exa");
 add_action("exa_object","examine");
 add_action("exa_object","see");
 add_action("exa_object","look");
 add_action("exa_object","l");
}

exa_object(str) {
  if(str == "human skull" || str == "handkerchief" ||
  str == "at human skull" || str == "at handkerchief") {
    if(str == "at human skull") str = "human skull";
    if(str == "at handkerchief") str = "handkerchief";
 
    write("Dycedakis gives you the "+capitalize(str)+" so you can examine it.\n");
    write("There is a fine inscription...\n");
    if(str == "human skull") display_spell_list("necromancy");
    else display_spell_list("illusion");
    write("You return the "+str+" to Dycedakis.\n");
    say(ME+" examines Dycedakis' "+capitalize(str)+".\n");
    return 1;
  }
}

catch_tell(str) {
  string type;
  string stat, what;
  int amt;

  if(sscanf(str, "%s says: train %s\n", type, stat) != 2) {
    learn_spell(str);
    return;
  }
 
  if(!guild->query_training_sessions()) {
    say("Dycedakis says:  Fool, You are not ready for more training.\n");
    return 1;
  }

  if(stat == "illu" || stat == "illusion") {
    if(PAV->stat_limit("illu")) return 1;
    what = "Illusion";
  }
  else if(stat == "necr" || stat == "necromancy") {
    if(PAV->stat_limit("necr")) return 1;
    what = "Necromancy";
  }
  else {
    say("Dycedakis says:  I cannot train you in "+stat+".\n");
    say("Dycedakis says:  I will train your "+HIR+"Illusion"+NORM+
    " or "+HIR+"Necromancy abilities"+NORM+".\n");
    return 1;
  }
  write(
  "Dycedakis says: Only fools would deny themselves the darker powers of\n"+
  "magic.  Even the purest soul casts a shadow.  You must show no fear\n"+
  "to these elements of magic!\n");
  say("Dycedakis teaches "+ME+" the ways of "+what+".\n");

  amt = PAV->stat_increase_amount("wil");

  write("Your "+what+" increases "+amt+"%.\n");
  if(what == "Illusion") guild->raise_illusion(amt);
  if(what == "Necromancy") guild->raise_necromancy(amt);
  guild->add_training_sessions(-1);

  return 1;
}

learn_spell(str) {
  string type, spell;
  int cost;

  if(sscanf(str, "%s says: teach %s\n", type, spell) !=2)
    return;

  if(!teachable_spell(spell, "illusion") &&
     !teachable_spell(spell, "necromancy")) {
    say("Dycedakis says: I do not know of such a spell.\n");
    return 1;
  }

  cost = get_spell_cost(spell);
  type = get_spell_type(spell);

  if(!can_learn_spell(spell)) {
    say("Dycedakis says: You are not ready to learn this spell.\n");
    say("Dycedakis says: You must advance further before I will teach you this spell.\n");
    return 1;
  }

  if(KNOW(spell)) {
    say("Dycedakis says: But you already know this spell.\n");
    return 1;
  }

  if(!cost) {
    say("Dycedakis looks puzzled.\n");
    return 1;
  }

  if(guild->query_new_spells() < cost) {
    say("Dycedakis says: You are not prepared to learn such a spell.\n");
    return 1;
  }

  write(
  "Dycedakis scowls at you with his dark eyes.\n"+
  "The Dark Master drills you relentlessly until you learn.\n");
  say("Dycedakis teaches "+ME+" a new spell.\n");

  if(PAV->spell_fail2(cost, type, "int")) {
    write(HIR+"You fail to understand.\n"+NORM);
    write("No spell is gained.\n");
    say(ME+" fails to learn the spell.\n");
    cost = cost / 2;
    if(cost < 1) cost = 1;
    guild->add_new_spells(-cost);
    return 1;
  }
  else {
    write("You scribe the spell into your spellbook.\n");
    write("You have learned a new spell!\n");
    say(ME+" scribes a new spell into his spellbook.\n");
    guild->learn_spell(spell);
    guild->add_new_spells(-cost);
  }
  return 1;
}


