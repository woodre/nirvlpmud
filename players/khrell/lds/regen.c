inherit "obj/clean";
string cast;

reset(arg) {
   if(arg) return;
  cast = "";
   call_out("effect",1);
}

query_weight() { return 0; }
query_value() { return 0; }
get() { return 1; }
can_get_and_put() { return 0; }
id(str) { return str == "frag_regen"; }

effect() {
  if(!environment()) return 1;
  if(cast == "") { des(); return  1;}
  if(!find_player(cast))  des();
   if(environment() != find_player(cast)) { call_out("des",1); return; }
   if(find_player(cast)->query_hp() == find_player(cast)->query_mhp() || find_player(cast)->query_sp() < 1) { done(); return; }
   find_player(cast)->add_hit_point(4);
   if(random(3)) find_player(cast)->add_spell_point(-2);
   if(random(250) == 1) { done(); return; }
   call_out("effect",3);
  return 1;
}

done() {
  if(find_player(cast)) tell_object(find_player(cast),"The crystal fades....\n");
   call_out("des",1);
return 1;
}

caster(ob) {
   cast=ob->query_real_name();
}
drop() { return 1; }
des() {
   destruct(this_object());
}

init() {
   if(this_player()->query_guild_name() == "shardak")
      add_action("no_cast","toggle");
   if(this_player()->query_guild_name() == "undead") 
      add_action("no_cast","ecnart");
   if(this_player()->query_guild_name() == "vampire") 
      add_action("no_cast","shift");
   if(this_player()->query_guild_name() == "cyberninja")
      add_action("no_cast","rejuvenate");
}

no_cast() {
   write("You can't seem to be able to do that right now.\n");
   return 1;
}
