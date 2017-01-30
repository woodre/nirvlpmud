#include "/players/mythos/bounty/def.h"
#define spd tp->add_spell_point(-(tp->query_msp()/2))
#define WEPFILE "/players/mythos/bounty/"+tpn+rnd_num+".c"

enhance(str) {
object targ, shadow;
int rnd_num;
string path,null;
string name,slay;
string type;
string check;
string gg;
int h,j;
  j = 0;
  rnd_num = random(66666);
  if(!bb) return 0;
  if(!str) { write("Usage: enhance <name of weapon> <name of slay type>\n"); return 1; }
  if(sscanf(str,"%s %s",name,slay) != 2) return 0;
  targ = present(name,tp);
  if(!targ) { write("You do not have that!\n"); return 1; }
  if(!targ->weapon_class()) { write("That is not a weapon!\n"); return 1;}
  if(targ->query_bounty_weapon()) {
    write("That has already been enhanced!\n");
  return 1; }
  check = call_other("/players/mythos/bounty/bounty.c","query_names",0);
  for(h=0;h<sizeof(check);h++) if(check[h] == slay) j = 1; 
  if(!j) {  write("That is not a slay type that is listed today.\n"); return 1; }
  if(tp->query_weapon() == targ) command("unwield weapon",tp);
  sscanf(targ,"%s#%s",path,null);
  if(targ->id("sword") || targ->id("blade") || targ->id("katana") ||
     targ->id("dagger") || targ->id("wakizashi") || targ->id("foil") ||
     targ->id("knife") || targ->id("rapier") || targ->id("saber") ||
     targ->id("epee") || targ->id("sabre")) type = "blade";
  else if(targ->id("spear") || targ->id("lance") || targ->id("halberd") ||
          targ->id("naginata") || targ->id("polearm")) type = "thrust";
  else if(targ->id("bow") || targ->id("gun") || targ->id("sling") ||
          targ->id("machine gun") || targ->id("launcher") ||
          targ->id("blaster") || targ->id("blowgun") || targ->id("longbow") ||
          targ->id("crossbow") || targ->id("shortbow") || targ->id("daikyu") ||
          targ->id("dart")) type = "distance";
  else type = "hand";
  if(path == "obj/weapon") {
  string hh;
    hh = targ->short();
    targ->set_hit_func(targ);
    shadow = clone_object("/players/mythos/bounty/spells/weap_shadow.c");
    shadow->start_weapon_shadow(targ);
    targ->set_type(type);
    targ->set_slay(slay);
    targ->set_form(formtype);
    targ->set_short_h(hh+RED+" ["+slay+" slayer]"+NORM);
  }
  else if(path == "players/mythos/closed/guild/spells/dwep") {
    targ->set_slayer(slay);
    targ->set_bounty();
  } else {
    gg = targ->short();
    write_file(WEPFILE,"#include ");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,"/players/mythos/bounty/spells/"+type+".h");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,";\n");
    write_file(WEPFILE,"inherit ");
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,path);
    write_file(WEPFILE,"\"");
    write_file(WEPFILE,";\n");
    write_file(WEPFILE,
       "short() { return "+gg+RED+" ["+slay+" slayer]"+NORM+"; }\n");
    shadow = clone_object(WEPFILE);
    shadow->set_slay(slay);
    shadow->set_form(formtype);
    move_object(shadow,tp);
    destruct(targ);
    rm(WEPFILE);
  }
  if(formtype == "tech") {
    write("You slide a small microchip into the base of the weapon.\n"+
          "The weapon glows red and a small voice speaks in your ear:\n"+RED+
          "      Smartlink activated. Target set to "+slay+"\n"+NORM);
    say(capitalize(tpn)+" slides a small chip into the base of a weapon.\n"+
        "The weapon glows with a red nimbus.\n");
  } else {
    write("Summoning POWER, with your forefinger you scribe the runes:\n"+
          "      "+RED+capitalize(slay)+" Slayer"+NORM+"\n"+
          "deep into the weapon.\n");
    say(capitalize(tpn)+" raises a glowing forefinger and\n"+
        "scribes something deep into a weapon.\n");
  }
  spd;
return 1; }
