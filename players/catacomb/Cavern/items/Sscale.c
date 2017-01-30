inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("shield");
  set_alias("scale");
  set_short(BLK+"Shimmergloom's scale"+NORM);
  set_long(
	"  One of the scales of the shadow dragon, Shimmergloom.  It\n"+
	"would provide excellent protection against the holy of Nirvana.\n");
  set_type("shield");
  set_ac(1);
  set_params("other|evil",1,10,"evil_protect");
  set_weight(2);
  set_value(2000);
}

evil_protect()
{
  int booya;
  booya = random(7);
  if (booya != 5)
  {
    write("\nThe scale lets out an evil mist.\n\n");
    say("The scale lets out an evil mist.\n");
    return 0502;
  }
}
