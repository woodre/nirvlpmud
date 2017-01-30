#include "../defs.h"

inherit "obj/treasure";

int value_tier;
int walker_value;

set_value_tier( int val );
set_object_stats();

void
reset(int arg) {
  if (arg) return;
  
  set_save_flag();
}

set_object_stats() {
  mapping data;
  
  data = DEADDM->get_walker_obj( value_tier );
  set_id( data["name"] );
  SetMultipleIds( data["ids"] );
  multipleIds += ({ "walkerobj" });
  set_short( data["short"] );
  set_long( data["long"] );
  set_weight( data["weight"] );
  set_value( walker_value / 5 );
}


init() {
  ::init();
  add_action("SetValue","val");
}

query_short() {
  string tmp_short;
  
  tmp_short = short_desc;
  
  if(this_player()->query_level() > 40)
    tmp_short+= "  < tier: " + value_tier + " val: "+walker_value + " >";
  
  return tmp_short;
}

SetValue( string str ) {
  int val;
  
  if( !str ) 
    write("Value: " + walker_value + "\n");
  else {
    sscanf( str,"%d", val );
    set_value_tier( val );
  }
  return 1;
}

query_value_tier() { return value_tier; }

set_value_tier( int val ) {
  if( val )
    value_tier = val;
  else
    value_tier = 1;
  
  switch( value_tier ) {
    case 1:
      walker_value = TIER_1_VALUE + random ( TIER_1_RAND );
      break;
    case 2:
      walker_value = TIER_2_VALUE + random ( TIER_2_RAND );
      break;
    case 3:
      walker_value = TIER_3_VALUE + random ( TIER_3_RAND );
      break;
    case 4:
      walker_value = TIER_4_VALUE + random ( TIER_4_RAND );
      break;
    case 5:
      walker_value = TIER_5_VALUE + random ( TIER_5_RAND );
	  break;
    default:
      walker_value = TIER_1_VALUE + random ( TIER_1_RAND );
      break;
  }
}

query_walker_value() { return walker_value; }

set_walker_value( int val ) { walker_value = val; }