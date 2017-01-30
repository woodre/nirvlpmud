/* Where i post any important changes / info, if needed */

status guild_cmd(string str)
{
  if(!str) return 0;
  if(str == "updates" || str == "update" || str == "news")
  {
    /*   call_other("/closed/wiz_soul", "more", UPDATE_PATH); */
    cat(UPDATE_PATH);
    return 1;
  }
  else return 0;
  return 1;
}

