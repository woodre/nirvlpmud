inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("coffee#A cup of coffee#You drink a cup of coffee#0#500#-10");
}
