#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_alias("hobart");
set_race("invisible");
set_long(
  "invisible monsters rule\n");

set_level(20);
set_hp(10000);
set_al(0);
set_wc(30);
set_ac(15);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("A thousand voices whisper to you from the darkness.\n");
  load_chat("A soft wind blows against the hair on your arms.\n");
  load_chat("Rancid gusts of air blow through your clothing...softly calling...enticing...\n");
  load_chat("The Black Wind grows ever closer to you...it hungers for your blood.\n");
  load_chat("Your senses begin to weaken, your will grows weak...the voices call your name...\n");
  load_chat("Thoughts drift in your head.  A single soft voice calls out to you...Machin Shin.\n");
  load_chat("The ever-present evil of the ways seeps into you...your will begins to waver.\n");
  load_chat("Pervasive and persistent, the dark taint of the ways weakens your defenses.\n");
  load_chat("The ubiquitous voices search for you...beware the Machin Shin!\n");
  load_chat("Your mind is clouded by the evil of the ways...you are hopelessly lost!\n");
  load_chat("The ways are endless.  All become lost here...lost and alone.\n");
  load_chat("Somewhere in the distance, a bridge succcumbs to the corruption of the ways and falls.\n");
  load_chat("The stale, biting air of the ways begins to move about you...it is the Black Wind!\n");
  load_chat("Your thoughts drift to happier days under a sunny sky.\n");
  load_chat("A screeching howl of frustration and uncontrolled anger echos through the caverns...\n");
  load_chat("A piece of the island on which you stand breaks off and falls...\n");
  load_chat("The bridge to what might be the east is diseased and twisted...\n");
  load_chat("Something small and disgusting crawls across your foot\n");
  load_chat("Your vision becomes blurred making it difficult to read the signs...\n"); 

 }
