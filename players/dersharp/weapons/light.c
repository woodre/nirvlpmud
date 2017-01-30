inherit "obj/weapon";
int att;
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("slaysword");
   set_short("Sword of Slaying");
   set_alias("sword");
   set_long("The Sword of Slaying, the trusty weapon of the Guardian Demons.\n")
   + ("This brilliant piece of work looks like it'll slice clean through anything.\n");
   set_hit_func(this_object());
   set_class(18);
   set_weight(3);
   set_value(5500);
   call_other(this_object(),"set_save_flag",0);
}
weapon_hit(attacker) {
   att=this_player()->query_attrib("int");
   if(random(50) < att) {
      say("The Sword of Slaying slices a hunk clean off!\n");
      write("The Sword takes control of you and forces you to hit DEEP, chopping a hunk off!\n");
   }
}
