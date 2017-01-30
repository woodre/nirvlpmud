do_hw(str) {
  object *world;
  int i,max;

  if(TP->query_sp() < 10)
  {
    write("You do not have sufficient mana.\n");
    return 1;
  }

  TP->add_spell_point(-10);

  max=sizeof(users());
  world=users();

  write("_________________________________________________________________\n");
  write(" Name        Level   Guild    Room\n");
  write("_________________________________________________________________\n");
  for(i=0;i<max;i++) {
    if(world[i]->query_pl_k())
      write(RED+"*"+NORM);
    else
      write(" ");
    if(world[i]->query_invis() < TP->query_level())
    {
      if(world[i]->query_ghost())
        write(pad((string)world[i]->query_real_name(),12));
      else
        write(pad((string)world[i]->query_name(),12));
      write(pad((string)world[i]->query_level()+"+"+world[i]->query_extra_level(),7));
      write(" ");
      write(pad((string)world[i]->query_guild_name(),4));
      write(" ");
      if(environment(world[i])) {
        if((string)environment(world[i])->realm()=="NT")
          write(HIB+"X"+NORM);
        else
          write(" ");
        if(world[i]->query_fight_area())
          write(RED+"*"+NORM);
        else
          write(" ");
        if((string)environment(world[i])->realm() == "NM")
          write(MAG+"#"+NORM);
        else
          write(" ");
        write(" ");
        write((string)environment(world[i])->short());
      }
    }
    write(NORM+"\n");
  }
  write(
"_________________________________________________________________\n"
  );
  return 1;
}
