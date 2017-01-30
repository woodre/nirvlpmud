/* Maledicta made changes on 4.23.01 with
   Boltars Approval.  Xp in parties will 
   now give less. */

object targ;
int flag;

shadow_healer_on(object a) {
  if(!a) return 1;
  targ = a;
  flag = 0;
  shadow(targ,1);
  return 1;
}

shadow_healer_off() {
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

add_exp(arg) {
  /* 05/24/06 Earwax: added this */
  if (object_name(previous_object()) == "room/adv_guild")
    targ->add_exp(arg);
  if(this_player()->query_level() > 20 && query_ip_number(this_player())) {
    tell_object(this_player(),"Please call add_xp(#) to change experience\n");
    return 1;
  }
return 1; }

/*  Commented out and changed by Maledicta.
    Reason: New xp system and partying allowed
            xp to be gained too easily.
add_xp(int a) {
int chng;
  chng = random(8) + 4;
  if(flag) a = a/chng;
  shadow(targ,0);
  targ->add_exp(a);
}
*/

/*  New add_xp() formula */
add_xp(int a)
{ 
    int chng;
    object x, p;

    if(((x = this_player()) && (status)x->is_player()
       && (int)x->query_level() > 20) ||
       ((p = previous_object()) && object_name(p) == "players/mythos/healerguild/guilddaem"))
      chng = 1;

    else
      chng = random(8) + 4; 

    if(a > 0) a = a/chng; 

#ifdef DOUBLEXPDAY
  a *= 2;
#endif
    targ->add_exp(a); 
}

set_combat_flag(int b) { if(!b) flag = 0; else flag = b; }

query_combat_flag() { return flag; }

query_xpshadow() { return 1; }
