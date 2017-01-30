inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("scroll");
   set_short("A mini guild scroll");
   set_long(
        "A scroll detailing the mini guilds of Ryllian.\n"+
        "You are quite sure that you could <read> <scroll>.\n");
   set_weight(0);
   set_value(0);
}

init()  {
  ::init();
  add_action("read_scroll","read");
        }

read_scroll(str)  {

  if(str == "scroll")  {
    cat("/players/saber/closed/new_mini/doc/info1");
    return 1;
        }
  if(str == "scroll2")  {
    cat("/players/saber/closed/new_mini/doc/info2");
    return 1;
        }
  if(str == "blade" || str == "blades")  {
    cat("/players/saber/closed/new_mini/doc/infoblade");
    return 1;
        }
  if(str == "felines" || str == "feline")  {
    cat("/players/saber/closed/new_mini/doc/infofeline");
    return 1;
        }
  if(str == "gothics" || str == "gothics")  {
    cat("/players/saber/closed/new_mini/doc/infogothic");
    return 1;
        }
  if(str == "gypsy" || str == "gypsies")  {
    cat("/players/saber/closed/new_mini/doc/infogypsy");
    return 1;
        }
  if(str == "kender" || str == "kenders")  {
    cat("/players/saber/closed/new_mini/doc/infokender");
    return 1;
        }
  if(str == "larn" || str == "servants of larn")  {
    cat("/players/saber/closed/new_mini/doc/infolarn");
    return 1;
        }
  if(str == "succubus")  {
    cat("/players/saber/closed/new_mini/doc/infosuccubus");
    return 1;
        }
        }
