#include "../def.h"

cmd_spike(str)
{
  object obj;
  object spike;
  object gob;
  int head_count;

  if(TP->query_guild_rank() < 1) return 0;
  if(str != "head")
  {
    write("You can only spike heads.\n");
    return 1;
  }
  if(!(obj=present(str,ENV(TP))))
  {
    write("You don't see \""+str+"\"\n");
    return 1;
  }

  gob = previous_object();
  if( !gob )
    return 0;

  if(!(spike = present("headspike", TP))){
    spike = clone_object("/obj/treasure");
    spike->set_id("headspike");
    spike->set_alias("spike");
    spike->set_value(0);
    spike->set_weight(1);
    spike->set_no_drop();
    /* spikes no longer save since it is stored in gob */
    spike->set_save_flag(1);
    move_object(spike, TP);
  }

  /* Convert old style spike to saving in the gob */
  if( spike->query_value() ) {
    string tmp, num;

    sscanf(spike->short(),"%s[%d]",tmp,num);
    gob->add_head_count( num );
    spike->set_value(0);
  }

  /** Increment for current head spike **/
  gob->add_head_count();
  head_count = (int) gob->query_head_count();

  if( head_count > 0 )
  {
    spike->set_short("a spike of many heads ["+head_count+"]");
    spike->set_long("\
A long spike containing "+head_count+" heads.\n");
  }
  else {
    spike->set_short("a spike [0]");
    spike->set_long("\
A spike containing zero heads.\n");
  }

  write("\n  You brutally slide "+obj->short()+" onto your long spike.\n\n");
  say(TP->QN+" collects a head on "+possessive(TP)+" spike.\n");
  destruct(obj);
  return 1;
}
