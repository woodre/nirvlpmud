/*  A nasty weapon...but with serveral drawbacks...
 *  1> you take max 20 damage everytime the full multiple goes off
 *  2> your ac is set to 0
 *  3> you can lose a stat  <a random(200) == 0 >
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

mixed *params;

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
    set_weight(4);
    set_value(10000);
    a = 1;
    set_hit_func(this_object());
}

weapon_hit(attacker){
att = attacker;
if(att) atn=attacker->query_name();
me = tp;
/* Check added by Snow 2/00 */
if(me != environment()) return 0;
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
         if(b == 0){
          if(environment()) environment()->hit_player(11+random(5), "other|wind");
         }
          if(b < 2){
          if(environment())
            environment()->hit_player(5+random(5), "other|wind");
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
 if(att && att->query_hp() > 20) att->hit_player(5+random(7), "other|wind");
/* AC drawback is applied through RegisterArmor code below
me->set_ac(0);
*/
 if(me->is_kid() || me->is_pet()) { 
  me->hit_player(1+random(50), "other|wind");
   me->add_exp(-100-random(1000)); }
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
    if(0 == random(200)) {   /* drawback 3 chance of random loss of atrrib */
    tell_object(me,HIB+"The elemental weapon saps your soul!\n"+
          "Magic flares!\n"+NORM);
    /* made it call a force reset() -mizan */

  if(!(me->query_npc())) {
    me->lower_attrib();
    me->reset(1);
    me->save_me(); 
    }
  }
 return 1;
}

extra_look() { 
if(wielded && living(environment(this_object())))
return BLU+"Mist shrouds "+
           capitalize(environment()->query_real_name() + NORM);
           else { return 0; }
}

/*
 Updates necessary due to the new armor code.
 -Feldegast 11-1-00
*/

init() {
  add_action("wield", "wield");
  add_action("stopwield", "unwield");
}

/* added in id(str), environment() checks [7.20.01] verte */
wield(str) {
    if(!id(str) || environment() != this_player()) return 0;
    if(wielded) {
      notify_fail("You are already wielding it!\n");
      return 0;
    }
    ::wield(str);
    if(!wielded) return;
    params = ({ "physical", 0, 0, "do_special" });
    this_player()->RegisterArmor(this_object(), params);
    wielded = 1;
    return 1;
}

stopwield() {
  if(environment() != this_player()) return 0;
  ::stopwield();
  this_player()->RemoveArmor(this_object());
  return 1;
}

do_special(me) {
  int modifier;
   string gname;
  modifier = me->query_ac();
  if(me != environment()) { /* dropping without unwielding first was not
                               properly removing this "armor" */
    me->RemoveArmor(this_object());
    return 0;
  }
  if(!wielded) return;
  if(!random(12))
    tell_object(me, "You are exposed to the elements!\n");
  /* Cninjas have damage increased 30% because they have no ac. */
/*
  if(me->query_guild_name() == "cyberninja")
*/
  /* Added other guilds to this, plus added in any AC they are wearing.
     Cause I am mean.      [verte] */
  /* made it negate ac for those other guilds instead of lowering
     res cause I am mean too - ill */
  if(((gname = (string)me->query_guild_name()) == "cyberninja") ||
       (gname == "dervish") || (gname == "neo symbiote") ||
       (gname == "Dark Order") ||
       (gname == "ranger"))
    return -3000-modifier;
  return -modifier;
}
