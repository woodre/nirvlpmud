do_login(str)
{
  if(TP->query_home())
  {
    write("You set your login to the village church.\n");
    TP->set_home(0);
  }
  else
  {
    write("You set your login to the Healer Hall.\n");
    TP->set_home(ROOMPATH+"hall.c");
  }
  return 1;
}
