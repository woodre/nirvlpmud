
stop_casting(str){
  if(str != "casting") return 0;
  if(User->query_ghost()) return 0;
  if(PO->light_check()) return 1;
  if(!PO->query_casting())
    TOU "You are not casting a spell.\n");
  else
  {
    if(PO->query_siphon())
    {
      TOU "The siphon stone surges and you fail to stop the spell.\n");
      return 1;
    }
    TOU "You stop casting your spell.\n");
    PO->set_casting(0);
  }
  return 1;
}
