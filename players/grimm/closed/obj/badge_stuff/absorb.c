string msg, msg2;
object target,barb;
int ABSORB_DMG;
 
set_absorb(x) { ABSORB_DMG = x; }
 
set_msg(str) { msg = str; }
 
set_msg2(str) { msg2 = str; }
 
shadow_me(ob,brb) {
  shadow(ob,1);
  barb = brb;
  target = ob;
}
 
hit_player(arg) {
  int damage;
  damage = target->hit_player(arg);
  if(ABSORB_DMG>0) {
    if(ABSORB_DMG>(damage-1)) {
      ABSORB_DMG -= damage;
      tell_object(target,msg+damage+" points. ("+
                  ABSORB_DMG+" left)\n");
      damage = 0;
    } else {
      damage -= ABSORB_DMG;
      ABSORB_DMG = 0;
      tell_object(target,msg2);
      barb->blam_abs();
    }
  } else {
    tell_object(target,msg2);
    barb->blam_abs();
  }
  return damage;
}
