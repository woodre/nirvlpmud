/* because this has a neg weight and is a "ring of strength"
   i have made the ac neg .... tit for tat
   - mythos <8-6-1998> */
/* Made the ring return +1 to wc if worn. -1 to -2 ac, for +1 wc.
   fair?  Let me know if you disagree. Mythos destroyed it and
   I thought it was time to bring it back to usable. */
inherit "obj/armor";
reset(arg){
   ::reset(arg);
    set_name("ring of strength");
   set_short("A silver ring");
   set_alias("generic_wc_bonus");
   set_long("A silver ring that will make you stronger.\n");
   set_type("ring");
   set_ac(0);
/*  CHANGED BY WIZARDCHILD - players were getting -str and it was causing bugs
   set_weight(-5);
*/  set_weight(1);
   set_value(500);
}

/*  changed weight to 1 and ac to 0.... too many people were using this as a means to lower weight without wearing the armor
  i may add some stuff to make it more effective but this will do 
for now... - Mythos <8-2-1999>  */
gen_wc_bonus(){ if(worn) return 1; else return 0; }

