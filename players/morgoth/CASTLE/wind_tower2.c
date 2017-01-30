inherit "room/room";
object monster, sword,ob;
status book_is_open, book_is_read;
int counter;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The Tower of Wind\n";
  long_desc = "The Tower of Wind.\n"+
              "A slight breeze plays with your hair.\n"+
              "There is a book resting on a tall pedestal.\n"+
              "The book has some strange characters on the \n"+
              "cover.  This room is open and airy.  The wind\n"+
              "whistles through the crevices in the stone walls.\n";
  dest_dir =
  ({
      "players/morgoth/CASTLE/wind_tower1", "down"
  });
}

init()
{
  add_action("read_book", "read");
  add_action("open_book", "open");
  add_action("look_at_book", "look");
  add_action("exa_book", "exa");
  ::init();
}

look_at_book(str)
{
  if(str == "at book")
  {
    write("You see a large thick book.\n");
    write("The cover has weird characters on it.\n");
    return 1;
  }
}

exa_book(str)
{
  if(str == "book")
  {
    write("There is something strange about this book !\n");
    return 1;
  }
}

open_book(str)
{
  if(str == "book")
  {
    if(!book_is_open)
    {
    write("You open the book.\n");
    say(call_other(this_player(), "query_name") + " opens the book.\n");
      book_is_open = 1;
      return 1;
    }
  }
}

read_book(str)
{
  if(str == "book")
  {
    if(!book_is_open)
    {
      write("You must open the book first !\n");
      say(call_other(this_player(), "query_name") + " tries to read the book but fails.\n");
      return 1;
    }
    if(book_is_open)
    {
    if(!book_is_read)
    {
     write("You try to read the letters but you can't understand them !\n");
     say(call_other(this_player(), "query_name") + " struggles to read the book.\n");
    ob = this_player();
    set_heart_beat(1);
    book_is_read = 1;
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
  counter++;
  switch(counter) {
    case 5: lsay("The letters in the book glow bathing " + ob->query_name() + "'s face in green light.\n");
            break;
   case 10: lsay("The wind picks up, the pages turn by themselves...\n");
            break;
   case 15: monster = clone_object("players/morgoth/MONSTERS/wyrme");
        lsay("A column of air rushes upward from the book !!!\n");
            lsay("Wyrme has arrived !!\n");
            sword = clone_object("players/morgoth/WEAPONS/whitesword");
            move_object(sword, monster);
/* This would lower the monster's wc. -Feldegast 10-6-2000
            call_other(monster,  "init_command", "wield", sword);
*/
            move_object(monster, this_object());
            set_heart_beat(0);
            break;
  }
}

