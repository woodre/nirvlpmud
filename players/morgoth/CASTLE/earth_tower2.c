inherit "room/room";
object griffin, statue, awl, money;
object ob;
status gem_is_gone;
int counter;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The Tower of Earth\n";
  long_desc = "The Tower of Earth.\n"+
              "There is a large triangle carved in the middle of\n"+
              "the floor.  In the center of the triangle is a \n"+
              "magnificent gem 6 inches in diameter.\n"+
             "Scratch marks indicate that someone else tried to \n"+
             "pry the gem out.  At each point of the triangle stands\n"+
             "a statue of a griffin.\n";
  counter == 0;
  while(counter < 3)
  {
    statue = clone_object("players/morgoth/OBJ/statue");
    move_object(statue, this_object());
    counter += 1;
  }
  dest_dir =
  ({
      "players/morgoth/CASTLE/earth_tower1", "down"
  });
}

init()
{
  add_action("look_at_gem", "look");
  add_action("exa_gem", "exa");
  add_action("pry_gem_out", "pry");
  ::init();
}

look_at_gem(str)
{
  if(str == "at gem")
  {
    write("You see a large deep blue gem.\n");
    return 1;
  }
}

exa_gem(str)
{
  if(str == "gem")
  {
    write("The gem is 6 inches in diameter.  It looks priceless !\n");
    return 1;
  }
}

pry_gem_out(str)
{
  awl = clone_object("players/morgoth/OBJ/awl");
  if(str == "gem")
  {
    if(!present("awl", this_player()))
    {
      write("You do not possess the right tool to pry the gem out !!\n");
      return 1;
    }
    if(present("awl", this_player()))
    {
   if(!gem_is_gone)
    {
      counter = 0;
      ob = this_player();
      set_heart_beat(1);
      return 1;
    }
    }
  }
}

lsay(str)
{
  tell_room(this_object(), str);
}

heart_beat()
{
  gem_is_gone = 1;
  counter++;
  switch(counter) {
  case 1:  lsay("As " + ob->query_name() + " tries to pry the gem, the statues eyes glow red !\n");
            break;
  case 2:  lsay("CRACKS FORM ON THE STATUES !!  UNDERNEATH, REAL GRIFFINS BEGIN TO EMERGE !!\n");
            break;
  case 4:  lsay("One of the statues falls apart !  A griffin flies out !\n");
           statue = present("statue", this_object());

           money = clone_object("obj/money");
           griffin = clone_object("players/morgoth/MONSTERS/griffin");
           money->set_money(3000);
           destruct(statue);
           move_object(money, griffin);
           move_object(griffin, this_object());
           break; 
  case 10:  lsay("CRRRAACK ! ANOTHER GRIFFIN EMERGES !!\n");
           statue = present("statue", this_object());

           money = clone_object("obj/money");
           griffin = clone_object("players/morgoth/MONSTERS/griffin");
           money->set_money(3000);
           destruct(statue);
           move_object(money, griffin);
           move_object(griffin, this_object());
            break;
  case 17: lsay("CRRRRUUNCH.. ANOTHER GRIFFIN FLIES OUT !\n");
           lsay("THE GRIFFINS CLOSE IN TO GUARD THE GEM !\n");
           statue = present("statue", this_object());

           money = clone_object("obj/money");
           griffin = clone_object("players/morgoth/MONSTERS/griffin");
           money->set_money(3000);
           destruct(statue);
           move_object(money, griffin);
           move_object(griffin, this_object());
            set_heart_beat(0);
            break;
  }
}

