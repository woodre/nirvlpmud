inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_short("A cap from a bottle of Snapple");
   set_long("This is a cap from a bottle of Snapple fruit juice. It looks like\n"+
            "you can 'click' it.\n");
   set_name("cap");
   set_weight(1);
   set_value(2);

   set_read("There used to be some words on the cap but they seem to have been\n"+
            "completely ground away.\n");
   set_smell("The cap smells like strawberry something...\n");
   set_taste("The cap has the faint taste of some kind of strawberry juice.\n");
}


init() 
{
    ::init();
	add_action("on_click","click");
}

on_click() 
{
	write("You click the cap... You hope no one picks up from where it is\n"+
          "coming from...\n");

	say("You hear a 'click'.\n");
	return 1;
}
