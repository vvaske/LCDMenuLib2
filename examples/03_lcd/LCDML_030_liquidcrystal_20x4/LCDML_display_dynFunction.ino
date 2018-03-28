/* ===================================================================== *
 *                                                                       *
 * Dynamic content                                                       *
 *                                                                       *
 * ===================================================================== *
 */


uint8_t g_dynParam = 100; // when this value comes from an eeprom, load it in setup 
                          // at the moment here is no setup function (todo) 
void mDyn_para(uint8_t line)
// *********************************************************************
{ 
  // check if this function is active (cursor stands on this line)     
  if (line == LCDML.MENU_getCursorPos()) 
  {
    // make only an action when the cursor stands on this menuitem
    //check Button
    if(LCDML.BT_checkAny()) 
    {
      if(LCDML.BT_checkEnter()) 
      {
        // this function checks returns the scroll disable status (0 = menu scrolling enabled, 1 = menu scrolling disabled)
        if(LCDML.MENU_getScrollDisableStatus() == 0)
        {
          // disable the menu scroll function to catch the cursor on this point
          // now it is possible to work with BT_checkUp and BT_checkDown in this function
          // this function can only be called in a menu, not in a menu function
          LCDML.MENU_disScroll();
        }
        else
        {
          // enable the normal menu scroll function
          LCDML.MENU_enScroll();
        }
        // dosomething for example save the data or something else             
        LCDML.BT_resetEnter();
      }

      // This check have only an effekt when MENU_disScroll is set
      if(LCDML.BT_checkUp())
      {        
        g_dynParam++;        
      }

      // This check have only an effekt when MENU_disScroll is set
      if(LCDML.BT_checkDown())
      {
        g_dynParam--;        
      }      

      
      if(LCDML.BT_checkLeft())
      {
        g_dynParam++;        
      }
      if(LCDML.BT_checkRight()) 
      {
        g_dynParam--;        
      }
    }              
  } 

  char buf[20];
  sprintf (buf, "dynValue: %d", g_dynParam);

  // use the line from function parameters
  lcd.setCursor(1, line);
  lcd.print(buf); 

}





