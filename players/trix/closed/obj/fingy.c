inherit"obj/treasure";
reset(arg) {
if(arg) return;
set_id("fingy");
set_alias("fingy");
set_short("A fingy");
set_long(
"A dirty fingy\n");
set_value(0);
set_weight(0);
}
init()
{ add_action("finga","finga");
}

finga(arg)
{ string filex;
   filex=read_file("/players/"+arg,2);
   write("********\n"+filex+"**********\n");
  return 1;
}
