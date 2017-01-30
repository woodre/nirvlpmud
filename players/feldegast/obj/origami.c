inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("scrap");
  set_alias("duck");
  set_short("An origami duck");
  set_long("A scrap of dirty looking paper folded in the shape of a\n"+
           "duck.  You see some writing on it, but you need to 'unfold'\n"+
           "it first.\n");
  set_weight(1);
  set_value(5);
  set_read(0);
}

void init()
{
  add_action("read","read");
  add_action("cmd_unfold","unfold");
  add_action("cmd_fold","fold");
}

int cmd_unfold(string str)
{
  notify_fail("Unfold what?\n");
  if(!str || !id(str)) return 0;
  write("You unfold the piece of paper.\n");
  say((string)this_player()->query_name()+" unfolds an origami duck.\n");
  set_short("A scrap of paper");
  set_long("This is a wrinkled piece of paper with some writing on it that\n"+
           "you can read.\n");
  set_read("The message reads: A fool and his money are soon parted.\n");
  init();
  return 1;
}

int cmd_fold(string str)
{
  notify_fail("Fold what?\n");
  if(!str || !id(str)) return 0;
  write("You fold up the piece of paper along its old lines.\n");
  say((string)this_player()->query_name()+" starts folding an origami duck.\n");
  reset(0);
  return 1;
}

int id(string str)
{
  return str=="origami" || str=="scrap" || str=="paper" || str=="duck";
}

int read(string str)
{
  notify_fail("Read what?\n");
  if(!str || !id(str) || !read_msg) return 0;
  write(read_msg);
  return 1;
}
