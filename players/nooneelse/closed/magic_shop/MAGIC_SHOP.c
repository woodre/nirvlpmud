/*
  magic_shop.c
*/

inherit "room/room";

object purchase_item;
string area_str, file_str, str, str2, str3;
int item_value;

init() {
  ::init();

  add_action("west",       "west");
  add_action("read_sign",  "read");
  add_action("read_sign",  "examine");
  add_action("read_sign",  "look");
  add_action("purchase",   "buy");
}

west() {
  if (!present("vampire fangs", this_player())) {
    write("Some demons appear to block the way, saying:\n"+
          "   Only vampires can use that exit!\n");
    return 1;
  }
  write("The demons appear, ready to block the way, but see your fangs\n"+
        "and allow you to pass.\n");
  return 0;
}

read_sign(str) {
  if (!str) return 0;
  str2=0;
  sscanf(str, "at %s", str2);
  if (!str2) str2=str;
  if (str2=="combat scrolls list") file_str="combat_scrolls_list";
  if (str2=="curse scrolls list") file_str="curse_scrolls_list";
  if (str2=="misc armor list") file_str="misc_armor_list";
  if (str2=="misc items list") file_str="misc_items_list";
  if (str2=="misc potions list") file_str="misc_potions_list";
/*
  if (str2=="misc scrolls list") file_str="misc_scrolls_list";
*/
  if (str2=="misc weapons list") file_str="misc_weapons_list";
/*
  if (str2=="protection list") file_str="protection_list";
*/
  if (str2=="rings list") file_str="rings_list";
  if (str2=="rod wand staff list") file_str="rod_wand_staff_list";
  if (str2=="summoning scrolls list") file_str="summoning_scrolls_list";

  if (present("vampire fangs", this_player())) file_str=file_str+"_v";
  cat(area_str+file_str);
  return 1;
}

check_cash() {
  /* vamp's discount */
  if (present("vampire fangs", this_player()))
    item_value = item_value - (item_value / 10);
  if (this_player()->query_money() < item_value) {
    write("That costs "+item_value+" gold coins, which you don't have.\n");
    return 1;
  }
}

purchase(str) {
  if (!str) {
    write("What'll you have friend?\n");
    return 1;
  }
  str2=0;

  /* combat scrolls */
  if (sscanf(str, "%s combat scroll", str2)==1) {
    if (str2=="firestorm") item_value=700;
    else
    if (str2=="icestorm") item_value=700;
    else
    if (str2=="lightning") item_value=500;
    else
    return 0;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"scroll_combat_curse");
    purchase_item->set_scroll_type(str2);
    purchase_item->set_scroll_value(item_value);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" scroll.\n");
    say(this_player()->query_name()+" purchases a "+str2+" scroll.\n",
      this_player());
    return 1;
  }

  /* curse scrolls */
  if (sscanf(str, "%s curse scroll", str2)==1) {
    if (str2=="death") item_value=30000;
    else
    if (str2=="fear") item_value=200;
    else
    if (str2=="paralysis") item_value=200;
    else
    if (str2=="force cube") item_value=500;
    else
    if (str2=="silence") item_value=200;
    else
      return 0;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"scroll_combat_curse");
    purchase_item->set_scroll_type(str2);
    purchase_item->set_scroll_value(item_value);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" scroll.\n");
    say(this_player()->query_name()+" purchases a "+str2+" scroll.\n",
      this_player());
    return 1;
  }

  /* misc armor */
  if (sscanf(str, "%s misc armor", str2)==1) {
    if (str2=="ruby slippers") item_value=500;
    else
    if (str2=="boots") item_value=2000;
    else
      return 0;
    if (check_cash()) return 1;
    if (str2=="ruby slippers")
      purchase_item=clone_object(area_str+"ruby_slippers");
    if (str2=="boots")
      purchase_item=clone_object(area_str+"boots_of_weightlessness");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+".\n");
    say(this_player()->query_name()+" purchases a "+str2+".\n", this_player());
    return 1;
  }

  /* misc items */
  if (sscanf(str, "%s misc item", str2)==1) {
    if (str2=="stone of alchemy") item_value=50;
    else
    if (str2=="chime of opening") item_value=300;
    else
    if (str2=="scroll of astral projection") item_value=500;
    else
    if (str2=="bomb") item_value=40000;
    else
      return 0;
    if (check_cash()) return 1;
    if (str2=="stone of alchemy")
      purchase_item=clone_object(area_str+"stone_of_alchemy");
    if (str2=="chime of opening")
      purchase_item=clone_object(area_str+"chime_of_opening");
    if (str2=="scroll of astral projection")
      purchase_item=clone_object(area_str+"scroll_astral_projection");
    if (str2=="bomb") purchase_item=clone_object(area_str+"bomb");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+".\n");
    say(this_player()->query_name()+" purchases a "+str2+".\n",
      this_player());
    return 1;
  }

  /* misc potions */
  if (sscanf(str, "%s misc potion", str2)==1) {
    if (str2=="haste") item_value=5000;
    else
    if (str2=="healing") item_value=10000;
    else
/*
    if (str2=="heroism") item_value=3000;
    else
*/
      return 0;
    if (check_cash()) return 1;
    if (str2=="haste")
      purchase_item=clone_object(area_str+"potion_haste");
    if (str2=="healing")
      purchase_item=clone_object(area_str+"potion_healing");
/*
    if (str2=="heroism")
      purchase_item=clone_object(area_str+"potion_heroism");
*/
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" potion.\n");
    say(this_player()->query_name()+" purchases a "+str2+" potion.\n",
      this_player());
    return 1;
  }

  /* misc scrolls */
/*
  if (sscanf(str, "%s misc scroll", str2)==1) {
    if (str2=="create wall") item_value=300;
    else
      return 0;
    if (check_cash()) return 1;
    if (str2=="create wall")
      purchase_item=clone_object(area_str+"scroll_create_wall");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" scroll.\n");
    say(this_player()->query_name()+" purchases a "+str2+" scroll.\n",
      this_player());
    return 1;
  }
*/

  /* misc weapons */
  if (sscanf(str, "%s misc weapon", str2)==1) {
    if (str2=="dragon slayer spear") item_value=12000;
    else
    if (str2=="giant slayer sword") item_value=10000;
    else
    if (str2=="staff of striking") item_value=7000;
    else
      return 0;
    if (check_cash()) return 1;
    if (str2=="dragon slayer spear")
      purchase_item=clone_object(area_str+"dragon_slayer_spear");
    if (str2=="giant slayer sword")
      purchase_item=clone_object(area_str+"giant_slayer_sword");
    if (str2=="staff of striking")
      purchase_item=clone_object(area_str+"staff_of_striking");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+".\n");
    say(this_player()->query_name()+" purchases a "+str2+".\n", this_player());
    return 1;
  }

  /* protection scrolls */
/* not sure how to make these work on nirvana
  if (sscanf(str, "%s protection scroll", str2)==1) {
    if (str2=="fire" || str2=="cold" || str2=="crushing" || str2=="magic")
      item_value=1000;
    else
      item_value=2000;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"protection_scroll_potion");
    purchase_item->set_spell_name(str2);
    purchase_item->set_item_value(item_value);
    purchase_item->set_this_is_a_scroll(1);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" scroll.\n");
    say(this_player()->query_name()+" purchases a "+str2+" scroll.\n",
      this_player());
    return 1;
  }

*/
  /* protection potions */
/*
  if (sscanf(str, "%s protection potion", str2)==1) {
    if (str2=="fire" || str2=="cold" || str2=="crushing" || str2=="magic")
      item_value=2000;
    else
      item_value=4000;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"protection_scroll_potion");
    purchase_item->set_spell_name(str2);
    purchase_item->set_item_value(item_value);
    purchase_item->set_this_is_a_scroll(0);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" potion.\n");
    say(this_player()->query_name()+" purchases a "+str2+" potion.\n",
      this_player());
    return 1;
  }
*/

  /* rings */
  if (sscanf(str, "%s ring", str2)==1) {
    if (str2=="enraging") item_value=50;
    else
/*
    if (str2=="magic resistance") item_value=10000;
    else
*/
      return 0;
    if (check_cash()) return 1;
    if (str2=="enraging")
      purchase_item=clone_object(area_str+"ring_enraging_monsters");
/*
    if (str2=="magic resistance")
      purchase_item=clone_object(area_str+"ring_magic_resistance");
*/
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" ring.\n");
    say(this_player()->query_name()+" purchases a "+str2+" ring.\n",
      this_player());
    return 1;
  }

  /* rods */
  if (sscanf(str, "%s rod", str2)==1) {
    if (str2=="magic missile") item_value=1000;
    else
    if (str2=="energy bolt") item_value=1000;
    else
    if (str2=="fireball") item_value=1000;
    else
    if (str2=="lightning bolt") item_value=1000;
    else
    if (str2=="illusion") item_value=1000;
    else
    if (str2=="polymorph") item_value=1000;
    else
      return 0;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"rod_wand_staff");
    purchase_item->set_item_value(item_value);
    purchase_item->set_spell_name(str2);
    purchase_item->set_this_is_a(0); /* rod */
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" rod.\n");
    say(this_player()->query_name()+" purchases a "+str2+" rod.\n",
      this_player());
    return 1;
  }

  /* wands */
  if (sscanf(str, "%s wand", str2)==1) {
    if (str2=="magic missile") item_value=3000;
    else
    if (str2=="energy bolt") item_value=3000;
    else
    if (str2=="fireball") item_value=3000;
    else
    if (str2=="lightning bolt") item_value=3000;
    else
    if (str2=="illusion") item_value=3000;
    else
    if (str2=="polymorph") item_value=3000;
    else
    if (str2=="anything") item_value=2400;
    else
      return 0;
    if (check_cash()) return 1;
    if (str2=="anything") {
      purchase_item=clone_object(area_str+"anything_wand");
    }
    else {
      purchase_item=clone_object(area_str+"rod_wand_staff");
      purchase_item->set_item_value(item_value);
      purchase_item->set_spell_name(str2);
      purchase_item->set_this_is_a(2); /* wand */
    }
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" wand.\n");
    say(this_player()->query_name()+" purchases a "+str2+" wand.\n",
      this_player());
    return 1;
  }

  /* staffs */
  if (sscanf(str, "%s staff", str2)==1) {
    if (str2=="magic missile") item_value=5000;
    else
    if (str2=="energy bolt") item_value=5000;
    else
    if (str2=="fireball") item_value=5000;
    else
    if (str2=="lightning bolt") item_value=5000;
    else
    if (str2=="illusion") item_value=5000;
    else
    if (str2=="polymorph") item_value=5000;
    else
      return 0;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"rod_wand_staff");
    purchase_item->set_item_value(item_value);
    purchase_item->set_spell_name(str2);
    purchase_item->set_this_is_a(1); /* staff */
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" staff.\n");
    say(this_player()->query_name()+" purchases a "+str2+" staff.\n",
      this_player());
    return 1;
  }

  /* summoning scrolls*/
  if (sscanf(str, "%s %s summoning scroll", str2, str3)==2) {
    if (str3=="elemental") {
      if (str2=="fire") item_value=1000;
      else
      if (str2=="water") item_value=1300;
      else
      if (str2=="earth") item_value=1600;
      else
      if (str2=="air") item_value=1900;
      else
        return 0;
    }
    else
    if (str3=="golem") {
      if (str2=="wood") item_value=3000;
      else
      if (str2=="earth") item_value=3300;
      else
      if (str2=="stone") item_value=3600;
      else
      if (str2=="iron") item_value=3900;
    }
    else
      return 0;
    if (check_cash()) return 1;
    purchase_item=clone_object(area_str+"scroll_summoning");
    purchase_item->set_elemental_type(str2);
    if (str3=="elemental")
      purchase_item->set_scroll_type(1); /* elemental */
    else
      purchase_item->set_scroll_type(2); /* golem */
    purchase_item->set_scroll_value(item_value);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - item_value);
    write("You pay "+item_value+" coins for a "+str2+" "+str3+
          " summoning scroll.\n");
    say(this_player()->query_name()+" purchases a "+str2+" "+str3+
        " summoning scroll.\n", this_player());
    return 1;
  }
  return 0;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc=("the Rainbow Inn Magic Shop");
  long_desc="         Welcome to the Rainbow Inn Magic Shop.\n\n"+
            "This small room is bare except for some lists tacked to the\n"+
            "wall, labeled:\n\n"+
            "        Combat Scrolls List\n"+
            "        Curse Scrolls List\n"+
            "        Misc Armor List\n"+
            "        Misc Items List\n"+
            "        Misc Potions List\n"+
            "        Misc Scrolls List\n"+
            "        Misc Weapons List\n"+
/*
            "        Protection List\n"+
*/
            "        Rings List\n"+
            "        Rod Wand Staff List\n"+
/*
            "        Summoning Scrolls List\n\n";
*/
            "\n       (You might want to try something like "+
            "'read misc weapons list'.)\n";
  items =
    ({
      "list", "Which one?",
    });
  dest_dir=
    ({
      "players/nooneelse/souvenir_shop", "east",
      "players/nooneelse/black/guild_shop", "west",
    });
  area_str="/players/nooneelse/closed/magic_shop/";
}
