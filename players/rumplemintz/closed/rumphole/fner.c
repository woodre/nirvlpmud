#pragma strong_types

inherit "/players/rumplemintz/basic/item";

#define FILE "/open/rumplemintz/rhole/test.o"

void
configure()
{
  ::configure();
  set_encumbrance(50);
  set_id(({"filenamer","fner","thing"}));
  set_short("A filename query thingy");
  set_long("This is a filename query thingamabob. What it 'should' do\n"+
           "is return the filename to the screen, and write a file into\n"+
           "open/rumplemintz/rhole/<whatever>.o\n"+
           "Usage:  fner <thing>\n");
  set_value(10);
}

void
init()
{
  add_action("doit","fner");
}

status
doit(string str)
{
  object target_ob;
  string path_to_thing;
  string real_path, clone_number;
  if (!str)
  {
    write("Usage: fner <thing>\n");
    return 0;
  }
  target_ob = present(str, this_player());
  if (!target_ob)
  {
    write("You do not have a "+str+"!\n");
    return 0;
  }
  path_to_thing = file_name(target_ob);
  sscanf(path_to_thing, "%s#%s", real_path, clone_number);
  write_file(FILE,real_path+"\n");
  transfer(target_ob, "room/void");
  destruct(target_ob);
  write(real_path+" : was written to the file.\n");
  return 1;
}
