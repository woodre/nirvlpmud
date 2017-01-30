inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("potion#A sobering potion#You drink the potion#0#200#-11");
}
