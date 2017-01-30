#include "/players/mythos/closed/guild/def.h"
night() {
object ob;
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 20) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 20) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob=clone_object("players/mythos/closed/guild/spells/night.c");
ob->set_owner(tpn);
tp->add_spell_point(-20);
pp->add_sacrifice(-20);
write("You call out for help....\n");
tell_room(environment(tp),"\nYou hear the flapping of wings....\n\n"+
                "A naked woman, of great beauty and \n"+
                "grace, flies in- great "+HIB+"RAVEN"+NORM+" wings beating...\n\n"+BOLD+
                "                 NIGHT HAS COME\n\n"+NORM);
move_object(ob,environment(tp));
pp->set_help(1);
pp->save_dark();
return 1;}
