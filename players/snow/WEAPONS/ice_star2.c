/*Multiple hit one-use projectile weapon*/
 
#define MT TP->query_attack()
#define MN MT->query_name()
#define ME this_player()->query_name()
#define TP this_player()
#define PS this_player()->query_possessive()
 
inherit "obj/weapon.c";
 
int dam,mhp,parts;
 
init() {
  ::init();
  add_action("throw_star","shuriken");
  }
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shuriken");
    set_alias("star");
    set_short("Ice Shuriken");
    set_long(
"This is an Ice Shuriken- a deadly throwing star made of shining\n"+
"crystals of ice. You can wield it or 'shuriken' an opponent.\n");
    set_class(12);
    set_weight(1);
    set_value(150);
    set_hit_func(this_object());
call_out("melt_star", 2000);
}
 
weapon_hit() {
  string mid;
  mid = MT->id();
  if(mid == "demon" || mid == "devil" ||
     mid == "dragon" || mid == "efreet") {
    MT->heal_self(-random(5)-4); }
  if (random(11) > 8) {
    say(
ME+" slices through "+MN+" with "+PS+" Ice Shuriken!\n");
    write(
"You slice through "+MN+" with your Ice Shuriken!\n");
  return 3;
  }
return 1;
}
 
melt_star() {
  if(wielded) {
    say("Your Ice Shuriken melts from your grasp!\n");
    command("unwield shuriken",environment(this_object()) );
    destruct(this_object());
  return 1;
  }
  say("The Ice Shuriken melts away...\n");
  transfer(this_object(), "/players/snow/storage.c");
  return 1;
}
 
throw_star(str)  {
  object ob;
  string sliver;
  string meat;
  if(TP->query_level() < 10)  {
    write("Your skills are too few to use this.\n");
  return 1; }
  if(!str) { write("Shuriken what?\n"); return 1; }
  ob = present(str,environment(this_player()));
  if(!ob || !living(ob)) {
  write("To use: 'shuriken <monster>'.\n"); return 1;  }
  if(!ob->query_npc()) { 
    write("Ice Shuriken cannot be thrown at players.\n");
    return 1; }
  meat = capitalize(str);
  dam = random(12)+ 6;
  mhp = ob->query_hp();
  parts = random(3) + 2;
  sliver = "A sliver of ice rips into the "+meat+"\n"+
           "The "+meat+" screams in pain!\n";
  say(ME+" throws "+PS+" Ice Shuriken at the "+meat+" !\n"+"\n");
  write("The Shuriken splits apart as you throw it!\n"+"\n");
  say("The Shuriken splits apart!\n");
  while(parts > 0) {
    tell_room(environment(TP), sliver);
    ob->heal_self(-dam);
    parts --; }
  if(!ob->query_attack()) {
  TP->attack_object(ob);
  ob->attack_object(this_player()); }
  destruct(this_object());
  return 1;
}
