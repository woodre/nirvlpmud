#pragma strict

#define VIRUSNAME "basea"

/**
 *
 * V1RbM0
 *
 * This is the standard virus engine.
 *
 */

string query_auto_load()
{
   string filename;
   string temp;
   int i;

   temp = object_name(this_object());
   
   if(sscanf(temp, "%s#%i", filename, i) != 2)
      return "";
   else
      return filename;
}

string short()
{
   if(this_player() && this_player()->query_level() > 19)
      return "Player infected with VIRUS: [" +
             VIRUSNAME + "] (Visit jello and 'virinf "+ VIRUSNAME + "')";
   else 
      return 0;
}

int get()
{
   return 1;
}

int drop()
{
   return 1;
}

void reset(int arg)
{
   if(!arg)
   {
      call_out("fake_beat", 1, 1);
   }
}

void fake_beat(int arg)
{
   int beat;

   if(!arg) beat = 10;

   if(!environment(this_object()))
      return;
   else
   {
      remove_call_out("fake_beat");
      call_out("fake_beat", beat);
   }
}

int query_save_flag()
{
   return 1;
}

void log_it(string incoming)
{
   if(!incoming)
      return;

   log_file("mizan.virii", environment(this_object())->query_real_name() + " " + incoming);
}

