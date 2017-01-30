/*
 dim.c
*/

inherit "room/room";

object maitre_d, coins, amulet;

string str, str2, what;

init() {
  ::init();

  add_action("touch",         "touch");
  add_action("north",         "north");
  add_action("read",          "read");
  add_action("kill_maitre_d", "kill");
  add_action("kill_maitre_d", "hit");
  add_action("kill_maitre_d", "slap");
  add_action("kill_maitre_d", "kick");
  add_action("kill_maitre_d", "spit");
}

north(str) {
  if (str) return;
  if (!present("nooneelseamulet", this_player())) {
    write("A large maitre d' appears and bars your way, saying:  "+
          "Members only!\n");
    say("A large maitre d' appears and bars "+this_player()->query_name()+
        "'s way, saying:  Members only!\n");
    return 1;
  }
  what = this_player()->query_gender();
  if (what=="male") what="Sir";
  if (what=="female") what="Madam";
  if (what=="creature") what="Creature";
  write("A large maitre d' appears to greet you, saying:  Welcome, "+
        what+".\n");
  say("A large maitre d' appears to greet "+this_player()->query_name()+
      ", saying:  Welcome, "+what+".\n");
  return;
}

touch(str) {
  if (!str) {
    write("Touch what?\n");
    return 1;
  }
  if (str=="image" || str=="amulet" || str=="mirror") {
    write("Touch which image?\n");
    return 1;
  }
  if (sscanf(str,"%s image",what)==1) {
    if (what!="red" &&
        what!="green" &&
        what!="black" &&
        what!="blue") {
      write("None of them is wearing a "+what+" amulet.\n");
      return 1;
    }
    make_amulet(what);
    write(
      "The image you selected reaches out and touches your forehead.\n"+
      "The instant you are touched, you feel something around you change.\n\n");
    this_player()->move_player("north#players/nooneelse/" + what + "entry");
    return 1;
  }
  if (sscanf(str,"%s reflection",what)==1) {
    if (what!="red" &&
        what!="green" &&
        what!="black" &&
        what!="blue") {
      write("None of them is wearing a "+what+" amulet.\n");
      return 1;
    }
    make_amulet(what);
    write(
      "The reflection you selected reaches out and touches your forehead.\n"+
      "The instant you are touched, you feel something around you change.\n\n");
    this_player()->move_player("north#players/nooneelse/" + what + "entry");
    return 1;
  }
  if (sscanf(str,"%s amulet",what)==1) {
    if (what!="red" &&
        what!="green" &&
        what!="black" &&
        what!="blue") {
      write("None of them is wearing a "+what+" amulet.\n");
      return 1;
    }
    make_amulet(what);
    write(
      "The image wearing the amulet you selected reaches out and\n"+
      "touches your forehead!\n"+
      "The instant you are touched, you feel something around you change.\n\n");
    this_player()->move_player("north#players/nooneelse/" + what + "entry");
    return 1;
  }
  if (str=="red") {
    write("Touch the red what?\n");
    return 1;
  }
  if (str=="green") {
    write("Touch the green what?\n");
    return 1;
  }
  if (str=="black") {
    write("Touch the black what?\n");
    return 1;
  }
  if (str=="blue") {
    write("Touch the blue what?\n");
    return 1;
  }
  return;
}

read(str) {
  if (!str) return;
  str2=0;
  sscanf(str,"at %s", str2);
  if (str=="sign" || str2=="sign") {
    command("look at sign", this_player());
    return 1;
  }
}

kill_maitre_d(str) {
  if (!str) return;
  if (!str=="maitre d" && !str=="waiter") return;
  maitre_d=present("maitre d");
  if(!maitre_d) {
    maitre_d=clone_object("obj/monster");
    maitre_d->set_name("maitre d");
    maitre_d->set_level(7); /*14*/
    maitre_d->set_hp(200);  /*125*/
    maitre_d->set_wc(14);   /*10*/
    maitre_d->set_ac(6);    /*5*/
    maitre_d->set_short("The maitre d");
    maitre_d->set_al(0);
    maitre_d->load_a_chat(
        "The maitre d' says: If you're not a member, get out!\n");
    maitre_d->load_a_chat("The maitre d' says: I'm going to call the guard!\n");
    maitre_d->load_a_chat("The maitre d' says: I'll clobber you!\n");
    maitre_d->load_a_chat("The maitre d' says: Knock it off bub!\n");
    maitre_d->load_a_chat(
      "The maitre d' says: What do you think you're doing?\n");
    maitre_d->load_a_chat(
        "The maitre d' slaps you with his reservation list.\n");
    maitre_d->set_a_chat_chance(40);
    maitre_d->attacked_by(this_player());
    coins=clone_object("obj/money");
    coins->set_money(300);
    move_object(coins, maitre_d);
    move_object(maitre_d, this_object());
    return 1;
  }
  return;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("misty area");
  no_castle_flag=1;
  long_desc=
"You are almost blinded by the reflection of the light from the\n"+
"walls.  They look like one continuous mirror.  You can see several\n"+
"images of yourself!  Each is wearing a different colored amulet.\n"+
"The amulets are red, green, black, and blue.  All of your reflections\n"+
"are looking directly at you and they all look menacing.\n\n"+
"The images are really sharp.  You could reach out and touch an image.\n"+
"To the north there is a discrete sign next to the doorway.\n"+
"To the south is an open doorway through which you can see a violet mist.\n\n";
  items =
    ({
      "mirror", "All you see is the images with the amulets.",
      "mirrors", "All you see is the images with the amulets.",
      "wall", "All you see is the images with the amulets.",
      "walls", "All you see is the images with the amulets.",
      "images", "They all look like you.",
      "image", "They all look like you.",
      "yellow amulet", "It is a yellow 2 inch rectanglular amulet.",
      "red amulet", "It is a red 2 inch rectanglular amulet.",
      "green amulet", "It is a green 2 inch rectanglular amulet.",
      "black amulet", "It is a black 2 inch rectanglular amulet.",
      "blue amulet", "It is a blue 2 inch rectanglular amulet.",
      "yellow image", "It is a reflection of you wearing a yellow amulet.",
      "red image", "It is a reflection of you wearing a red amulet.",
      "green image", "It is a reflection of you wearing a green amulet.",
      "black image", "It is a reflection of you wearing a black amulet.",
      "blue image", "It is a reflection of you wearing a blue amulet.",
      "yellow reflection", "It is a reflection of you wearing a yellow amulet.",
      "red reflection", "It is a reflection of you wearing a red amulet.",
      "green reflection", "It is a reflection of you wearing a green amulet.",
      "black reflection", "It is a reflection of you wearing a black amulet.",
      "blue reflection", "It is a reflection of you wearing a blue amulet.",
      "maitre d", "He's standing there sneering at you & looking bored.",
      "sign", "   ..............................\n"+
              "   :                            :\n"+
              "   :    The Rainbow Club Inn    :\n"+
              "   :                            :\n"+
              "   :                            :\n"+
              "   :              (members only):\n"+
              "   ..............................",
    });
  dest_dir=
    ({
      "players/nooneelse/mist", "south",
      "players/eurale/VAMPIRES/RMS/souvenir_shop","north",
    });
}

make_amulet(what) {
  if (present("nooneelseamulet", this_player())) return 1;
  amulet=clone_object("/players/nooneelse/obj/amulet");
  amulet->set_amulet_color(what);
  transfer(amulet, this_player());
  write("You receive an amulet from the image.\n");
}
