int pleva;
#define AMMOTYPE "spuckballs"
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  pleva=3;
  set_name("Spuckball Supergun");
  set_alias("supergun");
  set_class(19);
  set_weight(2);
  set_value(67000);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("load","load");
  add_action("power","dial");
}

short() {
  int ammo;
  object ob;
  ob=present(AMMOTYPE, this_object());
  if(ob) {
    ammo=ob->query_ammo();
  }
  if(wielded) return "A Spuckball Supergun [" + ammo + "] (wielded)";
  return "A Spuckball Supergun [" + ammo + "]";
}

long() {
write("There is something different about this Spuckweapon... at first it\n"+
  "is hard to get a grasp of, but after a brief study, you realize that\n"+
  "this weapon breaks the Spuck 'norm' in weapon design. It looks\n"+
  "decidedly sinister, instead of playfully harmless, and there is\n"+
  "some kind of digital display embedded in the stock, which is alien\n"+
  "to the design of most Spuck weapons.\n");
  write("\n");
write("It looks like there is a knob here you can control to set the power\n"+
  "level of this weapon. 'dial #' seems to work.\n");
  write("\n");
write("The LCD display reads: 'Power level set at [" + pleva + "]'.\n"); 
}

power(str) {
  int i;
  if(sscanf(str, "%d", i) != 1) return 0;
  if(i < 1 || i > 10) {
    write("The LCD display reads: 'Invalid parameter'.\n");
    return 1;
  }
  write("The Spuckball Supergun is now set at power level [" + i + "].\n");
  say((this_player()->query_name()) + " fiddles the power set control of a Spuckball Supergun.\n");
  pleva=i;
  return 1;
}

load(str) {
  object ammo,all_in_ob;
  int rounds2;

  if(!str || str != "supergun") return 0;
  all_in_ob = all_inventory(this_object());
  if(sizeof(all_in_ob) > 4) {
    write("There is no room for more Spuckballs.\n");
    return 1;
  }
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) {
    write("You don't have any Spuckball tubes.\n");
    return 1;
  } 
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);
  rounds2=ammo->query_ammo();
  if(!rounds2 || rounds2 > 99990) {
    destruct(ammo);
    write("Your Spuckball blaster rejects the crappy ammo.\n");
  }
  write("You pour some Spuckballs into the supergun.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " pours some Spuckballs into a Spuckball Supergun.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {   
    if(rounds() < pleva) {
      write("There are not enough Spuckballs to make the supergun work properly!\n");
      return -17;
    }
  write("You punch a volley of high-velocity Spuckballs at "+capitalize(attacker->query_name())+ "!\n");
  say(capitalize(this_player()->query_name())+" cuts loose with a volley of ultra-velocity Spuckballs at "+capitalize(attacker->query_name())+"!\n");
    clip->lose_ammo(pleva);
    if(attacker)attacker->hit_player(random(random(pleva) * random(10)));
    if(!rounds()) {
      destruct(clip);
      write("You've shot the last of your Spuckballs!\n");
      return 1;
    }
    if(pleva > 5 && 1==random(10)) {
      write("The recoil of the blast knocks you off your feet!\n");
      say((this_player()->query_name())+ " is rocketed clear across the room from the recoil.\n");
      this_player()->run_away();
      return 1;
    }
    return 1;         
  }
  write("Your supergun is out of Spuckballs!\n");
  if(pleva && 1 == random(10)) {
    write("The supergun vibrates a deathly hum as it charges up for the next shot.\n");
    say(capitalize(this_player()->query_name())+ "'s supergun hums and vibrates with a lethal glow!\n");
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

