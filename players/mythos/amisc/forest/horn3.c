/*
 * players/mythos/amisc/forest/horn3.c
 * Adds +1 WC to a weapon
 *
 * Added check for broken weapon - Sparrow 2/24/2011
 * Added check for already used on weapon, and redid
 *       code to make it easier to read - Rumplemintz 4/08/2011
 */

#pragma strong_types  /* Rumplemintz */

inherit "obj/treasure";

#ifdef 0
void reset(status arg) {
  ::reset(arg);
  if(arg)
    return;
#endif
void reset() {
  set_id("horn");
  set_short("A beautiful horn");
  set_long("A horn off the head of a Kirin.\n\n"+
           "There seems to be something odd about this horn.\n"+
           "Perhaps if you 'tap'ped it on your 'weapon' something may "+
           "happen.\n");
  set_weight(4);
  set_value(2000);
}

void init() {
  ::init();
  add_action("tap","tap");
}

status tap(string str) {
  int pre_wc;
  object weapon;
  string wlong, wshort;

  if (!str) {
    write("What do you wish to tap?\n");
  }
  
  weapon = present(str, this_player());

  if (!weapon) {
    write("You do not have that.\n");
  }
  
  if (weapon->weapon_class() <= 0) {
    write(weapon->short() + " is not a weapon!\n");
    return 1;
  }
  
  /* [Sparrow 2/24/2011] Added following to avoid 'bug' granting extra
     wc if a broken weapon is tapped then fixed by samurai
  */
  if (weapon->query_broke()) {
    write("You try to tap your BROKEN weapon but the horn does nothing.\n");
    return 1;
  }

  /* Added following to only allow one application of the horn per weapon.
     Rumplemintz - 4/08/2011
  */
  if (weapon->id("horn_tapped")) {
    write("You tap the horn to " +
          weapon->short() + ", but nothing seems to happen.\n");
    return 1;
  }

  if ((string)weapon->query_name() == "cold") {
    write("The horn seems to rebel against the powers of the cold fire...\n");
    return 1;
  }
  
  pre_wc = (int)weapon->weapon_class();
  wlong = (string)weapon->query_long();
  wshort = (string)weapon->query_short();

  weapon->set_class(pre_wc + 1);
  weapon->set_weight(weapon->query_weight() + 2);
  weapon->add_id("horn_tapped");
  if (!wlong)
    weapon->set_long(wshort + "\nBlessed by the Kirin.\n");
  else
    weapon->set_long(wlong + "\nBlessed by the Kirin.\n");
  weapon->set_short(wshort + " (Blessed)");
  write(wshort +
        " glows and somehow you realize it has become a bit stronger.\n");
  if (weapon->query_wielded()) {
    command("unwield "+str,this_player());
    command("wield "+str,this_player());
  }
  write_file("/players/mythos/logs/horn",
             ctime(time()) + " " +
             this_player()->query_real_name() + "  " +
             object_name(weapon) + " wc: " + pre_wc + "->" +
             weapon->weapon_class() + "\n");
  destruct(this_object());
  return 1;
}

status nondup() { return 1; }  /* Not sure what this is, so leaving it.
                                  Rumplemintz */

