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
    set_short("This is a member of the liberal press");
    set_long("This is a member of the tradition liberal press.\n");

    set_alias("reporter");
    set_chat_chance(20);
              load_chat("Liberal says:  We never report the truth!\n");
              load_chat("Liberal says:  That was a great symbolic gesture.\n");
              load_chat("The liberal wonders if you will ever see through his sham.\n");
 cam=clone_object("players/haji/rush/obj/check");
      x=random(578);
      call_other(cam,"set_val",x);
 move_object(cam,this_object());
}
