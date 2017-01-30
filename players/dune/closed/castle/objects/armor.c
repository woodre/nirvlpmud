inherit "obj/armor";


id(str) { return str == "plate" || str == "ribbed plate" || 
                 str == "armor"; }


reset(arg)
{
  ::reset(arg);
  set_name("Blue tinted ribbed plate");
  set_short("Blue tinted ribbed plate");
  set_alias("ribbed plate");
  set_long(
"      A blue haze surrounds this wonderful piece of shining armor.\n"+
"Lusterous blue metal wraps around the lighter blue frame. The armor\n"+
"has the name 'Solomar' upon the back. The armor appears as if it\n"+
"provides protection for pretty much the whole body. It is crafted\n"+
"with painstaking detail.\n");
  set_ac(4);
  set_weight(5);
  set_value(6000);
}
