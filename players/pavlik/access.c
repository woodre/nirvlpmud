status valid_write(string name, string path)
{
  string junk;

  if (sscanf(path, "/players/pavlik/guild/mages%s", junk))
  {
    if (name == "jareel" || name == "pestilence")
      return 1;
  }
  return 0;
}

status valid_read(string name, string path)
{
  return valid_write(name, path);
}
