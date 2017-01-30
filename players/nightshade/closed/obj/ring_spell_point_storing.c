inherit "obj/armor";
int stored;
reset(arg) {
::reset(arg);
if(arg) return;
  set_name("ring of spell storing");
  set_alias("ring");
  set_short("Ring of spell storing");
  set_weight(1);
  set_value(5000);
  set_ac(1);
  set_type("ring");
}

init() {
::init();
  add_action("store_spell","store");
  add_action("restore_spell","restore");
}
long() {
write("The magical ring was enchanted to store magical energy until\n"
+ "it is need. The ring is able to store up to 200 spell points.\n");
write(" <store> [amount], or <store> -> store all your sp.\n");
write(" <restore> [amount], or <restore> -> restore to your max.\n");
write(" Spell points stored: " +stored+ "\n");
  return 1;
}

store_spell(amt) {
int am;
int SP;
int not;
SP = this_player()->query_spell_point();
  if(!amt) {
    write("You store all your spell points into the ring.\n");
    say(this_player()->query_name()+ "'s ring glows brightly.\n");
    stored = stored + this_player()->query_spell_point();
    if(stored > 200) not = stored - 200;
    if(stored > 200) stored = 200;
    this_player()->add_spell_point(-SP);
    this_player()->add_spell_point(not);
    return 1;
  }
  sscanf(amt, "%d", am);
  if(am < 0) {
    write("What ?\n");
    return 1;
  }
  if(this_player()->query_spell_point() < am) {
    write("You do not have that much spelll points!\n");
    return 1;
  }
  stored = stored + am;
  if(stored > 200) {
    stored = 200;
  }
  write("You stored "+am+" spell points into the ring.\n");
  say(this_player()->query_name()+ "'s ring glows brightly.\n");
  this_player()->add_spell_point(-am);
  return 1;
}

restore_spell(amt) {
int am, SP;
SP = this_player()->query_spell_point();
  if(!amt) {
    if(stored < 1) {
      write("The ring does not have any spell points stored.\n");
      return 1;
    }
    am = this_player()->query_msp() - SP;
    if(stored < am) {
      this_player()->add_spell_point(stored);
      stored = 0;
    write("You drain all the spell points from the ring.\n");
      return 1;
    }
    this_player()->add_spell_point(am);
    stored = stored - am;
    write("You restore your spell points to the max.\n");
    return 1;
  }
  sscanf(amt, "%d", am);
  if(stored < am) {
    write("The ring does not have that many spell points!\n");
    return 1;
  }
  this_player()->add_spell_point(am);
  stored = stored - am;
  write("You restore your spell points from the ring.\n");
  return 1;
}

