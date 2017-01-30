inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A small cardboard sign");
   set_long(">> Note:\n\n"+
            "This room is supposed to be a party/hangout room. More items are needed to\n"+
            "make this place more fun and relaxing. I'm working on it...\n\n"+
            "The management\n");

   set_name("sign");

   set_read(">> Note:\n\n"+
            "This room is supposed to be a party/hangout room. More items are needed to\n"+
            "make this place more fun and relaxing. I'm working on it...\n\n"+
            "The management\n");

   set_smell("The sign smells like Kinko's!\n");
   set_taste("The sign tastes surprisingly enough... like cardboard.\n");
}


