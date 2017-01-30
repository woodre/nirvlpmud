/*
 souvenir_shop.c
*/

inherit "room/room";

object purchase_item, clerk;

string str, str2, armor_type, short_msg, long_msg, paint_color;

int cost, armor_class, weapon_class, weight;

init() {
  ::init();

  add_action("west",      "west");
  add_action("south",     "south");
  add_action("read_sign",  "read");
  add_action("purchase",   "buy");
}

west() {
  if (!present("nooneelse@vampire@fangs", this_player())) {
    write("Some demons appear to block the way, saying:\n"+
          "   Only vampires can use that exit!\n");
    return 1;
  }
  write("The demons appear, ready to block the way, but see your fangs\n"+
        "and allow you to pass.\n");
  return 0;
}

south() {
  if (this_player()->query_level() >= 35) return 0;
  write("Only wizards can enter the keep sales office at this time.\n");
  return 1;
}

read_sign(str) {
  if (!str) return;
  str2=0;
  sscanf(str, "at %s", str2);
  if (str=="sign" || str2=="sign") {
    command("look at sign", this_player());
    return 1;
  }
}

purchase(str) {
  if (!str) {
    write("What'll you have friend?\n");
    return 1;
  }
  if (str=="notepad") {
    if (this_player()->query_money() < 60) {
      write("That costs 60 gold coins, which you don't have.\n");
      return 1;
    }
    purchase_item=clone_object("players/nooneelse/obj/notepad");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - 60);
    write("You pay 60 coins for a pooper notepad.\n");
    say(this_player()->query_name()+" purchases a notepad.\n");
    return 1;
  }
  if (str=="pooper scooper" || str=="scooper") {
    if (this_player()->query_money() < 25) {
      write("That costs 25 gold coins, which you don't have.\n");
      return 1;
    }
    purchase_item=clone_object("players/nooneelse/obj/pooper_scooper");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - 25);
    write("You pay 25 coins for a pooper scooper.\n");
    say(this_player()->query_name()+" purchases a pooper scooper.\n");
    return 1;
  }
  if (str=="cookie" || str=="fortune cookie") {
    if (this_player()->query_money() < 10) {
      write("That costs 10 gold coins, which you don't have.\n");
      return 1;
    }
    purchase_item=clone_object("players/nooneelse/obj/fortune_cookie");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - 10);
    write("You pay 10 coins for a fortune cookie.\n");
    say(this_player()->query_name()+" purchases a fortune cookie.\n");
    return 1;
  }
  if (str=="ru784" || str=="RU784" || str=="abortion pill") {
    if (this_player()->query_money() < 1500) {
      write("That costs 1500 gold coins, which you don't have.\n");
      return 1;
    }
    purchase_item=clone_object("players/nooneelse/obj/ru784");
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - 1500);
    write("You pay 1500 coins for an RU784 abortion pill.\n");
    say(this_player()->query_name()+" purchases an RU784 abortion pill.\n");
    return 1;
  }
  if (str=="watch") {
    if (this_player()->query_money() < 10) {
      write("That costs 10 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 10);
    write("You pay 10 coins for a watch.\n");
    say(this_player()->query_name()+" purchases a watch.\n");
    move_object(clone_object("players/nooneelse/obj/watch"), this_player());
    return 1;
  }
  if (str=="camera") {
    if (this_player()->query_money() < 100) {
      write("That costs 100 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 100);
    write("You pay 100 coins for a camera.\n");
    say(this_player()->query_name()+" purchases a camera.\n");
    move_object(clone_object("players/nooneelse/obj/camera_poloroid"),
                this_player());
    return 1;
  }
  /* taken out because they can cause disconnect if someone has too many */
  if (str=="shirt1" || str=="shirt2") {
    write("Sorry, we are out of stock on those.\n");
    return 1;
  }
  if (str=="shirt1") {
    if (this_player()->query_money() < 25) {
      write("That costs 25 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 25);
    write("You pay 25 coins for a t-shirt with a small bat on it.\n");
    say(this_player()->query_name()+" purchases a t-shirt.\n");
    move_object(clone_object("players/nooneelse/obj/t_shirt"),
                this_player());
    return 1;
  }
  if (str=="shirt2") {
    if (this_player()->query_money() < 25) {
      write("That costs 25 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 25);
    write("You pay 25 coins for a t-shirt with a large bat on it.\n");
    say(this_player()->query_name()+" purchases a t-shirt.\n");
    move_object(clone_object("players/nooneelse/obj/t_shirt2"),
                this_player());
    return 1;
  }
  if (str=="slingshot") {
    if (this_player()->query_money() < 25) {
      write("That costs 25 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 25);
    write("You pay 25 coins for a slingshot.\n");
    say(this_player()->query_name()+" purchases a slingshot.\n");
    move_object(clone_object("players/nooneelse/obj/slingshot"), this_player());
    return 1;
  }
  if (str=="wimpy") {
    if (this_player()->query_money() < 10) {
      write("That costs 10 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 10);
    write("You pay 10 coins for a wimpy.\n");
    say(this_player()->query_name()+" purchases a wimpy.\n");
    move_object(clone_object("players/nooneelse/obj/programmable_wimpy"),
                this_player());
    return 1;
  }
  if (str=="stake") {
    weapon_class=2;
    weight=1;
    cost=1000;
    short_msg="sharp, heavy wooden stake";
    long_msg="sharp, heavy wooden stake.";
    purchase_weapon(str);
    return 1;
  }
  if (str=="communicator") {
    if (this_player()->query_money() < 300) {
      write("That costs 300 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 300);
    write("You pay 300 coins for a small box.\n");
    say(this_player()->query_name()+" purchases a small box.\n");
    move_object(clone_object("players/nooneelse/klingon/klingon_communicator"),
                this_player());
    return 1;
  }
  if (str=="ring") {
    if (this_player()->query_money() < 10) {
      write("That costs 10 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 10);
    write("You pay 10 coins for a moonstone ring.\n");
    say(this_player()->query_name()+" purchases a moonstone ring.\n");
    move_object(clone_object("players/nooneelse/obj/moonstone_ring"),
                this_player());
    return 1;
  }
  if (str=="tunic") {
    armor_class=1;
    weight=1;
    cost=150;
    armor_type="armor";
    short_msg="florescent pink tunic";
    long_msg="florescent pink tunic with large, bright green flowers\n"+
             "and embroidered with: 'Nooneelse's Nightmare!  A fun place!'";
    purchase_armor(str);
    return 1;
  }
/*
  if (str=="cloak") {
    armor_class=1;
    weight=2;
    cost=150;
    armor_type="cloak";
    short_msg="glaring yellow cloak";
    long_msg="glaring yellow cloak, with bright purple piping\n"+
             "and embroidered with: 'Nooneelse's Nightmare!  A fun place!'";
    purchase_armor(str);
    return 1;
  }
*/
  if (str=="sandals") {
    armor_class=1;
    weight=1;
    cost=150;
    armor_type="boots";
    short_msg="pair of flaring red sandals";
    long_msg="pair of flaring red sandals, with pea green highlights\n"+
             "and embroidered with: 'Nooneelse's Nightmare!  A fun place!'";
    purchase_armor(str);
    return 1;
  }
  str2=0;
  sscanf(str, "hamster %s", str2);
  if (str=="cage" || str2=="cage") {
    if (this_player()->query_money() < 500) {
      write("That costs 500 gold coins, which you don't have.\n");
      return 1;
    }
    call_other(this_player(), "add_money", - 500);
    write("You pay 500 coins for a small cage of hamsters.\n");
    say(this_player()->query_name()+" purchases a small cage.\n");
    move_object(clone_object("players/nooneelse/obj/hamster_cage"),
                this_player());
    return 1;
  }
  /* this has to be last, because of the way the sscanf works */
  if (sscanf(str, "%s paint", paint_color) != 1) return;
  if (paint_color) {
    if (this_player()->query_money() < 25) {
      write("That costs 25 gold coins, which you don't have.\n");
      return 1;
    }
    purchase_item=clone_object("/players/nooneelse/obj/bucket");
    purchase_item->set_bucket_color(paint_color);
    move_object(purchase_item, this_player());
    call_other(this_player(), "add_money", - 25);
    write("You pay 25 coins for a bucket of "+paint_color+" paint.\n");
    say(this_player()->query_name()+
        " purchases a bucket of "+paint_color+" paint.\n");
    return 1;
  }
  return;
}

purchase_weapon(str) {
  if (this_player()->query_money() < cost) {
    write("That costs "+cost+" gold coins, which you don't have.\n");
    return 1;
  }
  purchase_item=clone_object("obj/weapon");
  purchase_item->set_name(str);
  purchase_item->set_class(weapon_class);
  purchase_item->set_weight(weight);
  if (str=="stake")
    purchase_item->set_value(30);
  else
    purchase_item->set_value(cost);
  purchase_item->set_short("a "+short_msg);
  purchase_item->set_long("A "+long_msg+".\n");
  move_object(purchase_item, this_player());
  call_other(this_player(), "add_money", - cost);
  write("You pay "+cost+" for a "+short_msg+".\n");
  say(this_player()->query_name()+" purchases a "+short_msg+".\n");
  return 1;
}

purchase_armor(str) {
  if (this_player()->query_money() < cost) {
    write("That costs "+cost+" gold coins, which you don't have.\n");
    return 1;
  }
  purchase_item=clone_object("obj/armor");
  purchase_item->set_name(str);
  purchase_item->set_ac(armor_class);
  purchase_item->set_weight(weight);
  purchase_item->set_value(cost);
  purchase_item->set_short("a "+short_msg);
  purchase_item->set_long("A "+long_msg+".\n");
  purchase_item->set_type(armor_type);
  move_object(purchase_item, this_player());
  call_other(this_player(), "add_money", - cost);
  write("You pay "+cost+" for a "+short_msg+".\n");
  say(this_player()->query_name()+" purchases a "+short_msg+".\n");
  return 1;
}


reset(arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc=("the Rainbow Inn Souvenir Shop");
  long_desc="This is small room is bare except for a clerk and "+
            "a sign on the wall.\n";
  items =
    ({
      "sign",
"It's lights are so bright, they light up the entire room in a soft glow.\n\n"+
"         Welcome to the Rainbow Inn Souvenir Shop.\n\n"+
"...............................................................\n"+
":  notepad                                      :   60 coins  :\n"+
":  tunic                                        :  150 coins  :\n"+
/*
":  cloak                                        :  150 coins  :\n"+
*/
":  sandals                                      :  150 coins  :\n"+
":  pooper scooper                               :   25 coins  :\n"+
":  fortune cookie                               :   10 coins  :\n"+
":  watch                                        :   10 coins  :\n"+
":  camera                                       :  100 coins  :\n"+
":  slingshot                                    :   25 coins  :\n"+
":  bucket of paint (you select the color)       :   25 coins  :\n"+
":     Use: buy <color> paint                    :             :\n"+
":  wimpy  (a programmable wimpy)                :   10 coins  :\n"+
":  A rare stake (you can only sell it for 30!)  : 1000 coins  :\n"+
":  A strange device called a communicator       :  300 coins  :\n"+
/*
":  A Moonstone mood ring                        :   10 coins  :\n"+
*/
":  A t-shirt with a small bat on it (shirt1)    :   25 coins  :\n"+
":  A t-shirt with a large bat on it (shirt2)    :   25 coins  :\n"+
":  A cage of hamsters                           :  500 coins  :\n"+
":    (this one could nauseate some folks. be    :             :\n"+
":     you know what it is before buying)        :             :\n"+
":  An RU784 abortion pill                       : 1500 coins  :\n"+
"..............................................................",
    });
  dest_dir=
    ({
      "players/nooneelse/black/guild_shop", "west",
      "players/nooneelse/sign_note_office", "north",
      "players/nooneelse/restaurant", "east",
      "players/nooneelse/closed/keep/keep_sales_office", "south",
    });
  if(!present("clerk")) {
    clerk=clone_object("obj/monster");
    clerk->set_name("clerk");
    clerk->set_short("The clerk");
    clerk->set_long(
       "He's standing there with a hammer in his belt and a couple of nails\n"+
       "in his hand.  He looks like he's been doing some maintenance.\n");
    clerk->set_level(14);
    clerk->set_hp(125);
    clerk->set_wc(10);
    clerk->set_ac(5);
    clerk->set_short("The clerk");
    clerk->set_al(0);
    clerk->load_chat("The clerk says: Well?\n");
    clerk->load_chat("The clerk says: Humph!  You think you're good enough?\n");
    clerk->load_chat("The clerk says: Who made YOU a member?\n");
    clerk->set_chat_chance(15);
    clerk->load_a_chat("The clerk says: I've had enough of this!  Get out!\n");
    clerk->load_a_chat("The clerk says: I'm going to call the guard!\n");
    clerk->load_a_chat("The clerk says: I'll clobber you!\n");
    clerk->set_a_chat_chance(40);
    purchase_item=clone_object("obj/weapon");
    purchase_item->set_name("hammer");
    purchase_item->set_alias("mallet");
    purchase_item->set_class(10);
    purchase_item->set_weight(3);
    purchase_item->set_value(100);
    purchase_item->set_short("a heavy wooden hammer");
    purchase_item->set_long("It is a heavy wooden mallet.\n");
    move_object(purchase_item, clerk);
    move_object(clerk, this_object());
  }
}
