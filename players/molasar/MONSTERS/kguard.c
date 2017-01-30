
inherit "obj/monster";

reset(arg) {
   if(arg) return;
    ::reset();
   set_name("guard");
   set_alias("king's guard");
   set_short("King's guard");
   set_long("A very well trained and equipped guardian of the King.\n");
  set_hp(225);
    set_ac(10);
    set_wc(22);
   set_level(15);
   set_al(121);
}

init() {
   ::init();
   if(!attacker_ob)
   if(this_player())
   if(this_player()->query_alignment() < 0) {
     write("Guard shouts:  ATTACK!!!!  PROTECT THE KING!!\n");
     this_object()->attack_object(this_player());
     return 1;
   }
}

