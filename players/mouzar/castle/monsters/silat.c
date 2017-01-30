inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("silat");
set_alias("hag");
set_short("Silat");
set_long("She appears to be a giant female humanoid whit pale green skin and.\n"+  
         "curved ran's horns curling from each side of her head.  They are\n"+
         "a very nice size.  The head is a darker green then the rest of the\n"+
         "her body.  Her teeth and nails look like yellowed ivory.  She is\n"+
         "dressed in rags that barely cover her bent and wrinkled form.\n");
 set_al(0);
set_level(18);
set_wc(26);
set_ac(19);
set_hp(450);
set_aggressive(0);
}
 
