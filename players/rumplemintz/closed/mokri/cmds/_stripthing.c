#define CHUNK_SIZE 300

void strip_me(string filename, int start_line)
{
  int a;
  string filetext, *lines;

  if(this_player()->query_level() < 1000) return;
  filetext = read_file(filename, start_line, CHUNK_SIZE);
  if(!filetext)
  {
    filetext = read_file(filename+".strip");
    if(!filetext)
    {
      write("No stripped file.\n");
      return;
    }
    if(!rm(filename))
    {
      write("Cannot remove " + filename + "\n");
      return;
    }

    "/bin/wiz/_mv"->cmd_mv(filename + ".strip " + filename);
    write("Strip complete.\n");
    return;
  }

  lines = explode(filetext, "\n");

  for(a = 0; a < sizeof(lines); a++)
  {
    filetext = lines[a];
    filetext = regreplace(filetext,"#include (.*);","#include \\1",1);
    write_file(filename+".strip",filetext);
    if(a+1 < sizeof(lines)) write_file(filename+".strip","\n");
  }

  strip_me(filename,start_line+CHUNK_SIZE);
  return;
}

cmd_stripsemi(string str)
{
  string filename;

  if(this_player()->query_level() < 1000) return;
  if(!str)
  {
    write("Strip what file?\n");
    return 1;
  }

  str = resolve_path(str);
  strip_me(str,1);
  return 1;
}
