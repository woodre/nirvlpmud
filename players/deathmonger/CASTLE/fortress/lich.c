
object lich, money, book;
reset(arg) {
     if (!arg)
     set_light(1);
     extra_reset();
}


extra_reset(){
     if(!present("lich")){
     lich = clone_object("obj/monster");
     lich->set_name("lich");
     lich->set_level(18);
     lich->set_hp(450);
     lich->set_short("A lich");
     call_other(lich, "set_long",
     "Liches are undead wizards who have sought eternal life in the worst\n"+
     "possible way.  They are evil, rotten creatures, hating everyone and \n"+
     "ruining life for mortals whenever they can.  Their magical abilities\n"+
     "make them dangerous foes.\n");
     lich->set_wc(15);
     lich->set_ac(10);
     lich->set_chance(55);
     lich->set_spell_dam(25);
     lich->set_spell_mess1("The lich mumbles a horrible chant.\n");
     lich->set_spell_mess2("The lich smashes you with his power!\n");
     money = clone_object("obj/money");
     money->set_money(random(1500));
     move_object(money, lich);
     move_object(lich, this_object());
}
}


init(){
add_action("west","west");
add_action("east","east");
}

east(){
     call_other(this_player(),"move_player",
       "east#players/deathmonger/CASTLE/fortress/corridor2");
return 1;
}

west(){
     if(present("lich")){
       write("The lich casts a wall in front of you.\n");
       return 1;
}
     call_other(this_player(),"move_player",
       "west#players/deathmonger/CASTLE/fortress/dracolich");
     return 1;
}
short(){
  return "The Lich's Room";
}

long(){
     write("You enter a crypt-like room full of spiderwebs and dust.\n");
     write("The light is rather dim here, and there are hundreds of spell-\n");
     write("books scattered about the room.  You see a dark cloaked figure\n");
     write("intensely studying one of the books and you wonder if you ought\n");
     write("to be doing the same.\n");
     write("There are two obvious exits:  east and west\n");
}
