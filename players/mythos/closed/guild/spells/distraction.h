#include "/players/mythos/closed/guild/def.h"
distraction() {
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 40) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 700) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(present("shadowcon",tp)) { write("You may not cast another distraction when another is in place!\n");
return 1;}
if(present("form_ob",tp)) { write("You may not cast distraction while shape changed!\n");
return 1;}
move_object(clone_object("/players/mythos/closed/guild/spells/discon.c"),tp);
command("shadow_me",tp);
tp->add_spell_point(-40);
pp->add_sacrifice(-700);
write("You concentrate for a minute, and a distraction forms...\n"+
      "Type <doff> to terminate the distraction.\n"+
      "Note: there is a time limit....\n");
say("There is a shimmering in the air....\n");
return 1;}
