inherit "obj/armor";


reset(arg){
  ::reset(arg);
  }


init(){
  ::init();
  add_action("main","upall");
  add_action("guild","undead");
  }

status main(string str)
{
string directory;
int x;
string *files;
object poop;

    if(!str) directory = (string)this_player()->get_path();
else directory = str;

    if(directory[0] == '~')
directory[1..(strlen(directory) - 1)];

    if(directory[0] != '/')
if(directory[strlen(directory) - 1] != '/')

    if(file_size(directory) != -2)
{
notify_fail("Unable to properly upd_dir...\n " +
"String is not a directory.\n");
return 0;
}

    files = get_dir(directory);

    write("Updating directory: " + directory + "\n");
for(x = 0; x < sizeof(files); x ++)
{
if(files[x][strlen(files[x]) - 2..strlen(files[x]) - 1] == ".c")
{
if((poop = find_object(directory + files[x])))
destruct(poop);
poop->load_file(0);
}
}
write("Update complete.\n");
return 1;
}

guild(str) {
  this_object()->set_guild_name(str);
return 1;}
