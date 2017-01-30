#include "/players/mythos/closed/guild/def.h"
shatter(str) {
object ob;
string title;
if(!str) { write("Usage: shatter <object name>\n"); return 1;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 50) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = present(str,tp);
if(!ob) { ob = present(str,environment(tp));}
if(!ob) { write("That is not here!\n"); return 1;}
if(present("nm",ob)) { write("That is already shattered!\n"); return 1;}
if(living(ob)) { write("You may only effect non-living things!\n"); return 1;}
if(ob->query_shatter_proof() || ob->query_weight() < 1  || ob->query_auto_load() ||
   ob->drop() || !(ob->get())) { 
  write("You may not shatter that!\n"); return 1;}
tp->add_spell_point(-25);
pp->add_sacrifice(-50);
tell_room(environment(tp),BLU+"COLD FIRE"+NORM+" snakes out from "+capitalize(tpn)+
          " and strikes "+str+"- shattering it!\n");
write("You shatter "+str+" with your cold presence!\n");
if(ob->weapon_class()) { ob->weapon_breaks(); return 1;}
if(ob->armor_class()) {
        ob->set_ac(0);
        ob->set_value(0);
        title=ob->short();
        ob->set_short(title+" <broken>"); 
        move_object(clone_object("/players/mythos/closed/guild/spells/nm.c"),ob);
        return 1;}
ob->set_value(0);
title = ob->short();
ob->set_short(title+" <shattered>");
move_object(clone_object("/players/mythos/closed/guild/spells/nm.c"),ob);
ob->set_save_flag(0);
return 1;}
