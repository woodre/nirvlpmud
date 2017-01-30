inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/weps/unded_blade.c"),this_object());
move_object(clone_object("/players/daranath/arms/unded_helm.c"),this_object());
move_object(clone_object("/players/daranath/arms/unded_armor.c"),this_object());
 ob = clone_object("obj/money");
 ob->set_money(random(200)+200);
  move_object(ob, this_object());

     set_name("Undead Knight");
     set_short("An Undead Knight stands here");
     set_alias("knight");
     set_race("undead");
     set_gender("creature");
     set_long("Darkened armor and the silver blade stand out as the corpse\n"+
              "of a nobleman from long ago stands before you, his flesh long\n"+
              "since fallen from his valiant frame. Red pin points of bright\n"+
              "flame stand out as a set of penetrating eyes, boring into\n"+
              "your soul from afar. This abomination must be put down!\n");
     set_level(20);

     init_command("wield blade");
     init_command("wear armor");
     init_command("wear helmet");

     set_ac(20);
     set_wc(30 + random(4));
     set_hp(500 + random(50));
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(20);
     load_a_chat("The undead thirst for the taste of the living.\n");
     load_a_chat("The undead knight howls: Protect the Warlord.\n");
     load_a_chat("The chill of the afterlife has never been more real.\n");

   }
}
