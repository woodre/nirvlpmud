
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
   if(arg) return;
     set_name("longsword");
     set_alias("elven longsword");
     set_short("An elven longsword");
     set_long("An elven longsword manufactured of an unknown metal.\n");
     set_weight(1);
     set_class(16);
     set_value(1000);
     set_hit_func(this_object());
}

query_save_flag() { return 1;}
weapon_hit(attacker) {
     if(call_other(attacker,"query_alignment") > 500) {
       write("Your blade jumps out of your hand!\n");
       command("drop elven longsword", this_player());
     }
   if(random(3) > 0) return 0;
     if(call_other(attacker, "query_alignment") < 500) {
       write("The longsword hits for a second attack!\n");
       call_other(attacker, "hit_player", random(20));
       return 1;
     }
     if(call_other(attacker, "query_alignment") < 0) {
       write("The longsword hits for a second attack!\n");
       call_other(attacker, "hit_player", random(10));
     }
}

