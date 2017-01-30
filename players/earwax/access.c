/* Example file for granting other wizards access to your files */

status valid_write(string name, string path)
{
  string junk; 

  /* Ew has access to my lib path */
  if (name == "ew" && sscanf(path, "/players/earwax/lib/%s", junk) == 1)
    return 1;
  /* Fred has full access to all my dirs, including closed */
  if (name == "fred")
    return 1;

  /* Khrell has access to all my non-closed dirs */
  if (name == "khrell" && !instr(path, "closed"))
    return 1;

  /* Jareel has access to the tracker directory only */
  if (name == "jareel" && sscanf(path, "/players/earwax/closed/TRACKER%s", junk) == 1)
    return 1;

  /* End of special cases, nobody else has special access */
  return 0;
}

status valid_read(string name, string path)
{
  /* If they can write to it, they can read it */
  if (valid_write(name, path)) return 1;

  /* Jareel can read any non-closed dir of mine */
  if (name == "jareel" && !instr(path, "closed"))
    return 1;

if (name == "rumplemintz" && sscanf(path, "/players/earwax/closed/bin%s", path))
  return 1;
  /* No other special access */
  return 0;
}
