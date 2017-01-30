#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("ryu");
  set_alias("dragon");
  set_race("beast");
  set_short("A Ryu- A Dragon of the Skies");
  set_long("A long wingless dragon.  Scales of metallic blue, and eyes\n"+
         "of deep green.  Teeth of deep blue and claws of ebony.  The \n"+
        "whiskers, that depict the fact that this is not a western dragon,\n"+
       "whip around in the wind.  Becareful, never attack a dragon without\n"+
        "caution.\n");
  set_hp(1500);
  set_level(25);
  set_al(-1000);
  set_wc(40);
  set_ac(20);
  set_heal(10,25);
  set_aggressive(0);
 
move_object(clone_object("/players/mythos/awep/forest/breath.c"),this_object());


  set_chat_chance(10);
  set_a_chat_chance(20);
  load_chat(CYN+"The Ryu flies up and does a quick spiral in the air.\n"+NORM);
  load_chat("The wind blows.....\n");
  load_chat(BLU+"Lightning flashes overhead!\n"+NORM);
  load_chat(BOLD+"The sky darkens....  it seems a storm is brewing...\n"+NORM);
  load_a_chat(HIB+"\tF  L  A  S  H\n"+NORM);
  load_a_chat(BOLD+"The Dragon roars!\n"+NORM);
  load_a_chat("Rain falls..\n");
  load_a_chat("THUNDER rumbles....\n");
  load_a_chat("The Ryu's claws rake across the body of its attacker!\n");
  load_a_chat("The Ryu bites down on its foe!\n");
  
  set_chance(35);
  set_spell_dam(random(75));
 set_spell_mess1("The Ryu seems to grin and whips its tail around- causing \n"+
	"great damage to all in its path!\n");
set_spell_mess2("The Ryu grins at you and whips its tail around.  You feel \n"+
	"great pain as the tail lashes across your body!\n");

  set_mass_chance(35);
  set_mass_dam(30);
  set_mass_spell(BOLD+"\n\tLightning floods the area!\n\n"+NORM+
                 BLU+ "\t^   ^   ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t ^   ^ ^ ^   ^  ^  ^   ^   ^ ^  ^\n"+
                      "\t  ^   ^   ^   ^ ^ ^   ^   ^   ^\n"+NORM+BLU+
                      "\t ^ ^   ^   ^   ^^^   ^   ^   ^ ^\n"+
                      "\t    ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t   ^   ^    ^ FLASH ^   ^   ^\n"+NORM+BLU+
                      "\t  ^     ^    ^  ^  ^     ^   ^\n"+
                      "\t   ^        ^   ^    ^   ^\n"+
                      "\t   ^            ^     ^ \n"+NORM+BLU+
                      "\t    ^            ^    ^\n"+
                      "\t                 ^\n"+NORM+"\n");
                      
}

#include "/players/mythos/amon/hb_ag.h"
