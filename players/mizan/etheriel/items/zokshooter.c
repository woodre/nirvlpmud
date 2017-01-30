#define AMMOTYPE "zokballs"
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  set_name("Zokball shooter");
  set_alias("shooter");
  set_class(15);
  set_weight(2);
  set_value(5400);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("load","load");
  add_action("strap","strap");
}

strap(str) {
  if(!str || str != "shooter") return 0;
  wield(str);
}

short() {
  int ammo;
  object ob;
  ob=present(AMMOTYPE, this_object());
  if(ob) {
    ammo=ob->query_ammo();
  }
  if(wielded) return "A Zokball shooter [" + ammo + "] (strapped)";
  return "A Zokball shooter [" + ammo + "]";
}

long() {
write("Developed by the Zok to compete with the venerable Spuck line\n"+
      "of weapons, this shooter is an example of why Zok are gaining\n"+
      "popularity in the profitable business of arms sales.\n"+
      "On the cutting edge of ether-technology, the shooter is about\n"+
      "as powerful as the respected Spuckball Rifle.\n"+
      "This is a different kind of weapon, as it must be 'strapped',\n"+
      "instead of being 'wielded'.\n");
}

load(str) {
  object ammo,all_in_ob;
  int rounds2;

  if(!str || str != "shooter") return 0;
  all_in_ob = all_inventory(this_object());
  if(sizeof(all_in_ob) > 2) {
    write("There is no room for more Zokballs.\n");
    return 1;
  }
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) {
    write("You don't have any Zokball tubes.\n");
    return 1;
  } 
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);
  rounds2=ammo->query_ammo();
  if(!rounds2 || rounds2 > 99990) {
    destruct(ammo);
    write("The shooter rejects the crappy ammo.\n");
  }
  write("You force some Zokballs into the shooter.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " pours some Zokballs into a Zokball shooter.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {   
    if(rounds() < 2) {
      write("There are not enough Spuckballs to make the rifle work properly!\n");
      return -14;
    }
    write("You shoot "+capitalize(attacker->query_name())+" with a burst of Zokballs.\n");
    say(capitalize(this_player()->query_name())+" shoots "+capitalize(attacker->query_name())+" with a Zokball shooter.\n");
    clip->lose_ammo(2);
    if(attacker)attacker->hit_player(random(6));
    if(!rounds()) {
      destruct(clip);
      write("You've shot your last Zokball!\n");
      return 1;
    }
    return 1;         
  }
  write("Your shooter is out of Zokballs!\n");
  return -14;
}

rounds() {
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

can_put_and_get() { return 1; }
