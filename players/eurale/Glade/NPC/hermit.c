#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("hermit");
set_alias("hermit");
set_race("human");
set_short("Hermit");
set_long(
  "This short, sturdy looking man is hunched over from age and hard\n"+
  "work living in the forest alone.  His scraggly, gray-streaked hair\n"+
  "is matted and falls beyond his shoulders.  He has a full, gray\n"+
  "beard to match.  His, meaty hands are calloused from the hard work.\n"+
  "He wears clothing made from the hides of animals he's killed and\n"+
  "sewn together.  His yellowed, decaying teeth have chewed many a\n"+
  "pelt to keep him clothed over the cold seasons.\n");

set_level(18);
set_hp(450);
set_al(100);
  if(!present("metal tool")) {
    move_object(clone_object("players/eurale/Glade/OBJ/tool.c"),
      this_object()); }
  init_command("wield tool");
set_wc(26);
set_ac(15);
set_aggressive(0);

set_chat_chance(8);
  load_chat("The hermit mumbles, 'Darned rock crushers..'\n");
  load_chat("The hermit shuffles about the room.\n");
  load_chat("The hermit pokes the smouldering ashes with his metal tool.\n");
  load_chat("You feel the hermit sneak a glace at you to size you up.\n");
set_a_chat_chance(15);
  load_a_chat("   The hermit BITES at you with rotting teeth.\n");
  load_a_chat("   An uppercut just misses your chin.\n");
  load_a_chat("   PAIN as the hermit kicks you in the groin.\n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
  "	The hermit "+BOLD+"WHALLOPS"+NORM+
  " his target with his metal tool.\n\n");
set_spell_mess2(
  "	The hermit "+BOLD+"WHALLOPS"+NORM+
  " you with his metal tool.\n\n");

}
