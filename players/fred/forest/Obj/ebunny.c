#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("energizer bunny");
set_alias("bunny");
set_short("The Energizer Bunny "+BOLD+RED+"["+NORM+BOLD+"Going and Going and Going and Going"+RED+"]"+NORM);
set_long(
  "  This is the famous Energizer Bunny.  It's a cute little pink bunny\n"+
  "that just keeps going against all odds.  It holds a small little drum\n"+
  "and a baton in each hand.\n");
MO(CO("/players/fred/forest/Obj/drum.c"), TO);
MO(CO("/players/fred/forest/Obj/baton.c"), TO);
command("wear drum", TO);
set_race("creature");
set_level(25);
set_hp(10000);
set_al(0);
set_ac(30);
set_wc(5);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The Energizer Bunny taps the drum rythmically.\n");
  load_chat("The Energizer Bunny twirls the baton around his head like a helicopter.\n"); 
set_chance(20);
set_spell_dam(10);
set_spell_mess1("The Energizer Bunny thwaps it's attacker with a baton.\n");
set_spell_mess2("The Energizer Bunny thwaps you with a baton.\n");
}

  
