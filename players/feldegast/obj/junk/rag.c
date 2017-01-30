inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("rag");
  set_alias("quest rag");
  set_short("Polishing rag");
  set_long("This is an old rag that the tower staff uses to polish\n"+
          "old lamps.\n");
  set_weight(1);
  set_value(5);
}
