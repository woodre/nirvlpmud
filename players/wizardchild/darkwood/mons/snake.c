/* snake.c: typical snake */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("snake");
  set_short("A snake");
  set_long("A venemous looking young snake. It is only 2-3 feet long, and probably isn't\n"
          +"capable of inflicting too much damage. As you approach, it slithers towards\n"
          +"the forest.\n");
  load_chat("The snake slithers.\n");
  set_chat_chance(12);
  set_level(9);
  set_hp(60+random(40));
  set_wc(12);
  set_ac(3);
  set_ep(400);
  set_al(-30);
  move_object(clone_object(ROOT_DIR+"obj/fangs"), this_object());
}
id(str) { return str == "snake"; }
