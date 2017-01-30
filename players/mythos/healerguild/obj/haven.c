#define MULT 10

int time;
object shad;

id(str) { return str == "haven_ob"; }

drop() { return 1; }
get() { return 0; }
  
set_shade_ob(object ob) { shad = ob; }

set_base(a) { time = a*MULT; }
  
reset(arg) { 
  if(arg) return;
  time = 0;
  set_heart_beat(1);    
}
  
init() {
    if(this_player()) {
      write("You enter a Haven of Peace.\nHere you are safe.\n");
    }
}
  
heart_beat() {
  if(!environment()) { destruct(this_object()); return 1; }
  time = time - 1;
  if(time < 1) clear();
}

clear() { 
  set_heart_beat(0);
  if(shad) shad->stop_shadow_haven();
  tell_room(environment(this_object()),"\nThe aura about this place vanishes.\nThis place is no longer a Haven.\n\n");
  destruct(this_object());
return 1; }
