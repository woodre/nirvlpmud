/******************************************************************************
 *
 *  File:         custom_save.c
 *
 *  Function:     Allow for data to be saved without using save_object()
 *
 *  Author(s):    Vital
 *
 *  Copyright:    Copyright (c) 2007 Vital-Dev
 *                All Rights Reserved.
 *
 *  Source:       Started anew.
 *
 *  Notes:        Another level of abstraction from the lib.
 *
 *  Change History:
 *      07/06/2007    Added Header
 *  
 *****************************************************************************/

int
custom_save(string path, string data)
{
  if (!path || !data) return 0;
  if (file_size(path)) rm(path);
  write_file(path, data);
}

string
custom_restore(string path)
{
  string data;
  if (!path) "No Path!";
  data = file_size(path)?read_file(path):"No Saved Data";
  return data;
}