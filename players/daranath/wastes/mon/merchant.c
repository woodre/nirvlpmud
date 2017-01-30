#include <ansi.h>
#define ROOT "/players/daranath/wastes/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object(ROOT+"obj/abi.c"),this_object());
move_object(clone_object(ROOT+"obj/turban.c"),this_object());
move_object(clone_object(ROOT+"wep/sabre.c"),this_object());

     set_name("Habib the Merchant");
     set_short("Habib the friendly Merchant");
     set_alias("habib");
     set_alt_name("merchant");
     set_race("human");
     set_gender("male");
     set_long("Habib owns a store in a far away land that is struggling to find new\n"+
           "items for sale. He has come here looking for you to sell him things \n"+
           "that he can take back home to his shop. His dark skin and piercing\n"+
           "eyes are betrayed by a warm smile. You actually want to sell him\n"+
           "your gear.\n"+
           "You may "+HIY+"<"+NORM+"ask"+HIY+">"+NORM+" him about his services.\n");
     set_level(15);

     init_command("wear abi");
     init_command("wear turban");
     init_command("wield sabre");

     set_ac(12);
     set_wc(18 + random(4));
     set_hp(230 + random(40));
     set_al(700);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(25);
load_chat("Habib takes a quick inventory of the many items he has purchased.\n");
load_chat("Habib smiles at you, while looking over your equipment.\n");
load_chat("Habib says: Hello, have you something to sell?\n");
load_chat("The merchant says: Greetings!  I am Habib, how may I help you???\n");
load_chat("The merchant arranges some items on the back of a small wagon\n");
load_chat("Habib puts away the items he bought from his last supplier.\n");
load_chat("Habib says: Do you have anything you would like to sell me?\n");

   }
}
