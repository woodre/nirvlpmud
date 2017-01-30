inherit "obj/drink";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_value("coffee#A cup of stale coffee#You drink a cup of stale coffee#0#520#-10");
}
