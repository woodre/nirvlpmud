#include "/players/linus/def.h"
#define USER environment(this_object())
inherit "/obj/armor.c";
id(str) { return str=="amulet" || str=="skull" || str=="skull amulet"; }
reset(arg) {
 ::reset(arg);
 set_name("skull amulet");
 set_ac(2);
 set_value(1500);
 set_weight(1);
 set_save_flag(1);
 set_type("amulet");
 set_params("other|evil", 2, 5, "do_spec");
}
long() {
 if(worn) { write("A small skull attached to a silver chain.  The skull seems to possess some\n"+
                 "magical properties.  The skull seems to stare at you with its "+HIY+"glowing eyes.\n"+NORM);
return 1;
}
else { write("A small skull attached to a silver chain.  The skull seems to possess some\n"+
                 "magical properties.  The skull seems to stare at you with its "+HIK+"darkened eyes.\n"+NORM);
return 1;
 }
}
short() { 
  if(worn) {
   return "Skull amulet -"+HIY+" Glowing"+NORM+" (worn)";
 }
  else {
   return WHT+"Skull amulet"+NORM;
 }
}
do_spec(object owner){
    if(!random(5)){
      tell_object(owner,
      "The eyes "+HIY+"flare up"+NORM+" to deflect the sinister attack!\n");
      return 0502;
      }
 return 0;
}
wear(str)
{
  if(!id(str)) return 0;
if(worn) return 0;
if(this_player()->query_sp() < 25){
write("You do not have the magical power the amulet needs.\n");
return 1;
}
::wear(str);
this_player()->add_spell_point(-25);
write("As you wear the amulet, the eyes in the skull "+HIY+"glow"+NORM+" with life.\n");
set_light(1);
     return 1;
}
remove(str) {
 if(!id(str)) return 0;
 if(!worn) return 0;
::remove(str);
 write("As you remove the amulet, the eyes in the skull fade.\n");
 set_light(-1);
 return 1;
}
