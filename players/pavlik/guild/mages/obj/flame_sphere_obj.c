#include "/players/pavlik/closed/colors.h"
#define EN environment(this_object())
#define ME capitalize(environment(this_object())->query_name())
#define IT capitalize(target->query_name())
object target;
reset(arg){
 if(arg)
   return;
}
short(){ return; }
long(){ write("a mages flame_sphere_obj.\n"); return; }
id(str){ return str == "flame_sphere_obj"; }
get(){ return 0; }
drop(){ return 1; }

do_spell(ob){
  target = ob;
  call_out("exe_spell", 25);
  return 1;
}

exe_spell(){
   object mmo;
   int randsec;
   if(EN) return destruct(this_object());
   if(!environment(EN)) return call_out("exe_spell", 2);
  present("mageobj", EN)->set_casting(0);
  if( (!target) || (!present(target, environment(EN)))){
    tell_object(EN, "\n"+
    "Target not here ..... "+HIR+"Flame Sphere"+NORM+" spell aborted.\n\n");
    destruct(this_object());
    return 1;
    }
  tell_object(EN, "You cast your Flame Sphere spell.\n");
  if(random(2)==1) tell_room(environment(EN), "\n"+
  ME+" flails his arms in the air and points at "+IT+".\n"+
  "A "+HIR+"swirling ball of flames"+NORM+" leaps from "+ME+"'s fingertips and explodes\n"+
  "right on target!  "+IT+" is "+HIR+"engulfed in flames!\n\n"+NORM);
  else tell_room(environment(EN), "\n"+
  ME+" casts a spell and a "+HIR+"fiery ball of flames"+NORM+" shoots from his fingers.\n"+
  "The flaming sphere "+HIY+"crackles"+NORM+" through the air and detonates on "+IT+"!!!\n\n");
  mmo=present("mageobj", EN);
  mmo->set_OBJ(target);
  randsec=random(1000);
  mmo->set_randn(randsec);
  command("IDODMG "+(5+random(15)+" "+randsec), EN);
  EN->add_spell_point(-15);
  destruct(this_object());
  return 1;
}
