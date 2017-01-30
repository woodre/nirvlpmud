#define WRAP(arg) (string)"/players/earwax/lib/waxfuns.c"->line_wrap((string)"/players/earwax/lib/color_parser.c"->parse_pcodes(arg+""))
inherit "/room/room.c";

void reset(status arg) {
  ::reset(arg);

  if (arg)
    return;

  short_desc = "Earwax's Help File Writing Room";
  long_desc = "write<filename> <description>\nread\nread filename";
}

status do_it(string arg) {
  string filename;

  if (!arg || sscanf(arg, "%s %s", filename, arg) != 2) {
    if (arg) { write_file("/players/earwax/housing/help/"+arg, "\n"); write("Blank line added to "+arg+".\n"); return 1; }
    notify_fail("Syntax: write <filename> <paragraph>\n");
    return 0;
  }

  arg = WRAP(arg);
  write_file("/players/earwax/housing/help/"+filename, arg+"\n");
  write("Input was put in "+filename+".  Text follows:\n");
  write(arg+"\n");
  return 1;
}

status show_it(string arg) {
  return (status)"/players/earwax/housing/bin/hinfo.c"->main(arg, this_object(), this_player());
}
void init() {
  add_action("show_it", "read");
  add_action("show_it", "hinfo");
  add_action("do_it", "write");
}
