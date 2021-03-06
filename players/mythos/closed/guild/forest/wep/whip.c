/*  A nasty weapon...but with serveral drawbacks...
 *  1> you take max 20 damage everytime the full multiple goes off
 *  2> your ac is set to 0
 *  3> you can lose a stat  <a random(300) == 0 >
 *  this weapon can only be found on a monster who is_player() so
 *  guild spells and like do not effect monster
 * The monster is Masakado- /players/mythos/amon/forest/masakado.c
 *                    -mythos
 *
 *  - approved by MIZAN
 */

#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn  tp->query_real_name()
int n,a,b, check;
string atn;
object me, att;
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("wind");
    set_alt_name("elemental");
    set_alias("air");
    set_short("Element of "+BLU+"AIR"+NORM);
    set_long("Mist surrounds you....\n"+
             "This is the infusion of the element of air:\n"+
             "with all its power and danger.\n");
    set_class(20);
    set_weight(1);
    set_value(10000);
    a = 1;
    set_hit_func(this_object());
}
weapon_hit(attacker){
att = attacker;
if(att) atn=attacker->query_name();
me = tp;
if(attacker && attacker->query_hp() > 20) { check = random(3); }
else { check = 1; }
  if(check == 0 && a) { n =  random(5); b = n; a = 0;}
  if(!a) {
  switch(n) {
  case 0: if(!att) { break;}
          air_whip();   
  case 1: if(!att) { break;}
          air_whip();  
  case 2: if(!att) { break;}
          air_whip(); 
  case 3: if(!att) { break;}
          air_whip();
  case 4: if(!att) { break;}
          air_whip(); a = 1; 
          if(b == 0) { tp->heal_self(-11 - random(5)); }  /*drawback 1  take some damage*/
          if(b < 2) { tp->heal_self(-1 - random(5)); 
                      write("The air whips around!\n"+
                      "It is too furious to control and you feel its sharp bite!\n");}
          break;
  }
  } 
  return 0;
}

query_save_flag()  { return 1; }

air_whip() { 
string what, how, msg;
object ob;
int i,mi;
if(!att) { return 1;}
 ob = all_inventory(environment(me));
 if(att && att->query_hp() > 20) att->hit_player(20);
 me->set_ac(0);     /*drawback 2  ac is set to 0*/
 mi = random(8);
 switch(mi) {
 case 0: break;
 case 1: how = " to small fragments"; what = "massacre"; break;
 case 2: how = " with a bone crushing sound"; what = "smashed"; break;
 case 3: how = " very hard"; what = "hit"; break;
 case 4: how = " hard"; what = "hit"; break;
 case 5: how = ""; what = "hit"; break;
 case 6: how = ""; what = "grazed"; break;
 case 7: how = " in the stomach"; what = "tickled"; break;
 }
 switch(random(10)) {
 case 0: msg = "The wind swirls around the enemy!\n"; break;
 case 1: msg = CYN+"Chaos is lose in the room!\n"+NORM; break;
 case 2: msg = ""; break;
 case 3: msg = ""; break;
 case 4: msg = "The wind howls and chaos reigns\n"; break;
 case 5: msg = GRN+"Mist whirls around you!\n"+NORM; break;
 case 6: msg = RED+"Blood flies as the air slices into flesh!\n"+NORM; break;
 case 7: msg = "You are blinded as the wind blasts into the enemy!\n"; break;
 case 8: msg = ""; break;
 case 9: msg = ""; break;
 }
 if(att) {
 tell_room(environment(me),msg); 
 if(mi > 0) {
  tell_object(me, "You " + what + " " + atn + how + ".\n");
  if(att) tell_object(att, capitalize(me->query_name()) +" "+what+" you"+how+".\n");
  for(i=0;i<sizeof(ob);i++) {
    if(ob[i] != me && ob[i] != att && living(ob[i])) {
      tell_object(ob[i],capitalize(me->query_name()) + " " + 
          what + " " + atn + how +".\n"); }
    } }
    else { 
    tell_object(me, "You missed.\n");
    for(i=0;i<sizeof(ob);i++) {
    if(ob[i] != me && living(ob[i])) {
      tell_object(ob[i], capitalize(me->query_name()) + " missed " + 
      atn + ".\n");}
    } } }
    if(0 == random(300)) {   /* drawback 3 chance of random loss of atrrib */
    tell_object(me,HIB+"The elemental weapon saps your soul!\n"+
          "Magic flares!\n"+NORM);
    if(!(me->query_npc())) me->lower_attrib(); }
 return 1;
}

extra_look() { 
if(wielded && living(environment(this_object()))) {
return BLU+"Mist shrouds "+
           capitalize(environment(this_object())->query_real_name())+".\n"; }
           else { return ""; }
}
