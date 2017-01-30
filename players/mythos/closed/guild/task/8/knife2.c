#include "/players/mythos/closed/ansi.h"
int n;
string msg;
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("drakis");
  set_alias("knife");
  set_short("? knife ?");
  set_long("The blade of this knife seems formless, the blade shifts \n"+
          "from shape to shape- one second its a blade of fire, the\n"+
          "next it is a pick of ice....\n");
  set_class(3);
  set_weight(1);
  set_value(50);
  n = 0;
  set_hit_func(this_object());
}

query_save_flag() { return 1;}

weapon_hit(attacker){
if(random(3) == 0) {
   tell_room(environment(this_player()),"A brilliant \n\t\t"+CYN+"flash"+NORM+"\n"+
              "occurs!  Energy fills the room and the smell of burnt flesh is in the air!\n");
   return n; }
   return;
}

init() {
  ::init();
  if(this_player()->is_player()) {
    switch(random(10)) {
      case 0: msg = "You feel intense pain as the blade\n"+
                    "flares into a burning flame!";
                    this_player()->add_hit_point(-20);
                    n = 30;
                    break;
      case 1: msg = "Something whispers incoherently...";
              n = random(30);
              break;
      case 2: msg = "The blade vanishes!";
              this_object()->set_class(18);
              n = 7;
              this_player()->add_spell_point(-(this_player()->query_sp()));
              break;
      case 3: msg = "You feel FEAR!";
              n = 18;
              break;
      case 4: msg = "The blade turns into stone.";
              n = 1;
              this_object()->set_class(15);
              break;
      case 5: msg = "You suddenly feel sick.";
              n = - random(100);
              this_object()->set_class(16);
              break;
      case 6: msg = "The blade freezes into a shard of ice.";
              this_object()->set_class(20);
              n = 5;
              this_player()->hit_player(40);
              break;
      case 7: msg = "The blade wavers and slowly forms into an iron spike.";
              this_object()->set_class(3+random(15));
              n = random(7);
              this_player()->add_spell_point(-random(100));
              break;
      case 8: msg = "The knife flares and turns red.";
              this_object()->set_class(18);
              n = 10;
              this_player()->set_ac(-5);
              break;
      case 9: msg = "The blade turns dark...";
              this_object()->set_class(30);
              n = -10;
              this_player()->hit_player(100);
              this_player()->set_ac(-10);
              break;
   }
   tell_object(this_player(),msg+"\n");
   }
}
