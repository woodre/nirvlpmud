status valid_write(string name, string path)
{
  string junk;

  if (sscanf(path, "/players/sami%s", junk))
  {
    if (name == "data" || name == "karash")
      return 1;
  }
  return 0;
}

status valid_read(string name, string path)
{
  return valid_write(name, path);
}
