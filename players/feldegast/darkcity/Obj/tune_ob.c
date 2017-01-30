#include "../def.h"
inherit "/obj/treasure";

int charges;
reset(arg) {
  if(arg) return;
  set_id("tune_ob");
  set_alias("aura");
  set_long(
    "This is the raw psychic energy used by the strangers to\n"+
     "mold the fabric of reality.  Type <tune_help> for more\n"+
    "information.\n"
  );
  set_weight(0);
  set_value(0);
  charges=6;
  call_out("headache",10);
}
init() {
  ::init();
  add_action("cmd_help","tune_help");
  add_action("cmd_attack","tune");
  add_action("cmd_release","release");
  add_action("cmd_sleep","sleep");
}
get() { return 0; }
drop() { return 1; }

extra_look() {
  if(environment()) {
    return environment()->query_name()+" is surrounded by an aura of crackling psychic energy";
  }
}
headache() {
  object victim;
  int will;
  victim=environment(this_object());
  if(victim && victim->is_player()) {
    victim->heal_self(-random(3*charges));
  tell_object(victim,
    "Your mind strains under the terrible burden of the energies it holds.\n");
  tell_room(environment(victim),victim->query_name()+" winces in pain.\n");
  will=2*victim->query_stat("wil")+victim->query_level();
  }
  call_out("headache",30+(3*random(will)));
}

cmd_help() {
  write(
"You have the following tuning abilities:\n"+
"  tune_help        - this help file\n"+
"  tune             - use the tuning energies in an attack\n"+
"  release energies - release all of the tuning energies at once\n"+
"                     in an area attack\n"+
"  sleep            - use the tuning energies to induce sleep in\n"+
"                     all combatants\n"+
"  tune city        - use your tuning power to change Dark City\n"
  );
  return 1;
}

static cmd_attack(str) {
  object ob;
  int n, ahp;
  if (!str)
  {
    write("Tune what?\n");
    return 1;
  }
  else
    if(str=="city") {
      write("You reach far beneath the city, using your tuning power to\n"+
            "manipulate the great machines.  You sense the Dark City of\n"+
            "the Strangers changing, bending itself to your will.\n");
/* changed path so it works - 6.6.01 verte */
"/players/feldegast/darkcity/controller"->set_city_config(random(4));
      charges--;
      return 1;
    }
    ob = present(str,environment(this_player()));
    if(!ob || !living(ob)) {
      write("Usage: tune <monster>\n");
      return 1;
    }
    if(!ob->is_player()) {
      n = random(30)+20;
      ahp = ob->query_hp();
      if(this_player()->query_sp() < 10 ) {
        write("You don't have enough spell points.\n");
        return 1;
      }
      if(n>ahp) { n = ahp - 1; }
      ob->hit_player(n);
      this_player()->add_sp(-10);
      charges-=1;

      write("You concentrate a devastating bolt of "+
        HIB+"mental energy"+NORM+" at "+ob->query_name()+".\n");
      say(TPN+" concentrates a devastating bolt of "+
        HIB+"mental energy"+NORM+" at "+ob->query_name()+".\n");
      this_player()->attack_object(ob);
      if(living(ob)) ob->attack_object(this_player());
      if (charges <= 0) {
        write("The crackling mental energies disappear.\n");    
        destruct(this_object());
      return 1;
    }
    return 1;
  }
  write("You cannot attack players with this.\n");
  return 1;
}
static cmd_release(str) {
  if(str!="energies") {
    notify_fail("Usage: release energies\n");
    return 0;
  }
  write("You concentrate upon releasing all of your tuning energy in\n"+
        "one great burst.\n");
  say(this_player()->query_name()+" begins concentrating intently upon something.\n");
  call_out("release",random(3),this_player());
  return 1;
}
release(object player) {
  object ob;
  object next;
  int n,ahp;
  tell_room(environment(player),player->query_name()+" releases "+player->query_possessive()+
        " remaining tuning energies in a dazzling\n"+
        "display of psychic pyrotechnics!\n");
  ob=first_inventory(environment(player));
  while(ob && charges>0) {
    next=next_inventory(ob);
    if(living(ob)) {
      if(!ob->is_player()) {
        n = random(30)+20;
        ahp = ob->query_hp();
        if(player->query_sp() >= 10 ) {
          if(n>ahp) { n = ahp - 1; }
          ob->hit_player(n);
          player->add_sp(-10);
          charges-=1;
          tell_room(environment(player),
            ob->query_name()+" is hit!\n");
           player->attacked_by(ob);
           if(living(ob)) ob->attacked_by(player);
        }
      }
    }
    ob=next;
  }
  if (charges <= 0) {
    write("The crackling mental energies disappear.\n");    
    destruct(this_object());
    return 1;
  }
}
static cmd_sleep() {
  object ob;
  if(this_player()->query_sp() < 10) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  tell_room(environment(this_player()),
    this_player()->query_name()+" says: Sleep.\n\n");
  ob=first_inventory(environment(this_player()));
  while(ob) {
    if(living(ob)) {
      if(ob->query_attack()) {
        ob->stop_fight();
      ob->stop_hunted();
      ob->stop_hunted();
        ob->stop_fight();
        tell_room(environment(this_player()),
          ob->query_name()+" sleeps.\n");
      }
    }
    ob=next_inventory(ob);
  }
  charges-=1;
  if (charges <= 0) {
    write("The crackling mental energies disappear.\n");    
    destruct(this_object());
    return 1;
  }
  return 1;

}
