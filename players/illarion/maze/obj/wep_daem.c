/* wep_daem.c

  Contains information about possible values for random/upgradable weapons
  

0: type: sword, axe, club, knife, polearm (from Templar types)
1: hands required
2: quality (base wc, durability)
3: experience (total hits by weapon)
4: enhancement (affects weapon_hit chance)
5: material
copper, bronze, iron, steel, mythril, gold, silver, platinum,
oricalchum, adamantium, molybendium, gromril, arcanium, ithilmar
6: color (cosmetic)
7: gem/element (Affects weapon_hit)
8: rune (Various effects)
9: name
swords:
1hand: katana, longsword, saber, shortsword, broadsword, rapier, falchion, khopesh
2hand: bastard sword, great sword, flamberge, zweihander, claymore
axes:
1hand: handaxe, battle axe, bearded axe, war axe
2hand: great axe, lochaber axe
clubs:
1hand: club, mace, flail, pick, cudgel, adze, war hammer, morning star, ball and chain, 
2hand: great hammer, great flail, mattock
knives:
1hand: knife, dagger, kukri, dirk, scramasax, main gauche, claw
polearm:
2hand: spear, halberd, quarterstaff, pike, lance, trident, voulge, naginata, lucerne 

*/

#include "/players/illarion/dfns.h"
#define TYPE wep_stats[0]
#define HANDS wep_stats[1]
#define QUALITY wep_stats[2]
#define EXPERIENCE wep_stats[3]
#define ENHANCEMENT wep_stats[4]
#define MATERIAL wep_stats[5]
#define COLOR wep_stats[6]
#define GEM wep_stats[7]
#define RUNE wep_stats[8]
#define WEPNAME wep_stats[9]

/* The higher this is the lower the chance of a special */
/* At 100, a player with 30 dex and a +10 weapon will have a 60%
   chance at a special
   
   The eventual effects of that special depend on other stats
   and the weapon type
 */
#define WEP_HIT_CHECK 100

#define WEP MAZEOBJ+"upgradable_weapon"

mapping wep_info;

void reset(status arg) {
  if(arg) return;
  if(!wep_info) {
    wep_info=([
    "types":({"sword","axe","club","knife","polearm"}),
    "materials":({"copper","bronze","iron","steel","mythril","gold","silver",
                  "platinum","oricalchum","adamantium","molybendium","gromril",
                  "arcanium","ithilmar"}),
    "sword1":({"longsword","shortsword","broadsword","gladius","rapier","sabre","scimitar","katana","falchion","khopesh"}),
    "sword2":({"bastard sword","great sword","flamberge","zweihander","claymore",}),
    "axe1":({"handaxe","bearded axe","war axe",}),
    "axe2":({"great axe","lochaber axe","battle axe",}),
    "club1":({"club","mace","flail","pick","cudgel","adze","morning star","ball and chain",}),
    "club2":({"great hammer","great flail","war hammer","mattock",}),
    "knife1":({"knife","dagger","kukri","dirk","scramasax","main gauche","claw"}),
    "knife2":0,
    "polearm1":0,
    "polearm2":({"spear","halberd","quarterstaff","pike","lance","trident","voulge","naginata","lucerne","staff"}),
    "quality":({1,"worthless",2,"worthless",3,"worthless",4,"worthless",5,"poor",6,"poor",7,"poor",8,"poor",9,"shoddy",
                10,"shoddy",11,"shoddy",12,"shoddy",13,"",
                14,"fine",15,"remarkable",16,"superior",17,"grand",18,"imperial",19,"flawless",20,"masterwork",}),
    "weight":({"sword1",3,"sword2",6,"axe1",4,"axe2",7,"club1",2,"club2",5,"knife1",1,"polearm2",8}),
    
    ]);
  }
}


string create_short(mixed *wep_stats) {
  string temp_short;
  string qual;
  qual=wep_info["quality"][member_array(QUALITY,wep_info["quality"])+1];
  if(qual && qual!="")
    qual+=" ";
  temp_short=qual+
    ((GEM && GEM != "")?GEM+" ":"")+
    ((COLOR && COLOR != "")?COLOR+" ":COLOR)+
    ((MATERIAL && MATERIAL != "")?MATERIAL+" ":"")+
    WEPNAME;
  if(ENHANCEMENT)
    temp_short+=" [+"+ENHANCEMENT+"]";
  if(member_array(temp_short[0..0],({"a","e","i","o","u"})) !=-1)
    temp_short="An "+temp_short;
  else
    temp_short="A "+temp_short;
  return temp_short;
}

void process_locker_init(string str) {
  mixed *wep_stats;
  wep_stats=explode(str,"^^^");
  sscanf(HANDS,"%d",HANDS);
  sscanf(QUALITY,"%d",QUALITY);
  sscanf(EXPERIENCE,"%d",EXPERIENCE);
  sscanf(ENHANCEMENT,"%d",ENHANCEMENT);
  previous_object()->set_stats(wep_stats);
}

void setup_weapon(mixed *wep_stats) {
  object wep;
  wep=previous_object();
  wep->set_type(TYPE);
  wep->set_class(QUALITY);
  wep->set_name(WEPNAME);
  wep->set_weight(wep_info["weight"][member_array(TYPE+HANDS,wep_info["weight"])+1]);
  wep->set_short(create_short(wep_stats));
  wep->set_long(format(
    "This is a "+TYPE+"-type weapon, requiring "+HANDS+" hands to wield. "+
    "Its appearance and attributes can be altered by the right kind of "+
    "blacksmith with coins and other special objects."));
  
}

varargs make_weapon(string type, int hands, int quality, int enhancement,
                    string material, string color, string name) {
  object wep;
  if(!type || !member_array(type,wep_info["types"]))
    type=wep_info["types"][random(sizeof(wep_info["types"]))];
  if(type=="knife")
    hands=1;
  else if(type=="polearm")
    hands=2;
  else if(hands<1 || hands > 2)
    hands=1+random(2);
  if(quality< 1 || quality > 20)
    quality=1+random(21);
  if(enhancement< 0 || enhancement> 10)
    enhancement=random(11);
  if(!material)
    material="";
  if(!color)
    color="";
  if(!name)
    name=wep_info[type+hands][random(sizeof(wep_info[type+hands]))];
  wep=clone_object(WEP);
  wep->set_stats(({type,hands,quality,0,enhancement,material,color,"","",name}));
  return wep;         
}

int weapon_hit(object wielder, object targ, mixed *wep_stats) {
  int wep_roll;
  wep_roll=random(WEP_HIT_CHECK);
  if(wep_roll < ENHANCEMENT*3 + (int)wielder->query_attrib("dex")) {
    write("You attack with commendable skill!\n");
  }  
}