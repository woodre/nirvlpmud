#include "../../defs.h"

inherit "obj/weapon.c";
id(str){ return (str == "harvester" || str == "dagger" || str == "tool" || str == "necro_tool"); }
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("harvester");
  set_alias("necro_tool");
  set_alt_name("dagger");
  set_short("A "+BOLD+"harvesting dagger"+OFF);
  set_long("A harvesting dagger, used primarily by a Necromancer.\n"+
           "The tool itself has a curved steel blade edged in diamond,\n"+
           "perfect for cutting and slashing through corpses. An\n"+
           "onyx skull is carved into the handle giving the weapon\n"+
           "a great overall balance.\n");
  set_class(12);
  set_weight(1);
  set_type("dagger");
  set_value(0);
  set_hit_func(this_object());
}

query_save_flag() { return 1; }

weapon_hit(att){
string msg;
  switch(random(10)){
  case 0:  msg = HIR+"You slash out with your dark weapon.\n"+OFF; break; 
  case 1:  msg = HIR+"Your dagger glows a deep "+OFF+MAG+"magenta"+HIR+" as you cover it with blood.\n"+OFF; break;
  case 2:  msg = att->query_name()+HIR+" winces as your dagger slices through "+att->query_possessive()+" flesh with ease.\n"+OFF; break;
  case 3:  msg = att->query_name()+HIR+" bleeds as you twist your dagger into "+att->query_possessive()+" body.\n"+OFF; break;
  default: msg = 0;
  }
  if(msg){
    write(msg);
    return 1; 
  }
  else{
  if(tp->query_attrib("luc") > random(50)) {
    write(HIR+"You slip your dagger between "+OFF+att->query_name()+"'s"+HIR+" defenses, gashing\n"+
          "out a large chuck of flesh.  Parts of "+OFF+"bone"+HIR+" have been exposed.\n"+OFF);
    return 7; 
  }
  }
}

weapon_breaks(){
  return 1; 
}

drop(silently) {
  if(previous_object() && !living(previous_object()) ) return 0;
   if (wielded) {
      call_other(wielded_by, "stop_wielding");
      wielded = 0;
   }
   if(!silently){
         write("You drop your dagger.\n");
         write(ROD+BOLD+BLK+"A dark mist swirls around your dagger.  Suddenly it\n"+
              "      "+"all collapses into nothingness.  The realm of death\n"+
              "      "+"has reclaimed its property.\n"+OFF);
     if(this_player())
         say("A dark mist surrounds "+this_player()->query_name()+"'s dagger and then all is gone.\n");
   }
   set_weight(0);
   if(this_player())
     this_player()->recalc_carry();
    destruct(this_object());
    return 1;
}

