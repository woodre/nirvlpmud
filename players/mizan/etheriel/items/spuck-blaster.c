#define MASTER_R "/players/mizan/closed/SpuckweaponDM.c"
#define AMMOTYPE "spuckballs"
inherit "obj/weapon";

int total_damage;

reset(arg) {
  ::reset(arg);
  set_name("Spuckball blaster");
  set_alias("blaster");
  set_class(21);
  set_weight(7);
  set_value(31000);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("load","load");
}

short() {
  string doh;
  int ammo;
  object ob;
  ob=present(AMMOTYPE, this_object());
  if(ob) {
    ammo=ob->query_ammo();
  }
  doh = "A heavy Spuckball blaster [" + ammo + "]";
  if(wielded) doh = doh + " (wielded)";
  if(this_player() && this_player()->query_level() > 39) doh = doh + " <Total damage inflicted: [" + total_damage + "]>";
  return doh;
}

long() {
write("You pity the hapless creature that may fall out of your favor, and\n"+
      "winds up in front of the barrel of this weapon. You can easily fit\n"+
      "your head in the barrel of this monstrosity, and a cold, deathly\n"+
      "chill rockets up your spine when you grip the weapon. It is not\n"+
      "the tingling of fear that you feel... but the desire to make someone's\n"+
      "life a living hell.\n");
}

load(str) {
  object ammo,all_in_ob;
  int rounds2;
  if(!str || str != "blaster") return 0;
  all_in_ob = all_inventory(this_object());
  if(sizeof(all_in_ob) > 10) {
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
  write("You pour some Spuckballs into the blaster.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " pours some Spuckballs into a Spuckball blaster.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {
    if(rounds() < 18) {
      write("There are not enough Spuckballs to make the blaster work properly!\n");
      return -17;
    }
  write("B O O M ! ! ! You pity "+capitalize(attacker->query_name())+", who appears to have been hit by a truck.\n");
  say(capitalize(this_player()->query_name())+" blasts the crap out of "+capitalize(attacker->query_name())+" with a Spuckball blaster.\n");
    clip->lose_ammo(18);
    checked_hit(50);
    if(!rounds()) {
      destruct(clip);
      write("You've shot the last of your Spuckballs!\n");
      return 1;
    }
    if(1==random(10) && this_player()->query_level() < 20) {
      write("The recoil of the blast knocks you off your feet!\n");
      say((this_player()->query_name())+ " is rocketed clear across the room from the recoil.\n");
      this_player()->run_away();
      return 1;
    }
    return 1;
  }
  write("Your blaster is out of Spuckballs!\n");
  return -18;
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

checked_hit(arg) {
  int a_hp,a_dam;
  object a_attack;
  a_attack=this_player()->query_attack();
  if(a_attack) {
    a_hp=a_attack->query_hp();
    a_dam=random(arg);
    if(!a_attack->query_npc() && a_dam > 49) a_dam = 50;
    if(a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
    a_attack->hit_player(a_dam);
    total_damage = total_damage + a_dam;
    MASTER_R->reg_blaster_hit(a_dam);
  }
}

