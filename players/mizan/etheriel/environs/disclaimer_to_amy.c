inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_short("An obnoxious ashtray");
   set_long("When you get close enough, the ashtray hollers at the top of\n"+
	"its 'lungs': 'GARBANZO!!!'\n");

   set_name("ashtray");

   set_read("The ashtray stares at you angrily.\n");

}

get() {
  write("You try, but the ashtray escapes.\n");
  return 0;
}
