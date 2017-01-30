#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object oak;
  if (!present("oak", this_object())) {
    oak = clone_object("obj/monster");
    oak->set_name("oak");
    oak->set_level(19);
    oak->set_hp(400 + random(100));
    oak->set_wc(28);
    oak->set_ac(16);
    oak->set_chance(50);
    oak->set_spell_dam(40);
    oak->set_spell_mess1("The giant oak thrases it's branches wildly.\n");
    oak->set_spell_mess2("The giant oak thrashes you with it's bracnches.\n");
    oak->set_short("A giant oak");
    oak->set_long(
"The oak is following your movements with its eyes.\n"+
"Maybe you should leave while you can.\n");
    oak->set_al(-200);
    oak->add_money(500 + random(4000));
    move_object(oak,this_object());
  }
  if (arg)
    return;
  short_desc = "You are deep inside Darkwood";
  long_desc = 
"You are deep inside Darkwood.  You wish you had never come here.\n";
  dest_dir = ({
    "players/angmar/fairyland/dw_path5", "south",
    "players/angmar/fairyland/darkwood3", "east",
  });
}

string realm() { return ("fairyland"); }
