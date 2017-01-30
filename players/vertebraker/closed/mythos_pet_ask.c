#define KEY "a01010101010"

object p, i, t;

id(str) { return (str == "mythos_pet_ask"); }

drop() { return 1; }

init()
{
    add_action("s", KEY);
}

ask_me_foo(pet, item, target)
{
    p=pet;
    i=item;
    t=target;
    command(KEY, environment());
}

s()
{
    write("\n\t" + (string)((object)p->query_owner())->query_name() + " wishes to send you " + 
       (string)i->short() + ".\n\tDo you accept this item? (you have 10 seconds to reply)\n<y/n> ");
    input_to("huh");
    call_out("ndIt", 10, this_player());
    return 1;
}

decline(x)
{
   if(i && p->query_owner()) move_object(i, p->query_owner());
   if(x)
     tell_object(x, "You decline the item.\n");
   if(p && p->query_owner())
     tell_object(p->query_owner(), x->query_name() + " declined the item.\n");
   if(p) p->NotBusy();
   destruct(this_object());
   return 1;
}

ndIt(x)
{
   decline(x);
}

huh(str)
{
    if(str == "y" || str == "Y" || str == "yes" || str == "YES")
    {
      write("Ok.\n");
      if(p)
      {
        p->okay_do_da_ting(i, t);
        if(p->query_owner())
          tell_object(p->query_owner(), this_player()->query_name() + " accepted the item.\n");
      }
      destruct(this_object());
      return 1;
    }
    else
    {
      write("Ok.\n"); command(str, this_player());
      decline(this_player());
      return 1;
    }
}
