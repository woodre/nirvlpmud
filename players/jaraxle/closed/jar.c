short_scan()
{
  string str1, str2;
  if(sscanf(environment(TP)->short(), "%skeyword%s", str1, str2) == 2)
    write("Success.\n"); 
  else
    write("Failure.\n");
}

long_scan()
{
  string str1, str2;
  if(sscanf(environment(TP)->query_long(), "%skeyword%s", str1, str2) == 2)
    write("Success.\n"); 
  else
    write("Failure.\n");
}
