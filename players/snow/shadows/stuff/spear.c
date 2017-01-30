#define TP this_player()
#define TO this_object()
#define TON TO->query_name()
#define TPN capitalize(TP->query_name())
#define GUILD TP->query_guild_name()
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define GEN TP->query_possessive()
#define RACE (TP->query_race() == "shadowcreature")
 
int shwear;
int shextra;
 
inherit "obj/weapon.c";
 
set_shadow_extra(se) { shextra = se; }
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shadow spear");
    set_alias("spear");
    set_alt_name("shadoweap");
    set_short("A dusky spear");
    set_type("spear");
    set_long(
"A hunting spear used by denizens of the shadow plane.\n");
    set_class(random(3)+14);
    set_weight(1);
    set_value(400);
    set_hit_func(this_object());
    set_shadow_extra(6);
  shwear = 0;
}
weapon_hit(attacker) {
  int W, dam;
W = random(20);
  if(random(1000) < shwear) {
    say(TPN+"'s "+TON+" shatters into pieces!\n");
    write("Your "+TON+" shatters into pieces!\n");
    command("unwield shadoweap",TP);
    destruct(TO);
  return 1;
  }
  if(!(GUILD == "shadow" || RACE)) {
    shwear = shwear + 1;
  }
  if(!random(3))
  if(MEAT->query_race() == "shadowcreature") {
    write("Your spear bites into "+MEATN+"!\n");
    dam = shextra;
    if(dam > MEAT->query_hp()) dam = (MEAT->query_hp() - 1);
    if(GUILD || RACE) {
      MEAT->hit_player(dam);
    }
    if(!(GUILD || RACE)) {
      MEAT->hit_player(dam/3);
    }
  }
  if(W > 15)  {
  say(TPN+" sinks "+GEN+" spear deep into "+MEATN+"!\n");
  write("You sink your spear deep into "+MEATN+"!\n");
return (random(5)); 
   }
       return;
}
