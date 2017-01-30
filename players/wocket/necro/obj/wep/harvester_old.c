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

query_save_flag() { return 0; }

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

init() {
  ::init();
  add_action("harvest","harvest");
}

weapon_breaks(){
  return 1; 
}

harvest(str) {
string name;
object ob;
int c_level;
int i;
string msg;
/*
bpartarray = ({"blood","skin","eye","heart","spine","soul"});
bpartgain = ({1,4,10,15,15,20});
*/

  if(!str){ 
    notify_fail("What would you like to harvest?\n"); 
    return 0; 
  }
  if(str != "corpse"){ 
    notify_fail("That is not something you can harvest.\n");
    return 0;
  }
  ob = present("corpse",environment(tp));
  if(!ob){
    ob = present("corpse",tp);
  }
  if(!ob){ 
    write("There is no corpse here.\n");
    return 1; 
  }  
  if(!GOB) { 
    write("You must be a necromancer to do that.\n");
    return 1; 
  }
  if(!wielded){
    write("You must have harvesting dagger wielded!\n"); return 1; 
  }

  if(sscanf(ob->short(),"corpse of %s",name)) {
    c_level = ob->query_corpse_level();
    if(c_level < 1){
      write("That corpse is worthless to you.\n");
      return 1;
    }
    if(c_level > 19 && !random(20) ){
        call_other(GOB,"add_soul",1);
        msg = "a soul";
    }
    if(c_level > 14 && !random(10)){
        call_other(GOB,"add_spine",1);
        if(!msg) msg = "a spine";
        else msg += ", a spine";
    }
    if(c_level > 14 && !random(10)){
        call_other(GOB,"add_heart",1);
        if(!msg) msg = "a heart";
        else msg += ", a heart";
    }
    if(c_level > 9 && !random(5)){
      i = random(2)+1;
      call_other(GOB,"add_eye",i);
      if(!msg){
        if(i == 2) msg = "2 eyes"; else msg = "an eye";
      }
      else{
        if(1 == 2) msg += ", 2 eyes"; else msg += ", an eye";
      }
    } 
    if(c_level > 3 && !random(3)){
      i = random(5)+1;
      call_other(GOB,"add_skin",i);
      if(!msg){
        if(i == 1)
         msg = "a piece of skin";
        else 
         msg = i+" pieces of skin";
      }
      else{
        if(i == 1)
         msg += ", a piece of skin";
        else
         msg += ", "+i+" pieces of skin";
      }
   }
   i = random(c_level)+1+random(5);
   if(i > 15) i = random(5)+10;
   if(i){  
    call_other(GOB,"add_blood",i);
    if(!msg){
        if(i == 1)
         msg = "a vial of blood";
        else 
         msg = i+" vials of blood";
      }
      else{
        if(i == 1)
         msg += ", and a vial of blood";
        else
         msg += ", and "+i+" vials of blood";
      }
   }
       
   write("You bend over and harvest all you can from the corpse.\n");
   write("Quickly you slip "+msg+" into your pouch.\n");
   destruct(ob);
   return 1;
   }
   notify_fail("You don't find a useful corpse here.\n");
   return 0;
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

