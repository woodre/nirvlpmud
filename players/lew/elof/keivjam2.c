inherit "obj/monster";

int move;
object head;
reset(arg) {
  ::reset(arg);

  if(!arg) {

    set_name("keivjam");
    set_alias("toejam");
   set_long("If you have ever wondered what causes the intense lag here.\n"+
            "Well here is part of the problem.  His name is James Keivom.\n"+
            "And he has this massive fettish with opening umpteen hundred\n"+
            "windows on elof so he can do things like: read a book,\n"+
            "calculate pie to the nearest quad-billionth place, basically\n"+
            "doing anything that can cause lag.  It is this fettish for\n"+
            "windows of his that has aquired him the title...\n"+
            "              Dances With Windows                          \n");
    set_level(19);
    set_hp(5000);
    set_wc(20);
    set_ac(12);
    set_aggressive(1);
    set_chat_chance(45);
    load_chat("Keivom says: I no creatum lag.\n");
    load_chat("Keivom says: Only mud can causum lag.\n");
    load_chat("Keivom begins working on ways to create lag.\n");
    set_a_chat_chance(100);
    load_a_chat("Keivom says: Ug, why you attack me. Me no cause lag.\n");
    load_a_chat("Keivom starts to crash the mud.\n");
    set_chance(30);
    set_spell_dam(20);
    set_spell_mess1("Keivjam blasts you with lag.\n");
    set_spell_mess2("Keivjam calls upon the lag demons from hell to take your soul.\n");
    head=clone_object("players/lew/elof/head");
    move_object(head, this_object());
}
}
