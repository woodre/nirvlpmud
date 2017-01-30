inherit "obj/monster.c";

reset(arg) {
object cam;
int x;
    ::reset(arg);
    if (arg)
	return;
    set_name("liberal");
    set_level(13);
    set_hp(240);
    set_wc(15);
    set_ac(5);
    set_short("A rather depressed looking liberal reporter");
    set_long("This is a liberal reporter who has been complemented by\n" +
             "Rush Limbaugh. As a result his liberal pals have excluded him from\n" +
             "all functions and this is where he ended up.\n");

    set_alias("reporter");
    set_chat_chance(20);
             load_chat("Liberal says: I never realized my collegues were so narrow minded!\n");
             load_chat("Liberal says: Rush was right what is wrong with that?\n");
             load_chat("Liberal says: They will never let me report again!\n");
 cam=clone_object("players/haji/rush/obj/check");
      x=random(578);
      call_other(cam,"set_val",x);
 move_object(cam,this_object());
}
