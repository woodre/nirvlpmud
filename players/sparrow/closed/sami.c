inherit "/obj/weapon";

#include <ansi.h>

void reset(int arg){
    if(arg) return;
    ::reset(arg);
    set_name("sword");
	set_params("other|fire",1000,0);
	set_params("other|earth",1000,0);
	set_params("other|light",1000,0);
	set_params("other|evil",1000,0);
	set_params("other|laser",1000,0);
	set_params("other|good",1000,0);
    set_short("sami's Sword");
    set_long("A long crooked Sword. It is stained with "+HIR+"Blood"+NORM+" .\n");
    set_class(20);
    set_weight(1);
    set_value(100);
    set_hit_func(this_object());
}

int weapon_hit(object attacker){
    if(random(50) < this_player()->query_attrib("int")){
        say(HIW+"Lightning "+NORM+"leaps from sami's sword to spite "+attacker->query_name()+"!\n");
        write("Your staff strikes "+attacker->query_name()+" with "+HIW+"lightning"+NORM+"!\n");
        return 5000;
    }
}


void init() {
  ::init();
  if (environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "sami" &&
      (string)this_player()->query_real_name() != "samitest") {
    write("Foolish child, this is not yours!\n");
    destruct(this_object());
    return;
  }
  add_action("sami_heal", "restore");
  add_action("dirty_money", "cash");
  add_action("sami_home", "home");
  add_action("sami_church", "church");
  add_action("sami_shinshi", "shinshin");
  add_action("sami_coinarea", "myarea");
}

status sami_heal() {
  this_player()->heal_self(1000);
  write("You have been "+HIR+"HEALED"+NORM+".\n");
  return 1;
}

status dirty_money() {
  int curr;
  curr = (int)this_player()->query_money();
  this_player()->add_money(80000 - curr);
  write(""+HIY+"Cash"+NORM+" set to "+HIY+"80k."+NORM+"\n");
  return 1;
}

status sami_home() {
  this_player()->move_player("home#players/sami/workroom.c");
  write("duces!\n");
  return 1;
}

status sami_church() {
  this_player()->move_player("home#room/church.c");
  write("duces!\n");
  return 1;
  }
  
  status sami_shinshi() {
  this_player()->move_player("home#players/shinshi/workroom.c");
  write("duces!\n");
  return 1;
  }
  
  status sami_coinarea() {
  this_player()->move_player("home#players/sami/area/coinarea/r1.c");
  write("duces!\n");
  return 1;
  }