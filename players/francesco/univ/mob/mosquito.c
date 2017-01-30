inherit "obj/monster";


reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("fly");
   set_race("mosquitos");
   set_alias("fly");
      set_short("A fly");
     set_long("How boring this fly!  You'd better kill it as soon as possible.\n");

   set_level(3);
   set_hp(15);
   set_al(-20);
   set_wc(6);
   set_ac(3);
}
