/* Added weapon hit and added 1000 to value. Weapon found on ungwe.c
   -Snow */
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("sting");
   set_alt_name("stinger");
   set_alias("sting");
   set_short("Ungweliante's sting");
   set_long("This is Ungweliante's sting, a weapon weeping poisoned blood.\n");
   set_class(18);
   set_weight(2);
   set_value(1800);
   set_hit_func(this_object());
}

weapon_hit() {
  if(1 == random(3)) {
    write("Venomous acid drips from your blade!\n");
    say(this_player()->query_name()+"'s Sting drips venomous acid!\n");
    return 4;
  }
  return 0;
}
