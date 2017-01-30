/* APPROVED BY SNOW 5/28/98 */

inherit "obj/armor";
#include "/players/pavlik/closed/colors.h"
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

int total;
int stone;

reset(arg){
  ::reset(arg);
  set_short("A ring");
  set_long("a ring");
  set_name("ring");
  set_ac(0);
  set_weight(1);
  set_value(800);
  set_alias("ring");
  set_arm_light(0);
  set_save_flag(1);
  set_type("ring");
  total = 0;
  stone = 0;
}

id(str) {
  if(!stone) return str == name || str == alias || str == type;
  else return str == name || str == alias || str == type ||
  str == "ilstkarn_magic_armor";
}

short() {
  string tmp;
  if(!stone) tmp = "A ring";
  else tmp = "A "+HIB+"Syrian"+NORM+" Ring";
  if(worn) return tmp + " (worn)";
  else return tmp;
}

long() {
  if(!stone) {
    write(
    "An elegant band of white gold.  This ring has a mounting for a gem\n"+
    "stone, but it is currently vacant.\n");
    return;
  }

  write(
  "The "+HIB+"Syrian"+NORM+" stone is well known for its protective properties.\n"+
  "The ice-blue gem stone is said to have powers of protection against Evil\n"+
  HIR+"Fire-magic"+NORM+".  The ring's band is made from white-gold.\n");
  if(total < 100) write("The syrian gem is in perfect condition.\n");
  else if(total < 300) write("The syrian gem is slightly chipped.\n");
  else if(total < 500) write("The syrian gem has several cracks in it.\n");
  else if(total < 700) write("The syrian gem has a deep crack in it.\n");
  else if(total < 900) write("The syrian gem is severly cracked.\n");
  else write("The syrian gem is about to shatter.\n");
  return;
}

init() {
  ::init();
  add_action("mount_gem", "mount");
}

mount_gem(str) {
  string crap1, crap2;
  object obj;

  obj = present("syrian_gem", this_player());
  
  if(obj && sscanf(str, "%s %s", crap1, crap2) == 2) {
    if(obj->id(crap1) && crap2 == "on ring") {
      if(worn) {
        write("You must remove the ring first.\n");
        return 1;
      }
      write("You mount the ice-blue gem in the fine white gold ring.\n");
      write("It is a perfect fit!\n");
      say(capitalize(this_player()->query_name())+" puts an ice-blue gem on "+
      "a ring.\n");
      set_name(HIB+"Syrian"+NORM+" Ring");
      set_alias("syrian ring");
      set_ac(1);
      stone = 1;
      this_player()->add_weight(-1);
      destruct(obj);
      return 1;
    }
  }
}

/*
 * Function called by some monsters to do damage.
 * This armor can block some of the damage (40-90%).
 */
do_fire_damage(x) {
  int dmg, blocked;

  /* amount blocked is random 40-90 % */
  blocked = 40 + random(51);
  dmg = (x * blocked) / 100;

  tell_object(worn_by,
  YEL+">>"+NORM+" Your ring blocks some of the spell. ["+blocked+"%]\n");

  worn_by->hit_player(dmg, "other|fire");

  total += blocked;

  if(total > 2000) {
    tell_object(worn_by,
    "The "+HIB+"Syrian"+NORM+" gem "+HIY+"EXPLODES!\n"+NORM+
    "The explosion wounds you!\n");
    tell_room(environment(worn_by),
    capitalize(worn_by->query_name())+"'s ring explodes!\n");
    worn_by->hit_player(random(100));
    drop();
    worn_by->add_weight(-1);
    destruct(this_object());
  }

  return 1;
}

