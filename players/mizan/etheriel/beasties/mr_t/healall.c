init() 
{
  add_action("healall","healall");
}

healall()
{
  object ob;
  int i;
  ob = users();
   for(i = 0; i < sizeof(ob); i++)
  {
    ob[i]->heal_self(6000);
    }
}
