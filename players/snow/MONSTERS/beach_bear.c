inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob,ob2;
  ob = clone_object("/obj/treasure");
call_other(ob,"set_id","pelt");
call_other(ob,"set_short","Beach Bear pelt");
call_other(ob,"set_value",1200);
call_other(ob,"set_alias","bear pelt");
call_other(ob,"set_long",
"A huge bearskin, this pelt should be worth quite a bit.\n");

   move_object(ob,this_object());


     set_name("beach bear");
     set_short("A large grey bear");
     set_race( "bear");
     set_alias("bear");
    set_long("A hungry-looking bear that scavenges on the arctic beaches.\n");
     set_level(18);
     set_ac(5+ random(10));
     set_wc(20 + random(20));
     set_hp(325+random(150));
     set_al(0);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The beach bear growls at you.\n");
     load_chat("The beach bear walks toward you, sniffing your scent.\n");
     load_a_chat("The beach bear roars in anger!\n");
     load_a_chat("The beach bear rears up on its hind legs!\n");
   }
}
