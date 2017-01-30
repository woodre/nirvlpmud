inherit "obj/monster.c";

reset(arg) {
object cam;
int x;
    ::reset(arg);
    if (arg)
	return;
    set_name("crewman");
    set_level(7);
    set_hp(165);
    set_wc(13);
    set_ac(4);
   set_short("A member of Dave's camera crew");
    set_long("This is a member of the Dave Letterman show's camera crew.\n");
    set_alias("camcrew");
    set_chat_chance(2);
      load_chat("You hear Dave Letterman's voice from the camera: May we see your photos please?\n");
 cam=clone_object("players/haji/rush/obj/cam");
 move_object(cam,this_object());
}
