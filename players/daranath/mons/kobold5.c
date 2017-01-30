inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/items/kobold_tool_belt.c");
     move_object(ob2, this_object());

     set_name("Kobold commoner");
     set_short("Kobold Commoner");
     set_alias("kobold");
     set_alt_name("commoner");
     set_race( "humanoid");
     set_gender("male");
     set_long("Standing about 3 feet tall, the kobold wears a tool belt\n"+
              "about its waist and seems to be working on something. The\n"+
              "blue tattoos run across its arms and torso.\n");
     set_level(5);
     set_ac(5);
     set_wc(7 + random(4));
     set_hp(60 + random(30));
     set_al(-150);
     set_aggressive(0);

   }
}
