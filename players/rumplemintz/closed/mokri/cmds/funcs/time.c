int date_to_time(string str)
{
  string *my_date, *my_time;
  int start_time, tmp;

  start_time = 1167627600;
  if(!str)
    return start_time;

  my_date = explode(str," ");
  if(sizeof(my_date) > 2)
    my_time = explode(my_date[2],":");

  if(my_date && sizeof(my_date) > 1 && sscanf(my_date[1],"%d",tmp) == 1)
    start_time += ((tmp - 1) * 86400);
  if(my_time && sizeof(my_time) && sscanf(my_time[0],"%d",tmp) == 1)
    start_time += (tmp * 60 * 60);
  if(my_time && sizeof(my_time) > 1 && sscanf(my_time[1],"%d",tmp) == 1)
    start_time += (tmp * 60);

  if(my_date && sizeof(my_date))
  {
    switch(my_date[0])
    {
      case "Feb":
        start_time += 2678400;
        break;
      case "Mar":
        start_time += 5097600;
        break;
      case "Apr":
        start_time += 7776000;
        break;
      case "May":
        start_time += 10368000;
        break;
      case "Jun":
        start_time += 13046400;
        break;
      case "Jul":
        start_time += 15638400;
        break;
      case "Aug":
        start_time += 18316800;
        break;
      case "Sep":
        start_time += 20995200;
        break;
      case "Oct":
        start_time += 23587200;
        break;
      case "Nov":
        start_time += 26265600;
        break;
      case "Dec":
        start_time += 28857600;
        break;
      }
    }
    
    return start_time;
}
