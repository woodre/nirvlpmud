/* Dark Rider Armor -Snow 3/00 */
inherit "/obj/armor.c";
string arm;
reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(5);
  switch(i) {
  case 1: arm = "gloves"; set_type("ring"); break;
  case 2: arm = "boots"; set_type("boots"); break;
  case 3: arm = "cloak"; set_type("misc"); break;
  case 4: arm = "hood"; set_type("helmet"); break;
  default: arm = "chainmail"; set_type("armor"); break;
  }
  set_name(arm);
  set_short("Dark Rider "+capitalize(arm));
  if(i == 1 || i == 2) {
    if(random(4)) {
      set_ac(1);
      set_value(random(500)+300);
      set_long("This well-crafted pair of "+arm+" was made by minions of the\n"+
               "Dark Lord Sauron. The "+arm+" are made of black leather and show\n"+
               "some wear.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long("This is a superbly-crafted pair of "+arm+". Dark mithral lines run\n"+
               "through the black leather, worked in shapes of dragons and spiders.\n");
      set_weight(2);
    }
  }
  if(i == 3 || i == 4) {
    if(random(4)) {
      set_ac(1);
      set_value(random(500)+300);
      set_long("This well-crafted "+arm+" was made by minions of the Dark Lord\n"+
               "Sauron. It is made of black leather and shows some wear.\n");
      set_weight(1);
    }
    else {
      set_ac(2);
      set_value(random(400)+1000);
      set_long("This is a superbly-crafted "+arm+". Dark mithral lines run\n"+
               "through the black leather, worked in shapes of dragons and\n"+
               "spiders.\n");
      set_weight(2);
    }
  }
  if(!i) {
    set_ac(random(4)+2);
    set_value(ac*500);
    if(ac < 5) {
      set_long("This is a suit of dark iron "+arm+". It was forged by smiths\n"+
               "of the Dark Lord Sauron. Its links are battered but remain\n"+
               "strong enough to resist most blows.\n");
      set_weight(ac);
    }
    else {
      set_long("This is a suit of dark mithral "+arm+". Its craftsmanship is\n"+
               "excellent and must be the work of dwarves enslaved by the \n"+
               "Dark Lord Sauron.\n");
      set_weight(random(2)+3);
    }
  }
  set_save_flag(1);
}
