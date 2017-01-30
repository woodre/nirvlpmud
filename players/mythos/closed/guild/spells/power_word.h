#include "/players/mythos/closed/guild/def.h"
/*  This is a very powerful spell.. especially the symbol for death
 *  In the case of death , the player is killed in exchange for the 
 *  death of the opponent....   
 *                                                       - mythos   */
int ril;
object ak;
power_word(str) {
object ob, cycle, sees;
int qa;
string type;
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(!str) { write("Usage: symbol <type>\n"+
                 "Types: Just as you found this, find the key words.\n");
           return 1;}
if(str) {
  type = str;
  if(!(tp->query_attack())) { write("You may only use this during attack!\n"); return 1;}
  if(!((tp->query_attack())->query_npc()) && !dpp) {
    write("You may not use this on players at this time!\n");
    return 1;}
if((tp->query_attack())->id("tiamat")) { 
   tp->zap_object(tp); tp->zap_object(tp); tp->zap_object(tp); tp->zap_object(tp); return 1; }
  if(tp->query_attack()->query_level() > 20) {
    write("That monster is too high a level for this!\n");
    return 1;
  }
  if(type != "death" && type != "fear" && type != "insanity") {
     write("There is no symbol for that!\n");
     write("Your energies backfire!\n");
     tp->heal_self(-random(200));
     return 1;}
  ak = tp->query_attack();
  if(type == "death") {
  if(tl < 16) {
   write("The powers gained from the fae have overwhelmed you!\nYou die!\n");
    tp->zap_object(tp);
  return 1; }
  if(tsp < 100) { write("You do not have enough energy!\n"); return 1;}
    write("You summon up energies and cast forth the symbol of DEATH!\n");
    say(capitalize(tpn)+" raises a hand and points at "+ (tp->query_attack())->query_name()+"!\n");
    tell_room(environment(tp),BOLD+"D E A T H is here!\n"+NORM+"\n"+BOLD+
    "     #########################################\n"+NORM+BOLD+
    "              #                #              \n"+NORM+BOLD);
    tell_room(environment(tp),
    "             ###########       #              \n"+NORM+BOLD+
    "            #         #        #        #     \n"+NORM+BOLD);
    tell_room(environment(tp),
    "           # #       #         #       #      \n"+NORM+BOLD+
    "          #   ##    #          #     #        \n"+NORM+BOLD);
    tell_room(environment(tp),
    "                 ###           #    #         \n"+NORM+BOLD+
    "                  #            #  #           \n"+NORM+BOLD);
    tell_room(environment(tp),
    "               #               ##             \n"+NORM+BOLD+
    "             #                 #              \n"+NORM+BOLD);
    tell_room(environment(tp),
    "          #                    #              \n"+NORM+BOLD+
    "       #                       ############   s\n\n"+NORM);
    tell_room(environment(tp),"Lightning Flashes!!\n");
    ak->heal_self(-10000000);
    tp->lower_attrib();
    tp->lower_attrib();
    tp->add_exp(-10000 - random(100000));
    tp->zap_object(tp);
    return 1;}
  if(type == "fear") {
  if((tp->query_attack())->id("fear")) {
  write("The creature sucks up the powers of the fae before you cast that symbol!\n"); return 1; }
  if(tsp < 250) { write("You do not have enough energy!\n"); return 1;}
  if(scrp < 1500) { write("The darkness calls for a sacrifice.\n"); return 1;}
  sees = all_inventory(tp);
  for(qa = 0; qa < sizeof(sees); qa++) {
    if(sees[qa]->id("cycle")) {
      if(sees[qa]->query_who() == ak) {
      write("You are already linked to this creature.\n");
    return 1;}
    }
  }
  write("You close your eyes and concentrate on that\n"+
        "one symbol: the symbol for fear!\n");
  say(capitalize(tpn)+" concentrates and then calls out....!\n");
  tell_room(environment(tp),BOLD+"F E A R envelops the enemy!\n\n"+NORM+BOLD+
  "                          [^]                        \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                      [<<<<^>>>>]                    \n"+NORM+BOLD+
  "                     [<<<<<^>>>>>]                   \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                       [        ]                    \n"+NORM+BOLD+
  "                              ]                      \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                            ]                        \n"+NORM+BOLD+
  "                          [ <^> ]                    \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                         [       ]                   \n"+NORM+BOLD+
  "                                 ]                   \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                                ]                    \n"+NORM+BOLD+
  "                              ]                      \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                            ]                        \n"+NORM+BOLD+
  "                         [                           \n"+NORM+BOLD);
  tell_room(environment(tp),
  "                        [                            \n"+NORM+BOLD+
  "                        [                            \n"+NORM+BOLD+
  "                         '                           \n\n"+NORM);
  ril = ak->query_hp();
  tp->add_spell_point(-250);
  pp->add_sacrifice(-1500);
  
  cycle = clone_object("/players/mythos/closed/guild/spells/cycle.c");
  cycle->set_who(ak);
  cycle->set_start(ril);
  move_object(cycle,tp);
  cycle->begin();
  return 1;}
  if(tsp < 200) { write("You do not have enough energy!\n"); return 1;}
  if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
  if(type == "insanity") {
  write("You concentrate on your opponent and touch its mind!\n");
  say(capitalize(tpn)+" glares at the enemy.....\n");
  write("You shatter the mental processes of the enemy!\n");
  tell_room(environment(tp),BOLD+"\n\n         I N S A N I T Y rules!\n\n"+NORM);
  ak->attack_object(ak);
  tp->lower_attrib();
  tp->lower_attrib();
  tp->lower_attrib();
  tp->reset(1);
  tp->save_me();
  }
tp->add_spell_point(-200);
pp->add_sacrifice(-1000);
return 1;}
return 1;}
