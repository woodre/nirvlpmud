#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object witch;

  if(!present("witch", this_object())){
    object broom;
    witch=clone_object("obj/monster");
    witch->set_name("witch");
    witch->set_level(19);
    witch->set_hp(400 + random(100));
    witch->set_wc(28);
    witch->set_ac(16);
    witch->set_short("A nasty witch");
    witch->set_long("The witches are not to be tampered with...\n");
    witch->set_al(-200);
    witch->set_chance(50);
    witch->set_spell_dam(75);
    witch->set_spell_mess1("The witch casts a lightning bolt!\n");
    witch->set_spell_mess2("The witch hurls a lightning bolt at you!\n");
    broom=clone_object("obj/weapon");
    broom->set_name("broom");
    broom->set_short("A broom");
    broom->set_long("This broom once belonged to a witch.\n");
    broom->set_class(12);
    broom->set_value(400);
    broom->set_weight(1);
    move_object(broom,witch);
    broom = clone_object("obj/money");
    broom->set_money(2000 + random(1500));
    move_object(broom, witch);
    move_object(witch,this_object());
  }
  if (arg)
    return;
  short_desc = "Walking in Darkwood";
  long_desc = 
"You are walking somewhere the Darkwood. It's almost pitch black.\n" +
"Are there any nasty monsters lurking around here?\n";
  dest_dir = ({
    "players/angmar/fairyland/dw_path4", "north",
  });
}

string realm() { return ("fairyland"); }
