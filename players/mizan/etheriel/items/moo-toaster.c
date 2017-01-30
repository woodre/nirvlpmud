#define AMMOTYPE "rawtoast"
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  set_name("toaster");
  set_class(19);
  set_weight(4);
  set_value(14000);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("load","load");
}

short() {
  int ammo;
  object ob;
  ob=present(AMMOTYPE, this_object());
  if(ob) {
    ammo=ob->query_ammo();
  }
  if(wielded) return "The Toaster of Moo [" + ammo + "] (wielded)";
  return "The Toaster of Moo [" + ammo + "]";
}

long() {
write("This is a solidly constructed shiny metal box with two slots\n"+
      "on the top and a big black lever on one side. An electrical cord\n"+
      "dangles uslessly from the side, but the toaster appears to be warm.\n"+
      "You hear a low whispering coming from the toaster, and when you\n"+
      "put it against your year, you hear it say: WIELD ME...I WANT BLOOD!\n"+
      "Feared. You would be a fool if you sold this thing... and you'd be\n"+
      "a god if you could figure out the proper way to use it...\n");
}

load(str) {
  object ammo;
  int rounds2;
  if(!str || str != "toaster") return 0;
    if(present(AMMOTYPE,this_object())) {
    write("The toaster is already loaded.\n");
    return 1;
  }
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) {
    write("You don't have any raw toast.\n");
    return 1;
  } 
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);
  rounds2=ammo->query_ammo();
  if(!rounds2 || rounds2 > 99990) {
    destruct(ammo);
    write("You jammed your toaster with unsatifactory ammo.\n"+
    "Luckily, you unjam it using a twig.\n");
  }
  write("You shove the thin white slices of raw toast into the slots on the toaster.\n");
  write("There are [" + rounds() + "] rounds remaining.\n");
  say(capitalize(this_player()->query_name()) + " shoves some white things into a toaster.\n");
  return 1;
}

weapon_hit(attacker) {
  object clip;
  int ammo;
  clip=present(AMMOTYPE,this_object());
  if(clip) {   
    write("You point the toaster at "+capitalize(attacker->query_name())+" and pull the lever.\n"+
	"PACHUNG! An overcooked slice of toast rockets from your kitchen appliance.\n");
    say(capitalize(this_player()->query_name())+" massacres "+capitalize(attacker->query_name())+" with a slice of burnt toast.\n");
    clip->lose_ammo();
    if(attacker)attacker->hit_player(random(50));
    if(!rounds()) {
      destruct(clip);
      write("You've used up your last slice of toast!\n");
      return 4;
    }
    return 2;         
  }
  write("Your toaster is out of ammo!\n");
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
