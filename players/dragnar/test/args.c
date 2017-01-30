inherit "obj/treasure";

int *args;

static void test_args(int x, int y, int z);

void
reset(int arg) {
   if (arg) return;
   set_id("object");
   set_short("object");
   set_long(
"A wiz object.\n");
   set_weight(0);
   set_value(0);
   set_save_flag();
}

void init() {
  add_action("cmd_print","t1");
  args = allocate(3);
}

cmd_print() {
  write(pad("johnniebillings",20,'*'));
  write("\n");
  write(pad("",20,'*'));
  write("\n");
  write("i: "+args[0]+" j: "+args[1]+" k: "+args[2]+"\n");
  call_out("test_args", 5, args );
  write("i: "+args[0]+" j: "+args[1]+" k: "+args[2]+"\n");
  return 1;
}

test_args(int *args)
{
  args[0] = 1;
  args[1] = 2;
  args[2] = 3;
  tell_object(find_player( "dragnar" ), "x: "+args[0]+" y: "+args[1]+" z: "+args[2]+"\n");
}
