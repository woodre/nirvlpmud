status valid_write(string name, string path)
{
  string junk; 

  if (name == "rumplemintz")
    if (sscanf(path, "/players/guilds/necro%s", junk)
    ||  sscanf(path, "/players/guilds/healers%s", junk)
    ||  sscanf(path, "/players/guilds/fallen%s", junk))
      return 1;
  if (name == "oberon")
    if (sscanf(path, "/players/guilds/necro%s", junk))
      return 1;
  if(name=="shinshi") if(sscanf(path, "/players/guilds/dervish%s", junk))
    return 1;
  if (name == "aingeal")
    if (sscanf(path, "/players/guilds/healers%s", junk))
      return 1;

/* change made by mizan via root access 2009 sep 13 */
  if (name == "mizan")
    if (sscanf(path, "/players/guilds/polymorphs%s", junk))
      return 1;
/* end changes */

  if (name == "brittany")
    if (sscanf(path, "/players/guilds/vampires%s",junk))
      return 1;
    return 0;
}

status valid_read(string name, string path)
{
  if (valid_write(name, path)) 
    return 1;

  return 0;
}
