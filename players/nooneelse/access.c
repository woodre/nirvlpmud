status valid_write(string name, string path)
{
  string junk;

  if (name == "khrell")
    if (sscanf(path, "/players/nooneelse/black%s", junk))
    return 1;
  return 0;
}

status valid_read(string name, string path)
{
  if (valid_write(name, path))
    return 1;

  return 0;
}