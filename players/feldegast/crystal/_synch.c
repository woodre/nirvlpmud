#include "../defs.h"

int do_cmd(string str)
{
  object gob, targ, synch_ob;
  object my_pob, your_pob;

  object *synch_list;
  int i,j;

  gob = present(GUILD_ID, TP);
  if(!gob)
  {
     write("Error!  No guild object!\n");
     return 1;
  }

  if((int)gob->query_crystals() < 1)
  {
     write("You require a faeite crystal to cast this spell.\n");
     return 1;
  }

  my_pob = present("party_object", TP);

  if(!my_pob)
  {
    notify_fail("You must be a member of a group to cast this.\n");
    return 0;
  }

  synch_list = (object *)gob->query_synch();

  if(!synch_list)
    gob->add_synch(TP);

  if(!str)
  {
    if(sizeof(synch_list) > 1)
    {
      write("You are synched with ");
      for(i = 0, j=sizeof(synch_list); i < j; i++)
      {
        if(j > 2 && i==j)
          write(" and");
        if(synch_list[i] != TP)
          write(" "+(string)synch_list[i]->query_name());
      }
      write(".\n");
    }
    else
    {
      write("You are not synched with anybody else.\n");
    }
  }

  targ = present(str, environment(TP));
  if(!targ)
  {
    notify_fail("That person is not here.\n");
    return 0;
  }

  if(!targ->is_player())
  {
    notify_fail("That is not a player.\n");
    return 0;
  }

  if(targ == TP)
  {
    notify_fail("You cannot cast this spell on yourself.\n");
    return 0;
  }

  your_pob = present("party_object", targ);
  if(!your_pob)
  {
    notify_fail("That person does not have a party object.\n");
    return 0;
  }

  if((string)my_pob->QPartyName() != (string)your_pob->QPartyName())
  {
    write("That person is not in your party.\n");
    return 1;
  }

  synch_ob = clone_object(OBJ_DIR + "synch_ob.c");
  synch_ob->set_master(gob);
  move_object(synch_ob, targ);

  write("You imbue a faeite crystal with sympathetic vibrations, and then hang\n"+
        "it around "+(string)targ->query_name()+"'s head.\n");
  tell_object(targ, CYN + TPN + " gives you a synch crystal.\n"+NORM);
  tell_room(environment(TP), TPN + " gives " + (string)targ->query_name()+ " a synch crystal.\n", ({ TP, targ }) );

  return 1;
}
  