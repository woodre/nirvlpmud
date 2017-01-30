inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/obj/mulan_uni.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/mulan_boots.c"),this_object());

     set_name("Mulan");
     set_short("A young girl is chained to the pole");
     set_alias("girl");
     set_alt_name("young girl");
     set_race("human");
     set_gender("female");
     set_long("A young oriental girl is chained to the sacrifce pole, her\n"+
              "arms twisted behind her in an extremly helpless position.\n"+
              "She is wearing the remains of a crimson bodyguard uniform,\n"+
              "the bottom half of which has been torn away, exposing\n"+
              "the lower half of her body. Blood cakes her face and\n"+
              "arms, as she has been severly beaten and tortured.\n");
     set_level(12);

     init_command("wear uniform");
     init_command("wear boots");

     set_ac(9);
     set_wc(15 + random(4));
     set_hp(160 + random(60));
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("The young girl struggles against the chains.\n");
     load_chat("The young girl pleads to you for help against her tormentors.\n");
     load_a_chat("Mulan strikes at you with her chains.\n");

   }
}
