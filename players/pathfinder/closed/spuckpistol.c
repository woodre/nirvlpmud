#define AMMOTYPE "spuckballs"
inherit "obj/weapon";

int total_damage;

reset(arg) {
  ::reset(arg);
  set_name("Spuckball pistol");
  set_alias("pistol");
  set_class(10);
  set_weight(1);
  set_value(1200);
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
  doh = "A Spuckball pistol [" + ammo + "]";
  if(wielded) doh = doh + " (wielded)";
  if(this_player() && this_player()->query_level() > 39) doh = doh + " <Total damage inflicted: [" + total_damage + "]>";
  return doh;
}

long() {
write("The moment you grip the pistol, you are left in a slight bogglement\n"+
  "about the exact function of this thing. Is it a toy? Does it really\n"+
  "work? Judging from what you had to fight in order to get this weapon,\n"+
  "you decide that despite its inherent squishiness, it is indeed a potent\n"+
  "little weapon.\n");
}

load(str) {
  object ammo;
  int rounds2;
  if(!str || str != "pistol") return 0;
    if(present(AMMOTYPE,this_object())) {
    write("The pistol already has a tube in it.\n");
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
    write("Your Spuckball pistol spits out the ammo you tried to shove into it.\n");
  }
  write("The Spuckball tube slides into the grip of the pistol neatly.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " loads a Spuckball pistol.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {   
  write("You point the pistol and shoot at "+capitalize(attacker->query_name())+".\n");
  say(capitalize(this_player()->query_name())+" shoots "+capitalize(attacker->query_name())+" with a Spuckball pistol.\n");
    clip->lose_ammo();
    checked_hit(3);
    if(!rounds()) {
      destruct(clip);
      write("You've shot your last Spuckball!\n");
      return 1;
    }
    return 1;         
  }
  write("Your pistol is out of Spuckballs!\n");
  return -10;
}

rounds() {
  object rc;
  int i;
  rc=present(AMMOTYPE, this_object());
  i=rc->query_ammo();
  return i;
}

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
  }
}

can_put_and_get() { return 1; }
