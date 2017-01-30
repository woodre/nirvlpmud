

int fire, attack;
string me, monster;

reset() { fire = 0; }

get() { return 1; }

id(str) { return str == "bracelet" || str == "autofire bracelet"; }

short() { return "An autofire bracelet"; }

long() {
   write("An automatic fireball bracelet. To use - fire <monster>\n");
}

init() {
   add_action("fire","fire");
}

fire(str) {
   if(!str || sscanf(str, "%s", monster) != 1) {
     write("Fire who?\n");
     return 1;
   }
   if(this_player()->query_level() < 15) {
     write("You are not able to use the fireball spell.\n");
     return 1;
   }
   if(!present(find_living(monster), environment(this_player())) ||
      !find_living(monster)) {
     write(capitalize(monster)+" is not here.\n");
     return 1;
   }
   me = this_player()->query_real_name();
   fire = 1;
   set_heart_beat(1);
   write("The bracelet glows.\n");
   return 1;
}

heart_beat() {
    if(fire == 1 && find_player(me)->query_spell_point() >= 20) {
      find_living(monster)->hit_player(random(40));
      if(!attack) {
        find_living(monster)->attack_object(find_player(me));
        attack = 1;
      }
      find_player(me)->add_spell_point(-20);
      tell_object(find_player(me), "You cast a fireball at "+
        capitalize(monster)+".\n");
      tell_room(environment(find_player(me)), capitalize(me)+" hits "+
        capitalize(monster)+" with a fireball.\n");
      return 1;
    } else
    tell_object(find_player(me), "The bracelet darkens.\n");
    fire = 0;
    set_heart_beat(0);
}

