#include "/players/wocket/closed/ansi.h"
#include "../def.h"

string spell;
string spell_desc;
string spell_short;
string type;
string COLOR;

int size;
int time;
int spcost;
int hpcost;
int coincost;
int ppgain;

id(str){ return (str == spell || str == "spell"); }
short(){ get_color(type); return "A "+COLOR+spell_short+OFF+" spell ("+size+" pages)"; }
long() {
get_color(type);
  write("\n");
  write(YEL+"+-------------------------+\n\n"+OFF);
  write(COLOR+"  Spell name: "+OFF+capitalize(spell)+"\n");
  write(COLOR+"  School: "+OFF+convert(type)+"\n");
  write(COLOR+"  Description:\n"+NORM+spell_desc);
  write(COLOR+"  Cost: "+OFF);
  if(spcost) write(spcost+COLOR+" sp  "+OFF);
  if(hpcost) write(hpcost+COLOR+" hp  "+OFF);
  if(coincost) write(coincost+COLOR+" coins"+OFF);
  write(YEL+"\n\n+-------------------------+\n"+OFF);
  write(OFF+"\n");
}
get(){ notify_fail("You are shocked as the spell prevents you from touching it.\n");
       return 0; 
}
drop(){ return 0; }
weight(){ return 1; }

reset(){
  spell = "blank";
  spell_short = HIC+"blank"+NORM;
  spell_desc = "This is a blank page.\n";
  size = 1; 
  time = 0;
  spcost = 0;
  hpcost = 0;
  coincost = 0;
  ppgain = 0;
get_color();
}

init(){
  add_action("read","read");
}

read(str){
  if(str != "spell" && str != spell){
    notify_fail("What would you like to read?\n");
  return 0;
  }
  long();
  return 1;
}

query_spellname(){ return spell; }
query_type(){ return type; }
query_spcost(){ return spcost; }
query_hpcost(){ return hpcost; }
query_coincost(){ return coincost; }
query_time(){ return time; }
query_ppgain(){ return ppgain; }
query_magic_spell(){ return 1; }
query_w_spell(){ return 1; }
query_pages(){ return size; }

add_cost(object mage){
  if(mage){
    mage->add_hit_point(-hpcost);
    mage->add_spell_point(-spcost);
    mage->add_money(-coincost);
  }
}

get_color(str){
switch(str){
case "sor": COLOR = HIR; break;
case "nec": COLOR = HIM; break;
case "enc": COLOR = HIY; break;
case "sum": COLOR = HIB; break;
case "ill": COLOR = HIC; break;
case "gen": COLOR = CYN; break;
default: COLOR = HIC; break;
}
}

convert(str){
switch (str){
case "sor": return "Sorcery"; break;
case "nec": return "Necromancy"; break;
case "enc": return "Enchantment"; break;
case "sum": return "Summoning"; break;
case "ill": return "Illusionary"; break;
case "gen": return "Generalistic"; break;
default:    return "None"; break;
}
}