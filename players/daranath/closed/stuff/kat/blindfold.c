inherit "obj/armor";
reset(arg){
   ::reset(arg);

   set_name("silk blindfold");
   set_short("A soft black silk blindfold");
   set_alias("blindfold");
   set_long("A long piece of silk that can be tied about the eyes of a\n"+
            "person and then unspeakable things can be done to them.\n"+
            "A staple in any erotic encounter.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(10);
}
init(){
  ::init();
add_action("block_look","look");
add_action("block_look","l");
add_action("block_who","who");
add_action("block_who","who2");
add_action("block_who","s_who");
}

block_look() {
write("You cannot see anything with the blindfold on!\n");
return 1; }

block_who() {
write("You cannot see who is about Nirvana with the blindfold on.\n");
return 1; }
