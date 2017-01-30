int main(string str)
{
  string sh;
  string bo;
  object obj;

  if(!str) return 0;
  if(!present(str, this_player()))
    return 0;
  obj=present(str,this_player());

  if(!(sh=(string)obj->query_short())) sh=(string)obj->short();
  bo=basename(obj);
  write_file("/players/vertebraker/list",
  bo+" "+sh+"\n");
  write("Recorded.\n");
  destruct(present(str, this_player()));
  return 1;
}
