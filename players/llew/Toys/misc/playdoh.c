inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("play-doh");
   set_alias("playdoh");
   set_short("A glob of "+({"white","red","green","black","gray","blue","yellow","orange","purple","brown"})[random(10)]+" play-doh");
   set_long("The glob of play-doh is very colorful, but not very useful.\n");
   set_value(100);
   set_weight(1);
   set_dest_flag(1);
}
