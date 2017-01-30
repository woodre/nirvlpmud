#include "/players/mythos/closed/guild/def.h"
misknowing(str) {
object ob;
string type, name, g, h;
int j, i;
if(!str) { write("Usage: knowing <type> <name>\n"); 
           write("Types: dir, mon, play\n"+
                 "      dir = direction <name = direction of choosing>\n"+
                 "      mon = monster  <name = name of monster>\n"+
                 "      play = player  <name = name of player>\n");
           return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 100) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(sscanf(str,"%s %s",type,name) != 2) { write("What?\n"); return 1;}
if(type != "mon" && type != "play" && type != "dir") {
  write("Type is not possible to know.\n"); return 1;}
if(type == "play") {
  ob = find_player(name);
  if(!ob) { write("That player is not on to know.\n"); return 1;}
  if(present("misknow",ob)) { 
  write(present("misknow",ob)->set_up());
  tell_object(ob,capitalize(tpn)+" has tried a knowing on you.\n"); }
  else {
  write("\n~\n");
  write("\n~ Short: "+ob->short()+"\n");
    write("~ Level: "+ob->query_level()+" +  "+ob->query_extra_level()+
          "    EXP: "+ob->query_exp()+"\n");
    write("~ Race: "+ob->query_race()+"    Guild: ");
    if(present(fear,ob)) { write("GUILD"); }
    else { write(ob->query_guild_name()); }
    write("    Wealth: "+ob->query_money()+"\n");
    if(ob->query_pregnancy()) { write("~ Pregnant: "+ob->query_pregnancy()+" / 16200\n");}
    if(ob->query_crime()) { write("~ CRIMINAL!\n"); }
    write("~ "+ob->show_age());
    if(ob->query_ghost()) { g = h = "DEAD"; }
    else {
    j = 100*(ob->query_hp())/(ob->query_mhp());
    i = 100*(ob->query_sp())/(ob->query_msp());
    if(j > 89) { g = "Excellent";}
    if(j < 90 && j > 49) { g = "Sound";}
    if(j < 50 && j > 24) { g = "Not Good"; }
    if(j > 9 && j < 25) { g = "Bad";}
    if(j < 10) { g = "Dire"; }
    if(i > 89) { h = "Excellent";}
    if(i < 90 && j > 49) { h = "Sound";}
    if(i < 50 && j > 24) { h = "Not Good"; }
    if(i > 9 && j < 25) { h = "Bad";}
    if(i < 10) { h = "Dire"; }
    }
    write("~ Health [Phys]: "+g+"     Health [Mental]: "+h+"\n");
    write("~ Where: "+environment(ob)->short()+"  Create: "+
          creator(environment(ob))+"\n");
    write("~");
    if( environment(ob)->realm() && environment(ob)->realm() == "NT") {
    write("   No-Teleport   "); }
    if( ob->query_fight_area() || ob->query_pl_k() || 
       present(fear,ob)->query_defence()) {
    write("   Play Kill   "); }
    write("\n~");
    j = ob->query_wc();
    i = query_ac();
    if(j > 19) { g = "Extremely Dangerous";}
    if(j > 16 && j < 20) { g = "Powerful";}
    if(j < 17 && j > 13) { g = "Strong";}
    if(j < 14 && j > 9) { g = "Okay";}
    if(j < 10 && j > 5) { g = "Mild"; }
    if(j < 6) { g = "Not";}
    if(i > 8) { h = "Extremely Tough";}
    if(i < 9 && i > 5) { h = "Tough";}
    if(i < 6 && i > 2) { h = "Mild";}
    if(i < 3) { h = "Not";}
    write("Offense: "+g+"     Defense: "+h+"\n");
    if(ob->query_weapon()) { write("~ Wielding: "+(ob->query_weapon())->short()+"\n"); }
    write("\n");
  }
  }
if(type == "mon") {
  ob = present(name,environment(tp));
  if(!ob) { ob = find_living(name); }
  if(!ob) { write("That monster is not in the mud fabric.\n"); return 1;}
  if(present("misknow",ob)) { 
  write(present("misknow",ob)->set_up()); } 
  else {
  write("\n~\n");
  write("\n~ Short: "+ob->short()+"\n");
    write("~ Level: "+ob->query_level()+"\n");
    write("~ Race: "+ob->query_race()+"    ");
    j = 100*(ob->query_hp())/(ob->query_mhp());
    i = ob->query_mhp();
    if(j > 89) { g = "Excellent";}
    if(j < 90 && j > 74) { g = "Sound";}
    if(j < 75 && j > 49) { g = "Okay";}
    if(j < 50 && j > 24) { g = "Not Good"; }
    if(j > 9 && j < 25) { g = "Bad";}
    if(j < 10) { g = "Dire"; }
    if(i > 1000) { h = "Godlike <1000~>";}
    if(i < 1001 && i > 800) { h = "Supernatural <800~1000>";}
    if(i < 801 && i > 600) { h = "Powerful <600~800>";}
    if(i < 601 && i > 400) { h = "Strong <400~600>";}
    if(i < 401 && i > 200) { h = "Above <200~400>";}
    if(i < 201 && i > 99) { h = "Average <100~200>";}
    if(i < 100) { h = "Low <~100>";}
    write("~ Health [Phys]: "+g+"     Range [Max]: "+h+"\n");
    write("~ Where: "+environment(ob)->short()+"  Create: "+
          creator(environment(ob))+"\n");
    write("~");
    if( environment(ob)->realm() && environment(ob)->realm() == "NT") {
    write("   No-Teleport   "); }
    write("\n~");
    j = ob->query_wc();
    i = query_ac();
    if(j > 45) { g = "Godlike";}
    if(j > 35 && j < 46) { g = "Supernatural";}
    if(j > 29 && j < 36) { g = "Extremely Dangerous";}
    if(j > 25 && j < 30) { g = "Powerful";}
    if(j < 26 && j > 19) { g = "Strong";}
    if(j < 20 && j > 14) { g = "Okay";}
    if(j < 15 && j > 10) { g = "Mild"; }
    if(j < 11) { g = "Not";}
    if(i > 20) { h = "Godlike";  }
    if(i > 16 && i < 21) { h = "Extremely Tough";}
    if(i < 17 && i > 12) { h = "Tough";}
    if(i < 13 && i > 4) { h = "Mild";}
    if(i < 5) { h = "Not";}
    write("Offense: "+g+"     Defense: "+h+"\n");
    if(ob->query_weapon()) { write("~ Wielding: "+(ob->query_weapon())->short()+"\n"); }
    write("\n");
  }
  }
  
if(type == "dir") {
  object ob2;
  ob = clone_object("/players/mythos/closed/guild/spells/searcher.c");
  ob->set_own(tpn);
  move_object(ob,environment(tp));
  ob2 = clone_object("/players/mythos/closed/guld/spells/searchcon.c");
  ob2->set_con(ob);
  move_object(ob2,tp);
  write("You now have a <control> for the searcher.\n");
  command(name,ob);
  }
say(capitalize(tpn)+" closes "+tp->query_possesive()+" eyes for a moment.\n");
tp->add_spell_point(-25);
pp->add_sacrifice(-100);
return 1;}
