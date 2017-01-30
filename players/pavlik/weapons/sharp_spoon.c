#include "/players/pavlik/closed/colors.h"
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())
inherit "obj/weapon.c";

int bleed;
object obj;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("Sharp Spoon");
  set_alt_name("spoon");
  set_short("a sharpened Spoon");
  set_long(
  "This dangerous twist of metal used to be a regular, harmless spoon.\n"+
  "Now, after countless years of rubbing, its tip has become sharp and\n"+
  "deadly.  The wicked utensil gleams dangerously.\n");
  set_type("dagger");
  set_class(16);
  set_weight(1);
  set_value(50);
  message_hit = ({
    HIR+"GOUGED"+NORM+" large chunks of flesh from the body of", "",
    HIB+"twisted"+NORM+" the spoon "+HIB+"deep"+NORM+" into the bowels of", "",
    RED+"sliced"+NORM+" a gaping wound in", "",
    BLU+"punctured"+NORM, " with the wicked spoon",
    HIM+"stabbed"+NORM, "",
    MAG+"cut"+NORM+" deep into the body of", "",
    CYN+"nicked"+NORM, " with the sharp spoon",
  });
  set_save_flag(1);
  set_hit_func(this_object());
  bleed = 0;
}

weapon_hit(attacker){
  int i;

  i = random(9)+1;

  if(bleed && attacker==obj) {
    write(HIR+"Blood continues to gush from "+IT+"'s sliced artery!\n"+NORM);
    say(HIR+"Blood continues to gush from "+IT+"'s sliced artery!\n"+NORM);
    attacker->hit_player(random(5));
    bleed--;
  }

  if(i == 3) {
    write("You accidently nick yourself with the sharp spoon.\n");
    say(ME+" accidently nicks himself with the sharp spoon.\n");
    this_player()->hit_player(2+random(5));
  }
  else if(i == 6) {
    write("You "+HIR+"PLUNGE"+NORM+" the spoon into "+IT+"'s body!\n");
    say(ME+" "+HIR+"PLUNGES"+NORM+" the spoon into "+IT+"'s body!\n");
  }
  else if(i == 9) {
    if(bleed || random(4)) {
      write("You "+HIC+"nearly decapitate "+NORM+IT+" with a wild swing of the spoon!\n");
      say(ME+HIC+" nearly decapitates "+NORM+IT+" with a wild swing of the spoon!\n");
      if(bleed) bleed++;
    }
    else if(obj == attacker) {
      write("You slice clean through one of "+IT+"'s arteries!\n");
      write(HIR+"Blood flows freely from the gaping wound!\n"+NORM);
      say(ME+" slices clean through one of "+IT+"'s arteries!\n");
      say(HIR+"Blood flows freely from the gaping wound!\n"+NORM);
      obj = attacker;
      bleed = 1+random(3);
    }
  }

  return i;

}

