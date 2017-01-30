
int wand_here;
object wand_piece;

void set_wand_piece(int x){ wand_here = x; }
int query_wand_piece(){ return wand_here; }

status search_cmd(string str)
{
  if(present("zeus_inculta_npc"))
  {
    write("You can't search while monsters are present.\n");
    return 1;
  }
  if(wand_here <= 0)
  {
    write("You search through the sand and find nothing of interest.\n");
    return 1;
  }
  else {
    write("You search through the sand and find "+
      "a dusty old piece of treasure.\n");
    wand_piece = clone_object("/players/zeus/desert/OBJ/wand_piece.c");

    if(wand_here == 1)
      wand_piece->set_number(1);
    else if(wand_here == 2)
      wand_piece->set_number(2);
    else if(wand_here == 3)
      wand_piece->set_number(3);

    if(!this_player()->add_weight(1))
    {
      write("You can't carry anymore.\n");
      return 1;
    }
    move_object(wand_piece, this_player());
    wand_here = 0;
    return 1;
  }
}

