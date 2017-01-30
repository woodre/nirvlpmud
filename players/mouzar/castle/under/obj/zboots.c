inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("boots");
set_size(1);
set_short("Lizard Skin Boots");
set_long(
  "Some very old boots that have a very bad oder to them.  They look\n"+
  "like they were very nice leather boots in their day.\n");
set_weight(1);
set_value(200);
set_ac(1);
set_type("boots");
}
