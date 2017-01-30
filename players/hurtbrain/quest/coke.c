inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("coke#This is a can of coke#You drink the coke. You feel somewhat better#50#750#9");
}
