#include "/players/pavlik/closed/colors.h"
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("Black Blade");
  set_alt_name("blade");
  set_short("a "+MAG+"Black Blade"+NORM);
  set_long(
  "A flat black-bladed broadsword with polished piece of Jet set in the hilt.\n"+
  "The dark blade reflects no light.\n");
  set_type("sword");
  set_class(12+random(3));
  set_weight(3);
  set_value(450);
  set_save_flag(1);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  int i;

   if(random(3)) return 0;
  i = random(call_other(this_player(), "query_attrib", "pie"));

  if(i > 17) {
    write("The black blade glows white as it sucks the life from your enemy!\n");
    write("You feel somewhat better.\n");
    say(ME+"'s dark sword glows white as it sucks the life from "+IT+"!\n");
    this_player()->heal_self(random(5));
    return 5;
  }
  else if(i > 12) {
    write("The black blade slices into "+IT+"'s body!\n");
    say(ME+"'s black blade slices into "+IT+"'s body!\n");
    return 4;
  }
  else if(i == 11) {
    write("The black blade CLEAVES "+IT+"'s body in half!\n");
    say(ME+"'s black blade CLEAVES "+IT+"'s body in two!\n");
    return 3+random(4);
  }
  else if(i > 6) {
    write("Sparks fly as the black blade grates against "+IT+"'s bone!\n");
    say("Sparks fly as the black blade grates against "+IT+"'s bone!\n");
    return 1+random(5);
  }
  else if(i > 2) {
    write("The black blade snickers insanely is it whistles through the air!\n");
    say("The black blade snickers insanely is it whistles through the air!\n");
    return random(3);
  }
  else {
    write("The black blade slips in your hand and you cut yourself!\n");
    say(ME+"'s sword slips.\n");
    this_player()->hit_player(random(5));
    return;
  }
  return;
}

