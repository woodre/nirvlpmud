inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A big black machine");
   set_long("This is a big, warm thing plugged into nowhere in particular.\n"+
	"It makes a funky sound when you press one of the numerous white\n"+
	"and black keys. A label on the front reads 'Roland TB303'.\n");

   set_name("machine");

   set_read("A small sticker on the baseplate reads: 'Tadao Kikumoto Kicks Ass!'");

   set_smell("The machine smells a lot like an old car.\n");
   set_taste("The machine tastes a lot like dried brandy for some reason.\n");
}


