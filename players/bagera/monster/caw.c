inherit "obj/monster";
reset(arg) {
::reset(arg);
 if(!arg) {
object gold;
gold=clone_object("obj/money");
gold->set_money(random(500));
move_object(gold, this_player());
set_name("caw");
set_alias("boa");
set_alias("snake");
set_short("Caw, a large boa constrictor");
set_long("A large boa constrictor with colorful swirling eyes\n"+
         "that it uses to hypnotize its prey. His large body\n"+
         "hangs down from a massive branch to meet your\n"+
         "face to face and eye to eye.\n");
set_aggressive(1);
set_ac(12);
set_wc(20);
set_level(15);
set_hp(225);
set_al(-100);
set_chat_chance(35);
load_chat("Caw hisses: Look into my eyessssss.\n");
load_chat("Caw hisses: Your getting sssssleepier.\n");
set_a_chat_chance(45);
load_a_chat("Caw sinks his venomous fangs deep into your flesh.\n");
load_a_chat("Caw's body slithers around you and squeezes the life from you!\n");
    }
  }
