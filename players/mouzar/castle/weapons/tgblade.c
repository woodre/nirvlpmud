 
inherit "/obj/weapon";
reset(arg) {
if(arg) return;
::reset();
set_name("blade");
set_alias("thaggyblade");
set_short("The Thaggyblade");
set_long("This is Thaggypoo's weapon. Damn it stinks!!!\n");
set_value(500);
set_weight(4);
set_class(15);
}
