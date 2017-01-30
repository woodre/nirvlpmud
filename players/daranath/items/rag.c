inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("cloth");
    set_alias("rag");
    set_short("A tattered bit of cloth");
    set_long("A tattered piece of cloth, this rag looks as if it fell\n"+
             "or was torn off from something. The cloth was at one time\n"+
             "white, but now it is stained with filth, and it carries\n"+
             "the scent of death and decay along with it.\n");
    set_weight(1);
    set_value(5);
}
