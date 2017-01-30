inherit "/players/snow/bull_board.c";
#include "../DEFS.h"


/*** Override the below functions when inheriting this object ****/
description() {}

string short()
{
    return ("A light board(" + num_messages + " msgs)");
}

restore_me() {}
save_me(int arg) {}
/*****************************************************************/


status id(string str) { return str == "board" || str == "terminal"; }


void long()
{
  description();
  if (num_messages == 0)
  {
    write("It is empty.\n");
    return;
  }
  write("The board contains " + num_messages);
  if (num_messages == 1)
    write(" note:\n\n");
  else
    write(" notes:\n\n");
  say(call_other(this_player(), "query_name") +
    " studies the board.\n");
  headers();
}


reset(arg)
{
  if (arg) return;
  restore_me();
}


void get_body(string str)
{
  if(str == "~q")
  {
    new_body=0;
    new_hd=0;
    write("Message canceled.\n");
    who = 0;
    return;
  }
  if (str == "**")
  {
    if(!new_hd) new_hd = "";
    new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") + ")";
    messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
    num_messages += 1;
    new_body = 0;
    new_hd = 0;
    save_me(1); /* broadcast new note */
    write("Ok.\n");
    who = 0;
    return;
  }
  new_body = new_body + str + "\n";
  write("]");
  input_to("get_body");
}


status remove(string str)
{
  string hd, body, rest, tmp_messages;
  string jun2, jun;
  string label, note_taker;
  int i, tmp;

  if(!IPTP) return 0;

  if (!str || 
      (sscanf(str, "%d", i) != 1 && 
       sscanf(str, "note %d", i) != 1))
  {
    return 0;
  }

  if (i > num_messages)
  {
    write("Not that number of messages.\n");
    return 1;
  }

  rest = messages;
  jun2 = messages;
  tmp_messages = "";

  while(rest != 0 && rest != "")
  {
    i -= 1;
    tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
    if (tmp != 2 && tmp != 3)
    {
      write("Corrupt.\n");
      return 1;
    }
    if (i == 0)
    {
      sscanf(hd, "%s(%s)", label, note_taker);
      if ((string)TP->query_real_name() == note_taker ||
          call_other(OFFICED, "checkStone", TP, "diamond sapphire"))
      {
        write("Note removal access granted.\n");
      }
      else
      {
        write("Access denied. You can only remove your own notes.\n");
        return 1;
      }
      say(TP->query_name() + " removed a note titled '" + hd + "'.\n");
      write("Ok.\n");
      messages = tmp_messages + rest;
      num_messages -= 1;
      save_me();
      return 1;
    }
    tmp_messages = tmp_messages + hd + ":\n**\n" + body + "\n**\n";
  }

  write("Hmm. This should not happen.\n");
  return 0; /* Rumplemintz */
}


/*This due to idiots too. -Snow */
status new(string str)
{
  object ob;
  if(!present(AFFILIATE, TP) && ((int)TP->query_level() < 21))
  {
    write("You cannot write on this board.\n");
    return 1;
}
  ::new(str);
  return 1;
}


status read(string str)
{
  if(!present(AFFILIATE, TP) && TP->query_level() < 20)
  {
    write("As you attempt to read the board, you begin to get dizzy.\n");
    command("drop all", TP);
    return 1;
  }
  ::read(str);
  return 1;
}
