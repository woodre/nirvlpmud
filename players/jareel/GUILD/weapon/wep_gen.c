#include "/players/jareel/ansi.h"
#define PATH "/players/maledicta/weapon/powers/"

reset(arg){
 if(arg) return;
 }

id(str){ return str == "weapon_daemon"; }

get_wep(object ob, int bonus){
string type;    /* Type of wep */
string nn;      /* name of the wep */
string pre;     /* prefix */
string suf;     /* suffix */
string sufp;    /* Path of suffix */
int wgt;        /* Weight */
int wc;         /* Weapon class of the wep */
int vl;         /* Value */
int nb;         /* No break? */
int th;         /* Two handed? */
int rwc;        /* Random Wc */
int rchance;    /* Chance of the bonus */
int abonus;   
int cbonus;
object wep;
string short;
string long;
string quality;
string npath;

abonus = bonus;
if(abonus < 1000) return 0;
abonus /= 1000;
if(abonus > 100) abonus = 100;

 switch(random(100) + 1){
 case 1..10:  nn = "sword"; vl = 100; wgt = 2; wc = 14; type = "sword"; break;
 case 11..13: nn = "shortsword"; vl = 50; wgt = 1; wc = 13; type = "sword"; break;
 case 14..22: nn = "longsword"; vl = 120; wgt = 2; wc = 14; type = "sword"; break;
 case 23..25: nn = "axe"; vl = 60; wgt = 2; wc = 14; type = "axe"; break;
 case 26..32: nn = "battleaxe"; vl = 200; wgt = 3; wc = 15; type = "axe"; break;
 case 33..40: nn = "mace"; vl = 80; wgt = 2; wc = 14; type = "club"; break;
 case 41..43: nn = "hammer"; vl = 60; wgt = 2; wc = 14; type = "club"; break;
 case 44..52: nn = "warhammer"; vl = 150; wgt = 3; wc = 15; th = 1; type = "hammer"; break;
 case 53..56: nn = "spear"; vl = 60; wgt = 3; wc = 14; th = 1; type = "polearm"; break;
 case 57..58: nn = "halberd"; vl = 250; wgt = 4; wc = 16; th = 1; type = "polearm"; break;
 case 59..60: nn = "knife"; vl = 20; wgt = 1; wc = 12; type = "dagger"; break;
 case 61..67: nn = "dagger"; vl = 25; wgt = 1; wc = 12; type = "dagger"; break;
 case 68..76: nn = "club"; vl = 30; wgt = 1; wc = 12; type = "club"; break;
 case 77..84: nn = "staff"; vl = 60; wgt = 2; wc = 13; th = 1; type = "polearm"; break;
 case 85..91: nn = "trident"; vl = 120; wgt = 3; wc = 15; th = 1; type = "polearm"; break;
 case 92:     nn = "greatsword"; vl = 200; wgt = 3; wc = 15; th = 1; type = "sword"; break;
 case 93:     nn = "flail"; vl = 100; wgt = 2; wc = 14; type = "club"; break;
 case 94:     nn = "morningstar"; vl = 100; wgt = 2; wc = 14; type = "club"; break;
 case 95:     nn = "rapier"; vl = 95; wgt = 2; wc = 14; type = "sword"; break;
 case 96:     nn = "katana"; vl = 450; wgt = 2; wc = 14; type = "sword"; break;
 case 97:     nn = "wakazashi"; vl = 200; wgt = 1; wc = 13; type = "sword"; break;
 case 98:     nn = "naginata"; 600; wgt = 3; wc = 15; th = 1; type = "polearm"; break;
 case 99:     nn = "scimitar"; vl = 120; wgt = 2; wc = 14; type = "sword"; break;
 case 100:    nn = "scythe"; vl = 120; wgt = 3; wc = 15; th = 1; type = "polearm"; break;
 }  

if(random(100) < abonus){
switch(random(abonus) + random(20) + 2){
case 119..120: pre = "King's";  wc += 4; vl *= 10; nb = 1; break;
case 117..118: pre = HIW+"Mithril"+NORM; vl *= 40; vl += 10000; wc += 3; wgt -= 1; nb = 1; break;
case 110..116: pre = "Knight's"; wc += 3; vl *= 5; break;
case 105..109: pre = "Merciless"; wc += 3; vl += 600; break;
case 95..104:  pre = "Deadly"; wc += 3; vl += 500; break;
case 88..94:   pre = "Ruthless"; wc += random(2) + 2; vl += 500; break;
case 80..87:   pre = "Master's"; wc += 2; wgt -= 1; vl += 600; break;
case 73..79:   pre = "Lord's"; wc += 2; vl *= 3; break;
case 68..72:   pre = "Brutal"; wc += 2; vl += 300; break;
case 63..67:   pre = "Savage"; wc += 2; vl += 300; break;
case 59..62:   pre = "Champion's"; wc += 2; vl += 300; break;
case 55..58:   pre = CYN+"Steel"+NORM; wc += 2; vl += 1000; break; 
case 51..54:   pre = "Massive"; wc += 2; wgt += 3; vl += 400; break;
case 48..50:   pre = CYN+"Platinum"+NORM; vl *= 20; vl += 5000; wc += 1; break;
case 43..47:   pre = HIW+"Silver"+NORM; vl *= 5; wc += 1; break;
case 30..42:   pre = "Soldier's"; wc += 1; vl *= 2; break;
case 26..29:   pre = HIW+"Iron"+NORM; vl *= 2;  wc += 1; break;
case 22..25:   pre = "Warrior's"; wc += 1; vl += 150; break;
case 18..21:   pre = "Jagged"; wc += 1; vl += 100; break;
case 17:       pre = "Heavy"; wc += 1; wgt += 1; vl += 50; break;
case 16:       pre = HIY+"Gold"+NORM; vl *= 10; break;
case 4..15:    pre = "Sturdy"; nb = 1; vl *= 2; break;
case 3:        pre = YEL+"Bronze"+NORM; wc -= 3; vl /= 3; break;
case 2:        pre = YEL+"Brass"+NORM; wc -= 6; vl /= 6; break;
       }
}

/* Little Bonus Wc to go with the special */
if(random(100) < abonus * 2){
switch(random(abonus) + 1){
  case 95..100:  rwc = 7;  rchance = 30; vl += 1000; break; 
  case 80..94:   rwc = 7;  rchance = 15; vl += 500;  break;
  case 60..79:   rwc = 5;  rchance = 30; vl += 500;  break;
  case 40..59:   rwc = 5;  rchance = 15; vl += 250;  break;
  case 20..39:   rwc = 3;  rchance = 30; vl += 250;  break;
  case 1..19:    rwc = 3;  rchance = 15; vl += 125;  break;
  }
}
/* A bit more base wc to go with quality of make */
switch(random(100) + 1){
  case 90..100: wc += 3; vl += 1500; quality = "Grandmaster";    break; 
  case 60..89: wc += 2;  vl += 1000; quality = "Master";         break; 
  case 20..59: wc += 1;  vl += 500;  quality = "Expert";         break; 
  case 1..19: wc += random(2); vl += 250; quality = "Mediocre";  break; 
  }

if(wc > 18) wc = 18;  /* Make sure its all legal */

cbonus = random(abonus) + 1;
if(!random(1200)) cbonus += 30;
if(abonus > 80 && cbonus < 50) cbonus = 50;

if(cbonus < 45){  
/* Low */
vl += 500;
switch(random(100) + 1){
case 91..100: sufp = "frost";        suf = "of Frost";       break;      
case 81..90:  sufp = "heat";         suf = "of Heat";        break;
case 71..80:  sufp = "shocking";     suf = "of Shocking";    break;
case 61..70:  sufp = "cold";         suf = "of Coldness";    break;
case 58..60:  sufp = "evil";         suf = "of Vileness";    break;
case 55..57:  sufp = "good";         suf = "of Purity";      break;
case 48..54:  sufp = "mana";         suf = "of Mana";        break;
case 38..47:  sufp = "ice";          suf = "of Ice";         break;
case 28..37:  sufp = "flame";        suf = "of Flame";       break;
case 18..27:  sufp = "electricity";  suf = "of Electricity"; break;
case 10..17:  sufp = "health";       suf = "of Health";      break;
case 1..9:    sufp = "wealth";       suf = "of Wealth";      break;
 }
}
else if(cbonus < 70){
vl += 1500;
/* Medium */
switch(random(100) + 1){
case 95..100: sufp = "magi";         suf = "of the "+BLU+"Magi"+NORM;     break;         
case 70..94:  sufp = "blizzard";     suf = "of "+BLU+"Blizzards"+NORM;    break;
case 45..69:  sufp = "fire";         suf = "of "+RED+"Fire"+NORM;         break;
case 20..44:  sufp = "lightning";    suf = "of "+YEL+"Lightning"+NORM;    break;
case 15..19:  sufp = "regeneration"; suf = "of "+GRN+"Regeneration"+NORM; break;
case 7..14:   sufp = "fortune";      suf = "of "+CYN+"Fortune"+NORM;      break;
case 1..6:    sufp = "disease";      suf = "of "+GRN+"Disease"+NORM;     break;
 }
}
else if(cbonus < 95){
vl += 6000;
/* High */
switch(random(101) + 1){
case 101:      sufp = "venom";          suf = "of "+HIG+"Venom"+NORM;           break;
case 85..100:  sufp = "glacier";        suf = "of the "+HIB+"Glacier"+NORM;     break;
case 70..84:   sufp = "nova";           suf = "of the "+HIY+"Nova"+NORM;        break;
case 50..69:   sufp = "inferno";        suf = "of the "+HIR+"Inferno"+NORM;     break; 
case 35..49:   sufp = "storms";         suf = "of "+HIB+"Storms"+NORM;          break;
case 30..34:   sufp = "neutral_slayer"; suf = "of "+HIW+"Neutral Slaying"+NORM; break;
case 25..29:   sufp = "chaos_slayer";   suf = "of "+HIW+"Chaos Slaying"+NORM;   break;
case 20..24:   sufp = "lawful_slayer";  suf = "of "+HIW+"Lawful Slaying"+NORM;  break; 
case 18..19:   sufp = "giant_slayer";   suf = "of "+HIW+"Giant Slaying"+NORM;   break;
case 16..17:   sufp = "undead_slayer";  suf = "of "+HIW+"Undead Slaying"+NORM;  break;
case 14..15:   sufp = "demon_slayer";   suf = "of "+HIW+"Demon Slaying"+NORM;   break;
case 12..13:   sufp = "dragon_slayer";  suf = "of "+HIW+"Dragon Slaying"+NORM;  break;
case 10..11:   sufp = "greed";          suf = "of "+HIC+"Greed"+NORM;           break;
case 9:        sufp = "archmagi";       suf = "of the "+HIG+"Archmagi"+NORM;    break;
case 8:        sufp = "poison";         suf = "of "+HIG+"Poison"+NORM;          break;
case 7:        sufp = "curing";         suf = "of "+HIW+"Curing"+NORM;          break;
case 6:        sufp = "cleansing";      suf = "of Cleansing"+NORM;              break;
case 5:        sufp = "life";           suf = "of "+HIG+"Life"+NORM;            break;
case 4:        sufp = "confusion";      suf = "of Confusion"+NORM;              break;
case 3:        sufp = "weakness";       suf = "of "+HIW+"Weakness"+NORM;        break;
case 2:        sufp = "mana_drain";     suf = "of "+HIG+"Mana Drain"+NORM;      break;
case 1:        sufp = "plague";         suf = "of "+HIR+"Plagues"+NORM;         break;
 }
}
else{
vl += 20000;
/* Great */
switch(random(100) + 1){
case 90..100: sufp = "coldfire";       suf = "of "+CYN+"Coldfire"+NORM;     break;
case 80..89:  sufp = "death";          suf = "of "+HIW+"Death"+NORM;        break;
case 70..79:  sufp = "speed";          suf = "of "+HIW+"Speed"+NORM;        break;
case 60..69:  sufp = "pain";           suf = "of "+HIR+"Pain"+NORM;         break;
case 45..59:  sufp = "witchhunter";    suf = "of "+HIB+"Witch"+NORM+BLU+"hunting"+NORM; break;
case 35..44:  sufp = "serpent";        suf = "of the "+RED+"Serp"+HIR+"ent"+NORM;  break;
case 25..34:  sufp = "lion";           suf = "of the "+HIY+"Lion"+NORM;     break;
case 10..24:  sufp = "reverse";        suf = "of Reversing"+NORM;    break;
case 1..9:    sufp = "coldfire";       suf = "of "+CYN+"Coldfire"+NORM;     break;
 }
}
if(pre) short = pre +" "+ capitalize(nn);
else short = capitalize(nn);
if(sufp) short += " " + suf;

long = "This is a "+nn+" of "+quality+" quality.\n";

wep = clone_object("/players/maledicta/weapon/weapon2.c");
wep->set_name(nn);
wep->set_short(short);
wep->set_long(long);
wep->set_type(type);
wep->set_weight(wgt);
wep->set_value(vl);
if(sufp) wep->add_special_fun(PATH+sufp+".c");
wep->set_class(wc);
if(nb) wep->set_no_break(1);
if(th) wep->set_two_handed_wep(1);
if(rwc && rchance){
  wep->add_special_chance(rchance);
  wep->add_special_damage(rwc);
  }
wep->set_hit_func(wep);
move_object(wep, ob);
return 1;
}
