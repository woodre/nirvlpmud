inherit "obj/weapon";

#include <ansi.h>
#include "../defs.h"

reset(arg) {
  string long_str, short_str;
  int value, phys;
  ::reset(arg);
  if(arg) return;

  set_name("mp5");
  set_class(18);
  set_weight(2);
  set_type("gun");
  set_alias("submachine gun");
  set_alt_name("mp5 submachine gun");
  SetMultipleIds( ({ "mp5 gun", "walkerobj" }) );
  
  value = 1200;
  phys = 6;
  short_str = HIBLK+"MP5"+NORM+" Submachine Gun";
  long_str = "A Heckler & Koch MP5 submachine gun. Designed with a highly reliable\n\
recoil-operated delayed blowback bolt system and a precision made cold\n\
hammer forged barrel. The stock can be retracted or folded to make it\n\
flexible enough for pretty much any situation. The finish is a flat\n\
matte black.";
  
  if( !random(5) ) {
    value += 400;
    phys -= 2;
    short_str += " (silenced)";
    long_str += " This gun is equipped with a Silencer to reduce noise.";
  }
  
  long_str += "\n";
      
  set_value( value );
  set_short( short_str );
  set_long( long_str );
  set_params("physical",phys);
  
}

wield(string str)
{
  if(id(str) && present(this_object(), this_player()) &&
    this_player()->query_weapon() == this_object()){
    ::wield(str);
    return 1;
  }
  ::wield(str);
  if(id(str))
  {
    if(!present(this_object(), this_player())) return 0;
    if(this_player()->is_npc()) return 0;
    set_class(18);
    if(this_player()->query_total_stats() < 200){
      set_class(12);
      write("You fumble around and finally flip the safety off.\n");
    }
    else {
      write("You slam a magazine into the MP5 with a satisfying click.\n");
      say(capitalize(this_player()->query_name())+" grins maniacally as "+this_player()->query_pronoun()+" slams a magazine into the MP5.\n");
    }

    return 1;
  }
}

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}
