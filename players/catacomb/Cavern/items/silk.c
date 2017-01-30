inherit "/obj/treasure.c";

reset (arg) 
{
	set_id("silk");
	set_short("A pile of silk");
	set_long(
      "  A pile of silk from a giant spider.  Silk is said to be\n"+
      "sought after by a medicine man in the area.  He uses it\n"+ 
      "as an ingredient in his potent senzu beans.\n");
      set_weight(1);
      set_value(1000);
}
