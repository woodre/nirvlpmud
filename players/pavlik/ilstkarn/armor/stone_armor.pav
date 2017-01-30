inherit "obj/armor";
#include "/players/pavlik/closed/colors.h"

/*
 * Stone Armor:
 * armor class: 6      type: armor
 * restrictions: the player cannot wear any other armor except
 * type ring and misc while this armor is being worn.  This armor is also
 * quite heavy.  The object is storable at times.
 *
 * from: ~/monsters/ilstkarn/basalisk
 */

reset(arg){
 ::reset(arg);
 set_short("a Stone Hide");
 set_long(
 "This is the rock-hard hide of a slain Basalisk.  The stone shell\n"+
 "is the perfect sculpture of the deadly beast.  The hide is immensely\n"+
 "heavy, but if you were able to wear it about your shoulders it would\n"+
 "provide unparralled protection.\n");
 set_name("the Basalisk's Hide");
 set_ac(6);
 set_weight(7);
 set_value(5000);
 set_alias("hide");
 set_arm_light(0);
 set_type("armor");
 if(random(3)) set_save_flag(1);
 else set_save_flag(0);
}

stone_type(str) {
  return str == "armor" || str == "helmet" || str == "boots" ||
  str == "amulet" || str == "shield";
}

test_type(str) {
  if(stone_type(str))
    return this_object();
  if(next)
    return call_other(next, "test_type", str);
  return 0;
}

wear(str) {
  object ob, obj;
  int i, tmp, failed;
  string junk;

  if(!id(str)) {
    return 0;
  }
  if(environment() != this_player()) {
    write("You must get it first!\n");
    return 1;
  }
  if(present("notarmor",this_player())) {
    write("For some reason you are unable to wear armor.\n");
    return 1;
  }
  if(worn) {
    write("You already wear it!\n");
    return 1;
  }
  if(size) {
    tmp=find_size(this_player());
    if(tmp > size) {
      write("You find that it is too small for you.\n");
      return 1;
    } 
    if(tmp < size - 1) {
      write("It is far to big for you, it simply falls off.\n");
      return 1;
    }  
    if(tmp < size) write("It's a little big but you can wear it.\n");
  }  
  /*
   * Test to make sure none of the multiple armor types is
   * already being worn.
   */
  failed = 0;
  obj = all_inventory(this_player());
  for(i=0; i<sizeof(obj); i++) {
    if(obj[i]->query_worn() && stone_type(obj[i]->query_type())) {
      write("You already have an armor of class " + type + ".\n");
      write("Worn armor " + call_other(obj[i],"short") + ".\n");
      failed = 1;
    }
  }
  if(failed) {
    return 1;
  }
  if(call_other(this_player(), "query_attrib", "str") < 19) {
    write("You are not strong enough to wear this.\n");
    return 1;
  }
  worn_by = this_player();
  worn = 1;
  return 1;
}

