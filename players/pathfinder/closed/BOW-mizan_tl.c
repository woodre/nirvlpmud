inherit "obj/weapon";

reset( int arg) {
  ::reset( arg);

  if (arg) return;

  set_name( "Longbow");
  set_class( 16);
  set_weight( 5);
  set_value( 2000);
  set_short( "Longbow");
  set_long( "A beautifully crafted longbow.\n");
  set_hit_func( this_object());		/* "weapon_hit" */
}

mixed weapon_hit( object attacker) {

  if (this_player()) {
    this_player()->fire_ball_object( attacker);
    this_player()->heal_self( 20); /* should double the cost? */
    write( "Octarine flames spurt from the longbow.\n");
  }

  return random(6); /* this is way too high */
}
