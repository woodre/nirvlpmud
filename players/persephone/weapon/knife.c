inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("knife");
    set_alias("sword");
    set_short("A Carving Knife");
    set_long("A large sharp carving knife used for carving people\n");
    set_class(20);
/* not needed -Bp.
    set_save_flag(0);
*/
    set_weight(4);
/* Changed value from 155,000 to 5000 -Snow 2/99 */
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){

/* added in the add_hit_point() part because this weapon was
  just a wc 20 with the return of hit_player(15) + 1
  it is now a wc20 retuurn of hit_player(10) + 0 and return -1 if special doesnt go off
  plus random(7) chance of doing 1-10 damage to player
                                   -mythos <11/6/95>
*/
  if(random(7)==0) {
    write("The knife slips in your hand!\nYou cut yourself!\n");
/* added in a death thingy [5.31.01] Vertebraker */
    this_player()->add_hit_point(-random(10)-1);
     if((int)this_player()->query_hp() <= 0 && !this_player()->query_ghost())
      this_player()->hit_player(1000);
  }
   if(call_other(this_player(), "query_attrib", "str") > random(100)) {
      write("You start to slice up your foe like a Sunday Roast.\n");
      write("The Blade of the knife slices deeply into your opponent.\n");
      attacker->hit_player(10);
      return 0;
   }
   return -1;
}
