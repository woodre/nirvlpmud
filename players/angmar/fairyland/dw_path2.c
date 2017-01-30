#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  object oak;
  if (!present("oak", this_object())){
    object branch;
    oak = clone_object("obj/monster");
    oak->set_name("oak");
    oak->set_level(18);
    oak->set_hp(350 + random(100));
    oak->set_wc(26);
    oak->set_ac(15);
    oak->set_chance(25);
    oak->set_spell_dam(60);
    oak->set_spell_mess1("The giant oak thrases it's branches wildly.\n");
    oak->set_spell_mess2("The giant oak thrashes you with it's bracnches.\n");
    oak->set_short("A big oak");
    oak->set_long(
"The oak is watching you with small gleaming eyes\n"+
"and waves it's branches menacingly.\n");
    oak->set_al(-200);
    oak->add_money(1000 + random(2500));
    branch=clone_object("obj/weapon");
    branch->set_name("branch");
    branch->set_short("A branch");
    branch->set_long("Seems to be a branch from an oak.\n");
    branch->set_class(13);
    branch->set_value(500);
    branch->set_weight(1);
    move_object(branch,oak);
    move_object(oak,this_object());
  }
  if (arg)
    return;
  short_desc = "On a path in Darkwood";
  long_desc = 
"You are walking on a twisty path in the legendary Darkwood.  You feel\n"+
"very uncomfortable.\n";
  dest_dir = ({
    "players/angmar/fairyland/dw_path3", "north",
    "players/angmar/fairyland/dw_path1", "south",
    "players/angmar/fairyland/darkwood1", "east",
  });
  items = ({
    "path", "The path twists and turns through Darkwood",
    "darkwood", "The forest gets more evil now, and light is frequently blocked by the trees",
  });
}

string realm() { return ("fairyland"); }
