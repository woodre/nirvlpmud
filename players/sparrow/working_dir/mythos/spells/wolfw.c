/* This is the weapon that the player when in wolf form wields
 *  the wolf form has disadvantages such as a set max hp, a set ac
 *  can not wield any weapons but this.
 *                                             -mythos
 */

#include "/players/mythos/closed/guild/def.h"
object atte, me;
string atn;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("aura_of_shape");
    set_class(15);
    set_weight(2);
    set_value(0);
    set_hit_func(this_object());
    call_out("check",3);
}
weapon_hit(attacker){
me = this_player();
atte = attacker;
atn = atte->query_name();
  if(qtf > random(60)) {
    switch(random(3)) {
      case 0: if(!attacker) { break; }
              slice();
      case 1: if(!attacker) { break; }
              slice();
      case 2: if(!attacker) { break; }
              slice(); break;
   }
   }
   
}

drop() { return 1;}
get() { return 0;}

check() {
  if(broke) {
  this_object()->fix_weapon();
  command("unwield aura_of_shape",environment(this_object()));
  command("wield aura_of_shape",environment(this_object()));
  }
    call_out("check",3);
return 1; }

query_save_flag()  { return 1; }

slice() {
string what, how;
object ob;
int i,mi;
if(!atte) { return 1;}
 ob = all_inventory(environment(me));
 if(atte && atte->query_hp() > 15) atte->hit_player(15);
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
 if(atte) {
   tell_room(environment(ep),"The "+HIY+"Winter Wolf"+NORM+
        " darts in and with razor-like teeth slices flesh!\n"); 
 if(mi > 0) {         
  tell_object(me, "You " + what + " " + atn + how + ".\n");
  if(atte) tell_object(atte, capitalize(me->query_name()) +" "+what+" you"+how+".\n");
  for(i=0;i<sizeof(ob);i++) {
    if(ob[i] != me && ob[i] != atte && living(ob[i])) {
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
 return 1;
}
