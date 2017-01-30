#include "/players/mythos/closed/guild/def.h"
knowing(str) {
object ob;
string type, name, g, h;
int j, i;
if(!str) { write("Usage: knowing <type> <name>\n"); 
           write("Types: dir, mon, play\n"+
                 "      mon = monster  <name = name of monster>\n"+
                 "      play = player  <name = name of player>\n");
           return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 100) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(sscanf(str,"%s %s",type,name) != 2) { write("What?\n"); return 1;}
if(type != "mon" && type != "play") {
  write("Type is not possible to know.\n"); return 1;}
if(type == "play") {
  ob = find_player(name);
  if(!ob) { write("That player is not on to know.\n"); return 1;}
  if(ob->query_invis() && ob->query_level() > 20) {
  write("That player is not on to know.\n"); return 1;}
  if(present("misknow",ob)) { 
  write(present("misknow",ob)->set_up());
  tell_object(ob,capitalize(tpn)+" has tried a knowing on you.\n"); }
  else {
  write("\n~\n");
  write("\n~ Short: "+ob->short()+"\n");
    write("~ Level: "+ob->query_level()+" + "+ob->query_extra_level()+"\n");
    write("~ Race: "+ob->query_race()+"  Guild: ");
    if(present(fear,ob)) { write("GUILD"); }
    else { write(ob->query_guild_name()); }
    if(ob->query_pregnancy()) { write("~ Pregnant\n");}
    if(ob->query_crime()) { write("~ CRIMINAL!\n"); }
    if(ob->query_ghost()) { g = h = "DEAD"; }
    write("\n~ Where: "+environment(ob)->short()+"  Create: "+
          creator(environment(ob))+"\n");
    if( environment(ob)->realm() && environment(ob)->realm() == "NT") {
    write("~ No-Teleport   \n"); }
    if( ob->query_fight_area() || ob->query_pl_k()) {
    write(HIR+"~ Play Kill   "+NORM+"\n"); }
    write("~");
    write("\n");
  }
  }
if(type == "mon") {
  ob = present(name,environment(tp));
  if(!ob) { write("That monster is not in front of you.\n"); return 1;}
  if(present("misknow",ob)) { 
  write(present("misknow",ob)->set_up()); } 
  else {
  write("\n~\n");
  write("\n~ Short: "+ob->short()+"\n");
    write("~ Level: "+ob->query_level()+"    ");
    write("Race: "+ob->query_race()+"\n");
    i = ob->query_mhp();
   if(i == 0) i = 1;
  j = 100*(ob->query_hp())/i;
    if(j > 89) { g = "Excellent";}
    if(j < 90 && j > 74) { g = "Sound";}
    if(j < 75 && j > 49) { g = "Okay";}
    if(j < 50 && j > 24) { g = "Not Good"; }
    if(j > 9 && j < 25) { g = "Bad";}
    if(j < 10) { g = "Dire"; }
    if(i > 1000) { h = "Godlike";}
    if(i < 1001 && i > 800) { h = "Supernatural";}
    if(i < 801 && i > 600) { h = "Powerful";}
    if(i < 601 && i > 400) { h = "Strong";}
    if(i < 401 && i > 200) { h = "Above";}
    if(i < 201 && i > 99) { h = "Average";}
    if(i < 100) { h = "Low";}
    write("~ Health [Phys]: "+g+"   Range [Max]: "+h+"\n");
    write("~ Where: "+environment(ob)->short()+"  Create: "+
          creator(environment(ob))+"\n");
    write("~");
    if( environment(ob)->realm() && environment(ob)->realm() == "NT") {
    write("   No-Teleport   \n~"); }
    j = ob->query_wc();
    i = ob->query_ac();
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
    write(" Offense: "+g+"   Defense: "+h+"\n");
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
  command("go "+name,tp);
  }
say(capitalize(tpn)+" closes "+tp->query_possessive()+" eyes for a moment.\n");
tp->add_spell_point(-25);
pp->add_sacrifice(-100);
return 1;}
