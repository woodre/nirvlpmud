/* Barry Manilow's Microphone */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("microphone");
   set_short("Barry Manilow's microphone");
   set_long("Barry Manilow's microphone is shiny matte black,\n"+
           "and is surprisingly light.  When you turn it over,\n"+
	   "you realize that it's empty.  No wonder Barry Manilow\n"+
	   "sounds exactly the same live as he does on his albums.\n");
   set_weight(1);
   set_value(50);
}

