
main(str) 
{
  object fin;
  fin = clone_object("/players/mythos/closed/play/finger");
  move_object(fin,this_player());
  command("fin "+str,this_player());
  destruct(fin);
  return 1; 
}
