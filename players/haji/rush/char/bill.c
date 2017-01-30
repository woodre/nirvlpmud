inherit "obj/monster.c";

reset(arg) {
object cam;
int x;
    ::reset(arg);
    if (arg)
	return;
    set_name("hippie");
    set_level(9);
    set_hp(211);
    set_wc(14);
    set_ac(5);
    set_short("A long haired hippie");
    set_long("This is the long haired maggot infested hippie\n" +
        "who renounced his citizenship and then wanted it back.\n" +
     "He has come to New York to see Rush and use what small intellect\n" +
     "he has in a futile effort to prove him wrong.\n" +
     "He seems to be having trouble figuring out which building Rush is in.\n");

    set_alias("maggot");
    set_chat_chance(20);
         load_chat("Hippie says: I hate this country!\n");
         load_chat("Hippie says: I love this country!\n");
         load_chat("Hippie says: Maybe I shouldn't have done all those drugs!\n");
 cam=clone_object("players/haji/rush/obj/check");
      x=random(255);
      call_other(cam,"set_val",x);
 move_object(cam,this_object());
}
