
inherit "obj/monster";

reset(arg) {
     object ob;
     ::reset(arg);
     if(!arg) {
          set_name("seagull");
          set_race("gull");
          set_level(5);
          set_ep(8000);
          set_hp(40 + random(30));
          set_al(0);
          set_short("a seagull");
          set_long("It looks hungry.\n");
          set_aggressive(0);
          set_chance(20);
          set_a_chat_chance(30);
          load_a_chat("Seagull says: Screeech!\n");
          set_wc(9);
          set_ac(5); 
          ob=clone_object("obj/treasure");
          ob->set_id("feather");
          ob->set_short("a feather");
          ob->set_value(200);
          ob->set_weight(0);
          move_object(ob, this_object()); }
}
