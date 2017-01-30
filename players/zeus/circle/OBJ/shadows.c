#include <ansi.h>

int i, dur;
object own;
string mgs;

reset(arg){
  if(arg) return;

  mgs=({ "Shadows swirl slowly around your body",
         "Shadows flow slowly across your body",
         "Shadows trail around you",
         "Shadows cling to your body",
         "Shadows drift slowly around you" });

  dur = 0;
  call_out("effkt", 7+random(4));
  i = random(3);
}

id(str){ return str == "shadows" || str == "zeus_shad_ob"; }
short(){ if(i == 0) return BOLD+BLK+"Shadows"+NORM; 
         else if(i == 1) return HIW+"Shadows"+NORM; 
         else if(i == 2) return WHT+"Shadows"+NORM; }
long(){ 
  string thisd;
  thisd = 
    "This is an enchanted gathering of shadows.  They drift and flow\n"+
    "slowly across the area reminding you of smoke.  There seems to\n"+
    "be some magical force keeping them here.\n"+NORM;
  if(i == 0) write(BOLD+BLK+thisd);
  if(i == 1) write(HIW+thisd);
  if(i == 2) write(WHT+thisd);
}

set_dur(x){ if(dur) dur += (dur / 2); else dur = x; }
set_own(x){ own = x; }

effkt(){
  int a,b;
  object gob;
  if(!environment()) return;
  if(!own){ rmob(); return; }
  if(present(own, environment())){
    gob = present("circle_object", own);
    if(!gob) return;
    if(!own->query_attack() || !present(own->query_attack(), environment()))
      gob->add_endurance(2);
    tell_object(own, HIW+mgs[random(sizeof(mgs))]+".\n"+NORM);
    dur -= 5;
  }
  else dur -= 2;
  if(dur > 6)
    call_out("effkt", 7+random(4));
  else
    call_out("rmob", 5+random(12));
}

rmob(){
  if(!environment()) return;
  if(dur > 6) call_out("effkt", 7+random(4));
  else {
    say(HIW+"The shadows dissipate...\n"+NORM);
    destruct(this_object());
  }
}

get(){ return 0; }

