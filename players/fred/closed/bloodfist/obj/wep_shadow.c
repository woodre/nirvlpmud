#include "/players/zeus/closed/all.h"

#define WEP_DAEMON "/players/fred/closed/bloodfist/daemon/wep_daemon"
#define DIR "/players/fred/closed/bloodfist/"
#define WAGL ((int)gob->query_attrib(0) + (int)gob->query_attribb(0))
#define WMIT ((int)gob->query_attrib(1) + (int)gob->query_attribb(1))
#define WACC ((int)gob->query_attrib(2) + (int)gob->query_attribb(2))
#define WVIG ((int)gob->query_attrib(3) + (int)gob->query_attribb(3))
#define WWIS ((int)gob->query_attrib(4) + (int)gob->query_attribb(4))
#define WFAI ((int)gob->query_attrib(5) + (int)gob->query_attribb(5))
#define USER environment(ths)

object ths, gob, ench, loc, ob, obj;
int wep_lvl, stype, forged, socket, o, so, p, base, mastery, charge;
int spec, ws, retrieve_delay, block, *simple, plunged, bonus;
string *gnames,a,b, me,nn,tt,he,col, *spec1, *spec2, *spec3, owner;
string *vtypes; /* vortex gem, mastery */

int bonusing; /* verte */

set_bloodfist_wep_shadow(object obj){
  ths = obj;
  gob = present("bloodfist_gob", USER);
  if(!USER)
  {
    write("Error, USER not defined.\n");
    return;
  }
  if(!gob)
  {
    write("Error, no guild object found.\n");
    return;
  }
  setup();
  shadow(ths,1);
}

rm_bloodfist_wep_shadow(){
/*  shadow(ths,0); */
  ths->unshadow();
  destruct(this_object());
  return 1;
}

query_forged(){ return forged; }
set_forged(){ forged = 1; }
query_bloodfist_wep_shadow(){ return 1; }
query_socketed(){ return (stype + spec); }  /* was sockted - 5/14/02 */
query_spec(){ return spec; }
query_ws(){ return ws; }
query_stype(){ return stype; }
set_socket(){ socket = 1; } /* NEW FUNC - 4-25-02 */
query_socket(){ return socket; } /* can wep be socketed */
int r(int x){  if(x) return random(x); }
string c(string x){  if(x) return capitalize(x); }
void add_charge(int x){ charge += x; }
void set_charge(int x){ charge = x; }
query_charge(){ return charge; }
void dec(){ retrieve_delay--; if(retrieve_delay > 0) call_out("dec", 1); }
void set_rd(int x){ retrieve_delay = x; block = 600; call_out("dec", 1); }
int query_rd(){ return retrieve_delay; }
void set_owner(string x){ owner = x; } /* if forged or thrown */
string query_owner(){ return owner; }  
void unlock(){ block = 0;  plunged = 0; }
void set_plunge(){ plunged = 1;  block = 1; }  /* plunge emote */


setup(){
  gnames =({ "crystal gem", "ruby gem", "emerald gem", "sapphire gem", 
    "diamond gem", "onyx gem", "topaz gem", "amethyst gem", 
  });

  spec1 =({ "crystal gem", "minor gem of agility", "minor gem of might", 
    "minor gem of accuracy", "minor gem of vigor", "minor gem of wisdom",
    "minor gem of faith", "prismatic gem", "gem of decay", "chaos gem",
    "gem of purity", "gem of hatred", "minor gem of performance",
    "gem of beauty", "gem of fury", "gem of eternity", "vortex gem",
    "lightning gem", "gem of unholy death rites", "gem of fortitude",
    "gem of moss", "gem of rain", "gem of idiocy", "gem of emotion",
    "minor gold gem", "minor gem of regeneration", 
    "minor gem of rejuvenation", "minor gem of restoration",
    "gem of instability", "faerie gem", "gem of pk", "gem of winter",
    "minor gem of cleansing", "gem of combat skills",
  });

  spec2 =({ "crystal gem", "gem of agility", "gem of might",
    "gem of accuracy", "gem of vigor", "gem of wisdom", "gem of faith",
    "soul gem", "gem of speed", "gem of performance", "blood gem",
    "sand gem", "ryo gem", "xetra gem", "gold gem", "angelic gem",
    "demonic gem", "gem of regeneration", "gem of rejuvenation",
    "gem of restoration", "gem of provoked aggression", "gem of the dragon",
    "gem of cleansing",
  });

  spec3 =({ "crystal gem", "major gem of agility", "major gem of might", 
    "major gem of accuracy", "major gem of vigor", "major gem of wisdom",
    "major gem of faith", "major gem of performance", "major gold gem",
    "gem of zeus", "holy angelic gem", "unholy demonic gem",
    "major gem of regeneration", "major gem of rejuvenation",
    "major gem of restoration", "minds eye gem", "gem of inescapable horror",
    "major gem of cleansing", "gem of battle rites", "sage gem",
    "timeless gem",
  });

  vtypes =({ "sword", "swords", "blade", "blades", "katana",
    "knife", "dagger", "polearm", "spear", "trident", "stick", "pole",
    "bow", "club", "staff", "mace", "morningstar", "axe", "hammer",
    "battleaxe" });

  /* simple gem ws's that only need a daemon call */
  simple =({ 7,8,9,13,15,16,17,18,21,23,25,26,27,29,31,32,
    7,8,10,12,13,15,16,17,18,19,21,22,10,11,12,13,14,15,16,17,20, });

  ws = 0;
  spec = 0;
  forged = 0;
}

get(){
  if(block)
  {
    if((string)this_player()->query_real_name() == owner)
      write(short()+" must be retrieved.\n");
    return 0;
  }
  else
    return 1;
}

query_save_flag(){ 
  if(forged) return 1; 
  else return (ths->query_save_flag());
}

wield(str)
{
  /*
  if(this_player()->query_real_name() != owner)
  {
    write("This weapon has been forged by another player.\n");
    return 1;
  }
  */
  if(environment(ths) != this_player())
    return 0;

  if(forged && TP->query_guild_name() != "bloodfist" && TP->query_level() < 21){
    write("This weapon has been forged for another player.\n");
    return 1;
  }
  if(this_player()->query_weapon() == ths) return 1;

  if(this_player()->query_weapon())
    this_player()->query_weapon()->stopwield();
    
  if(ths->wield(str)){
    if(this_player()->query_guild_name() != "bloodfist" && 
      this_player()->query_level() < 21){
      rm_bloodfist_wep_shadow(); 
      return 1;
    }

    if(!(gob = present("bloodfist_gob", this_player())))
      rm_bloodfist_wep_shadow();
    else
      WEP_DAEMON->wield_checks(gob,spec,ws);
    return 1; 
  }
}

query_value()
{
  if(forged) return 0; 
  else return (ths->query_value());
}

short(){
  string aqw, ns;
  if(aqw = c((string)ths->query_type())){}
  else aqw = c((string)ths->query_name());

  if(stype)
    ns = ths->short()+" ["+gnames[stype]+"]";
  else if(spec == 1 && ws == 18) /* gem of unholy death rites */
  {
    if(ths->query_wielded())
      ns = BOLD+BLK+"An Unholy "+aqw+" of Death"+NORM+" (wielded)";
    else if(ths->query_broken() && !ths->query_wielded())
      ns = BOLD+BLK+"An Unholy "+aqw+" of Death"+NORM+" [BROKEN]";
    else if(ths->query_broken() && ths->query_wielded())
      ns = BOLD+BLK+"An Unholy "+aqw+" of Death"+NORM+" [BROKEN] (wielded)";
    else
      ns = BOLD+BLK+"An Unholy "+aqw+" of Death"+NORM;
  }
  else if(spec == 1 && ws == 20) /* gem of moss */
  {
    if(ths->query_wielded())
      ns = ths->short()+" "+GRN+"(coated in moss)"+NORM;
    else if(ths->query_broken() && !ths->query_wielded())
      ns = ths->short()+" [BROKEN]"+GRN+" (coated in moss)"+NORM;
    else if(ths->query_broken() && ths->query_wielded())
      ns = ths->short()+" (wielded) [BROKEN]"+GRN+" (coated in moss)"+NORM;
    else
      ns = ths->short()+GRN+" (coated in moss)"+NORM;
  }
  else if(ws && spec == 1)
    ns = ths->short()+" ["+spec1[ws]+"]";
  else if(ws && spec == 2)
    ns = ths->short()+" ["+spec2[ws]+"]";
  else if(ws && spec == 3)
    ns = ths->short()+" ["+spec3[ws]+"]";
  else
    ns = ths->short();
  if(plunged)
    ns += " (protruding from the ground)";
  return ns;
}

long() {
  string aqw;
  ths->long(); 
  aqw = ((index(vtypes, ths->query_type()) < 0) ? "weapon" : ths->query_type());
  if(stype)
    write("This "+aqw+" has been socketed with a "+gnames[stype]+".\n");
  if(stype == 1)
    write("This "+aqw+" radiates with an aura of warmth.\n");
  else if(stype == 2)
    write("This "+aqw+" has a strange poison seeping from it.\n");
  else if(stype == 3)
    write("There is a coating of ice over this "+aqw+".\n");
  else if(stype == 4)
    write("This "+aqw+" emits a holy aura of strength.\n");
  else if(stype == 5)
    write("There is a subtle dark aura surrounding this "+aqw+".\n");
  else if(stype == 6)
    write("This "+aqw+" glows with an aura of pure light.\n");
  if(charge)
    write("This weapon has a charge of "+charge+".\n");
}

void socket(string x, int y, int z){
  if(!y && !z && (stype = index(gnames, x)) > -1){}
  else stype = 0;
  if(stype == 6)
     ths->set_wep_light(2);
  if(y && z){
    spec = y;
    ws = z;
  }
}

query_wear(){
  if((spec == 1 && ws == 19) || /* gem of fortitude */
    (spec == 3 && ws == 20))    /* timeless gem */
    return 1; 
  else 
    return ths->query_wear(); 
}

stopwield()
{
  if(environment(ths) != this_player()) return 0;
  ob = this_player()->query_weapon();
  if(ob->query_wielded())
    WEP_DAEMON->special_checks(gob,spec,ws);
  bonusing = 0;
  return ob->stopwield();
}

remove_object(){
  WEP_DAEMON->special_checks(gob,spec,ws);
}

drop(silently){
  if(environment(ths) != this_player()) return 0;
  if(ths->query_wielded())
    WEP_DAEMON->special_checks(gob,spec,ws);
  return ths->drop(silently);
}

xfer_special()
{
  call_other(environment(ths), "stop_wielding");
  ths->set_wielded(0);
  ths->set_wielded_by(0);
  return 1;
}

query_guild_bonus() { return "bloodFistVerteFix"; }

add_guild_bonus() {
  bonusing = 1;
}
remove_guild_bonus() {
 if(bonusing)
  stopwield();
}

swapped()
{
  WEP_DAEMON->wield_checks(gob,spec,ws);
}
