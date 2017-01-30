inherit "room/room";

reset(arg) {

  object dog;
  if (!arg){
    set_light(0);
    short_desc = "Kennel Room";
      long_desc = 
        "You have entered the kennel where the hell hounds are kept.  In the corner\n" +
        "is the lead dog.  You are surely no match for this dog.  He is responsible for\n" +
        "watching over the prison, should the guards fail.\n\n";
    dest_dir = 
        ({
                "players/paulasx/prison/cellhall6.c", "west",
        });
     }

  if(!present("dog", this_object())){
    dog=clone_object("obj/monster");
    call_other(dog,"set_name","dog");
    call_other(dog,"set_level",15);
    call_other(dog,"set_hp",350);
    call_other(dog,"set_wc",30);
    call_other(dog, "set_ac", 10);
    call_other(dog, "set_dead_ob", this_object());
    call_other(dog,"set_short","A DEMON dog");
    call_other(dog,"set_long",
               "A ball of fur and teeth. There is blood dripping\n"+
               "from its mouth.  You should have never entered this room!!\n");
    call_other(dog,"set_al",-200);
    move_object(dog,this_object());
  }
}

monster_died() {
  object cash;
  write("You find some coins beneath the demon dog's mat.\n");
  cash=clone_object("/obj/money.c");
  cash->set_money(600+5*random(80));
  move_object(cash,this_object());
}
