#pragma strong_types

inherit "room/room";

int boxhere;
int fishhere;

void
reset(status arg) {
  boxhere=1;
  fishhere=1;
  if (!present("elfboy", this_object())){
    object elfboy;
    elfboy = clone_object("obj/monster");
    elfboy->set_name("elfboy");
    elfboy->set_level(1);
    elfboy->set_hp(15);
    elfboy->set_wc(5);
    elfboy->set_ac(3);
    elfboy->set_gender("male");
    elfboy->set_short("A fishing elfboy");
    elfboy->set_alias("boy");
    elfboy->set_al(300);
    elfboy->set_long(
"The elfboy doesn't seem to notice you. He is concentrating\n"+
"hard on his fishing.\n");
    elfboy->set_a_chat_chance(70);
    elfboy->load_a_chat("Elfboy cries: Noo! Please, don't kill me!\n");
    elfboy->load_a_chat("Elfboy says: Mummy! Mummy! Help! Help!\n");
    elfboy->load_a_chat("The boy is beating you furiously with his hands.\n");
    elfboy->load_a_chat("Elfboy says: Waaaaahh!\n");
    move_object(clone_object("players/angmar/o/fishing_rod"), elfboy);
    move_object(elfboy,this_object());
  }
  if (arg)
    return;
  short_desc = "In a clump of reeds";
  long_desc = 
"You trudge through the reeds, and find yourself in a small\n" +
"fishing area.  Reeds and other water plants have been cleared\n" +
"away to form a small spot to sit and fish, if you don't mind\n" +
"getting your pants wet.\n";
  dest_dir =  ({
    "players/angmar/fairyland/by_lake", "west",
  });
  items =  ({
    "plants", "All sorts of water plants, algae, and tubes grow here",
    "reeds", "Small green tubes, growing from the bottom of the lake",
    "bottom", "You search the bottom, but only find reed roots",
    "lake", "The lake is tranquil and calm; the perfect place to fish",
  });
}

status
fish() {
  if (boxhere) {
    move_object(clone_object("players/angmar/o/box"), this_object());
    write("You got something!\n");
    boxhere = 0;
    return 1;
  }
  if (fishhere) {
    move_object(clone_object("players/angmar/o/dead_fish"),this_object());
    write("You got something!\n");
    fishhere = 0;
    return 1;
  }
  write("No luck today.\n");
  return 1;
}

string realm() { return ("fairyland"); }

status     
Give(string str) {
  object boy,candy,rod;
  
  if (!str)
    return 0;
  if (str != "candy to elfboy" && str != "taffy to elfboy" &&
      str != "candy to boy" && str != "taffy to boy")
    return 0;
  else {
    candy = present("candy", this_player());
    if (!candy) {
      write("You do not have any candy.\n");
      return 1;
    }
    boy = present("elfboy", this_object());
    if (!boy) {
      write ("Give candy to whom?\n");
      return 1;
    }
    move_object(candy, environment(this_player()));
    destruct(candy);
    rod = present("rod", boy);
    move_object(rod, this_object());
    destruct(boy);
    say("The elfboy grins as " + this_player()->query_name() + 
        " gives him some candy.\n");
    write("Candy: Ok.\n");
    write("The elfboy grins as you give him some candy.\n");
    say("Throwing caution to the wind and his fishing rod to the ground, "+
        "he leaves.\n");
    return 1;
  }
}
