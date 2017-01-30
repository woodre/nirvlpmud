inherit "obj/weapon.c";
int hit;

reset(arg) {
   hit=(random(29)+21);
   set_name("blood sword");
   set_alias("sword");
   set_short("A Blood Sword");
   set_long("This is a leathal looking rapier. However, three needles\n"
           +"stick out of its hilt. The needles would have to be injected\n"
           +"into the hand when the sword is being used.\n");
   set_class(hit);
   set_weight(5);
   set_value(10000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
int hurt;
hurt = (hit/10);
call_other(this_player(), "add_hit_point", -hurt);
write("you feel like that blow took something out of you.\n");
if(this_player()->query_npc() == 1) {
   destruct(this_object());
   return 1;
}
}

