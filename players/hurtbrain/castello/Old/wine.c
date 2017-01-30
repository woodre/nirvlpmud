inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("wine#A bottle of wine#You drink the wine#10#150#9");
}
