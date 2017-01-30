int pleva;
#define AMMOTYPE "zokballs"
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  pleva=3;
  set_name("Zokball slagblower");
  set_alias("slagblower");
  set_class(12);
  set_weight(2);
  set_value(2500);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("load","load");
  add_action("power","power");
  add_action("full_auto","full");
  add_action("burst","burst");
}

short() {
  int ammo;
  object ob;
  ob=present(AMMOTYPE, this_object());
  if(ob) {
    ammo=ob->query_ammo();
  }
  if(wielded) return "A Zokball slagblower [" + ammo + "] (wielded)";
  return "A Zokball slagblower [" + ammo + "]";
}

long() {
write("Sleek and purposeful lines give this weapon a compact and lethal\n"+
  "aura, as you have a burning desire to point and shoot at the next\n"+
  "available sucker that crosses your path.\n");
/*
  write("Not only can this weapon\n"+
  "be wielded normally, but it can be fired in a 'burst' or be let\n"+
  "loose 'full auto'.\n");
 */
write(
  "\n"+
  "A small screw dial can be set given 'power #'.\n");
write("Its analog display reads: 'Power level [" + pleva + "]'.\n");
}

power(str) {
  int i;
  if(sscanf(str, "%d", i) != 1) return 0;
  if(i < 1 || i > 9) {
    write("You boggle at yourself quietly, since the screw dial only goes from 1 to 9.\n");
    return 1;
  }
  write("You turn the dial and set it at [" + i + "].\n");
  say((this_player()->query_name()) + " fiddles with a screw dial of a Zokball slagthrower.\n");
  pleva=i;
  return 1;
}

load(str) {
  object ammo,all_in_ob;
  int rounds2;

  if(!str || str != "slagthrower") return 0;
  all_in_ob = all_inventory(this_object());
  if(sizeof(all_in_ob) > 4) {
    write("There is no room for more Zokballs.\n");
    return 1;
  }
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) {
    write("You don't have any Zokballs.\n");
    return 1;
  } 
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);
  rounds2=ammo->query_ammo();
  if(!rounds2 || rounds2 > 99990) {
    destruct(ammo);
    write("Your Zokball slagthrower blaster rejects the crappy ammo.\n");
  }
  write("You rip open a bag of Zokballs and pour them into the slagthrower.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " rips open a bag of Zokballs and dumps them into a slagthrower.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {   
    if(rounds() < pleva) {
      write("There are not enough Zokballs to make the slagthrower work properly!\n");
      return -17;
    }
  write("A stream of ionized Zokball slag burns into "+capitalize(attacker->query_name())+ "!\n");
  say(capitalize(this_player()->query_name())+" blasts "+capitalize(attacker->query_name())+" with a molten stream of Zokball sludge!\n");
    clip->lose_ammo(pleva);
    if(!rounds()) {
      destruct(clip);
      write("You've shot the last of your Zokballs!\n");
      return 1;
    }
    if(attacker) return random(random(pleva) * random(7));
    if(pleva > 5 && 1==random(130 / pleva)) {
      write("The recoil of the blast knocks you off your feet!\n");
      say((this_player()->query_name())+ " is rocketed clear across the room from the recoil.\n");
      this_player()->run_away();
      return 1;
    }
    return 1;         
  }
  write("Your slagthrower is out of Spuckballs!\n");
  if(pleva && 1 == random(10)) {
    write("The slagthrower charges up for the next shot with a sickening 'GRUNCH!'\n");
    say(capitalize(this_player()->query_name())+ "'s Zokball slagthrower charges up with a sickening 'GRUNCH!'\n");
  }
  return -16;
}

rounds() {
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

can_put_and_get() { return 1; }

query_save_flag() { return 1; }

