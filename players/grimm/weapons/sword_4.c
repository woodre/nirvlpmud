inherit "obj/weapon";
reset(arg) {
  if(arg) return;
  set_name("Butter Knife");
  set_short("Butter Knife");
  set_long("This once spread the butter on bread, now it spreads the enemy"+
" on the\nbattlefield.\n");
  set_weight(1);
  set_class(4);
  set_alias("knife");
  set_value(7);
  set_read("'Sword by Grimm'\n");
}
