inherit "obj/treasure";

reset(arg)
{   if (arg) return;
   set_id("troll head");
   set_alias("head");
   set_short("The head of Supertroll");
   set_long("The head of the infamous Supertroll.\n"+
       "You think you could <splat> it at somebody.\n");
   set_weight(2);
   set_value(2000);
}


init()  {
   add_action("throw_head","splat");
        }


throw_head(str)  {
object ob;

  if(!str)  {
    write("Splat who?\n");
    return 1;
        }

  if(!(ob = present(str, environment(this_player()))))  {
    write(capitalize(str)+" is not here.\n");
    return 1;
        }

  write("You hurl the trolls head at "+capitalize(str)+".\n");
  say(this_player()->query_name()+" hurls the head of a troll at "+
      capitalize(str)+".\n");
  tell_room(environment(ob),  "\n\n\n"+
     "  S\n"+
     "   P\n");
   tell_room(environment(ob),
     "    L\n"+
     "     A\n"+
     "      T\n"+
     "\n"+
     "\nEwwwwww...\n");
   return 1;
          }
   


quest_ob() { return 1; }
query_save_flag() { return 1; }
