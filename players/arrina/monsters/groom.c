 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob;
   ob = clone_object("/players/arrina/weapons/crop.c");
 move_object(ob,this_object());
       set_name("groom");
      set_short("A Ghostly Groom");
      set_race( "ghost");
      set_long("A very strong groom.  His hands show strength\n"+
        "brought on by years of caring for the horses.\n");
      set_level(19);
      set_ac(16);
     init_command("wield crop");
      set_wc(28);
      set_hp(475);
      set_al(-1800);
      set_aggressive(0);
      set_chat_chance(20);
       load_chat("Groom says: You must not disturb anything here.\n");
       load_chat("Groom says: I cared for the horses all my life.\n");
       load_chat("Groom says: The horses here were once magnificent!\n");
       }
 }
