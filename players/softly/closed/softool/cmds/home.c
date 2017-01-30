
main()
{
   write("You go home.\n");
   move_object(this_player()),"/players/softly/workroom");
   command("look",this_player());
   return 1;
}
