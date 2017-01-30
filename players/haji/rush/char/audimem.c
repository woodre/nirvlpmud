inherit "obj/monster.c";

reset(arg) {
object cam;
int x;
    ::reset(arg);
    if (arg)
	return;
    set_name("dittohead");
    set_level(5);
    set_hp(105);
    set_wc(12);
    set_ac(4);
     set_short("A dittohead");
    set_long("This is a dittohead he has come to see the great Rush.\n");
    set_alias("genius");
    set_chat_chance(20);
      load_chat("Dittohead says: Mega dittos Rush!\n");
      load_chat("The dittohead does the Algore tree clap.\n");
      load_chat("Dittohead says: I can't believe thios country elected that fool!\n");
 cam=clone_object("players/haji/rush/obj/check");
      x=random(150);
      call_other(cam,"set_val",x);
 move_object(cam,this_object());
}
