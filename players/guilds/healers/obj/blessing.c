object targ;
int threshold;
int amount;
int TIME;

shadow_blessing_on(object a) {
  if(!a) return 1; 
  targ = a;
  shadow(targ,1);
  return 1;
}

shadow_blessing_off() {
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

hit_player(dam,zap) {
   amount = amount + dam;
   if(threshold != 7 && amount > threshold){ tell_object(targ,"Your are no longer Blessed!\n");  shadow_blessing_off(); }
return dam; }

heal_self(h) {
  if(h > 0) {
    shadow(targ,0);
    targ->heal_self(h);
  } else {
   amount = amount - h;
   if(threshold != 7 && amount > threshold){ tell_object(targ,"Your are no longer Blessed!\n");  shadow_blessing_off(); }
  } 
}

add_hit_point(h) {
  if(h > 0) {
    shadow(targ,0);
    targ->add_hit_point(h);
  } else {
   amount = amount - h;
   if(threshold != 7 && amount > threshold){ tell_object(targ,"Your are no longer Blessed!\n");  shadow_blessing_off(); }
  } 
}

set_threshold(a) { threshold = a; amount = 0; if(a != 7) TIME = a*5; else TIME = 1000; call_out("count_down",7);}

count_down() {
    TIME--;
    if(TIME < 1) { tell_object(targ,"Your are no longer Blessed!\n");  shadow_blessing_off(); }
call_out("count_down",7);
return 1; }
