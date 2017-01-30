inherit "obj/armor";
#define ME		this_player()
#define TOB		this_object()
#define PN		this_player()->query_real_name()
#define CPN		capitalize(this_player()->query_real_name())

object ob, ob2;

string him, who, s;
string name;



reset(arg)
{
    set_short("Boxer-Shorts");
    set_long("These are Dersharp's Silk Blue Boxers!\n");
    set_ac(100);
    set_weight(0);
    set_value(0);
    set_name("box");
    set_type("armor");
}

init()
{
  if(PN!="dersharp")
  {
    write("Yeah I bet you'd like to play wit dis!!\n");
    command(ME,"gossip Im playin wit Dersharp's Boxers!!!\n");
    destruct(TOB);
    return 1;
    }
    else
       {
        write("Roll WIT DA PUNCHES!!\n");
        return 1;
  }
  ::init();
    if(ME!= environment(TOB)) return;
    if(ME->query_level()<20 && PN !="dersharp") return;
    add_action("marry_people","Marry");
    add_action("Frog_him","Frog");
    add_action("Clone","Clone");
  }
marry_people(str)
  {
    sscanf(str,"%s %s",who,name);
    ob = find_player(who);
    if(ob)
    {
      if(!present("wedding_ring",ob))
      {
        ob2 = clone_object("/players/dersharp/wedding.c");
        ob2->local_set_spouse(who);
        move_object(ob2,ob);
      }
    }
/*
    ob = find_player(name);
    if(ob)
    {
      if(!present("wedding_ring",ob))
      {
      ob2 = clone_object("/players/dersharp/wedding.c");
      ob2->local_set_spouse(who);
      move_object(ob2,ob);
      }
    }
*/
    write("They art now engaged in holy matrimony.\n");
    return(1);
  }
