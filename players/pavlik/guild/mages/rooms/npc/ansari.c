#include "/players/pavlik/guild/mages/macs2"
#include "/players/pavlik/guild/mages/rooms/npc/MASTERS"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Ansari");
 set_alias("ansari");
 set_short("Ansari the Evoker");
 set_long(
 "Ansari stands nearly seven feet tall.  His long narrow limbs might\n"+
 "appear awkward on another body but they simple heighten the\n"+
 "subtle elegance of Ansari's nature.  His dark hands move gracefully\n"+
 "through the air as he speaks.  He is clothed in a simple robe of\n"+
 "green cloth and a golden earring twinkles from his left ear-lobe.\n"+
 "   Ansari holds an autumn leaf in his hand.\n");
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
 add_action("exa_leaf","exa");
 add_action("exa_leaf","examine");
 add_action("exa_leaf","see");
 add_action("exa_leaf","look");
}

exa_leaf(str) {
  if(str == "autumn leaf" || str == "at autumn leaf") {
    write("Ansari gives you an Autumn Leaf so you can examine it.\n");
    write("The delicate veins of the leaf create a writing...\n");
    display_spell_list("evocation");
    write("You return the leaf to Ansari.\n");
    say(ME+" examines Ansari's autumn leaf.\n");
    return 1;
  }
}

catch_tell(str) {
  string junk, junk2;
  string stat, what;
  int amt;

  if(sscanf(str, "%s says: train %s\n", junk, stat) != 2) {
    learn_spell(str);
    return;
  }
 
  if(!guild->query_training_sessions()) {
    say("Ansari says:  You are not ready for more training.\n");
    return 1;
  }

  if(stat == "evoc" || stat == "evocation"){
    if(PAV->stat_limit("evoc")) return 1;
    what = "Evocation";
  }
  else {
    say("Ansari says:  I cannot train you in "+stat+".\n");
    say("Ansari says:  I can only train your "+CYN+"evoc"+NORM+
    " ability.\n");
    return 1;
  }
  write(
  "Ansari says:  You must be able to sense the magic that each\n"+
  "object of our world possess.  Then you will be able to unite\n"+
  "the energies and create great things.  A good magician\n"+
  "listens to his senses.\n");
  say("Ansari teaches "+ME+" the ways of "+what+".\n");

  amt = PAV->stat_increase_amount("wil");

  write("Your "+what+" increases "+amt+"%.\n");
  if(what == "Evocation") guild->raise_evocation(amt);
  guild->add_training_sessions(-1);

  return 1;
}

learn_spell(str) {
  string type, spell;
  int cost;

  if(sscanf(str, "%s says: teach %s\n", type, spell) !=2)
    return;

  if(!teachable_spell(spell, "evocation")) {
    say("Ansari says: I do not know of such a spell.\n");
    return 1;
  }

  if(!can_learn_spell(spell)) {
    say("Ansari says: You are not ready to learn this spell.\n");
    return 1;
  }


  if(KNOW(spell)) {
    say("Ansari says: But you already know this spell.\n");
    return 1;
  }

  cost = get_spell_cost(spell);
  type = get_spell_type(spell);

  if(!cost) {
    say("Ansari looks puzzled.\n");
    return 1;
  }

  if(guild->query_new_spells() < cost) {
    say("Ansari says: You are not prepared to learn such a spell.\n");
    return 1;
  }

  write("Ansari gives you an Autumn Leaf.\n"+
  "The Master Evoker wisely teaches you the ways of magic.\n");
  say("Ansari teaches "+ME+" a new spell.\n");

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

