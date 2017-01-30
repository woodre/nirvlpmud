status valid_write(string name, string path)
{
  return name == "rumplemintz";
}

status valid_read(string name, string path)
{
  return valid_write(name, path);
}
