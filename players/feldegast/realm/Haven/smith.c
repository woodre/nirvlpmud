
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("kager");
  set_alt_name("smith");
  set_alias("shopkeeper");
  set_short("Kager the Blacksmith");
  set_long(
"Kager is a hairless man with the strong muscles and thick limbs\n"+
"of a smith.  His face is constantly flushed a bright red pink\n"+
"and he usually wears a dirty old shirt with leggings and thick\n"+
"black boots while in his shop.\n"+
"You may have him: fix <weapon> or sharpen <weapon>\n");
  set_gender("male");
  set_race("human");
  set_level(18);
  set_wc(26);
  set_ac(15);
  set_hp(450+random(50));
  set_al(0);
}
init() {
  add_action("cmd_fix","fix");
  add_action("cmd_sharpen","sharpen");
}
cmd_fix(str) {
  object wep;
  if(!str) {
    write("Kager says: What weapon would you like me to fix?\n");
    return 1;
  }
  if(!(wep=present(str,this_player()))) {
    write("That weapon is not present.\n");
    return 1;
  }
  if(this_player()->query_money()<500) {
    write("Kager insists upon seeing your money up front, but you\n"+
    "don't have the necessary funds.\n");
    return 1;
  }
  if(!wep->query_broke()) {
    write("Kager says: Pardon, but that weapon is not broken.\n");
    return 1;
  }
  if(wep->query_wielded()) {
    command("unwield "+str,this_player());
  }
  this_player()->add_money(-500);
  wep->fix_weapon();
  write("Kager takes the broken pieces of the "+str+"\n"+
        "and uses his master crafsmanship to repair it.\n");
  write("He charges you 500 coins for the repair, a\n"+
  "bargain, really.\n");
  return 1;
}
cmd_sharpen(str) {
  object wep;
  int cost;
  if(!str) {
    write("Kager says: What weapon would you like me to sharpen?\n");
    return 1;
  }
  wep=present(str,this_player());
  if(!wep) {
    write("Kager says: I'm sorry, but you don't have that.\n");
    return 1;
  }
  if(wep->query_broke()) {
    write("Kager says: I cannot sharpen a broken weapon.\n");
    return 1;
  }
  cost=wep->query_wear()*5;
  if(this_player()->query_money()<cost) {
    write("Kager asks to see your money in advance, but you\n"+
      "don't have enough to pay him.\n");
   return 1;
  }
  wep->add_wear(wep->query_wear());
  write("Kager takes your "+str+" and works his skills\n"+
      "with grindstone and anvil to make your weapon look\n"+
         "almost like new.  You pay him "+cost+" coins for his\n"+
        "excellent service.\n");
  this_player()->add_money(-cost);
  return 1;
}
