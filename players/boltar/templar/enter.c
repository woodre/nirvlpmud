reset(arg)
{
    if (!arg)
	set_light(1);
    extra_reset();
}

extra_reset()
{
    object guard, armor, weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
    if (!present("guard")) {
	while(i<5+random(3)) {
	    i += 1;
	    guard = clone_object("obj/monster.talk");
	    call_other(guard, "set_name", "guard");
	    call_other(guard, "set_level", random(2) + 17);
	    call_other(guard, "set_hp", 900+random(50));
	    call_other(guard, "set_al", 60);
	    call_other(guard, "set_short", "A Templar guard");
	    call_other(guard, "set_ac", 0);
	    call_other(guard, "set_aggressive", 0);
	    call_other(guard, "set_a_chat_chance", 50);
	    n = random(3);
	    weapon = clone_object("obj/weapon");
	    if (n == 0) {
		w_name = "Short Sword";
		class = 17;
		value = 930;
		weight = 3;
		alt_name = "sword";
	    }
	    if (n == 1) {
		w_name = "Battle Axe";
		class = 16;
		value = 930;
		weight = 3;
		alt_name = "axe";
	    }
	    if (n == 2) {
		w_name = "hand axe";
		class = 15;
		value = 900;
		weight = 2;
		alt_name = "axe";
	    }
	    call_other(weapon, "set_name", w_name);
	    call_other(weapon, "set_class", class);
	    call_other(weapon, "set_value", value);
	    call_other(weapon, "set_weight", weight);
	    call_other(weapon, "set_alt_name", alt_name);
	    transfer(weapon, guard);
	    call_other(guard, "init_command", "wield "+w_name);
            guard->set_wc(28);
	    move_object(guard, this_object());
            n=random(2);
            armor = clone_object("obj/armor");
            armor->set_weight(4);
            armor->set_type("armor");
            armor->set_value(1800);
            if (n=0) {
               armor->set_name("chainmail");
               armor->set_ac(3);
               armor->set_short("White Chainmail armor");
               armor->set_long("Templar Chainmail Armor\n");
           }
            if (n=1) {
               armor->set_name("platemail");
               armor->set_ac(4);
               armor->set_short("White Platemail armor");
               armor->set_long("Templar Platemail Armor\n");
           }
           transfer(armor,guard);
           call_other(guard,"init_command","wear armor");
           guard->set_ac(17);
	}
    }
}
init()
{
    add_action("southwest"); add_verb("southwest");
    add_action("east","east");
    add_action("north"); add_verb("north");
    add_action("up","up");
}

north()
{
    if(present("guard") && !present("KnightTemplar", this_player()) ){
	write("A guard bars your way.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "north#players/boltar/templar/armory");
    return 1;
}

southwest()
{
    call_other(this_player(),"move_player", "southwest#room/south/sshore1");
    return 1;
}
east(){
  this_player()->move_player("east#players/boltar/templar/recruit");
  return 1;
}

long()
{
     write("This a very richly decorated room, hanging on the walls are\n"+
           "various tapestries, the largest white with a red cross.\n"+
           "The floor is a perfect white marble pollished to a high gloss.\n"+
           "High on the walls are many small statues depicting various\n"+
           "aspects of the Templars' life and religion.\n");
    write("There is an entrance to a small room to the north.\n");
    write("There is a staircase leading upwards in the corner.\n");
    write("There is a large open archway to the east.\n");
    write("The Castle gates are to the southwest.\n");
}

short() {
    return "Entrance of the Templar Castle";
}
up()
{
    if(present("guard") && !present("KnightTemplar", this_player()) ){
	write("A guard bars your way.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "up#players/boltar/templar/tower1");
    return 1;
}
weapon_hit(att) {
int i;
object check;
check = allocate(20);
   check = all_inventory(environment(att));
   i = 0;
   while (i<sizeof(check)){
  write(check[i]);
 write("\n");
   if(check[i])
     if(check[i]->query_name()=="guard" && !check[i]->query_attacker()) {
       check[i]->attack_object(att);
     }
   }
return 1;
}
