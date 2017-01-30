main(str)
{
  object ob;
   if(!str || !(ob=find_player(str))) return 0;
    else move_object(clone_object("/players/vertebraker/closed/vtell"), ob);
    return 1;
}
