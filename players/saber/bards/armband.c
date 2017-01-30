#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)
{   if (arg) return;
    set_id("armband");
    set_short("A dark black armband (worn)");
    set_long("A dark black armband worn to symbolize the dishonor\n"+
       "which has been been brought in to the midst of the Alliance.\n");
    set_weight(0);
    set_value(0);
        }

extra_look()  {
object bard;
bard = environment(this_object())->query_name();
write(bard+" appears to be in mourning.\n");
        }
