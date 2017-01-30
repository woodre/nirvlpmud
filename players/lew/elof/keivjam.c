inherit "obj/monster";

int move;
object link;
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
    set_hp(500);
    set_whimpy(200);
    set_wc(15);
    set_ac(3);
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
    link=clone_object("players/lew/elof/link");
    move_object(link, this_object());
  call_out("random_move",3);
}
}
random_move() {
  if(!environment(this_object())) return 1;
move = random(7);
if (move == 0)
   command("north");
else if (move == 1)
   command("south");
else if (move == 2)
   command("east");
else if (move == 3)
   command("west");
else if (move == 4)
   command("northeast");
else if (move == 5)
   command("southeast");
else if (move == 6)
   command("southwest");
else if (move == 7)
   command("northwest");
call_out("random_move",1);
}
heart_beat() {
    object pet;
    pet=present("pet", environment(this_object()));
    ::heart_beat();
    if(pet) {
    say("The pet is deresed by keivjam's process.\n");
    destruct(pet);
}
}
