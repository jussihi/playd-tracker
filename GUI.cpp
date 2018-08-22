#include "GUI.hpp"


GUI::GUI()
{
  /* Initialize starting row to 0 */
  mCurrentRow = 0;

  /* Initialize screen */
  initscr();

  /* Don't output anything */
  noecho();

  /* Get initial screen size */
  getmaxyx(stdscr, mScreenHeight, mScreenWidth);

  /* Create top window and Initialize (refresh) it */
  mTopWindow = newwin(7, 72, 1, 1);
  RefreshTopWindow();
  
  /* Create row window and initialize (refresh) it */
  mRowWindow = newwin(5, 4, 9, 1);
  RefreshRowWindow();

  /* Initialize windows with minimum of 4 instrument windows */
  for(int i = 0; i < 4; i++) mTrackWindows.push_back(nullptr);

}


GUI::~GUI()
{
  /* End ncurses */
  endwin();
}


void GUI::GetInput()
{
  getch();

  if(CheckScreenSizeChanged())
  {
    // printw("Size changed!\n");
  }

  

  /* Print something to the screen */
  //printw("Hello World!\n");

  /* Moves the cursor to the desired position */
  //move(2, 5);
  //attron(A_BOLD | A_DIM | A_REVERSE);
  //printw("Hello Again!\n");
  //attroff(A_BLINK);

  /* Loads memory to screen */
  //refresh();

  /* Waits for user input */
  //getch();


  //clear();
  /* New Window pointer */
  // newwin(height, width, start_y, start_x);
}

bool GUI::CheckScreenSizeChanged()
{
  int x, y;
  getmaxyx(stdscr, y, x);

  bool changed = false;
  if(y != mScreenHeight || x != mScreenWidth)
  {
    endwin();
    initscr();
    noecho();
    //clear();
    refresh();
    RefreshTopWindow();
    RefreshRowWindow();
    changed = true;
  }
  return changed;
}


void GUI::RefreshTopWindow()
{
  wclear(mTopWindow);
  delwin(mTopWindow);
  mTopWindow = newwin(7, 72, 1, 1);
  box(mTopWindow, 0, 0);

  refresh();

  mvwprintw(mTopWindow, 0, 6, "playd trckr V0.01"); 
  mvwprintw(mTopWindow, 0, 32, "Copyright 2018 Jussi Hietanen");

  int x,y;
  getmaxyx(mTopWindow, y, x);

  mvwprintw(mTopWindow, 1, 6, "x: %d, y: %d", x, y);
  wrefresh(mTopWindow);
}


void GUI::RefreshRowWindow()
{
  wclear(mRowWindow);
  delwin(mRowWindow);
  mRowWindow = newwin(5, 4, 9, 1);
  int y, x;
  getmaxyx(stdscr, y, x);
  wresize(mRowWindow, y - 9, 4);
  box(mRowWindow, 0, 0);
  refresh();
  wrefresh(mRowWindow);
}