#include "/players/mythos/closed/guild/def.h"

flash_fire(str) {
int type, hitp, spellp, dam,dnum, click;
object targ;
string msg;
if(qtf < 17) { write("Your control over fae is not enough!\n"); return 1;}
if(!str) {
  write("Usage: flash <#> <extra>\n"+
        "  # ->  1 = single flash, 2 = multiple flashes, \n"+
        "        3 = flame\n"+
        "  single flash means that once attacked the flash_fire\n"+
        "  will go off causing attacker to lose half of its hp\n"+
        "  as will you.\n"+
        "  multiple flash means that once attacked all those in room\n"+
        "  (no players except in guild hall) will be reduced by a certain\n");
  write("  fraction of their hp <fraction is dependant on serveral things>\n"+
        "  and you will lose half of current hp or so.>\n"+
        "  flame is a controllable attack spell, where you can control\n"+
        "  how much damage is done by how much sp / hp you wish to use.\n"+
        "  if the # is 1 or 2 then no extra is needed\n"+
        "  if # is 3 then extra = # of hp # sp\n"+
        "    i.e.  flash 3 10 5 for flash type 3, 10 hp, 5 sp\n"+
        "          if 0 hp or 0 sp is wished to be used you must\n"+
        "          the 0\n"+
        "          i.e. flash 3 100 0 for 100 hp 0 sp\n"+
        "    note: might be a good idea to use aliases.\n"+
        "          i.e. alias ff flash 3\n"+
        "    also, in order to use more than 30 sp you must \n"+
        "          use at least sp/3 hp\n"+
        "          i.e. for 50 sp usage you need at least 17 hp\n"+
        "               for 33 sp you need at least 11 hp\n");
  return 1;
}
if(str) {
click = 0;
  if(sscanf(str,"%d %d %d",type,hitp,spellp) == 3) {
    if(type == 3) {
      if(!(tp->query_attack())) { 
        write("You must use this during combat!\n");
      return 1;}
      targ = tp->query_attack();
      if(tp->query_hp() < hitp || tp->query_sp() < spellp) {
        write("You do not have enough!\n");
      return 1;}
      if(scrp < 500) { write("The darkness calls for a sacrifice.\n"); return 1;}
      if(spellp > 30 && hitp < spellp/3) { 
        write("Note: in order to use more than 30 sp\n"+
              "      you must use sp/3 hp\n");
      return 1;}
      dam = hitp * 5/2 + random(spellp * 2);
      dnum = 0;
      if(dam > 20) dnum = 1;
      if(dam > 50) dnum = 2;
      if(dam > 75) dnum = 3;
      if(dam > 100) dnum = 4;
      if(dam > 150) dnum = 5;
      
      switch(dnum) {
        case 0: msg = "Cold Fire strikes "+capitalize(targ->query_name())+"\n"+
                      "The room suddenly feels cold..."; break;
        case 1: msg = HIB+"Cold Fire"+NORM+" erupts from the ground,\n"+
                      "surrounding "+capitalize(targ->query_name())+"!\n"+
                      "Death looms in the air...."; break;
        case 2: msg = HIB+"Cold Fire surrounds "+capitalize(targ->query_name())+"!\n"+
                      NORM+"Screams of agony resound through the room!\n"+
                      "The Fire vanishes...."; break;
        case 3: msg = capitalize(tpn)+" screams!\n"+
                      "Suddenly "+HIB+"Cold Fire"+NORM+" rains down on the enemy!\n"+
                      "Flesh burns, bones shatter, and blood freezes!"; break;
        case 4: msg = capitalize(tpn)+" raises a hand and \n"+HIB+"BoLtS of FLaMe"+
                      NORM+" smash into "+capitalize(targ->query_name())+"\n"+
                      "The air snaps with a large sound as all is frozen!"; break;
        case 5: msg = "Blood drips down "+capitalize(tpn)+"'s outstretched hand.\n"+
                      "Suddenly "+HIR+"BaleFire"+NORM+" lashes out from the hand,\n"+
                      "striking the enemy, smashing through its body!\n"+
                      capitalize(targ->query_name())+" screams!";
                      break;       }
      tell_room(environment(tp),msg+"\n");
      targ->heal_self(-dam);
      tp->add_hit_point(-hitp);
      tp->add_spell_point(-spellp);
      pp->add_sacrifice(-500);
      return 1;
    }
  }
    if(sscanf(str,"%d",type) == 1) {
      if(type == 1) {
        if(tsp < 200) { write("You do not have enough energy!\n"); return 1;}
        if(scrp < 3000) { write("The darkness calls for a sacrifice.\n"); return 1;}
        if(present("fire_field_1",tp)) { 
          write("You already have a fire field around you!\n");
        return 1;}
        if(tp->query_attack()) {
          write("You may not cast this during combat!\n");
         return 1;}
        move_object(clone_object("/players/mythos/closed/guild/spells/fire_field_1.c"),tp);
        tp->add_spell_point(-200);
        pp->add_sacrifice(-3000);
        write("Energies flare and the infinate is contacted.\n"+
              "A Fire Field materializes around you.\n");
        say("A crackling field of COLD FIRE surrounds "+capitalize(tpn)+".\n");
      return 1;}
      if(type == 2) {
         if(tsp < 200) { write("You do not have enough energy!\n"); return 1;}
         if(scrp < 3500) { write("The darkness calls for a sacrifice.\n"); return 1;}
         if(present("fire_field_2",tp)) { 
          write("You already have a flow field around you!\n");
        return 1;}
        if(tp->query_attack()) {
          write("You may not cast this during combat!\n");
         return 1;}
        move_object(clone_object("/players/mythos/closed/guild/spells/fire_field_2.c"),tp);
        tp->add_spell_point(-200);
        pp->add_sacrifice(-3500);
        write("You feel the Dark Fae seep into you and a flow field surrounds you.\n");
        say("A Dark Aura forms "+capitalize(tpn)+".\n");
      return 1;}
    return 1;}
    write("What?\n");
return 1;}
return 1;}
