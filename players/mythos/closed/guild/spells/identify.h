#include "/players/mythos/closed/guild/def.h"
identify(str) {
string wc, ac, save;
string obpath;
object ob;
if(!str) { 
write("Usage: identify <name>\n"); 
write("     Levels:         Armor    |   Weapons\n"+
      "                 ~~~~~~~~~~~~~|~~~~~~~~~~~~~\n");
write("                   Godlike    |   Godlike\n"+
      "                   Mighty     |    Mighty\n"+
      "                   Strong     |   Powerful\n"+
      "                    Good      |   Effective\n");
write("                    Okay      |     Good\n"+
      "                   Useless    |     Okay\n"+
      "                              |    Useless\n\n"+
      "Note: if it saves and is Godlike watchout,\n"+
      "      power has a price.\n");
return 1;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 150) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = present(str,tp);
if(!ob) { write("You do not have that.\n"); return 1;}
if(!(ob->weapon_class())) { wc = "Not a weapon"; }
else {
 if(ob->weapon_class() > 20) { wc = "Godlike"; }
 if(ob->weapon_class() > 18 && ob->weapon_class() < 21) { wc = "Mighty";}
 if(ob->weapon_class() > 16 && ob->weapon_class() < 19) { wc = "Powerful";}
 if(ob->weapon_class() > 13 && ob->weapon_class() < 17) { wc = "Effective";}
 if(ob->weapon_class() > 10 && ob->weapon_class() < 14) { wc = "Good";}
 if(ob->weapon_class() > 6 && ob->weapon_class() < 11) { wc = "Okay";}
 if(ob->weapon_class() < 7) { wc = "Usless";}
}
if(!(ob->armor_class())) { ac = "Not armor";}
else {
 if(ob->armor_class() > 4) { ac = "Godlike";}
 if(ob->armor_class() == 4) { ac = "Mighty";}
 if(ob->armor_class() == 3) { ac = "Strong";}
 if(ob->armor_class() == 2) { ac = "Good";}
 if(ob->armor_class() == 1) { ac = "Okay";}
 if(ob->armor_class() < 1) { ac = "Useless";}
}
if(ob->query_save_flag()) { save = "n";}
else { save = "y";}
    write("name:    "+ob->short()+"\n");
    write("wc:      "+wc+"\n");
    write("ac:      "+ac+"\n");
if(ob->armor_class()) {
    write("type:    "+ob->query_type()+"\n"); }
    write("weight:  "+ob->query_weight()+"\n");
    write("value:   "+ob->query_value()+"\n");
    write("save:    "+save+"\n");
tp->add_spell_point(-25);
pp->add_sacrifice(-150);
if(!(ob->query_save_flag()) && (ob->weapon_class() > 18 ||ob->armor_class() > 4 || 
(ob->armor_class() > 1 && ob->query_type() != "armor") ) ) {
  write_file("/players/mythos/logs/check",ctime(time())+" "+tpn+
   " ided "+ob->short()+": ");
  sscanf(ob,"%s",obpath);
    write_file("/players/mythos/check",obpath);
   write_file("/players/mythos/check","\n");
  }
return 1;}
