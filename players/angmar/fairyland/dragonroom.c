#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if(!present("dragon", this_object())){
    object diamond, dragon, chainmail;
    dragon = clone_object("obj/monster");
    dragon->set_name("dragon");
    dragon->set_level(18);
    dragon->set_hp(700);
    dragon->set_wc(35);
    dragon->set_ac(17);
    dragon->set_al(-200);
    dragon->set_short("A large ferocious red dragon");
    dragon->set_long(
"A huge dragon. His name is Smaug and is rumoured to be the last.\n"+
"of his kind. When you see him you really hope so. He looks like\n" +
"he usually eat folks like you whole, and that his intent is to\n"+
"prove it to you rather soon. He gives you a gaze that could\n"+
"melt stone.  Fumes come out of his nostrils in a way that\n"+
"makes you feel that this dragon is sure of himself. He has NO\n" +
"thoughts about losing a battle. His scars make you realize why.\n"+
"The feeling his gaze inflicts in you gives you an insight in the\n"+
"term \"premonition\".\n");
    dragon->set_alias("smaug");
    dragon->set_gender("male");
    dragon->set_spell_mess1("The dragon breathes fire!");
    dragon->set_spell_mess2("The dragon breathes fire at you!");
    dragon->set_chance(30);
    dragon->set_spell_dam(23);
    move_object(clone_object("players/angmar/o/platinum_ring"), dragon);
    chainmail=clone_object("obj/armor");
    chainmail->set_name("chainmail");
    chainmail->set_short("mithril chainmail");
    chainmail->set_long("It looks very light.\n");
    chainmail->set_alias("mithril chainmail");
    chainmail->set_value(3000);
    chainmail->set_weight(6);
    chainmail->set_ac(4);
    chainmail->set_type("armor");
    move_object(chainmail,dragon);
    move_object(dragon,this_object());
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "In the dragon's cave";
  long_desc = 
"This is where the great dragon lives and hoards his treasures.\n";
  dest_dir = ({
    "players/angmar/fairyland/tunnel", "south",
  });
  items = ({
    "treasures", "The usual things a dragon collects over a lifetime",
  });
}

string realm() { return ("fairyland"); }
