inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("alcohol#A bottle of pure alcohol#You drink a bottle of pure alcohol#30#500#14");
}
