#include "/players/pavlik/guild/mages/macs2"
#include "/players/pavlik/guild/mages/rooms/npc/MASTERS"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Yshir");
 set_alias("yshir");
 set_short("Yshir the Enchantress");
 set_long(
 "A translucent beauty of blue and gold Yshir the Enchantress\n"+
 "smiles upon you in your dream-like state.  Her long golden hair\n"+
 "flows over her shoulders and down her back. Her long blue and\n"+
 "gold gown sweeps quietly across the floor as she moves.\n"+
 "  Yshir holds a silver harp and a rose quartz in her hands.\n");
 set_level(100);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}

short(){
  if(random(2)==0) return "Yshir stands before you";
  else return "Yshir sits by your side";
}

init(){
 ::init();
 add_action("exa_object","exa");
 add_action("exa_object","examine");
 add_action("exa_object","see");
 add_action("exa_object","look");
}

exa_object(str) {
  if(str == "silver harp" || str == "rose quartz" ||
  str == "at silver harp" || str == "at rose quartz") {
    if(str == "at silver harp") str = "silver harp";
    if(str == "at rose quartz") str = "rose quartz";

    write("Yshir hands you the "+capitalize(str)+" so you can examine it.\n");
    write("There is a fine inscription carved into its side...\n");
    if(str == "silver harp") display_spell_list("conjuration");
    else display_spell_list("enchantment");
    write("You return the object to Yshir.\n");
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
    write("Yshir says:  You are not ready for more training.\n");
    return 1;
  }

  if(stat == "ench" || stat == "enchant" || stat == "enchantment") {
    if(PAV->stat_limit("ench")) return 1;
    what = "Enchantment";
  }
  else if(stat=="conj" || stat=="conjure" || stat=="conjuration") {
    if(PAV->stat_limit("conj")) return 1;
    what = "Conjuration";
  }
  else {
    write("Yshir says:  I cannot train you in "+stat+".\n");
    write("Yshir says:  I will train your "+CYN+"Conjuration"+NORM+
    " or "+CYN+"Enchantment"+NORM+" abilities.\n");
    return 1;
  }
  write(
  "You listen attentivly as Yshir instructs you in the ways of\n"+
  "magic.  The subtle nuances of magic seep into your mind as\n"+
  "you practice your spells again and again.\n");

  amt = PAV->stat_increase_amount("wil");

  write("Your "+what+" ability increases "+amt+"%.\n");
  if(what == "Enchantment") guild->raise_enchantment(amt);
  if(what == "Conjuration") guild->raise_conjuration(amt);
  guild->add_training_sessions(-1);

  return 1;
}

learn_spell(str) {
  string type, spell;
  int cost;

  if(sscanf(str, "%s says: teach %s\n", type, spell) !=2)
    return;

  if(!teachable_spell(spell, "conjuration") &&
     !teachable_spell(spell, "enchantment")) {
    write("Yshir says: I do not know of such a spell.\n");
    return 1;
  }

  cost = get_spell_cost(spell);
  type = get_spell_type(spell);

  if(!can_learn_spell(spell)) {
    say("Yshir says: You are not ready to learn this spell.\n");
    say("Yshir says: You must advance further before I will teach you this spell.\n");
    return 1;
  }

  if(KNOW(spell)) {
    write("Yshir says: But you already know this spell.\n");
    return 1;
  }

  if(!cost) {
    write("Yshir looks puzzled.\n");
    return 1;
  }

  if(guild->query_new_spells() < cost) {
    write("Yshir says: You are not prepared to learn such a spell.\n");
    return 1;
  }

  write("Yshir says: very well.  listen closely...\n");
  write("Yshir patiently teaches you the ways of magic.\n");

  if(PAV->spell_fail2(cost, type, "int")) {
    write(HIR+"You fail to understand.\n"+NORM);
    write("No spell is gained.\n");
    cost = cost / 2;
    if(cost < 1) cost = 1;
    guild->add_new_spells(-cost);
    return 1;
  }
  else {
    write("You scribe the spell into your spellbook.\n");
    write("You have learned a new spell!\n");
    guild->learn_spell(spell);
    guild->add_new_spells(-cost);
  }
  return 1;
}


