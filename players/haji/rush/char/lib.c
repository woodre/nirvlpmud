inherit "obj/monster.c";

reset(arg) {
object cam;
int x;
    ::reset(arg);
    if (arg)
	return;
    set_name("liberal");
    set_level(5);
    set_hp(105);
    set_wc(12);
    set_ac(4);
    set_short("A liberal protestor");
       set_long("This is your average commie liberal protestor.\n");
    set_alias("protestor");
    set_chat_chance(20);
      load_chat("Liberal says: this is a great symbolic gesture!\n");
      load_chat("Liberal says: Have a bake sale to pay off the deficit!\n");
      load_chat("Liberal says; I am NOT a hypocrite!\n");
 cam=clone_object("players/haji/rush/obj/check");
      x=random(150);
      call_other(cam,"set_val",x);
 move_object(cam,this_object());
}
