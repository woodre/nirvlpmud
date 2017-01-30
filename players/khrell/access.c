status valid_write(string name, string path)
{
  string junk; 

  if (name == "aingeal")
    if (sscanf(path, "/players/khrell/healers%s", junk))
    return 0;
}

status valid_read(string name, string path)
{
  if (valid_write(name, path)) 
    return 1;

  return 0;
}
