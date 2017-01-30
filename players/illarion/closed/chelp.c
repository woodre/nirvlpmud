/* chelp.c -- guild help "spell" */
#define SPELL_DIR "/players/catwoman/guild/power/"

string *commands;

void help() {
  write("]---------------> Coven Help <---------------[\n");
  write("Topic: Chelp\n");
  write("Type: Command\n");
  write("Cost: n/a\n");
  write("Level: n/a\n");
  write("Description: To get more information on a topic relating to the\n");
  write("coven, use \"chelp <topic>\".\n");
}

int main(string str) {
  int x,size;
  if(!commands) {
    commands = get_dir(SPELL_DIR);
    size=sizeof(commands);
    for(x=0;x<size;x++)
      sscanf(commands[x],"%s.c",commands[x]);
  }
  if(!str) {
    for(x=1;x<=size;x++) {
      write(commands[x-1]+"\t");
      if((x%5)==0) write("\n");
    }
    return 1;
  }
  if((x=member_array(str,commands))==-1) {
    write("There is no Coven Help on that topic.\n");
    return 1;
  }
  call_other(SPELL_DIR+commands[x],"help");
  return 1;
}
