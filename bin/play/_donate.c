#include <ansi.h>
#define THA_GREEN find_object("/room/vill_green")

int cmd_donate(string str)
{
  object obj;
  object tp;
  object rm;
  
  tp=this_player();
  rm=environment(tp);

  if(!str)
  {
    write("Donate what?\n");
  }
  else
  {
    if(!(obj = present(str, tp)) &&
      !(obj = present(str, environment(tp))))
    {
      write("You don't see or have \""+str+"\".\n");
    }
    else
    {
      if(living(obj))
      {
        string on;
        write((on=(string)obj->query_name())
          +" slaps you for trying.\n");
        say(on+" just slapped "+
          (string)tp->query_name()+"!\n");
      }
      else if(!obj->get())
      {
        write("You can't even pick that up to donate it.\n");
        return 0;
      }
      else if(!obj->query_value())
      {
        write("You cannot donate a worthless item!\n");
      }
      else if(obj->query_kept())
      {
        write("You cannot donate a kept item.\n");
      }
      else
      {
        if(environment(obj) != tp)
        {
          command("get "+str, tp);
        }
        if(transfer(obj, present("army_box",THA_GREEN)))
        {
          write("Donation failure...\n");
        }
        else
        {
          write("You begin speaking in tongues...\n");
          command("say "+HIK+crypt("heh",0)+" "+
            crypt("heh",0)+NORM, tp);
          write(((string)obj->query_name() ?
            (string)obj->query_name() :
            (string)obj->short())+" disappears from your grasp.\n");
/* Added by Rumplemintz  10-Nov-2010, need to call to actually change item
   to donated status */
            obj->set_donated_item(1);

          tell_room(THA_GREEN,
            "The Salvation Army Box burps "+RED+"rudely"+
            NORM+".\n");
        }
      }
    }
  }
  return 1;
}