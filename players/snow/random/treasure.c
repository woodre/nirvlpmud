/* Device to make random items of treasure */

id(str) { return str == "treasure object"; }

init() {
  add_action("gem","gem");
  add_action("wep","weapon");
  add_action("arm","armor");
  add_action("random_item","randomitem");
  }

random_item() {
  int rnum;
  rnum = random(3);
  if(rnum == 0) gem();
  if(rnum == 1) wep();
  if(rnum == 2) arm();
  return 1;
}

gem() {
  int boo;
  object gem;
  gem = clone_object("/obj/treasure.c");
  boo = random(6);
  if(boo == 0) {
    gem->set_id("topaz");
    gem->set_short("Topaz");
    gem->set_long("A topaz gemstone.\n");
    gem->set_value(random(300)+200);
   }
  if(boo == 1) {
    gem->set_id("opal");
    gem->set_short("Opal");
    gem->set_long("An opal gemstone.\n");
    gem->set_value(random(500)+300);
  }
  if(boo == 2) {
    gem->set_id("ruby");
    gem->set_short("Ruby");
    gem->set_long("A ruby gemstone.\n");
    gem->set_value(random(500)+500);
  }
  if(boo == 3) {
    gem->set_id("sapphire");
    gem->set_short("Sapphire");
    gem->set_long("A sapphire gemstone.\n");
    gem->set_value(random(500)+500);
  }
  if(boo == 4) {
    gem->set_id("emerald");
    gem->set_short("Emerald");
    gem->set_long("An emerald gemstone.\n");
    gem->set_value(random(500)+400);
  }
  if(boo == 5) {
    gem->set_id("diamond");
    gem->set_short("Diamond");
    gem->set_long("A diamond gemstone.\n");
    gem->set_value(random(500)+1000);
  }
  move_object(gem, environment(this_player()) );
  return 1;
}

wep() {
  int boo;
  object wep;
  wep = clone_object("/obj/weapon.c");
  boo = random(6);
  if(boo == 0) {
    wep->set_name("dagger");
    wep->set_alias("bronze dagger");
    wep->set_short("Bronze Dagger");
    wep->set_long("A sharp bronze dagger.\n");
    wep->set_class(8);
    wep->set_weight(1);
    wep->set_value(random(100)+100);
   }
  if(boo == 1) {
    wep->set_name("short sword");
    wep->set_alias("sword");
    wep->set_short("Short sword");
    wep->set_long("A short sword.\n");
    wep->set_class(10);
    wep->set_weight(1);
    wep->set_value(random(200)+200);
  }
  if(boo == 2) {
    wep->set_name("knife");
    wep->set_alias("rusty knife");
    wep->set_short("Rusty knife");
    wep->set_long("A rusty knife.\n");
    wep->set_class(6);
    wep->set_weight(1);
    wep->set_value(random(100)+50);
  }
  if(boo == 3) {
    wep->set_name("broadsword");
    wep->set_alias("decorated broadsword");
    wep->set_short("Decorated Broadsword");
    wep->set_long("A beautifully forged and decorated broadsword.\n");
    wep->set_class(16);
    wep->set_weight(2);
    wep->set_value(random(400)+600);
  }
  if(boo == 4) {
    wep->set_name("long spear");
    wep->set_alias("spear");
    wep->set_short("Long Spear");
    wep->set_long("An iron-tipped spear.\n");
    wep->set_class(14);
    wep->set_weight(3);
    wep->set_value(random(200)+200);
  }
  if(boo == 5) {
    wep->set_name("longsword");
    wep->set_alias("sword");
    wep->set_short("Longsword");
    wep->set_long("A well-crafted longsword.\n");
    wep->set_weight(2);
    wep->set_class(16);
    wep->set_value(random(300)+500);
  }
  move_object(wep, environment(this_player()) );
  return 1;
}

arm() {
  int boo;
  object arm;
  arm = clone_object("/obj/armor.c");
  boo = random(6);
  if(boo == 0) {
    arm->set_name("wooden shield");
    arm->set_alias("shield");
    arm->set_short("Wooden Shield");
    arm->set_long("A wooden shield.\n");
    arm->set_ac(1);
    arm->set_type("shield");
    arm->set_weight(1);
    arm->set_value(random(100)+100);
   }
  if(boo == 1) {
    arm->set_name("bronze helmet");
    arm->set_alias("helmet");
    arm->set_short("Bronze helmet");
    arm->set_long("A bronze helmet.\n");
    arm->set_ac(1);
    arm->set_type("helmet");
    arm->set_weight(1);
    arm->set_value(random(200)+200);
  }
  if(boo == 2) {
    arm->set_name("bracers");
    arm->set_alias("steel bracers");
    arm->set_short("Steel Bracers");
    arm->set_long("A pair of steel bracers.\n");
    arm->set_ac(1);
    arm->set_type("ring");
    arm->set_weight(1);
    arm->set_value(random(100)+300);
  }
  if(boo == 3) {
    arm->set_name("iron breastplate");
    arm->set_alias("breastplate");
    arm->set_short("Iron breastplate");
    arm->set_long("A well-wrought iron breastplate.\n");
    arm->set_ac(3);
    arm->set_type("armor");
    arm->set_weight(4);
    arm->set_value(random(400)+700);
  }
  if(boo == 4) {
    arm->set_name("leather boots");
    arm->set_alias("boots");
    arm->set_short("Leather boots");
    arm->set_long("An pair of leather boots.\n");
    arm->set_ac(1);
    arm->set_type("boots");
    arm->set_weight(1);
    arm->set_value(random(200)+200);
  }
  if(boo == 5) {
    arm->set_name("leather cloak");
    arm->set_alias("cloak");
    arm->set_short("Leather cloak");
    arm->set_long("A nice leather cloak.\n");
    arm->set_ac(1);
    arm->set_type("misc");
    arm->set_weight(2);
    arm->set_value(random(300)+500);
  }
  move_object(arm, environment(this_player()) );
  return 1;
}
 
