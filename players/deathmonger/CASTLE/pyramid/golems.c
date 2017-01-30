
reset(arg){
     if(!arg)
     set_light(1);
     extra_reset();
}
object golem;

extra_reset(){
     int i;
     i = 0;
     if(!golem || !present("golem")){
     while(i<3){
     i += 1;
     golem = clone_object("obj/monster");
     golem->set_name("golem");
     golem->set_alias("bone golem");
     golem->set_level(12);
     golem->set_wc(16);
     golem->set_ac(10);
     golem->set_aggressive(1);
     golem->set_hp(180);
     golem->set_short("A bone golem");
     call_other(golem, "set_long",
     "These are artificial life forms created by wizards.  Formed from bone,\n"+     "bone golems are invulnerable to your puny magic spells.  They are\n"+
     "automotons without any intelligence or emotions.\n");
     move_object(golem, this_object());
}
}
}

init(){
     add_action("fireball","fireball");
     add_action("fireball","fi");
     add_action("shock","shock");
     add_action("shock","sh");
     add_action("west","west");
     add_action("east","east");
}
long(){
     write("You stand in the foyer of the Great Pyramid.  There are bone\n");
     write("golems guarding the entrance to the main crypt.  Don't expect\n");
     write("any mercy from them as they are unintelligent, emotionless\n");
     write("automotons.\n");
     write("There are two obvious exits:  east and west.\n");
     return 1;
}

short(){
     return "The foyer of the Great Pyramid (Golems)";
}

fireball(){
     write("The fireball just bounces off the golem.\n");
     return 1;
}

shock(){
     write("The electricity doesn't even stun the golem.\n");
     return 1;
}

east(){
     call_other(this_player(), "move_player",
       "west#players/deathmonger/CASTLE/pyramid/crypt");
     return 1;
}
west(){
     call_other(this_player(), "move_player",
       "west#players/deathmonger/CASTLE/pyramid/entrance");
     return 1;
}
