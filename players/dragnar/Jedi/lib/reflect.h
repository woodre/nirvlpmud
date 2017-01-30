Reflect() {
  int new_damage;
  
  new_damage = damage;
  if(new_damage > 50) new_damage = 50;
  tell_object(USER,
    HIM+"-=- You feel the force flow through you "+attack->query_name()+"'s attack"+
    " is reflected back at them!"+NORM+"\n");
  attack->heal_self(-(random(new_damage/(15 - query_skill("reflect")))));
  USER->add_hit_point(damage);
  new_hp += damage;
  old_hp = new_hp;
}
