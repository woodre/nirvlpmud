int do_cmd(string str)
{
  this_player()->set_noidlequit();
  write("You will not be automatically logged out.\n");
  return 1;
}
