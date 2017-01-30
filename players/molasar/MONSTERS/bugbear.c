
inherit "obj/monster";

reset(x) {
    if(x) return;
   set_hp(120);
   set_ac(5);
   set_wc(12);
   set_name("bugbear");
   set_alias("bear");
   set_race("bugbear");
   set_short("A bugbear");
   set_long("A ferocious looking bugbear.\n");
   set_level(8);
   set_al(-213);
   set_can_kill(1);
   ::reset(0);
}

init() {
   if(this_player()->query_race() != "bugbear") {
      this_object()->attack_object(this_player());
     return 1;
   }
}

