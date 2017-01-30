#include "/players/mythos/closed/ansi.h"
#define tp this_player()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("music");
    set_alt_name("sound");
    set_alias("dj_weapon");
    set_short("Music");
    set_long("The powerful sound of the best music\n"+
             "in the techno industry!\n");
    set_read("Keep the Faith of Juliana's Tokyo!\n");
    set_class(22);
    set_weight(1);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int a;
string msg;
if(random(3) == 0) {
    switch(random(26)) {
    case 0: msg = "Injected With A Poison  <by> Praga Khan & Jade 4 U"; break;
    case 1: msg = "James Brown Is Dead  <by> L.A. Style"; break;
    case 2: msg = "James Dad Is Brown  <by> L.A. Style"; break;
    case 3: msg = "Are U Wake Up?  <by> Starr Gazer"; break;
    case 4: msg = "Bombas  <by> Chimo Bayo"; break;
    case 5: msg = "Dance Your Ass Off  <by> R.T.Z."; break;
    case 6: msg = "God Shave the Queen  <by> L.A. Style"; break;
    case 7: msg = "Pumpin'  <by> Raveman"; break;
    case 8: msg = "Poing  <by> Rotterdam Termination Source"; break;
    case 9: msg = "Anasthasia  <by> T99"; break;
    case 10: msg = "survival dAnce ~no no cry more~  <by> trf"; break;
    case 11: msg = "Can You Feel It Babe  <by> Bit Max"; break;
    case 12: msg = "Move On Baby  <by> Cappella"; break;
    case 13: msg = "Tokyo, GO!  <by> John Robinson"; break;
    case 14: msg = "U & Me  <by> Cappella"; break;
    case 15: msg = "Dreamon  <by> Parametric"; break;
    case 16: msg = "Sex Drive  <by> Glam w/ Pete Burns"; break;
    case 17: msg = "Take Me Away  <by> Twenty 4 Seven"; break;
    case 18: msg = "Light My Fire  <by> Clubhouse"; break;
    case 19: msg = "Rough Sex  <by> Lords of Acid"; break;
    case 20: msg = "Drink My Honey  <by> Lords of Acid"; break;
    case 21: msg = "Crablouse  <by> Lord of Acid"; break;
    case 22: msg = "Phantom of the Opera  <by> Harajuku"; break;
    case 23: msg = "No Limit  <by> 2 Unlimited"; break;
    case 24: msg = "Mortal Kombat Mix  <by> Oliver Adams"; break;
    case 25: msg = "Obumbrata  <by> Apotheosis"; break;
    }
    tell_room(environment(tp),"\n   "+capitalize(tp->query_real_name())+" plays "+msg+"\n\n");
    attacker->hit_player(1+random(22)); }
    if(random(10) == 0) {
    tell_room(environment(tp),HIM+
    "\n               ENERGY FLOODS THE ROOM AS JULIANA'S TAKES OFF!\n\n"+NORM);
    attacker->hit_player(5+random(30));
    }
if(call_other(this_player(),"query_attrib","wil") < random(100)) {
tp->heal_self(-1 - random(22)); }
if(random(5) == 0) { tp->set_ac(tp->query_ac() - 2); } 
if(call_other(this_player(),"query_attrib","luc") < random(20)) {
tp->set_wc(3);
write("You lose control over the music!  It vanishes!\n");
destruct(this_object());
return 1;}
}

init() {
  ::init();
  if(tp->query_real_name() == "dj") {
  this_object()->set_class(50); }
  else { this_object()->set_class(22); }
}
