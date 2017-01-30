inherit "obj/armor";


init()
{
  add_action("incant","incant");
}


id(str)
{
  return str == "plate" || str == "warplate" || 
         str == "armor" || str == "armageddon";
}


reset(arg)
{
   ::reset(arg);
   set_name("Armageddon");
   set_short("Armageddon, the warplate");
   set_alias("warplate");
   set_long(
"     Armageddon is a beautifully crafted suit of field plate.\n"+
"Its metal shines brilliantly, except for the dark center. The shape\n"+
"of a black widow spider spans across the shining breast plate. The\n"+
"characteristic red hourglass seems to glow a faint red.\n"+
"Armageddon derives its power through incanting the word 'sith'.\n");
   set_ac(5);
   set_weight(9);
   set_value(60000);
}


incant(string str)
{
  if (!str)
  {
    write("What word do you incant?\n");
    return 1;
  }
  if (str != "sith")
  {
    write("Nothing happens.\n");
    return 1;
  }
  if (!this_player()->query_attack())
  {
    write("Armageddon hears your call, but does nothing.\n");
    return 1;
  }
  call_out("sith", 1, this_player());
  tell_room(environment(this_player()), 
    capitalize(this_player()->query_name())+
    "'s warplate shines a deep red. The black widow spider upon\n"+
    "the plate armor starts to move, protracting its hideous sting.\n");
  return 1;
}


sith(object ob)
{ 
  object tob;
  if (ob->query_attack())
  {
    tob = ob->query_attack();
    if (tob && tob->query_hit_point() >= 1)
    {
      tob->heal_self(-1);
      tell_room(environment(ob), 
                "Armageddon stings "+tob->query_name()+".\n");
    }
    call_out("sith", 2, ob);
    return 1;
  }
  tell_room(environment(ob), "Armageddon ceases its attacks.\n");
  return 1;
}
