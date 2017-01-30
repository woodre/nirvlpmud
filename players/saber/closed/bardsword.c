#define tp this_player()->query_name()
int w,n,ahp;
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("bardsword");
    set_alias("sword");
     set_short("A Crystal Bardsword");
     set_long("An ivory white longsword of gleaming crystal.\n"+
       "It is very light, and has a wicked edge to it.\n"+
       "There is a Bardic rune on the hilt.\n");
    set_class(17);
    set_weight(2);
    set_type("sword"); /* 6.6.01 by verte */
    set_value(10000);
    /*converted to magical dtype illarion 4 dec 2004
    set_hit_func(this_object());
    */
    set_params("magical",0,"magic_hit");
}
/* dtype conversion
weapon_hit(attacker) {
  */
magic_hit(attacker){
   object inst;
   w=random(15);
   /* Bard bonus added by illarion 4 dec 2004 */
   if(inst=present("bard_obj",environment())) 
     w+=inst->query_bard_level()/3;
  if(attacker)
   if (w>11) {
       write("The Bardsword gleams with a pure white fire as it cleaves through your foe.\n");
       write(capitalize(attacker->query_name())+" staggers.\n");
       say(tp+"'s Bardsword gleams with a pure white fire as "+this_player()->query_pronoun()+" cleaves through "+this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_name())+" staggers.\n");
      return 5;
    }
    return;
}
/* it will sing later */
