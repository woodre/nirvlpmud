/*
This weapon can be merged with glowknife.c to form glow_sword.c
Cost is 100 sp and alignment and piety restrictions must be met.
*/
 
#include "/players/snow/closed/cyber/color.h"
 
#define TP this_player()
#define TPN TP->query_name()
#define OP TP->query_attack()
#define OPN OP->query_name()
#define PIE call_other(this_player(),"query_attrib","pie")
#define ALN TP->query_alignment()
#define SWORD "Glass Sword"
#define CO call_other
 
inherit "obj/weapon.c";
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("glass sword");
    set_alias("sword");
    set_short(SWORD);
   set_type("sword");
    set_long(
"A sword made of glass. As you look closer you can see a\n"+
"dagger-shaped indentation in the blade. There are some\n"+
"etchings on the blade as well.\n");
    set_read(
"If you are pure in heart and mind, I may be merged with\n"+
"the dagger of light.\n");
    set_class(15);
    set_weight(1);
    set_value(100);
    set_hit_func(this_object());
}
 
weapon_hit() {
  add_wear(10);
  return;
}
 
init() {
  ::init();
  add_action("merge_knife","merge");
}
 
merge_knife() {
  object ob, ob2;
  ob = present("glowing knife",TP);
  if(!ob) {
    write("You do not have the dagger to merge with this sword.\n");
    return 1; }
  if(PIE < 15 || ALN < 500) {
    write("You are not pure enough in mind and soul to perform the merge.\n");
    return 1; }
  if(TP->query_sp() < 100) {
    write("You do not have enough spell energy to perform the merge.\n");
    return 1; }
  ob2 = clone_object("/players/snow/WEAPONS/glow_sword.c");
  write_file("/players/snow/closed/q/glow", ctime(time())+" "+
    this_player()->query_real_name()+" formed the glowing sword.\n");
  write("You carefully place the parts together and concentrate...\n"+
        "\n\n   You form the "+YELLOW+"Glowing Sword"+OFF+"!\n\n");
  TP->add_spell_point(-100);
  if(ob->wielded()) command("unwield knife",TP);
  if(this_object()->wielded()) command("unwield sword", TP);
  destruct(ob); destruct(this_object());
  move_object(ob2, TP);
  return 1;
}
