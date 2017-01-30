status main(string arg)
{
  object *peeps;
  int i, siz;

  siz = sizeof(peeps = users());

  for (i = 0; i < siz; i++)
  {
    if (environment(peeps[i]) && (int)peeps[i]->query_level() >= 20)
    {
      write(pad((query_idle(peeps[i])/60), 5));
      write(pad(capitalize((string)peeps[i]->query_real_name()), 12));
      write(pad((int)peeps[i]->query_level(), 7));
      write(pad((int)peeps[i]->query_invis(), 7));
      write((string)peeps[i]->query_pwd()+"\n");
    }
  }
  return 1;
}
