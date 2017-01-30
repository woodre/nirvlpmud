#define tp this_player()

inherit "obj/quicktyper";
init()
{
   ::init();
   add_action("do_commands", "do");
}
query_auto_load()
{
   return "/players/sado/ts:";
}
do_commands(str)
{
   string         *argv, com;
   int             i, reps;
   int             size;
   
   argv = explode(str, ",");
   size = sizeof(argv);
   for (i = 0; i < size; i++) {
      if (sscanf(argv[i], "%d%s", reps, com) == 2) {
         for (reps; reps > 0; reps--) {
            command(com, tp);
          }
        } else {
         command(argv[i], tp);
        }
   }
   return 1;
}
