/* Approved by:  Maledicta   05.13.01  */
/*
// 2005.08.20 -Forbin
// Changes:
//   increased robe_life from 2500 to 3500, raise AC to 2
*/
inherit "obj/armor";
#include "/players/zeus/closed/all.h"

int robe_life;

reset(arg){
  ::reset(arg);
  if(arg) return;

  robe_life = 3500;   /* life of armor  */

  set_name("robe");
  set_short(NORM+MAG+"Heldurabhoricka's Robe"+NORM);
  set_type("armor");
  set_ac(2);
  set_weight(1);
  set_value(1100);
  call_out("shl", 10);
}

shl(){
  if(!environment()) return;
  if(environment()->is_player()){
    if(ENV->query_spell_point() < ENV->query_msp()){
      ENV->add_spell_point(1+random(3));
      robe_life--;
    }
  }
  call_out("shl", 10);
}

query_life(){
  string a;
  if(robe_life >= 1001)
    a = "The robe is extremely strong.\n";
  else if(robe_life <= 1000 && robe_life >= 750)
    a = "The robe is very strong.\n";
  else if(robe_life < 750 && robe_life >= 500)
    a = "The robe is just a little weaker.\n";
  else if(robe_life < 500 && robe_life >= 200)
    a = "The robe is weaker and looks worn.\n";
  else if(robe_life < 200 && robe_life >= 60)
    a = "The robe is beginning to fall to pieces.\n";
  else if(robe_life < 60)
    a = "The robe will fall apart very soon.\n";
  return a;
}

/*
query_hits(){ return robe_life; }
set_hits(int i){ robe_life = i; }
*/

long(){
  write(
"This is the robe of the legendary magician Heldurabhoricka.  It is\n"+
"very long, and drags slightly on the ground.  The inside lining is\n"+
"entirely black.  It has a large hood, which hangs loosely from the\n"+
"collar. "+query_life());
  if(environment()->query_level() > 20)
    write("Life: "+HIG+robe_life+NORM+"\n");
}

do_special(x){
  robe_life--;
  if(robe_life <= 0)
  {
    tell_object(x,
      "\n\tThe magic from your robe has faded away...\n"+
      "\tWithout it the robe falls to pieces...\n\n");
    this_object()->drop();
    destruct(this_object());
    return 0;
  }
  x->add_spell_point(1+random(3));
  if(!random(7))
  {
	tell_object(x, "Energy flows from the robe into you...\n");
    x->add_spell_point(2);
  }
}

generic_object() {return 1;}
restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }


locker_arg() { return "" + robe_life; } 

locker_init(arg) { 
robe_life = atoi(arg);
}

/* Approved by:  Maledicta   05.13.01  */
