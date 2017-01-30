main(str)
{
 object ob;
 if(str && (ob=find_player(str)))
  ob->remove_ghost();
 return 1;
}
