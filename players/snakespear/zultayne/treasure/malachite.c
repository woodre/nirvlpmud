inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("malachite");
set_alias("qpiece5")
   set_short("a chunk of malachite");
   set_long("A nice sized chunk of malachite.  A beautiful green stone\n"+
      "with bands of varying hues, that once may have been used\n"+
      "to increase one's ability to send power.  It looks very valueable!\n");
   set_weight(2);
   set_value(800+random(200));
}
