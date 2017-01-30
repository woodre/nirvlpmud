inherit "obj/treasure";

reset (arg)
{
  if (arg) return;
  set_id("roses");
  set_short("Bagera's roses");
  set_long("A dozen of the finest roses you have ever seen !\n"+
           "These roses only belong to Bagera !\n"+
           "they will smell good only for her !\n"+
           "Whoever gave them to her must like her very, very much !\n");
  set_weight(1);
  set_value(50);
}

init()
{
  add_action("smell_roses", "smell");
}

smell_roses(str)
{
  object ob1;
object roses;
roses  = clone_object("players/morgoth/OBJ/roses");
  if ((!str) || !id(str)) return 0;
  if(this_player()->query_real_name() != "bagera")
  {
    ob1 = present("roses", this_player());
    write("You are not Bagera !!!\n");
    destruct(ob1);
    return 1;
  }
  write("mmmmmmmmmm the roses smell delicious !\n");
  return 1;
}
