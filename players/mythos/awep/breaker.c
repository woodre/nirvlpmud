inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("breaker");
  set_alias("breaker");
  set_short("Weapon Breaker");
  set_long("A Weapon Breaker- it looks like a two pronged metal weapon.\n"+
    "Basically, it is a JITTE. Often used by\n"+
    "the police in Ancient Japan.\n");
  set_class(16);
  set_weight(1);
  set_value(600);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
int W;
object ob;
W=random(3);
if(W==0) {
  ob=first_inventory(attacker);
  if(ob->weapon_class() > 0) {
    if(attacker->query_weapon() == ob) {
      ob->weapon_breaks();
    write("You break the "+ob->short()+"!\n");
}}
  ob=next_inventory(attacker);
return 4;
}
return; }
